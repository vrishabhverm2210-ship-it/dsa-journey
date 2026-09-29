1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4        vector<vector<string>>res;
5     unordered_map<string, vector<string>> mp;
6
7for(string s : strs) {
8    string temp = s;
9    sort(temp.begin(), temp.end());
10
11    mp[temp].push_back(s);
12}
13     for(auto i:mp){
14        res.push_back(i.second);
15     }
16     return res;
17    }
18};