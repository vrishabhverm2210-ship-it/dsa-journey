1class Solution {
2public:
3int x[8]={-1,-1,-1,0,1,1,1,0};
4int y[8]={-1,0,1,1,1,0,-1,-1};
5bool isValid(int row,int col,int n,int m){
6    if(row<0 || row>=n || col<0 || col>=m)return false;
7    return true;
8}
9    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
10        // make the dist vector
11        int n=grid.size();
12        vector<vector<int>>dist(n,vector<int>(n,INT_MAX)); 
13       priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
14       // base case to handle 
15       if(grid[0][0]==1)return -1;
16       pq.push({1,{0,0}});
17       dist[0][0]=1;
18       
19       while(!pq.empty()){
20        pair<int,pair<int,int>>top=pq.top();
21        pq.pop();
22        int node=top.first;
23        int i=top.second.first;
24        int j=top.second.second;
25        if(node >dist[i][j])continue;
26        // go for the neighbours
27        for(int k=0;k<8;k++){
28            int row=x[k]+i;
29            int col=y[k]+j;
30            if(!isValid(row,col,n,n))continue;
31            if(grid[row][col]== 0 && dist[row][col]>node+1){
32                dist[row][col]=node+1;
33                pq.push({node+1,{row,col}});
34            }
35        }
36       }
37       if(dist[n-1][n-1]==INT_MAX)return -1;
38return dist[n-1][n-1];
39    }
40};