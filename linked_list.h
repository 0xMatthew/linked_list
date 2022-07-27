#include <iostream>
#include <string>
#include "node.h"

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
class linked_list
{
public:
    node *head;
    node *tail;
    linked_list();
    void print_nodes();
    void print_nodes_reverse();
    void append(int data);
    void prepend(int data);
    void remove(int data);
};
#endif