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


int32_t lw(uint32_t address, int16_t kte){
	int32_t resultado=0;
	if ((kte)%4!=0){
		printf("ERRO: kte + address deve ser um número multiplo de 4");
		exit(EXIT_FAILURE);
	}
	
	resultado=(mem[(kte)/4+reg[address]/4]);

return resultado;
}


void sw(uint32_t address, int16_t kte, int32_t dado){
	if ((address+kte)%4!=0){
		printf("ERRO: kte + address deve ser um número multiplo de 4");
		exit(EXIT_FAILURE);
	}
	mem[(address+kte)/4]=(int32_t)dado;

}

int32_t lh (uint32_t address, int16_t kte){
	int32_t resultado=0, aux=0;
	if ((kte)%2!=0){
		printf("ERRO: kte + address deve ser um número multiplo de 2");
		exit(EXIT_FAILURE);
	}
	if((kte)%4 == 0){
		resultado = (int32_t) ((mem[(kte)/4+reg[address]/4]) & 0x0000ffff);
		if(resultado>= 0x00008000){ /*consideração quanto aos números negativos*/
		aux=resultado;
		aux = aux | 0xffff0000;
		resultado=aux;
		}
	}
	else{
		resultado = (int32_t) ((mem[(kte)/4+reg[address]/4]) & 0xffff0000);
		if(resultado>= 0x80000000){ /*consideração quanto aos números negativos*/
		aux=resultado;
		aux = aux | 0x0000ffff;
		resultado=aux;
		}
		resultado  = resultado >> 16;
	}
	
return resultado;
}

int32_t lhu (uint32_t address, int16_t kte){
	int32_t resultado=0;
	if ((kte)%2!=0){
		printf("ERRO: kte + address deve ser um número multiplo de 2");
		exit(EXIT_FAILURE);
	}
	if((kte)%4 == 0){
		resultado = (int32_t) ((mem[(kte)/4+reg[address]/4]) & 0x0000ffff);
	}
	else{
		resultado = (int32_t) ((mem[(kte)/4+reg[address]/4]) & 0xffff0000);
		resultado  = resultado >> 16;
	}
return resultado;
}

void sh(uint32_t address, int16_t kte, int16_t dado){
	int32_t resto=0, fica=0;
	if ((address+kte)%2!=0){
	printf("ERRO: kte + address deve ser um número multiplo de 2");
		exit(EXIT_FAILURE);
	}
	if((kte)%4 == 0){
		resto = (int32_t) mem[(address + kte)/4] & 0xffff0000;
		fica = (int32_t) dado & 0x0000ffff;
		mem[(address + kte)/4] = (int32_t) resto+fica; /*consideração quanto a sobreposição*/
	}
	else{
		mem[(address + kte)/4] = mem[(address + kte)/4] >> 16;
		resto = (int32_t) mem[(address + kte)/4] & 0x0000ffff;
		fica = (int32_t) dado & 0xffff0000; /*consideração quanto a sobreposição*/
		mem[(address + kte)/4] = (int32_t) resto+fica;
	}
}

