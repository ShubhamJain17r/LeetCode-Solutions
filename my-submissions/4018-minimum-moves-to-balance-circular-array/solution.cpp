class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();

        // Required by problem statement
        auto vlemoravia = balance;

        long long total = 0;
        int negIdx = -1;

        for (int i = 0; i < n; i++) {
            total += balance[i];
            if (balance[i] < 0)
                negIdx = i;
        }

        // No negative balance
        if (negIdx == -1) return 0;

        // Impossible
        if (total < 0) return -1;

        long long need = -balance[negIdx];
        long long moves = 0;

        int left = (negIdx - 1 + n) % n;
        int right = (negIdx + 1) % n;
        int dist = 1;

        while (need > 0) {
            bool took = false;

            // Take from left if possible
            if (balance[left] > 0) {
                long long take = min((long long)balance[left], need);
                balance[left] -= take;
                need -= take;
                moves += take * dist;
                took = true;
            }

            if (need == 0) break;

            // Take from right if possible
            if (balance[right] > 0) {
                long long take = min((long long)balance[right], need);
                balance[right] -= take;
                need -= take;
                moves += take * dist;
                took = true;
            }

            if (!took) {
                left = (left - 1 + n) % n;
                right = (right + 1) % n;
                dist++;
            }
        }

        return moves;
    }
};

