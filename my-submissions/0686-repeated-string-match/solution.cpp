class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int k = ceil((double)b.length() / a.length());
        
        string t = "";
        for (int i = 0; i < k; ++i)
            t += a;

        if (t.find(b) != string::npos) return k;

        t += a;   // k + 1
        if (t.find(b) != string::npos) return k + 1;

        t += a;   // k + 2 (needed for border overlaps)
        if (t.find(b) != string::npos) return k + 2;

        return -1;
    }
};

