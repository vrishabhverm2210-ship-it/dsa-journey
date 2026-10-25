class Solution {
public:
    int count1(int a){
        int count=0;
        for(int i=0;i<32;i++){
            
            if(a&(1<<i)){
                count++;
            }
        }
        return count;
    }
    int calculateScore(int a, int b) {
        int s1=count1(a);
        int s2=count1(b);
        if(s1>=s2)return s1*s2;
        return s2/s1;
    }
};