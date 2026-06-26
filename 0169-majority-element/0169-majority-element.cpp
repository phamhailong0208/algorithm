class Solution {
public:
    int majorityElement(vector<int>& nums) {
        set<int>X = {};
        map<int,int> m= {};
        for (int i=0; i <nums.size(); i++) {
            if (X.count(nums[i]) ==0) {
                X.insert(nums[i]);
                m.insert({nums[i], 1});
                cout << "Insert: " << nums[i] << " count: " << m[nums[i]] << endl;
            }else{
                for (auto &p: m) {
                    if (p.first == nums[i]) {
                        p.second++;
                    }
                }
            }
        }
        for (int i=0;i < nums.size(); i++) {
            for (auto &p: m) {
                if (p.first == nums[i] && p.second > nums.size()/2) {
                    return p.first;
                } 
            }
        }
        return 1;
    }
};