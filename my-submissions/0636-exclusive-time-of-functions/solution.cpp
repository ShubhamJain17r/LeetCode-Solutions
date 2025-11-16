class Solution {
public:
    tuple<int, bool, int> decodeLog(string log) {
        int i = 0;
        while (log[i] != ':') i++;
        int id = stoi(log.substr(0, i++));
        bool start = (log[i] == 's');
        while (log[i] != ':') i++;
        int time = stoi(log.substr(++i, log.length() - i));
        return make_tuple(id, start, time);
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> exTime(n, 0);
        stack<tuple<int, bool, int>> st;

        int last_TIME, last_ID;
        bool last_START;

        for (string log : logs) {
            auto LOG = decodeLog(log);
            auto [id, start, time] = LOG;

            if (start) {
                if (!st.empty()) {
                    exTime[last_ID] += (time - last_TIME);
                }
                st.push(LOG);
            }
            else {
                exTime[id] += (time - last_TIME + 1);
                st.pop();
            }
            if (!st.empty()){
                tie(last_ID, last_START, last_TIME) = st.top();
                if (!start){
                    last_TIME = time + 1;
                }
            }
        }
        return exTime;
    }
};
