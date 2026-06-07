// Problem: Reverse Pairs
// Link: https://leetcode.com/problems/reverse-pairs/
// Difficulty: Hard
// Approach: Modified Merge Sort — count pairs while merging
// Time: O(n log n) | Space: O(n)


class Solution {
public:
    int merge(vector<int>& nums, int l, int mid, int r) {
        int count = 0;

        int j = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (j <= r && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        vector<int> temp;
        int left = l, right = mid + 1;

        while (left <= mid && right <= r) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left++]);
        }

        while (right <= r) {
            temp.push_back(nums[right++]);
        }

        for (int i = 0; i < temp.size(); i++) {
            nums[l + i] = temp[i];
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;

        int mid = l + (r - l) / 2;

        int count = 0;
        count += mergeSort(nums, l, mid);
        count += mergeSort(nums, mid + 1, r);
        count += merge(nums, l, mid, r);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