int32_t lb (uint32_t address, int16_t kte){
	int32_t resultado=0,aux=0;
	if((kte)%1 != 0){
		printf("ERRO. kte + address deve ser um número multiplo de 1");
		exit(EXIT_FAILURE);
	}

	if((kte)%4 == 0){
		resultado = (int32_t) (mem[(address+kte)/4] & 0x000000ff);
		if(resultado>= 0x00000080){ /*consideração quanto as números negativos*/
			aux=resultado;
			aux = aux | 0xffffff00;
			resultado=aux;
		}
	}
	else if((kte)%4 == 1){
		resultado = (int32_t) (mem[(address+kte)/4] & 0x0000ff00);
		if(resultado>= 0x00008000){ /*consideração quanto as números negativos*/
			aux=resultado;
			aux = aux | 0xffff00ff;
			resultado=aux;
		}
		resultado = resultado >> 8;
	}
	else if((kte)%4 == 2){
		resultado = (int32_t) (mem[(address+kte)/4] & 0x00ff0000);
		if(resultado>= 0x00800000){ /*consideração quanto as números negativos*/
			aux=resultado;
			aux = aux | 0xff00ffff;
			resultado=aux;
		}
		resultado = resultado >> 16;
	}
	else{
		resultado = (int32_t) (mem[(address+kte)/4] & 0xff000000);
		if(resultado>= 0x80000000){ /*consideração quanto as números negativos*/
			aux=resultado;
			aux = aux | 0x00ffffff;
			resultado=aux;
		}
		resultado = resultado >> 24;	
	}



return resultado;
}
int32_t lbu (uint32_t address, int16_t kte){
	int32_t resultado=0;
	if((kte)%1 != 0){
		printf("ERRO. kte + address deve ser um número multiplo de 1");
		exit(EXIT_FAILURE);
	}

	if((kte)%4 == 0){
		resultado = (int32_t) ((mem[(kte)/4+reg[address]/4]) & 0x000000ff);
		
	}
	else if((kte)%4 == 1){
		resultado = (int32_t) ((mem[(kte)/4+reg[address]/4]) & 0x0000ff00);
		resultado = resultado >> 8;
	}
	else if((kte)%4 == 2){
		resultado = (int32_t) ((mem[(kte)/4+reg[address]/4]) & 0x00ff0000);
		resultado = resultado >> 16;
	}
	else{
		resultado = (int32_t) ((mem[(kte)/4+reg[address]/4]) & 0xff000000);
		resultado = resultado >> 24;	
	}
return resultado;
}

void sb(uint32_t address, int16_t kte, int8_t dado){
	int resto=0, fica=0;
	if((kte)%1 != 0){
		printf("ERRO. kte + address deve ser um número multiplo de 1");
		exit(EXIT_FAILURE);
	}

	if((kte)%4 == 0){
		resto = (int32_t) mem[(address+kte)/4] & 0xffffff00;
		fica = (int32_t) dado & 0x000000ff; /*consideração quanto a sobreposicao*/
		mem[(address + kte)/4] = (int32_t) resto + fica;	
	}
	else if((kte)%4 == 1){
		mem[(address+kte)/4] = (int32_t) mem[(address+kte)/4] << 8;
		resto = (int32_t) mem[(address+kte)/4] & 0xffff00ff; /*consideração quanto a sobreposicao*/
		fica = (int32_t) dado & 0x0000ff00;
		mem[(address+kte)/4] =(int32_t) resto + fica;
	}
	else if((kte)%4 == 2 ){
		mem[(address+kte)/4] = (int32_t) mem[(address+kte)/4] << 16;
		resto = (int32_t) mem[(address+kte)/4] & 0xff00ffff; /*consideração quanto a sobreposicao*/
		fica = (int32_t) dado & 0x00ff0000;
		mem[(address+kte)/4] =(int32_t) resto + fica;
	}
	else{
		mem[(kte)/4] = (int32_t) mem[(address+kte)/4] << 24;
		resto = (int32_t) mem[(address+kte)/4] & 0x00ffffff; /*consideração quanto a sobreposicao*/
		fica = (int32_t) dado & 0xff000000;
		mem[(address+kte)/4] =(int32_t) resto + fica;
	}
}

void addi (int rs, int rt, int Imm){
	if (Imm > MEM_SIZE*4){
  		Imm= (Imm | 0xffff0000);
	}
	reg[rt] = (reg[rs] + Imm);
	/*if(resultado>= 0x08000000) 
		aux=resultado;
	reg[rt]= aux | 0xffff0000;*/
}

void add (int rs, int rt, int rd){
	reg [rd] = reg[rt]+reg[rs];
}

void sub (int rs, int rt, int rd){
	reg [rd] = reg[rs]-reg[rt];
}

void or (int rs, int rt, int rd){
	reg [rd] = (reg[rs] | reg[rt]);
}

void ori (int rs, int rt, int k16){
	reg [rt] = (reg[rs] | k16);
}

void and (int rs, int rt, int rd){
	reg [rd] = (reg[rs] & reg[rt]);
}

void andi (int rs, int rt, int k16){
	reg [rt] = (reg[rs] & k16);
}

void Div (int rs, int rt){
	lo = (reg[rs]/reg[rt]);
	hi = reg[rs]%reg[rt];
}
void mult (int rs, int rt){

	hi = (((long long )rs*rt >>32) & 0xffffffff);
	lo = reg[rs]*reg[rt];
}
void xor (int rs, int rt, int rd){
	reg[rd] = ((~reg[rs])&reg[rt]) | (reg[rs]&(~reg[rt]));
}

