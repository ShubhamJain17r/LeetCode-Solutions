class Solution {
public:
    bool makesquareHelper(vector<int>& matchsticks, int idx, vector<int> &square, int target) {
        if (idx < 0) {
            return true;
        }

        int s = matchsticks[idx];
        for (int i = 0; i < 4; ++i) {       // on which side we should add that matchstick
            if (square[i] + s > target) continue;

            bool skip = false;
            for (int j = 0; j < i && !skip; ++j)
                if (square[i] == square[j]) skip = true;

            if (skip) continue;

            square[i] = square[i] + s;
            if (makesquareHelper(matchsticks, idx - 1, square, target)) 
                return true;
            square[i] = square[i] - s;

            if (square[i] == 0) break;
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (n < 4) return false;

        int sum = 0;
        for (const int &val : matchsticks)
            sum += val;
        
        if (sum % 4 != 0) return false;
        int target = sum / 4;

        for (const int &val : matchsticks)
            if (val > target) return false;

        sort(matchsticks.begin(), matchsticks.end());

        vector<int> square(4, 0);
        return makesquareHelper(matchsticks, n - 1, square, target);
    }
};
