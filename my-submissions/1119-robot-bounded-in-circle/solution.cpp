class Solution {
public:
    bool isRobotBounded(string instructions) {
        int direction = 0;
        int x = 0, y = 0;
        vector<vector<int>> dist = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };
        for (char c : instructions) {
            if (c == 'G') {
                x += dist[direction][0];
                y += dist[direction][1];
            }
            else if (c == 'L') {
                direction--;
                if (direction == -1) 
                    direction = 3;
            }
            else {
                direction++;
                if (direction == 4)
                    direction = 0;
            }
        }
        return direction != 0 || (x == 0 && y == 0);
    }
};
