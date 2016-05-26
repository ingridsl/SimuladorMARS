Universidade de Brasília
**********************************************************************
Simulador do MIPS 2
Organização e Arquitetura de Computadores 1/2016
**********************************************************************
  Ingrid Santana Lopes			14/0083065
**********************************************************************

Índice:
- Características do Ambiente de Programação
- Componentes
- Compilação
- Execução
- Funções

Caracteristicas do Ambiente de Programação
------------------------------------
compilador usado: gcc 4.8.4
sistema operacional usado: Ubuntu 14.04.1
IDE usada: nenhuma


Compenentes
------------------------------------
O trabalho possui primeiramente 3 pastas, lib, src e include. No include deve estar um arquivo do tipo .h,  simulador.h. A pasta lib estará vazia enquanto a pasta src possui mais duas pastas dentro e alguns arquivos. Os arquivos que devem estar presentes na pasta src são simulador.c, simulacao.c, data.bin, text.bin, Fibonacci.asm, mips1.asm e makefile.txt . Atente-se ao fato de que simulacao.c é onde se encontra a main. Dentro da pasta obj estarão os obj gerados na compilação. Podem aparecer os arquivos register.bin e memory.bin no caso de a memoria e os registradores do simulador terem sido impressos. 

Fibonacci.asm contém o código da sequência de Fibonacci enquanto mips1.asm contém o código do pdf. Em ambos os casos, os .asm sofreram alterações para que se usasse apenas as funções implementadas no programa.

Compilação
------------------------------------
a compilação deverá ser feita através do terminal, estando aberto na pasta "src". 
Para compilar, basta digitar no terminal o comando "make" e apertar enter.
Caso a compilação já tenha sido executada anteriormente e não necessite de alterações, o terminal exibirá a mensagem "make: `simulacao' is up to date." Caso queira compilar novamente para ter certeza de que foi compilado, basta apagar o que se encontra dentro da pasta obj ou o executável que se encontra em src de nome simulacao.

Execução
------------------------------------
para executar o programa, digite através do terminal o comando "./simulacao" se já ouver compilado o programa. 

Funções
------------------------------------
Quanto as funções que foram implementadas no trabalho anterior simulando instruções do MIPS, estão presentes juntamente com aquelas requeridas pelo pdf ou necessárias para o bom funcionamento do programa. As instruções requeridas foram também denominadas como funções para melhor visualização e provavel uso futuro. Em simulador.h é possível ver a lista das mesmas acompanhado de um /*ok*/ que foi escrito conforme se avaliava e construia as funções para que se possa ter certeza de que todas foram devidamente implementadas.

	* int32_t lw(uint32_t address, int16_t kte) 
		simula a função load word do MIPS onde considerando a tabela de funções do tipo I, address representa o valor de RS e kte o valor de Imm. Assim, para se executar a função lw $t0, k, uma construção ideal seria reg[8] = lw (0,8192) considerando que k está na posição 8192 (em valor decimal) da memória. Correspondente a 0x2000. Dessa forma, a função lerá o que está na posição 8192 da memória e colocará em reg[8] que simula a posição do registrador t0.

	* void sw(uint32_t address, int16_t kte, int32_t dado) 
		simula a função store word do MIPS onde considerando a tabela de funções do tipo I, address representa o valor de reg[address], kte o valor de Imm e dado o valor presente no endereço que ele irá checar. Assim, para se executar a função sw $t1, k, uma construção ideal seria sw (0,8192, reg[9]) considerando que k está na posição 8192 (em valor decimal) da memória. Correspondente a 0x2000 e que reg[9] corresponde ao valor alocado no registrador $t1.

	* int32_t lh (uint32_t address, int16_t kte)
		simula a função load half word do MIPS onde considerando a tabela de funções do tipo I, address representa o valor de RS e kte o valor de Imm. Assim, para se executar a função lh $t0, k, uma construção ideal seria reg[8] = lh (0,8192) considerando que k está na posição 8192 (em valor decimal) da memória. Correspondente a 0x2000. Dessa forma, a função lerá o que está na posição 8192 da memória e colocará em reg[8] que simula a posição do registrador t0.

	* int32_t lhu (uint32_t address, int16_t kte)
		simula a função load half word unsigned do MIPS onde considerando a tabela de funções do tipo I, address representa o valor de RS e kte o valor de Imm. Assim, para se executar a função lhu $t0, k, uma construção ideal seria reg[8] = lhu (0,8192) considerando que k está na posição 8192 (em valor decimal) da memória. Correspondente a 0x2000. Dessa forma, a função lerá o que está na posição 8192 da memória e colocará em reg[8] que simula a posição do registrador t0.

	* void sh(uint32_t address, int16_t kte, int16_t dado) 
		simula a função store word do MIPS onde considerando a tabela de funções do tipo I, address representa o valor de reg[address], kte o valor de Imm e dado o valor presente no endereço que ele irá checar. Assim, para se executar a função sh $s1, 8232($zero), uma construção ideal seria sh (0,8232, reg[17]), 8232 em decimal, Correspondente a 0x2028 e que reg[17] corresponde ao valor alocado no registrador $s1.

	* int32_t lb (uint32_t address, int16_t kte)
		simula a função load byte do MIPS onde considerando a tabela de funções do tipo I, address representa o valor de RS e kte o valor de Imm. Assim, para se executar a função lb $t2, i, uma construção ideal seria reg[10] = lb (0,8193) considerando que k está na posição 8193 (em valor decimal) da memória. Correspondente a 0x2004. Dessa forma, a função lerá o que está na posição 8193 da memória e colocará em reg[10] que simula a posição do registrador t2.

	* int32_t lbu (uint32_t address, int16_t kte)
		simula a função load half byte do MIPS onde considerando a tabela de funções do tipo I, address representa o valor de RS e kte o valor de Imm. Assim, para se executar a função lbu $t2, i, uma construção ideal seria reg[10] = lbu (0,8193) considerando que k está na posição 8193 (em valor decimal) da memória. Correspondente a 0x2004. Dessa forma, a função lerá o que está na posição 8193 da memória e colocará em reg[10] que simula a posição do registrador t2.

	* void sb(uint32_t address, int16_t kte, int8_t dado)
		simula a função store word do MIPS onde considerando a tabela de funções do tipo I, address representa o valor de reg[address], kte o valor de Imm e dado o valor presente no endereço que ele irá checar. Assim, para se executar a função sb $s1, 8232($zero), uma construção ideal seria sb (0,8232, reg[17]), 8232 em decimal, Correspondente a 0x2028 e que reg[17] corresponde ao valor alocado no registrador $s1.
