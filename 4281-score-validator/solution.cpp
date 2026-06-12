class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, counter = 0;
        for(auto s : events) {
            if(s == "W") counter++;
            else if(s == "WD" || s == "NB") score++;
            else score += stoi(s);
            if(counter >= 10) break;
        }
        return {score, counter};
    }
};
