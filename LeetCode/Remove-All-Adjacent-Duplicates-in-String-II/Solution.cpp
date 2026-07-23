1class Solution {
2public:
3    string removeDuplicates(string s, int k) {
4        int n=s.size();
5        stack<pair<char,int>>st;
6       for(int i=0;i<n;i++){
7        // first case that if hmara stack is empty
8        if(st.empty()){
9            st.push({s[i],1});
10        }
11        else if(st.top().first!=s[i]){
12            st.push({s[i],1});
13        }
14        else if(st.top().first==s[i] && st.top().second<k-1){
15            // in this case only increase the frequency
16            pair<char,int>p=st.top();
17            st.pop();
18            st.push({p.first,p.second+1});
19        }
20        else{
21            st.pop();
22        }
23       } 
24         // now extract the answer from the stack and push it into the res vector
25         string res="";
26         while(!st.empty()){
27            pair<char,int>p=st.top();
28            st.pop();
29            for(int i=0;i<p.second;i++){
30            res.push_back(p.first);
31            }
32         }
33        reverse(res.begin(),res.end());
34        return res;
35    }
36};