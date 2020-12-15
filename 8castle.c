#include <stdio.h>
#include <stdlib.h>

//function that's gonna run if you lose :)
void lose() {
    system("cls;clear");
    printf("you lost. try again!\n");
}

//function that's checking win/lose.

int checkWinLose(int **x) {
    int i, j;
    int flag = 0, flag2 = 0;

    //checking rows
    for (i = 0; i < 8; i++) {
        flag = 0;
        for (j = 0; j < 8; j++)
            if (x[i][j] == -1) flag += 1;

        if (flag > 1) {
            flag2 = 1;
            return 1;
        }
    }
    if (flag2 != 1) {

        //checking columns
        for (i = 0; i < 8; i++) {
            flag = 0;
            for (j = 0; j < 8; j++)
                if (x[j][i] == -1) flag += 1;

            if (flag > 1) {
                flag2 = 1;
                return 1;
            }
        }
    }
    return 5;
}

int getMap(int **x) {
    int i, j, xi, yj;
    int a = 1, p = 1;
//getting points
    for (i = 0; i < 8; i++) {
        a = scanf("%d %d", &xi, &yj);
        if (a < 1) {
            fflush(stdin);
            p = 0;
        }
        if (xi < 0 || yj < 0 || xi > 7 || yj > 7) p = 0;

        else x[xi][yj] = -1;
    }
    return p;
}

//putting zeroes in the array
void zeroing(int **x) {
    int i, j;
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            x[i][j] = 0;
}


int main() {
    int x[8][8] = {0};
    int a, b;
    a = getMap(x);
    b = checkWinLose(x);

    while (b == 1 || a == 0) {
        lose();
        zeroing(x);
        a = getMap(x);
        b = checkWinLose(x);
    }

    printf("you won!");
}





