/*
 * kata.h
 *
 *  Created on: Feb 3, 2016
 *      Author: dmitry
 */

#ifndef EX02_H_
#define EX02_H_

#define nullptr 0

template<class T> class Node {
public:
    Node(T data) { value = data; };
//    Node(const Node& node) {
//        value = node.value;
//        next = nullptr;
//    }

public:
    T value;
    Node<T> *next = nullptr;
};

void delete_list(Node<int> *head);
Node<int>* get_nth(Node<int> *head, int n);

Node<int>* create_list(int *values, int size);
Node<int>* find_loop(Node<int> *head);

#endif /* EX02_H_ */
