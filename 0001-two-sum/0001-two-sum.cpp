class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int,int> num_to_index;
        for (int i=0; i < nums.size(); i++) {
            int compliment = target - nums[i];
            if (num_to_index.count(compliment) > 0) {
                return {num_to_index[compliment], i};
            }else {
                num_to_index[nums[i]] = i;
            }
        }
        return {0,0};
    }
};