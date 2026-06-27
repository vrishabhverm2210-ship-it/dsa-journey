1class Solution {
2public:
3//MAX HEAP COMPATOR
4struct emp{
5    bool operator()(pair<int,char>&a,pair<int,char>&b){
6        if(a.first!=b.first){
7            return a.first<b.first;
8        }
9        return a.second<b.second;
10    }
11};
12    string reorganizeString(string s) {
13        int n=s.size();
14        // max heap
15        priority_queue<pair<int,char>,vector<pair<int ,char>> ,emp>pq;
16        // unordered_map for storing frequencies
17        unordered_map<char,int>mpp1;
18        for(int i=0;i<n;i++){
19            mpp1[s[i]]++;
20        }
21        // now it;s time to push in pq
22        for(auto i:mpp1){
23            char ch=i.first;
24            int freq=i.second;
25            pair<int ,char>curr={freq,ch};
26            pq.push(curr);
27        }
28        string res="";
29        int idx=0;
30        while(!pq.empty()){
31             pair<int,char>top1=pq.top();
32             pq.pop();
33             if(idx==0 || res[idx-1]!=top1.second){
34                res.push_back(top1.second);
35                idx++;
36                top1.first--;
37                if(top1.first>0)pq.push({top1.first,top1.second});
38                continue;
39             }
40             else{
41                if(pq.empty())return "";
42                pair<int,char>top2=pq.top();
43                pq.pop();
44                res.push_back(top2.second);
45                idx++;
46                top2.first--;
47                if(top2.first>0)pq.push({top2.first,top2.second});
48              
49             }
50               pq.push(top1);
51             
52        }
53      return res;  
54    }
55};