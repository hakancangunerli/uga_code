#ifndef BINARYTREE_H
#define BINARY_H
// Nodetype definition 
// program should be generic 

template <class T>
struct NodeType
{
    T key;
    NodeType *left;
    NodeType *right;
};


template <class T>
class BinaryTree {
    public:
    NodeType<T> *root;
    BinaryTree();
    ~BinaryTree();
    void Destroy(NodeType<T> *node); 
    void insert(T &key); // this just calls the method below 
    void insertItem(NodeType<T> *node, T &key); // insert a node
    void insertionFirst(NodeType<T>* node, T &key);
    void del(T &key); // call the method below
    NodeType<T> *deleteItem(NodeType<T> *node, T &key); // this will actually delete the node 
    bool search(NodeType<T>* tempRoot, T &key, bool& found);
    NodeType<T>* deleteWithTwoChildren(NodeType<T>* tempRoot, T &key);
    void retrieve(T &item, bool &found); 
    void preOrder() const; 
    void preOrder(NodeType<T> *node) const;
    void inOrder() const;
    void inOrder(NodeType<T> *node) const;
    void postOrder() const;
    void postOrder(NodeType<T> *node) const;
    int getLength() const;
    int CountNodes(NodeType<T>* node) const;
    int getNumLeafNodes(NodeType<T>* tempRoot); 
    int getNumSingleParent(NodeType<T>* tempRoot);
    T getSumOfSubtrees(NodeType<T>* tempRoot, T &key);
    T subtreeAdd(NodeType<T>* tempRoot);
    
    private:
    NodeType<T> *left;
    NodeType<T> *right;
    int length;
};
#endif