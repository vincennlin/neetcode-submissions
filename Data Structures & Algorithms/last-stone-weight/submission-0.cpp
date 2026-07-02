class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int num : stones) {
            maxHeap.push(num);
        }

        while (maxHeap.size() > 1) {
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            if (x > y) {
                maxHeap.push(x - y);
            }
        }

        return maxHeap.size() == 1 ? maxHeap.top() : 0;
    }
};
