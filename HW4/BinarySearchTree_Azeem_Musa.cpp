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
                // Value not in tree
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
                else if (!n->right){     // Node has left child
                    node* tmp = n->left;
                    delete n;
                    n = nullptr;
                    return tmp;
                }
                else if (!n->left){ // Node has right child
                    node* tmp = n->right;
                    delete n;
                    n = nullptr;
                    return tmp;
                }
                // Case 3: Node has two children
                    // Replace node with the minimum value of its right subtree
                    // Delete duplicate descendant
                // Find minimum in right subtree of n
                node* tmp = find_min(n->right);
                // Set value of current node with minimum value
                n->val = tmp->val;
                // Remove the duplicate in the right subtree of current node
                remove(n->right, n->val);
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
            if (!(n->left)) {
                return n;
            }
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
            remove(root, key);
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


        void print_in_order() {
            /*
                Print all values in the tree in order

                Parameters: None
                Returns:    None
            */
            print_in_order(root);
            std::cout << std::endl;
        };
};

#endif