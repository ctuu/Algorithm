#include <stdio.h>
#include <string.h>
#define NUM 2
#define MAX 1001

int main(void)
{
    int a, b, c, count, t;
    int n[NUM];
    char num[NUM + 1][MAX] = {0};

        for (a = 0; a < NUM; a++)
        {
            scanf("%s", num[a]);
            n[a] = strlen(num[a]);
            for (c = MAX - 1, b = n[a] - 1; b >= 0; b--, c--)
            {
                num[a][c] = num[a][b] - 48;
                num[a][b] = '\0';
            }
        }

        for (a = 0; a < NUM; a++)
            for (b = 1; b < MAX; b++)
                num[NUM][b] += num[a][b];

        for (b = MAX - 1; b > 0; b--)
            while (num[NUM][b] >= 10)
            {
                num[NUM][b] -= 10;
                num[NUM][b - 1] += 1;
            }

        for (c = 0, b = 0; b < MAX; b++)
        {
            if (num[NUM][b] == 0 && c == 0)
            {
                if (b == MAX - 1 && c == 0)
                    printf("%d", num[NUM][b]);
                continue;
            }
            else
            {
                c = 1;
                printf("%d", num[NUM][b]);
            }
        }

    return 0;
}