1class Solution {
2public:
3    string removeDuplicates(string s) {
4        // implement stack
5        stack<char>st;
6        for(int i=0;i<s.size();i++){
7            char ch=s[i];
8            if(st.size()==0){
9                st.push(ch);
10                continue;
11            }
12            if(st.top() == s[i]){
13                // popping cdn
14                st.pop();  // automatically it will remove the duplicate 1 element(mentioned in the question itself)
15                continue;
16            }
17            if(st.top() != s[i]){
18                st.push(ch);
19                continue;
20            }
21        }
22        // we have to extract answer from stack using while loop
23        string res="";
24        while(!st.empty()){
25            res.push_back(st.top());
26            st.pop();
27        }
28        // at last revrerse our answer variable
29        reverse(res.begin(),res.end());
30        return res;
31    }
32};