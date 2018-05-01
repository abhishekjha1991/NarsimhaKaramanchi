#include<iostream>

#include "Tree.h"

using namespace std;

inline void BasicTreeCreationAndDeletionTesting(){
    Tree<char> *tree = new Tree<char>();
    cout << "tree->getCount() = " << tree->getCount() << endl;
    tree->InorderTraversalRecursive();
    tree->PreorderTraversalRecursive();
    tree->PostorderTraversalRecursive();
    TreeNode<char> *root = new TreeNode<char>('0');
    tree->setRoot(root);
    TreeNode<char> *firstTreeNode = new TreeNode<char>('1');
    root->setLeftChild(firstTreeNode);
    TreeNode<char> *secondTreeNode = new TreeNode<char>('2');
    root->setRightChild(secondTreeNode);
    TreeNode<char> *fifthTreeNode = new TreeNode<char>('5');
    secondTreeNode->setLeftChild(fifthTreeNode);
    TreeNode<char> *sixthTreeNode = new TreeNode<char>('6');
    secondTreeNode->setRightChild(sixthTreeNode);
    TreeNode<char> *thirdTreeNode = new TreeNode<char>('3');
    firstTreeNode->setLeftChild(thirdTreeNode);
    TreeNode<char> *fourthTreeNode = new TreeNode<char>('4');
    firstTreeNode->setRightChild(fourthTreeNode);
    cout << "tree->getCount() = " << tree->getCount() << endl;
    tree->InorderTraversalRecursive();
    tree->PreorderTraversalRecursive();
    tree->PostorderTraversalRecursive();
    //tree->deleteTree();
    tree->~Tree();
}

inline void testIfIdenticalTrees(){
    /*Tree<char> *tree1 = new Tree<char>();
    Tree<char> *tree2 = new Tree<char>();
    cout << "Two empty trees are identical : ";
    tree1->areTreesIdentical(tree2) == 1 << endl;

    tree1->deleteTree();
    tree2->deleteTree();*/
}
