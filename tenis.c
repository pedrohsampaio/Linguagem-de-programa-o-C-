#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void ImprimirPlacar(int *ptr1,int *ptr2,unsigned int quantidadePartida);
void MudarPlacar(int *Placar1,int *Placar2,int *Pontos1,int *Pontos2,unsigned int quantidadePartida);

int main(){
	setlocale(LC_ALL,"Portuguese");
	unsigned int NumeroPartida,i,j,diferenca,soma1=0,soma2=0;
	do{
		printf("Quantidade de partidas anotadas?");
		scanf("%u",&NumeroPartida);	
	}while(NumeroPartida>201);
	int Jogador1[201*8]={0},Jogador2[201*8]={0},setJog1=0,setJog2=0,PlacarJogador1[NumeroPartida],PlacarJogador2[NumeroPartida];
	for(i=0;i<NumeroPartida;i++){
		system("cls");
		do{
			printf("Sets que foram ganhos pelo primeiro jogador? ");
			scanf("%i",&setJog1);
		}while((setJog1>4)||(setJog1<0));
		do{
			printf("Sets que foram ganhos pelo segundo jogador? ");
			scanf("%i",&setJog2);
		}while((setJog2>4)||(setJog2<0));
		PlacarJogador1[i]=setJog1,PlacarJogador2[i]=setJog2;
		system("cls");
		printf("Insira os placares: *Formato de escrita: [Pontos1/Pontos2]*\n\n");
		for(j=0;j<setJog1+setJog2;j++){
			do{
				printf("%i° set:",j+1);
				scanf("%i/%i",&Jogador1[(7*i)+j+i],&Jogador2[(7*i)+j+i]);
				diferenca=Jogador1[(7*i)+j+i]-Jogador2[(7*i)+j+i];
				diferenca*=(diferenca>0)?1:-1;
				if((Jogador1[(7*i)+j+i]==-1)&&((Jogador2[(7*i)+j+i]>-1)&&(Jogador2[(7*i)+j+i]<21)))
					break;
				else{
					if((Jogador2[(7*i)+j+i]==-1)&&((Jogador1[(7*i)+j+i]>-1)&&(Jogador1[(7*i)+j+i]<21)))
						break;
					else{
						if((Jogador2[(7*i)+j+i]==-1)&&(Jogador1[(7*i)+j+i]==-1))
							break;	
					}	
				}
			}while((Jogador1[(7*i)+j+i]>20)||((Jogador1[(7*i)+j+i]<9)&&(Jogador1[(7*i)+j+i]>-1))||(Jogador2[(7*i)+j+i]>20)||((Jogador2[(7*i)+j+i]<9)&&(Jogador2[(7*i)+j+i]>-1))&&(diferenca<2)&&(j<setJog1+setJog2));
		}
	}
	system("cls");
	printf("Digitado inicialmente: \n");
	ImprimirPlacar(Jogador1,Jogador2,NumeroPartida);
	MudarPlacar(PlacarJogador1,PlacarJogador2,Jogador1,Jogador2,NumeroPartida);
	printf("\nPlacares Finais:\n");
	ImprimirPlacar(Jogador1,Jogador2,NumeroPartida);
	printf("\n\nPontuações: \n");
	for(i=0;i<NumeroPartida;i++){
		printf("\n%i° Partida:\n",i+1);
		for(j=0;j<8;j++){
			soma1+=Jogador1[(7*i)+j+i],soma2+=Jogador2[(7*i)+j+i];
		}
		printf("1° jogador: %u.\n2° jogador: %u.\n",soma1,soma2);
		soma1=0,soma2=0;
	}
	system("Pause");
	return 0;
}

