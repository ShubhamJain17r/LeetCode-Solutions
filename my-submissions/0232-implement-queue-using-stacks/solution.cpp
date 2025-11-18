class MyQueue {
    stack<int> s1;
    stack<int> s2;
    int pop_peekHelper(stack<int>& s1, stack<int>& s2) {
        if (!s1.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
public:
    MyQueue() {

    }
    
    void push(int x) {
        if (s1.empty()) {
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        s1.push(x);
    }
    
    int pop() {
        int x = pop_peekHelper(s1, s2);
        s2.pop();
        return x;
    }
    
    int peek() {
        return pop_peekHelper(s1, s2);
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
