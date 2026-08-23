class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int left_sum = 0;
        int right_sum = 0;

        int left = 0;
        int right = 0;

        
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                left++;
            else
                left_sum += num[i] - '0';
        }


        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                right++;
            else
                right_sum += num[i] - '0';
        }

        if ((left + right) % 2 == 1)
            return true;

        int l =2*left_sum+9*left;

        int k = 2*right_sum+9*right;

        return l != k;
    }
};