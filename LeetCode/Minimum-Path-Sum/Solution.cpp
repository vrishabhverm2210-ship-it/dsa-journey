1class Solution {
2public:
3    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
4        int n = grid.size();
5        int m = grid[0].size();
6
7        // Out of bounds
8        if (i >= n || j >= m) return INT_MAX;
9
10        // Destination cell
11        if (i == n - 1 && j == m - 1) return grid[i][j];
12
13        // If already computed
14        if (dp[i][j] != -1) return dp[i][j];
15
16        int right = solve(grid, i, j + 1, dp);
17        int down = solve(grid, i + 1, j, dp);
18
19        return dp[i][j] = grid[i][j] + min(right, down);
20    }
21
22    int solveTab(vector<vector<int>>& grid, int i, int j ){
23          int n = grid.size();
24        int m = grid[0].size(); 
25
26    vector<vector<int>> dp(n, vector<int>(m, 0)); 
27    dp[0][0]=grid[0][0];
28    //fill first row
29
30         // Fill first row
31        for (int j = 1; j < m; j++)
32            dp[0][j] = dp[0][j - 1] + grid[0][j];
33
34        // Fill first column
35        for (int i = 1; i < n; i++)
36            dp[i][0] = dp[i - 1][0] + grid[i][0];
37
38        // Fill the rest
39        for (int i = 1; i < n; i++) {
40            for (int j = 1; j < m; j++) {
41                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
42            }
43        }
44
45        return dp[n - 1][m - 1];
46    }
47
48    
49
50    int minPathSum(vector<vector<int>>& grid) {
51        int n = grid.size();
52        int m = grid[0].size();
53       /* vector<vector<int>> dp(n, vector<int>(m, -1));
54
55        return solve(grid, 0, 0, dp);*/
56
57
58        return solveTab(grid,0,0);
59    }
60};
61
62