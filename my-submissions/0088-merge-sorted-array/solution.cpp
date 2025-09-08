class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        
        int i = m-1, j = n-1, k = m + n - 1;
        // i -> points to the largest element of nums1
        // j -> points to the largest element of nums2
        // k -> points to end of nums1 array
        
        while (i >= 0 && j >= 0){
            if (nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }else{
                nums1[k--] = nums2[j--];
            }
        }

        while (i >= 0){
            nums1[k--] = nums1[i--];
        }
        while (j >= 0){
            nums1[k--] = nums2[j--];
        }
    }
};
