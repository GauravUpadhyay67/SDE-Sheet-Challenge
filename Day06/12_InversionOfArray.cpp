// Problem: Inversion of Array (Count Inversions)
// Link: https://www.geeksforgeeks.org/counting-inversions/
// Difficulty: Hard
// Approach: Modified Merge Sort — count inversions while merging
// Time: O(n log n) | Space: O(n)


class Solution {
  public:
    
    int merge(vector<int>&arr, int l, int mid, int r){
        vector<int>sortedArr;
        int left1 = l, left2 = mid+1;
        int count = 0;
        
        while(left1 <= mid && left2 <= r){
            if(arr[left1] <= arr[left2]){
                sortedArr.push_back(arr[left1++]);
            }
            else{
                count += (mid - left1 + 1);
                sortedArr.push_back(arr[left2++]);
            }
        }
        
        while(left1 <= mid){
            sortedArr.push_back(arr[left1++]);
        }
        
         while(left2 <= r){
            sortedArr.push_back(arr[left2++]);
        }
        
        for(int i=0; i<sortedArr.size(); i++){
            arr[l] = sortedArr[i];
            l++;
        }
        return count;
    }
  
    int mergeSort(vector<int>& arr, int l, int r) {
        int count = 0;
        if(l == r) return 0;
        
        int mid = l + (r - l)/2;
        
        count += mergeSort(arr, l, mid);
        count += mergeSort(arr, mid+1, r);
        
        count += merge(arr, l, mid, r);
        
        return count;
    }
    
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return mergeSort(arr, 0, n-1);
    }
};
