/*
 * ex01_test.cc
 *
 *  Created on: Aug 17, 2016
 *      Author: dmitry
 */

#include "ex03.h"
#include "gtest/gtest.h"

// test stack implementation
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

// test queue implementation
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

// test hanoi algorithm
TEST(Ex03, hanoi) {
    HanoiStack s1("A");
    HanoiStack s2("B");
    HanoiStack s3("C");

    int N = 3;
    for (int i = N; i > 0; i--) {
        s1.push(i);
    }

    int moves = hanoi(s1.size(), s1, s2, s3);
    printf("hanoi: size = %d, moves = %d, expected = %d\n", N, moves, (1 << N) -1);

    EXPECT_EQ(true, s1.empty());
    EXPECT_EQ(true, s2.empty());

    for (int i = 1; i <= N; i++) {
        ASSERT_EQ(false, s3.empty());
        EXPECT_EQ(i, s3.pop());
    }
    EXPECT_EQ(true, s3.empty());
}

TEST(Ex03, queue_with_2stacks) {
    QueueWith2Stacks queue;

    int N = 10;
    for (int i = 0; i < N; i++) {
        queue.push(i);
    }

    ASSERT_EQ(false, queue.empty());
    for (int i = 0; i < N; i++) {
        EXPECT_EQ(i, queue.pop());
    }
    EXPECT_EQ(true, queue.empty());
}

TEST(Ex03, stack_sort) {
    int counts[] = { 1, 2, 3, 5, 8, 100, 1000 };
    for (int n = 0; n < sizeof(counts) / sizeof(int); n++) {
        int count = counts[n];
        int data[count];
        Stack<int> stack;

        for (int i = 0; i < count; i++) {
            data[i] = rand() % 100;
            stack.push(data[i]);
        }

        sort(stack);

        std::qsort(data, count, sizeof(int), [](const void *a, const void *b) {
            int val1 = *static_cast<const int*>(a);
            int val2 = *static_cast<const int*>(b);
            if (val1 < val2) {
                return -1;
            } else if (val2 < val1) {
                return 1;
            }
            return 0;
        });

        for (int i = 0; i < count; i++) {
            ASSERT_EQ(false, stack.empty());
            ASSERT_EQ(data[i], stack.pop());
        }
        ASSERT_EQ(true, stack.empty());
    }
}
