class Solution {
public:
    int getInt(int x, int y, int z) {
        return x * 100 + y * 10 + z;
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> st;
        for(int i = 0; i < digits.size(); i++) {
            for(int j = i + 1; j < digits.size(); j++) {
                for(int k = j + 1; k < digits.size(); k++) {
                    vector<int> nums = {
                        getInt(digits[i], digits[j], digits[k]),
                        getInt(digits[i], digits[k], digits[j]),
                        getInt(digits[j], digits[i], digits[k]),
                        getInt(digits[j], digits[k], digits[i]),
                        getInt(digits[k], digits[i], digits[j]),
                        getInt(digits[k], digits[j], digits[i])
                    };
                    for(auto num : nums) {
                        if(num >= 100 && num % 2 == 0) st.insert(num);
                    }
                }
            }
        }
        return vector<int>(st.begin(), st.end());
    }
};
