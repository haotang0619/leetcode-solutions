class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = speed.size();
        vector<int> groups;
        for(int i = 1; i < n; i++) {
            if(position[i] - position[i - 1] > distance) {
                groups.push_back(speed[i - 1]);
            }
        }
        groups.push_back(speed[n - 1]);
        stack<int> sk;
        for(auto& s : groups) {
            while(!sk.empty() && sk.top() > s) sk.pop();
            sk.push(s);
        }
        return sk.size();
    }
};
