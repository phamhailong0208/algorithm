class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0, maxLen = 0;
        
        for (int right = 0; right < s.size(); right++) {
            while (seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
    // string subString(string startString, int index, int lengthofSubString) {
    //     string resultString;
    //     for (int i=index; i< lengthofSubString; i++) {
    //         char newCharacter = startString[i];
    //         resultString += newCharacter;
    //     }
    //     return resultString;
    // }
};