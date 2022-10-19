#include <iostream>
#include "BinarySearchTree_Azeem_Musa.cpp"

using std::cout;
using std::endl;

int main(int argv, char **argc){
    std::cout << "Musa Azeem Binary Search Tree" << std::endl;
    BST b;
    b.insert(10);
    b.insert(15);
    b.insert(13);
    b.insert(9);
    b.insert(13);
    b.print_in_order();
}