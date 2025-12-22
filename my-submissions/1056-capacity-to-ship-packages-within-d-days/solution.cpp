#include<bits/stdc++.h>
class Solution {
public:
bool canFinishWithinDays(vector<int>& weights, int capacity, int days) {
    long long sum = 0;
    int daysTaken = 1;
    for (const int &weight : weights) {
        sum += weight;
        if (sum > capacity) {
            daysTaken++;
            sum = weight;
        }
    }
    return daysTaken <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int left = *max_element(weights.begin(), weights.end());
    int right = left * 2;

    while (!canFinishWithinDays(weights, right, days)) right *= 2;

    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (canFinishWithinDays(weights, mid, days)) right = mid - 1;
        else                                         left = mid + 1;
    }
    return left;
}
};
