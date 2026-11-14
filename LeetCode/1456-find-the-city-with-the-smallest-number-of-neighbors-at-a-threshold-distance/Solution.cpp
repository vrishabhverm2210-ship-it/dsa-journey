class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
             // now make the adjacecny list 
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

// now we have to do this same process for the all the nodes
for(int i=0;i<n;i++){
        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,i});  // i th node
        dist[i]=0;
        while(!pq.empty()){
            pair<int,int>top=pq.top();
            pq.pop();
            int node=top.second;
            int d=top.first;
            if(d>dist[node])continue;
            for(int i=0;i<adj[node].size();i++){
                pair<int,int>top1=adj[node][i];
                int neigh=top1.first;
                int wt=top1.second;
                if(wt+d<dist[neigh]){
                    dist[neigh]=wt+d;
                    pq.push({wt+d,neigh});
                }
            }
        }
        // once hmare 1 particular source ke liye distance nikal gya saron ka then uodate score
        int score=0;
        for(int j=0;j<dist.size();j++){
            if( j != i && dist[j]<=distanceThreshold)score++;
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