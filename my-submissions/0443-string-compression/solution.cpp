class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int k = 0;
        int i = 0;
        while (i < n) {
            char curr = chars[i];
            int count = 0;
            while (i < n && chars[i] == curr) {
                i++;
                count++;
            }
            chars[k++] = curr;
            if (count > 1){
                string cntoStr = to_string(count);
                for (char c : cntoStr) {
                    chars[k++] = c;
                }
            }
        }
        return k;
    }
};
