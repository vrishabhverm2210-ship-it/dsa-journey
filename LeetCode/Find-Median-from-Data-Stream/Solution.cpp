1class MedianFinder {
2public:
3    priority_queue<int> maxi; // Max heap (left half)
4    priority_queue<int, vector<int>, greater<int>> mini; // Min heap (right half)
5
6    MedianFinder() {
7    }
8
9    void addNum(int num) {
10
11        // Step 1: Insert into the appropriate heap
12        if (maxi.empty() || num <= maxi.top()) {
13            maxi.push(num);
14        } else {
15            mini.push(num);
16        }
17
18        // Step 2: Balance the heaps
19        if (maxi.size() > mini.size() + 1) {
20            mini.push(maxi.top());
21            maxi.pop();
22        } else if (mini.size() > maxi.size()) {
23            maxi.push(mini.top());
24            mini.pop();
25        }
26    }
27
28    double findMedian() {
29
30        if (maxi.size() > mini.size()) {
31            return maxi.top();
32        }
33
34        return (maxi.top() + mini.top()) / 2.0;
35    }
36};
37
38/**
39 * Your MedianFinder object will be instantiated and called as such:
40 * MedianFinder* obj = new MedianFinder();
41 * obj->addNum(num);
42 * double param_2 = obj->findMedian();
43 */