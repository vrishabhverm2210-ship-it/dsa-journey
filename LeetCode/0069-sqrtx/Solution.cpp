class Solution {
public:
    int mySqrt(int x) {
        int start=0;
        int end=x;
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            long long mid2= (long long)mid*mid;
            if(mid2==x){
                return mid;
            }
            else if(mid2 >x){
                end=mid-1;
            }
            else{
                ans=mid;
                start=mid+1;
            }
        }
        return ans;
    }
};