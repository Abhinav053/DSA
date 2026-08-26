class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0;
        int one = 0;
        string mini = "";
        
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '1')
                one++;


            while (one > k) {
                if (s[i] == '1')
                    one--;
                i++;
            }

           
            if (one == k) {
            
                while (s[i] == '0')
                    i++;

                string curr = s.substr(i, j - i + 1);

                if (mini == "" || curr.size() < mini.size() ||
                    (curr.size() == mini.size() && curr < mini)) {
                    mini = curr;
                }
            }
        }

        return mini;
    }
};