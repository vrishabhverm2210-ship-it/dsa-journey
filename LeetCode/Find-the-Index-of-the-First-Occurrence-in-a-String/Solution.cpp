1class Solution {
2public:
3    int strStr(string haystack, string needle) {
4        int n=haystack.size();
5        int m=needle.size();
6        for(int i=0;i<n;i++){
7            if(haystack[i]==needle[0]){
8                int idx=i+1;
9                for(int j=1;j<m;j++){
10                    if(needle[j]==haystack[idx]){
11                        idx++;
12                    }
13                    else{
14                        break;
15                    }
16                }
17                if(abs(i-idx)==needle.size())return i;
18            }
19            
20        }
21        return -1;
22    }
23};