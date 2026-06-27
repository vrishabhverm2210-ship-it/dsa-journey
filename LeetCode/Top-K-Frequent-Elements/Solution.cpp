1class Solution {
2    struct emp{
3        bool operator()(pair<int,int>&a , pair<int,int >&b){
4            if(a.first!=b.first){
5                return a.first>b.first;
6            }
7            return a.second>b.second;
8        }
9    };
10public:
11    vector<int> topKFrequent(vector<int>& nums, int k) {
12        int n=nums.size();
13        priority_queue<pair<int,int>,vector<pair<int,int>>, emp >pq;
14        unordered_map<int ,int>mpp;
15        //Insert in map
16        for(int i=0;i<n;i++){
17            mpp[nums[i]]++;
18        }
19        // Now map mai se fetch krow pair pair banake dalo heap mai
20        for(auto i:mpp){
21            int element=i.first;
22            int frequency=i.second;
23            pair<int,int>curr={frequency,element};
24            if(pq.size()<k){  // syntax problem aayi thi
25                pq.push(curr);
26                continue;
27            } 
28           pq.push(curr);
29            pq.pop();
30            
31        }
32
33        // vector banao for returning answer
34        vector<int>res;
35        while(!pq.empty()){
36            res.push_back(pq.top().second);
37            pq.pop();
38        }
39return res;
40    }
41};
42//SC=O(N)+O(K)
43//TC=O(N)+O(NLOGK)   K =>HEAP SIZE
44//N=> ARRAY SIZE AND WORST CASE MAI HASHMAP KA SIZE  