class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        
        int idx = 0;            // curr sandwich
        queue<int> q(students.begin(), students.end());

        while (idx != n) {
            if (sandwiches[idx] == q.front()) {
                q.pop();
                idx++;
                continue;
            }
            int cnt = 0;
            while (cnt <= q.size() && q.front() != sandwiches[idx]) {
                int x = q.front();
                q.pop();
                q.push(x);
                cnt++;
            }
            if (cnt > q.size()) return q.size();
        }

        return 0;
    }
};
