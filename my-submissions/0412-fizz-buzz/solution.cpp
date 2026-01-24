class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> vec(n);

        for (int i = 0; i < n; ++i) {
            int num = i + 1;
            if ((num % 3 == 0) && (num % 5 == 0)) {
                vec[i] = "FizzBuzz";
            }
            else if (num % 3 == 0) {
                vec[i] = "Fizz";
            }
            else if (num % 5 == 0) {
                vec[i] = "Buzz";
            }
            else {
                vec[i] = to_string(num);
            }
        }

        return vec;
    }
};
