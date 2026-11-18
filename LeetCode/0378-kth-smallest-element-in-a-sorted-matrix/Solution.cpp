class Solution {
public:
bool ispossible(vector<vector<int>>& matrix, int k,int mid){
    int n=matrix.size();
    int count=0;
    int row=n-1;
    int col=0;
    while(row>=0 && col<n){
        if(matrix[row][col]<=mid){
            count+=row+1;
            col++;
        }
        else{
row--;
        }
    }
    if(count>=k)return true;
    return false;
}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int res=-1;
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(matrix,k,mid)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};