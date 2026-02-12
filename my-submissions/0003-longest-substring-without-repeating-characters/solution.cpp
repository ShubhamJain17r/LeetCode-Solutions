class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> arr(256, -1);
        int maxLen = 0;
        int left = 0;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            // std::cout<<arr[c]<<' ';
            if (arr[c] == -1 || arr[c] < left) {
                maxLen = max(maxLen, i - left + 1);
            }
            else {
                left = arr[c] + 1; 
            }
            arr[c] = i;
        }
        return maxLen;
    }
};
