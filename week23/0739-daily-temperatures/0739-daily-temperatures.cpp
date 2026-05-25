class Solution {
public:
    vector <int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector <int> result(n,0);
        stack<int> stack;
        for (int i =0 ; i < n; i++) {
            while(!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
                int idx = stack.top();
                stack.pop();
                result[idx] = i - idx;
            }
            stack.push(i);
        }
        return result;
    }
};