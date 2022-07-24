#include <iostream>
#include "node.h"
#include "linked_list.h"

linked_list::linked_list() {
    head = nullptr;
}
void linked_list::print_nodes()
{
    node* tmp = head;
    if (head == nullptr)
    {
        std::cout << "your list has only a nullptr\n";
        return;
    }

    std::cout << "your list: ";
    while (tmp != nullptr)
    {
        std::cout << tmp->data << ", ";
        tmp = tmp->next;
    }
}

void linked_list::append(int data)
{
    node* new_node = new node(data);
    if (head == nullptr)
    {
        head = new_node;
        return;
    }

    node* tmp = head;
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = new_node;
}

void linked_list::prepend(int data)
{
    node* new_node = new node(data);
    if (head == nullptr)
    {
        head = new_node;
        return;
    }

    new_node->next = head;
    head = new_node;
}

void linked_list::remove(int data)
{
    std::string succ_mess = "successfully removed integer \"" + std::to_string(data) + "\"\n";
    std::string error_mess = "failed to remove integer \"" + std::to_string(data) + "\"\n";
    node* cur_node = head;
    node* prev_node = nullptr;

    if (head == nullptr)
    { //no nodes exist
        std::cout<< error_mess;
        return;
    }

    while (cur_node->data != data && cur_node->next != nullptr)
    { //iterate through linked list until cur_node's data matches OR the end of the list has been reached
        prev_node = cur_node;
        cur_node = cur_node->next;
    }

    if (cur_node->data == data && prev_node != nullptr)
    { // conditional check returns true if cur_node's data matches and cur_node is NOT head
        prev_node->next = cur_node->next;
        delete cur_node;
        std::cout << succ_mess;
        return;
    }
    else if (cur_node->data == data && prev_node == nullptr)
    { //conditional check returns true if cur_node's data matches and cur_node IS head
        head = head->next;
        std::cout << succ_mess;
        return;
    }
    else
    { //otherwise, cur_node does not have a data match
        std::cout << error_mess;
        return;
    }
}