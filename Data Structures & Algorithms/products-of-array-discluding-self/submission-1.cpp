class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int prod = 1;
        int alt_prod = 1;
        int count = 0;
        for(const auto& num : nums){
            prod*=num;
            if(num != 0) alt_prod *= num;
            if(num == 0) count++;
        }

        vector<int> ans;
        if(count > 1) return vector<int>(n, 0);

        for(const auto& num: nums){
            if(num != 0) ans.push_back(prod/num);
            else ans.push_back(alt_prod);
        }

        return ans;
    }
};
