1class Solution {
2public:
3bool isOperator(string t) {
4    if(t == "+" || t == "-" || t == "*" || t == "/")
5        return true;
6
7    return false;
8}
9    int evalRPN(vector<string>& tokens) {
10        int n=tokens.size();
11        stack<string >st;
12        for(int i=0;i<n;i++){
13           if(isOperator(tokens[i])){
14            // we have to do calculations
15            if(tokens[i]=="+" || tokens[i]=="*"){
16                int n1=stoi(st.top()); st.pop();
17                int n2=stoi(st.top()); st.pop();
18                if(tokens[i]=="+")st.push(to_string(n1+n2));
19                else{
20                    st.push(to_string(n1*n2));
21                }
22            }
23            else{  // order matters in the case of division and subtraction
24                int n2=stoi(st.top()); st.pop();
25                  int n1=stoi(st.top()); st.pop();
26                  if(tokens[i]=="/"){
27                    st.push(to_string(n1/n2));
28                  }
29                  else{
30                    st.push(to_string(n1-n2));
31                  }
32            }
33           }
34           else{
35            // push into the stack otherwise
36            st.push(tokens[i]);
37           }
38        }
39        return stoi(st.top());
40    }
41};