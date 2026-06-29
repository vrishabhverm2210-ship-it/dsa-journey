1class Solution {
2public:
3    string removeDuplicates(string s) {
4
5        int i = 0;
6        while (i < s.length() - 1 && s.length() > 1) {
7            if (s[i] == s[i + 1]) {
8                s.erase(i, 2);
9                i = 0;
10            } else {
11                i++;
12            }
13        }
14            return s;
15    }
16};