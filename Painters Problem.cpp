class Solution {
  public:
  
    bool isPossible(vector<int>& arr, int k, int mid) {
        int sum = 0;
        int painters = 1;
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > mid)
                return false;
            if (sum + arr[i] <= mid) {
                sum += arr[i];
            } else {
                painters++;
                sum = arr[i];
                if (painters > k)
                    return false;
            }
        }
        return true;
    }
    int minTime(vector<int>& arr, int k) {
        int low = 0, high = 0;
        for (int i = 0; i < arr.size(); i++) {
            high += arr[i];
            low = max(low, arr[i]);
        }
        int ans = high;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
