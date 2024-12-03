#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int path[100][100];

void printPath(int s, int d)
{
    if(s == d) cout << s << " ";
    else if(path[s][d] == -1) cout << "No path found" << endl;
    else
    {
        printPath(s, path[s][d]);
        cout << d << " ";
    }
}

int main()
{
    int n, e, u, v, w, i, s;
    cout << "Number of vertices: "; cin >> n;
    cout << "Number of edges: "; cin >> e;

    int dist[n][n];
    // Initialize dist and path matrices
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                dist[i][j] = 0;
                path[i][j] = i;
            }
            else
            {
                dist[i][j] = INF;
                path[i][j] = -1;
            }
        }
    }

    cout << "Enter edges (source destination weight):\n";
    for(int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        dist[u][v] = w;
        path[u][v] = u;  // Direct edge from u to v
    }

    // Floyd-Warshall Algorithm
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    // Check for negative weight cycles
    bool hasNegativeCycle = false;
    for(int i = 0; i < n; i++)
    {
        if(dist[i][i] < 0)
        {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) cout << "Graph contains a negative weight cycle.\n";
    else cout << "No negative weight cycle detected.\n";

    // Print all-pairs shortest path matrix
    cout << "\nShortest path matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nEnter source and destination to find the shortest path: ";
    int src, dest; cin >> src >> dest;

    cout << "Shortest path: ";
    printPath(src, dest);
    if(dist[src][dest] == INF) cout << "\nCost: INF" << endl;
    else cout << "\nCost: " << dist[src][dest] << endl;
    return 0;
}
