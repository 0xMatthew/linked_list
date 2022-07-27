#include <iostream>
#include "node.h"
#include "linked_list.h"

linked_list::linked_list()
{
    head = nullptr;
    tail = nullptr;
}
void linked_list::print_nodes()
{ // prints by traversing the nodes from front-most element to last element
    node *tmp = head;
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
    std::cout << "\n";
}

void linked_list::print_nodes_reverse()
{
    node *tmp = tail;
    if (tail == nullptr)
    {
        std::cout << "your list has only a nullptr\n";
        return;
    }

    std::cout << "your list (in reverse order): ";
    while (tmp != nullptr)
    {
        std::cout << tmp->data << ", ";
        tmp = tmp->prev;
    }
    std::cout << "\n";
}

void linked_list::append(int data)
{
    node *new_node = new node(data);
    if (head == nullptr)
    {
        head = new_node;
        head->prev = nullptr;
        return;
    }

    node *tmp = head;
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }

    tmp->next = new_node; // adds new_node to end of linked_list
    new_node->prev = tmp; // points prev pointer to node prior to newly-added node

    tail = new_node;

    new_node = nullptr;
    delete new_node;
}

void linked_list::prepend(int data)
{
    node *new_node = new node(data);
    if (head == nullptr)
    {
        head = new_node;
        head->prev = nullptr;
        return;
    }

    new_node->next = head; // new_node's next pointer now points to the old head
    head->prev = new_node; // old head's prev pointer now points to new_node

    head = new_node; // new_node is now the new head

    new_node = nullptr;
    delete new_node;
}

void linked_list::remove(int data)
{
    std::string element_type;
    std::string succ_mess = "successfully removed integer \"" + std::to_string(data) + "\"\n";
    std::string fail_mess = "failed to remove integer \"" + std::to_string(data) + "\"\n";
    std::string error_mess = "something went wrong\n";
    node *cur_node = head;
    // node *prev_node = nullptr;

    if (head == nullptr)
    { // no nodes exist
        std::cout << fail_mess;
        return;
    }

    while (cur_node->data != data)
    { // iterate through linked list until cur_node's data matches OR the end of the list has been reached
        if (cur_node->next == nullptr)
        {
            std::cout << fail_mess;
            return;
        }
        cur_node = cur_node->next;
    }

    if (cur_node != head && cur_node != tail)
    { // conditional check if cur_node IS a middle element
        element_type = "middle element";

        cur_node->prev->next = cur_node->next;
        cur_node->next->prev = cur_node->prev;

        cur_node = nullptr;
        delete cur_node;

        std::cout << succ_mess << "element type: " << element_type << " \n";
        return;
    }
    else if (cur_node == head)
    { // conditional check returns true if cur_node's data matches and cur_node IS head
        element_type = "head";

        head = cur_node->next;
        head->prev = nullptr; // ABSOLUTELY NECESSARY to avoid new head's prev from pointing to address of old head

        cur_node = nullptr;
        delete cur_node;

        std::cout << succ_mess << "element type: " << element_type << " \n";
        return;
    }
    else if (cur_node == tail)
    { // conditional check evaluates to true if cur_node data matches and cur_node IS tail
        element_type = "tail";

        tail = cur_node->prev;
        tail->next = nullptr; // ABSOLUTELY NECESSARY to avoid new tail's next from pointing to the address of the old tail

        cur_node = nullptr;
        delete cur_node;

        std::cout << succ_mess << "element type: " << element_type << " \n";
        return;
    }
    else
    { // something went wrong
        std::cout << error_mess;
        return;
    }
}