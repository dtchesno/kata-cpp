/*
 * kata_test.cc
 *
 *  Created on: Feb 3, 2016
 *      Author: dmitry
 */


#include "kata.h"
#include "gtest/gtest.h"

#include <stdio.h>


TEST(QSort, 1) {
    int value = rand() % 100;
    int data[1] = { value };

    qsort(data, 0, 0);

    EXPECT_EQ(value, data[0]);
}

TEST(QSort, random) {
    int counts[] = { 1, 2, 3, 5, 8, 100, 1000, 111111 };
    for (int n = 0; n < sizeof(counts) / sizeof(int); n++) {
        int count = counts[n];
        int original[count];
        int data[count];

        for (int i = 0; i < count; i++) {
            data[i] = original[i] = rand() % 100;
        }

        qsort(data, 0, count - 1);
        std::qsort(original, count, sizeof(int), [](const void *a, const void *b) {
            int val1 = *static_cast<const int*>(a);
            int val2 = *static_cast<const int*>(b);
            if (val1 < val2) {
                return -1;
            } else if (val2 < val1) {
                return 1;
            }
            return 0;
        });

        EXPECT_EQ(0, memcmp(data, original, sizeof(data)));
    }
}

TEST(MergeSort, 1) {
    int value = rand() % 100;
    int data[1] = { value };

    mergesort(data, 1);

    EXPECT_EQ(value, data[0]);
}

TEST(MergeSort, random) {
    int counts[] = { 1, 2, 3, 5, 8, 100, 1000, 111111 };
    for (int n = 0; n < sizeof(counts) / sizeof(int); n++) {
        int count = counts[n];
        int original[count];
        int data[count];

        for (int i = 0; i < count; i++) {
            data[i] = original[i] = rand() % 100;
        }

        mergesort(data, count);
        std::qsort(original, count, sizeof(int), [](const void *a, const void *b) {
            int val1 = *static_cast<const int*>(a);
            int val2 = *static_cast<const int*>(b);
            if (val1 < val2) {
                return -1;
            } else if (val2 < val1) {
                return 1;
            }
            return 0;
        });

        EXPECT_EQ(0, memcmp(data, original, sizeof(data)));
    }
}

