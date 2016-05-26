/* este é o .c principal. este programa deve ser compilado com o comando make com o terminal na mesma pasta deste. O .o gerado está na pasta .obj e para execução, deve-se chamar o comando ./simulacao no terminal*/

/* Aluno: Ingrid Santana Lopes - 14/0083065
Universidade de Brasilia
Organização e Arquitetura de Computadores - 1/2016
Professor: Ricardo Jacobi */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "simulador.h"


int main (){
	pc = 0, ri=0, hi =0, lo=0;
	int start=0, end=0, resposta=0, sys=0;
	char format='\0';
	system(CLEAR); /*limpa terminal para melhor visualização da execução do programa*/

	pegaHexa();

	while(resposta!=5){
		printf("\nO que deseja fazer? \n\t1-step() => fetch(), decode(), execute()\n\t 2-run() \n\t 3 - dump_mem\n\t4 - dump_reg\n\t5 - Sair\n_");
		format='\0';
		scanf("%d", &resposta);
		switch(resposta){
			case 1: if(pc<MEM_SIZE/2 && sys!=2){
					sys=step(); 
				}
				else
					printf("Todas as instruções já foram lidas e efetuadas");
			break;
			case 2: run(); break;
			case 3: 
				do {	
					getchar();
					printf("\nDigite em decimal a posição que deseja usar como 'start'\n");
					scanf("%d", &start);
					printf("\nDigite em decimal a posição que deseja usar como 'end'\n");
					scanf("%d", &end);
					if (start<0 || end >= MEM_SIZE || start>=MEM_SIZE||end<0){
						printf("Tamanho inválido");
						break;
					}
					
					getchar();
					printf("\nDigite o formato de impressão \n\t'h' - hexa, 'd' - decimal'\n");
					scanf("%c", &format);
					if ((format != 'h') &&  (format != 'H') && (format != 'd') && (format != 'D' ))
						printf("Formato inválido");
					else
						dump_mem(start,end,format);

				}while((start<=0) && (end >= MEM_SIZE) && (format != 'h') &&  (format != 'H') && (format != 'd') && (format != 'D' ));
				break;
			case 4:
				do {
					getchar();
					printf("\nDigite o formato de impressão \n\t'h' - hexa, 'd' - decimal'\n");
					scanf("%c", &format);
					if ((format != 'h') &&  (format != 'H') && (format != 'd') && (format != 'D' ))
						printf("Formato inválido");

					else
						dump_reg(format);
				}while((format != 'h') &&  (format != 'H') && (format != 'd') && (format != 'D' ));
			break;
			case 5: break;
			default: printf("\nOpção inválida\n"); break;
		} 
	}


printf("\n");

return 0;
}
