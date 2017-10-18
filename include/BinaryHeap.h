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
    protected:
        pair<int, int> extract_min();
        void insert_value(pair<int, int>);
        void min_heapify(int);
    private:
        vector<pair<int, int> > nodes;
};

#endif // BINARYHEAP_H
