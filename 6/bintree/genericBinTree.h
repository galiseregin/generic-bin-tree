#ifndef __GEN_BIN_TREE_H
#define __GEN_BIN_TREE_H

#include "result.h"

typedef struct BinTree BinTree;
typedef void* Ptr;

typedef struct {
    Ptr     (*allocate) ();
    void    (*destroy)  (Ptr);
    void    (*copy)     (Ptr,Ptr);
    int     (*compare)  (Ptr,Ptr);
    void    (*print)    (Ptr);
} BinTreeFunctions;

BinTree* createBinTree(BinTreeFunctions funcs);
BinTree* createBinTreeFromArr(BinTreeFunctions funcs, Ptr arr[], int size);
BinTree* findInBinTree(BinTree* root, Ptr val);
Ptr getValueInRoot(BinTree* root);
Result addToBinTree(BinTree* root, Ptr val);
Result removeFromBinTree(BinTree** rootPtr, Ptr val);
int sizeOfBinTree(BinTree* root);
void destroyBinTree(BinTree* root);
void printPreOrder(BinTree* root);
void printInOrder(BinTree* root);
void printPostOrder(BinTree* root);

#endif
