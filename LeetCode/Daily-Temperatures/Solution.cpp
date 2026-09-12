1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& temperatures) {
4       int n= temperatures.size();
5           vector<int>ans(n,0);
6           stack<int>st;
7           st.push(n-1);
8           for(int i=n-2;i>=0;i--){
9            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
10                st.pop();
11            }
12            if(st.empty()){
13                ans[i]=0;
14            }
15            else{
16                ans[i]=st.top()-i;
17            }
18            st.push(i);
19           }
20return ans;
21    }
22};