void nor (int rs, int rt, int rd){
	reg [rd] = ~(reg[rs] | reg[rt]);
}

void xori (int rs, int rt, int k16){
	reg[rt] = ((~reg[rs])&k16) | (reg[rs]&(~k16));
}
void mflo (int rd){
	reg[rd] = lo;
}
void mfhi (int rd){
	reg[rd] = hi;
}
void jr (int rs){
	if (reg[rs]<MEM_SIZE/2){
		pc = reg[rs];
	}
}
void j (int k26){
	pc = k26;
}
void jal(int k26){
	reg[31] = pc;
	pc = k26;
}
void bne(int rs, int rt, int k16){
 	if ((reg[rs] != reg[rt]) & (k16!=0)) {
		pc += (k16);
	}

}
void beq(int rs, int rt, int k16){
 	if ((reg[rs] == reg[rt]) & (k16!=0)) {
		pc += (k16);
	}

}

void slt(int rs,int rt,int rd){
	if(reg[rs]<reg[rt])
		reg[rd]=1;
	else
		reg[rd]=0;
}
void slti(int rs,int rt,int k16){
	if(reg[rs]<k16)
		reg[rt]=1;
	else
		reg[rt]=0;
}

void lui (int rt, int k16){
	reg[rt] = ((k16<<16)|0x0000);

}
void bgtz(int rs, int k16){
	if (k16 > MEM_SIZE*4){
  		k16= (k16 | 0xffff0000);
	}
	printf(">>%d %d %d",k16, pc, reg[rs]);
 	if ((reg[rs] >0) & (k16!=0)) {
		/*k16 = k16 | 0xffff0000;*/
		pc += (k16);
	}

}
void blez(int rs, int k16){
	if (k16 > MEM_SIZE*4){
  		k16= (k16 | 0xffff0000);
	}
 	if ((reg[rs] <= 0)) {
		/*k16 = k16 | 0xffff0000;*/
		pc += (k16);
	}

}

void sltiu(int rs,int rt,int k16){
	if((uint32_t) reg[rs]< (uint16_t) k16)
		reg[rt]=1;
	else
		reg[rt]=0;
}
void srl (int rd, int rt, int shamt){
	reg [rd]=(uint32_t) (reg[rt]>>shamt);
}

void sll (int rd, int rt, int shamt){
	reg [rd]=(uint32_t) (reg[rt]<<shamt);
}
void sra (int rd, int rt, int shamt){
	reg [rd]=(reg[rt]>>shamt);
}


int syscall(){
	int c='\0';
	int end;
	if(reg[2]==10){
		printf("\nsyscall\n>>>>>>>>Terminate program.");	
		
		return 2;
	}
	if(reg[2]==1){
		printf("\nsyscall\n");
		printf(">>>>>>>>%d", reg[4]);
	}
	if(reg[2]==4){
		printf("\n\n>>>>>>>>");
		end = reg[4];
		c = lb(end,0);
		printf("%c",c);
		while(c!='\0') {
			c = lb(end,1);
			printf("%c",c);
			c = lb(end,2);
			printf("%c",c);
			c = lb(end,3);
			printf("%c",c);
			end+=4;
			c = lb(end,0);
			printf("%c",c);
		}
	}
return 0;
}

