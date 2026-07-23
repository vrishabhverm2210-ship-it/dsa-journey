1class Solution {
2public:
3    string removeDuplicates(string s) {
4        int n=s.size();
5        // we are going to make stack 
6        stack<int>st;
7       
8        for(int i=0;i<n;i++){
9            if(st.empty()){
10                st.push(s[i]);
11                continue;
12            }
13            if(st.top()==s[i]){
14                st.pop();
15            }
16            else{
17                st.push(s[i]);
18            }
19        }
20        // now extract the answer from the stack and push it into the res vector
21         string res="";
22         while(!st.empty()){
23            res.push_back(st.top());
24            st.pop();
25         }
26        reverse(res.begin(),res.end());
27        return res;
28    }
29};