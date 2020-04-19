#include "pch.h"

#include <iostream>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

#include "FLATCStack.h"

TEST(TestCaseFlatCStack, TestStackCreate) {
    StackPtr s = StackCreate();
    EXPECT_TRUE(s != NULL);
    EXPECT_TRUE(s->mTop == -1);
    EXPECT_TRUE(s->mCapacity == 2); //expect the equation to be true
    EXPECT_HRESULT_FAILED(s->mStack[s->mTop]); //expect the test to fail(error occurring)

    s = StackCreate(4);
    EXPECT_TRUE(s != NULL);
    EXPECT_TRUE(s->mTop == -1);
    EXPECT_TRUE(s->mCapacity == 4);
    EXPECT_HRESULT_FAILED(s->mStack[s->mTop]);
}

TEST(TestCaseFlatCStack, TestStackPush) {
    StackPtr s = StackCreate();
    // test StackPush to be success when still not over capacity
    EXPECT_NO_FATAL_FAILURE(StackPush(s, 2));
    EXPECT_TRUE(s->mStack[s->mTop] == 2);
    EXPECT_NO_FATAL_FAILURE(StackPush(s, 7));
    EXPECT_TRUE(s->mStack[s->mTop] == 7);
    // test StackPush to be no failure when over capacity but the operation must be not effective
    EXPECT_NO_FATAL_FAILURE(StackPush(s, 5)); //expect function to not occur error
    EXPECT_TRUE(s->mStack[s->mTop] == 7);
}

TEST(TestCaseFlatCStack, TestStackPop) {
    StackPtr s = StackCreate(1);
    s->mTop += 1;
    s->mStack[0] = 7;
    int val;
    // test whether StackPop operating correctly
    EXPECT_NO_FATAL_FAILURE(val = StackPop(s));
    EXPECT_TRUE(val == 7);
    // test whether StackPop returning INT_MIN
    EXPECT_NO_FATAL_FAILURE(val = StackPop(s));
    EXPECT_TRUE(val == INT_MIN);
}