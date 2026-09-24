1class Solution {
2public:
3
4    int x[4] = {-1, 1, 0, 0};
5    int y[4] = {0, 0, -1, 1};
6
7    bool isvalid(int i, int j, vector<vector<char>>& board) {
8        return i >= 0 && i < board.size() &&
9               j >= 0 && j < board[0].size() &&
10               board[i][j] != '-1';
11    }
12
13    bool dfs(vector<vector<char>>& board, string& word,
14             int idx, int i, int j) {
15
16        if (idx == word.size() - 1)
17            return true;
18
19        char original = board[i][j];
20        board[i][j] = '-1';
21
22        for (int k = 0; k < 4; k++) {
23
24            int row = i + x[k];
25            int col = j + y[k];
26
27            if (isvalid(row, col, board) &&
28                board[row][col] == word[idx + 1]) {
29
30                if (dfs(board, word, idx + 1, row, col))
31                    return true;
32            }
33        }
34
35        // BACKTRACK
36        board[i][j] = original;
37
38        return false;
39    }
40
41    bool exist(vector<vector<char>>& board, string word) {
42
43        int n = board.size();
44        int m = board[0].size();
45
46        for (int i = 0; i < n; i++) {
47            for (int j = 0; j < m; j++) {
48
49                if (board[i][j] == word[0]) {
50
51                    if (dfs(board, word, 0, i, j))
52                        return true;
53                }
54            }
55        }
56
57        return false;
58    }
59};