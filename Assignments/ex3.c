#include <stdio.h>
#include <string.h>
typedef struct
{
    int id;
    char name[30];
    float grade;
} SV;

int main()
{
    FILE *fp;
    fp = fopen("baitap3.txt", "w");
    if (fp == NULL)
    {
        printf("Error!");
        return 0;
    }
    SV sv1;
    printf("Nhap mssv: ");
    scanf("%d", &sv1.id);
    fprintf(fp, "ID: %d\n", sv1.id);
    while (getchar() != '\n');

    printf("\nNhap ten sinh vien: ");
    fgets(sv1.name, sizeof(sv1.name), stdin);
    sv1.name[strcspn(sv1.name, "\n")] = 0;
    fprintf(fp, "Name: %s\n", sv1.name);

    printf("\nNhap diem: ");
    scanf("%f", &sv1.grade);
    fprintf(fp, "Grade: %.1f\n", sv1.grade);

    fclose(fp);
    fp = fopen("baitap3.txt", "r");
    if (fp == NULL)
    {
        printf("Error!");
        return 0;
    }
    int s;
    do{
        s = getc(fp);
        printf("%c",s);
    }while(s != EOF);
    fclose(fp);

    return 0;
}