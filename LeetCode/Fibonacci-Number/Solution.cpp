1class Solution {
2public: 
3unordered_map<int,int>mpp1;
4    int fib(int n) {
5          if(n==0 )return 0;
6          if(n==1)return 1;
7          //check in map
8          if(mpp1.find(n) != mpp1.end())return mpp1[n];
9          // otherwise store it for the future use , then return it
10          int t1=fib(n-1);
11          int t2=fib(n-2);
12          int ans=t1+t2;
13          mpp1[n]=ans;
14          return ans;
15
16    }
17};