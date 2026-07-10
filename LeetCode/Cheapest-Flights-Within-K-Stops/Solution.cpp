1class Solution {
2public:
3    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
4        // let's do this with belman algo 
5        vector<int>res(n,1e8);
6        res[src]=0;
7        for(int i=0;i<=k;i++){
8            vector<int>temp=res;// imprtant stepppppp
9            for(int j=0;j<flights.size();j++){
10              int source=flights[j][0];
11              int dest=flights[j][1];
12              int wt=flights[j][2];
13              if(res[source] != 1e8 && temp[dest] > res[source]+wt){  // this step is crucial jaha pe hum res mai rewrite hone se bacha re hai using temp vector    /// important step hai 
14
15                temp[dest]=res[source]+wt;
16              }
17            }
18              res=temp;
19        }
20      
21        if(res[dst]==1e8)return -1;
22        return res[dst];
23    }
24};