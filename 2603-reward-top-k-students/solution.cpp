class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> pos(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> neg(negative_feedback.begin(), negative_feedback.end());
        unordered_map<int, int> points;
        for(int i = 0; i < report.size(); i++) {
            string s = report[i];
            int cnt = 0;
            string now = "";
            for(auto c : s) {
                if(c == ' ') {
                    if(pos.count(now) > 0) cnt += 3;
                    else if(neg.count(now)) cnt -= 1;
                    now = "";
                } else now += c;
            }
            if(pos.count(now) > 0) cnt += 3;
            else if(neg.count(now)) cnt -= 1;
            points[student_id[i]] = cnt;
        }
        sort(student_id.begin(), student_id.end(), [&points](int &a, int &b) {
            if(points[a] == points[b]) return a < b;
            return points[a] > points[b];
        });
        return vector<int>(student_id.begin(), student_id.begin() + k);
    }
};
