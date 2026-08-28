1class Solution {
2public:
3int x[4]={-1,1,0,0};
4int y[4]={0,0,-1,1};
5bool isvalid(int row,int col,int n,int m){
6    if(row<0 || row>=n || col<0 || col>=m)return false;
7    return true;
8}
9void dfs(vector<vector<int>>& image,int sr,int sc,int color,int c){
10    int n=image.size();
11    int m=image[0].size();
12    image[sr][sc]=color;
13    for(int k=0;k<4;k++){
14        int row=sr+x[k];
15        int col=sc+y[k];
16        if(isvalid(row,col,n,m) && image[row][col]==c){
17            dfs(image,row,col,color,c);
18        }
19    }
20}
21    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
22        // there is no need to run a loop like the no of island questions
23        // we can directly start dfs from image[sr][sc]
24        int c=image[sr][sc];
25        if(c == color)
26    return image;
27        dfs(image,sr,sc,color,c);
28        return image;
29    }
30};