1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4        
5    int n= nums.size();
6        // push the choice into the stack 
7        stack<int>st;
8        for(int i=n-2;i>=0;i--){
9            st.push(nums[i]);
10        }
11        vector<int>res;
12        // now normal loop to find the next greater element
13        for(int i=n-1;i>=0;i--){
14            while(!st.empty() && st.top()<=nums[i]){
15                st.pop();
16            }
17            if(st.empty()){
18                res.push_back(-1);
19            }
20            else{
21               res.push_back(st.top());
22            }
23            st.push(nums[i]);
24        }
25        reverse(res.begin(),res.end());
26        return res;
27     }
28};