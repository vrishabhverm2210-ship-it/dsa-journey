class Solution {
public:
void fun(int n,int open,int close,vector<string>&ans,string temp){
    // base case(when we have to return our answer)
    if(open == n && close == n){
        ans.push_back(temp);
        return;
    }
    // two conditon
    if(open<n){
        temp.push_back('(');
        fun(n,open+1,close,ans,temp);
        temp.pop_back();
    }
    if(close<open){
        temp.push_back(')');
        fun(n,open,close+1,ans,temp);
        temp.pop_back();
    }
    return;
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        fun(n,0,0,ans,temp);
        return ans;
    }
};