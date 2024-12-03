#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int path[100][100];

int main()
{
    int V, E;
    cout << "Enter the number of vertices: "; cin >> V;
    cout << "Enter the number of edges: "; cin >> E;

    int dist[V];
    int graph[V][V];

    // Initialize graph and path matrices
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(i == j)
            {
                graph[i][j] = 0;
                path[i][j] = i; // Path to self is itself
            }
            else
            {
                graph[i][j] = INF; // No direct edge
                path[i][j] = -1; // No predecessor initially
            }
        }
    }

    cout << "Enter the edges (u v weight):\n";
    for(int i = 0; i < E; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        graph[u][v] = w;
        path[u][v] = u; // Direct edge from u to v
    }

    cout << "Enter the source vertex: ";
    int src; cin >> src;

    // Initialize distances from the source
    for(int i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;

    // Bellman-Ford Algorithm: Relax all edges V-1 times
    for(int i = 0; i < V - 1; i++)
    {
        for(int u = 0; u < V; u++)
        {
            for(int v = 0; v < V; v++)
            {
                if(graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                    path[u][v] = u; // Update the path to reflect the predecessor
                }
            }
        }
    }
    // Check for negative weight cycles
    bool hasNegativeCycle = false;
    for(int u = 0; u < V; u++)
    {
        for(int v = 0; v < V; v++)
        {
            if(graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                hasNegativeCycle = true;
                break;
            }
        }
        if(hasNegativeCycle) break;
    }
    if(hasNegativeCycle) cout << "Graph contains a negative weight cycle.\n";
    else cout << "No negative weight cycle detected.\n";
    // Print distances from the source
    cout << "\nShortest distances from source " << src << ":\n";
    for(int i = 0; i < V; i++)
    {
        cout << "Vertex " << i << ": ";
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}
