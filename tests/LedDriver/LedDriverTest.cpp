extern "C"
{
#include "LedDriver.h"
}

#include "CppUTest/TestHarness.h"


TEST_GROUP(LedDriver)
{
    uint16_t virtualLeds; // TEST_GROUPの中の変数はTEST_GROUPで共有できる
    void setup()  // setupは各TEST実行の際に呼び出される
    {
      LedDriver_Create(&virtualLeds);
    }

    void teardown()
    {
    }
};

// テストは下に書いてあるものから先に実行される

TEST(LedDriver, LedsOffAfterCreate)
{
  virtualLeds = 0xffff;
  LedDriver_Create(&virtualLeds);
  LONGS_EQUAL(0, virtualLeds);
}

TEST(LedDriver, TurnOnLedOne)
{
  LedDriver_TurnOn(1);
  LONGS_EQUAL(1, virtualLeds);
}

TEST(LedDriver, TurnOffLedOne)
{
  LedDriver_TurnOn(1);
  LedDriver_TurnOff(1);
  LONGS_EQUAL(0, virtualLeds);
}

TEST(LedDriver, TurnOnMultipleLeds)
{
  LedDriver_TurnOn(9);
  LedDriver_TurnOn(8);
  LONGS_EQUAL(0x180, virtualLeds);  
}

#if 0
TEST(LedDriver, TurnOffAnyLed)
{
  LedDriver_TurnOn(9);
  LedDriver_TurnOn(8);
  LedDriver_TurnOff(8);
  LONGS_EQUAL(0x100, virtualLeds);
}
#endif

TEST(LedDriver, AllOn)
{
  LedDriver_TurnAllOn();
  LONGS_EQUAL(0xffff, virtualLeds);
}

