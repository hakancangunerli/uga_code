#ifndef BTREE_H
#define BTREE_H

#include "ItemType.h"
#include "Node.h"

class BinaryTree {

public:
    Node *root;

    BinaryTree();
    
    ~BinaryTree();
    void destroy(Node*& tree);
    
    void insert(ItemType item);
    void putItem(Node*& tree, ItemType item);
    
    void deleteItem(ItemType item);
    void deleteFind(Node*& tree, ItemType item);
    void deleteNode(Node*& tree);
    void getPredecessor(Node* tree, ItemType& data);
    
    void retrieve(Node* node, ItemType &item, bool &found) const;
    
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
    void printTreeIn(Node* tree) const;
    void printTreePre(Node* tree) const;
    void printTreePost(Node* tree) const;
    
    int getLength() const;
    int countNodes(Node* tree) const;
    
    void getSameLevelNonsiblings(ItemType &item);
    
};

#endif
