class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        int idx = -1;

        for (string operation : operations){
            cout<<idx<<endl;
            if (operation == "C"){
                record.pop_back();
                idx--;
            }
            else if (operation == "D"){
                int val = record[idx] * 2;
                record.push_back(val);
                idx++;
            }
            else if (operation == "+"){
                int val = record[idx] + record[idx-1];
                record.push_back(val);
                idx++;
            }
            else{
                record.push_back(stoi(operation));
                idx++;
            }
        }
        int total = 0;
        for (int val : record){
            total += val;
        }
        return total;
    }
};
