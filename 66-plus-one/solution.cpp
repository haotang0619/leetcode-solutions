class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for(int i = 0; i < digits.size() && carry > 0; i++) {
            digits[i] += carry;
            if(digits[i] == 10) {
                digits[i] = 0;
                carry = 1;
            } else carry = 0;
        }
        if(carry == 1) digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
