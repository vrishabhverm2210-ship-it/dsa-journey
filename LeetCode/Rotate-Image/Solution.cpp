1class Solution {
2public:
3    void rotate(vector<vector<int>>& matrix) {
4        int n=matrix.size();
5        // firsty do the transpose
6        for(int i=0;i<n;i++){
7            for(int j=i+1;j<n;j++){
8                 int temp=matrix[i][j];
9                matrix[i][j]=matrix[j][i];
10                matrix[j][i]=temp;
11            }
12        }
13      int i=0;
14      int j=n-1;
15        while(i<j){
16        for(int k=0;k<n;k++){
17            swap(matrix[k][i] ,matrix[k][j]);
18        }
19        i++;
20        j--;
21        }
22    }
23};