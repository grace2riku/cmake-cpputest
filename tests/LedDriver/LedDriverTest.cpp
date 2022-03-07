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
