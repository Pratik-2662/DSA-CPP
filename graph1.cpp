#include <iostream>
#include <list>
using namespace std;
class Graph
{
    int v;
    list<int> *l;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        // l[y].push_back(x);
    }
    void printGraph()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "Vertex " << i << ": ";
            for (int itr : l[i])
            {
                cout << itr << ", ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 4);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 1);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    g.addEdge(4, 2);
    g.addEdge(4, 3);
    g.printGraph();
}