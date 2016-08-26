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
        mSize++;
    };

    T pop() {
        T value = front->value;
        Node<T> *temp = front;
        front = front->next;
        delete temp;
        mSize--;
        return value;
    };

    T& top() {
        return front->value;
    };

    int size() { return mSize; };

    //bool empty() { return front == nullptr; };
    bool empty() { return mSize == 0; };

private:
    Node<T> *front = nullptr;
    int mSize = 0;
};


class HanoiStack : public Stack<int> {
public:
    HanoiStack(const char* name) : mName(name) {};
    void push(const int item) {
        if (empty() || item < top()) {
            Stack<int>::push(item);
        }
    };
    const char* name() { return mName; };
private:
    const char *mName;
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

class QueueWith2Stacks {
public:
    void push(int value);
    int pop();
    bool empty();
private:
    void flip(Stack<int>& s1, Stack<int>& s2);
private:
    Stack<int> directStack;
    Stack<int> reverseStack;
};

int hanoi(int num, HanoiStack& s1, HanoiStack& s2, HanoiStack& s3);
void sort(Stack<int>& stack);

#endif /* INCLUDE_EX03_H_ */
