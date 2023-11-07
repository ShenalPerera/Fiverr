//    CS 211 Spring 2023 - Programming Assignment 03
//    Binary Search Trees in C++
//
//    David C. Tuttle
//    Last Modified: 23 Mar 2023

//----------------------------------------------------
// File: BST.cpp
// Purpose: Implementation file for a demonstration
// of a basic binary tree
//
//----------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "BST.h"

using namespace std;

//--------------------------------------------
// Function: insert(T)
// Purpose: insert a node into a binary tree
// Returns: void
//--------------------------------------------

bool BST::insert(T el) {
    // Pointers to keep track of where we are in descending
    // through the tree to find an insertion point
    BSTNode *p = root;
    BSTNode *prev = NULL;
    T currVal;

    // If tree is empty, then insert the first node

    if (this->isEmpty()) {
        root = new BSTNode(el);
        return true;
    }

    // Descend the tree for a proper place to put the input value
    // The input value will become a new leaf on the tree
    // NOTE: This does NOT perform any tree balancing!

    while (p != NULL) {
        // prev remembers where we were, so when ptr becomes
        // NULL, prev will point to the node where we will
        // attach the new value as a child
        prev = p;

        // Descend the tree until we hit a leaf - go left if value
        // is less than current node, go right if greater
        currVal = p->getEl();
        if (el < currVal)
            p = p->getLeftChild();
        else if (el > currVal)
            p = p->getRightChild();
        else {
            // If the value matches one already in the tree, we
            // DON'T add it to the tree and simply return
            cout << "Value NOT inserted - already in the tree! \n";
            return false;
        }
    }

    // If we get here, we've found the place to attach the new node
    // Create the new node and attach it to the node that prev
    // is pointing to

    if (el < prev->getEl()) {
        prev->setLeftChild(new BSTNode(el));
    }
    else {
        prev->setRightChild(new BSTNode(el));
    }
    return true;
}

//--------------------------------------------
// Function: isEmpty()
// Purpose: determine whether a BST has no nodes
// Returns: a boolean - true if empty
//--------------------------------------------

bool BST::isEmpty() const {
    return (root == NULL);
}

//--------------------------------------------
// Function: search(T)
// Purpose: search for a value in a binary tree
// Returns: a boolean - true is found, false if not
//--------------------------------------------

bool BST::search(int el) const {

    // Set ptr to root of tree (if tree is empty, ptr becomes NULL)
    BSTNode *p = root;
    T currVal;

    // Descend the tree to search for the given input value
    while (p != NULL) {

        // Descend the tree until we find a node with the given value
        // If we hit a leaf before finding the value, it's not in the tree
        currVal = p->getEl();
        if (el < currVal)
            p = p->getLeftChild();
        else if (el > currVal)
            p = p->getRightChild();
        else
            // Value found!  Return true
            return true;
    }

    // If we reach this point, then we fell out of the search loop
    // without finding anything.  Return false
    return false;
}

//--------------------------------------------
// Function: isLeaf(T)
// Purpose: search for a value in a leaf of a
// binary tree
// Returns: a boolean - true is found, false if not
//--------------------------------------------

bool BST::isLeaf(int el) const {

    // Set ptr to root of tree (if tree is empty, ptr becomes NULL)
    BSTNode *p = root;
    T currVal;

    // Descend the tree to search for the given input value
    while (p != NULL) {

        // Descend the tree until we find a node with the given value
        // If we hit a leaf before finding the value, it's not in the tree
        currVal = p->getEl();
        if (el < currVal)
            p = p->getLeftChild();
        else if (el > currVal)
            p = p->getRightChild();
        // if el == currVal, then we found the value!
        // If it's a leaf, return true, else return false
        else if (p->getLeftChild() == NULL &&
                 p->getRightChild() == NULL)
            return true;
        else
            return false;
    }

    // If we reach this point, then we fell out of the search loop
    // without finding the value at all.  This means it wasn't in the
    // tree, so we return false
    return false;
}

