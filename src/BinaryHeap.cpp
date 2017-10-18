#include "BinaryHeap.h"
#include <bits/stdc++.h>
using namespace std;

BinaryHeap::BinaryHeap()
{
    //ctor
}

void BinaryHeap::push(pair<int, int> node)
{
    insert_value(node);
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

    pair<int, int> node = extract_min();

    return node;
}

void BinaryHeap::min_heapify(int i)
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
        min_heapify (smallest);
    }
}

pair<int, int> BinaryHeap::extract_min()
{
    if(nodes.size() == 0)
        return make_pair(-1, -1);
    pair<int, int> node = nodes[0];
    nodes[0] = nodes[nodes.size()-1];
    nodes.pop_back();
    min_heapify(0);
    return node;
}

void BinaryHeap::insert_value(pair<int, int> node)
{
    nodes.push_back(node);
    int i;
    while(i > 0 and nodes[(i-1)/2].first > nodes[i].first)
    {
        swap(nodes[(i-1)/2], nodes[i]);
        i = (i-1)/2;
    }
    return;
}
