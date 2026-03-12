class Solution {
public:
    vector<string> split(const string &path) {
        int n = path.length();
        vector<string> splitted;
        for (int i = 0; i < n; ++i) {
            while (i < n && path[i] == '/') i++;
            string dir;
            while (i < n && path[i] != '/') {
                dir += path[i];
                i++;
            }
            if (dir.length())
                splitted.push_back(std :: move(dir));
        }
        return splitted;
    }
    string simplifyPath(string path) {
        stack<string> st;
        vector<string> fileSys = split(path);

        // for (const string &dir : fileSys) {
        //     cout << dir << endl;
        // }

        for (const string &dir : fileSys) {
            if (dir == "..") {
                if (!st.empty()) st.pop();
            }
            else if (dir == ".") {}
            else {
                st.push(dir);
            }
        }

        stack<string> stN;
        while (!st.empty()) {
            // cout << st.top() << " ";
            stN.push(st.top());
            st.pop();

        }

        string ans;
        while (!stN.empty()) {
            ans.push_back('/');
            ans += stN.top();
            stN.pop();
        }
        
        return ans.empty() ? "/" : ans;
    }
};
