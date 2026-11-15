class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // make a adjacency list
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int src=edges[i][0];
            int dest=edges[i][1];
            int wt=edges[i][2];
            adj[src].push_back({dest,wt});
            adj[dest].push_back({src,wt});

        }
        int res=INT_MAX;
        int city=-1;

         // now we have to apply dijkstra by making every node as a soruce node
         for(int i=0;i<n;i++){

            // make dist vector
            vector<int>dist(n,INT_MAX);
            // make a min heap
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            pq.push({0,i});
            dist[i]=0;
            while(!pq.empty()){
                pair<int,int>curr=pq.top();
                pq.pop();
                int d=curr.first;
                int node=curr.second;
                if(d>dist[node])continue;
                for(int i=0;i<adj[node].size();i++){
                      auto neigh=adj[node][i];
                      int neigh1=neigh.first;
                      int wt=neigh.second;
                      if(d+wt<dist[neigh1]){
                        dist[neigh1]=d+wt;
                        pq.push({d+wt,neigh1});
                      }

                }
            }

int score=0;

for(int j=0;j<dist.size();j++){
    if(j!=i && dist[j]<= distanceThreshold)score++;

}
  // we have to track the city number also
        if(res>=score){
            // this will automatically take the greatest index city
            city=i;
            res=score; // CHOTI VALI UODATE HOJEGI
         }
         }
         return city;
    }
};