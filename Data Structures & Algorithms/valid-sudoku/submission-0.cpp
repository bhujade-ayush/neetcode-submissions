class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            unordered_map<char, int> mp;
            for(int j = 0; j < 9; j++){
                mp[board[i][j]]++;
            }

            for(const auto& [key, val] : mp){
                if(key > '0' && key <= '9' && val > 1) return false;
            }
        }
        for(int i = 0; i < 9; i++){
            unordered_map<char, int> mp;
            for(int j = 0; j < 9; j++){
                mp[board[j][i]]++;
            }

            for(const auto& [key, val] : mp){
                if(key > '0' && key <= '9' && val > 1) return false;
            }
        }
        int n = 9;
        int p = 0;
        int q = 0;
        while(n--){
            unordered_map<char, int> mp;
            for(int i = p; i < p+3; i++){
                for(int j = q; j < q+3; j++){
                    mp[board[i][j]]++;
                }
            }
            p+=3;
            if(p >= 9){
                p = 0;
                q += 3;
            }
            for(const auto& [key, val] : mp){
                if(key > '0' && key <= '9' && val > 1) return false;
            }
        }

        return true;
    }
};
