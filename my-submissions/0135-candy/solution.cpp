class Solution {
public:
    int candy(vector<int>& rating) {
        // for (int val : rating) {
        //     cout<<val<<" ";
        // }
        // cout<<endl;
        int n = rating.size();
        vector<int> arr(n, 1);
        for (int i = 1; i < n; i++) {
            if (rating[i] > rating[i-1])
                arr[i] = arr[i-1] + 1;
        }
        // for (int val : arr) {
        //     cout<<val<<" ";
        // }
        // cout<<endl;
        for (int i = n - 2; i >= 0; i--) {
            if (rating[i] > rating[i+1] && arr[i] <= arr[i+1])
                arr[i] = arr[i+1] + 1;
        }
        int sum = 0;
        for (int val : arr) {
            sum += val;
            // cout<<val<<" ";
        }
        return sum;
    }
};
