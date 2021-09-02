#ifndef NODETYPE_H
#define NODETYPE_H

using namespace std;

class NodeType {
public:
    ItemType data;
    NodeType *next;
    NodeType *back;
};

#endif
