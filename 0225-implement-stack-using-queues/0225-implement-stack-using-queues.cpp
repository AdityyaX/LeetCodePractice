class MyStack {
    /*
    push 1 2 3 4 5
    1
    2 1
    3 2 1
    4 3 2 1
    5 4 3 2 1



    */
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        int s = q.size();
        for (int i = 0; i < s - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int n = q.front();
        q.pop();
        return n;
    }

    int top() {
        int n = q.front();
        return n;
    }

    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */