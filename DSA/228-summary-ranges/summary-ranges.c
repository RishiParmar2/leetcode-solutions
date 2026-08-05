char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;

    if (numsSize == 0)
        return NULL;

    char **result = (char **)malloc(numsSize * sizeof(char *));

    int i = 0;
    while (i < numsSize) {
        int start = nums[i];

        while (i + 1 < numsSize && nums[i + 1] == nums[i] + 1)
            i++;

        int end = nums[i];

        int len;
        if (start == end) {
            len = snprintf(NULL, 0, "%d", start);
            result[*returnSize] = (char *)malloc(len + 1);
            sprintf(result[*returnSize], "%d", start);
        } else {
            len = snprintf(NULL, 0, "%d->%d", start, end);
            result[*returnSize] = (char *)malloc(len + 1);
            sprintf(result[*returnSize], "%d->%d", start, end);
        }

        (*returnSize)++;
        i++;
    }

    return result;
}