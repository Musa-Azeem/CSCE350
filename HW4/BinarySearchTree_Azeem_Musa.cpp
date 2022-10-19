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

// Class header
class BST {
    private:
        struct node{
            // Struct to represent a single node in the BST
            int val = 0;
            node *left = nullptr;
            node *right = nullptr;
        };

        node *root;

    public:
        BST();
        ~BST();
        int insert(int val);
        int remove(int val);
        std::vector<int> search(int val, int &found) const;
};

BST::BST() : root = nullptr {}

bool BST::insert(int val){
    /*
        Insert value into binay search tree
        If tree is empty, this value becomes the root node

        Parameters:
            val (int)   :   value to add to the tree
        Returns:
            int         :   returns 0 if successful, 1 if not
    */

    if (!root) {
        // If tree is empty, create root node
        root = new node;
        node->val = val;
        return 0
    }

    // insert into tree
}


BST::~BST(){
    // del all nodes
}

#endif