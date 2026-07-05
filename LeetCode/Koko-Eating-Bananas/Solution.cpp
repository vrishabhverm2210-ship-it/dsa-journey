1class Solution {
2public:
3int maxi(vector<int>& piles ){
4    int maxi1=INT_MIN;
5    for(int i=0;i<piles.size();i++){
6        maxi1=max(piles[i],maxi1);
7    }
8    return maxi1;
9}
10    int minEatingSpeed(vector<int>& piles, int h) {
11        int low=1;
12        int high=maxi(piles);
13         int res=-1;
14         while(low<=high){
15            int mid=low+(high-low)/2;
16            // find the speed
17            long long speed=0;
18            for(int i=0;i<piles.size();i++){
19                if(piles[i]%mid ==0){
20                    speed+=piles[i]/mid;
21                }
22                else{
23                    speed+=piles[i]/mid;
24                    speed++;
25                }
26            }
27            if(speed<=h){
28                res=mid;
29                high=mid-1;
30            }
31            else{
32                low=mid+1;
33            }
34
35         }
36         return res;
37    }
38};