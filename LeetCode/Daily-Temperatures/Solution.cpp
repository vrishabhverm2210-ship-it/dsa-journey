1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& temperatures) {
4        // int count=1;
5        int n=temperatures.size();
6        vector<int>res(n);
7        stack<int >st;
8        st.push(n-1);
9        res[n-1]=0;
10        for(int i=n-2;i>=0;i--){
11            while(!st.empty() &&  temperatures[st.top()]<=temperatures[i]){
12                st.pop();
13                // count++;
14            }
15            if(st.empty()){
16                res[i]=0;
17            }
18            else{
19                res[i]=st.top()-i;    // no
20            }
21             st.push(i);
22        }
23        return res;
24    }
25};