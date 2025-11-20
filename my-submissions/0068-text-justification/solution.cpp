class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLen = 0;

            // pick as many words as fit
            while (j < n && lineLen + words[j].size() + (j - i) <= maxWidth) {
                lineLen += words[j].size();
                j++;
            }

            int totalWords = j - i;
            int spacesNeeded = maxWidth - lineLen;

            // last line OR only 1 word → left justify
            if (j == n || totalWords == 1) {
                string line = words[i];
                for (int k = i + 1; k < j; k++)
                    line += " " + words[k];
                line += string(maxWidth - line.size(), ' ');
                result.push_back(line);
            } 
            else {
                // fully justify
                int gaps = totalWords - 1;
                int spaceEach = spacesNeeded / gaps;
                int extra = spacesNeeded % gaps;

                string line = "";
                for (int k = i; k < j - 1; k++) {
                    line += words[k];
                    line += string(spaceEach + (extra > 0 ? 1 : 0), ' ');
                    if (extra > 0) extra--;
                }
                line += words[j - 1];  // last word in the line
                result.push_back(line);
            }

            i = j;  // next line
        }

        return result;
    }
};