//--------------------------------------------
// Function: deleteLeaf(T)
// Purpose: delete node from tree if it's a leaf
// Returns: a boolean - true is deleted, false if not
//--------------------------------------------
bool BST::deleteLeaf(int el) {

    // Set ptr to root of tree (if tree is empty, ptr becomes NULL)
    // Also keep track of the previous (parent) node of the current node
    BSTNode *p = root;
    BSTNode *prev = NULL;
    T currVal;

    // Descend the tree to search for the given input value
    while (p != NULL) {
        // Descend the tree until we find a node with the given value
        // If we hit a leaf before finding the value, it's not in the tree
        currVal = p->getEl();
        if (el < currVal) {
            prev = p;
            p = p->getLeftChild();
        }
        else if (el > currVal) {
            prev = p;
            p = p->getRightChild();
        }
        // If el == currVal, then we found the value!
        // If it's a leaf, we can delete node and return true
        else if (isLeaf(el)) {
            // FIRST, check: is this the only node in the tree?
            // If so, we have to handle this special case!
            if (prev == NULL)
                root = NULL;
            // Don't forget to reset pointer on parent node!
            // But which way did we go to get here?
            else if (currVal < prev->getEl())
                // current node is the left child of prev
                prev->setLeftChild(NULL);
            else
                // current node is the right child of prev
                prev->setRightChild(NULL);
            // We've "chopped" the leaf off the tree - OK to delete
            delete p;
            return true;
        }
        else {
            // We found the value, but it's not a leaf, so it stays
            return false;
        }
    }

    // If we reach this point, then we fell out of the search loop
    // without finding the value at all.  This means it wasn't in the
    // tree, so we return false
    return false;
}

// An accessor method to get the BST's root pointer

BSTNode* BST::getRoot() const {
    return root;
}

//--------------------------------------------
// Function: breadthFirstTraversal()
// Purpose: Expects nothing, returns nothing
// Side Effects: prints values in breadth-first order
//--------------------------------------------

void BST::breadthFirstTraversal() const {
    const int QUEUE_SIZE = 50;
    BSTNode *queue[QUEUE_SIZE];
    int headIndex = 0;
    int tailIndex = 0;

    if (root == NULL) {
        cout << "*** Tree is empty ***" << endl;
        return;
    }

    queue[tailIndex] = root;

    while (headIndex != tailIndex + 1) {
        if (queue[headIndex]->getLeftChild() != NULL) {
           tailIndex = (tailIndex + 1) % QUEUE_SIZE;
           queue[tailIndex] = queue[headIndex]->getLeftChild();
        }
        if (queue[headIndex]->getRightChild() != NULL) {
           tailIndex = (tailIndex + 1) % QUEUE_SIZE;
           queue[tailIndex] = queue[headIndex]->getRightChild();
        }
        cout << queue[headIndex]->getEl() << " ";
        headIndex = (headIndex + 1) % QUEUE_SIZE;
    }
    cout << endl;
    return;
}

// **********************************************************
// ADD NEW METHODS HERE
// **********************************************************

void BST::preorderTraversal() const {
    preorderTraversalHelper(root);
}

void BST::inorderTraversal() const {
    inorderTraversalHelper(root);
}


void BST::postorderTraversal() const {
    postorderHelper(root);
}

int BST::countNodes() const {
    return countNodesHelper(root);
}

int BST::countLeaves() const {
    return countLeavesHelper(root);
}

int BST::countInterior() const {
    return countInteriorHelper(root);
}

int BST::treeHeight() const {
    return findTreeHeight(root);
}

void BST::deleteAllNodes() {
    deleteAllNodesHelper(root);
    root = nullptr;
}


bool BST::deleteNode(T el) {
    // Special case for empty tree
    if (root == nullptr) {
        return false;
    }

    // Search for the node containing the value to delete
    BSTNode* curr = root;
    BSTNode* parent = nullptr;
    bool found = false;
    while (curr != nullptr && !found) {
        if (curr->getEl() == el) {
            found = true;
        } else {
            parent = curr;
            if (el < curr->getEl()) {
                curr = curr->getLeftChild();
            } else {
                curr = curr->getRightChild();
            }
        }
    }

    // If the node wasn't found, return false
    if (!found) {
        return false;
    }
    // If the node has two children, replace it with the minimum element in the right subtree
    if (curr->getLeftChild() != nullptr && curr->getRightChild() != nullptr) {
        BSTNode* min = curr->getRightChild();
        parent = curr;
        while (min->getLeftChild() != nullptr) {
            parent = min;
            min = min->getLeftChild();
        }
        curr->setEl(min->getEl()) ;
        curr = min;
    }

    // If the node has zero or one child, update the parent pointer to point to the appropriate child
    BSTNode* child;
    if (curr->getLeftChild() != nullptr) {
        child = curr->getLeftChild();
    } else if (curr->getRightChild() != nullptr) {
        child = curr->getRightChild();
    } else {
        child = nullptr;
    }

    if (parent == nullptr) {
        root = child;
    } else if (parent->getLeftChild() == curr) {
        parent->setLeftChild(child);
    } else {
        parent->setRightChild(child);
    }
    delete curr;
    return true;
}


