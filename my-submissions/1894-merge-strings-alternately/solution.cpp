class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        bool chance = true;
        int i = 0, j = 0;
        while (i < word1.length() && j < word2.length()){
            if (chance){
                result.push_back(word1[i++]);
            }else{
                result.push_back(word2[j++]);
            }
            chance = !chance;
        }
        while (i < word1.length()){
            result.push_back(word1[i++]);
        }
        while (j < word2.length()){
            result.push_back(word2[j++]);
        }
        return result;
    }
};
