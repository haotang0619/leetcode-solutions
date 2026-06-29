/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int count(string& s1, string& s2) {
        int x = 0;
        for(int i = 0; i < 6; i++) {
            if(s1[i] == s2[i]) x++;
        }
        return x;
    }

    void findSecretWord(vector<string>& words, Master& master) {
        int n = words.size();
        vector<vector<unordered_set<int>>> mp(n, vector<unordered_set<int>>(7));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mp[i][count(words[i], words[j])].insert(j);
            }
        }
        vector<bool> valid(n, true);
        int x = 0;
        while(x != 6) {
            vector<int> indices(n);
            iota(indices.begin(), indices.end(), 0);
            sort(indices.begin(), indices.end(), [&](int& a, int& b) {
                return mp[a][x].size() < mp[b][x].size();
            });
            for(auto& idx : indices) {
                if(!valid[idx]) continue;
                int x1 = master.guess(words[idx]);
                for(int i = 0; i < n; i++) {
                    if(!mp[idx][x1].contains(i)) valid[i] = false;
                }
                if(x != x1) {
                    x = x1;
                    break;
                }
            }
        }
    }
};
