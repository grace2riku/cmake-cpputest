extern "C"
{
#include "LedDriver.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(LedDriver)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(LedDriver, LedsOffAfterCreate)
{
  uint16_t virtualLeds = 0xffff;
  LedDriver_Create(&virtualLeds);
  LONGS_EQUAL(0, virtualLeds);
}

TEST(LedDriver, TurnOnLedOne)
{
  uint16_t virtualLeds;
  LedDriver_Create(&virtualLeds);
  LedDriver_TurnOn(1);
  LONGS_EQUAL(1, virtualLeds);
}