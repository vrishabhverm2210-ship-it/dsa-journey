1class Solution {
2public:
3bool isoperator(string ch){
4    if(ch=="+" || ch=="-" || ch=="*" || ch=="/")
5        return true;
6
7    return false;
8}
9    int evalRPN(vector<string>& tokens) {
10        int n=tokens.size();
11        stack<int>st;
12        for(int i=0;i<n;i++){
13            if(isoperator(tokens[i])){
14                string ch=tokens[i];
15               if(ch=="+" || ch=="*"){
16                int c1=st.top(); st.pop();
17                int c2=st.top(); st.pop();
18                if(ch=="+")st.push(c1+c2);
19                else st.push(c1*c2);
20               }
21               else {
22                int  c2=st.top();st.pop();
23                int c1=st.top();st.pop();
24                if(ch=="/"){
25                    st.push(c1/c2);
26
27                }
28                else{
29                    st.push(c1-c2);
30                }
31               }
32
33            }
34            else{
35                st.push(stoi(tokens[i]));
36            }
37        }
38        return st.top();
39    }
40};