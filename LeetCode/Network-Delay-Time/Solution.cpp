1class Solution {
2public:
3    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
4        /// make adj list
5        // make the aj list
6        vector<vector<pair<int,int>>>adj(n);
7        for(int i=0;i<times.size();i++){
8            int src=times[i][0];
9            int dest=times[i][1];
10            int wt=times[i][2];
11            // as it is directed
12            adj[src-1].push_back({dest-1,wt});
13        }
14        
15        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
16        pq.push({0,k-1});
17        vector<int>res(n,1e8);
18        res[k-1]=0;
19        while(!pq.empty()){
20            pair<int,int>curr=pq.top();
21
22            int  node=curr.second;
23            int dist=curr.first;
24               pq.pop();
25        if(res[node]<dist)continue;
26         
27
28            for(int i=0;i<adj[node].size();i++){
29                   pair<int,int> top1=adj[node][i];
30                int neigh=top1.first;
31                int wt=top1.second;
32                   if(wt+dist <res[neigh]){
33                    pq.push({wt+dist,neigh});
34                    res[neigh]=wt+dist;
35                   }
36            }
37        
38        }
39        int mini=INT_MIN;
40        for(int i=0;i<res.size();i++){
41            mini=max(res[i],mini);
42        }
43        if(mini==1e8)return -1;
44        return mini;
45    }
46};