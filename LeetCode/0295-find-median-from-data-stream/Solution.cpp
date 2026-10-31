
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
 class MedianFinder {
public:
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    MedianFinder() {}

    void addNum(int num) {
        // Insert into the appropriate heap
        if (maxi.empty() || num <= maxi.top()) {
            maxi.push(num);
        } else {
            mini.push(num);
        }

        // Balance the heaps
        if (maxi.size() > mini.size() + 1) {
            mini.push(maxi.top());
            maxi.pop();
        } 
        else if (mini.size() > maxi.size()) {
            maxi.push(mini.top());
            mini.pop();
        }
    }

    double findMedian() {
        if (maxi.size() > mini.size()) {
            return maxi.top();
        }

        return ((double)maxi.top() + mini.top()) / 2.0;
    }
};