class Solution {
public:
    bool findString(string doubled, string goal) {
        int n = doubled.length();
        int m = goal.length();
        if (m > n) return false;
        for ( int i = 0; i < n-m; i++) {
            int j=0;
            while (j < m && doubled[i+j] == goal[j]) {
                j++;
            }
            if (j == m) return true;
        }
        return false;
    }
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        string doubled = s+s;
        return findString(doubled, goal);
        // return doubled.find(goal) != string::npos;
    }
};