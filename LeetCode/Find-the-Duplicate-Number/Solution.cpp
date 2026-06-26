1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4         // Let's use slow-fast apporach here(main tax how to traverse)
5         int slow=0;
6         int fast=0;
7         while(true){    // no need to check becuase given hai question mai ki given hai ek duplicate for sure
8            slow=nums[slow];
9            fast=nums[fast];
10            fast=nums[fast];  // two times
11            if(slow==fast){
12                slow=0;
13                while(slow!=fast){
14                    slow=nums[slow];
15                    fast=nums[fast];
16                }
17                return slow;    // yahi humara duplicate point hoga for sure
18            }
19
20         }
21         return -1;
22    }
23};