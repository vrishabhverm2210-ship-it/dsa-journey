1class Solution {
2public:
3    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
4                          int k) {
5        vector<int> res(n, 1e8);
6        vector<int> temp;
7        res[src] = 0;
8        for (int i = 0; i <= k; i++) {
9            temp = res;
10            for (int j = 0; j < flights.size(); j++) {
11                int src = flights[j][0];
12                int dest = flights[j][1];
13                int wt = flights[j][2];
14                if (res[src] != 1e8 && temp[dest] > wt + res[src]) {
15                    temp[dest] = wt + res[src];
16                }
17            }
18            res = temp;
19        }
20        if (res[dst] == 1e8)
21            return -1;
22        return res[dst];
23    }
24};