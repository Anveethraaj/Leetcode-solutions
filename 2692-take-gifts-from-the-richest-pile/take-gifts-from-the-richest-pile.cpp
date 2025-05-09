class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq;
        for (int gift : gifts)
            pq.push((long long)gift); // store as long long

        while (k-- && !pq.empty()) {
            long long top = pq.top(); pq.pop();
            pq.push((long long)sqrt(top));
        }

        long long total = 0;
        while (!pq.empty()) {
            total += pq.top();
            pq.pop();
        }

        return total;
    }
};
