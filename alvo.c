#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>

int MMC(int numeros[],int num);
void splash();

int main(){
	setlocale(LC_ALL,"Portuguese");
	splash();
	int Obestaculos[50],quantidadeObestaculos,i,tempo,DetectarTecla;
	printf("***O número de obestáculos deve ser entre 1 e 50***\n***  0 obestáculos o programa é encerrado***\n\n");
	do{
		do{ 																		/* O laço de repetição impedi que valores que não estão na faixa exigida pela questão sejam inseridos.*/
			printf("Quantidade de obestáculos: ");
			scanf("%i",&quantidadeObestaculos);
		}while((quantidadeObestaculos<0)||(quantidadeObestaculos>50));
		system("cls");
		switch(quantidadeObestaculos){
			case 0:
				printf("O programa foi encerrado!");
				break;
			default:
				quantidadeObestaculos-=1;
				printf("Tempo de cada obestáculo (digite um tempo entre 1 e 30 segundos):\n");
				for(i=0;i<=quantidadeObestaculos;i++){
					do{
						printf("Tempo %i° obestáculo: ",i+1);
						scanf("%i",&Obestaculos[i]);
						
					}while((Obestaculos[i]<1)||(Obestaculos[i]>30));                        /* O laço de repetição impedi que valores que não estão na faixa exigida pela questão sejam inseridos.*/
				}
				system("cls");
				tempo=MMC(Obestaculos,quantidadeObestaculos);
				printf("O Tempo mínimo para o o alvo ser atingido é: %i segundos.\n",tempo);
				printf("\nPara continuar executando o programa aperte 'Enter'.\nFinalizar- Qualquer outra tecla.");
				DetectarTecla=getch();
				system("cls");
		}
	}while(DetectarTecla==13);
	return 0;
}

int MMC(int numeros[],int num){
	int acumulador=1,i,div[4]={0,0,0,0};
	do{
		for(i=0;i<4;i++)
			div[i]=0;
		for(i=0;i<=num;i++){
			if(numeros[i]%2==0)
				div[0]+=1;
			if(numeros[i]%3==0)
				div[1]+=1;
			if(numeros[i]%5==0)
				div[2]+=1;
			if(numeros[i]%7==0)
				div[3]+=1;
		}
		if(div[0]>0){
			for(i=0;i<=num;i++){
				if(numeros[i]%2==0)
					numeros[i]/=2;
			}
			acumulador*=2;
		}else{
			if(div[1]>0){
				for(i=0;i<=num;i++){
					if(numeros[i]%3==0)
					numeros[i]/=3;
				}
				acumulador*=3;	
			}else{
				if(div[2]>0){
					for(i=0;i<=num;i++){
						if(numeros[i]%5==0)
							numeros[i]/=5;
					}
					acumulador*=5;
				}else{
					if(div[3]>0){
						for(i=0;i<=num;i++){
							if(numeros[i]%7==0)
							numeros[i]/=7;
						}
						acumulador*=7;
					}else{
						return acumulador;
					}
				}
			}
		}
	}while(1);
}


void splash(){
	printf("SALVE O PLANETA TERRA DESTRUINDO O ALVO ATRÁS DOS OBESTÁCULOS! \n\n");
	printf("                                                                                                    \n                                                                                                    \n                                                                                                    \n                                                                                                    \n                                                                                                    \n                                                 ::.                                                \n                                                 BX2SX22r:.                                         \n                                                 rX...ir72XXS7:                                     \n                                   ::.            B:.    ...i72X2r                                  \n                                .2MMB7            2X.. ..      .i7S2:                               \n                                BB8BX              Bi: ... .7222222SSS.                             \n                        .       7::ir              rM..   707::...:rS20r                            \n      ..             rBBB:  iSBB .:i7BBB7           82.  20..:.:::...X7M.                           \n .XBBBBBBBBBXr.     7B0r077XBBBBr 0BBBBMB7           Br..M..:::::::i..07X       .....               \n0BBBBBBBBBBBBBBBBBBMBBB0X2.. .MB2XB2..  .ii.         .B::M ..:::.:.:..07X    :i7722XX0X2r           \n   7BBBMMMBBBBBBBBM ...  .i.. :7rM. ...i:.:i:         :M:0r :iri::i. 7SS7  .::i:iir772SXMMX.        \n     2BBMM8MMBBBBB.      :7... 77r ..:r7ir:::i:        :87X7.:::.:::7X20  ...:..:iir77722X8B2       \n      .BBBMMM8MMBB7727772Z7i77. .r772272X77:.72X2        SXX27riir72XS2  .....::::ri777722SXB8      \n        BBMMMM8MMBBBBBBBBBBX.ii 7iirr722: ..:22M7         :7S0080Z0S7.  ...:...i::7rr777722SXBM     \n         BBMMMM8MMBBBBBBBBBB7::.2i:..i.  27:2S2.              ..:.    ....::::..::r7r7772222X0B7    \n          BBMMMM8M8MMMMM8BBBB..:ir2i.XX:MBBB2.                       :::...::ii:.:irr777722XX8BM    \n          .BBMMMBMMMM8MMBMBB2 . ::.  BBBZr.                         .r:::::::.:::ir7777722XXXXBB    \n           7BBMMMBBBMBMBMBBBS        8S                             .2riii:i:ii7rr777222722X22X0    \n            7BBBBBBBBBBBBBBB7rBBBBB0772                              227rrrirr7777772227772S770i    \n              XBBBBBBBBBBBBr ..BBB7: ..7                             :X277777777727222727272722     \n                :28BBBBBBM2...:27i27..:r7                             70XS22222222S22727777722      \n                           i:.77  .0r:::2                              rMB0XSSSXXXS272777772r       \n                           r.:X.    7i::7                                2BBB88002222727227.        \n                           27Xi      7ii2.                                 78BBBB800XX27i.          \n                           2X7        :2S2                                    .iir7i:.              \n                           2:2.        .02::                                                        \n                          ..:X.         22.i.                                                       \n                          .2M2          .877:                                                       \n                          SB2            .BB.                                                       \n                         .B7               B2                                                       \n                       :BBBi               BBr                                                      \n                       .:.                7BB2                                                      \n                                                                                                    \n                                                                                                    \n                                                                                                    \n");
	printf("\n\n\n");
	system("Pause");
	system("cls");
}
