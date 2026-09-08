1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4        // let's try to do it via boyre more algo
5        int n=nums.size();
6        int count=0;
7        int candidate=0;
8        for(int i=0;i<n;i++){
9            if(count==0){
10                candidate=nums[i];
11                count++;
12             
13            }
14            else if(candidate==nums[i]){
15                count++;
16            }
17            else{
18                count--;
19            }
20        }
21        return candidate;
22    }
23};