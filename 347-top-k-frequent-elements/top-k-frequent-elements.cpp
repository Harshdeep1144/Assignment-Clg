class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        vector<int> res;

        for (int& num : nums) {
            mpp[num]++;
        }

        vector<pair<int, int>> freq(mpp.begin(), mpp.end());

        auto comp = [&](auto& a, auto& b) {
            return a.second > b.second;
        };

        sort(freq.begin(), freq.end(), comp);

        for (int i = 0; i < k; i++) {
            res.push_back(freq[i].first);
        }

        return res;
    }
};