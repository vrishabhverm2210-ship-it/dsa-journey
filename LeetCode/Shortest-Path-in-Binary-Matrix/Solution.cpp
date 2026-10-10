1class Solution {
2public:
3int x[8] = {-1,-1,-1,0,0,1,1,1};
4    int y[8] = {-1,0,1,-1,1,-1,0,1};
5
6    bool isValid(int row, int col, int n) {
7        return row >= 0 && row < n && col >= 0 && col < n;
8    }
9    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
10        int n=grid.size();
11        int m=grid[0].size();
12        if(grid[0][0]==1)return -1;
13        if(grid[n-1][m-1]==1)return -1;
14
15        queue<pair<int,int>>q;
16        q.push({0,0});
17        grid[0][0]=1;
18        int dist=1;
19        while(!q.empty()){
20            int size=q.size();
21            while(size--){
22                pair<int,int>curr=q.front();
23                q.pop();
24                int i=curr.first;
25                int j=curr.second;
26                if(i==n-1&&j==m-1)return dist;
27                  for(int k=0;k<8;k++){
28                    int row=i+x[k];
29                    int col=j+y[k];
30                    
31                    if(isValid(row,col,n) && grid[row][col]==0){
32                            grid[row][col] = 1; // mark visited
33                        q.push({row, col});
34                    }
35                }
36
37            
38            }
39            dist++;
40        }
41return -1;
42    }
43};