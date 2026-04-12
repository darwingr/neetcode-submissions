// 2 Heaps
class MedianFinder {
    priority_queue<int> smalls; // max_heap
    priority_queue<int, vector<int>, greater<int>> bigs; // min_heap
public:
    MedianFinder() {
        
    }
    
    // O(log N)
    void addNum(int num) {
        //  1. add
        if (smalls.empty() || num <= smalls.top())
            smalls.push(num);
        else
            bigs.push(num);
        
        //  2. balance
        if (smalls.size() < bigs.size()) {
            smalls.push(bigs.top());
            bigs.pop();
        } else if (smalls.size() - 1 > bigs.size()) {
            bigs.push(smalls.top());
            smalls.pop();
        }
    }
    // O(1)
    // O(N)
    double findMedian() {
        if (smalls.size() == bigs.size())
            return (smalls.top() + bigs.top()) / 2.0;
        
        return smalls.top();
    }
};
