/* next quiz, recursion and binary tree (november 4th)
BST

// we want search insert and delete to be log(n)

        50 -> level 0
        /     \
       40      70  -> level 1 
        /  \    /  \   
       20  45  60 80   -> level 2 
      /          \
    25          65   -> level 3

     leaf : 25,45, 65, 80 
height:3 

right side is above 50 , left side is below 50 

if the bst is balances, then the height of the tree is log(n)


if (root == nullptr){
    return 0;
} else{
    return (height(root->left), height(root->right)) +1 ;
}
}




    
*/