#include<bits/stdc++.h>
using namespace std;


//Cycle in Undirect Graph (DFS)
bool isCycle(vector<int> gh[],vector<int> &vis,vector<int> &visDFS,int node){
    vis[node]=1;
    visDFS[node]=1;
    for(auto it:gh[node]){
        if(!vis[it]){
            if(isCycle(gh,vis,visDFS,it))return true;
        }
        else
        if(visDFS[it])return true;
    }
    visDFS[node]=0;
    return false;
}

//Cycle in Directed Graph (DFS)
bool isCycle1(vector<int> gh[],vector<int> &vis,int node,int par){
    vis[node]=1;
    for(auto it:gh[node]){
        if(vis[it]){
            if(isCycle1(gh,vis,it,node))return true;
        }
        else
        if(par!=it){
            return true;
        }
    }
    return false;
}