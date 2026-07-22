1class Solution {
2public:
3bool ispossible(vector<int>& weights, int days, int mid){
4    int count=1;
5    int sum=0;
6    for(int i=0;i<weights.size();i++){
7        sum+=weights[i];
8        if(sum>mid){
9            sum=weights[i];
10            count++;
11            if(count>days)return false;
12        }
13    }
14    return true;
15}
16    int shipWithinDays(vector<int>& weights, int days) {
17        int high=0;   // sum ho jayega
18         int low=INT_MIN; // MAXIMUM BECAUSE HUM EK BLOCK KO TOD KE NI DAAL SKTE MIN HUME HIGHEST VALI CAPACITY TOH CHAHIYE HI
19        for(int i=0; i<weights.size();i++){
20            high+=weights[i];
21            low=max(low,weights[i]);
22        }
23        
24        int res=-1; 
25         while(low<=high){
26            int mid=low+(high-low)/2;
27            if(ispossible(weights,days,mid)){
28                // store the answer and search for the more minimum 
29                res=mid;
30                high=mid-1;
31            }
32            else{
33                low=mid+1;
34            }
35        }
36        return res;
37
38
39    }
40};