1class Solution {
2public:
3struct emp{
4    bool operator()(pair<int,char>&a,pair<int,char>&b){
5        if(a.first!=b.first){
6            return a.first<b.first;
7        }
8        return a.second<b.second;
9    }
10};
11    string reorganizeString(string s) {
12        priority_queue<pair<int,char>,vector<pair<int,char>>,emp>pq;
13        //bUILD Hashmap
14        unordered_map<char,int>mpp1;
15        for(int i=0;i<s.size();i++){
16            mpp1[s[i]]++;
17        }
18        // now insert all this in heap
19        for(auto i:mpp1){
20            int freq=i.second;
21            int character=i.first;
22            pair<int,char>curr={freq,character};
23            pq.push(curr);
24        }
25        // now we have to make result
26        
27        // vector<string>res;
28        string res="";
29         int seat=0;
30        while(!pq.empty()){ 
31           pair<int,char>p=pq.top();
32           pq.pop();
33            if(res.size()==0 || res[seat-1] != p.second){
34                res.push_back(p.second);
35                seat++;
36                p.first--;
37                if(p.first>0){
38                pq.push(p);
39                }
40            }
41            else{
42                if(pq.empty()){return "";}
43           pair<int,char>p1=pq.top();
44           pq.pop();
45        //    if(p1.second==res[seat-1]) return "";
46           res.push_back(p1.second);
47           seat++;
48           p1.first--;
49           if(p1.first>0){
50            pq.push(p1);
51           }
52           pq.push(p);
53            }
54        }
55           return res;
56            }
57
58};