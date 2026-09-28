#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection(int a[], int n)
{
    int i, min, temp;

    if (n <= 1)
        return;

    min = 0;

    for (i = 1; i < n; i++)
        if (a[i] < a[min])
            min = i;

    temp = a[0];
    a[0] = a[min];
    a[min] = temp;

    selection(a + 1, n - 1);
}

int main()
{
    int n, i;
    int *a;
    clock_t start, end;
    double time;
    FILE *fp;

    srand(time(NULL));
    fp = fopen("selection.dat", "w");

    printf("Recursive Selection Sort\n");
    printf("-------------------------------\n");
    printf("n\tTime (seconds)\n");

    for (n = 100; n <= 5000; n += 100)
    {
        a = malloc(n * sizeof(int));

        for (i = 0; i < n; i++)
            a[i] = rand() % 10000;

        start = clock();
        selection(a, n);
        end = clock();

        time = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t%.6f\n", n, time);
        fprintf(fp, "%d %.6f\n", n, time);

        free(a);
    }

    fclose(fp);

    printf("-------------------------------\n");
    printf("Data saved in selection.dat\n");

    return 0;
}
