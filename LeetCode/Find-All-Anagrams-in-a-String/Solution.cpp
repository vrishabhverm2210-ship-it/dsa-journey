1class Solution {
2public:
3    vector<int> findAnagrams(string s, string p) {
4        // store the all characters of p in map
5        int k=p.size();
6        unordered_map<char,int>mpp1;
7        for(int i=0;i<k;i++){
8            mpp1[p[i]]++;
9        }
10        vector<int>res;
11        unordered_map<char,int>mpp2;
12        int low=0;
13         for(int i=0;i<k-1;i++){
14            mpp2[s[i]]++;
15         }
16        for(int high=k-1;high<s.size();high++){
17             mpp2[s[high]]++;
18            if(mpp1==mpp2){
19                res.push_back(low);
20            }
21            // low ko aage badhao
22            mpp2[s[low]]--;
23            if(mpp2[s[low]]==0)mpp2.erase(s[low]);
24            low++;
25            
26        }
27        return res;
28            }
29};