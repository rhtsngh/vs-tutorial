#include "pch.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

//Below is the function wanted to test and 3 test cases(group of cases);
bool IsPrime(int n)
{
    return false;
}

TEST(IsPrimeTest, PositiveNumbers)
{
    EXPECT_FALSE(IsPrime(4));
    EXPECT_TRUE(IsPrime(5));
}

TEST(IsPrimeTest, NegativeNumbers)
{
    EXPECT_FALSE(IsPrime(-1));
    EXPECT_FALSE(IsPrime(-100));
}

TEST(IsPrimeTest, TrivialCases)
{
    EXPECT_FALSE(IsPrime(0));
    EXPECT_FALSE(IsPrime(1));
    EXPECT_TRUE(IsPrime(2));
    EXPECT_TRUE(IsPrime(3));
}