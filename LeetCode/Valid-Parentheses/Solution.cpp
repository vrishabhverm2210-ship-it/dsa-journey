1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char>st;
5        for(int i=0;i<s.size();i++){
6            char ch=s[i];
7            if(ch=='{' || ch=='(' || ch=='['){
8                st.push(ch);
9            }
10            else {  // means closed bracket
11            // firstly check is there any open bracket if not return straighway flse;
12            if(st.empty())return false;
13            if((st.top()=='[' && ch==']' )||(st.top()=='(' && ch==')' ) || (st.top()=='{' && ch=='}' ) ){
14                st.pop();
15            }
16            else {
17                return false;
18            }
19
20            }
21        }
22        if(!st.empty())return false;
23        return true;
24    }
25};