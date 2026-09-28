1class Solution {
2public:
3bool ispossible(vector<int>& piles, int h,int  mid){
4    long long count=0;
5    for(int i=0;i<piles.size();i++){
6        if(piles[i]%mid==0){
7        count+=piles[i]/mid;
8        }
9        else{
10            count+=piles[i]/mid;
11            count+=1;
12        }
13    }
14    if(count<=h)return true;
15    return false;
16}
17    int minEatingSpeed(vector<int>& piles, int h) {
18        int low=1;
19        int high=INT_MIN;
20        for(int i=0;i<piles.size();i++){
21            high=max(high,piles[i]);
22        }
23        int res=-1;
24        while(low<=high){
25            int mid=low+(high-low)/2;
26            if(ispossible(piles,h,mid)){
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