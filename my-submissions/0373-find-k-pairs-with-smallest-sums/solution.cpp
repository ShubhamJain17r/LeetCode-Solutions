class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;

        // min-heap storing {sum, i, j}
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > pq;

        // push first element of each row: (nums1[i], nums2[0])
        for (int i = 0; i < nums1.size() && i < k; i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while (k-- > 0 && !pq.empty()) {
            auto cur = pq.top(); 
            pq.pop();
            int i = cur[1], j = cur[2];

            result.push_back({nums1[i], nums2[j]});

            // push next element in the row: (i, j+1)
            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return result;
    }
};

