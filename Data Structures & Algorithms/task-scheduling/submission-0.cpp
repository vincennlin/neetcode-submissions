class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }

        priority_queue<int> maxHeap;
        for (int cnt : count) {
            if (cnt > 0) {
                maxHeap.push(cnt);
            }
        }

        int time = 0;
        queue<pair<int, int>> cdHeap;
        while (!maxHeap.empty() || !cdHeap.empty()) {
            time++;

            if (maxHeap.empty()) {
                time = cdHeap.front().second;
            } else {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) {
                    cdHeap.push({cnt, time + n});
                }
            }

            if (!cdHeap.empty() && cdHeap.front().second == time) {
                maxHeap.push(cdHeap.front().first);
                cdHeap.pop();
            }
        }

        return time;
    }
};