class Solution {
public:
void dfs(vector<vector<int>>&adj, int node, vector<int >&vis){
     vis[node] = 1;

        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(adj, it, vis);
            }
        }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)return -1;
         int comp=0;
          vector<vector<int>>adj(n);
          for(int i=0;i<connections.size();i++){
              int src=connections[i][0];
              int dest=connections[i][1];
              adj[src].push_back(dest);
              adj[dest].push_back(src);
          }
         vector<int>vis(n,0);
           for(int i=0;i<n;i++){
               if(vis[i]==0){
                comp++;
                dfs(adj,i,vis);
               }
         }

        return comp-1;


    }
};