1class Solution {
2public:
3struct emp{
4    bool operator()(const pair<int,int>&a,const pair<int,int>&b){
5        if(a.first!=b.first){
6            return a.first<b.first;
7        }
8     return    a.second<b.second;
9    }
10};
11    int leastInterval(vector<char>& tasks, int n) {
12           // max heap
13           priority_queue<pair<int,int>,vector<pair<int,int>>,emp>pq;
14           unordered_map<char,int>mpp1;
15              unordered_map<char,int>free;
16           for(int i=0;i<tasks.size();i++){
17            mpp1[tasks[i]]++;
18            free[tasks[i]]=1;
19           }
20         
21           for(auto i:mpp1){
22            pq.push({i.second,i.first});
23           }
24     int seat=1;
25     while(!pq.empty()){
26        vector<pair<int,int>>pulled;
27        while(!pq.empty()){
28            pair<int,int>curr=pq.top();
29            pq.pop();
30            int freq=curr.first;
31            char ch=curr.second;
32          if(seat>=free[ch]){
33            if(freq>1){
34            pq.push({freq-1,ch});
35                free[ch]=seat+n+1;
36            }
37            break;    
38          }
39          else{
40            pulled.push_back(curr);
41          }
42        }
43        for(int i=0;i<pulled.size();i++){
44            pq.push(pulled[i]);
45        }
46        seat++;
47     }
48return seat-1;
49    }
50};