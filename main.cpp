#include <iostream>
#include "node.h"
#include "linked_list.h"

void main(){
    linked_list l1;

    l1.append(32);
    l1.append(20);
    l1.append(42);
    l1.append(55);

    l1.prepend(33);

    l1.remove(20);

    l1.prepend(1);

    l1.append(1337);
    
    l1.remove(1);
    
    l1.print_nodes();

}