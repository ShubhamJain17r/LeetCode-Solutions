class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int p;
        for (int i = 0; i<n; ++i){
            if (citations[n - 1 - i] >= i+1){
                p = i+1;
            }else{
                break;
            }
        }
        return p;
    }
};
