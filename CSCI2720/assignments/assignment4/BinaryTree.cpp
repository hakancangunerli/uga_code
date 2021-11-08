#include "BinaryTree.h"
#include <iostream>
using namespace std;
template <class T>

// Author: Anjiya Kazani
// contructs tree 
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}

//Hakan Gunerli
// destructs the Tree
template <class T>
BinaryTree<T>::~BinaryTree()
{
    Destroy(root);
}


//  Hakan Gunerli 
// the actual code to destroy the tree, similar to the one at the slides. 
template <class T>
void BinaryTree<T>::Destroy(NodeType<T>* node)
{
    if (node)
    {
        Destroy(node->left);
        Destroy(node->right);
        delete node;
    }
}

// Hakan Gunerli
//Calls InsertItem to insert item
template <class T>
void BinaryTree<T>::insert(T &key)
{
    insertItem(root, key); // calling another function here
}

// Hakan Gunerli
//Does the actual insertion of node by comparison and checking for NULL
template <class T>
void BinaryTree<T>::insertItem(NodeType<T> *node, T &key)
{
    if (key < node->key)
    {
        if (node->left == NULL)
        { // if the left is null
            NodeType<T> *temporary = new NodeType<T>;
            temporary->right = NULL;
            temporary->left = NULL;
            temporary->key = key;
            node->left = temporary;
        }
        else
        { // if the left is not null
            insertItem(node->left, key);
        }
    }
    else if (key > node->key)
    { // if the key is greater than the current node
        if (node->right == NULL)
        {
            NodeType<T> *temporary = new NodeType<T>();
            temporary->right = NULL;
            temporary->left = NULL;
            temporary->key = key;
            node->right = temporary;
        }
        else
        { // if the right is not null
            insertItem(node->right, key);
        }
    }
    else
    { // if the key is equal to the current node (aka none of the tests above match)
        cout << "Duplicate key, this item already exists " << endl;
    }
}

// Hakan Gunerli
// to be able to call the insert function recursively, we'll call a function that takes in a node and a key
template <class T>
void BinaryTree<T>::insertionFirst(NodeType<T> *node, T &key)
{
    node->key = key;
    root = node;
}

//Hakan Gunerli
// We'll write the delete similar to the insert, there'll be a delete (named del bc delete is a keyword). Calls deleteItem. 
template <class T>
void BinaryTree<T>::del(T &key)
{
    deleteItem(root, key);
}

//Hakan Gunerli
//Remove a node with a key value equal to the parameter key’s value otherwise leave the tree unchanged (if the keyis not present). 
template <class T>
NodeType<T> *BinaryTree<T>::deleteItem(NodeType<T> *temporary, T &key)
{

    if (temporary == NULL) // handle empty case
    {
        return temporary;
    }

    if (temporary->key > key)
    {
        temporary->left = deleteItem(temporary->left, key);
        return temporary;
    }
    else if (temporary->key < key)
    {
        temporary->right = deleteItem(temporary->right, key);
        return temporary;
    }

    if (temporary->left == NULL) // if the left side is empty
    {
        NodeType<T> *temp = temporary->right; // create a temporary node
        delete temporary;                     // delete the current node
        return temp;                          // return the temporary node
    }
    else if (temporary->right == NULL)
    {
        // pretty much the same thing as above, but with the right side

        NodeType<T> *temp = temporary->left; // create a temporary node
        delete temporary;                    // delete the current node
        return temp;                         // return the temporary node
    }
    else
    {
         deleteWithTwoChildren(temporary, key); 
    }
    return temporary;
}


//Hakan Gunerli
//Where the node to be deleted has twochildren, replace the deleted node with its immediate predecessor or successor
template<class T>
NodeType<T>* BinaryTree<T>::deleteWithTwoChildren(NodeType<T>* tempRoot, T &key) {
    NodeType<T>* tempParent = tempRoot; // create a tempParent node
    NodeType<T>* tempChild = tempRoot->right; // create a tempChild node
    while (tempChild->left != NULL) { // while the left child is not null
        tempParent = tempChild;
        tempChild = tempChild->left;
    }
    if (tempParent != tempRoot) { // if the parent is not the root
        tempParent->left = tempChild->right;
    } else { // if the parent is the root
        tempParent->right = tempChild->right;
    }
    tempRoot->key = tempChild->key; // set the root to the child's key
    delete tempChild; // delete the child
    return tempRoot;
}

//Author Anjiya Kazani
//// Calls the recursive function CountNodes to count the// nodes in the tree.
template <class T>
int BinaryTree<T>::getLength() const{
    
    return CountNodes(root); // call recursive function
        
}

//Author Anjiya Kazani
//checks if node is null, if not then adds and increments
template <class T>
int BinaryTree<T>::CountNodes(NodeType<T>* node) const {  
if (node == NULL){ // if the node is null
    return 0;
}
else { // otherwise, add left and right nodes amount +1 
return (CountNodes(node->left) +CountNodes(node->right) + 1);
}
}


// Author: Anjiya Kazani
// calls recursive Search 
template <class T>
void BinaryTree<T>::retrieve(T &item, bool &found)
{
    search(root, item, found);
}

