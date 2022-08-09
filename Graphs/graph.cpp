#include <iostream>
using namespace std;
#include <queue> 

// DFS traversal
void printDFS(int** edges,int n,int sv,bool* visited){
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            printDFS(edges,n,i,visited);
        }
    }
}

// BFS traversal
void printBFS(int** edges,int n,int sv,bool* visited){
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    visited[sv]=true;
    while(!pendingNodes.empty()){
        int x = pendingNodes.front();
        cout<<x<<" ";
        pendingNodes.pop();
        for(int i=0;i<n;i++){
            if(i==x){
                continue;
            }
            if(edges[x][i]==1){
                if(visited[i]){
                    continue;
                }
                pendingNodes.push(i);
                visited[i]=true;
            }
        }
    }


}

// Adjascency Matrix Approach
int main()
{
    int n,e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }       
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    printBFS(edges,n,0,visited);
    return 0;
}
