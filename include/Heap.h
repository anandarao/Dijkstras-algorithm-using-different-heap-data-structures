#include <bits/stdc++.h>
using namespace std;

#ifndef HEAP_H
#define HEAP_H

class Heap
{
    public:
        virtual pair<int, int> top() = 0;
        virtual pair<int, int> pop() = 0;
        virtual void push(pair<int, int>) = 0;
        virtual int getOperations() = 0;
    private:
        int operations;
};

#endif // HEAP_H
