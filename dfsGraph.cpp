#include <iostream>
#include <list>
using namespace std;
class Graph
{
    int v;
    list<int> *l;
    bool *visited;

public:
    Graph(int v)
    {
        this->v = v;
        visited = new bool[v];
        l = new list<int>[v];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }
    void dfs(int source)
    {
        visited[source] = true;
        cout << source << " ";
        list<int>::iterator i;
        for (i = l[source].begin(); i != l[source].end(); i++)
        {
            if (!visited[*i])
            {
                dfs(*i);
            }
        }
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.dfs(2);
}