#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Graph.h>

using namespace std;

int main()
{
    char Random;
    int V, start, stop, source, n, edges, rangeStart, rangeEnd;
    float avg_deg;
    do
    {
        cout<<"Enter R for Random Graph generation and S for specified Graph Input"<<endl;
        cin>>Random;
    }while(Random != 'R' && Random != 'r' && Random != 'S' && Random != 's');
    cout << "Enter the number of vertices in the graph : ";
    cin >> V;
    Graph g(V);
    if(Random == 'R' || Random == 'r')
    {
        cout << "Enter the source vertex : ";
        cin >> source;
        cout<< "Enter the average degree: ";
        cin>>avg_deg;
        cout<<"Enter the range start and range end: ";
        cin>>rangeStart>>rangeEnd;
        edges = (int)(avg_deg * V);
        map<pair<int,int>,int>m;
        cout<<"Edge number "<<edges<<endl;
        cout<<"Edges are: "<<endl;
        for(int i = 0; i < edges; i++)
        {
            srand (time(NULL));
            int random_number = -1;
            while(random_number == -1)
            {
                random_number =rand()%(V*V);
                if(m[make_pair(random_number/V,random_number%V)] || random_number/V == random_number%V)
                    random_number = -1;
                else
                {
                    int weight = rand()%(rangeEnd - rangeStart) + rangeStart;
                    m[make_pair(random_number/V,random_number%V)] = 1;
                    cout<<random_number/V<<" - "<<random_number%V<<": "<<weight<<endl;
                    g.addEdge(random_number/V, random_number%V, weight);
                }
            }
        }
    }
    else
    {
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
    }
    cout << "-----BINARY HEAPS-----" << endl;
    start = clock();
	g.shortestPath(source, BINARY);
	stop = clock();
    cout << "Execution time using Binary Heaps: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;

    cout << "-----BINOMIAL HEAPS-----" << endl;
    start = clock();
	g.shortestPath(source, BINOMIAL);
	stop = clock();
    cout << "Execution time using Binomial Heaps: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;

    cout << "-----FIBONACCI HEAPS-----" << endl;
    start = clock();
	g.shortestPath(source, FIBONACCI);
	stop = clock();
    cout << "Execution time using Fibonacci Heaps: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;

    return 0;
}

