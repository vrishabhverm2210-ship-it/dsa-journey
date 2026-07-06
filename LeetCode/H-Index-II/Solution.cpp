1class Solution {
2public:
3int maxi(vector<int>& citations){
4    int maxi1=INT_MIN;
5    for(int i=0;i<citations.size();i++){
6        maxi1=max(maxi1,citations[i]);
7    }
8    return maxi1;
9}
10bool isPossible(vector<int>& citations,int mid){
11    int count=0;
12    for(int i=0;i<citations.size();i++){
13     if(citations[i]>=mid){
14        count++;
15     }
16    }
17    if(count>=mid)return true;
18    return false;
19}
20    int hIndex(vector<int>& citations) {
21        int low=0;
22        int high=maxi(citations);
23        int res=-1;
24        while(high>=low){
25            int mid=low+(high-low)/2;
26            if(isPossible(citations,mid)){
27                res=mid;
28                low=mid+1;
29            }
30            else{
31                high=mid-1;
32            }
33        }
34        return res;
35    }
36};