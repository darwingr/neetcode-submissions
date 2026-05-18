//  O(N) space
class KthLargest {
    const int k;
    priority_queue<int> smalls; // max heap
    priority_queue<int,vector<int>,greater<int>> bigs; // min_heap
public:
    // 
    KthLargest(int k, vector<int>& nums) :
        k(k)
    {
        for (int n : nums) {
            if (bigs.empty() || bigs.size() < k)
                bigs.push(n);
            else if (bigs.top() < n) {
                smalls.push(bigs.top());
                bigs.pop();
                bigs.push(n);
            }
            else
                smalls.push(n);
        }
    }
    
    //
    int add(int val) {
        if (bigs.empty() || bigs.size() < k)
            bigs.push(val);
        else if (bigs.top() < val) {
            smalls.push(bigs.top());
            bigs.pop();
            bigs.push(val);
        }
        else
            smalls.push(val);
        return bigs.top();
    }
};
