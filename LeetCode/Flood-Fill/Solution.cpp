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
20        image[sr][sc]=-1;
21        while(!q.empty()){
22           pair<int,pair<int,int>>p=q.front();
23           q.pop();
24           int c=p.first;
25           int i=p.second.first;
26           int j=p.second.second;
27          res[i][j]=color;
28          for(int k=0;k<4;k++){
29            int row=i+x[k];
30            int col=j+y[k];
31            if(isvalid(row,col,n,m) && image[row][col]==element){
32            
33                q.push({element,{row,col}});
34                image[row][col]=-1;
35            }
36          }
37
38
39        }
40        return res;
41            }
42};