void ImprimirPlacar(int *ptr1,int *ptr2,unsigned int quantidadePartida){
	int i,j;
	for(i=0;i<quantidadePartida;i++){
		printf("%i° Partida: \n\n",i+1);
		for(j=0;j<8;j++){
			if((ptr1[(7*i)+j+i]!=0)&&(ptr2[(7*i)+j+i]!=0))
			printf("(%i° set) [%i/%i] \n",j+1,ptr1[(7*i)+j+i],ptr2[(7*i)+j+i]);	
		}
		printf("\n\n");
	}
}

void MudarPlacar(int *Placar1,int *Placar2,int *Pontos1,int *Pontos2,unsigned int quantidadePartida){
	int i,j;
	for(i=0;i<quantidadePartida;i++){
		if(Placar1[i]>Placar2[i]){
			for(j=0;j<8;j++){ //maximiza os valores
				if((Pontos1[(7*i)+j+i]!=0)&&(Pontos2[(7*i)+j+i]!=0)){
					if((Pontos1[(7*i)+j+i]==-1)&&(Pontos2[(7*i)+j+i]<=9)&&(Pontos2[(7*i)+j+i]!=-1))
						Pontos1[(7*i)+j+i]=11;
					else{
						if((Pontos1[(7*i)+j+i]==-1)&&(Pontos2[(7*i)+j+i]==-1))
							Pontos1[(7*i)+j+i]=20,Pontos2[(7*i)+j+i]=18;
						else{
							if((Pontos1[(7*i)+j+i]==-1)&&(Pontos2[(7*i)+j+i]>11))
								Pontos1[(7*i)+j+i]=Pontos2[(7*i)+j+i]+2;
						}		
					}
				}
			}
			for(j=0;j<8;j++){
				if((Pontos2[(7*i)+j+i]==-1)&&(Pontos1[(7*i)+j+i]>=11))
					Pontos2[(7*i)+j+i]=Pontos1[(7*i)+j+i]-2;
				else{
					if((Pontos2[(7*i)+j+i]==-1)&&(Pontos1[(7*i)+j+i]<=9)&&(Pontos1[(7*i)+j+i]!=-1))
						Pontos2[(7*i)+j+i]=11;
					else{
						if((Pontos2[(7*i)+j+i]==-1)&&(Pontos1[(7*i)+j+i]==10))
							Pontos2[(7*i)+j+i]=Pontos1[(7*i)+j+i]+2;
					}
				}
			}			
		}else{
			for(j=0;j<8;j++){
				if((Pontos1[(7*i)+j+i]!=0)&&(Pontos2[(7*i)+j+i]!=0)){
					if((Pontos2[(7*i)+j+i]==-1)&&(Pontos1[(7*i)+j+i]<=9)&&(Pontos1[(7*i)+j+i]!=-1))
						Pontos2[(7*i)+j+i]=11;
					else{
						if((Pontos2[(7*i)+j+i]==-1)&&(Pontos1[(7*i)+j+i]==-1))
							Pontos2[(7*i)+j+i]=20,Pontos1[(7*i)+j+i]=18;
						else{
							if((Pontos2[(7*i)+j+i]==-1)&&(Pontos1[(7*i)+j+i]>11))
								Pontos2[(7*i)+j+i]=Pontos1[(7*i)+j+i]+2;
						}	
					}
				}
			}
			for(j=0;j<8;j++){
				if((Pontos1[(7*i)+j+i]==-1)&&(Pontos2[(7*i)+j+i]>=11))
					Pontos1[(7*i)+j+i]=Pontos2[(7*i)+j+i]-2;
				else{
					if((Pontos1[(7*i)+j+i]==-1)&&(Pontos2[(7*i)+j+i]<=9)&&(Pontos2[(7*i)+j+i]!=-1))
						Pontos1[(7*i)+j+i]=11;
					else{
						if((Pontos1[(7*i)+j+i]==-1)&&(Pontos2[(7*i)+j+i]==10))
							Pontos1[(7*i)+j+i]=Pontos2[(7*i)+j+i]+2;
					}
				}
			}
		}
	}
	
}
