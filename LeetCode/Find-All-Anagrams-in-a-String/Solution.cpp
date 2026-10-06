1class Solution {
2public:
3    vector<int> findAnagrams(string s, string p) {
4           vector<int>res;
5           if(s.size() < p.size()) return {};
6           unordered_map<char,int>mpp2;
7           for(int i=0;i<p.size();i++){
8            mpp2[p[i]]++;
9           }
10           int low=0;
11           int high=0;
12           unordered_map<char,int>mpp1;
13           for(int i=0;i<p.size();i++){
14            mpp1[s[i]]++;
15            high++;
16           }
17           if(mpp1==mpp2){
18                 res.push_back(low);
19           }
20           for(high=high;high<s.size();high++){   
21           mpp1[s[high]]++;
22           mpp1[s[low]]--;
23           if(mpp1[s[low]]==0){
24            mpp1.erase(s[low]);
25           }
26           
27           low++;
28            if(mpp1==mpp2){
29                 res.push_back(low);
30           }
31    }
32    return res;
33    }
34};