1class Solution {
2public:
3int fun(vector<int>&a){
4    int maxi=INT_MIN;
5    for(int i=0;i<255;i++){
6        maxi=max(a[i],maxi);
7
8    }
9    return maxi;
10}
11    int characterReplacement(string s, int k) {
12        vector<int>mpp1(256,0);
13         int n=s.size();
14         int low=0;
15         int high=0;
16         int maxi=INT_MIN;
17         for(high=0;high<n;high++){
18             mpp1[s[high]]++;
19             int maxcnt=fun(mpp1);
20             int len=high-low+1;
21             int diff=len-maxcnt;
22             while(diff>k){   // DIKAT VALA CASE
23             mpp1[s[low]]--;
24            //  if(mpp1[s[low]]==0)mpp1.erase(s[low]);  // No need to do this because it's a vector
25             low++;
26             maxcnt=fun(mpp1);
27             len=high-low+1;
28             diff=len-maxcnt;
29             }
30             len=high-low+1;
31             maxi=max(maxi,len);
32         }
33         return maxi;
34    }
35};