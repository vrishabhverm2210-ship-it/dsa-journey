1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4       stack<int>st;
5       int n=nums.size();
6       for(int i=n-2;i>=0;i--){   // we are pushing the elements for the last index , for providing him fair chance
7        st.push(nums[i]);
8       }
9        vector<int>res(n);
10       // now we have to apply are standard next greater template
11       for(int i=n-1;i>=0;i--){ 
12        // popping case
13        while(!st.empty() && st.top()<=nums[i]){
14            st.pop();
15        }
16        if(st.empty())res[i]=-1;
17        else{
18          res[i]=st.top();
19        }
20        st.push(nums[i]);
21       }
22       return res;
23    }
24};