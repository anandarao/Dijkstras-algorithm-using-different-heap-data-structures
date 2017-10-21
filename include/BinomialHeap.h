
#include "Heap.h"

#ifndef BINOMIALHEAP_H
#define BINOMIALHEAP_H

struct BNode
{
    pair<int,int> data;
    int degree;
    BNode *child, *sibling, *parent;

    explicit BNode(pair<int, int>);
};

class BinomialHeap: public Heap
{
    public:
        BinomialHeap();
        pair<int, int> top();
        pair<int, int> pop();
        void push(pair<int, int>);
        int getOperations();
        void printTree(BNode *h);
        void printHeap();
    protected:
        pair<int, int> extractMin();
        void insertATreeInHeap(BNode *tree);
        list<BNode*> removeMinFromTreeReturnBHeap(BNode *tree);
        BNode* mergeBinomialTrees(BNode *b1, BNode *b2);
        list<BNode*> unionBinomialHeap(list<BNode*> l1,list<BNode*> l2);
        void adjust();
        void insert(pair<int,int> key);
        BNode* getMin();
    private:
        int operations;
        list<BNode*> heap;
};

#endif // BINOMIALHEAP_H
