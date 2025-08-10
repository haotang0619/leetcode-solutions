class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        map<int, vector<int>> mp;
        for(int i = 0; i < servers.size(); i++) pq.push({servers[i], i});
        vector<int> ans;
        for(int j = 0, t = 0; j < tasks.size(); j++) {
            if(t < j) t++;
            if(mp.contains(t)) {
                for(auto i : mp[t]) pq.push({servers[i], i});
                mp.erase(t);
            }
            if(pq.empty()) {
                t = (*mp.begin()).first;
                for(auto i : mp[t]) pq.push({servers[i], i});
                mp.erase(t);
            }
            auto [w, i] = pq.top();
            pq.pop();
            ans.push_back(i);
            mp[t + tasks[j]].push_back(i);
        }
        return ans;
    }
};
