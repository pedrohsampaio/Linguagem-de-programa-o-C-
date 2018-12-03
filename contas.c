#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

long long int TamanhoNum(long long int num1);
long long int RemoverZeroDireita(long long int num);
void ordenarVetor(long long int *vetor, int tamanho,long long int *conta1, char *tipo1,float *Cred1,float *Deb1);
void CalcularAnaliticas(int tamanho,long long int *conta,char *tipo1,float *Cred1, float *Deb1);

int main(){
	setlocale(LC_ALL,"Portuguese");
	int i,j;
	short unsigned int quantidade;
	printf("Quantidade de contas para dar baixa? ");
	scanf("%u",&quantidade);
	long long int contas[quantidade],contascpy[quantidade];
	long long int contasZerosRemovidos[quantidade];
	char tipo[quantidade],tipocpy[quantidade];
	float Cred[quantidade],Deb[quantidade],Credcpy[quantidade],Debcpy[quantidade];
	for(i=0;i<quantidade;i++){
		for(j=0;j<2;j++)
			Cred[i]=0,Deb[i]=0;
	}
	system("cls");
	printf("*Insira as contas*\n\n");
	for(i=0;i<quantidade;i++){
		printf("*%i° conta* \n",i+1);
		printf("Numéro: ");
		scanf("%lld",&contas[i]);
		printf("tipo: ");
		scanf("%s",&tipo[i]);
		if(tipo[i]=='S'){
			printf("Débito (espaço) Crédito: ");
			scanf("%f %f",&Cred[i],&Deb[i]);
		}
		printf("\n");
	}
	system("cls");
	printf("\n\n*Digitados*\n\n");
	for(i=0;i<quantidade;i++){
		long long int tam;
		tam=TamanhoNum(contas[i]);
		for(;20-tam>0;tam++)
			printf("0");
		printf("%lld    %3.c      %4.2f %4.2f\n",contas[i],tipo[i],Cred[i],Deb[i]);
	}
	for(i=0;i<quantidade;i++){
		contasZerosRemovidos[i]=RemoverZeroDireita(contas[i]);
		contas[i]=contasZerosRemovidos[i];
	}
	for(i=0;i<quantidade;i++){
		contascpy[i]=contas[i];
	}
	ordenarVetor(contasZerosRemovidos,quantidade,contas,tipo,Cred,Deb);
	CalcularAnaliticas(quantidade,contas,tipo,Cred,Deb);
	for(i=0;i<quantidade;i++){
		for(j=0;j<quantidade;j++){
			if(contascpy[i]==contas[j])
				tipocpy[i]=tipo[j],Credcpy[i]=Cred[j],Debcpy[i]=Deb[j];
		}
	}
	printf("\n\n*Depois dos cálculos*\n\n");
	for(i=0;i<quantidade;i++){
		long long int tam;
		tam=TamanhoNum(contas[i]);
		printf("%20.lld",contascpy[i]);
		/*for(;20-tam>0;tam++)
			printf(" ");*/
		printf("  %6.c      %4.2f %4.2f\n",tipocpy[i],Credcpy[i],Debcpy[i]);
	}
	return 0;
}
	
	

long long int TamanhoNum(long long int num1){
	int Tamanho=0;
	while(num1>0){
		num1/=10;
		Tamanho++;
	}
	return Tamanho;
}

long long int RemoverZeroDireita(long long int num){
	while(num%10==0)
		num/=10;
	return num;
}

void ordenarVetor(long long int *vetor, int tamanho,long long int *conta1, char *tipo1,float *Cred1,float *Deb1){
	int i,j;
	for(i=0;i<tamanho;i++){
		for(j=0;j<tamanho;j++){
			int aux;
			char auxChar;
			float auxFloat;
			if(vetor[i]<vetor[j]){
				aux=vetor[i],vetor[i]=vetor[j],vetor[j]=aux;
				aux=conta1[i],conta1[i]=conta1[j],conta1[j]=aux;
				auxChar=tipo1[i],tipo1[i]=tipo1[j],tipo1[j]=auxChar;
				auxFloat=Cred1[i],Cred1[i]=Cred1[j],Cred1[j]=auxFloat;
				auxFloat=Deb1[i],Deb1[i]=Deb1[j],Deb1[j]=auxFloat;
			}			
		}
	}
}

void CalcularAnaliticas(int tamanho,long long int *conta,char *tipo1,float *Cred1, float *Deb1){
	int i,j;
	for(i=tamanho-1;i>-1;i--){
		if(tipo1[i]=='A'){
			long long int tam1,tam2;
			tam1=TamanhoNum(conta[i]);
			for(j=i+1;j<tamanho;j++){
				tam2=TamanhoNum(conta[j]);
				if((tam2==tam1+1)&&(conta[j]/10==conta[i])){
					Cred1[i]+=Cred1[j],Deb1[i]+=Deb1[j];
				}
			}
		}
	}
}
