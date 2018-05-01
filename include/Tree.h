#ifndef TREE_H
#define TREE_H

#include<iostream>
using namespace std;

template<typename T>
class TreeNode{
    public:
        TreeNode(const T);
        ~TreeNode();
        T getData();
        TreeNode<T>* getLeftChild();
        TreeNode<T>* getRightChild();

        void setData(const T);
        void setLeftChild(const TreeNode*);
        void setRightChild(const TreeNode*);

    private:
        T *leftChild, *rightChild;
        T data;
};

template<typename T>
TreeNode<T>::TreeNode(const T data){
    setData(data);
    setLeftChild(0);
    setRightChild(0);
    cout << "TreeNode created " << getData() << endl;
}

template<typename T>
TreeNode<T>::~TreeNode(){
    cout << "Deleting TreeNode " << getData() << endl;
}

template<typename T>
T TreeNode<T>::getData(){
    return data;
}

template<typename T>
TreeNode<T>* TreeNode<T>::getLeftChild(){
    return (TreeNode<T>*)(leftChild);
}

template<typename T>
TreeNode<T>* TreeNode<T>::getRightChild(){
    return (TreeNode<T>*)(rightChild);
}

template<typename T>
void TreeNode<T>::setData(const T data){
    this->data = data;
}

template<typename T>
void TreeNode<T>::setLeftChild(const TreeNode<T>* lc){
    this->leftChild = (T*)lc;
}

template<typename T>
void TreeNode<T>::setRightChild(const TreeNode<T>* rc){
    this->rightChild = (T*)rc;
}

template<typename T>
class Tree{
    public:
        /** Default constructor */
        Tree();
        /** Default destructor */
        virtual ~Tree();
        TreeNode<T>* getRoot();
        void setRoot(TreeNode<T>*);

        void deleteTree();
        void deleteTreeUtil(TreeNode<T> *);

        unsigned int getCount();
        unsigned int getCountUtil(TreeNode<T> *);

        void InorderTraversalRecursive();
        void InorderTraversalRecursiveUtil(TreeNode<T> *);

        void PreorderTraversalRecursive();
        void PreorderTraversalRecursiveUtil(TreeNode<T> *);

        void PostorderTraversalRecursive();
        void PostorderTraversalRecursiveUtil(TreeNode<T> *);

        bool areTreesIdentical(TreeNode<T>* , TreeNode<T>* );
        bool areTreesIdentical(Tree<T>* );


    protected:

    private:
        TreeNode<T>* root;
};

template<typename T>
Tree<T>::Tree(){
    setRoot(0);
    cout << "Tree created." << endl;
}

template<typename T>
Tree<T>::~Tree(){
    deleteTree();
    setRoot(0);
    cout << "Tree deleted." << endl;
}

template<typename T>
TreeNode<T>* Tree<T>::getRoot(){
    return root;
}

template<typename T>
void Tree<T>::setRoot(TreeNode<T> *node){
    root = node;
}

template<typename T>
void Tree<T>::deleteTree(){
    return deleteTreeUtil(getRoot());
}

template<typename T>
void Tree<T>::deleteTreeUtil(TreeNode<T> *root){
    //cout << "Yet again";
    char ch;
    //cin >> ch;
    if(root == 0){
        return;
    }else{
        deleteTreeUtil(root->getLeftChild());
        deleteTreeUtil(root->getRightChild());
        delete root;
        root = 0;
    }
}

template<typename T>
unsigned int Tree<T>::getCountUtil(TreeNode<T> *root){
    if(root == 0){
        return 0;
    }

    unsigned int count = 0;
    return 1+getCountUtil(root->getLeftChild())+getCountUtil(root->getRightChild());
}

template<typename T>
unsigned int Tree<T>::getCount(){
    return getCountUtil(getRoot());
}

template<typename T>
void Tree<T>::InorderTraversalRecursive(){
    if(0 == getRoot()){
        cout << "Tree Empty." << endl;
    }else{
        cout << " Inorder traversal : " << endl;
        InorderTraversalRecursiveUtil(getRoot());
        cout << endl;
    }
}

template<typename T>
void Tree<T>::InorderTraversalRecursiveUtil(TreeNode<T> *root){
    if(root){
        InorderTraversalRecursiveUtil(root->getLeftChild());
        cout << " " << root->getData();
        InorderTraversalRecursiveUtil(root->getRightChild());
    }
}

template<typename T>
void Tree<T>::PreorderTraversalRecursive(){
    if(0 == getRoot()){
        cout << "Tree Empty." << endl;
    }else{
        cout << " Preorder traversal : " << endl;
        PreorderTraversalRecursiveUtil(getRoot());
        cout << endl;
    }
}

template<typename T>
void Tree<T>::PreorderTraversalRecursiveUtil(TreeNode<T> *root){
    if(root){
        cout << " " << root->getData();
        PreorderTraversalRecursiveUtil(root->getLeftChild());
        PreorderTraversalRecursiveUtil(root->getRightChild());
    }
}

template<typename T>
void Tree<T>::PostorderTraversalRecursive(){
    if(0 == getRoot()){
        cout << "Tree Empty." << endl;
    }else{
        cout << " Postorder traversal : " << endl;
        PostorderTraversalRecursiveUtil(getRoot());
        cout << endl;
    }
}

template<typename T>
void Tree<T>::PostorderTraversalRecursiveUtil(TreeNode<T> *root){
    if(root){
        PostorderTraversalRecursiveUtil(root->getLeftChild());
        PostorderTraversalRecursiveUtil(root->getRightChild());
        cout << " " << root->getData();

    }
}

template<typename T>
bool Tree<T>::areTreesIdentical(TreeNode<T>* root1, TreeNode<T>* root2){
    if(root1 == 0 && root2 == 0){
        return true;
    }else if(root1 ==0 || root2 == 0){
        return false;
    }else{
        return((root1->getData() == root2->getData()) &&
               (areTreesIdentical(root1->getLeftChild(), root2->getLeftChild())) &&
               (areTreesIdentical(root1->getRightChild(), root2->getRightChild())));
    }
}

template<typename T>
bool Tree<T>::areTreesIdentical(Tree<T>* tree2){
    return areTreesIdentical(getRoot(), tree2->getRoot());
}
#endif // TREE_H
