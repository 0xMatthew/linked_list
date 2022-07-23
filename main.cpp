#include <iostream>
class node{
    public:
        int data;
        node * next;
};

void traverse_node(int n, node *starting_node){
    node * tmp = starting_node;
    int i = 0;
    while(tmp->next && i < n){
        std::cout << tmp->data << ", ";
        tmp = tmp->next;
        i++;
    }
}

void push_element_end(int data, node *starting_node){
    node *cur_node = new node;
    cur_node->data = data;
    cur_node->next = starting_node->next;
    starting_node->next = cur_node; 
}

void main(){


    node *head = new node;
    node *second = new node;
    node *third = new node;

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    
    push_element_end(69, third);
    traverse_node(4, head);

}