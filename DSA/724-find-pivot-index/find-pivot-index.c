int pivotIndex(int* nums, int numsSize)
{
    int leftsum = 0;
    int sum = 0;

    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    }

    for (int i = 0; i < numsSize; i++)
    {
        int rightsum = sum - leftsum - nums[i];

        if (leftsum == rightsum)
            return i;

        leftsum += nums[i];
    }

    return -1;
}