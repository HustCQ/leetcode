/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, vector<int>> elements;

        for (int i = 0; i < nums.size(); ++i) {
            elements[nums[i]].push_back(i);
        }

        for (map<int, vector<int>>::iterator it = elements.begin(); it != elements.end(); ++it) {
            int residue = target - it->first;
            if (residue == it->first && it->second.size() >= 2) {
                res.push_back(it->second[0]);
                res.push_back(it->second[1]);
                break;
            }
            map<int, vector<int>>::iterator positionIt = elements.find(residue);
            if (positionIt != elements.end()) {
                res.push_back(it->second[0]);
                res.push_back(positionIt->second[0]);
                break;
            }
        }

        return res;
    }
};
// @lc code=end

