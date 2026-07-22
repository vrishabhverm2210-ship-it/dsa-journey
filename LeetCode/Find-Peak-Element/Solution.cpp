1class Solution {
2public:
3    int findPeakElement(vector<int>& nums) {
4     // i have two conditions in my mind
5     int low=0;
6     int high=nums.size()-1;
7     int res=-1;
8     while(low<=high){
9        int mid=low+(high-low)/2;
10          if(mid == nums.size() - 1){
11        res = mid;
12        break;
13    }
14        if(nums[mid]<nums[mid+1]){
15            low=mid+1;
16        }
17        else{
18          
19             res=mid;
20            high=mid-1;
21        }
22     }   
23     return res;
24    }
25};