#include <stdio.h>

int main(){
    FILE *fp;
    fp = fopen("baitap1.txt","w");
    
    if(fp == NULL){
        printf("Error!");
        return 0;
    }

    int n;
    printf("Nhap vao so n: ");
    scanf("%d", &n);
    fprintf(fp, "Gia tri n: %d", n);
    
    fclose(fp);
    
    fp = fopen("baitap1.txt","r");
    if(fp == NULL){
        printf("Error");
        return 0;
    }

    int s;                          
    while((s = getc(fp)) != EOF){   
        printf("%c", s);
    }

    fclose(fp);
    return 0;
}