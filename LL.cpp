//
//  LL.cpp
//  LinkedList
//
//  Created by Esraa Hamdi Abbas on 11/1/21.
//

#include "LL.hpp"

LinkedList::LinkedList() {
    head = NULL;
    size = 0;
}

node *LinkedList::merge(node *a, node *b) // merges two sorted linked lists
{
    if (a == nullptr) {
        return b;
    } else if (b == nullptr) {
        return a;
    }

    node *c = nullptr;
    if (a->value < b->value) {
        c = a;
        c->next = merge(a->next, b);
    } else if (b->value < a->value) {
        c = b;
        c->next = merge(a,b->next);
    }

    return c;
}

node *LinkedList::midPoint(node *head) // finds the midpoint by the runner technique
{
    node *fast = head->next;
    node *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

node *LinkedList::mergesort(node *head) {
    if (head->next == nullptr || head == nullptr) {
        return head;
    }

    node* midpoint = midPoint(head);

    node* a = head;
    node* b = midpoint->next;
    midpoint->next = nullptr;
    a = mergesort(a);
    b = mergesort(b);
    return merge(a,b);
}

void LinkedList::sort() {
    head = mergesort(head);
}

void LinkedList::add(int value) {

    if (head == NULL) {
        node *n = new node;
        n->value = value;
        n->next = NULL;
        head = n;
    } else {
        node *cursor = head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
        }
        node *n = new node;
        n->value = value;
        n->next = NULL;
        cursor->next = n;
    }
    size++;
}

int LinkedList::Size() {
    return size;
}

void LinkedList::ShowList() {
    node *cursor = head;
    while (cursor != NULL) {
        std::cout << cursor->value << std::endl;
        cursor = cursor->next;
    }
}
