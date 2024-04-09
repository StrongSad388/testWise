#include <stdlib.h>
#include <stdio.h>

int rand5() {
    return rand() % 5 + 1;
}

int rand7() {
    int num = 5 * (rand5() - 1) + rand5();
    if (num > 21) {
        return rand7();
    }
    return num % 7;
}


int distribution[7] = {0};
int main(int argc, char *argv[]) {
    int count = 10000;
    if (argc > 1) {
        count = atoi(argv[1]);
    }
    for (int i = 0; i < count; i++) {
        int num = rand7();
        //printf("%d ", num);
        if (num < 0 || num > 7) {
            printf("Error: %d\n", num);
            return 1;
        }
        distribution[num - 1]++;
    }
    printf("Count: %d\nDistribution %%\n", count);
    for (int i = 0; i < 7; i++) {
        printf("%d: %f\n", i + 1, (float)distribution[i]/count);
    }
    return 0;
}