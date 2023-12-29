
#**********************************************************************
# Add your names here.
#      Your name:  Jordan Ansari
# Partner's name:  Jacob Ashworth
#**********************************************************************


# This file contains a MIPS assembly language program that uses only the
# instructions introduced in p1.asm, p2.asm, p3.asm, p4.asm and p5.asm.
#
# It also takes advantage of several spim syscalls and the assembly
# directive .asciiz
#

#**********************************************************************

	.globl	SwapMaxWithLast
	.text

# ---------------------------------------------------------------------
# Procedure: SwapMaxWithLast
#
# No frame, none is needed.
#
# Arguments:
#  $a0 = address of the array
#  $a1 = number of elements in the array
#
# Returns:
#  none
#
# Register allocations:
#  none:
#
# Swaps the maximum element with the last element of the array.
# ---------------------------------------------------------------------

SwapMaxWithLast:

# The SwapMaxWithLast label is the procedure entry point.
#
#
	# Initialization
#	la	$t0, N		# Set $t0 to the address of N
	or	$t0, $a1, $0	# Set $t0 to the value of N
	li	$t1, 1		# Set $t1 to 1
	li	$t2, 0		# Set $t2 (hereafter called i) to 0
	or	$t4, $a0, $0	# Set $t4 to the address of A[i]
	li	$t5, 1		# Don't change this- needed for when the loop shift is removed
	li	$t6, -32768
#	lw	$t6, 0($t4)
#	lw	$t9, 4($t4)
#	blt	$t6, $t9, loop
#	j 	secondsmaller

#secondsmaller:
#	lw	$t6, 4($t4)	# Set $t6 (hereafter called max) to the first value in the array
#	j loop
	
	# $t7 and $t8 are assigned in the loop before they are used
	
loop:
	slt	$t9, $t2, $t0	# Check if i < N
	beq	$t9, $0, exit	# Continue loop if i < N

	# Load the next element
	sll   $t5, $t2, 2	# Set $t5 to i*4
	add	$t5, $t5, $t4	# Set $t5 to address of A[i]
	lw	$t5, 0($t5)	# Set $t5 to A[i]

	# Update max and maxindex if necessary
	slt	$t8, $t6, $t5	# Set flag to 1 if max < A[i], and 0 otherwise
	beq	$t8, $0, ok	# Skip update if flag is 0
	add	$t6, $t5, $0	# Set max to A[i]
	add	$t7, $t2, $0	# Set maxindex to i
	
ok:
	add	$t2, $t2, $t1	# Increment i
	j	loop		# Continue loop


exit:
	sub	$t0, $t0, 1
	sll 	$t3, $t0, 2
	sll	$t1, $t7, 2
	add	$t1, $t1, $t4
	add	$t3, $t3, $t4
	lw	$t5, 0($t3)
	sw	$t6, 0($t3)
	sw	$t5, 0($t1)
#
	jr	$ra
