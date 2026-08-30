1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int ans=0;
5        for(int i=0;i<32;i++){
6            int count=0;
7            for(auto n:nums){
8                if(n & (1<<i)){  // if it's true only then do count++, means humari ith bit pe 1 hai, n no ki 
9                    count++;
10                }
11            }
12            if(count%3!=0){
13                ans|=(1<<i); // means the ith bit of the answer consist of the 1 bit 
14            }
15        }
16        return ans;
17    }
18};