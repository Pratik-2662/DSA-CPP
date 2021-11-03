#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Graph
{
public:
    map<int, vector<int>> m;
    void addEdge(int x, int y)
    {
        m[x].push_back(y);
    }
    bool isCycle(int vertex, map<int, bool> &visited, int parent)
    {
        visited[vertex] = true;
        map<int, vector<int>>::iterator itr;
        for (itr = m.begin(); itr != m.end(); itr++)
        {
            for (auto i : itr->second)
            {
                if (!visited[i])
                {
                    if (isCycle(i, visited, itr->first))
                    {
                        return true;
                    }
                }
                else
                {
                    if (i != parent)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool isTree()
    {
        map<int, bool> visited;
        if (isCycle(0, visited, -1))
        {
            return false;
        }
        return true;
    }
};
int main()
{
    Graph g2;
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree() ? cout << "Cycle" : cout << "No Cycle";
    return 0;
}