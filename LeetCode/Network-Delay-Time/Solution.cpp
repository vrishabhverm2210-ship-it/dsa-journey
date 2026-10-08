1class Solution {
2public:
3    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
4        // make the aj list
5        vector<vector<pair<int,int>>>adj(n);
6        for(int i=0;i<times.size();i++){
7            int src=times[i][0];
8            int dest=times[i][1];
9            int wt=times[i][2];
10            // as it is directed
11            adj[src-1].push_back({dest-1,wt});
12        }
13        // make the priority queue
14        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
15        pq.push({0,k-1});
16        vector<int>res(n,1e8);
17        res[k-1]=0;
18        while(!pq.empty()){
19            pair<int,int>top=pq.top();
20            pq.pop();
21            int dist=top.first;
22            int node=top.second;
23            if(dist>res[node])continue;
24            for(int i=0;i<adj[node].size();i++){
25                pair<int,int> top1=adj[node][i];
26                int neigh=top1.first;
27                int wt=top1.second;
28                if(wt+dist<res[neigh]){
29                    res[neigh]=wt+dist;
30                    pq.push({wt+dist,neigh});
31                }
32            }
33        }
34        // find the maximum one
35        int maxi=INT_MIN;
36        for(int i=0;i<res.size();i++){
37            maxi=max(maxi,res[i]);
38        }
39        if(maxi==1e8)return -1;
40        return maxi;
41    }
42};