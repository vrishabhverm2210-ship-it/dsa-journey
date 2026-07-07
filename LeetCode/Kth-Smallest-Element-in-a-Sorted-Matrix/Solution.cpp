1class Solution {
2public: 
3bool isPossible(vector<vector<int>>& matrix, int k,int mid){
4    int n=matrix.size();
5    int row=n-1;
6    int col=0;
7     int count=0;
8    while(row>=0 && col<n){
9        if(matrix[row][col]<=mid){
10            count+=row+1;  
11            col++;
12        }
13        else{
14            row--;
15        }
16    }
17    if(count>=k)return true;
18    return false;
19}
20    int kthSmallest(vector<vector<int>>& matrix, int k) {
21        int n=matrix.size();
22        int low=matrix[0][0];
23        int high=matrix[n-1][n-1];
24        int res=-1;
25        while(high>=low){
26            int mid=low+(high-low)/2;
27            if(isPossible(matrix,k,mid)){
28                res=mid;
29                high=mid-1;
30            }
31            else
32            {
33                low=mid+1;
34            }
35        }
36        return res;
37    }
38};