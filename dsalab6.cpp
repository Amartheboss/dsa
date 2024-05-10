#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//DFS traversal 
void DFS(int node,int n,vector<vector<int>>&adjlist,bool vis[]){
    vis[node]=true;
    cout<<node<<" ";
    vector<int>::iterator ptr;
    for(ptr=adjlist[node].begin();ptr!=adjlist[node].end();ptr++){
        if(!vis[*ptr]){
            DFS(*ptr,n,adjlist,vis);
        }
    }
}

int main(){
    int n,edge;
    cout<<"Enter no. of nodes and vertices:";
    cin>>n>>edge;

    vector<vector<int>>adjlist(n+1);

    for(int i =0;i<edge;i++){
        int x,y;
        cout<<"Enter the edge(v1->v2) starting node and ending node:";
        cin>>x>>y;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }

    //code for BFS traversal
    bool visit[n+1]={false};//intialize all values to false
    queue<int>q;
    q.push(1);
    visit[1]=true;
    cout<<"BFS Traversal:";
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        vector<int>::iterator it;
        for(it= adjlist[node].begin();it!=adjlist[node].end();it++){
            //Fixed the loop condition
            if(!visit[*it]){
                visit[*it]=true;//Change to true
                q.push(*it);
            }
        }
    }

    //code for DFS traversal
    cout<<"\nDFS Traversal:";
    bool vis[n+1]={false};//Intialize all value to false
    DFS(1,n,adjlist,vis);
    return 0;
}