1class Solution {
2public:
3unordered_map<int,int>mpp1;
4int fun1(int i,int n){
5    //  Base cases
6    if(i==n)return 1;
7    if(i>n)return 0;
8    // check in map
9    if(mpp1.find(i) != mpp1.end()){
10        return mpp1[i];
11    }
12    // otherwise
13    int r1=fun1(i+1,n);
14    int r2=fun1(i+2,n);
15    int ans=r1+r2;
16    mpp1[i]=ans;
17    return ans;
18}
19    int climbStairs(int n) {
20        return fun1(0,n);
21    }
22};