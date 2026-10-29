class Solution {
public:
    string removeDuplicates(string s) {
        // implement stack
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(st.size()==0){
                st.push(ch);
                continue;
            }
            if(st.top() == s[i]){
                // popping cdn
                st.pop();  // automatically it will remove the duplicate 1 element(mentioned in the question itself)
                continue;
            }
            if(st.top() != s[i]){
                st.push(ch);
                continue;
            }
        }
        // we have to extract answer from stack using while loop
        string res="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        // at last revrerse our answer variable
        reverse(res.begin(),res.end());
        return res;
    }
};