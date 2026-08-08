int pivotIndex(int* nums, int numsSize) {
    int idx = -1;
    int leftsum = 0, rightsum = 0, sum = 0;
    if (numsSize == 1)
        return 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        rightsum = sum - leftsum - nums[i];
        if (leftsum == rightsum)
            return i;
        leftsum += nums[i];
    }
    return idx;
}