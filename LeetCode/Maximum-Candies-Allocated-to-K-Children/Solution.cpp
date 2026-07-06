1class Solution {
2public:
3long long maxi(vector<int>&candies  ){
4    int maxi1=INT_MIN;
5    for(int i=0;i<candies.size();i++){
6        maxi1=max(candies[i],maxi1);
7    }
8    return maxi1;
9}
10bool isPossible(vector<int>& candies, long long k,long long mid){
11    long long count=0;
12   // long long total=0;
13    for(int i=0;i<candies.size();i++){
14    //     total+=candies[i];
15    //     while(total>=mid){
16    //         count++;
17    //         total-=mid ;
18            
19    //     }
20    //     total=0;
21    // }
22    count+=candies[i]/mid;
23    if(count>=k)return true;
24    }
25    // if(count>=k){
26    //     return true;
27    // }
28    return false;
29}
30    int maximumCandies(vector<int>& candies, long long k) {
31        long long low=1;
32        long long  high=maxi(candies);
33        long long res=0;
34        while(high>=low){
35            long long mid=low+(high-low)/2;
36            if(isPossible(candies,k,mid)){
37                res=mid;
38                low=mid+1;
39            }
40            else{
41                high=mid-1;
42            }
43        }
44        return res;
45    }
46};