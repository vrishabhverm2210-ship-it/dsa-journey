1class Solution {
2public:
3    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
4         vector<int>res(n,1e9);
5         res[src]=0;
6         vector<int>temp;
7        for(int i=0;i<=k;i++){
8           temp=res;
9            for(int j=0;j<flights.size();j++){
10                int src=flights[j][0];
11                int dest=flights[j][1];
12                int wt=flights[j][2];
13                if(res[src]!=1e9 && temp[dest]>res[src]+wt){
14                    temp[dest]=res[src]+wt;
15                }
16            }
17            res=temp;
18        }
19        if(res[dst]==1e9)return -1;
20        return res[dst];
21    }
22};