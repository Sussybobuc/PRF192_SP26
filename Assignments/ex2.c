#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("baitap2.txt", "w");
    if (fp == NULL)
    {
        printf("Error!");
        return 0;
    }
    int n;
    printf("Nhap vao so n:");
    scanf("%d", &n);
    fprintf(fp, "%d\n", n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        fprintf(fp, "%d ", arr[i]);
    }

    fclose(fp);

    fp = fopen("baitap2.txt", "r");
    if (fp == NULL)
    {
        printf("Error!");
        return 0;
    }
    printf("\nNoi dung cua file");
    int count;
    if (fscanf(fp, "%d", &count) != EOF)
    {
        printf("%d\n", count);
        int value;
        for (int i = 0; i < count; i++)
        {
            if (fscanf(fp, "%d", &value) != EOF)
            {
                printf("%d\t", value);
            }
        }
    }
    fclose(fp);
    return 0;
}