// Author: Anjiya Kazani
// Checks if root is null and serches in left and right subtree if found, then bool is true, if not then false.
template <class T>
bool BinaryTree<T>::search(NodeType<T> *tempRoot, T &key, bool &found)
{
    if (tempRoot == NULL)
    {
        found = false; // cannot find the item
        return found;
    }
    else if (key < tempRoot->key) // search left subtree
    {
        search(tempRoot->left, key, found);
    }
    else if (key > tempRoot->key) // search right subtree
    {
        search(tempRoot->right, key, found);
    }
    else
    {
        key = tempRoot->key; // after all those checks, we found the item
        found = true;
        return found;
    }
    return found;
}

// Author: Anjiya Kazani
// preOrder checks root node first then left node and right node 
template <class T>
void BinaryTree<T>::preOrder() const

{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Author: Anjiya Kazani
//checks root then left node then right
template <class T>
void BinaryTree<T>::preOrder(NodeType<T> *tempRoot) const
{
    // book definition
    // since this has to be a const, i have to call another
    // function that is not const

    if (tempRoot != NULL)
    {
        cout << tempRoot->key << " "; // root
        preOrder(tempRoot->left);     // left
        preOrder(tempRoot->right);    // right
    }
}

// Author: Anjiya Kazani
//checks left node then root then right
template <class T>
void BinaryTree<T>::inOrder() const
{
    // book definition
    // since this has to be a const, i have to call another
    // function that is not const

    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// Author: Anjiya Kazani
//checks left then root then right
template <class T>
void BinaryTree<T>::inOrder(NodeType<T> *tempRoot) const
{
    if (tempRoot != NULL)
    {
        inOrder(tempRoot->left);      // left
        cout << tempRoot->key << " "; // root
        inOrder(tempRoot->right);     // right
    }
}

// Author: Anjiya Kazani
//left right then node is checked
template <class T>
void BinaryTree<T>::postOrder() const
{
    // book definition
    // since this has to be a const, i have to call another
    // function that is not const

    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

// Author: Anjiya Kazani
//left right then node is checked
template <class T>
void BinaryTree<T>::postOrder(NodeType<T> *tempRoot) const
{
    if (tempRoot != NULL)
    {
        // left, right, root
        postOrder(tempRoot->left);
        postOrder(tempRoot->right);
        cout << tempRoot->key << " ";
    }
}

// Hakan Gunerli 
// gets the amount of single parents by iteration
template <class T>
int BinaryTree<T>::getNumSingleParent(NodeType<T> *temporaryRoot)
{
    int amountoftempParents = 0;
    if (temporaryRoot == NULL)
    { // base case
        return 0;
    }
    else if ((temporaryRoot->left == NULL && temporaryRoot->right != NULL) || (temporaryRoot->left != NULL && temporaryRoot->right == NULL))
    {                      // if there is only one tempChild
        amountoftempParents++; // if left is and right is null, then it is a single tempParent
    }
    amountoftempParents += (getNumSingleParent(temporaryRoot->left) + getNumSingleParent(temporaryRoot->right)); // recursion to keep adding them up
    return amountoftempParents;                                                                                  // return amount
}

// Hakan Gunerli
// recursively calls subtrees and adds them
template <class T>
T BinaryTree<T>::getSumOfSubtrees(NodeType<T> *temporaryRoot, T &key)
{
    if (temporaryRoot == NULL)
    { // base empty case
        return 0;
    }
    else if (key < temporaryRoot->key)
    {                                                      // search left subtree
        return getSumOfSubtrees(temporaryRoot->left, key); // recursive call
    }
    else if (key > temporaryRoot->key)
    {                                                       // search right subtree
        return getSumOfSubtrees(temporaryRoot->right, key); // recursive call
    }
    else
    {
        return (subtreeAdd(temporaryRoot->left) + subtreeAdd(temporaryRoot->right)); // return sum of subtrees by calling subtreeAdd below
    }
}

template <class T>
T BinaryTree<T>::subtreeAdd(NodeType<T> *temporaryRoot)
{
    if (temporaryRoot == NULL)
    { // base case empty
        return 0;
    }
    return (temporaryRoot->key + subtreeAdd(temporaryRoot->left) + subtreeAdd(temporaryRoot->right)); // recursive case just add them all up, mainly used for the getSumofSubtrees
}

// Hakan Gunerli 
// get the number of leaf nodes by calling recursively adding. 
template <class T>
int BinaryTree<T>::getNumLeafNodes(NodeType<T> *temporaryRoot)
{
    if (temporaryRoot == NULL)
    { // base case
        return 0;
    }
    else if (temporaryRoot->left == NULL && temporaryRoot->right == NULL)
    { // base case two: if both the right and the left is empty then it's a leaf node of 1
        return 1;
    }
    else
    {
        return (getNumLeafNodes(temporaryRoot->left) + getNumLeafNodes(temporaryRoot->right)); // otherwise, keep adding the left and right
    }
}

// at the end
template class BinaryTree<int>;



// TODO: don'\t forget to uncomment these. 

template class BinaryTree<float>;
template class BinaryTree<string>;