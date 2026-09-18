1class Solution {
2public:
3    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
4        vector<int>temp(n+m,0);
5        int k=0;
6        int i=0;
7        int j=0;
8        if(n==0 && m==0)return;
9        // if(n==0) nums1=nums2 ;return ;
10        // if(m==0) return;
11        while(i<n&& j<m){
12            if(nums1[i]<nums2[j]){
13                temp[k]=nums1[i];
14                i++;
15                k++;
16            }
17            else {
18                temp[k]=nums2[j];
19                k++;
20                j++;
21            }
22        //     else{
23        //         temp[k]=nums1[i];
24        //         i++;
25        //         k++;
26        //         temp[k]=nums2[j];
27        //         j++;
28        //         k++;
29        //     }
30        // }
31        }
32        while(i<n){
33            temp[k++]=nums1[i++];
34
35        }
36        while(j<m){
37            temp[k++]=nums2[j++];
38        }
39        nums1=temp;
40    }
41};