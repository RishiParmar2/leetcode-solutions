// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */

void countingSort(int *nums, int size)
{
    int count[1001] = {0};

    // Count frequency of each number
    for (int i = 0; i < size; i++)
    {
        count[nums[i]]++;
    }

    // Put numbers back in sorted order
    int index = 0;

    for (int i = 0; i <= 1000; i++)
    {
        while (count[i] > 0)
        {
            nums[index] = i;
            index++;
            count[i]--;
        }
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size,
                  int* nums2, int nums2Size,
                  int* returnSize)
{
    // Sort both arrays using our own sorting function
    countingSort(nums1, nums1Size);
    countingSort(nums2, nums2Size);

    int size;

    if (nums1Size < nums2Size)
        size = nums1Size;
    else
        size = nums2Size;

    int *result = (int *)malloc(size * sizeof(int));

    *returnSize = 0;

    int i = 0;
    int j = 0;

    // Two pointer approach
    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] == nums2[j])
        {
            // Add only unique values
            if (*returnSize == 0 || result[*returnSize - 1] != nums1[i])
            {
                result[*returnSize] = nums1[i];
                (*returnSize)++;
            }

            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return result;
}