1class Solution {
2public:
3    bool isAnagram(string s, string t) {
4        map<char,int>mpp1;
5        for(int i=0;i<s.size();i++){
6            mpp1[s[i]]++;
7        }
8        map<char,int>mpp2;
9         for(int i=0;i<t.size();i++){
10            mpp2[t[i]]++;
11        }
12        if(mpp1==mpp2){
13            return true;
14        }
15        
16        return false;
17    }
18};