class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string encoded_string = "";

        vector<int> sizes;
        for(int i = 0; i < n; i++){
            sizes.push_back(strs[i].length());
        }

        for(int i = 0; i < n; i++){
            encoded_string += to_string(sizes[i]);
            if(i < n-1) encoded_string += ",";
        }

        encoded_string += "#";

        for(const auto& str: strs){
            encoded_string += str;
        }

        cout << encoded_string;

        return encoded_string;
    }

    vector<string> decode(string encoded_string) {
        vector<int> sizes;

        int i = 0;
        string sz = "";
        while(encoded_string[i] != '#'){
            sz += encoded_string[i];
            if(encoded_string[i+1] == ',' || encoded_string[i+1] == '#'){
                sizes.push_back(stoi(sz));
                sz = "";
                i++;
                if(encoded_string[i] == '#') break;
            }
            i++;
        }

        i++;
        
        vector<string> decoded_strs;
        for(const auto& size : sizes){
            string str = encoded_string.substr(i, size);
            decoded_strs.push_back(str);
            i+=size;
        }

        return decoded_strs;
    }
};
