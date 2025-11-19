class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Optimal (Using Bucket Sort)
        unordered_map<int, int> mpp;
        int n = nums.size();

        for (int& num : nums) {
            mpp[num]++;
        }

        vector<vector<int>> bucket(n + 1);
        // index = freq
        // value = element
        // bucket[i] = elements having freq 'i'

        for (auto& val : mpp) {
            int element = val.first;
            int freq = val.second;

            bucket[freq].push_back(element);
        }

        vector<int> res;

        for (int i = n; i >= 0; i--) {
            if (bucket[i].size() == 0)
                continue;

            while (bucket[i].size() != 0 && res.size() < k) {
                res.push_back(bucket[i].back());
                bucket[i].pop_back();
            }
        }

        return res;

        // Brute force
        // unordered_map<int, int> mpp;
        // vector<int> res;

        // for (int& num : nums) {
        //     mpp[num]++;
        // }

        // vector<pair<int, int>> freq(mpp.begin(), mpp.end());

        // auto comp = [&](auto& a, auto& b) {
        //     return a.second > b.second;
        // };

        // sort(freq.begin(), freq.end(), comp);

        // for (int i = 0; i < k; i++) {
        //     res.push_back(freq[i].first);
        // }

        // return res;
    }
};