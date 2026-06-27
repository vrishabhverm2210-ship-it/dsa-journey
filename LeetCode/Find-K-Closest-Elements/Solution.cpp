1class Solution {
2public:
3int distance(int point, int x){
4    return abs(x - point); 
5   
6}
7struct emp{
8    bool operator()(pair<int,int>&a,pair<int,int>&b){
9        if(a.first!=b.first){
10            return a.first<b.first;
11        }
12        return a.second<b.second;
13    }
14};
15    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
16          priority_queue<pair<int ,int >,vector<pair<int, int >>,emp>pq;
17        for(int i=0;i<arr.size();i++){
18          int dist=distance(arr[i],x);
19          int value=arr[i];
20          pair<int ,int> curr={dist,value};
21    if(pq.size()<k){
22        pq.push(curr);
23        continue;
24    }
25    pq.push(curr);
26    pq.pop();
27          }
28       // now we have to return the answer
29           vector<int>res;
30           while(!pq.empty()){
31                 res.push_back(pq.top().second);
32                 pq.pop();
33           }
34//    reverse(res.begin(), res.end());
35sort(res.begin(),res.end());
36     return res;
37    }
38};