#include <iostream>
#include "node.h"
#include "linked_list.h"

void linked_list:: print_nodes()
{
    node *tmp = head;
    if (head == nullptr)
    {
        std::cout << "your list has only a nullptr";
        return;
    }

    while (tmp != nullptr)
    {
        std::cout << tmp->data << ", ";
        tmp = tmp->next;
    }
}

void linked_list::push_element_end(int data)
{
    node *new_node = new node(data);
    if (head == nullptr)
    {
        head = new_node;
        return;
    }

    node *tmp = head;
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = new_node;
}