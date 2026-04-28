#include <iostream>
using namespace std;
int main()
{
    int V, E;
    cin >> V >> E;
    int graph[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[0] = 0;
    for (int i = 1; i < V; i++)
        for (int j = 0; j < V; j++)
            for (int k = 0; k < V; k++)
                if (graph[j][k] != 0 && dist[j] != INT_MAX && dist[j] + graph[j][k] < dist[k])
                    dist[k] = dist[j] + graph[j][k];
    for (int i = 0; i < V; i++)
        cout << "Distance from source to vertex " << i << " is " << dist[i] << endl;
    return 0;
}
