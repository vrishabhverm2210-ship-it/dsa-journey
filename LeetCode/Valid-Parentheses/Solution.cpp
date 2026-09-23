1class Solution {
2public:
3    bool isValid(string s) {
4        int n=s.size();
5        stack<int>st;
6        for(int i=0;i<n;i++){
7            int ch=s[i];
8            if(ch=='[' || ch=='(' || ch=='{'){
9                st.push(ch);
10            }
11            else{
12                if(st.empty()){
13                    return false;
14                }
15                else{
16                    if((st.top()=='[' && ch==']' )||(st.top()=='(' && ch==')' )||(st.top()=='{' && ch=='}' )){
17                       st.pop();
18                    }
19                    else{
20                        return false;
21                    }
22                }
23            }
24        }
25        if(!st.empty())return false;
26        return true;
27    }
28};