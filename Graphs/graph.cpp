#include <iostream>
#include <unordered_map>
#include <list>
#include <set>
<template typename T>
using namespace std;
#include <queue>

class graph{
    public:
    unordered_map<T,list<T>> adj;

    void addEdge(T u,T v,bool direction){
        // direction 0 -> undirected
        // direction 1 -> directed

        // create an edge form u to v
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};


void prepareAdjList(unordered_map<int,set<int>> &adjList,vector<pair<int,int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop(); 
        ans.push_back(frontNode);
        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

void dfs(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &component,int node){
    component.push_back(node);
    visited[node]=true;
    for(auto i:adjList[frontNode]){
        if(!visited[i]){
            dfs(adjList,visited,component,i);
        }
    }
}

// BFS
vector<int> BFS(int vertex, vector<pair<int,int>> edges){
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;

    prepareAdjList(adjList,edges);
    // traverse all components of the graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
}

// DFS
vector<vector<<int>> DFS(int vertex, vector<pair<int,int>> edges){
    unordered_map<int,set<int>> adjList;
    vector<vector<<int>> ans;
    unordered_map<int,bool> visited;

    prepareAdjList(adjList,edges);
    // traverse all components of the graph
    for(int i=0;i<vertex;i++){
        if(!vertex[i]){
            vector<int> component;
            dfs(adjList,visited,ans,i);
            ans.push_back(component);
        }
    }
}

bool isCyclicBFS(int src,unordered_map<int,bool> &visited,unordered_map<int,set<int>> &adjList){
    unordered_map<int,int> parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int> q;
    q.push(src);
     
    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front]){
            if(visited[neighbour]==true && neighbour !=parent[front]){
                return true;
            }else if(!visited[neighbourhood]){
                q.push(neighbourhood);
                visited[neighbourhood]=1;
                parent[neighbour] = front;
            }
        }
    }

}

bool isCyclicDFS(int node, int parent,unordered_map<int,bool> &visited,unorderd_map<int,list<int>> &adj){
    visited[node] = true;
    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            return isCyclicDFS(neighbour,node,visited,adj);
        }
        else if(neoghbour!=parent){
            return true;
        }
    }
}

string cycleDetection(vector<vector<int>> edges,int n,int m){
    unordered_map<int,set<int>> adjList;
    unordered_map<int,bool> visited;
    prepareAdjList(adjList,edges);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(i,visited,asjList);
            if(ans==1) return "YES";
        }
    }
    return "NO";
}

int main()
{
    int n,m;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;

    graph<int>(g);

    for(int i=0; i<m;i++){
        int u,v;
        cin>>u>>v;
        // creating an undirected graph
        g.addEdge(u,v,0);

    }
    
    // printing graph
    g.printAdjList();
     
    return 0;
}
