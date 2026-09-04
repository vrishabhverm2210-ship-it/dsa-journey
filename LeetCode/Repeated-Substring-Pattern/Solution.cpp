1class Solution {
2public:
3    bool repeatedSubstringPattern(string s) {
4        // let's make the lps of this 
5        int n=s.size();
6        vector<int>lps(n,0);
7        int j=0;
8       int i=1;
9       while(i<n){
10        if(s[i]==s[j]){
11            j++;
12            lps[i]=j;
13            i++;
14        }
15        else{
16            if(j!=0){
17                j=lps[j-1];
18            }
19            else{
20                i++;
21            }
22        }
23       }
24       int n1=lps[n-1];
25       if(n1==0)return false;
26       if(n%(n-n1)==0)return true;
27       return false;
28    }
29};