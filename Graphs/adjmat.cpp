#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int v, e;
    cout << "Enter number of vertices: " << endl;
    cin >> v;
    cout << "Enter number of edges: " << endl;
    cin >> e;

    vector<vector<int>> graph(v + 1, vector<int>(v + 1, 0));

    cout << "Enter edges (v1 v2):" << endl;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
