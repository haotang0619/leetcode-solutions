class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes += 'R';
        pair<char, int> last = {'.', -1};
        for(int i = 0; i < dominoes.size(); i++) {
            if(dominoes[i] == '.') continue;
            if(dominoes[i] == 'L') {
                if(last.first == '.' || last.first == 'L') {
                    for(int j = last.second + 1; j < i; j++) dominoes[j] = 'L';
                } else {
                    double mid = ((double)last.second + i) / 2;
                    for(int j = last.second + 1; j < i; j++) {
                        if(j < mid) dominoes[j] = 'R';
                        else if(j > mid) dominoes[j] = 'L';
                    }
                }
                last = {'L', i};
            } else {
                if(last.first == 'R') {
                    for(int j = last.second + 1; j < i; j++) dominoes[j] = 'R';
                }
                last = {'R', i};
            }
        }
        dominoes.pop_back();
        return dominoes;
    }
};
