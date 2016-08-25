/*
 * ex03.h
 *
 *  Created on: Aug 24, 2016
 *      Author: dmitry
 */

#ifndef INCLUDE_EX03_H_
#define INCLUDE_EX03_H_

#include "ex02.h"

template<class T> class Stack {
public:
    void push(const T& item) {
        Node<T> *node = new Node<T>(item);
        if (front == nullptr) {
            front = node;
        } else {
            node->next = front;
            front = node;
        }
    };

    T pop() {
        T value = front->value;
        Node<T> *temp = front;
        front = front->next;
        delete temp;
        return value;
    };

    T& top() {
        return front->value;
    };

    bool empty() { return front == nullptr; };

private:
    Node<T> *front = nullptr;
};


class HanoiStack : public Stack<int> {
public:
    void push(const int item) {
        if (!empty() && item < top()) {
            Stack<int>::push(item);
        }
    };
};


template<class T> class Queue {
public:
    void push(const T& item) {
        Node<T> *node = new Node<T>(item);
        if (first == nullptr) {
            first = last = node;
        } else {
            last->next = node;
            last = node;
        }
    };

    T pop() {
        T value = first->value;
        Node<T> *temp = first;
        first = first->next;
        delete temp;
        return value;
    };

    T& front() {
        return first->value;
    };

    bool empty() { return first == nullptr; };

private:
    Node<T> *first = nullptr;
    Node<T> *last = nullptr;
};


void run_hanoi(int size, HanoiStack& s1, HanoiStack& s2, HanoiStack& s3);
void move_hanoi(int size, HanoiStack& s1, HanoiStack& s2, HanoiStack& s3);

#endif /* INCLUDE_EX03_H_ */
