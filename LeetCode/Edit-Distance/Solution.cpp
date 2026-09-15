1class Solution {
2public:
3    int solveRec(int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
4        // Base cases
5        if (i == 0) return j; // Need to insert j characters
6        if (j == 0) return i; // Need to delete i characters
7
8        // If already computed
9        if (dp[i][j] != -1) return dp[i][j];
10
11        // If characters match, no operation needed
12        if (word1[i - 1] == word2[j - 1]) {
13            return dp[i][j] = solveRec(i - 1, j - 1, word1, word2, dp);
14        }
15
16        // If characters don't match: try all 3 operations
17        int insertOp = solveRec(i, j - 1, word1, word2, dp);     // Insert
18        int deleteOp = solveRec(i - 1, j, word1, word2, dp);     // Delete
19        int replaceOp = solveRec(i - 1, j - 1, word1, word2, dp); // Replace
20
21        return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
22    }
23
24    int minDistance(string word1, string word2) {
25        int n = word1.length();
26        int m = word2.length();
27
28        // DP table initialized with -1
29        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
30
31        return solveRec(n, m, word1, word2, dp);
32    }
33};
34