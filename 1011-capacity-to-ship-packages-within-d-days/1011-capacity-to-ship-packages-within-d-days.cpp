class Solution {
    private:
  bool ship(const std::vector<int>& weights, int val, int days) {
        int sum = 0;
        int count = 0; 
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] > val) {
                count++; 
                sum = 0;  
            }
            sum += weights[i];
        }
        return count+1 <= days;  
    }
public:
 int shipWithinDays(std::vector<int>& weights, int days) {
        int n = weights.size();
        int l = *max_element(weights.begin(), weights.end()); 
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += weights[i];
        }
        int h = sum;  

     
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (ship(weights, mid, days)) {
                h = mid - 1; 
            } else {
                l = mid + 1; 
            }
        }
        return l;
    }
};