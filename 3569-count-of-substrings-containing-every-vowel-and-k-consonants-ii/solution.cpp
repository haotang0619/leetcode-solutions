class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        unordered_map<char, int> mp;
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
        long long ans = 0;
        int idx1 = 0, idx2 = 0, idx3 = -1, cnt = 0, n = word.length();
        bool flag = true;
        while(idx2 <= n && flag) {
            if(idx2 == n) flag = false;

            while(cnt < k && idx2 < n) {
                if(st.find(word[idx2]) != st.end()) mp[word[idx2]]++;
                else cnt++;
                idx2++;
            }
            
            int curr = 0;
            while(cnt == k) {
                while(mp.size() == 5) {
                    if(idx3 < idx1) {
                        curr++;
                        idx3 = idx1;
                    }
                    if(st.find(word[idx1]) == st.end()) break;
                    if(mp[word[idx1]] == 1) break;
                    mp[word[idx1]]--;
                    idx1++;
                }
                // cout << idx1 << " " << idx2 << " " << curr << endl;
                ans += curr;
                if(idx2 < n) {
                    if(st.find(word[idx2]) != st.end()) mp[word[idx2]]++;
                    else cnt++;
                    idx2++;
                } else break;
            }
            
            while(cnt > k) {
                if(st.find(word[idx1]) != st.end()) {
                    mp[word[idx1]]--;
                    if(mp[word[idx1]] == 0) mp.erase(word[idx1]);
                } else cnt--;
                idx1++;
            }
        }
        return ans;
    }
};
