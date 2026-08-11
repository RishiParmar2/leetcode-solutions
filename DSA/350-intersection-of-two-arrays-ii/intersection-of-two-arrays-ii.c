/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* intersect(int* nums1, int nums1Size,
               int* nums2, int nums2Size,
               int* returnSize) {
    
    // Since nums[i] is between 0 and 1000
    int count[1001] = {0};

    // Count elements in nums1
    for (int i = 0; i < nums1Size; i++) {
        count[nums1[i]]++;
    }

    // Maximum possible result size is the smaller array
    int* result = malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));

    *returnSize = 0;

    // Find intersection
    for (int i = 0; i < nums2Size; i++) {
        int num = nums2[i];

        if (count[num] > 0) {
            result[*returnSize] = num;
            (*returnSize)++;

            count[num]--;
        }
    }

    return result;
}