1class Solution {
2public:
3bool isPossible(vector<int>& bloomDay, int m, int k,int mid){
4    int flower=0;
5    int bouquet=0;
6    for(int i=0;i<bloomDay.size();i++){
7        if(bloomDay[i]<=mid){
8            flower++;
9            if(flower==k){
10                bouquet++;
11                flower=0;
12            }
13        }
14        else{
15            flower=0;
16        }
17    }
18    if(bouquet>=m)return true;
19    return false;
20}
21    int minDays(vector<int>& bloomDay, int m, int k) {
22        if(bloomDay.size()< 1LL*m*k)return -1;
23        int res=-1;
24        int low=INT_MAX;
25        int high=INT_MIN;
26        for(int i=0;i<bloomDay.size();i++){
27            low=min(low,bloomDay[i]);    // no of days
28            high=max(high,bloomDay[i]);
29        }
30        while(high>=low){
31            int mid=low+(high-low)/2;
32            if(isPossible(bloomDay,m,k,mid)){
33                res=mid;
34                high=mid-1;
35            }
36            else{
37                low=mid+1;
38            }
39        }
40        return res;
41    }
42};