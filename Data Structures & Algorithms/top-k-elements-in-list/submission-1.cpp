class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> buckets(n+1);

        unordered_map<int, int> mp;
        for(const auto& key : nums){
            mp[key]++;
        }

        for(const auto& [key, val] : mp){
            buckets[val].push_back(key);
        }

        vector<int> ans;

        for(int i = n; i >= 0; i--){
            for(const auto& ele : buckets[i]){
                ans.push_back(ele);
            }

            if(ans.size() >= k) return ans;
        }
        return ans;
    }
};
