class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size();
        // we are going to make stack 
        stack<int>st;
       
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(st.top()==s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        // now extract the answer from the stack and push it into the res vector
         string res="";
         while(!st.empty()){
            res.push_back(st.top());
            st.pop();
         }
        reverse(res.begin(),res.end());
        return res;
    }
};