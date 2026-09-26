class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (int x : nums) {
            int complement = k - x;

            if (mp[complement] > 0) {
                mp[complement]--;
                ans++;
            } else {
                mp[x]++;
            }
        }

        return ans;
    }
};