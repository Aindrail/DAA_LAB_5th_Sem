/*
Write a Program to implement Depth First Search (DFS).
*/

#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int> adj[], int s, bool visited[]){
    visited[s] = true;
    cout<<s<<" ";
    for(int v: adj[s]){
        if(!visited[v]){
            DFS(adj, v, visited);
        }
    }
}

int main(){
    int n, e;
    cout<<"Enter the number of vertices and edges: ";
    cin>>n>>e;
    vector<int> adj[n];
    int u, v;
    for(int i=0; i<e; i++){
        cout<<"Enter the vertices of edge "<<i+1<<": ";
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool visited[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    cout<<"The DFS traversal is: ";
    DFS(adj, 0, visited);
}