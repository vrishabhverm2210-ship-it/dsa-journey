1class Solution {
2public:
3    string longestPrefix(string s) {
4        // now i am gonna use the KMP APPROACH
5        vector<int>res(s.size(),0);
6        int i=1;
7        int len=0;
8        while(i<s.size()){
9            if(s[len]==s[i]){
10                len++;
11                res[i]=len;
12                i++;
13
14            }
15            else{
16                if(len!=0){
17                    len=res[len-1];
18
19                }
20                else{
21                    res[i]=0;
22                    i++;
23                }
24            }
25        }
26        // now can our vector res
27       int leni = res[s.size() - 1];
28
29return s.substr(0, leni);
30    }
31};