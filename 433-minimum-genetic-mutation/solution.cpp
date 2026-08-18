class Solution {
public:
    vector<char> opt = {'A', 'C', 'G', 'T'};
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        unordered_map<string, int> dist;
        dist[startGene] = 0;
        queue<string> qu;
        qu.push(startGene);
        while(!qu.empty()) {
            auto gene = qu.front();
            qu.pop();
            int d = dist[gene];
            for(int i = 0; i < 8; i++) {
                char orig = gene[i];
                for(auto& c : opt) {
                    gene[i] = c;
                    if(dist.contains(gene)) continue;
                    if(!st.contains(gene)) continue;
                    if(gene == endGene) return d + 1;
                    qu.push(gene);
                    dist[gene] = d + 1;
                }
                gene[i] = orig;
            }
        }
        return -1;
    }
};
