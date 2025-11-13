class Solution {
public:
    void dfs(
        vector<vector<int>>& employeeTree, vector<int>& informTime, int& currTime, int& maxTime, int employee
    ) {
        if (informTime[employee] == 0) {
            maxTime = max(maxTime, currTime);
        }
        currTime += informTime[employee];
        for (int subordinate : employeeTree[employee]) {
            dfs(employeeTree, informTime, currTime, maxTime, subordinate);
        }
        currTime -= informTime[employee];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> employeeTree(n);
        for (int i = 0; i< n; ++i) {
            if (manager[i] != -1)
                employeeTree[manager[i]].push_back(i);
        }
        int currTime = 0;
        int maxTime = 0;
        dfs(employeeTree, informTime, currTime, maxTime, headID);
        return maxTime;
    }
};
