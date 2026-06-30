1class Solution {
2public:
3    bool canConstruct(string ransomNote, string magazine) {
4        // make two maps and compare
5        unordered_map<char,int>need;
6        for(int i=0;i<ransomNote.size();i++){
7            need[ransomNote[i]]++;
8        }
9          unordered_map<char,int>have;
10        for(int i=0;i<magazine.size();i++){
11            have[magazine[i]]++;
12        }
13        // now for compare
14        for(auto i:need){
15            char ch=i.first;
16            int freq1=i.second;
17            int freq2=have[ch];
18
19            if(freq1>freq2)return false;
20        }
21return true;
22    }
23};