class Solution {
public:
bool distPossible(vector<int> &position, int balls, int dist) {
    int last = position[0];
    int cnt = 1;
    for (int i = 1; i < position.size(); ++i) {
        if (position[i] - last >= dist) {
            cnt++;
            last = position[i];
            if (cnt == balls) return true;
        }
    }
    return false;
}

int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int l = 1, r = position.back() - position[0];
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (distPossible(position, m, mid)) l = mid + 1;
        else                                r = mid - 1;
    }
    return r;
}
};
