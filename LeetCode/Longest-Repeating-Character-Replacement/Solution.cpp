1class Solution {
2public:
3int maxcnt(  unordered_map<char,int>&mpp1){
4    int cnt=0;
5    for(auto i:mpp1){
6        cnt=max(cnt,i.second);
7    }
8    return cnt;
9}
10    int characterReplacement(string s, int k) {
11        int n=s.size();
12        unordered_map<char,int>mpp1;
13        int low=0;
14        int high=0;
15        int res=0;
16        for(high=0;high<n;high++){
17            mpp1[s[high]]++;
18            while(high-low+1-maxcnt(mpp1)>k){
19                mpp1[s[low]]--;
20                if(mpp1[s[low]]==0)mpp1.erase(s[low]);
21                low++;
22            }
23            res=max(res,high-low+1);
24        }
25        return res;
26    }
27};