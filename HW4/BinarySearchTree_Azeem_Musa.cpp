/*
    Author  :   Musa Azeem
    Date    :   10/19/2022
    
    This file implements a binary search tree class for CSCE 350 HW4
    
    Binary Search Tree Usage:
*/
#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>
#include <vector>

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

        node* remove(node *n, const int key);

        node* insert(node* n, const int val){
            /*
                Recursive function to traverse tree and insert value in the
                correct location
            */
            if (!n){
                // Reach empty node, return value
                n = new node;
                n->val = val;
            }
            if (val < n->val) {
                // If value is less than current node, go left
                n->left = insert(n->left, val);
            }
            else if (val > n->val) {
                // If value is greater than current, go right
                n->right = insert(n->right, val);
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
                return nullptr;
            }

            // Print node values as traversed
            std::cout << n->val << " ";
            
            // Compare value to node's value to find which direction to traverse
            if (key == n->val) {
                return n;
            }
            if (key < n->val){
                return search(n->left, key);
            }
            else {
                return search(n->right, key);
            }
        };  

        // int search(node *n, int key, &std::vector<int> traversed) const;
        // void remove_all(node *n);

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
            // std::cout << n->val << " ";

            if(n->right && n->left)
                std::cout << n->val << ":  " << "  left: " << n->left->val << "  right: " << n->right->val << std::endl;
            else if (n->right)
                std::cout << n->val << ":  " << "  right: " << n->right->val << std::endl;
            else if (n->left)
                std::cout << n->val << ":  " << "  left: " << n->left->val << std::endl;
            else
                std::cout << n->val << ":  " << std::endl;

            // Then print all values to the right
            print_in_order(n->right);
        }


    public:
        BST() : root(nullptr) {};      // Default Constructor

        ~BST(){
            /*
                Destructor deletes all nodes
            */
            remove_all(root);
        };

        void insert(const int val){
            /*
                Insert value into binary search tree
                If tree is empty, this value becomes the root node

                Parameters:
                    val (int)   :   value to add to the tree
            */

            if (!root) {
                // If tree is empty, create root node
                root = new node;
                root->val = val;
            }

            // If there are already nodes in the tree, call recursive function to insert
            insert(root, val);
        };

        void remove(const int val);

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

        void print_in_order(){
            /*
                Print all values in the tree in order

                Parameters: None
                Returns:    None
            */
            print_in_order(root);
            std::cout << std::endl;
        };


    // friend std::ostream & operator<<(std::ostream &lhs, const BST &rhs){
    //     lhs << rhs.root->val;
    //     return lhs;
    // };

};










#endif