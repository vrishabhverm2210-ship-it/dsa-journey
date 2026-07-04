1class Solution {
2public:
3    int peakIndexInMountainArray(vector<int>& arr) {
4        int n=arr.size();
5        int start=0;
6        int end=arr.size()-1;
7        int res=-1;
8        while(start<=end){
9            int mid=start+(end-start)/2;
10            // if(arr[mid]>arr[mid+1]){
11            //     high=mid;
12            // }
13             if(arr[mid]<arr[mid+1]){
14                start=mid+1;
15            }
16            else{
17
18                res=mid;
19                end=mid-1;
20            }
21        }
22        return res;
23    }
24};