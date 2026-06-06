class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int m = queries.size(), n = dictionary.size(), s = queries[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int dist = 0;
                for(int k = 0; k < s; k++) {
                    if(queries[i][k] != dictionary[j][k]) dist++;
                    if(dist > 2) break;
                }
                if(dist <= 2) {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
