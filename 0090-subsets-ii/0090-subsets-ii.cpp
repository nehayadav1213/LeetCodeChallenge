class Solution {
public:
    vector<vector<int>> ans;

    void solve(int start, vector<int>& nums, vector<int>& current) {
        ans.push_back(current);

        for (int i = start; i < nums.size(); i++) {

            // Same level par duplicate skip karo
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            current.push_back(nums[i]);

            solve(i + 1, nums, current);

            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> current;
        solve(0, nums, current);

        return ans;
    }
};