#include <iostream>
#include "node.h"

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
class linked_list{
    public:
        node *head;
        void print_nodes();
        void push_element_end(int data);
};
#endif