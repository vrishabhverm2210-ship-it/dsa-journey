1class Solution {
2public:
3struct emp{
4    bool operator()(pair<int,int>&a,pair<int,int>&b){
5        if(a.first!=b.first){
6            return a.first>b.first;
7        }
8        return a.second>b.second;
9    }
10};
11    vector<int> topKFrequent(vector<int>& nums, int k) {
12        unordered_map<int,int>mpp1;
13        for(int i=0;i<nums.size();i++){
14            mpp1[nums[i]]++;
15        }
16        // create the min heap
17        priority_queue<pair<int,int>,vector<pair<int,int>>,emp>pq;
18        for(auto i:mpp1){
19            pair<int,int>curr={i.second,i.first};
20            pq.push(curr);
21            if(pq.size()>k){
22                pq.pop();
23            }
24        }
25
26        vector<int> res;
27        while(!pq.empty()){
28            res.push_back(pq.top().second);
29            pq.pop();
30        }
31return res;
32    }
33};