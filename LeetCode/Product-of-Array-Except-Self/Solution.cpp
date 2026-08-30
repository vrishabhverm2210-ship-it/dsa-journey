1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int n=nums.size();
5        vector<int>prefix(n),suffix(n),result(n);
6
7        // calculate prefix product first
8        prefix[0]=1;
9        for(int i=1;i<n;i++){
10            prefix[i]=prefix[i-1]*nums[i-1];
11        }
12        // now calculate it's suffix part
13        suffix[n - 1] = 1;
14         for (int i = n - 2; i >= 0; i--) {
15           suffix[i] = suffix[i + 1] * nums[i + 1];
16    } 
17
18   // Now calculate result
19   for(int i=0;i<n;i++){
20    result[i]= prefix[i] * suffix[i];
21   }
22 
23 return result;
24        
25    }
26};