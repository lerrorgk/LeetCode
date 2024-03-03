class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0); 
        st.push(0);

        for (int i = 1; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int right = i;
                int mid = st.top();
                st.pop();
                if (!st.empty()) {
                    int left = st.top();
                    int w = right - left - 1;
                    int h = heights[mid];
                    result = max(result, w * h);
                }
            }
            st.push(i);
        }
        return result;
    }
};
