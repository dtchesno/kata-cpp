/*
 * ex01_test.cc
 *
 *  Created on: Aug 17, 2016
 *      Author: dmitry
 */

#include "ex01.h"
#include "gtest/gtest.h"


TEST(RemoveDupChars, all) {
    char pattern[100];

    strcpy(pattern, "aaaaa");
    remove_dup_chars(pattern);
    EXPECT_EQ(0, strcmp(pattern, "a"));

    strcpy(pattern, "aabbb");
    remove_dup_chars(pattern);
    EXPECT_EQ(0, strcmp(pattern, "ab"));

    strcpy(pattern, "ababac");
    remove_dup_chars(pattern);
    EXPECT_EQ(0, strcmp(pattern, "abc"));

    strcpy(pattern, "");
    remove_dup_chars(pattern);
    EXPECT_EQ(0, strcmp(pattern, ""));
}
