#include<bits/stdc++.h>
using namespace std;

// If you can color graph with two colors, where no two adjacent nodes have same color. 
// The Graph should not contain odd cycles

bool dfs(vector<int> gh[],int node, vector<int> &vis,vector<int> &color){
    for(auto it:gh[node]){
        if(!vis[it]){
            vis[it]=1;
            if(color[node]==1)color[it]=0;
            else color[it]=1;
            if(!dfs(gh,it,vis,color))return false; 
        }
        else{
            if(color[it]==color[node])return false;
        }
    }
    return true;
}

bool bfs(vector<int> gh[],int n){
    queue<int> qt;
    vector<int> color(n,-1);
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            color[i]=1;
            qt.push(i);
            while(!qt.empty()){
                int ft=qt.front();
                qt.pop();
                for(auto it:gh[ft]){
                    if(color[it]==-1){
                        if(color[ft]==0)color[it]=1;
                        else color[it]=1;
                    }
                    else{
                        if(color[it]==color[ft])return false;
                    }
                }
            }
        }
    }
    return true;
}
bool isBiPartite(vector<int> gh[],int n){
    vector<int> vis(n+1,0);
    vector<int> color(n+1,-1);
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            color[i]=1;
            if(!dfs(gh,i,vis,color))return false;
        }
    }
    return true;
}