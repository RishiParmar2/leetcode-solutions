/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int findDigitCount(int *digits, int digitsSize, int count[10]) {
    for (int i = 0; i < digitsSize; i++) {
        count[digits[i]]++;
    }
    return 0;
}

int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
    int count[10] = {0};
    
    // Count occurrences of each digitt
    for (int i = 0; i < digitsSize; i++) {
        count[digits[i]]++;
    }

    // At most 450 even three-digit numbers.
    int *result = malloc(450 * sizeof(int));
    *returnSize = 0;

    // Check every possible three-digit even number.
    for (int num = 100; num <= 998; num += 2) {
        int a = num / 100;
        int b = (num / 10) % 10;
        int c = num % 10;

        int needed[10] = {0};
        needed[a]++;
        needed[b]++;
        needed[c]++;

        int possible = 1;

        for (int d = 0; d < 10; d++) {
            if (needed[d] > count[d]) {
                possible = 0;
                break;
            }
        }

        if (possible) {
            result[(*returnSize)++] = num;
        }
    }

    return result;
}
