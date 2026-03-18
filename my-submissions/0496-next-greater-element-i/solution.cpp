class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> nextGreater;
        nextGreater.reserve(nums2.size());

        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; --i) {

            while (!st.empty() && st.top() <= nums2[i])
                st.pop();

            nextGreater[nums2[i]] = st.empty() ? -1 : st.top();

            st.push(nums2[i]);
        }

        vector<int> ans;
        ans.reserve(nums1.size());

        for (int x : nums1)
            ans.push_back(nextGreater[x]);

        return ans;
    }
};
