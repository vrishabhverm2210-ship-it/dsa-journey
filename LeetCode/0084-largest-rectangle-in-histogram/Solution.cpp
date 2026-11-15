class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
         int n = height.size();
    stack<int> s ;
    
    // FOR RIGHT SMALLEST ELEMENT
    vector<int> right(n) ;
   for (int i=n-1;i>=0;i--){
    while (s.size() !=0 && height[s.top()] >= height[i] ){
        s.pop();
    }
    if (s.empty()){
      right[i] = n;
     }else {
     right[i] = s.top();
     }
     s.push(i);
   }

    // TO REUSE STACK
    while (!s.empty()){
        s.pop();
    }


   // FOR LEFT SMALLEST ELEMENT 
   vector <int> left (n);
   for (int i=0;i<n;i++){
    while (s.size() !=0 && height[s.top()] >= height[i] ){
        s.pop();
    }
    if (s.empty()){
      left[i] = -1;
     }else {
     left[i] = s.top();
     }
     s.push(i);
   }

    int ans =0;
    for(int k=0;k<n;k++){
        int width = right[k] - left[k] -1;
        int CURRans = height[k] * width ;
        ans =max (CURRans, ans);
}    
      return ans ; 
    }
       
    
};