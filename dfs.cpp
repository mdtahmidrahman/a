#include<bits/stdc++.h>
using namespace std;
const int M = 100;
int adj[M][M];
bool visited[M];
void dfs(int n, char start){
     stack<char>s;
     s.push(start - 'A');
     visited[start - 'A'] = true;
     while(!s.empty()){
        char current_node = s.top();
        s.pop();
        cout<<(char)(current_node + 'A')<<" ";
        for(int i = 0; i < n; i++)
        {
            if(adj[current_node][i] == 1 && !visited[i])
            {
                s.push(i);
                visited[i] = true;
            }
        }
     }
}

int main()
{
    int n, e;
    cin>>n>>e;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            adj[i][j] = 0;
        }
    }
    for(int i = 0; i < e; i++){
        char u,v;
        cin>>u>>v;
        adj[u-'A'][v-'A'] = adj[v-'A'][u-'A'] = 1;
    }
    cout<<"Adjacent matrix: "<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"DFS started from : "<<" ";
    dfs(n, 'A');
    return 0;
}
