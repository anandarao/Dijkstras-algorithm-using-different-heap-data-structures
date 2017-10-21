#include "Graph.h"
#include "BinaryHeap.h"
#include "BinomialHeap.h"
#include "FibonacciHeap.h"

# define INF 0x3f3f3f3f

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pair<int, int> > [V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src, int heap_type)
{
    Heap *heap;
    if(heap_type == BINARY)
        heap = new BinaryHeap();
    else if(heap_type ==  BINOMIAL)
    {
        cout << "inside heaptype" << endl;
        heap = new BinomialHeap();
    }
    else if(heap_type ==  FIBONACCI)
    {
        cout << "inside heaptype" << endl;
        heap = new FibonacciHeap();
    }

    vector<int> dist(V, INF);
    cout << "b4 push" << endl;
    (*heap).push(make_pair(0, src));
    cout << "after push" << endl;
    dist[src] = 0;
    cout << "b4 while" << (*heap).top().second << endl;
    while ((*heap).top() != make_pair(-1, -1))
    {
        int u = (*heap).top().second;
        (*heap).pop();
        cout << "after pop"<< endl;
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                (*heap).push(make_pair(dist[v], v));
            }
        }
    }

    cout << "b4 printing" << endl;
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);

    printf("Number of Operations performed : %d \n", (*heap).getOperations());
}
