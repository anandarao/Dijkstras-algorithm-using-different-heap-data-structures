
#include "Heap.h"

#ifndef FIBONACCIHEAP_H
#define FIBONACCIHEAP_H

struct Node
{
    pair<int,int> data;
    int degree;
    Node *child, *sibling, *parent;
};

class FibonacciHeap: public Heap
{
    public:
        FibonacciHeap();
        pair<int, int> top();
        pair<int, int> pop();
        void push(pair<int, int>);
        int getOperations();
        void printTree(Node *h);
        void printHeap();
    protected:
        pair<int, int> extractMin();
        Node* newNode(pair<int,int> key);
        void insertATreeInHeap(Node *tree);
        list<Node*> removeMinFromTreeReturnFHeap(Node *tree,Node*& n);
        Node* mergeFibonacciTrees(Node *b1, Node *b2);
        list<Node*> unionFibonacciHeap(list<Node*> l1,Node*,list<Node*> l2,Node*);
        void adjust();
        void insert(pair<int,int> key);
        Node* getMin();
    private:
        int operations;
        list<Node*> heap;
        Node *minNode;
};

#endif // FIBONACCIHEAP_H

