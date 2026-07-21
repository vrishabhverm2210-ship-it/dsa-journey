1class Solution {
2    private:
3    bool checkequal(int a[26],int b[26]){
4        for(int i=0;i<26;i++){
5            if(a[i]!=b[i]){
6                return 0;
7            }
8        }return 1;
9    }
10public:
11    bool checkInclusion(string s1, string s2) {
12        //character count array from s1
13   int count1[26]={0};
14   for(int i=0;i<s1.length();i++){
15   int index=s1[i]-'a';
16   count1[index]++;
17   }
18     // traverse s2 string in window of size s1 length
19    int i=0;
20    int windowsize=s1.length();
21    int count2[26]={0};
22    //running for first window
23    while(i<windowsize&&i<s2.length()){
24          int index=s2[i]-'a';
25          count2[index]++;
26          i++;
27    }
28    if (checkequal (count1,count2) )
29        return 1;
30
31    //aage window process krow
32    while(i<s2.length()){
33        char newchar=s2[i];
34        int index=newchar-'a';
35        count2[index]++;
36        char oldchar=s2[i-windowsize];
37          index=oldchar-'a';
38         count2[index]--;
39         i++;
40    
41     if (checkequal(count1,count2) )
42        return 1;
43
44    }
45  return 0;   
46}
47};