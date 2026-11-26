class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int >a;
        vector<int>b;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)a.push_back(nums[i]);
            else{
                b.push_back(nums[i]);
            }
        }
         if(a.size()==0){
            for(int i=0;i<b.size();i++){
                b[i]=b[i]*b[i];
            }
            return b;
         }
         if(b.size()==0){
            for(int i=0;i<a.size();i++){
                a[i]=a[i]*a[i];
            }
            reverse(a.begin(),a.end());
            return a;
         }

         int n=a.size();
         int m=b.size();
         for(int i=0;i<n;i++){
            a[i]=a[i]*a[i];
         }
         reverse(a.begin(),a.end());
          // for positive
           for(int i=0;i<m;i++){
            b[i]=b[i]*b[i];
         }
         int i=0;
         int j=0;
         int idx=0;
         vector<int>res(n+m);
         while(i<n && j<m){
            if(a[i]<b[j]){
                res[idx++]=a[i++];
               
            }
            else{
                res[idx]=b[j];
                idx++;
                j++;
            }
         }
         while(i<n){
           res[idx]=a[i];
                idx++;
                i++; 
         }
         while(j<m){
             res[idx]=b[j];
                idx++;
                j++;
         }
         return res;
    }
};