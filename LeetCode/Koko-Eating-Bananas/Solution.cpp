1class Solution {
2public:
3bool ispossible(vector<int>& piles, int h,int mid){
4    long long count=0;
5    for(int i=0;i<piles.size();i++){
6        if(piles[i]%mid==0){
7        count+=piles[i]/mid;
8        }
9        else{
10            count+=piles[i]/mid;
11            count++;  
12        }
13    }
14    if(count>h){
15        return false;
16    }
17    return true;
18}
19    int minEatingSpeed(vector<int>& piles, int h) {
20        int low=1;
21        int res=-1;
22        int maxi=INT_MIN;
23         for(int i=0;i<piles.size();i++){
24         maxi=max(maxi,piles[i]);
25    }
26        int high=maxi;
27        while(low<=high){
28            int mid=low+(high-low)/2;
29            if(ispossible(piles,h,mid)){
30                // store the answer and search for the more min
31                res=mid;
32                high=mid-1;
33            }
34            else{
35                low=mid+1;
36            }
37        }
38        return res;
39    }
40};