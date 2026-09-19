1class Solution {
2public:
3    int titleToNumber(string columnTitle) {
4        int n=columnTitle.size();
5        int ans=0;
6        for(int i=0;i<n;i++){
7
8            int value = columnTitle[i] - 'A' + 1;
9             ans=ans*26+value;    // 26 is the base unit
10        }
11        return ans;
12    }
13};