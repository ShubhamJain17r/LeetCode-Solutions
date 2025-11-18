class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        tickets[k] = -tickets[k];
        queue<int> q;
        for (int val : tickets)
            q.push(val);
        int time = 0;
        while (!q.empty()) {
            int p = q.front();
            if (p < 0) {
                p++;
                if (p == 0) 
                    return ++time;
                
            }
            else {
                p--;
            }
            if (p != 0)
                q.push(p);
            time++;
            q.pop();
        }
        return time;
    }
};
