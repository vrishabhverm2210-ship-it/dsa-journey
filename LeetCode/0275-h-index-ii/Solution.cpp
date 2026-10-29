class Solution {
public:
int maxi(vector<int>& citations){
    int maxi1=INT_MIN;
    for(int i=0;i<citations.size();i++){
        maxi1=max(maxi1,citations[i]);
    }
    return maxi1;
}
bool isPossible(vector<int>& citations,int mid){
    int count=0;
    for(int i=0;i<citations.size();i++){
     if(citations[i]>=mid){
        count++;
     }
    }
    if(count>=mid)return true;
    return false;
}
    int hIndex(vector<int>& citations) {
        int low=0;
        int high=maxi(citations);
        int res=-1;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(isPossible(citations,mid)){
                res=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return res;
    }
};