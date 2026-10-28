class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
           // Start from every column in the first row
        for (int col = 0; col < m; col++) {
            vector<int> temp;

            int i = 0, j = col;

            while (i < n && j < m) {
                temp.push_back(mat[i][j]);
                i++;
                j++;
            }

            sort(temp.begin(), temp.end());

            i = 0;
            j = col;

            for (int x : temp) {
                mat[i][j] = x;
                i++;
                j++;
            }
        }
for(int row=0;row<n;row++){
  vector<int> temp;

  int i=row;
  int j=0;

  while(i<n && j<m){
    temp.push_back(mat[i][j]);
    i++;
    j++;
  }
  sort(temp.begin(),temp.end());
  i=row;
  j=0;
  for(auto x:temp){
      mat[i][j]=x;
      i++;
      j++;
  }
}
return mat;
    }
};