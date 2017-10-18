#include "Heap.h"

#ifndef BINARYHEAP_H
#define BINARYHEAP_H


class BinaryHeap: public Heap
{
    public:
        BinaryHeap();
        pair<int, int> top();
        pair<int, int> pop();
        void push(pair<int, int>);
        int getOperations();
    protected:
        pair<int, int> extractMin();
        void insertValue(pair<int, int>);
        void minHeapify(int);
    private:
        vector<pair<int, int> > nodes;
        int operations;
};

#endif // BINARYHEAP_H
