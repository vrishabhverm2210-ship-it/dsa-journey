1class Solution {
2public:
3void fun1(string s, unordered_set<string>&set ,int idx,string &temp,vector<string>&res){
4    if(idx==s.size()){
5        res.push_back(temp);
6        return;
7    }
8    for(int j=idx;j<s.size();j++){
9         string word=s.substr(idx,j-idx+1);
10                     if(set.count(word)) {
11
12                // choose
13                if(temp.empty())
14                    temp += word;
15                else
16                    temp += " " + word;
17
18                // explore
19                fun1(s, set, j + 1, temp, res);
20
21                // backtrack
22                temp.erase(temp.size() - word.size());       // Delete everything from (jo number ayega subtract krke) to the end.
23                
24                // remove the space before word if it was added
25                if(!temp.empty() && temp.back() == ' ')// back() gives you the last character of the string.
26                    temp.pop_back();
27            }
28
29    }
30}
31    vector<string> wordBreak(string s, vector<string>& wordDict) {
32        unordered_set<string>set;
33        for(int i=0;i<wordDict.size();i++){
34            set.insert(wordDict[i]);
35        }
36
37        vector<string>res;
38        string temp="";
39        fun1(s,set,0,temp,res);
40        return res;
41    }
42};