void BST::leftRotation(BSTNode &gr, BSTNode &par, BSTNode &ch) {
    // check that the parent is the correct parent of the child
    if (par.getLeftChild() != &ch && par.getRightChild() != &ch) {
        cout << "Error: child node is not a child of the parent node." << endl;
        return;
    }
    // check that the grandparent is the correct grandparent of the parent
    if (gr.getLeftChild() != &par && gr.getRightChild() != &par) {
        cout << "Error: parent node is not a child of the grandparent node." << endl;
        return;
    }
    // perform the rotation
    BSTNode *temp = ch.getLeftChild();
    ch.setLeftChild(&par);
    par.setRightChild(temp);
    if (gr.getLeftChild() == &par) {
        gr.setLeftChild(&ch);
    } else {
        gr.setRightChild(&ch);
    }
}


void BST::rightRotation(BSTNode &gr, BSTNode &par, BSTNode &ch) {
    // check that the parent is the correct parent of the child
    if (par.getLeftChild() != &ch && par.getRightChild() != &ch) {
        cout << "Error: child node is not a child of the parent node." << endl;
        return;
    }
    // check that the grandparent is the correct grandparent of the parent
    if (gr.getLeftChild() != &par && gr.getRightChild() != &par) {
        cout << "Error: parent node is not a child of the grandparent node." << endl;
        return;
    }
    // perform the rotation
    BSTNode *temp = ch.getRightChild();
    ch.setRightChild(&par);
    par.setLeftChild(temp);
    if (gr.getLeftChild() == &par) {
        gr.setLeftChild(&ch);
    } else {
        gr.setRightChild(&ch);
    }
}


// **********************************************************
// NEW HELPER METHODS HERE
// **********************************************************

void BST::preorderTraversalHelper(BSTNode *node) const {
    if (node != nullptr){
        cout << node->getEl() << " ";
        preorderTraversalHelper(node->getLeftChild());
        preorderTraversalHelper(node->getRightChild());
    }
}

void BST::inorderTraversalHelper(BSTNode *node) const {
    if (node != nullptr){
        inorderTraversalHelper(node->getLeftChild());
        cout << node->getEl() << " ";
        inorderTraversalHelper(node->getRightChild());
    }
}

void BST::postorderHelper(BSTNode* node) const {
    if (node != nullptr) {
        postorderHelper(node->getLeftChild());
        postorderHelper(node->getRightChild());
        cout << node->getEl() << " ";
    }
}


int BST::countNodesHelper(BSTNode* node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + countNodesHelper(node->getLeftChild()) + countNodesHelper(node->getRightChild());
}

int BST::countLeavesHelper(BSTNode* node) const {
    if (node == nullptr) {
        return 0;
    }
    if (node->getLeftChild() == nullptr && node->getRightChild() == nullptr) {
        return 1;
    }
    return countLeavesHelper(node->getLeftChild()) + countLeavesHelper(node->getRightChild());
}


int BST::countInteriorHelper(BSTNode* node) const {
    if (node == nullptr) {
        return 0;
    } else if (node->getLeftChild() == nullptr && node->getRightChild() == nullptr) {
        return 0;
    } else {
        return 1 + countInteriorHelper(node->getLeftChild()) + countInteriorHelper(node->getRightChild());
    }
}

int BST::findTreeHeight(BSTNode* node) const {
    if (node == nullptr) {
        return -1; // height of an empty tree is -1
    }
    int leftHeight = findTreeHeight(node->getLeftChild());
    int rightHeight = findTreeHeight(node->getRightChild());
    return 1 + std::max(leftHeight, rightHeight);
}

void BST::deleteAllNodesHelper(BSTNode* node) {
    if (node == nullptr) {
        return;
    }
    deleteAllNodesHelper(node->getLeftChild());
    deleteAllNodesHelper(node->getRightChild());
    delete node;
}