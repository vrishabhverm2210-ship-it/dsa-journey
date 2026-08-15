1class Solution {
2public:
3unordered_map<string , int>mpp1;
4bool fun1(string s1,string s2){
5    // base case
6  if(s1 == s2)
7            return true;
8    if(s1.size()<=1 || s2.size()<=1){
9        return false;
10    }
11    int n=s1.size();
12    string temp="";
13    temp.append(s1);
14    temp.append(" ");
15    temp.append(s2);
16    if(mpp1.find(temp)!=mpp1.end()){
17        return mpp1[temp];
18    }
19    bool flag=false; // initially we are asuming that they arn't scrambled string
20    for(int i=1;i<n;i++){
21      if (
22    (fun1(s1.substr(0, i), s2.substr(0, i)) &&
23     fun1(s1.substr(i, n-i), s2.substr(i, n-i)))
24    ||
25    (fun1(s1.substr(0, i), s2.substr(n-i, i)) &&
26     fun1(s1.substr(i, n-i), s2.substr(0, n-i)))
27) {
28    // mpp1[temp]=true;
29    flag = true;
30    break;
31}
32    }
33    return  mpp1[temp]=flag;
34}
35    bool isScramble(string s1, string s2) {
36        return fun1(s1,s2);
37    }
38};