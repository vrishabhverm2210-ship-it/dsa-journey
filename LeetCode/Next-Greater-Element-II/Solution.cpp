1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4        stack<int>st;
5        int n=nums.size();
6         vector<int>res(n);
7         // initally push into stack for giving fair chance to last index element clockwise
8         for(int i=n-2;i>=0;i--){
9            st.push(nums[i]);
10         }
11         // now there is 0th index element on our stack top 
12          // now apply general logic of next greater element
13          for(int i=n-1;i>=0;i--){     // because we are starting from last index itself
14           // popping condition
15           while(!st.empty() && st.top() <= nums[i]){
16            st.pop();
17           }
18           if(st.empty()){
19            res[i]=-1;
20           }
21           else{
22            res[i]=st.top();
23           }
24           st.push(nums[i]);
25          }
26          return res;
27    }
28};