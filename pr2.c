#include"headerpr2.h"

void autotest(void) {
char word[256];
printf("Before autotest...\n");
wow_word("text.txt", word);
if (strlen(word) == 2) {
    printf("Autotest passed...\n");
}
else {
    printf("Autotest failed...\n");
}
}

int wow_word(const char* filename, char* word) {
    FILE *fp;
    int cnt = 0;
    char s[512],wrd[512], *snach, *skon;
    int word_min = INT_MAX;
fp = fopen(filename, "r");
if (fp) {
    while (fgets(s, 256, fp)) {
        for (snach = strchr(s, '"'), skon = snach ? strchr(snach + 1, '"') : NULL;            //if (snach) skon = strchr(snach + 1,'"');
            snach && skon;                                                                    //else skon = NULL;
            snach = strchr(skon + 1, '"'), skon = snach ? strchr(snach + 1, '"') : NULL) {    //
            strncpy (wrd, snach + 1, skon - snach - 1);
            wrd[skon - snach - 1] = '\0';
            if (strlen(wrd) <= word_min && *wrd >= 'A' && *wrd <= 'Z') {
                for(i = 1, i < strlen(wrd)){
                    if (wrd[i] >= 48 || wrd[i] <= 57){
                       printf("Not satisfyed...\n");
                    }
                }
                else{
                   cnt = 1;
                   word_min = strlen(wrd);
                   word[0] = '\0';
                   strcpy(word, wrd);
                }
            }
        }
    }
}
else {
        printf("ERR! Cannot open file...");
        return 0;
}
fclose(fp);
return cnt;
}

