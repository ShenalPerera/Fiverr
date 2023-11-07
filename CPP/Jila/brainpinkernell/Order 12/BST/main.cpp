//    CS 211 Fall 2022 - Programming Assignment 03
//    Binary Search Tree methods
//
//    David C. Tuttle
//    Last Modified: 23 Mar 2023

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "BST.h"

using namespace std;

int main() {
    cout << boolalpha;

    // Create some test trees to perform tests with

    int t1_nodes[7] = {20, 10, 30, 5, 15, 25, 35};
    int t2_nodes[20] = {500, 250, 750, 150, 350,
                        650, 850, 125, 175, 325,
                        375, 625, 675, 825, 875,
                        110, 330, 670, 870, 873};
    int t3_nodes[6] = {6, 5, 4, 3, 2, 1};
    // t4 will be a tree with one node with value 1000
    // t5 will be an empty tree with no nodes

    // Pointers for rotation tests
    BSTNode *chPtr, *parPtr, *grPtr;

    // Create and populate the trees
    BST *tree_1 = new BST();
    for (int i=0; i<7; i++)
        tree_1->insert(t1_nodes[i]);

    BST *tree_2 = new BST();
    for (int i=0; i<20; i++)
        tree_2->insert(t2_nodes[i]);

    BST *tree_3 = new BST();
    for (int i=0; i<6; i++)
        tree_3->insert(t3_nodes[i]);

    BST *tree_4 = new BST();
    tree_4->insert(1000);

    BST *tree_5 = new BST();

    //*******************************************
    // Demonstration of exampleTraversal on tree_1
    //*******************************************

    // tree_1 start as:
    //               +----20----+
    //           +--10--+    +--30--+
    //           5     15    25    35

    cout << "*** READY FOR TESTING! *** \n";

    // UNCOMMENT LINES BELOW TO RUN TESTS USING ALL THE TREES

    cout << endl << "*** TREE 1 TEST ***";
    cout << endl << "Preorder traversal" << endl << "    ";
    tree_1->preorderTraversal();
    cout << endl << "Inorder traversal" << endl << "    ";
    tree_1->inorderTraversal();
    cout << endl << "Postorder traversal" << endl << "    ";
    tree_1->postorderTraversal();
    cout << endl << "Node count (should be 7): "
         << tree_1->countNodes() << endl;
    cout << "Leaf count (should be 4): "
         << tree_1->countLeaves() << endl;
    cout << "Interior count (should be 3): "
         << tree_1->countInterior() << endl;
    cout << "Tree height (should be 2): "
         << tree_1->treeHeight() << endl;
    cout << endl;

    cout << endl << "Traversal of tree_1" << endl << "  ";
    tree_1->breadthFirstTraversal();
    cout << endl;

    cout << endl << "Deleting interior node 10: "
         << tree_1->deleteNode(10) << endl;
    cout << endl << "Deleting interior node 20: "
         << tree_1->deleteNode(20) << endl;

   cout << endl << "Traversal of tree_1" << endl << "  ";
   tree_1->breadthFirstTraversal();
   cout << endl;

    cout << endl << "*** TREE 2 TEST ***";
    cout << endl << "Preorder traversal" << endl << "    ";
    tree_2->preorderTraversal();
    cout << endl << "Inorder traversal" << endl << "    ";
    tree_2->inorderTraversal();
    cout << endl << "Postorder traversal" << endl << "    ";
    tree_2->postorderTraversal();
    cout << endl << "Node count (should be 20): "
         << tree_2->countNodes() << endl;
    cout << "Leaf count (should be 8): "
         << tree_2->countLeaves() << endl;
    cout << "Interior count (should be 12): "
         << tree_2->countInterior() << endl;
    cout << "Tree height (should be 5): "
         << tree_2->treeHeight() << endl;
    cout << endl;

    cout << "Perform Left Rotation on tree_2" << endl;
    grPtr = tree_2->getRoot();
    parPtr = tree_2->getRoot()->getRightChild();
    chPtr = tree_2->getRoot()->getRightChild()->getRightChild();
    tree_2->leftRotation(*grPtr, *parPtr, *chPtr);


    cout << "Traversal of tree_2 at root" << endl << "  ";
    tree_2->breadthFirstTraversal();
    tree_2->preorderTraversal();
    cout << endl;

    cout << "Perform Right Rotation on tree_2" << endl;
    grPtr = tree_2->getRoot();
    parPtr = tree_2->getRoot()->getLeftChild();
    chPtr = tree_2->getRoot()->getLeftChild()->getLeftChild();
    tree_2->rightRotation(*grPtr, *parPtr, *chPtr);

    cout << endl << "Traversal of tree_2" << endl << "  ";
    tree_2->breadthFirstTraversal();
    tree_2->preorderTraversal();
    cout << endl;

    cout << "The next two calls should NOT perform rotations!" << endl;
    cout << "(The nodes are not in the correct relative positions)" << endl;
    tree_2->leftRotation(*grPtr, *parPtr, *chPtr);
    tree_2->rightRotation(*grPtr, *parPtr, *chPtr);

   cout << endl << "Traversal of tree_2" << endl << "  ";
   tree_2->breadthFirstTraversal();
   cout << endl;

    cout << endl << "*** TREE 3 TEST ***";
    cout << endl << "Preorder traversal" << endl << "    ";
    tree_3->preorderTraversal();
    cout << endl << "Inorder traversal" << endl << "    ";
    tree_3->inorderTraversal();
    cout << endl << "Postorder traversal" << endl << "    ";
    tree_3->postorderTraversal();
    cout << endl << "Node count (should be 6): "
         << tree_3->countNodes() << endl;
    cout << "Leaf count (should be 1): "
         << tree_3->countLeaves() << endl;
    cout << "Interior count (should be 5): "
         << tree_3->countInterior() << endl;
    cout << "Tree height (should be 5): "
         << tree_3->treeHeight() << endl;
    cout << endl;

    cout << endl << "*** TREE 4 TEST ***";
    cout << endl <<"Preorder traversal" << endl << "    ";
    tree_4->preorderTraversal();
    cout << endl << "Inorder traversal" << endl << "    ";
    tree_4->inorderTraversal();
    cout << endl << "Postorder traversal" << endl << "    ";
    tree_4->postorderTraversal();
    cout << endl << "Node count (should be 1): "
         << tree_4->countNodes() << endl;
    cout << "Leaf count (should be 1): "
         << tree_4->countLeaves() << endl;
    cout << "Interior count (should be 0): "
         << tree_4->countInterior() << endl;
    cout << "Tree height (should be 0): "
         << tree_4->treeHeight() << endl;
    cout << endl;

    cout << endl << "*** TREE 5 TEST ***";
    cout << endl << "Preorder traversal" << endl << "    ";
    tree_5->preorderTraversal();
    cout << endl << "Inorder traversal" << endl << "    ";
    tree_5->inorderTraversal();
    cout << endl << "Postorder traversal" << endl << "    ";
    tree_5->postorderTraversal();
    cout << endl << "Node count (should be 0): "
         << tree_5->countNodes() << endl;
    cout << "Leaf count (should be 0): "
         << tree_5->countLeaves() << endl;
    cout << "Interior count (should be 0): "
         << tree_5->countInterior() << endl;
    cout << "Tree height (should be -1): "
         << tree_5->treeHeight() << endl;
    cout << endl;

// // DELETE THE TREES

    tree_1->deleteAllNodes();
    cout << endl << "Tree 1 Node count (should be 0): "
         << tree_1->countNodes() << endl;
    delete tree_1;

    tree_2->deleteAllNodes();
    cout << "Tree 2 Node count (should be 0): "
         << tree_2->countNodes() << endl;
    delete tree_2;

    tree_3->deleteAllNodes();
    cout << "Tree 3 Node count (should be 0): "
         << tree_3->countNodes() << endl;
    delete tree_3;

    tree_4->deleteAllNodes();
    cout << "Tree 4 Node count (should be 0): "
         << tree_4->countNodes() << endl;
    delete tree_4;

    tree_5->deleteAllNodes();
    cout << "Tree 5 Node count (should be 0): "
         << tree_5->countNodes() << endl;
    delete tree_5;

    return EXIT_SUCCESS;
}