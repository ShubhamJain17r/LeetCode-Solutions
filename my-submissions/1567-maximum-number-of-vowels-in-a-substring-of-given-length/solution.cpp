class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
    }
    int maxVowels(string s, int k) {
        int vowelCount = 0;
        int maxVowelCount = 0;
        int n = s.length();
        int i = 0;
        for (; i < k; ++i) {
            if (isVowel(s[i])) vowelCount++;
        }

        maxVowelCount = vowelCount;

        for (i = 1 ; i <= n - k; ++i) {
            if (isVowel(s[i-1])) vowelCount--;
            if (isVowel(s[i + k - 1])) vowelCount++;
            maxVowelCount = max(vowelCount, maxVowelCount);
            if (maxVowelCount == k) return maxVowelCount; 
        }
        return maxVowelCount;
    }
};
