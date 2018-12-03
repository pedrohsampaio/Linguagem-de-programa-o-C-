#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

unsigned int MaiorNumero(unsigned int numeros[],unsigned int quantidade);
unsigned int verifPrimo(unsigned int num);
long long int MMC(unsigned int numeros[],unsigned int quantidade);

int main(){
	setlocale(LC_ALL,"Portuguese");
	char TeclaPressionada;
	unsigned int Numeros,i;
	long long int resultado;
	do{
		system("cls");
		do{
			printf("Quantidade de obestáculos? ");
			scanf("%u",&Numeros);
		}while((Numeros<0)||(Numeros>50));
		if(Numeros==0)
			break;	
		unsigned int inserir[Numeros]; //vai receber os números para calcular o MMC
		system("cls");
		for(i=0;i<Numeros;i++){
			do{
				printf("%u° obestáculo: ",i+1);
				scanf("%u",&inserir[i]);
			}while((inserir[i]<=0)||(inserir[i]>30));
		}
		system("cls");
		printf("Frequência dos obstáculos (");
		for(i=0;i<Numeros;i++){
			if(i!=Numeros-1)
				printf("%u,",inserir[i]);
			else
				printf("%u) ",inserir[i]);
		}
		resultado=MMC(inserir,Numeros);
		printf(" menor instante de tempo: %lld.",resultado);
		printf("\n\nSe deseja calcular novamente pressione 'Enter'.");
		TeclaPressionada=getch();
	}while(TeclaPressionada==13);
	return 0;
}

long long int MMC(unsigned int numeros[],unsigned int quantidade){
	unsigned int maior,i,j,divisor;
	long long int acumulador=1;
	do{
		maior=MaiorNumero(numeros,quantidade),j=0;
		if(maior>1){
			for(i=2;j!=1;i++){
				if((maior%i==0)&&(verifPrimo(i)==1))
					divisor=i,j=1;	
			}
			for(i=0;i<quantidade;i++){
				if(numeros[i]%divisor==0)
					numeros[i]/=divisor;
			}
			acumulador*=divisor;
		}else
			return acumulador;
	}while(1);
}

unsigned int MaiorNumero(unsigned int numeros[],unsigned int quantidade){
	unsigned int i,maior=0;
	for(i=0;i<quantidade;i++){
		if(numeros[i]>maior)
			maior=numeros[i];
	}
	return maior;
}

unsigned int verifPrimo(unsigned int num){ //verifica se o número é primo se ele retornar 1 quer dizer que o número é primo
	unsigned int i,divisores=0;
	if(num<=1)
		return 0;
	else{
		for(i=2;i<num;i++){
			if(num%i==0)
				divisores+=1;
		}
	}
	return (divisores>0)?0:1;
}
