#include<bits/stdc++.h>
using namespace std;


// TopoSort is liner sorting of graph where for every edge (U-->V) , U comes before V in ordering. 
// It can only work in Directed Acyclic Graph

//TopoSort using DFS
void dfs(vector<int> adj[],int node,vector<int> &vis,stack<int> &st){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it])dfs(adj,it,vis,st);
    }
    st.push(node);
}

vector<int> toposort(vector<int> adj[],int N){
    stack<int> st;
    vector<int> vis(N,0);
    for(int i=0;i<N;i++){
        if(!vis[i])dfs(adj,i,vis,st);
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

// TopoSort using BFS
// Here we use the Indegree array, and first start the BFS traversal from only those node which have
// zero indegree. Also while doing the push operation in queue in the loop, we first decrease the
// indegree of every neighbour node and push only those which have indegree 0.

vector<int> toposortBFS(vector<int> gh[],int N){
    vector<int> indegree(N,0);
    vector<int> ans;
    for(int i=0;i<N;i++){
        for(auto it:gh[i]){
            indegree[it]++;
        }
    }
    queue<int> qt;
    for(int i=0;i<N;i++){
        if(indegree[i]==0){
            qt.push(i);
        }
    }
    while(qt.size()){
        int ft=qt.front();
        qt.pop();
        ans.push_back(ft);
        for(auto it:gh[ft]){
            indegree[it]--;
            if(indegree[it]==0){
                qt.push(0);
            }
        }
    }
    return ans;
}