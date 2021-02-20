char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) return "";
    if (strsSize == 1) return strs[0];

    int len = 0, minLen = strlen(strs[0]);
    for (int i = 1; i < strsSize; ++i) {
        minLen = strlen(strs[i]) < minLen ? strlen(strs[i]) : minLen;
    }

    for (int c = 0; c < minLen; ++c) {
        for (int s = 0; s < strsSize - 1; ++s) {
            if (strs[s][c] == strs[s+1][c]) {
                if (s == strsSize - 2) {
                    ++len;
                }
            } else {
                goto end;
            }
        }
    }

    end:
    if (len > 0) {
        char* res = malloc(len * sizeof(int));
        // terminate the SOURCE before strcpy to destination !!!
        strs[0][len] = '\0';
        strcpy(res, strs[0]);
        return res;
    }

    return "";
}