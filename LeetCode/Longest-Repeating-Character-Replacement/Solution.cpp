1class Solution {
2public:
3int fun1(   unordered_map<char,int>&mpp1){
4    int maxi=INT_MIN;
5    for(auto i:mpp1){
6        maxi=max(maxi,i.second);
7    }
8    return maxi;
9}
10    int characterReplacement(string s, int k) {
11        int n=s.size();
12        int low=0;
13        int high=0;
14        int res=-1;
15        unordered_map<char,int>mpp1;
16        for(high=0;high<n;high++){
17            mpp1[s[high]]++;
18            // wrong block
19            while((high-low+1)-fun1(mpp1)>k){
20               mpp1[s[low]]--;
21               if(mpp1[s[low]]==0)mpp1.erase(s[low]);
22               low++;
23            }
24
25int len=high-low+1;
26res=max(res,len);
27        }
28        return res;
29    }
30};