1class Solution {
2public:
3    string intToRoman(int num) {
4          vector<int> values = {
5            1000, 900, 500, 400,
6            100, 90, 50, 40,
7            10, 9, 5, 4, 1
8        };
9
10        vector<string> symbols = {
11            "M", "CM", "D", "CD",
12            "C", "XC", "L", "XL",
13            "X", "IX", "V", "IV", "I"
14        };
15        string ans="";
16        for(int i=0;i<values.size();i++){
17            while(num>=values[i]){
18                 ans+=symbols[i];
19                 num-=values[i];
20            }
21        }
22        return ans;
23    }
24};