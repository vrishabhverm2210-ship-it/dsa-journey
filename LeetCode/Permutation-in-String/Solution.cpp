1class Solution {
2public:
3    bool checkInclusion(string s1, string s2) {
4        // let's make sliding window of s1.size()
5        int k=s1.size();
6        // store the frequency 
7        unordered_map<char,int>mpp1;
8        for(int i=0;i<s1.size();i++){
9            mpp1[s1[i]]++;
10        }
11        int low=0;
12         unordered_map<char,int>mpp2;
13        for(int high=0;high<s2.size();high++){
14           mpp2[s2[high]]++;
15           if(high - low + 1>k){
16            mpp2[s2[low]]--;
17            if(mpp2[s2[low]]==0)mpp2.erase(s2[low]);
18            low++;
19           }
20           if(high - low + 1==k){
21            if(mpp1==mpp2)return true;
22           }
23        }
24        return false;
25    }
26};