1class Solution {
2public:
3string fun1(string s){
4    string temp="";
5    for(int i=0;i<s.size();i++){
6        char ch=s[i];
7        if(ch>='A' && ch<='Z'){
8            temp.push_back(ch + 32);
9        }
10        else if((ch>='a' && ch<='z' )|| (ch>='0' && ch<='9')){
11            temp.push_back(ch);
12        }
13    }
14    return temp;
15}
16bool ispalindrome(string temp){
17    int i=0;
18    int j=temp.size()-1;
19    while(i<j){
20        if(temp[i++]!=temp[j--])return false;
21    }
22    return true;
23}
24
25    bool isPalindrome(string s) {
26        string temp=fun1(s);
27        // this temp is containing only lowercase character
28        return ispalindrome(temp);
29    }
30};