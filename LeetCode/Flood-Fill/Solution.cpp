1class Solution {
2public:
3int x[4]={-1,1,0,0};
4int y[4]={0,0,-1,1};
5bool issafe(int row,int col,int n,int m){
6    if(row<0 || col<0 || row >=n ||col>=m)return false;
7    return true;
8}
9void dfs(vector<vector<int>>& image,int startcolor, int i, int j,int color){
10       int n=image.size();
11        int m=image[0].size();
12    image[i][j]=color;
13    for(int k=0;k<4;k++){
14        int row=i+x[k];
15        int col=j+y[k];
16        if(issafe(row,col,n,m) && image[row][col]==startcolor){
17          dfs(image,startcolor,row,col,color);
18        }
19    }
20}
21    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
22        vector<vector<int>>  res;
23        int start=image[sr][sc];
24        // image[sr][sc]=color;
25     
26        // for(int i=0;i<n;i++){
27        //     for(int j=0;j<m;j++){
28        //         if(image[i][j]==start){
29
30        //         }
31        //     }
32        // }
33        if(start==color)return image;
34        dfs(image,start,sr,sc,color);
35return image;
36    }
37};