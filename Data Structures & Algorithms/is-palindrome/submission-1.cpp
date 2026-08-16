class Solution {
public:
    bool isAlphanumeric(char c) {
        if((c >= '0' && c <= '9') || (c >= 'A' && c >= 'Z' || (c >= 'a' && c <= 'z'))) return true;
        return false;
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;

        for(auto& c: s){
            c = tolower(c);
        }

        while(i < j){
            while(i < j && !isAlphanumeric(s[i])) i++;
            while(i < j && !isAlphanumeric(s[j])) j--;
            if(i < j && s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};
