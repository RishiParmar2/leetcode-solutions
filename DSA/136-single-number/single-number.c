int singleNumber(int* nums, int numsSize) {
    // int freq[60001] = {0};

    // for (int i = 0; i < numsSize; i++) {
    //     freq[nums[i] + 30000]++;
    // }

    // for (int i = 0; i < 60001; i++) {
    //     if (freq[i] == 1) {
    //         return i - 30000;
    //     }
    // }

    int res = 0;
    for(int i = 0; i< numsSize; i++)
        res ^= nums[i];
    return res;
    // return 0;
}