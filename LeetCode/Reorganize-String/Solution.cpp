1class Solution {
2public:
3struct emp{
4    bool operator()(pair<int,char>&a,pair<int,char>&b){
5        if(a.first != b.first){
6           return  a.first<b.first;
7        }
8          return  a.second<b.second;
9    }
10};
11    string reorganizeString(string s) {
12        unordered_map<char,int>mpp1;
13        for(int i=0;i<s.size();i++){
14            mpp1[s[i]]++;
15        }
16        //Inserted in map according to their frequencies
17        priority_queue<pair<int,char>,vector<pair<int ,char>>,emp>pq;
18        // make a pair of hashmap entries and push into heap
19        for(auto i:mpp1){
20            int freq=i.second;
21            int character=i.first;
22            pair<int,char>curr={freq,character};
23            pq.push(curr);
24        }
25        // now make res vector in which we have to store our final result
26        string res="";
27        int seat=0;
28        while(!pq.empty()){
29            pair<int,char>top=pq.top();
30            pq.pop();
31        if(res.size()==0 || res[seat-1] != top.second){
32             res.push_back(top.second);
33             top.first--;
34             seat++;
35             if(top.first>0){
36                pq.push(top);
37            }
38          }
39          else{  
40            if(pq.empty())return "";
41            pair<int,char>top1=pq.top();
42            pq.pop();
43            // if(res[seat-1] == top1.second)return "";  // yeh krne ki need nahi hai becuase it's very verrry much obvious that unique character hi ayega
44                 res.push_back(top1.second);
45                 top1.first--;
46                 seat++;
47                   if(top1.first>0){
48                pq.push(top1);
49            }
50            pq.push(top);
51     }
52        }
53        return res;
54    }
55};