class Solution {
public:
int fun1(string curr,string prefix){
    int len=0;
    for(int i=0;i<min(curr.size(),prefix.size());i++)
{
                if(curr[i]==prefix[i])len++;
                else{
                    break;
                }
}
return len;
}
    string longestCommonPrefix(vector<string>& strs) {
        string prefix=strs[0];
        int len=INT_MAX;
        for(int i=1;i<strs.size();i++){
           int temp= fun1(strs[i],prefix);
            len=min(temp,len);
        }
        return prefix.substr(0,len);
    }
};