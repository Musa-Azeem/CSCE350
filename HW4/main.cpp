#include <iostream>
#include "BinarySearchTree_Azeem_Musa.cpp"

using std::cout;
using std::endl;
using std::cin;

int main(int argv, char **argc){
    std::cout << "Musa Azeem Binary Search Tree" << std::endl;
    BST bst;

    bool done = false;
    int input;
    cin >> input;

    while (!done) {
        switch(input){
            case 0:
                cin >> input;
                bst.insert(bst, input);
                break;
        }
        cin >> done;
    }

    b.insert(10);
    b.insert(15);
    b.insert(13);
    b.insert(9);
    b.insert(13);
    b.print_in_order();

    b.search(9);
    b.search(234);
}