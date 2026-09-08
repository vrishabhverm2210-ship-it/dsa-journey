1class Solution {
2public:
3int fun1(string curr,string prefix){
4    int len=0;
5    for(int i=0;i<min(curr.size(),prefix.size());i++)
6{
7                if(curr[i]==prefix[i])len++;
8                else{
9                    break;
10                }
11}
12return len;
13}
14    string longestCommonPrefix(vector<string>& strs) {
15        string prefix=strs[0];
16        int len=INT_MAX;
17        for(int i=1;i<strs.size();i++){
18           int temp= fun1(strs[i],prefix);
19            len=min(temp,len);
20        }
21        return prefix.substr(0,len);
22    }
23};