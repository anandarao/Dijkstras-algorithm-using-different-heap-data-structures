#include "BinaryHeap.h"
#include <bits/stdc++.h>
using namespace std;

BinaryHeap::BinaryHeap()
{
        operations = 0;
}

int BinaryHeap::getOperations()
{
    return operations;
}

void BinaryHeap::push(pair<int, int> node)
{
    insertValue(node);
    return;
}

pair<int, int> BinaryHeap::top()
{
    if(nodes.size() == 0)
        return make_pair(-1, -1);

    return nodes[0];
}

pair<int, int> BinaryHeap::pop()
{
    if(nodes.size() == 0)
        return make_pair(-1, -1);

    pair<int, int> node = extractMin();

    return node;
}

void BinaryHeap::minHeapify(int i)
{
    int left  = 2*i + 1;
    int right = 2*i + 2;
    int smallest;
    if(left < (int)nodes.size() and nodes[left].first < nodes[i].first )
        smallest = left;
    else
        smallest = i;
    if(right < (int)nodes.size() and nodes[right].first < nodes[smallest].first )
        smallest = right;
    if(smallest != i)
    {
        swap (nodes[i], nodes[smallest]);
        operations++;
        minHeapify (smallest);
    }
}

pair<int, int> BinaryHeap::extractMin()
{
    if(nodes.size() == 0)
        return make_pair(-1, -1);
    pair<int, int> node = nodes[0];
    nodes[0] = nodes[nodes.size()-1];
    operations++;
    nodes.pop_back();
    minHeapify(0);
    return node;
}

void BinaryHeap::insertValue(pair<int, int> node)
{
    nodes.push_back(node);
    int i = nodes.size() - 1;
    while(i > 0 and nodes[(i-1)/2].first > nodes[i].first)
    {
        swap(nodes[(i-1)/2], nodes[i]);
        operations++;
        i = (i-1)/2;
    }
    return;
}
