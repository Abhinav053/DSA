class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (auto k : knowledge) {
            mp[k[0]] = k[1];
        }

        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(') {
                ans += s[i];
            } 
            else {
                string str = "";
                i++;  

                while (s[i] != ')') {
                    str += s[i];
                    i++;
                }

                if (mp.find(str) != mp.end()) {
                    ans += mp[str];
                } 
                else {
                    ans += "?";
                }
            }
        }

        return ans;
    }
};