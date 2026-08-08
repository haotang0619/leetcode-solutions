class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        set<int> on;
        for(auto& b : bulbs) {
            if(on.contains(b)) on.erase(b);
            else on.insert(b);
        }
        return vector<int>(on.begin(), on.end());
    }
};
