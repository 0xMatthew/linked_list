#include <iostream>

#ifndef NODE_H
#define NODE_H

class node{
    public:
        int data;
        node * next;
        node();
        node(int data);
};
#endif