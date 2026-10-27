class Solution {
public:
priority_queue<int>maxi;
priority_queue<int,vector<int>,greater<int>>mini;
unordered_map<int,int>mpp1;

    int leftSize = 0;
    int rightSize = 0;


void pruneMax(){

    while(!maxi.empty()&& mpp1[maxi.top()]>0){
        mpp1[maxi.top()]--;
        maxi.pop();
    }
}
    void pruneMin(){

        while(!mini.empty()&& mpp1[mini.top()]>0){
            mpp1[mini.top()]--;
            mini.pop();
        }
    }
    void balanceHeap(){

        if(leftSize>1+rightSize){
            mini.push(maxi.top());
            maxi.pop();
            leftSize--;
            rightSize++;
            pruneMax();
        }
        else if(leftSize < rightSize){
            maxi.push(mini.top());
            mini.pop();
            leftSize++;
            rightSize--;
            pruneMin();

        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
         vector<double> res;

         for(int i=0;i<k;i++){

            if(maxi.empty() || maxi.top()>=nums[i]){
                maxi.push(nums[i]);
                leftSize++;
            }
            else{
                mini.push(nums[i]);
                rightSize++;
            }
            balanceHeap();
         }

         // first median
         if(k&1){
            res.push_back(maxi.top());
         }
         else{
             res.push_back(((long long)maxi.top()+mini.top())/2.0);
         }


         // sliding start
         for(int i=k;i<nums.size();i++){

            int add=nums[i];
            int remove=nums[i-k];

             // mark stale
            mpp1[remove]++;


            // remove from valid count
            if(remove<=maxi.top()){
                leftSize--;
            }
            else{
                rightSize--;
            }
              // insert new element
            if(add <= maxi.top()){
                maxi.push(add);
                leftSize++;
            }
            else{
                mini.push(add);
                rightSize++;
            }

             // rebalance
            balanceHeap();

            // remove stale tops
            pruneMax();
            pruneMin();

            // median
            if(k&1)
                res.push_back(maxi.top());
            else
                res.push_back(((long long)maxi.top()+mini.top())/2.0);
         }
         return res;
    }
};