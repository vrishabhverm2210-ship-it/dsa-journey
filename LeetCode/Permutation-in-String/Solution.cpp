1class Solution {
2public:
3    bool checkInclusion(string s1, string s2) {
4               unordered_map<int,int> mp1;
5       unordered_map<int,int> mp2;
6       int k=s1.size();
7    for(int i=0;i<s1.size();i++){
8        mp1[s1[i]]++;
9    }
10 int low=0;
11 for(int high=0;high<s2.size();high++){
12    mp2[s2[high]]++;
13    while(high-low+1>k){
14        mp2[s2[low]]--;
15        if(mp2[s2[low]]==0){
16            mp2.erase(s2[low]);
17        }
18        low++;
19    }
20if(mp1==mp2){
21    return true;
22}
23 }
24 return false;
25    }
26};