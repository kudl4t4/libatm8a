#include <gtest/gtest.h>

#include "oscillator.h"

class oscillator_ut: public ::testing::Test {
public:
    virtual void SetUp() {
        _oss = {};
        oscillator::_os = &_oss;
    }
    virtual void TearDown() {
    }
protected:
    void writeOSCCAL(unsigned char val) {
        _oss._OSCCAL = val;
    }
    unsigned char readOSCCAL() {
        return _oss._OSCCAL;
    }
private:
    oscillator_Struct _oss;
};

/* TEST CODES */
TEST_F(oscillator_ut, setOscillatorCalibration)
{
    oscillator::setOscillatorCalibration(0x45);
    EXPECT_EQ(0x45, readOSCCAL());
}

TEST_F(oscillator_ut, getOscillatorCalibration)
{
    writeOSCCAL(0x67);
    EXPECT_EQ(0x67, oscillator::getOscillatorCalibration());
}