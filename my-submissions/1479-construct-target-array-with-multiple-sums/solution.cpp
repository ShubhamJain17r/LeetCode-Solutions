class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long total = 0;
        priority_queue<int> pq;
        for (int val : target) {
            pq.push(val);
            total += val;
        }
        while (true) {
            int x = pq.top(); pq.pop();
            long long rest = total - x;
            if (rest == 1 || x == 1) return true;
            if (rest == 0 || x < rest) return false;

            long long prev = x % rest;
            if (prev == 0) return false;

            total = rest + prev;
            pq.push(prev);
        }
        return true;
    }
};
