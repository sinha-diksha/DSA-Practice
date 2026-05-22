class StockSpanner {
public:
    stack<pair<int,int>> st;
    int index;
    StockSpanner() {
        index=0;
    }
    
    int next(int price) {
        
        while(!st.empty() && st.top().second<=price){
            st.pop();
        }
        int val=-1;
        if(!st.empty()){
            val=st.top().first;
        }
        int returnVal=index-val;
        st.push({index, price});
        index++;

        return returnVal;
        



    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */