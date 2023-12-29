
#**********************************************************************
# Add your names here.
#      Your name:  Jordan Ansari
# Partner's name:  Logan Bryant
#**********************************************************************

# This file contains a MIPS assembly language program that uses only the
# instructions introduced in p1.asm, p2.asm, p3.asm, p4.asm and p5.asm.
#

	.globl	p6
	.globl	V
	.globl	N

	.data

V:	.word   20, 56, -90, 37, -2, 30, 10, -66, -4, 18
N:	.word	10

#**********************************************************************

	.text

	jal	main	# Start test program

p6:			# Program 6 starts here

#----------------------------------------------------------------------
#	 Rotate the array V
#----------------------------------------------------------------------
#
# Initialization
	la	$t1, N		# Set $t1 to the address of N
	lw	$t1, 0($t1)	# Set $t1 to the value of N
	sub	$t1, $t1, 1	# Set $t1 to N-1
	la	$t2, V		# Set $t4 to the address of A[i]
	
	sll	$t0, $t1, 2	# Set $t0 to 4*(N-1)
	add	$t0, $t0, $t2	# Set $t0 to the address of A[N-1]
	lw	$t4, 0($t0)	# Set $t4 to the value at A[N-1]
	
loop:
	beq	$t1, $0, done	# Jump to done if i=0
	ori	$t6, $t0, 0	# Set $t6 to the address of A[i] $t0
	sub	$t0, $t0, 4	# Set $t0 to the address of A[i-1]
	lw	$t7, 0($t0)	# Set $t7 to the value at $t0
	sw	$t7, 0($t6)
	sub	$t1, $t1, 1
	bne	$t1, 0, loop
	
	
	

#----------------------------------------------------------------------
done:
	#sub	$t0, $t0, 4	# Set $t0 to the address of A[0]
	sw	$t4, 0($t0)
	jr	$ra		# Exit program 6
