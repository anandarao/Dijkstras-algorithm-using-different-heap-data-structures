#include <iostream>
#include <ctime>
#include <Graph.h>

using namespace std;

int main()
{
    int V, start, stop, source, n;
    cout << "Enter the number of vertices in the graph : ";
    cin >> V;
    Graph g(V);

    cout << "Enter the source vertex : ";
    cin >> source;

    for (int i = 0; i < V; i++)
    {
        cout << "Enter the number of neighbours of vertex " << i << " :";
        cin >> n;
        assert(n < V);
        cout << "Enter the neighbours of vertex " << i << "along with the edge weigths." << endl;
        for (int j = 0; j < n; j++)
        {
            int u, w;
            cin >> u >> w;
            assert(u < V && w >= 0);
            g.addEdge(i, u, w);
        }
    }

    /*cout << "-----BINARY HEAPS-----" << endl;
    start = clock();
	g.shortestPath(source, BINARY);
	stop = clock();
    cout << "Execution time using Binary Heaps: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;

    cout << "-----BINOMIAL HEAPS-----" << endl;
    start = clock();
	g.shortestPath(source, BINOMIAL);
	stop = clock();
    cout << "Execution time using Binomial Heaps: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;*/

    cout << "-----FIBONACCI HEAPS-----" << endl;
    start = clock();
	g.shortestPath(source, FIBONACCI);
	stop = clock();
    cout << "Execution time using Fibonacci Heaps: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;

    return 0;
}

