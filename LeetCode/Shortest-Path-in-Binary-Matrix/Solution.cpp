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
12        queue<pair<int,int>>q;
13              // Start or destination blocked
14        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
15            return -1;
16
17        q.push({0,0});
18        grid[0][0]=1;
19        int distance=1;
20           while (!q.empty()) {
21            int size = q.size();
22
23            while (size--) {
24                pair<int,int>curr=q.front();
25                q.pop();
26                int i=curr.first;
27                int j=curr.second;
28                  if (i == n-1 && j == n-1)
29                    return distance;
30                for(int k=0;k<8;k++){
31                    int row=i+x[k];
32                    int col=j+y[k];
33                    
34                    if(isValid(row,col,n) && grid[row][col]==0){
35                            grid[row][col] = 1; // mark visited
36                        q.push({row, col});
37                    }
38                }
39            }
40            distance++;
41           }
42return -1;
43    }
44};