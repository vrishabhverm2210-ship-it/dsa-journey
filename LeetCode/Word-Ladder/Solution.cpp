1class Solution {
2public:
3    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
4        // construct map
5        unordered_map<string ,int>mpp1;
6        for(int i=0;i<wordList.size();i++){
7            mpp1[wordList[i]]++;
8        }
9        // it's given that beginWord may or may not be in the list , so if not then push it
10        if(mpp1.find(beginWord)==mpp1.end()){
11            mpp1[beginWord]=1;
12        }
13        // if there is no end word in the list
14        if(mpp1.find(endWord)==mpp1.end()){
15            return 0;
16        }
17
18        queue<pair<string,int>>q;
19        q.push({beginWord,1});
20        mpp1.erase(beginWord);
21
22        while(!q.empty()){
23            string s=q.front().first;
24            int val=q.front().second;
25            q.pop();
26            if(s==endWord)return val;
27            // explore the whole string
28           for(int i=0;i<s.size();i++){
29             char ch=s[i];
30             for(int j=97;j<123;j++){
31                if(ch==j)continue;
32                s[i]=j;   
33                if(mpp1.find(s)!=mpp1.end()){
34                  q.push({s,val+1});
35                  mpp1.erase(s);
36                }
37             }
38                 // same bana diya taaki agle letter ke comination check krne mai bigde na
39                s[i]=ch;
40          }
41        }
42        return 0;
43    }
44};