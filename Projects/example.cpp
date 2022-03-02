#include<stdio.h>
#include<string.h>

int main() {
    char c;
    char s[100];
    scanf("%c", &c);
    getchar();
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    int length = strlen(s);
    int index = -1;

    for (int i = 0; i < length; i++) {
        if (s[i] == c) {
            index = i;
            i=length;
        }
    }

    printf("%d", index);

    return 0;
}