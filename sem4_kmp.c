#include <stdio.h>
#include <string.h>

// Function to compute the Longest Prefix Suffix (LPS) array for the pattern
// This array represents the length of the longest proper prefix which is also a proper suffix
void computeLPS(char* pattern, int M, int* lps) {
    int len = 0; // Length of the previous longest prefix suffix
    lps[0] = 0;  // lps[0] is always 0
    for (int i = 1; i < M; ) {
        // If characters at current position i and len match
        // Increment both i and len
        if (pattern[i] == pattern[len]) lps[i++] = ++len;
        // If they don't match and len is non-zero, update len to lps[len - 1]
        // This helps in skipping unnecessary comparisons
        else if (len) len = lps[len - 1];
        // If they don't match and len is zero, set lps[i] to zero and increment i
        // Since no prefix of length greater than zero is also a suffix
        else lps[i++] = 0;
    }
}

// Function to perform Knuth-Morris-Pratt (KMP) pattern matching algorithm
void KMP(char* text, char* pattern) {
    int N = strlen(text);    // Length of the text
    int M = strlen(pattern); // Length of the pattern
    int lps[M];              // Array to store the LPS values
    computeLPS(pattern, M, lps); // Compute the LPS array for the pattern

    // Loop through the text and pattern to find matches
    for (int i = 0, j = 0; i < N; ) {
        // If characters at current positions i and j match
        // Increment both i and j
        if (text[i] == pattern[j]) {
            i++, j++;
            // If entire pattern is found, print the index where it starts
            // Then update j to continue searching for further matches
            if (j == M) printf("Pattern found at index %d\n", i - j), j = lps[j - 1];
        }
        // If characters don't match and j is non-zero, update j to lps[j - 1]
        // This helps in skipping unnecessary comparisons
        else if (j) j = lps[j - 1];
        // If characters don't match and j is zero, increment i
        else i++;
    }
}

// Main function
int main() {
    char text[] = "ababcabcabababd"; // Input text
    char pattern[] = "ababd";        // Pattern to search for
    KMP(text, pattern);                   // Call KMP function to perform pattern matching
    return 0;
}
