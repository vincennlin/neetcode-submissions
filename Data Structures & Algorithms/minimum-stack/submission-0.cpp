class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {
        st = stack<int>();
        minSt = stack<int>();
    }

    void push(int val) {
        st.push(val);
        minSt.push(min(val, minSt.empty() ? val : minSt.top()));
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};
