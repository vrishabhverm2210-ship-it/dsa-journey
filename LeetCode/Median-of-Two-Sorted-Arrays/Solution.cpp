1class Solution {
2public:
3    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
4        int n1=nums1.size();
5        int n2=nums2.size();
6        vector<int>res(n1+n2);
7        int i=0;
8        int j=0;
9        int k=0;
10        while(i<n1 && j<n2){
11            if(nums1[i]<nums2[j]){
12                res[k]=nums1[i];
13                k++;
14                i++;
15            }
16            else{
17                 res[k]=nums2[j];
18                k++;
19                j++;
20            }
21        }
22        while(i<n1){
23              res[k]=nums1[i];
24                k++;
25                i++;
26        }
27        while(j<n2){
28                res[k]=nums2[j];
29                k++;
30                j++;
31        }
32
33        int len=n1+n2;
34      if (len % 2 == 0) {
35    return (res[len/2 - 1] + res[len/2]) / 2.0;
36}
37
38return res[len/2];
39    }
40};