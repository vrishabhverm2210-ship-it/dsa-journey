1class Solution {
2public:   // Minimum time means jo time sbse bda hoga res vector mai vo hoga main anser
3    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
4        // make adj list
5        vector<vector<pair<int,int>>>adj(n);
6        for(int i=0;i<times.size();i++){
7            int source=times[i][0];
8            int dest=times[i][1];
9            int wt=times[i][2];
10            // now it is given that indexing is 1 to n
11            adj[source-1].push_back({dest-1,wt});  
12                    }
13     vector<int>res(n,INT_MAX);
14     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
15     res[k-1]=0; // must step
16     pq.push({0,k-1});
17     while(!pq.empty()){
18        pair<int,int>top=pq.top();
19        pq.pop();
20        int dist=top.first;
21        int node=top.second;
22        // pruning cdn
23        if(dist>res[node])continue;
24        for(int i=0;i<adj[node].size();i++){
25            int neigh=adj[node][i].first;
26            int wt=adj[node][i].second;
27            // relaxation conditiom
28            if(wt+dist < res[neigh]){
29                res[neigh]=wt+dist;
30                pq.push({wt+dist,neigh});
31            }
32        }
33     }
34// now we have to return the max answer and if not posiible so return --1
35int maxi=INT_MIN;
36for(int i=0;i<n;i++){
37    if(res[i]==INT_MAX)return -1;
38    maxi=max(res[i],maxi);
39}
40return maxi;
41
42    }
43};