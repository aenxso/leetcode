class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        int l = 1, r = arr.size() - 2, peak = -1; // add a +1/-1 buffer to l & r because of arr[mid-1]/arr[mid+1] check
        
        // find mountain peak
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                peak = mid;
                break;
            } else if(arr[mid] > arr[mid + 1]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if(peak == -1) return false; // no peak found
        
        // check if every element before peak is getting bigger
        for(int i = 0; i < peak; i++) {
            if(arr[i] >= arr[i + 1]) return false;
        }

        // check if every element after peak is getting smaller
        for(int i = peak; i < arr.size() - 1; i++) {
            if(arr[i] <= arr[i + 1]) return false;
        }
        
        return true;
    }
};