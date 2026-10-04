1class MinStack {
2    private:
3    stack<pair<int,int>>st;
4public:
5
6    MinStack() {
7        
8    }
9    
10    void push(int value) {
11        if(st.empty()){
12            st.push({value,value});
13        }
14        else {
15            int mini=min(value,st.top().second);
16            st.push({value,mini});
17
18        }
19    }
20    
21    void pop() {
22        st.pop();
23    }
24    
25    int top() {
26       return st.top().first;
27    }
28    
29    int getMin() {
30        return st.top().second;
31    }
32};
33
34/**
35 * Your MinStack object will be instantiated and called as such:
36 * MinStack* obj = new MinStack();
37 * obj->push(value);
38 * obj->pop();
39 * int param_3 = obj->top();
40 * int param_4 = obj->getMin();
41 */