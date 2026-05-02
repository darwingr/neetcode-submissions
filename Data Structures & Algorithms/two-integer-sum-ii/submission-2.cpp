// 2-pointers L & R, inc L if small, dec R if big
//  O(N)
//  O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int small = 0;
        int big = numbers.size()-1;
        int sum = numbers[small] + numbers[big];
        
        while (sum != target) {
            if (sum < target)
                small++;
            else
                big--;
            sum = numbers[small] + numbers[big];
        }
        return {small+1, big+1};
    }
};
