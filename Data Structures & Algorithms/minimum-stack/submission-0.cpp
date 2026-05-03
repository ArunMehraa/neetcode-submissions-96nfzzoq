class MinStack {
public:
    MinStack() {
        
    }
    stack<pair<int,int>>st;
    void push(int val) {
        if(st.size()==0)st.push({val,val});
        else{
            int topp = top();
            int mini = getMin();
            if(val<mini)st.push({val,val});
            else st.push({val,mini});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
