#include <bits/stdc++.h>
using namespace std;
const int MAX_VERTICES = 100;
int adj[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
void bfs(int n, char start)
{
    queue<char> q;
    q.push(start  - 'a');
    visited[start - 'a'] = true;

    while (!q.empty())
    {
        char current_node = q.front();
        q.pop();
        cout <<(char)(current_node + 'a')<< " ";
        for (int i = 0; i < n; i++)
        {
            if (adj[i][current_node] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
    }
        }
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        char u, v;
        cin >> u >> v;
        adj[u - 'a'][v - 'a'] = adj[v - 'a'][u - 'a'] = 1;
    }
    cout << "Adjacent matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << "BFS started from 'a' : ";
    bfs(n, 'a');
    cout << endl;
    return 0;
}
