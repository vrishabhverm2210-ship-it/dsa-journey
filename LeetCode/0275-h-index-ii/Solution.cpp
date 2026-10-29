class Solution {
public:
bool isPossible(vector<int>& citations,int mid){
    int count=0;
    for(int i=0;i<citations.size();i++){
        if(citations[i]>=mid){
            count++;
        }
    }
    if(count>=mid){return true;}
    return false;
}
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int low=0;
       int high=citations[n-1];
int res=1;
       while(low<=high){
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