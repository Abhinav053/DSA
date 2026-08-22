class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp;
        vector<int> ans;

        for(auto k : p) {
            mp[k]++;
        }

        int i = 0;
        int j = 0;
        unordered_map<char,int> temp;

        while(j < s.size()) {

            if(mp.find(s[j]) != mp.end()) {
                temp[s[j]]++;

                while(temp[s[j]] > mp[s[j]]) {
                    temp[s[i]]--;
                    i++;
                }

                if(j - i + 1 == p.size()) {
                    ans.push_back(i);
                    temp[s[i]]--;
                    i++;
                }

                j++;
            }
            else {
                temp.clear();
                j++;
                i = j;
            }
        }

        return ans;
    }
};