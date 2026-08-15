1class Solution {
2public:
3
4    struct emp {
5        bool operator()(pair<int,int>& a, pair<int,int>& b) {
6            if (a.first == b.first)
7                return a.second > b.second;
8
9            return a.first > b.first;
10        }
11    };
12
13    vector<int> getOrder(vector<vector<int>>& tasks) {
14
15        int n = tasks.size();
16
17        // {enqueueTime, processingTime, originalIndex}
18        vector<vector<int>> temp;
19
20        for (int i = 0; i < n; i++) {
21            temp.push_back({tasks[i][0], tasks[i][1], i});
22        }
23
24        // Sort according to enqueue time
25        sort(temp.begin(), temp.end());
26
27        // {processingTime, originalIndex}
28        priority_queue<pair<int,int>,
29                       vector<pair<int,int>>,
30                       emp> pq;
31
32        vector<int> res;
33
34        long long time = 0;
35        int i = 0;
36
37        while (i < n || !pq.empty()) {
38
39            // If no task is currently available,
40            // jump time to the next task's enqueue time
41            if (pq.empty() && time < temp[i][0]) {
42                time = temp[i][0];
43            }
44
45            // Add all tasks that have arrived
46            while (i < n && temp[i][0] <= time) {
47                pq.push({temp[i][1], temp[i][2]});
48                i++;
49            }
50
51            // Pick task according to:
52            // 1. smallest processing time
53            // 2. smallest original index
54            auto curr = pq.top();
55            pq.pop();
56
57            res.push_back(curr.second);
58
59            // Process the task
60            time += curr.first;
61        }
62
63        return res;
64    }
65};