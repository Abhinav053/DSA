class MyQueue {
    stack<int>st;
    stack<int>tmp;
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(!st.empty()){
            tmp.push(st.top());
            st.pop();
        }
        int k=tmp.top();
        tmp.pop();

        while(!tmp.empty()){
            st.push(tmp.top());
            tmp.pop();
        }
        return k;
    }
    
    int peek() {
         while(!st.empty()){
            tmp.push(st.top());
            st.pop();
        }
        int k=tmp.top();
        

        while(!tmp.empty()){
            st.push(tmp.top());
            tmp.pop();
        }
        return k;
    }
    
    bool empty() {
        return st.empty();
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