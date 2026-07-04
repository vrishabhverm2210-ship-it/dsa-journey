1class Solution {
2public:
3int maxi(vector<int>& piles){
4    int maxi1=INT_MIN;
5    for(int i=0;i<piles.size();i++){
6        maxi1=max(maxi1,piles[i]);
7    }
8    return maxi1;
9}
10    int minEatingSpeed(vector<int>& piles, int h) {
11       int res;  // FOR STORING THE FINAL RESULT
12        int low=1;
13        int high=maxi(piles);
14        while(low<=high){
15            int mid=low+(high-low)/2;  // use this middle no
16             long long speed=0;  // for every iteration it will start new
17            for(int i=0;i<piles.size();i++){
18                if(piles[i]%mid==0){
19                   speed+=piles[i]/mid;
20                } 
21                else{
22                    speed+=piles[i]/mid;
23                    speed+=1;
24                }
25            }
26
27            if(speed>h){   // means guard will come before completing bananas
28               low=mid+1;
29            }
30            else {
31              res=mid;
32              high=mid-1;  // search for less 
33            }
34            
35        }
36return res;
37    }
38};