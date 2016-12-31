ifeq ($(TOOLCHAIN_PATH),)
    $(error "TOOLCHAIN_PATH is not set, eg. TOOLCHAIN_PATH=C:/avr-gnu-toolchain_build64")
    exit 1
endif

ifeq ($(F_CPU),)
    $(error "F_CPU is not set")
    exit 1
endif

EXTENSION=
ifeq ($(OS),Windows_NT)
	EXTENSION=.exe
endif

CROSS_COMPILE   		= $(TOOLCHAIN_PATH)/bin/avr
CC						= $(CROSS_COMPILE)-gcc
CXX						= $(CROSS_COMPILE)-g++
LD						= $(CROSS_COMPILE)-ld
AR						= $(CROSS_COMPILE)-ar
OBJDUMP                 = $(CROSS_COMPILE)-objdump
OBJCOPY                 = $(CROSS_COMPILE)-objcopy
NM                      = $(CROSS_COMPILE)-nm
SIZE                    = $(CROSS_COMPILE)-size

.PHONY: all test size clean

BUILDDIR=build
SOURCEDIR=sources
UTDIR=ut
INCDIR=include/
SRC=$(wildcard $(SOURCEDIR)/*.cpp)
OBJS=$(patsubst $(SOURCEDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRC))

VERSION_MAJOR=0
VERSION_MINOR=2.3
NAME=libatm8a
TARGET=$(NAME).$(VERSION_MAJOR).$(VERSION_MINOR).a

all: MCU=atmega8a
all: MMCU=avr4
all: COMPILE_OPTIONS=\
		-mmcu=$(MCU) \
		-DF_CPU=$(F_CPU)UL \
		-I $(INCDIR) \
		-std=gnu++11 \
		-O2 \
		-funsigned-char \
		-funsigned-bitfields \
		-ffunction-sections \
		-fdata-sections \
		-fpack-struct \
		-fshort-enums \
		-Wall \
		-Werror \
		-Wno-return-type			
all: LINKER_OPTIONS=\
		-mmcu=$(MCU)\
		-DF_CPU=$(F_CPU)UL \
		-Wl,--start-group \
		-Wl,-lm \
		-Wl,--end-group \
		-Wl,--gc-sections
	
all: dir print library

dir: ;
	-mkdir $(BUILDDIR)

print: ;
	@echo
	@echo
	@echo	
	@echo "=== AVR: " $(MCU)
	@echo "=== F_CPU: " $(F_CPU)
	@echo "=== MMCU: " $(MMCU)
	@echo
	@echo
	@echo
	
library: $(TARGET)

$(TARGET): $(OBJS)
	@echo
	$(AR) -r -c -s $@ $(OBJS)

$(OBJS): $(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp
	@echo
	$(CXX) $(COMPILE_OPTIONS) -o $@ -c $<
	
test: ;
	cd $(UTDIR) && $(MAKE)

size: ;
	@echo
	@echo "Library size"
	@echo "----------------"
	$(SIZE) --totals $(TARGET)

clean:
	cd $(UTDIR) && $(MAKE) clean
	-rm -rf $(BUILDDIR)
	-rm -rf $(TARGET)