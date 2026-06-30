1class Solution {
2public:
3void fun(unordered_map<char, string>& mpp1 ,string digits,int idx,int n,vector<string>& res, string temp){
4    // base case
5    if(idx==n){
6        res.push_back(temp);
7        return;
8    }
9    string s=mpp1[digits[idx]];
10    for(int i=0;i<s.size();i++){
11        temp.push_back(s[i]);
12        fun(mpp1,digits,idx+1,n,res,temp);
13        temp.pop_back();
14    }
15    return;
16
17}
18    vector<string> letterCombinations(string digits) {
19        vector<string> res;
20        string temp="";
21       unordered_map<char, string> mpp1;
22int n=digits.size();
23mpp1['2'] = "abc";
24mpp1['3'] = "def";
25mpp1['4'] = "ghi";
26mpp1['5'] = "jkl";
27mpp1['6'] = "mno";
28mpp1['7'] = "pqrs";
29mpp1['8'] = "tuv";
30mpp1['9'] = "wxyz";
31fun(mpp1,digits,0,n,res,temp);
32return res;
33    }
34};