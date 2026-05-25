class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        vector <int> stack;
        for (auto &it: asteroids) {
            bool destroyed = false;
            while(!stack.empty() && it < 0 && stack.back() > 0){
                if (stack.back() < -it) {
                    stack.pop_back();
                    continue;
                }
                else if (stack.back() == -it){
                    stack.pop_back();
                }
                //else if stack.back() > -it
                destroyed = true;
                break;
            }
            if (!destroyed) {
                stack.push_back(it);
            }
        }
        return stack;
    }
};