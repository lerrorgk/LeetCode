class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }

        auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pri_que(comp);

        for (auto& it : map) {
            pri_que.push(it);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }

        vector<int> result;
        while (!pri_que.empty()) {
            result.emplace_back(pri_que.top().first);
            pri_que.pop();
        }
        return result;
    }
};
