1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4        int slow=0;
5        int fast=0;
6        while(true ){
7            slow=nums[slow];
8            fast=nums[fast];
9            fast=nums[fast];
10            if(slow==fast){
11                slow=0;
12                while(slow!=fast){
13                    slow= nums[slow];
14                    fast=nums[fast];
15                }
16                return slow;
17            }
18        }
19        return -1;
20    }
21};