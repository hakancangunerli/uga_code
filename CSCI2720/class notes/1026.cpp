/* 

check slide 57 about the importance of balance 

two base cases: if the item is present, and if the item is not present 
bool search (tree, item){
if (tree == NULL){
    return false;
} else if (item == tree->data){
    return true;
} else if (item < tree->data){
    return search(tree->left, item);
}else{
    return search(tree->right, item);
}
}
}

tree traversal 

three general ways to do it 
Inorder 20, 50, 70 (left, root, right)
Preorder  50,20,  70 (root, left, right) [ you visit the parent before the children left, right]
Postorder 20, 70, 50 (left, right, root) [ you visit the children before you visit the parent ]


Inorder(tree != NULL){
    Inorder(tree->left);
    cout << tree->data << " ";
    Inorder(tree->right); 
}
Preoder(tree != NULL){
    cout << tree->data << " ";
    Preoder(tree->left);
    Preoder(tree->right);
}

Postorder (tree != NULL){
    Postorder(tree->left);
    Postorder(tree->right);
    cout << tree->data << " ";
}

1. deleting a  leaf node 
2. deleting a node with one child
3. deleting a node with two children    

for iterative 
while (nodePtr != NULL){
    if (item < nodePtr->info){
        parentPtr = nodePtr;
        nodePtr = nodePtr->leftPtr;
    }
}

*/ 