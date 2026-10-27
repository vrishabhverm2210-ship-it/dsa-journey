class Solution {
public:
void fun(unordered_map<char, string>& mpp1 ,string digits,int idx,int n,vector<string>& res, string temp){
    // base case
    if(idx==n){
        res.push_back(temp);
        return;
    }
    string s=mpp1[digits[idx]];
    for(int i=0;i<s.size();i++){
        temp.push_back(s[i]);
        fun(mpp1,digits,idx+1,n,res,temp);
        temp.pop_back();
    }
    return;

}
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string temp="";
       unordered_map<char, string> mpp1;
int n=digits.size();
mpp1['2'] = "abc";
mpp1['3'] = "def";
mpp1['4'] = "ghi";
mpp1['5'] = "jkl";
mpp1['6'] = "mno";
mpp1['7'] = "pqrs";
mpp1['8'] = "tuv";
mpp1['9'] = "wxyz";
fun(mpp1,digits,0,n,res,temp);
return res;
    }
};