class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        for (char task : tasks) {
            freq[task]++;
        }

        priority_queue<int> q;

        for (auto& it : freq) {
            q.push(it.second);
        }

        int time = 0;

        while (!q.empty()) {
            vector<int> temp;

           
            for (int i = 0; i <= n; i++) {
                if (!q.empty()) {
                    int f = q.top();
                    q.pop();

                    f--;

                    if (f > 0) {
                        temp.push_back(f);
                    }
                }

                time++;

                
                if (q.empty() && temp.empty()) {
                    break;
                }
            }

          
            for (int f : temp) {
                q.push(f);
            }
        }

        return time;
    }
};