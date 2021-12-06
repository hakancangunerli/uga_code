/* 

ASSIGNMENT 5:
you can use the integer array to do it as a data member and pass that to all the __FLT_EVAL_METHOD_TS_18661_3__

N complexity arrays should be 8-10 digits 
Nlog(n) complexity arrays should be 4-6 digits

if it's not a data compared with another data, it's NOT complexity. 



RBT:
root is always black, all leaves that are null are black
red node cannot have a red child 


delete is complicated, when you delete the black node it's going to be a problem. only focus on the insert. Not gonna talk about the delete operation in an exam. 

insert three cases:
cannot add a node as a black node. always add a red node.

1. if a parent of that node is black, do nothing. 
2. if a parent of that node is red, then you have to check if the uncle is red or black. (since red cannot have a red child, if uncle is red, we'd have to do recoloring. ) if uncle is black, you'd have to do restructring. (restruction is the rotation operation, you'd switch the color p and g as well)
 
<add the picture you took> 

<add the other picture> 

learn how to do rbl and avl tree and how you insert steps 

*/ 