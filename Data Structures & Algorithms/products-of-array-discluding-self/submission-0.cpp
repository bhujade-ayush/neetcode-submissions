class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;

        int prod = 1;
        int alt_prod = 1;
        for(const auto& num : nums){
            mp[num]++;
            prod*=num;
            if(num != 0) alt_prod *= num;
        }

        vector<int> ans;
        if(mp[0] > 1) return vector<int>(n, 0);

        for(const auto& num: nums){
            if(num != 0) ans.push_back(prod/num);
            else ans.push_back(alt_prod);
        }

        return ans;
    }
};
