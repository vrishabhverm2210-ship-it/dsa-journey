1class Solution {
2public:
3    int minSubArrayLen(int target, vector<int>& nums) {
4        int n=nums.size();
5        int sum=0;
6        int res=INT_MAX;
7        int low=0;
8        for(int high=0;high<n;high++){
9            sum+=nums[high];
10            while(target<=sum){
11                // first find the length
12                int len=high-low+1;
13                res=min(res,len);
14                // remove the lowth element from the sum
15                sum-=nums[low];
16                low++;
17            }
18        }
19        if(res==INT_MAX)return 0;
20        return res;
21    }
22};