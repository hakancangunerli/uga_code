Hakan Can Gunerli #811727237 hcg41790 

Anjiya Kazani #811921000 afk01397 


## To run: 
compile using 

` make ` 

delete using 

` make clean ` 

to run the code, use:


`./main [filename]`

## who did what

Hakan did:

    void Destroy(NodeType<T> *node); 
    void insert(T &key); 
    void insertItem(NodeType<T> *node, T &key);
    void insertionFirst(NodeType<T>* node, T &key);
    void del(T &key);
    NodeType<T> *deleteItem(NodeType<T> *node, T &key); 
    NodeType<T>* deleteWithTwoChildren(NodeType<T>* tempRoot, T &key);
    int getNumLeafNodes(NodeType<T>* tempRoot); 
    int getNumSingleParent(NodeType<T>* tempRoot);
    T getSumOfSubtrees(NodeType<T>* tempRoot, T &key);

Anjiya did: 

    void preOrder() const; 
    void preOrder(NodeType<T> *node) const;
    void inOrder() const;
    void inOrder(NodeType<T> *node) const;
    void postOrder() const;
    void postOrder(NodeType<T> *node) const;
    int getLength() const;
    int CountNodes(NodeType<T>* node) const;
    bool search(NodeType<T>* tempRoot, T &key, bool& found);
    void retrieve(T &item, bool &found); 
    T subtreeAdd(NodeType<T>* tempRoot);

  
## Pseudocode getNumSingleParent: O(n): 
if node is null return 0,  | O(1) 

if (root is null (which is the base case) return 0)

if (left root equal NULL and right does not equal NULL or vice versa meaning theres only one child then the amout of parents increments, its a single parent.

then theres a recursion to keep adding amount of temp parents and then return them. 


### Master theorem for getNumSingleParent
It's monotonically increasing 

  it's getting divided by two since we're tring to cut the problem into left and right tree

  thus 1 = 2^1, which is O(n)


## Pseudocode getNumLeafNodes: 
if node is null return 0,  | O(1) 

if it's not, check if the root on the left or the right are null, if they are it's only one leaf node, return 1 | O(1)
    
if none of these match then add the number of left nodes from the right and the left   | O(n)

Each time this function is adding the amount of leafnodes, it'd be O(n) in total. 


### Master theorem for getNumLeafNodes
It's monotonically increasing 

  it's getting divided by two since we're tring to cut the problem into left and right tree

  thus 1 = 2^1, which is O(n)



## Pseudocode getSumofSubtrees: O(n)
if node is null return 0, | O(1) 

 if (key is less than temporaryRoot's key that means it's the left so we have to recursively call the left and compare with key 

 if (key is more than temporaryRoot's key that means it's the right so we have to recursively call the right and compare with key
  
if it's not the case, then we have to return the combination of the right subtreeAdd right and SubtreeAdd Left.

subtreeAdd checks if the root is null and if it is it returns 0  otherwise it recursively calls itself to add the left and right 

### Master theorem for getSumofSubtrees
It's monotonically increasing 

  it's getting divided by two since we're tring to cut the problem into left and right tree

  thus 1 = 2^1, which is O(n)

