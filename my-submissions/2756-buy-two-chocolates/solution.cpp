class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int s = INT_MAX, sm = INT_MAX;
        for (int& v : prices) {
            if (v < s) {
                sm = s;
                s = v;
            }
            else if (v < sm) {
                sm = v;
            }
        }
        int expense = s + sm;
        if (expense <= money)
            return (money - expense);
        return money;
    }
};
