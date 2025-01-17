#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<pair<int, int>> graph[N];
int main()
{
    int v, e;
    cout << "Enter number of vertices: " << endl;
    cin >> v;
    cout << "Enter number of edges: " << endl;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        graph[v1].push_back({v2, weight});
        graph[v2].push_back({v1, weight});
    }
    cout << "Adjacency List:" << endl;
    for (int i = 1; i <= v; i++)
    {
        cout << "Vertex " << i << ": ";
        for (auto edge : graph[i])
        {
            cout << "(to: " << edge.first << ", weight: " << edge.second << ") ";
        }
        cout << endl;
    }
}