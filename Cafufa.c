#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	int ate,num1,num2,i,ultimoDigito,contador=0;
	do{
		printf("Até qual número? ");
		scanf("%i",&ate);
	}while((ate<0)||(ate>1000));
	do{
		if(contador>0)
			printf("Os valores não podem ser zero.\n");
		do{
			printf("Primeiro valor: ");
			scanf("%i",&num1);
		}while((num1<0)||(num1>9));
		do{
			printf("Segundo Valor: ");
			scanf("%i",&num2);
		}while((num2<0)||(num2>9));
		system("cls");
		if((ate==0)&&(num1==0)&&(num2==0)){
			printf("Programa encerrado!");
			return 0;
		}
		contador++;
	}while((num1==0)||(num2==0));
	for(i=1;i<=ate;i++){
		if(i%num1==0)
			printf(" Cafufa ");
		else{
			if(i%num2==0)
				printf(" Cafufa ");
			else{
				ultimoDigito=i/10,ultimoDigito=i*10,ultimoDigito=i-ultimoDigito;
				if((ultimoDigito==num1)||(ultimoDigito==num2))
					printf(" Cafufa ");
				else
					printf(" %i ",i);
			}
		}
		if(i!=ate)
			printf(",");
		else
			printf(".\n");
	}
	system("Pause");
	return 0;
}
