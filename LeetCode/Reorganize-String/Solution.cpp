1class Solution {
2public:
3struct emp{
4    bool operator()(pair<int,char>&a,pair<int,char>&b){
5  if(a.first!=b.first){
6    return a.first<b.first;
7  }
8  return a.second<b.second;
9    }
10};
11    string reorganizeString(string s) {
12         string res="";
13         unordered_map<char,int>mpp1;
14         int n=s.size();
15         priority_queue<pair<int,char>,vector<pair<int,char>>,emp>pq;
16         for(int i=0;i<n;i++){
17            mpp1[s[i]]++;
18         }
19         for(auto i:mpp1){
20            pq.push({i.second,i.first});
21         }
22         int idx=0;
23         while(!pq.empty()){
24            pair<int,char>curr=pq.top();
25            int freq=curr.first;
26            char ch=curr.second;
27         
28            pq.pop();
29            if(idx==0|| res[idx-1]!=ch){
30            res.push_back(ch);
31            idx++;
32            freq--;
33            if(freq>=1){
34                pq.push({freq,ch});
35            }
36            continue;
37            }
38
39     else{
40         if(pq.empty())return "";
41         pair<int,char>temp=pq.top();
42         pq.pop();
43         res.push_back(temp.second);
44         temp.first--;
45         idx++;
46         if(temp.first>=1){
47        pq.push(temp);
48       
49         }
50     }
51     pq.push(curr);
52         }
53         return res;
54    }
55};