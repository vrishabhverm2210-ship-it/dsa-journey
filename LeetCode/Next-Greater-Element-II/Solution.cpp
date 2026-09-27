1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4        int n= nums.size();
5        // push the choice into the stack 
6        stack<int>st;
7        for(int i=n-2;i>=0;i--){
8            st.push(nums[i]);
9        }
10        vector<int>res;
11        // now normal loop to find the next greater element
12        for(int i=n-1;i>=0;i--){
13            while(!st.empty() && st.top()<=nums[i]){
14                st.pop();
15            }
16            if(st.empty()){
17                res.push_back(-1);
18            }
19            else{
20               res.push_back(st.top());
21            }
22            st.push(nums[i]);
23        }
24        reverse(res.begin(),res.end());
25        return res;
26    }
27};