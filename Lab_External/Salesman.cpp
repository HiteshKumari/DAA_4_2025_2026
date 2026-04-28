#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int graph[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    int count = 1, min_cost = 0, current_vertex = 0;
    visited[current_vertex] = 1;
    while (count < n)
    {
        int next_vertex = -1, min_edge = INT_MAX;
        for (int j = 0; j < n; j++)
            if (!visited[j] && graph[current_vertex][j] != 0 && graph[current_vertex][j] < min_edge)
            {
                min_edge = graph[current_vertex][j];
                next_vertex = j;
            }
        visited[next_vertex] = 1;
        min_cost += min_edge;
        current_vertex = next_vertex;
        count++;
    }
    cout << "Minimum cost of the tour is " << min_cost << endl;
    return 0;
}
