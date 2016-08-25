/*
 * ex01_test.cc
 *
 *  Created on: Aug 17, 2016
 *      Author: dmitry
 */

#include "ex03.h"
#include "gtest/gtest.h"


TEST(Ex03, stack) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(3, stack.pop());
    EXPECT_EQ(2, stack.pop());
    EXPECT_EQ(1, stack.pop());
    EXPECT_EQ(true, stack.empty());
}

TEST(Ex03, queue) {
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    ASSERT_EQ(false, queue.empty());
    EXPECT_EQ(1, queue.pop());

    ASSERT_EQ(false, queue.empty());
    EXPECT_EQ(2, queue.pop());

    ASSERT_EQ(false, queue.empty());
    EXPECT_EQ(3, queue.pop());

    ASSERT_EQ(true, queue.empty());
}

TEST(Ex03, run_hanoi) {
    HanoiStack s1;
    HanoiStack s2;
    HanoiStack s3;

    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);

    run_hanoi(5, s1, s2, s3);

    EXPECT_EQ(true, s1.empty());
    EXPECT_EQ(true, s2.empty());

    ASSERT_EQ(false, s3.empty());
    EXPECT_EQ(1, s3.pop());
    ASSERT_EQ(false, s3.empty());
    EXPECT_EQ(2, s3.pop());
    ASSERT_EQ(false, s3.empty());
    EXPECT_EQ(3, s3.pop());
    ASSERT_EQ(false, s3.empty());
    EXPECT_EQ(4, s3.pop());
    ASSERT_EQ(false, s3.empty());
    EXPECT_EQ(5, s3.pop());
    EXPECT_EQ(true, s3.empty());
}
