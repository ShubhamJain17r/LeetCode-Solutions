class Solution {
private:
    string toLower(string &para) {
        int i = 0;
        while (i < para.length()) {
            if (para[i] >= 'A' && para[i] <= 'Z') 
                para[i] += 32;
            else if (para[i] >= 'a' && para[i] <= 'z' || para[i] == ' ');
            else
                para[i] = ' ';
            i++;
        }
        return para;
    }
public:
    string mostCommonWord(string para, vector<string>& banned) {
        unordered_map<string, int> mapp;
        unordered_set<string> sett(banned.begin(), banned.end());

        // cout<<para<<endl<<endl;

        para = toLower(para);

        // cout<<para<<endl;

        int n = para.length();
        int i = 0;
        while (i < n){
            string word = "";
            while (i < n && para[i] == ' ') i++;
            while (i < n && para[i] != ' ') word.push_back(para[i++]);
            // cout<<word<<endl;
            if (word.length() && sett.count(word) == 0) mapp[word]++;
        }
        string ans = "";
        int maxFreq = 0;
        for (auto &p : mapp) {
            // cout<<p.first<<" "<<p.second<<endl;
            int freq = p.second;
            if(freq > maxFreq) {
                maxFreq = freq;
                ans = p.first;
            }
        }
        return ans;
    }
};
