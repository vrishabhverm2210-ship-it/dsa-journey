1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char>st;  // we have to make the stack of char datatype
5        // step1 ->for opening we are pushing inside the stack
6        for(int i=0;i<s.size();i++){
7            char ch=s[i];
8            if(ch == '[' || ch == '{' || ch == '('){
9                st.push(ch);
10                continue;
11            }
12            else{  // step2: if they are closing we have to firstly check empty cdn then matching condtion
13            if(st.empty())return false;
14            char top=st.top();
15            if((ch==']' && top =='[')  || (ch==')' && top =='(') || (ch=='}' && top =='{')){
16                st.pop();
17            }
18            else{
19                return false;
20            }
21            }
22        }
23        if(!st.empty())return false;
24        return true;
25
26    }
27};