class DSU {
public:
    vector<int> dsu;

    int find(int x) {
        if(dsu[x] == x) return x;
        return dsu[x] = find(dsu[x]);
    }

    void unite(int a, int b) {
        dsu[find(b)] = find(a);
    }

    void extend() {
        int n = dsu.size();
        dsu.push_back(n);
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, unordered_map<string, int>> mpNameEmail;
        unordered_map<string, DSU> mpNameDsu;
        
        for(auto& account : accounts) {
            int n = account.size();
            string name = account[0];
            for(int i = 1; i < n; i++) {
                string email = account[i];
                if(!mpNameEmail[name].contains(email)) {
                    mpNameEmail[name][email] = mpNameEmail[name].size();
                    mpNameDsu[name].extend();
                }
                if(i >= 2) {
                    int a = mpNameEmail[name][account[1]], b = mpNameEmail[name][email];
                    mpNameDsu[name].unite(a, b);
                }
            }
        }
        
        unordered_map<string, unordered_map<int, vector<string>>> result;
        for(auto& [name, mp] : mpNameEmail) {
            for(auto& [email, i] : mp) {
                int idx = mpNameDsu[name].find(i);
                result[name][idx].push_back(email);
            }
        }
        
        vector<vector<string>> ans;
        for(auto& [name, mp] : result) {
            for(auto& [idx, v] : mp) {
                ans.push_back({name});
                auto& now = ans.back();
                for(auto& email : v) now.push_back(email);
                sort(now.begin() + 1, now.end());
            }
        }
        return ans;
    }
};
