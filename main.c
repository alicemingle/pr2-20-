#include "headerpr2.h"

int main(void) {
    char word[512];
    int cnt;
    autotest();
    cnt = wow_word("test.txt", word);
    if (cnt == 1) {
        printf("%s\n", word);
    }
    else {
        if(cnt == 0);
        printf("ERR! No satisfying words\n");
    }
}
