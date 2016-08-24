/*
 * ex01_test.cc
 *
 *  Created on: Aug 17, 2016
 *      Author: dmitry
 */

#include "ex02.h"
#include "gtest/gtest.h"


TEST(Ex02, get_nth) {
    int values[] = { 5, 4, 3, 2, 1, 0 };

    Node<int> *list = create_list(values, sizeof(values) / sizeof(int));
    EXPECT_EQ(0, get_nth(list, 0)->value);
    EXPECT_EQ(1, get_nth(list, 1)->value);
    EXPECT_EQ(2, get_nth(list, 2)->value);
    EXPECT_EQ(3, get_nth(list, 3)->value);
    EXPECT_EQ(4, get_nth(list, 4)->value);
    EXPECT_EQ(5, get_nth(list, 5)->value);
    EXPECT_EQ(nullptr, get_nth(list, -1));
    EXPECT_EQ(nullptr, get_nth(list, -11));
    EXPECT_EQ(nullptr, get_nth(list, 6));
    EXPECT_EQ(nullptr, get_nth(list, 12));
    delete_list(list);

    values[0] = random() % 256;
    list = create_list(values, 1);
    EXPECT_EQ(values[0], get_nth(list, 0)->value);
    EXPECT_EQ(nullptr, get_nth(list, 1));
    delete_list(list);

    EXPECT_EQ(nullptr, get_nth(nullptr, 0));
}

TEST(Ex02, find_loop) {
    Node<int> A(0);
    Node<int> B(1);
    Node<int> C(2);
    Node<int> D(3);
    Node<int> E(4);
    Node<int> F(5);
    A.next = &B;
    B.next = &C;
    C.next = &D;
    D.next = &E;
    E.next = &F;

    // F->A
    F.next = &A;
    EXPECT_EQ(A.value, find_loop(&A)->value);

    // F->B
    F.next = &B;
    EXPECT_EQ(B.value, find_loop(&A)->value);

    // F->C
    F.next = &C;
    EXPECT_EQ(C.value, find_loop(&A)->value);

    // F->D
    F.next = &D;
    EXPECT_EQ(D.value, find_loop(&A)->value);


    // F->E
    F.next = &E;
    EXPECT_EQ(E.value, find_loop(&A)->value);

    // F->F
    F.next = &F;
    EXPECT_EQ(F.value, find_loop(&A)->value);

    // F->nullptr
    F.next = nullptr;
    EXPECT_EQ(nullptr, find_loop(&A));
}
