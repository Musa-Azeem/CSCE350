#include <iostream>
#include "BinarySearchTree_Azeem_Musa.cpp"

void print_usage();

int main(int argv, char **argc){

    std::cout << "------------- Welcome to Binary Search Tree -------------" << std::endl;

    BST bst;

    bool done = false;
    int choice;
    int input;

    while (!done) {
        choice = 0;
        print_usage();
        std::cin >> choice;

        switch(choice){
            case 0:
                // Print tree
                std::cout << "Tree: ";
                bst.print_in_order();
                break;
            case 1:
                // Insert a value
                std::cout << "Enter the value to insert into the tree: ";
                std::cin >> input;
                bst.insert(input);
                break;
            case 2:
                // Remove a value
                std::cout << "Enter the value to remove from the tree: ";
                std::cin >> input;
                break;
            case 3:
                // Search for a value
                std::cout << "Enter the value to search the tree for: ";
                std::cin >> input;
                bst.search(input);
                break;
            case 4:
                // Quit program
                done = true;
                break;
            default:
                std::cout << "Invalid Input" << std::endl;
                break;
        }
    }
    
    std::cout << "Goodbye" << std::endl;
}

void print_usage(){
    std::cout << "Usage:" << std::endl;
    std::cout << "\tEnter 0 to print the Binary Search Tree in order" << std::endl;
    std::cout << "\tEnter 1 to insert a value in the Binary Search Tree" << std::endl;
    std::cout << "\tEnter 2 to remove a value in the Binary Search Tree" << std::endl;
    std::cout << "\tEnter 3 to search for a value in the Binary Search Tree" << std::endl;
    std::cout << "\tEnter 4 to quit" << std::endl;
}