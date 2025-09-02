class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) return -1;
        int si = -1;
        for (int i = 0; i<haystack.length(); ++i){
            if (haystack[i] == needle[0]){
                si = i;
                int j = 0;
                while (i < haystack.length() && j < needle.length() && haystack[i] == needle[j]){
                    i++, j++;
                    // cout<<i<<" "<<j<<endl;
                }
                // cout<<"out"<<endl;
                if (j == needle.length())return si;
                i = si;
                si = -1;
            }
        }
        return si;
    }
};
