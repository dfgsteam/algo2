#include<iostream>
#include<vector>
using namespace std;

//adjacency list for representation of a graph
vector<int> arr[51];

//array for discovery time and lowest ancestor and marking for visited node
int low[51],in[51],vis[51];

//for maintain discovery time
int timer,r;

//for back edge
void DFS(int node,int par){
    int nchild=0;
    vis[node]=1;
    in[node]=low[node]=timer;
    timer++;

    //for exploring node
    for(int child:arr[node]){
        if(child==par){
            continue;
        }
        if(vis[child]==1){

            low[node]=min(low[node],in[child]);

            //back edge
        }
        else{
            DFS(child ,node);
            low[node]=min(low[node],low[child]);
            if(low[child]>=in[node] && par!=-1){
                    cout<<node<<endl;
                    r++;//for counting
                //cout<<" Cross edge between "<<child<<" and "<<node<<" "<<endl;
            }
            nchild++;

            //forward edge
        }
   }
   //for extra care of root node
   if(par==-1 && nchild>1){
    cout<<node<<endl;
    r++;
   }
}
int main(){

    int n,m,x,y, home, work;

    /*n is number of vertex and m is number of edge
    x and y is representing path between x and y  */
    cin>>n>>m;
    cin>>home>>work;
    while(m--){
        cin>>x>>y;
        //this is for undirected graph

        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    DFS(0,-1);
    cout<<"Total number of cut vertex = "<<r<<" follows above"<<endl;

    return 0;


}