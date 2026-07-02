class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    void addNum(int num) {
        maxheap.push(num);

        minheap.push(maxheap.top());
        maxheap.pop();

        if (minheap.size() > maxheap.size() + 1) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian() {
        if (minheap.size() > maxheap.size())
            return minheap.top();

        return (minheap.top() + maxheap.top()) / 2.0;
    }
};