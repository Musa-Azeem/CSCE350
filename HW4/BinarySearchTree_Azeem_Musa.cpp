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

// Class header
class BST {
    private:
        node* root;                 // Root Node

        node* remove(node *n, int key);

        node* insert(node* n, int val){
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

        // int search(node *n, int key, &std::vector<int> traversed) const;
        // void remove_all(node *n);

        void remove_all(node* n){
            if (!n) {
                return;
            }
            remove_all(n->left);
            remove_all(n->right);
            delete n;
        };

        void print_in_order(node* n){
            if (!n){
                return;
            }
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
            print_in_order(n->right);
        }


    public:
        BST() : root(nullptr) {};      // Default Constructor

        ~BST(){
            // delete all nodes
            remove_all(root);
        };

        int insert(int val){
            /*
                Insert value into binay search tree
                If tree is empty, this value becomes the root node

                Parameters:
                    val (int)   :   value to add to the tree
                Returns:
                    int         :   returns 0 if successful, 0 if not
            */

            if (!root) {
                // If tree is empty, create root node
                root = new node;
                root->val = val;
                return 0;
            }

            // If there are already nodes in the tree, call recursive function to insert
            insert(root, val);
            return 0;
        };

        int remove(int val);
        // std::vector<int> search(int val, int &found) const;

        void print_in_order(){
            print_in_order(root);
            std::cout << std::endl;
        };


    // friend std::ostream & operator<<(std::ostream &lhs, const BST &rhs){
    //     lhs << rhs.root->val;
    //     return lhs;
    // };

};










#endif