#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
public:
    int V;
    int E;
    vector<list<int>> adj;

    Graph(int V)
    {
        this->V = V;
        this->E = 0;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
        E++;
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << ":";
            for (auto it = adj[i].begin(); it != adj[i].end(); ++it)
                cout << " -> " << *it;
            cout << endl;
        }
    }

    void DFSUtil(int v, vector<bool> &visited)
    {

        visited[v] = true;
        cout << v << " ";

        for (list<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it)
        {
            if (!visited[*it])
            {
                DFSUtil(*it, visited);
            }
        }
    }

    void DFS(int start)
    {
        vector<bool> visited(V, false);
        cout << "DFS starting from vertex " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }

    void BFS(int start)
    {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS starting from vertex " << start << ": ";
        while (!q.empty())
        {

            int v = q.front();
            cout << v << " ";
            q.pop();

            for (list<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it)
            {
                if (!visited[*it])
                {
                    visited[*it] = true;
                    q.push(*it);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    g.DFS(0);

    g.BFS(0);

    return 0;
}
