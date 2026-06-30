1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& temperatures) {
4       int n=temperatures.size();
5       stack<int>st;
6       vector<int>res(n);
7       st.push(n-1);
8       res[n-1]=0;
9       for(int i=n-2;i>=0;i--){
10        while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
11            st.pop();
12        }
13        if(st.empty())res[i]=0;
14        else{
15            res[i]=st.top()-i;
16        }
17        st.push(i);
18       }
19       return res;
20    }
21};
22 // we are going to use next greater element logic but we are storing indexes instead of actual value