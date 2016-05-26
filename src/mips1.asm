.data
primos: .word 1, 3, 5, 7, 11, 13, 17, 19
size: .word 8
msg: .asciiz "Os oito primeiros numeros primos sao : "
space: .ascii " "

.text

	addi $8, $0, 8192		#carrega endereco inicial do array
	addi $9, $0, 8224		#carrega endereco de size
	lw $t1, 0($t1)		#carrega size em t1
	addi $2, $0, 4		#imprime mensagem inicial
	addi $4, $0, 8228
	syscall
	
loop: 	beq $t1, $zero, exit	#se processou todo o array, encerra
	addi $2, $0, 1		#servico de impressao de inteiros
	lw $a0, 0($t0)		#inteiro a ser exibido
	syscall
	addi $2, $0, 4		#imprime separador
	addi $4, $0, 8268
	syscall
	addi $t0, $t0, 4	#incrementa indice array
	addi $t1, $t1, -1	#decrementa contador
	j loop			#novo loop

exit:  addi $2, $0, 10
	syscall
