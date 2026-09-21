1class Solution {
2public:
3    string convertToTitle(int columnNumber) {
4        string res = "";
5
6        while (columnNumber > 0) {
7            columnNumber--;
8
9            char ch = 'A' + (columnNumber % 26);
10            res.push_back(ch);
11
12            columnNumber /= 26;
13        }
14
15        reverse(res.begin(), res.end());
16
17        return res;
18    }
19};