1class Solution {
2public:
3    bool isfound = false;
4
5    int x[4] = {-1, 1, 0, 0};
6    int y[4] = {0, 0, -1, 1};
7
8    bool isvalid(int i, int j, vector<vector<char>>& board) {
9        return i >= 0 && i < board.size() && j >= 0 && j < board[0].size() &&
10               board[i][j] != '-1';
11    }
12
13    void dfs(vector<vector<char>>& board, string& word, int idx, int i, int j) {
14
15        if (idx == word.size() - 1) {
16            isfound = true;
17            return;
18        }
19
20        char original = board[i][j];
21
22        // mark visited
23        board[i][j] = '-1';
24
25        for (int k = 0; k < 4; k++) {
26
27            int row = i + x[k];
28            int col = j + y[k];
29
30            if (isvalid(row, col, board) && board[row][col] == word[idx + 1]) {
31
32                dfs(board, word, idx + 1, row, col);
33
34                if (isfound)
35                    return;
36            }
37        }
38
39        // backtrack
40        board[i][j] = original;
41    }
42
43    bool exist(vector<vector<char>>& board, string word) {
44
45        int n = board.size();
46        int m = board[0].size();
47
48        for (int i = 0; i < n; i++) {
49            for (int j = 0; j < m; j++) {
50
51                if (board[i][j] == word[0]) {
52
53                    dfs(board, word, 0, i, j);
54
55                    if (isfound)
56                        return true;
57                }
58            }
59        }
60
61        return false;
62    }
63};