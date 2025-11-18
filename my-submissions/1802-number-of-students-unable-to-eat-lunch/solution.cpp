class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> q;
        for (int i = 0; i < n; ++i) 
            q.push(i);
        int idx = 0;
        int lastMismatch = -1;
        while (idx < n) {
            int s = q.front();
            if (students[s] == sandwiches[idx]) {
                idx++;
                lastMismatch = -1;
            }
            else {
                if (lastMismatch == -1) 
                    lastMismatch = s;
                else if (lastMismatch == s)
                    break;
                q.push(s);
            }
            q.pop();
        }
        return q.size();
    }
};
