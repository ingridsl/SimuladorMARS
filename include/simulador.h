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

#ifdef _WIN64
#define CLEAR "cls" /*windows*/
#else
#define CLEAR "clear" /*linux e mac*/
#endif

#ifndef SIMULADOR_H
#define SIMULADOR_H

/*definição do tamanho da memória da simulação e da quantidade de registradores e outras variaveis necessarias*/
#define MEM_SIZE 4096
int32_t mem[MEM_SIZE];
int32_t reg[32];
uint32_t pc, ri, hi, lo;
int opcode,rs,rt,rd,shamt,funct,k16, k26;

/*definição das instruções que são possíveis de serem simuladas considerando o opcode de cada uma de acordo com o MIPS*/
#define LW 0x23 				/*ok*/
#define LH 0x21					/*ok*/
#define LHU 0x25				/*ok*/
#define LB 0x20					/*ok*/
#define LBU 0x24				/*ok*/
#define SW 0x2B					/*ok*/
#define SH 0x29					/*ok*/
#define SB 0x28					/*ok*/
#define SYSCALL 0x0C				/*ok*/
#define EXT 0x00				/*ok*/			
#define BLEZ 0x06				/*ok*/		
#define SLTIU 0x0B				/*ok*/	 	
#define J 0x02					/*ok*/
#define ADD 0x20				/*ok*/
#define OR 0x25  				/*ok*/
#define SLL 0x00	 			/*ok*/
#define BGTZ 0x07 				/*ok*/
#define ANDI 0x0C				/*ok*/	
#define JAL 0x03				/*ok*/
#define LUI 0x0F				/*ok*/
#define BEQ 0x04				/*ok*/
#define ADDI 0x08				/*ok*/
#define ORI 0x0D				/*ok*/
#define BNE 0x05				/*ok*/
#define SLTI 0x0A				/*ok*/
#define XORI 0x0E				/*ok*/			
#define SUB 0x22				/*ok*/
#define XOR 0x26				/*ok*/ 	
#define SRL 0x02				/*ok*/
#define MULT 0x18				/*ok*/
#define NOR 0x27				/*ok*/	
#define SRA 0x03				/*ok*/
#define DIV 0x1A				/*ok*/	
#define AND 0x24				/*ok*/	
#define SLT 0x2A				/*ok*/
#define JR 0x08					/*ok*/
#define MFHI 0x10				/*ok*/
#define MFLO 0x12				/*ok*/

/*simulação da função de load word*/
int32_t lw(uint32_t address, int16_t kte);

/*simulação da função de store word*/
void sw(uint32_t address, int16_t kte, int32_t dado);

/*simulação da função de load half word*/
int32_t lh (uint32_t address, int16_t kte);

/*simulação da função de load half word unsigned*/
int32_t lhu (uint32_t address, int16_t kte);

/*simulação da função de store half word*/
void sh(uint32_t address, int16_t kte, int16_t dado);

/*simulação da função de load byte*/
int32_t lb (uint32_t address, int16_t kte);

/*simulação da função de load byte unsigned*/
int32_t lbu (uint32_t address, int16_t kte);

/*simulação da função de store byte*/
void sb(uint32_t address, int16_t kte, int8_t dado);

void addi (int rs, int rt, int Imm);

void add (int rs, int rt, int rd);

void sub (int rs, int rt, int rd);

void or (int rs, int rt, int rd);

void ori (int rs, int rt, int k16);

void and (int rs, int rt, int rd);

void andi (int rs, int rt, int k16);

void Div (int rs, int rt);

void mult (int rs, int rt);

void xor (int rs, int rt, int rd);

void nor (int rs, int rt, int rd);

void xori (int rs, int rt, int k16);

void mflo (int rd);

void mfhi (int rd);

void jr (int rs);

void j (int k26);

void jal(int k26);

void bne(int rs, int rt, int k16);

void beq(int rs, int rt, int k16);

void slt(int rs,int rt,int rd);

void slti(int rs,int rt,int k16);

void lui (int rt, int k16);

void bgtz(int rs, int k16);

void blez(int rs, int k16);

void sltiu(int rs,int rt,int k16);

void srl (int rd, int rt, int shamt);

void sll (int rd, int rt, int shamt);

int syscall();

int execute ();

int step();

void decode ();

void fetch();

void run();

void pegaHexa ();

void dump_mem (int start, int end, char format);

void dump_reg (char format);

#endif
