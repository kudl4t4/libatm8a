export F_CPU

ifeq ($(F_CPU),)
    $(error "F_CPU is not set")
    exit 1
endif

EXTENSION=
ifeq ($(OS),Windows_NT)
	EXTENSION=.exe
endif

GTEST_DIR=gtest/googletest
INC_DIR=../include/

SOURCE=$(wildcard *.cpp)
OBJECTS=$(patsubst %.cpp,$(BUILDDIR)/%.o,$(SOURCE))

BUILDDIR=build
SOURCEDIR=../sources
LIBSRC=$(wildcard $(SOURCEDIR)/*.cpp)
LIBOBJS=$(patsubst $(SOURCEDIR)/%.cpp,$(BUILDDIR)/%.o,$(LIBSRC))
TARGET=libatm8a

ARFLAGS=-rcs

.PHONY: all clean

all: CXXFLAGS=\
	-std=gnu++11\
	-DF_CPU=$(F_CPU)UL\
	-DT_UNITTEST
all: GXX_FLAGS=\
	-g\
	-Wall\
	-Wextra\
	-lpthread
all: GPP_FLAGS=\
	-isystem
	
	
all: tests
	
tests: dirmk gtest libatm8a uts

dirmk:
	-mkdir $(BUILDDIR)
	
uts: $(OBJECTS)
	@echo
	$(CXX) -o tests -I $(INC_DIR) -I $(GTEST_DIR)/include $(OBJECTS) -L. -lgtest_main -latm8a
	./tests$(EXTENSION)

$(OBJECTS): $(BUILDDIR)/%.o: %.cpp
	@echo
	$(CXX) $(CXXFLAGS) -I $(INC_DIR) -I $(GTEST_DIR)/include -o $@ -c $<

libatm8a: $(LIBOBJS)
	@echo
	$(AR) $(ARFLAGS) $@.a $(LIBOBJS)

$(LIBOBJS): $(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp
	@echo
	$(CXX) $(CXXFLAGS) -I $(INC_DIR) -o $@ -c $<
	
gtest: libgtest_main.a 

gtest-all.o: $(GTEST_SRCS_)
	$(CXX) $(GPP_FLAGS) $(GXX_FLAGS) -I $(GTEST_DIR)/include -I $(GTEST_DIR) -c $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o: $(GTEST_SRCS_)
	$(CXX) $(GPP_FLAGS) $(GXX_FLAGS) -I $(GTEST_DIR)/include -I $(GTEST_DIR) -c $(GTEST_DIR)/src/gtest_main.cc

gtest.a: gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

libgtest_main.a: gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^
	
clean:
	-rm -rf $(BUILDDIR)/
	-rm -rf gtest-all.o gtest_main.o gtest.a libgtest_main.a libatm8a.a tests$(EXTENSION)