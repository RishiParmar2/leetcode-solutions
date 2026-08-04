/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char* s, char c, int* returnSize) {
    int n = strlen(s);
    *returnSize = n;

    int *ans = (int *)malloc(n * sizeof(int));

    int prev = INT_MIN / 2;

    // L to R
    for (int i = 0; i < n; i++) {
        if (s[i] == c)
            prev = i;

        ans[i] = i - prev;
    }

    prev = INT_MAX / 2;

    // R to L
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == c)
            prev = i;

        if (prev - i < ans[i])
            ans[i] = prev - i;
    }

    return ans;
}