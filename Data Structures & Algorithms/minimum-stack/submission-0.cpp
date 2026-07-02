class MinStack {
private:
    stack<int> mainSt;
    stack<int> minSt;

public:
    MinStack() {}

    void push(int val) {
        mainSt.push(val);

        if (minSt.empty()) {
            minSt.push(val);
        } else {
            minSt.push(std::min(val, minSt.top()));
        }
    }

    void pop() {
        mainSt.pop();
        minSt.pop();
    }

    int top() {
        return mainSt.top();
    }

    int getMin() {
        return minSt.top();
    }
};