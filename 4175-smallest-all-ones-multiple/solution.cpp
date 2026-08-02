class Solution {
public:
    vector<int> valid = {1, 3, 7, 9};
    
    int minAllOneMultiple(int k) {
        unordered_map<int, vector<int>> mul;
        for(auto& num : valid) {
            mul[num].resize(10);
            for(int i = 0; i <= 9; i++) mul[num][(num * i) % 10] = i;
        }
        if(!mul.contains(k % 10)) return -1;
        
        int ans = 0, now = 0, last = k % 10;
        while(true) {
            ans++;
            int target = (11 - (now % 10)) % 10;
            int next = k * mul[last][target];
            now = (now + next) / 10;
            
            string tmp = to_string(now);
            bool flag = true;
            for(auto& c : tmp) {
                if(c != '1') {
                    flag = false;
                    break;
                }
            }
            if(flag) break;
        }
        return ans + to_string(now).size();
    }
};
