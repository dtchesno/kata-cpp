#include "ex02.h"
#include <stdio.h>

Node<int>* get_nth(Node<int> *head, int n) {
    if (n < 0 || head == nullptr) {
        return nullptr;
    }

    Node<int> *pNth = nullptr;
    Node<int> *pNode = head;
    int i = 0;
    while (pNode != nullptr) {
        if (pNth != nullptr) {
            pNth = pNth->next;
        } else if (i == n) {
            pNth = head;
        }
        i++;
        pNode = pNode->next;
    }

    return pNth;
}

Node<int>* find_loop(Node<int> *head) {
    Node<int> *p1 = head;
    Node<int> *p2 = head;

    // move p1 with step=1 & p2 with step=2
    // p1 & p2 should meet at (n-k) position
    // where n - total length and k - distance from beginning to loop start
    //
    // DETAILS:
    //  - after 1st k steps, p1 at loop start, p2 at k steps past loop start
    //  - next consider move inside loop, p1 at 0, p2 at k
    //  - after next (n-k) steps, p1 at loop end, p2 at k+2*(n-k) or
    //    again at k as done loop twice while p1 once we can remove any (n-k)
    //  - now, if we make k steps back, p1 at (end loop - k), so as p2
    //    because of k-2*k=-k
    do {
        p1 = p1->next;
        p2 = p2->next;
        if (p1 == nullptr || p2 == nullptr || p2->next == nullptr) {
            return nullptr;
        }
        p2 = p2->next;
    } while (p1 != p2);

    // move p1 from start & p2 from current pos with the same speed
    // that will bring both p1 & p2 to loop start
    p1 = head;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}

Node<int>* create_list(int *values, int size) {
    if (size <= 0) {
        return nullptr;
    }

    Node<int> *pHead = new Node<int>(values[0]);
    Node<int> *ptr = pHead;
    for (int i = 1; i < size; i++) {
        ptr->next = new Node<int>(values[i]);
        ptr = ptr->next;
    }

    return pHead;
}

void delete_list(Node<int> *head) {
    while (head != nullptr) {
        Node<int> *ptr = head;
        head = head->next;
        delete ptr;
    }
}
