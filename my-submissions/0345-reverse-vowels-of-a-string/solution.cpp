class Solution {
public:
    bool isVowel(char c){
        if (c >= 65 && c <= 90) c = c + 32;

        if (c >= 97 && c <= 122){
            if (c == 'a' || c=='e' || c=='i' || c=='o' || c=='u')return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int n = s.length();

        int st = 0, ed = n-1;

        while (st < ed){
            while (st < ed && !isVowel(s[st]))st++;
            while (st < ed && !isVowel(s[ed]))ed--;

            cout<<s[st]<<" "<<s[ed]<<endl;

            swap(s[st++], s[ed--]);
        }
        return s;
    }
};
