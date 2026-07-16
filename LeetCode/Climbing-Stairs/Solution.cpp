1class Solution {
2public:
3// unordered_map<int,int>mpp1;
4// int fun1(int i,int n){
5//     //  Base cases
6//     if(i==n)return 1;
7//     if(i>n)return 0;
8//     // check in map
9//     if(mpp1.find(i) != mpp1.end()){
10//         return mpp1[i];
11//     }
12
13//     // otherwise
14//     int r1=fun1(i+1,n);
15//     int r2=fun1(i+2,n);
16//     int ans=r1+r2;
17//     mpp1[i]=ans;
18//     return ans;
19// }
20
21    int climbStairs(int n) {
22        // return fun1(0,n);
23        // let's solve thsi using tabulation
24        // make vector dp
25        vector<int>dp(n+1);
26        dp[n]=1;
27        dp[n-1]=1;
28        for(int i=n-2;i>=0;i--){
29            dp[i]=dp[i+1]+dp[i+2];
30        }
31    return dp[0];
32
33    // let's try to make it space optimised
34    int next=1;
35    int next_next=1;
36    for(int i=n-2;i>=0;i--){
37        int ans=next+next_next;
38        next_next=next;
39        next =ans;
40    }
41    return next;
42    }
43};