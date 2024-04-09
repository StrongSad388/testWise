#include <stdio.h>

int myEcho() {
    char buffer[BUFSIZ];
    while (EOF != scanf("%s", buffer)) {
        printf("%s\n", buffer);
    }
    return 0;
}

int main() {
    return myEcho();
}