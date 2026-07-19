1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int buy=prices[0];
5        int maxi=0;
6        int profit=0;
7        int n=prices.size();
8        for(int i=1;i<n;i++){
9          profit=prices[i]-buy;
10          maxi=max(profit,maxi);
11          buy=min(buy,prices[i]);
12        }
13        return maxi;
14    }
15};