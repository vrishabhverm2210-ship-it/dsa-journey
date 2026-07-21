1class Solution {
2public:
3    int longestOnes(vector<int>& nums, int k) {
4        int zerocnt=0;
5        int n=nums.size();
6        int low=0;
7        int res=0;
8        for(int high=0;high<n;high++){
9            // now 1st step increase the zero count
10            if(nums[high]==0)zerocnt++;
11            // now write the shrinking condition we have to shrink when our zerocount exceeds k
12            while(zerocnt>k){
13                if(nums[low]==0)zerocnt--;
14                low++;        
15            }
16            // now update the length
17            int len=high-low+1;
18            res=max(res,len);
19        }
20        return res;
21    }
22};