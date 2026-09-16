1class Solution {
2public:
3    void rotate(vector<vector<int>>& matrix) {
4        int n=matrix.size();
5        for(int i=0;i<n;i++){
6            for(int j=i+1;j<n;j++){
7                int temp=matrix[i][j];
8                matrix[i][j]=matrix[j][i];
9                matrix[j][i]=temp;
10            }
11        }
12
13        // now 
14        int left=0;
15        int right=n-1;
16        while(left<right){
17        for(int i=0;i<n;i++){
18                int temp= matrix[i][left];
19                matrix[i][left]=matrix[i][right];
20                matrix[i][right]=temp;
21        }
22        left++;
23        right--;
24   }
25    }
26};