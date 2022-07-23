#include <iostream>
#include "node.h"

node::node()
{
    data = 0;
    next = nullptr;
}
node::node(int data)
{
    this->data = data;
    this->next = nullptr;
}