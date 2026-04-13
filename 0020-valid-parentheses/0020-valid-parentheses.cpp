class Solution {
public:
    bool isValid(string s) {
        stack <char> stack;
        for (char c: s){
            if ( (c == '{') || (c == '[') || (c == '(')) {
                stack.push(c);
            }
            else {
                if (stack.empty()) return false;
                char cur = stack.top();
                if (((cur == '{') && (c != '}')) || 
                    ((cur == '[') && (c != ']')) || 
                    ((cur == '(') && (c != ')'))) return false;
                stack.pop();
            }
        }
        return stack.empty();
    }
};