#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
bool visited[N];

void dfs(int vertex)
{
    if (visited[vertex])
        return;

    visited[vertex] = true;
    for (int i = 0; i < graph[vertex].size(); i++)
    {
        int neighbor = graph[vertex][i];
        if (!visited[neighbor])
        {
            dfs(neighbor);
        }
    }
}

int main()
{
    int v, e;
    cout << "Enter number of vertices: " << endl;
    cin >> v;
    cout << "Enter number of edges: " << endl;
    cin >> e;

    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    cout << "Performing DFS from vertex 1:" << endl;
    dfs(1);
    cout << "Visited array:" << endl;
    for (int i = 1; i <= v; i++)
    {
        cout << "Vertex " << i << ": " << visited[i] << endl;
    }

    return 0;
    return 0;
}
