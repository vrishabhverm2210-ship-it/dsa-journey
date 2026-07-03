1class Solution {
2public:
3    string removeDuplicates(string s) {
4        int n=s.size();
5        stack<char>st;
6        string res="";
7        for(int i=0;i<n;i++){
8          if(st.empty()){
9            st.push(s[i]);
10            continue;
11          }
12          if(st.top()==s[i]){
13            st.pop();
14            continue;
15          }
16          if(st.top() != s[i]){
17            st.push(s[i]);
18          }
19        }
20       while(!st.empty()){
21        res.push_back(st.top());
22        st.pop();
23       } 
24       reverse(res.begin(),res.end());
25       return res;
26    }
27};