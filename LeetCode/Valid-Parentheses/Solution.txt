1class Solution {
2public:
3    bool isValid(string s) {
4        int n=s.size();
5        stack<char>st;
6        for(int i=0;i<n;i++){
7            char ch=s[i];
8            if(ch=='{' || ch=='('|| ch == '['){
9                st.push(ch);
10            }
11            else{   // ofcourse it's closing
12                if(st.empty())return false;
13                if(st.top()=='[' && ch==']' || st.top()=='{' && ch=='}'|| st.top()=='(' && ch==')' ){
14                    st.pop(); 
15                }
16                else{
17                    return false;
18                }
19            }
20        }
21        if(!st.empty())return false;
22        return true;
23    }
24};