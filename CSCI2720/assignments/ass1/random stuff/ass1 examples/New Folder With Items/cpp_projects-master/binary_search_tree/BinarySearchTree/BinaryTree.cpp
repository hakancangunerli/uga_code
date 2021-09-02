#include "ItemType.h"
#include "Node.h"
#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree(){
    root=NULL;
} //default constructor

BinaryTree::~BinaryTree(){
    destroy(root);
} //default destructor

void BinaryTree::destroy(Node*& tree) {
    //desctructor helper function
    if (tree!=NULL) {
        destroy(tree->left);
        destroy(tree->right);
        delete tree;
    }
}

void BinaryTree::insert(ItemType item){
    putItem(root,item);
}

void BinaryTree::putItem(Node*& tree, ItemType item) {
    if (tree==NULL) {
    //insertion place found.
      tree = new Node;
      tree->right=NULL;
      tree->left=NULL;
      tree->key=item;
    }
    else if (item.compareTo(tree->key)==LESS) {
        putItem(tree->left,item);
    } //if smaller than parent
    else {
        putItem(tree->right,item);
    } //if greater than parent
} //inserts item into tree


void BinaryTree::deleteItem(ItemType item){
    deleteFind(root, item);
} //calls the recursive function deletefind to find the appropriate node to delete

void BinaryTree::deleteFind(Node*& tree, ItemType item){
    //deletes item from tree
    if (item.compareTo(tree->key)==LESS) {
        deleteFind(tree->left,item);
    }
    else if (item.compareTo(tree->key)==GREATER) {
        deleteFind(tree->right,item);
    }
    else {
        deleteNode(tree);
    }
}
void BinaryTree::deleteNode(Node*& tree) {
    ItemType data;
    Node* tempPtr;
    tempPtr = tree;
    if (tree->left==NULL) {
        tree = tree->right;
        delete tempPtr;
    }
    else if (tree->right ==NULL) {
        tree = tree->left;
        delete tempPtr;
    }
    else {
      getPredecessor(tree->left,data);
      tree->key=data;
      deleteFind(tree->left,data); //deletes predecessor node
    }
}

void BinaryTree::getPredecessor(Node* tree, ItemType& data) {
    //sets datat to the key of the rightmost node in tree
    while (tree->right !=NULL) {
        tree=tree->right;
    }
    data= tree->key;
}

void BinaryTree::retrieve(Node* node, ItemType &item, bool &found) const{
    if (node==NULL) {
        found = false;
    }
    else if (item.compareTo(node->key)==LESS) {
        retrieve(node->left, item, found);
    }
    else if (item.compareTo(node->key)==GREATER) {
        retrieve(node->right,item,found);
    }
    else {
        found = true;
    }
} //retrieves item by returning true if found

void BinaryTree::preOrder() const{
    printTreePre(this->root);
}

void BinaryTree::inOrder() const{
    printTreeIn(this->root);
}

void BinaryTree::postOrder() const{
    printTreePost(this->root);
}

void BinaryTree::printTreeIn(Node* tree) const {
    if (tree!=NULL) {
        printTreeIn(tree->left);
        cout << tree->key.getValue() << " ";
        printTreeIn(tree->right);
    }
}

void BinaryTree::printTreePre(Node* tree) const {
    if (tree!=NULL) {
        cout << tree->key.getValue() << " ";
        printTreePre(tree->left);
        printTreePre(tree->right);
    }
}

void BinaryTree::printTreePost(Node* tree) const {
    if (tree!=NULL) {
        printTreePost(tree->left);
        printTreePost(tree->right);
        cout << tree->key.getValue() << " ";
    }
}

int BinaryTree::getLength() const{
    return countNodes(root);
} //returns length of a list as an int

void BinaryTree::getSameLevelNonsiblings(ItemType &item){
}

int BinaryTree::countNodes(Node* tree) const{
    if (tree==NULL) {
        return 0;
    }
    else {
        return countNodes(tree->left) + countNodes(tree->right) + 1;
    }
} //returns length of a list as an int