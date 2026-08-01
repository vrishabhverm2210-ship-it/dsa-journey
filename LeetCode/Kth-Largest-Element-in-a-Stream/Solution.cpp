1class KthLargest {
2public:
3priority_queue<int,vector<int>,greater<int>>pq;
4int k;
5    KthLargest(int k, vector<int>& nums) {   // this is constructor
6        // in this I have to setup the k largest elements into the heap before the actual stream begins
7        this->k = k;
8        for(int i=0;i<nums.size();i++){
9            pq.push(nums[i]);
10            if(pq.size()>k){
11                pq.pop();
12            }
13        }
14    }
15    
16    int add(int val) {
17    // now i have to work for the stream
18   pq.push(val);
19  if(pq.size() > k)
20    pq.pop();
21   
22return pq.top();
23    }
24};
25
26/**
27 * Your KthLargest object will be instantiated and called as such:
28 * KthLargest* obj = new KthLargest(k, nums);
29 * int param_1 = obj->add(val);
30 */