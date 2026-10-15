1class Solution {
2public:
3bool ispossible(vector<vector<int>>& matrix, int k,int mid){
4    int n=matrix.size();
5    int count=0;
6    int row=n-1;
7    int col=0;
8    while(row>=0 && col<n){
9        if(matrix[row][col]<=mid){
10            count+=row+1;
11            col++;
12        }
13        else{
14row--;
15        }
16    }
17    if(count>=k)return true;
18    return false;
19}
20    int kthSmallest(vector<vector<int>>& matrix, int k) {
21        int n=matrix.size();
22        int res=-1;
23        int low=matrix[0][0];
24        int high=matrix[n-1][n-1];
25        while(low<=high){
26            int mid=low+(high-low)/2;
27            if(ispossible(matrix,k,mid)){
28                res=mid;
29                high=mid-1;
30            }
31            else{
32                low=mid+1;
33            }
34        }
35        return res;
36    }
37};