#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1;
        int l = 0;
        int r = n;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return nums[l];
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test 1 (Expected 0): " << s.findMin(nums1) << endl;
    return 0;
}