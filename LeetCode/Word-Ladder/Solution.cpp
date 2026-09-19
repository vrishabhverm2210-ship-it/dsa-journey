1class Solution {
2public:
3    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
4        int n=wordList.size();
5        unordered_map<string, int>mpp1;
6        for(int i=0;i<n;i++){
7            mpp1[wordList[i]]=1;
8           
9        } 
10         if(mpp1.find(beginWord) ==mpp1.end()){  // means nahi mila
11                mpp1[beginWord]=1;
12            }
13            if(mpp1.find(endWord)== mpp1.end()){ // key step
14                return 0;
15            }
16        // make queue
17        queue<pair<string,int>>q;
18        q.push({beginWord,1});
19        mpp1.erase(beginWord); // crucial step
20        while(!q.empty()){
21            pair<string,int>top=q.front();
22            q.pop();
23            string s=top.first;
24            int val=top.second;
25            if(s==endWord)return val;
26            // for neighbours
27            for(int i=0;i<s.size();i++){
28                char ch=s[i];
29                for(int j=97;j<=122;j++){
30                 if(ch==j)continue;
31                 s[i]=j;     // ek letter ke liye saare try hongeeeeeeee
32                 if(mpp1.find(s) != mpp1.end()){
33                  q.push({s,val+1});
34                  mpp1.erase(s);
35                 }
36                }
37                // same bana diya taaki agle letter ke comination check krne mai bigde na
38                s[i]=ch;
39            }
40        }
41return 0;
42    }
43};