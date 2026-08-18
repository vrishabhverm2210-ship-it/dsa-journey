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
12    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
13        int element=image[sr][sc];
14        int n=image.size();
15        int m=image[0].size();
16        vector<vector<int>>res=image;
17      
18        queue<pair<int,pair<int,int>>>q;
19        q.push({element,{sr,sc}});
20        while(!q.empty()){
21           pair<int,pair<int,int>>p=q.front();
22           q.pop();
23           int c=p.first;
24           int i=p.second.first;
25           int j=p.second.second;
26          res[i][j]=color;
27          for(int k=0;k<4;k++){
28            int row=i+x[k];
29            int col=j+y[k];
30            if(isvalid(row,col,n,m) && image[row][col]==element){
31            
32                q.push({element,{row,col}});
33                image[row][col]=-1;
34            }
35          }
36
37
38        }
39        return res;
40            }
41};