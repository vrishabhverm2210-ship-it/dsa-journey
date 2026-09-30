1class Solution {
2public:
3    bool checkInclusion(string s1, string s2) {
4        int n=s1.size();
5        int m=s2.size();
6        if(m<n)return false;
7        unordered_map<char,int>mpp1;
8        for(int i=0;i<n;i++){
9            mpp1[s1[i]]++;
10        }
11  unordered_map<char,int>mpp2;
12   int low=0;
13        int high=0;
14        for(int i=0;i<n;i++){
15            mpp2[s2[i]]++;
16            high++;
17        }
18if(mpp1==mpp2)return true;
19        for(high=high;high<m;high++){
20         
21               mpp2[s2[high]]++;
22               mpp2[s2[low]]--;
23               if(mpp2[s2[low]]==0)mpp2.erase(s2[low]);
24               low++;
25               if(mpp1==mpp2)return true;
26        }
27        return false; 
28    }
29};