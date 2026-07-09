1class Solution {
2public:
3    int maxOperations(vector<int>& nums, int k) {
4        sort(nums.begin(),nums.end());
5        int n =nums.size();
6        int i=0;
7        int j=n-1;
8        int count=0;
9        while(i<j){
10            if(nums[i]+nums[j]==k){
11                count++;
12                i++;
13                j--;
14            }
15            else if( nums[i] +nums[j]> k )
16            {
17              j--;
18            }
19            else
20            {
21                i++;
22            }
23        }
24        return count;
25    }
26};