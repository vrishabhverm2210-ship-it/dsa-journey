1class Solution {
2public:
3    int peakIndexInMountainArray(vector<int>& arr) {
4        int low=0;
5        int high=arr.size()-1;
6        int res=-1;
7        while(low<=high){
8            int mid=low+(high-low)/2;
9            if(arr[mid]<arr[mid+1]){
10                // we are in the first  half so increase the low
11                low=mid+1;
12            }
13            else{
14                // we are in the second half try minimising
15                res=mid;
16                high=mid-1;
17            }
18        }
19        return res;
20    }
21};