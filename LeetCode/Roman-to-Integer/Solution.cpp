1class Solution {
2public:
3    int romanToInt(string s) {
4      unordered_map<char, int> mpp1;
5
6mpp1['I'] = 1;
7mpp1['V'] = 5;
8mpp1['X'] = 10;
9mpp1['L'] = 50;
10mpp1['C'] = 100;
11mpp1['D'] = 500;
12mpp1['M'] = 1000;
13
14        int n=s.size();
15        int ans=0;
16        for(int i=0;i<n;i++){
17        if(i+1<n && mpp1[s[i]]<mpp1[s[i+1]]){
18         int temp=  mpp1[s[i+1]]-mpp1[s[i]];
19         ans+=temp;
20         i++;
21        }
22        else{
23        ans+=mpp1[s[i]];
24        }
25        }
26        return ans;
27    }
28};