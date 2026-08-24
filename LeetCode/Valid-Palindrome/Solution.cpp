1class Solution {
2public:
3bool isValid(char ch){
4    if(ch>='A' && ch<='Z')return true;
5   else if(ch>='a' && ch<='z')return true;
6   else if(ch>='0' && ch<='9')return true;
7   else {
8    return false;
9   }
10}
11char to_lower(char ch){
12    return ch+=('a'-'A');
13}
14    bool isPalindrome(string s) {
15        int n=s.size();
16        string temp="";
17        for(int i=0;i<n;i++){
18            char ch=s[i];
19            if(isValid(ch)){
20               if(ch>='A' && ch<='Z'){
21                 temp.push_back(to_lower(ch));
22                 continue;
23            }
24                temp.push_back(ch);
25            }
26    }// till now our temp vector is ready
27    int i=0;
28    int j=temp.size()-1;
29    while(i<j){
30        if(temp[i]!=temp[j])return false;
31        i++;
32        j--;
33    }
34    return true;
35    }
36};