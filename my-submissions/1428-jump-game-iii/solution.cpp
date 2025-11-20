class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<int> visited(n, false);
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int idx = q.front(); q.pop();
            if (arr[idx] == 0)
                return true;
            int left = idx - arr[idx];
            int right = idx + arr[idx];
            if (left >= 0 && !visited[left]) {
                q.push(left);
                visited[left] = true;
            }
            if (right < n && !visited[right]) {
                q.push(right);
                visited[right] = true;
            }
        }
        return false;        
    }
};
