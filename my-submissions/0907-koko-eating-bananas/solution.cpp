class Solution {
public:
// int getMaxValue(const vector<int>& piles) {
//     int maxValue = INT_MIN;
//     for (int pileSize : piles)
//         maxValue = max(maxValue, pileSize);
//     return maxValue;
// }

bool canFinishWithinHours(const vector<int>& piles, int bananasPerHour, int totalHours) {
    for (int pileSize : piles) {
        totalHours -= static_cast<int>(ceil(pileSize / static_cast<double>(bananasPerHour)));
        if (totalHours < 0)
            return false;
    }
    return true;
}

int minEatingSpeed(vector<int>& piles, int hoursAvailable) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());

    while (left <= right) {
        int midSpeed = left + ((right - left) >> 1);

        if (canFinishWithinHours(piles, midSpeed, hoursAvailable))
            right = midSpeed - 1;
        else
            left = midSpeed + 1;
    }
    return left;
}
};
