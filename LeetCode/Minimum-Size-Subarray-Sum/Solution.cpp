1class Solution {
2public:
3    int minSubArrayLen(int target, vector<int>& nums) {
4        int mini=INT_MAX;
5        int n=nums.size();
6        int high=0;
7        int low=0;
8        int sum=0;
9        for(high=0;high<n;high++){
10          sum+=nums[high];
11          // wrong info block
12          while(sum>=target){
13               int len=high-low+1;
14            mini =min(mini,len);
15            sum-=nums[low];
16            low++;
17        
18            // int len=high-low+1;
19            // mini =min(mini,len);
20          }         
21        }
22        if(mini==INT_MAX)return 0;
23        return mini;
24    }
25};