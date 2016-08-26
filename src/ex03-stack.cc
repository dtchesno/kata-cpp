/*
 * ex03-stack.cc
 *
 *  Created on: Aug 24, 2016
 *      Author: dmitry
 */

#include "ex03.h"
#include <stdio.h>

int hanoi(int num, HanoiStack& s1, HanoiStack& s2, HanoiStack& s3) {
    if (num == 0) {
        return 0;
    }

    int moves = 0;
    if (num == 1) {
        //printf("push %d from %s to %s\n", s1.top(), s1.name(), s3.name());
        s3.push(s1.pop());
        moves = 1;
    } else {
        moves = hanoi(num - 1, s1, s3, s2);

        //printf("push %d from %s to %s\n", s1.top(), s1.name(), s3.name());
        s3.push(s1.pop());
        moves++;

        moves += hanoi(num - 1, s2, s1, s3);
    }

    return moves;
}

void QueueWith2Stacks::push(int value) {
    if (directStack.empty()) {
        flip(reverseStack, directStack);
    }
    directStack.push(value);
}

int QueueWith2Stacks::pop() {
    if (reverseStack.empty()) {
        flip(directStack, reverseStack);
    }
    return reverseStack.pop();
}

bool QueueWith2Stacks::empty() {
    return directStack.empty() && reverseStack.empty();
}

void QueueWith2Stacks::flip(Stack<int>& s1, Stack<int>& s2) {
    while (!s1.empty()) {
        s2.push(s1.pop());
    }
}

void sort(Stack<int>& stack) {
    Stack<int> sorted;

    while (!stack.empty()) {

        // if current element is in-order, just move around
        if (sorted.empty() || stack.top() > sorted.top()) {
            sorted.push(stack.pop());
            continue;
        }

        // now find place for current element in sorted, taking out 1 by 1
        int current = stack.pop();
        int pulled = 0;
        do {
            stack.push(sorted.pop());
            pulled++;
        } while (!sorted.empty() && current < sorted.top());

        // now insert current element and move back whatever was pulled out
        sorted.push(current);
        while (pulled > 0) {
            sorted.push(stack.pop());
            pulled--;
        }
    }

    // copy sorted data back
    while (!sorted.empty()) {
        stack.push(sorted.pop());
    }
}
