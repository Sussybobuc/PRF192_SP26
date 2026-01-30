#include<stdio.h>

int main()
{int a,b;
	float kq;
	char Meth;
	if(scanf("%d,%d", &a,&b) != 2){
		printf("Nhap sai");
		return 0;
	} fflush(stdin);
	if(scanf("%c", &Meth)!=1 || 
		(Meth != '+'&& Meth !='-'&& Meth !='*' && Meth != '/' && Meth !='%')){
		printf("Nhap sai");
		return 0;} switch(Meth){case '+':
			kq = a+b;
			break;case '-':
			kq = a-b;
			break;case '*':
			kq = a*b;
			break;case '/':
			kq = (float)a/b;
			if(a==0 || b==0){
				printf("Khong the chia cho 0");
				return 0;
				} break;case '%':
			kq = a%b;
			if(a==0 || b==0){
				printf("Khong the chia cho 0");
				return 0;}}if(kq-(int)kq!=0){printf("%d %c %d = %.2f",a,Meth,b,kq);
		return 0;}printf("%d %c %d = %.0f",a,Meth,b,kq);
	return 0;
}
