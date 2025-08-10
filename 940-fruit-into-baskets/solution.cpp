class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int l = 0, r = 0; r < fruits.size(); r++) {
            if(mp.size() == 2 && !mp.contains(fruits[r])) {
                while(mp.size() == 2) {
                    mp[fruits[l]]--;
                    if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                    l++;
                }
            }
            mp[fruits[r]]++;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
