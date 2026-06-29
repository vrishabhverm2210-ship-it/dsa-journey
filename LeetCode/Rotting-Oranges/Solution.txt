1class Solution {
2public:
3int x[4]={-1,1,0,0};
4int y[4]={0,0,-1,1};
5bool isValid(int row,int col,int n,int m){
6    if(row<0 ||row>=n || col<0 || col>=m)return false;
7    return true;
8}
9    int orangesRotting(vector<vector<int>>& grid) {
10        int n=grid.size();
11        int m=grid[0].size();
12        int fresh=0;
13        queue<pair<int,int>>q;
14        // loop for finding 2 and pushing it into queue
15        for(int i=0;i<n;i++){
16            for(int j=0;j<m;j++){
17             if(grid[i][j]==2){
18                q.push({i,j});
19               grid[i][j]=-2;   // for avoiding repetition
20               }
21
22              else if(grid[i][j]==1)fresh++;
23                //  fresh++;
24            }    
25        }
26        if(fresh<1)return 0;
27        int time=0;
28        // now do multisource bfs
29        while(!q.empty() && fresh>0){
30            time++;
31            int s=q.size();
32            while(s>0){
33                pair<int,int>top=q.front();
34                q.pop();
35                s--;
36                int i=top.first;
37                int j=top.second;
38                for(int k=0;k<4;k++){
39                    int row=i+x[k];
40                    int col=j+y[k];
41                    if(isValid(row,col,n,m) && grid[row][col]==1){
42                        q.push({row,col});
43                        grid[row][col]=-2;
44                        fresh--;
45                    }
46                }
47            }
48        }
49        if(fresh>0)return -1;
50        return time;
51    }
52};