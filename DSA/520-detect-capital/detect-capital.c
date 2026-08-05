bool detectCapitalUse(char* word) {
    int upperCase = 0;
    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        if (isupper(word[i])) {
            upperCase++;
        }
    }

    return upperCase == len ||                  // All uppercase
           upperCase == 0 ||                    // All lowercase
           (upperCase == 1 && isupper(word[0])); // Only first letter uppercase
}