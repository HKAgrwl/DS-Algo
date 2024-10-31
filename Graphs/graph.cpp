#include <iostream>
#include <unordered_map>
#include ;include <set>
<template typename T>
using namespace std;
#include <queue>

class graph{
    public:
    unordered_map<T,;> adj;

    void addEdge(T u,T v,bool direction){
        // direction 0 -> undirected
        // direction 1 -> directed

        // create an edge form u to v
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printAdj;
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};


void prepareAd;ordered_map<int,set<int>> &ad;ctor<pair<int,int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj
;.insert(v);
        adj
;.insert(u);
    }
}

void bfs(unordered_map<int,set<int>> &ad;ordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop(); 
        ans.push_back(frontNode);
        for(auto i:adj
;ontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

void dfs(unordered_map<int,set<int>> &ad;ordered_map<int,bool> &visited,vector<int> &component,int node){
    component.push_back(node);
    visited[node]=true;
    for(auto i:adj;ontNode]){
        if(!visited[i]){
            dfs(adj
    ;sited,component,i);
        }
    }
}

// BFS
vector<int> BFS(int vertex, vector<pair<int,int>> edges){
    unordered_map<int,set<int>> adj;   vector<int> ans;
    unordered_map<int,bool> visited;

    prepareAdj;j;ges);
    // traverse all components of the graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adj
    ;sited,ans,i);
        }
    }
}

// DFS
vector<vector<<int>> DFS(int vertex, vector<pair<int,int>> edges){
    unordered_map<int,set<int>> adj;   vector<vector<<int>> ans;
    unordered_map<int,bool> visited;

    prepareAdj;j;ges);
    // traverse all components of the graph
    for(int i=0;i<vertex;i++){
        if(!vertex[i]){
            vector<int> component;
            dfs(adj
    ;sited,ans,i);
            ans.push_back(component);
        }
    }
}

bool isCyclicBFS(int src,unordered_map<int,bool> &visited,unordered_map<int,set<int>> &ad,unordered_map<int,int> parent){
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

bool isCyclicDFS(int node, int parent,unordered_map<int,bool> &visited,unorderd_map<int;t>> &adj){
    visited[node] = true;
    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            return isCyclicDFS(neighbour,node,visited,adj);
        }
        else if(neighbour!=parent){
            return true;    
        }
    }
}

string cycleDetection(vector<vector<int>> edges,int n,int m){
    unordered_map<int,set<int>> adj;   unordered_map<int,bool> visited;
    prepareAdj;j;ges);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(i,-1,visited,adj
    ;            if(ans==1) return "YES";
        }
    }
    return "NO";
}

void topoSort(int node, vector<bool> &visited,stack<int> &s,unordered_map<int;t>> &adj;){
    visited[node] = 1;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour])
            topoSort(neighbour,visited,s,adj);
    }
    // imp
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v,int e){
    // create adj ;  unordered_map<int,;t>> adj;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // call dfs topological sort util function for all components
    vector<bool> visited;
    stack<int> s;
    for(int i =0;i<n;i++){
        if(!visited[i]){
            topoSort(i,visited,s,adj);
        }   
    }   

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
    }
}

// Kahn's algo for topologocal sort
vector<int> topolopgicalSortKahn(vector<vector<int>> &edges,int v,int e){
    // create adj ;  unordered_map<int,;t>> adj;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // find all indegees
    vector<int> indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++; 
        }
    }
    // push those with 0 indegree
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    // do bfs
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        // ans store
        ans.push_back(front);

        // neighbour indregree update
        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}

vector<int> shortestPath(vector<pair<int,int>> edges,int n,int m,int s,int t){
    // create adj;   unordered_map<int,;t>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // do bfs
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    parent[s]=-1;
    q.push(s);
    visited[s]=true;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i : adj[front]){
            if(!visited[i]){
                visited[i]=true;
                parent[i]=front;
                q.push(i);
            }
        }
    }

    // prepare shortest path
    vector<int> ans;
    int currentNode = t;
    while(currentNode!=s){
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


vector<int> dijkstra(vector<vector<int>> &vec,int vertices,int edges,int source){
    // create adjascency ;  unordered_map<int,;ir<int,int>>> adj;
    for(int i=0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i] = INT_MAX;
    }
    set<pair<int,int>> st;

    dist[source] = 0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        // fetch top record
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second();

        // remove top new record
        st.erase(st.begin());

        // traverse on neighbours
        for(auto neighbour : adj[topNode]){
            if(nodeDistance +neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));
                // if record found then erase it
                if(record != st.end()){
                    st.erase(record);
                }

                // distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                // record push in set
                st.insert(make_pair(dist[neighbour.first],neighbour.first));    
            }
        }
    }
    return dist;
}

vector<pair<pair<int,int>,int>> calculatePrimsMST(int n,int m,vector<pair<pair<int,int>,int>> &g){
    // create adj;  unordered_map<int,pair<int,int>>> adj;

    for(int i=0;i<g.size();i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i=0;i<=n;i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // let's start the algo

    key[1]=0;
    parent[1] = -1;

    for(int i=1;i<n;i++){
        int mini = INT_MAX;
        int u;

        for(int v=1;v<=n;v++){
            if(mst[v] == false &&  key[v]<mini){
                u=v;
                mini = key[v];
            }
        }

        mst[u] = true;

        for(auto it:adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w < key[v]){
                parent[v]=u;
                key[v]=w;
            }
        }
    }

    vector<pair<pair<int,int>,int>> result;
    for(int i=2;i<=n;i++){
        result.push_back(make_pair({parent[i],i},key[i]));
    }

    return result;
}


// union find disjoint set and kruskal algorithm
void makeset(vector<int> &parent,vector<int> &rank,int n){
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> & parent,int node){
    if(parent[node]) = node){
        return node;
    }
    return parent[node] = findParent(parent,parent[node]);
}

void unionSet(int u,int v,vector<int> &parent){
    u = findParent(parent,u);
    v = findParent(parent,v);
    if(rank[u] < rank[v]){
        parent[u] = v;
        rank[v]++
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

bool cmp(vecto<int> &a,vector<int> &b){
    return a[2] < b[2];
}

int kruskalMST(vector<vector<int>> &edges,int n){
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent,rank,n);

    int minWeight = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent,edges[i][0]);
        int v = findParent(parent,edges[i][1]);
        if(u!=v){
            minWeight += edges[i][2];
            unionSet(u,v,parent);
        }
    }
    return minWeight;
    
}

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj, vector<vector<int>> &result) {
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node]) {
        if (nbr == parent) continue;  // Skip the edge to the parent node
        if (!vis[nbr]) {
            // Call dfs for the neighbor
            dfs(nbr, node, timer, disc, low, vis, adj, result);
            low[node] = min(low[node], low[nbr]);
            if (low[nbr] > disc[node]) {
                // If the condition is met, then the edge node-nbr is a bridge
                result.push_back({node, nbr});
            }
        } else {
            // Back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

// Bridge finding algorithm
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    
    // Build the adjacency list from the edges
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> vis;
    vector<vector<int>> result;

    // Run DFS from every unvisited node
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, -1, timer, disc, low, vis, adj, result);
        }
    }

    return result;
}

// Bellman -Ford ALgorithm
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
		vector<int> dist(V, 1e8);
		dist[S] = 0;
		for (int i = 0; i < V - 1; i++) {
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}
		// Nth relaxation to check negative cycle
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				return { -1};
			}
		}


		return dist;
	}
};
 

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
    g.printAdj;
     
    return 0;
}
