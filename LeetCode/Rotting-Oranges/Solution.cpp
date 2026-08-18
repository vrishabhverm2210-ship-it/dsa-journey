1class Solution {
2public:
3int x[4]={-1,1,0,0};
4int y[4]={0,0,-1,1};
5
6bool isvalid(int row,int col,int n,int m ){
7    if(row >=0 && row<n && col >=0 && col<m){
8        return true;
9    }
10    return false;
11}
12    int orangesRotting(vector<vector<int>>& grid) {
13        // make a queue
14        queue<pair<int,pair<int,int>>>q;
15        int freshcount=0;
16        for(int i=0;i<grid.size();i++){
17            for(int j=0;j<grid[0].size();j++){
18              if(grid[i][j]==2){
19                q.push({grid[i][j],{i,j}});
20                 grid[i][j]=-1;
21              }
22              if(grid[i][j]==1){
23                freshcount++;
24              }
25            }
26        }
27        // now process in queue
28        int second=0;
29                if(freshcount<1)return 0;
30
31        while(!q.empty()&& freshcount>0){
32            int size=q.size();
33            second++;
34            while(size--){
35                pair<int,pair<int,int>>curr=q.front();
36                q.pop();
37                int node=curr.first;
38                int i=curr.second.first;
39                int j=curr.second.second;
40               
41             // push the neighbour
42            for(int k=0;k<4;k++){
43                int row=i+x[k];
44                int col=j+y[k];
45                if(isvalid(row,col,grid.size(),grid[0].size())  && grid[row][col]==1){
46                 q.push({grid[row][col],{row,col}});
47                 freshcount--;
48                  grid[row][col]=-1;
49
50                }
51            }
52            }
53        }
54        if(freshcount>0)return -1;
55        return second;
56    }
57};