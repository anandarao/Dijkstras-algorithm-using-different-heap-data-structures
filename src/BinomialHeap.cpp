#include "BinomialHeap.h"
#include <bits/stdc++.h>
using namespace std;

BinomialHeap::BinomialHeap()
{
        operations = 0;
}

int BinomialHeap::getOperations()
{
    return operations;
}

void BinomialHeap::push(pair<int, int> BNode)
{
    insert(BNode);
    return;
}

pair<int, int> BinomialHeap::top()
{
    if(heap.size() == 0)
        return make_pair(-1, -1);

    return getMin()->data;
}

pair<int, int> BinomialHeap::pop()
{
    if(heap.size() == 0)
        return make_pair(-1, -1);

    pair<int, int> BNode = extractMin();

    return BNode;
}

pair<int, int> BinomialHeap::extractMin()
{
    if(heap.size() == 0)
        return make_pair(-1, -1);
    list<BNode*> new_heap,lo;
    BNode *temp;
    temp = getMin();
    list<BNode*>::iterator it;
    it = heap.begin();
    while (it != heap.end())
    {
        if (*it != temp)
        {
            new_heap.push_back(*it);
        }
        it++;
    }
    operations++;
    lo=removeMinFromTreeReturnBHeap(temp);
    heap = unionBinomialHeap(new_heap,lo);
    adjust();
    return temp->data;
}

BNode::BNode(pair<int,int> key)
{
    this->data = key;
    this->degree = 0;
    this->child = this->parent = this->sibling = NULL;
}
void BinomialHeap::insert(pair<int,int> key)
{
    BNode *temp = new BNode(key);
    insertATreeInHeap(temp);
}


void swap(BNode *b1,BNode *b2)
{
    BNode *a;
    a=b1;
    b1=b2;
    b2=a;
}

BNode* BinomialHeap::mergeBinomialTrees(BNode *b1, BNode *b2)
{
    if ((b1->data).first > (b2->data).first)
    {
        swap(b1, b2);
        operations++;
    }
    b2->parent = b1;
    b2->sibling = b1->child;
    b1->child = b2;
    b1->degree++;

    return b1;
}

list<BNode*> BinomialHeap::unionBinomialHeap(list<BNode*> l1,
                               list<BNode*> l2)
{
    list<BNode*> _new;
    list<BNode*>::iterator it = l1.begin();
    list<BNode*>::iterator ot = l2.begin();
    while (it!=l1.end() && ot!=l2.end())
    {
        if((*it)->degree <= (*ot)->degree)
        {
            _new.push_back(*it);
            it++;
        }
        else
        {
            _new.push_back(*ot);
            ot++;
        }
    }
    while (it != l1.end())
    {
        _new.push_back(*it);
        it++;
    }
    while (ot!=l2.end())
    {
        _new.push_back(*ot);
        ot++;
    }
    operations++;
    return _new;
}

void BinomialHeap::adjust()
{
    if (heap.size() <= 1)
        return;
    list<BNode*> new_heap;
    list<BNode*>::iterator it1,it2,it3;
    it1 = it2 = it3 = heap.begin();

    if (heap.size() == 2)
    {
        it2 = it1;
        it2++;
        it3 = heap.end();
    }
    else
    {
        it2++;
        it3=it2;
        it3++;
    }
    while (it1 != heap.end())
    {
        if (it2 == heap.end())
            it1++;
        else if ((*it1)->degree < (*it2)->degree)
        {
            it1++;
            it2++;
            if(it3!=heap.end())
                it3++;
        }
        else if (it3!=heap.end() &&
                (*it1)->degree == (*it2)->degree &&
                (*it1)->degree == (*it3)->degree)
        {
            it1++;
            it2++;
            it3++;
        }
        else if ((*it1)->degree == (*it2)->degree)
        {
            *it1 = mergeBinomialTrees(*it1,*it2);
            it2 = heap.erase(it2);
            if(it3 != heap.end())
                it3++;
        }
    }
    operations++;
    return;
}

void BinomialHeap::insertATreeInHeap(BNode *tree)
{
    list<BNode*> temp;
    temp.push_back(tree);
    heap = unionBinomialHeap(heap,temp);
    adjust();
    return;
}

list<BNode*> BinomialHeap::removeMinFromTreeReturnBHeap(BNode *tree)
{
    list<BNode*> tempheap;
    BNode *temp = tree->child;
    BNode *lo;
    operations++;
    while (temp)
    {
        lo = temp;
        temp = temp->sibling;
        lo->sibling = NULL;
        tempheap.push_front(lo);
    }
    return tempheap;
}

BNode* BinomialHeap::getMin()
{
    if (heap.size() == 0)
        return NULL;
    list<BNode*>::iterator it = heap.begin();
    BNode *temp = *it;
    operations++;
    while (it != heap.end())
    {
        if (((*it)->data).first < (temp->data).first)
            temp = *it;
        it++;
    }
    return temp;
}
void BinomialHeap::printTree(BNode *h)
{
    while (h)
    {
        printTree(h->child);
        h = h->sibling;
    }
}

void BinomialHeap::printHeap()
{
    list<BNode*> ::iterator it;
    it = heap.begin();
    while (it != heap.end())
    {
        printTree(*it);
        it++;
    }
}
