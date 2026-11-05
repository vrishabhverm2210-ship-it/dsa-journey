class Solution {
public:
int timer=1;
void dfs(int node,int parent,vector<bool>&vis, vector<int>adj[],vector<int>&time,vector<int>&low,  vector<vector<int>>&bridges){

    vis[node]=1;
    time[node]=low[node]=timer;
    timer++;
    for(auto it:adj[node]){
        if(it==parent)continue;
        if(vis[it]==0){
            dfs(it,node,vis,adj,time,low,bridges);
            low[node]=min(low[node],low[it]);
            // bridge detection condition
            if(low[it]>time[node]){
                bridges.push_back({it,node});
            }
        }
        else{
          low[node]=min(low[node],low[it]);
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,0);
        vector<int>time(n,0);
        vector<int>low(n,INT_MAX);
        vector<vector<int>>bridges;

        dfs(0,-1,vis,adj,time,low,bridges);
        return bridges;
    }
};