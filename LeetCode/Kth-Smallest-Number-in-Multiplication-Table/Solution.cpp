1class Solution {
2public:
3bool isPossible(int m, int n, int k ,int mid){
4    int row=m;
5    int col=1;
6    int count=0;
7    while(row>=1 && col<=n ){
8        if(row*col<=mid){
9         count+=row;
10         col++;
11        }
12        else{
13            row--;
14        }
15    }
16    if(count>=k)return true;
17    return false;
18}
19    int findKthNumber(int m, int n, int k) {
20        int low=1;
21        int high=m*n;
22        int res=-1;
23        while(high>=low){
24            int mid=low+(high-low)/2;
25            if(isPossible(m,n,k,mid)){
26                res=mid;
27                high=mid-1;
28            }
29            else
30            {
31                low=mid+1;
32            }
33        }
34        return res;
35    
36}
37};