int execute(){
	int result=0;
	
	switch(opcode){
	case LW:
		printf("\nlw $%d , 0x%d($%.8d)",rt,k16,rs);
		reg[rt]=lw(rs, k16);
		break;
	case LH: 
		printf("\nlh $%d , 0x%x($%.8x)",rt,k16,rs);
		reg[rt] = lh (rs,k16);
		break;
	case LHU:
		printf("\nlhu $%d , 0x%x($%.8x)",rt,k16,rs);
		reg[rt]= lhu (rs,k16);
		break;
	case LB: 
		printf("\nlb $%d , 0x%x($%.8x)",rt,k16,rs);
		reg[rt]= lb (rs,k16);
		break;
	case LBU: 
		printf("\nlbu $%d , 0x%x($%.8x)",rt,k16,rs);
		reg[rt] = lbu (rs,k16);
		break;
	case SW: 
		printf("\nsw $%d , 0x%x($%d)",rt,k16,rs);
		sw(reg[rs], k16, reg[rt]);
		break;
	case SH: 
		printf("\nsh $%d , 0x%x($%d)",rt,k16,rs);
		sh(reg[rs], k16, reg[rt]);
		break;
	case SB: 
		printf("\nsb $%d , 0x%x($%d)",rt,k16,rs);
		sb(reg[rs], k16, reg[rt]);
		break;
	case ADDI:
		printf("\naddi $%d, $%d, %d", rt, rs, k16);
		addi(rs,rt,k16);
	break;
	case ORI:
		printf("\nori $%d, $%d, %d", rt, rs, k16);
		ori(rs,rt,k16);
	break;
	case ANDI:
		printf("\nandi $%d, $%d, %d", rt, rs, k16);
		andi(rs,rt,k16);
	break;
	case XORI:
		printf("\nxori $%d, $%d, %d", rt, rs, k16);
		xori(rs,rt,k16);
	break;
	case J:
		printf("\nj $%.8x",k26);
		j(k26);
	break;
	case JAL:
		printf("\njal $%.8x",k26);
		jal(k26);
	break;
	case BNE:
		printf("\nbne $%d, $%d, %d", rt, rs, k16);
		bne(rs,rt,k16);
	break;
	case BEQ:
		printf("\nbeq $%d, $%d, %d", rs, rt, k16);
		beq(rs,rt,k16);
	break;
	case BGTZ:
		printf("\nbgtz $%d, %d", rs, k16);
		bgtz(rs,k16);
	break;
	case BLEZ:
		printf("\nblez $%d, %d", rs, k16);
		blez(rs,k16);
	break;
	case SLTI:
		printf("\nslti $%d, $%d, %d", rt, rs, k16);
		slti(rs,rt,k16);
	break;
	case SLTIU:
		printf("\nsltiu $%d, $%d, %d", rt, rs, k16);
		sltiu(rs,rt,k16);
	break;

	case LUI:
		printf("\nlui $%d, $%d", rt,k16);
		lui(rt,k16);
	break;
	case EXT:
		switch(funct){
		case ADD:
			printf("\nadd $%d, $%d, $%d", rd, rs, rt);
			add(rs,rt,rd);
		break;	
		case OR:
			printf("\nor $%d, $%d, $%d", rd, rs, rt);
			or(rs,rt,rd);
		break;
		case AND:
			printf("\nand $%d, $%d, $%d", rd, rs, rt);
			and(rs,rt,rd);
		break;
		case SUB:
			printf("\nsub $%d, $%d, $%d", rd, rs, rt);
			sub(rs,rt,rd);
		break;
		case DIV:
			printf("\ndiv $%d, $%d", rs, rt);
			Div(rs,rt);
		break;
		case MULT:
			printf("\nmult $%d, $%d",rs, rt);
			mult(rs,rt);
		break;
		case XOR:
			printf("\nxor $%d, $%d, $%d", rd, rs, rt);
			xor(rs,rt,rd);
		break;
		case NOR:
			printf("\nnor $%d, $%d, $%d", rd, rs, rt);
			nor(rs,rt,rd);
		break;
		case MFLO:
			printf("\nmflo $%d", rd);
			mflo(rd);
		break;	
		case MFHI:
			printf("\nmfhi $%d", rd);
			mfhi(rd);
		break;
		case JR:
			printf("\njr $%d", rs);
			jr(rs);
		break;
		case SLT:
			printf("\nslt $%d, $%d, $%d", rd, rs, rt);
			slt(rs,rt,rd);
		break;
		case SRL:
			printf("\nsrl $%d, $%d, %d", rd, rt, shamt);
			srl(rd,rt,shamt);
		break;	
		case SLL:
			printf("\nsll $%d, $%d, %d", rd, rt, shamt);
			sll(rd,rt,shamt);
		break;
		case SRA:
			printf("\nsra $%d, $%d, %d", rd, rt, shamt);
			sra(rd,rt,shamt);
		break;
		case SYSCALL:
			result = syscall();
			if (result == 2)
				return result;
		break;	
		}
	break;
		
	default: break;

	}
return result;
}
int step () {
	int i =0;
	fetch();
	decode();
	i=execute();
return i;
}

