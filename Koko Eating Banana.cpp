class Solution {
public:
    
    bool possible(vector<int>& piles, int h, int k) {
        int hours = 0;
        
        for (int i = 0; i < piles.size(); i++) {
            hours += (piles[i] + k - 1) / k;
            if (hours > h)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for (int i = 0; i < piles.size(); i++) {
            r = max(r, piles[i]);
        }
        int ans = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (possible(piles, h, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
