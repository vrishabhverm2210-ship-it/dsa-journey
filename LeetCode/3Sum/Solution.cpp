1class Solution {
2public:
3    vector<vector<int>> threeSum(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5          vector<vector<int>>res;
6          for(int idx=0;idx<nums.size()-2;idx++){
7            if(idx>0 && nums[idx]==nums[idx-1])continue;
8            int i=idx+1;
9            int j=nums.size()-1;
10            while(i<j){
11                if(nums[i]+nums[j] == -1* nums[idx]){
12                    res.push_back({nums[i],nums[j],nums[idx]});
13                    i++;
14                    j--;
15                    while(i<nums.size() && nums[i]==nums[i-1]){   // Pichle vaale se compare krega
16                        i++;
17                    }
18                      while(j>=0 && nums[j]==nums[j+1]){// remeber the edge cases 
19                        j--;
20                    }
21                }
22              else  if(nums[i]+nums[j] > -1* nums[idx]) j--;
23              else{
24                i++;
25              }
26            }
27          }
28          return res;
29    }
30};