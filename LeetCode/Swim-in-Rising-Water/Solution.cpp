1class Solution {
2public:
3int x[4]={-1,1,0,0};
4int y[4]={0,0,-1,1};
5bool isValid(int row,int col,int n,int m){
6    if(row<0 || row>=n || col<0 || col>=m)return false;
7    return true;
8}
9    int swimInWater(vector<vector<int>>& grid) {
10        int n=grid.size();
11        int m=grid[0].size();
12           // make min heap(now we have to store the cordinates so teen cheezen honi chahiye
13         priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
14          vector<vector<int>>res(n);
15             for(int i=0;i<n;i++ ){
16              vector<int>t(n,INT_MAX);
17              res[i]=t;
18         }
19           res[0][0] = grid[0][0];
20         pq.push({grid[0][0],{0,0}});
21         while(!pq.empty()){
22            pair<int,pair<int,int>>curr=pq.top();
23            pq.pop();
24            int time=curr.first;
25            int i=curr.second.first;
26            int j=curr.second.second;
27            if(time>res[i][j])continue;
28            for(int k=0;k<4;k++){
29
30                int row=i+x[k];
31                int col=j+y[k];
32                if(!isValid(row,col,n,m))continue;
33                 int newtime=max(time,grid[row][col]);
34                if( newtime < res[row][col]){
35               res[row][col]=newtime;
36               pq.push({newtime,{row,col}});
37                    
38            }
39         }
40         }
41return res[n-1][n-1] ;
42    }
43};