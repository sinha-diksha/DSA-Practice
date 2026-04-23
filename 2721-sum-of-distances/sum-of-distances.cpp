class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, vector<int>> mp;

        // group indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // process each group once
        for (auto &it : mp) {
            vector<int> &vec = it.second;
            int sz = vec.size();

            vector<long long> pref(sz);
            pref[0] = vec[0];
            for (int i = 1; i < sz; i++) {
                pref[i] = pref[i - 1] + vec[i];
            }

            for (int k = 0; k < sz; k++) {
                int idx = vec[k];

                long long left = 0;
                if (k > 0) {
                    left = (long long)idx * k - pref[k - 1];
                }

                long long right = 0;
                if (k < sz - 1) {
                    long long rightSum = pref[sz - 1] - pref[k];
                    long long countRight = sz - k - 1;
                    right = rightSum - (long long)idx * countRight;
                }

                ans[idx] = left + right;
            }
        }

        return ans;
    }
};