1class Solution {
2public:
3    int peakIndexInMountainArray(vector<int>& arr) {
4        int low=0;
5        int high=arr.size()-1;
6        int res=-1;
7        while(low<=high){
8            int mid=low+(high-low)/2;
9                  if(mid == arr.size() - 1){
10        res = mid;
11        break;
12    }
13            if(arr[mid]<arr[mid+1]){     // can do mid+1 cause it gurantees peak
14                // we are in the first  half so increase the low
15                low=mid+1;
16            }
17            else{
18                // we are in the second half try minimising
19                res=mid;
20                high=mid-1;
21            }
22        }
23        return res;
24    }
25};