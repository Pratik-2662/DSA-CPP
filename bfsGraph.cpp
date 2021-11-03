#include <iostream>
#include <list>
#include <queue>
using namespace std;
class Graph
{
private:
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
    }
    void bfs(int source)
    {
        bool *visited = new bool[v];
        list<int>::iterator i;
        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
        }
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty())
        {
            int temp = q.front();
            cout << temp << " ";
            q.pop();
            for (i = l[temp].begin(); i != l[temp].end(); i++)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    q.push(*i);
                }
            }
        }
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.bfs(2);
}