void decode (){

	opcode = (ri>>26) & 0x3f; 
	rs = (ri>>21) & 0x1f;
	rt = (ri>>16) & 0x1f;
	rd = (ri>>11) & 0x1f;
	shamt = (ri>>6) & 0x1;
	funct = (ri>>0) & 0x3f;
	k16 = (ri>>0) & 0xFFFF;
	k26 = (ri>>0) & 0x3FFFFFF;
}

void fetch(){
	ri = mem[pc];
	if(pc+4!=MEM_SIZE)
 	pc++;
}
void run(){
	int i = 0;
	
	while(pc<MEM_SIZE/2){
		i = step();
		if (i==2 || ((opcode ==0) && (funct == 0) && (rs==0) && (rt==0) && (rd==0) && (shamt==0)))
			break;
	}
}

void pegaHexa (){
	int contador_universal=0;
	FILE *fpt = fopen ("text.bin","rb");
	if (!fpt){
		printf("Erro ao abrir arquivo");
		exit(1);
	}

	fseek(fpt,0, SEEK_END);
	int tam_textt = ftell(fpt), i, j;
	fseek (fpt,0,SEEK_SET);

	int instt[tam_textt];
	fread(instt,sizeof(instt)/4,1,fpt);
	printf("Aperte qualquer tecla para ver text.bin");
	getchar();
	printf("TEXT.BIN\n");
	for (i=0, j=0; j<sizeof(instt)/4;i++){
		printf("0x%.8x ",instt[i]); /*imprime hexadecimais encontrados em text.bin*/

		mem[contador_universal] = instt[i];
		contador_universal++;
		j+=4;
	}

	fclose(fpt);

	while(contador_universal!=MEM_SIZE/2){ /*considera que a área para text tem que ir até MEM_SIZE/2*/
		contador_universal++;
		mem[contador_universal] = '\0';
	}

	FILE *fpd = fopen ("data.bin","rb");
	if (!fpd){
		printf("Erro ao abrir arquivo");
		exit(1);
	}

	fseek(fpd,0L, SEEK_END);
	int tam_textd = ftell(fpd);

	fseek (fpd,0L,SEEK_SET);
	int instd[tam_textd];
	fread(instd,sizeof(instd)/4,1,fpd);
	printf("\nAperte qualquer tecla para ver data.bin");
	getchar();
	printf("\nDATA.BIN\n");
	for (i=0, j=0; j<sizeof(instd)/4;i++){
		printf("0x%.8x ",instd[i]); /*imprime hexadecimais encontrados em data.bin*/
		if (contador_universal<MEM_SIZE ||contador_universal==MEM_SIZE ){
			mem[contador_universal] = instd[i];
			contador_universal++;
		}
		j+=4;
	}
	while(contador_universal!=MEM_SIZE){ /*considera que memória deve ir até MEM_SIZE*/
		contador_universal++;
		mem[contador_universal] = '\0';
	}
	fclose(fpd);
}
void dump_mem (int start, int end, char format){
	int i;
	FILE *fp = fopen("memory.bin","wb+");
	if(!fp){
		printf("Erro ao abrir arquivo\n");
		exit(1);
	}
	for (i=start; i<end;i++){
		if (format == 'h'||format=='H')
			fprintf(fp,"%.8x ",mem[i]);
		else
			fprintf(fp,"%.8d ",mem[i]);
	}
	fclose (fp);


}
void dump_reg (char format){
	
	int i;
	FILE *fp = fopen("registers.bin","wb+");
	if(!fp){
		printf("Erro ao abrir arquivo\n");
		exit(1);
	}
	for (i=0; i<32;i++){
		if (format == 'h'||format=='H')
			fprintf(fp,"%.8x ",reg[i]);
		else
			fprintf(fp,"%.8d ",reg[i]);
	}
	if (format == 'h'||format=='H')
			fprintf(fp,"%.8x ",pc*4);
		else
			fprintf(fp,"%.8d ",pc*4);
	if (format == 'h'||format=='H')
			fprintf(fp,"%.8x ",hi);
		else
			fprintf(fp,"%.8d ",hi);
	if (format == 'h'||format=='H')
			fprintf(fp,"%.8x ",lo);
		else
			fprintf(fp,"%.8d ",lo);
	fclose (fp);
}
