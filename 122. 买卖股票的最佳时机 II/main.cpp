class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> st;
        int ans = 0;
        for(int p : prices){
            if(st.empty() || st.top() < p){
                st.push(p);
            } else if(st.top() >= p){
                int b = st.top();
                int a = 0;
                while(!st.empty()){
                    a = st.top();
                    st.pop();
                }
                ans += (b - a);
                st.push(p);
            }
        }
        if(!st.empty()){
            int b = st.top();
            int a = 0;
            while(!st.empty()){
                a = st.top();
                st.pop();
            }
            ans += (b - a);
        }
        return ans;
    }
};