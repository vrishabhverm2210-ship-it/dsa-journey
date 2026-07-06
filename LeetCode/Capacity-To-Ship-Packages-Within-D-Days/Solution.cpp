1class Solution {
2public:
3bool isPossible(vector<int>& weights, int days,int guess){
4    int sum=0;
5    int count=1;
6    for(int i=0;i<weights.size();i++){
7        sum+=weights[i];
8        if(sum>guess){
9            count++;
10            sum=weights[i];
11            if(count>days)return false;
12        }
13    }
14  return true;
15}
16    int shipWithinDays(vector<int>& weights, int days) {
17        int res=-1;
18        int low=INT_MIN;
19        int high=0;
20        for(int i=0;i<weights.size();i++){
21            low=max(low,weights[i]);
22            high+=weights[i];
23        }
24        while(low<=high){
25            int mid=low+(high-low)/2;
26            if(isPossible(weights,days,mid)){
27                res=mid;
28                high=mid-1;
29            }
30            else{
31                low=mid+1;
32            }
33        }
34        return res;
35    }
36};