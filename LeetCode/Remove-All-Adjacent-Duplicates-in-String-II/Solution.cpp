1class Solution {
2public:
3    string removeDuplicates(string s, int k) {
4        stack<pair<char,int>>st;
5        string res="";
6        int n=s.size();
7        for(int i=0;i<n;i++){
8            if(st.empty()){
9                st.push({s[i],1});
10                continue;
11            }
12            if(st.top().first != s[i]){
13                st.push({s[i],1});
14                continue;
15            }
16            if(st.top().first==s[i] && st.top().second<k-1){
17                pair<char,int>top=st.top();
18                st.pop();
19                st.push({top.first,top.second+1});
20                continue;
21            }
22            else{
23                st.pop();
24            }
25        }
26        while(!st.empty()){
27            pair<char,int>top=st.top();
28            st.pop();
29            while(top.second--){
30                res.push_back(top.first);
31            }
32        }
33        reverse(res.begin(),res.end());
34        return res;
35    }
36};