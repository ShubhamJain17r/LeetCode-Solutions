class Solution {
public:
    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int> p;

    //     for (int val : nums){
    //         p.push(val);
    //     }
    //     while (k > 1){
    //         p.pop();
    //         k--;
    //     }
    //     return p.top();
    // }
    int findKthLargest(vector<int>& nums, int k) {
        int count[20001] = {0};
        for (int val : nums)
            count[val + 10000]++;
        for (int i = 20000; i >= 0; --i){
            k -= count[i];
            if (k <= 0)
                return i - 10000;
        }
        return -1;
    }
};
