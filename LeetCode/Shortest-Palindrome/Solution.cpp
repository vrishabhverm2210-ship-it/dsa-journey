1class Solution {
2public:
3vector<int>fun1(string& s){
4      int n = s.size();
5        vector<int> lps(n, 0);
6         int i=1;
7        int len=0;
8while(i<n){
9       
10        if(s[i]==s[len]){
11            len++;
12            lps[i]=len;
13            i++;
14        }
15        else{
16            if(len!=0){
17                len=lps[len-1];
18            }
19            else{
20                i++;
21            }
22        }
23}
24return  lps;
25}
26    string shortestPalindrome(string s) {
27        // make the new string
28        string rev=s;
29        reverse(rev.begin(),rev.end());
30        string temp=s+'#'+rev;
31        // now find the lps
32        vector<int>lps=fun1(temp);
33// it give us the longest palindromic prefix length
34       int len= lps.back();
35       string remaining=s.substr(len);
36       reverse(remaining.begin(),remaining.end());
37       return remaining+s;
38
39    }
40};