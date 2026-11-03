
class Codec {
private:
    void serializeHelper(TreeNode* root, string& result) {
        if (!root) {
            result += "X,";
            return;
        }

        result += to_string(root->val);
        result += ",";

        serializeHelper(root->left, result);
        serializeHelper(root->right, result);
    }

    TreeNode* deserializeHelper(const string& data, int& index) {
        if (index >= data.size())
            return nullptr;

        if (data[index] == 'X') {
            index += 2;
            return nullptr;
        }

        int value = 0;
        int sign = 1;

        if (data[index] == '-') {
            sign = -1;
            index++;
        }

        while (index < data.size() && data[index] != ',') {
            value = value * 10 + (data[index] - '0');
            index++;
        }

        index++; // Skip ','

        TreeNode* root = new TreeNode(value * sign);

        root->left = deserializeHelper(data, index);
        root->right = deserializeHelper(data, index);

        return root;
    }

public:
    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);

        if (!result.empty())
            result.pop_back();

        return result;
    }

    TreeNode* deserialize(string data) {
        int index = 0;
        return deserializeHelper(data, index);
    }
};

