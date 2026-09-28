1class Solution {
2public:
3    string intToRoman(int num) {
4
5        vector<int> values = {
6            1000, 900, 500, 400,
7            100, 90, 50, 40,
8            10, 9, 5, 4, 1
9        };
10
11        vector<string> symbols = {
12            "M", "CM", "D", "CD",
13            "C", "XC", "L", "XL",
14            "X", "IX", "V", "IV", "I"
15        };
16
17        string ans = "";
18
19        for(int i = 0; i < values.size(); i++) {
20
21            while(num >= values[i]) {
22
23                ans += symbols[i];
24
25                num -= values[i];
26            }
27        }
28
29        return ans;
30    }
31};