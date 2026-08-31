1class MinStack {
2public:
3stack<int>st;
4stack<int>minstack;
5    MinStack() {
6        // there is no need to store anything here
7    }
8    
9    void push(int value) {
10       st.push(value);
11       if(minstack.empty() || minstack.top()>=value){
12        minstack.push(value);
13       }
14    }
15    
16    void pop() {
17        int top=st.top();
18        st.pop();
19        if(top==minstack.top()){
20            minstack.pop();
21        }
22    }
23    
24    int top() {
25        return st.top();
26    }
27    
28    int getMin() {
29        return minstack.top();
30    }
31};
32
33/**
34 * Your MinStack object will be instantiated and called as such:
35 * MinStack* obj = new MinStack();
36 * obj->push(value);
37 * obj->pop();
38 * int param_3 = obj->top();
39 * int param_4 = obj->getMin();
40 */