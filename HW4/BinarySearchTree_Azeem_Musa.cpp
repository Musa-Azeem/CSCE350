/*
    Author  :   Musa Azeem
    Date    :   10/19/2022
    
    This file implements a binary search tree class for CSCE 350 HW4
    
    Binary Search Tree Usage:
        print_in_order() :  print the tree in order

        insert(val) :       insert a value into the tree
            val (int) :     integer value to insert into the tree
        
        remove(key) :       remove a value from the tree
            key (int) :     integer value to remove from the tree

        search(key) :       Search for a value in the tree
            key (int) :     integer value to search for
*/

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>

// Struct to represent node in tree
struct node{
    // Struct to represent a single node in the BST
    int val = 0;
    node *left = nullptr;
    node *right = nullptr;
};

// Binary Search Tree Class
class BST {
    private:
        node* root;                 // Root Node


        void print_in_order(node* n){
            /*
                Recursive function to print the tree values in order
            */
            if (!n){
                // Reach end of branch
                return;
            }
            // First print all values to the left
            print_in_order(n->left);

            // Pring current value
            std::cout << n->val << " ";

            // Then print all values to the right
            print_in_order(n->right);
        };


        node* insert(node* n, const int val){
            /*
                Recursive function to traverse tree and insert value in the
                correct location
                If the value is already in the tree, nothing is done
            */
            if (!n){
                // Reach empty node, create new new node for value
                n = new node;
                n->val = val;
            }
            if (val < n->val) {
                // If value is less than current node, go left
                n->left = insert(n->left, val);
            }
            else if (val > n->val) {
                // If value is greater than current node, go right
                n->right = insert(n->right, val);
            }
            return n;
        };


        node* remove(node *n, const int key){
            /*
                Recursive function to remove key value from tree
                If the value is not found, nothing is done
            */
            if (!n) {
                // Leaf node reached, value not in tree
                return n;
            }
            if (key == n->val) {
                // Value is found, so remove it: Three Cases

                // Case 1: Node has no children - Just delete it
                if (!n->left and !n->right) {
                    delete n;
                    n = nullptr;
                    return n;
                }

                // Case 2: Node has one child - Replace node with its child
                // Node has left child
                else if (!n->right){     
                    node* tmp = n->left;
                    delete n;
                    return tmp;
                }
                // Node has right child
                else if (!n->left){ 
                    node* tmp = n->right;
                    delete n;
                    return tmp;
                }

                // Case 3: Node has two children
                /*
                    1) Find the minimum value in the right subtree of the node
                    2) Replace node with the minimum value of its right subtree
                    3) Delete duplicate descendant in the right subtree
                */

                // 1) Find minimum value in the right subtree of n
                node* tmp = find_min(n->right);

                // 2) Set value of current node with minimum value
                n->val = tmp->val;

                // 3) Remove the duplicate in the right subtree of current node
                n->right = remove(n->right, n->val);
                return n;
            }

            if (key < n->val) {
                // If key is less than current node, go left
                n->left = remove(n->left, key);
            }
            else {
                // If key is greater than current, go right
                n->right = remove(n->right, key);
            }
            return n;
        };


        node* search(node* n, const int key) const{
            /*
                Recursive function to search for a key in the tree
                Function prints the value of every node traversed
                If key is not found, a null node is returned
                If key is found, the node containing the key is returned
            */

            if (!n) {
                // If leaf branch is reached, value was not found
                return n;
            }

            // Print node values as traversed
            std::cout << n->val << " ";
            
            // Compare value to node's value to find which direction to traverse
            if (key == n->val) {
                // Value was found
                return n;
            }
            if (key < n->val){
                // If key is less than current node, go left
                return search(n->left, key);
            }
            else {
                // If key is greater than current, go right
                return search(n->right, key);
            }
        };  


        node* find_min(node* n){
            /*
                Recursive function to find minumum value in a tree
            */
            if (!(n->left)) {
                // If node has no left child, it is the minimum
                return n;
            }
            // Keep going left
            return find_min(n->left);
        };


        void remove_all(node* n){
            /*
                Recursive function to deallocate memory for all nodes in tree
            */
            if (!n) {
                // Reach end of branch
                return;
            }
            // Remove all nodes in left and right children
            remove_all(n->left);
            remove_all(n->right);
            delete n;
        };


    public:
        BST() : root(nullptr) {};      // Default Constructor

        ~BST(){
            /*
                Destructor deletes all nodes
            */
            remove_all(root);
        };

        
        void print_in_order() {
            /*
                Print all values in the tree in order

                Parameters: None
                Returns:    None
            */
            print_in_order(root);
            std::cout << std::endl;
        };


        void insert(const int val){
            /*
                Insert value into binary search tree
                If tree is empty, this value becomes the root node
                If the tree is empty or the value is already in the tree, 
                    nothing is done

                Parameters:
                    val (int)   :   value to add to the tree
            */

            if (!root) {
                // If tree is empty, create root node
                root = new node;
                root->val = val;
            }

            // If not empty, call recursive function to insert
            insert(root, val);
        };


        void remove(const int key) {
            /*
                Remove the key value from the tree
                If the key value is not in the tree, nothing is done

                Parameters:
                    key (int)   :   Value to remove from the tree
            */
            if (!root) {
                // If tree is empty, do nothing
                return;
            }

            // If not empty, call recursive function to remove
            root = remove(root, key);
        }


        bool search(const int key) const {
            /*
                Search for a key in the binary search tree
                Function will print the value of all nodes traversed during search
                It will also print whether the key was found or not

                Parameters:
                    key (int)   :   value to search for

                Returns:
                    bool        :   true if value is found, false if not  
            */

            std::cout << "Nodes Traversed: ";
            if (search(root, key)) {
                std::cout << "\nSearch key was found." << std::endl;
                return true;
            }
            else{
                std::cout << "\nSearch key was not found." << std::endl;
                return false;
            }
        };  
};


// Driver code

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
                bst.remove(input);
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

#endif