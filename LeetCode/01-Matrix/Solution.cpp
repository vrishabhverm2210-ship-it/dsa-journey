1class Solution {
2public:
3int x[4]={-1,1,0,0};
4int y[4]={0,0,-1,1};
5bool isvalid(int i,int j,int n,int m){
6    if(i<0 || i>=n|| j<0 || j>=m)return false;
7    return true;
8}
9    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
10        int  n=mat.size();
11        int m=mat[0].size();
12        queue<pair<int,pair<int,int>>>q;
13        for(int i=0;i<n;i++){
14            for(int j=0;j<m;j++){
15                if(mat[i][j]==0){
16                    q.push({0,{i,j}});
17                }
18            }
19        }
20
21        // run a mutltisource bfs
22        while(!q.empty()){
23            int size=q.size();
24            while(size--){
25                pair<int,pair<int,int>>curr=q.front();
26                q.pop();
27                int node=curr.first;
28                int i=curr.second.first;
29                int j=curr.second.second;
30                for(int k=0;k<4;k++){
31                    int row=i+x[k];
32                    int col=j+y[k];
33                    if(isvalid(row,col,n,m) && mat[row][col]==1){
34                        mat[row][col]=node+1;
35                        q.push({node+1,{row,col}});
36                        mat[row][col]=-1*mat[row][col];
37                    }
38                }
39            }
40        }
41        for(int i=0;i<n;i++){
42            for(int j=0;j<m;j++){
43              mat[i][j]=abs(mat[i][j]);
44            }
45        }
46        return mat;
47    }
48};