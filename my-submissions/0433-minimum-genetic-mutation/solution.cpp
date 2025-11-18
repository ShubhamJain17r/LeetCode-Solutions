class Solution {
public:
    bool oneChange(string a, string b) {
        int diff = 0;
        for (int i = 0; i < 8; ++i) {
            if (a[i] != b[i])
                diff++;
            if (diff > 1) 
                return false;
        }
        return true;
    }
    
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> visited;
        int steps = 0;
        queue<string> q;
        q.push(startGene);
        visited.insert(startGene);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string curr = q.front();
                q.pop();
                if (curr == endGene)
                    return steps;
                for (string s : bank) {
                    if (visited.find(s) == visited.end() && oneChange(curr, s)) {
                        visited.insert(s);
                        q.push(s);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
