1class Solution {
2public:
3int x[4]={-1,1,0,0};
4int y[4]={0,0,-1,1};
5
6bool isValid(int row,int col,int n,int m ){
7    if(row >=0 && row<n && col >=0 && col<m){
8        return true;
9    }
10    return false;
11}
12    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
13    
14        int n=mat.size();
15        int m=mat[0].size();
16            vector<vector<int>>res(n, vector<int>(m, -1));
17        queue<pair<int,pair<int,int>>>q;
18           
19        // push all the one into the q
20        for(int i=0;i<n;i++){
21            for(int j=0;j<m;j++){
22                  if (mat[i][j] == 0) {
23                    q.push({0, {i, j}});
24                    res[i][j] = 0;  // mark visited
25                }
26            }
27        }
28        // now do bfs
29        while(!q.empty()){
30            int size=q.size();
31            while(size--){
32                pair<int,pair<int,int>>curr=q.front();
33                q.pop();
34                int dist=curr.first;
35                int i=curr.second.first;
36                int j=curr.second.second;
37                res[i][j]=dist;
38                 for(int k=0;k<4;k++){
39                    int row=i+x[k];
40                    int col=j+y[k];
41                    if(isValid(row,col,n,m) && res[row][col]==-1){
42                         res[row][col] = dist + 1;
43
44                    q.push({dist + 1, {row, col}});
45                    }
46                 }
47            }
48        }
49        return res;
50    }
51};