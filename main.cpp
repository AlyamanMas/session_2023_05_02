//
//  main.cpp
//  LinkedList
//
//  Created by Esraa Hamdi Abbas on 11/1/21.
//
#include "LL.hpp"
#include <iostream>

using namespace std;

int main() {
    // insert code here...
    LinkedList list;
    list.add(5);
    list.add(7);
    list.add(3);
    list.add(9);
    cout<<"Original List"<<endl;
    list.ShowList();
    cout<<"Sorted List "<<endl;
    list.sort();
    list.ShowList();

    return 0;
}
