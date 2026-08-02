// Asked GPT only for the combinations of large numbers
class Solution {
public:
    vector<bool> isPrime;
    vector<int> primes;

    void buildPrimes(int n) {
        int m = n / 2;
        isPrime.assign(m + 1, true);
        for(int i = 2; i <= m; i++) {
            if(!isPrime[i]) continue;
            primes.push_back(i);
            for(int j = i * i; j <= m; j += i) isPrime[j] = false;
        }
    }

    int exp(int n, int p) {
        int e = 0;
        while (n) n /= p, e += n;
        return e;
    }

    int maxK = 1e7;
    long long count(unordered_map<char, int>& mp) {
        long long ans = 1;
        int len = 0, k = primes.size();
        vector<int> pcnt(k);
        for(auto& [c, cnt] : mp) {
            for(int i = 0; i < k && primes[i] <= cnt; i++) {
                pcnt[i] -= exp(cnt, primes[i]);
            }
            len += cnt;
        }
        for(int i = 0; i < k && primes[i] <= len; i++) pcnt[i] += exp(len, primes[i]);
        for(int i = k - 1; i >= 0; i--) {
            double l = log((double)maxK / ans) / log(primes[i]);
            if(pcnt[i] >= l) return maxK;
            ans = ans * pow(primes[i], pcnt[i]);
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) {
        unordered_map<char, int> mp;
        for(auto& c : s) mp[c]++;
        char end = '\0';
        for(char c = 'a'; c <= 'z'; c++) {
            if(mp[c] % 2 == 1) end = c;
            mp[c] /= 2;
        }
        int n = s.size();
        buildPrimes(n);
        long long total = count(mp);
        if(total < k) return "";
        
        string ans;
        while(k > 1) {
            for(int i = 0; i < n / 2; i++) {
                for(char c = 'a'; c <= 'z'; c++) {
                    if(mp[c] == 0) continue;
                    mp[c]--;
                    long long cnt = count(mp);
                    if(k - cnt >= 1) k -= cnt, mp[c]++;
                    else {
                        ans += c;
                        break;
                    };
                } 
            }
        }
        for(char c = 'a'; c <= 'z'; c++) {
            for(int i = 0; i < mp[c]; i++) ans += c;
        }
        string rev = ans;
        reverse(rev.begin(), rev.end());
        if(end == '\0') return ans + rev;
        return ans + end + rev;
    }
};
