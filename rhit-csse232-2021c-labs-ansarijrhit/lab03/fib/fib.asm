#**********************************************************************
# Add your names here.
#      Your name:  Jordan Ansari
# Partner's name:  Jacob Ashworth
#**********************************************************************


#**********************************************************************
# This file contains a recursive MIPS assembly language 
# procedure which calculates Fibonacci numbers.
#**********************************************************************

	.globl fib
	
	
	.text

	j	main	# Run the test program which will call your fib procedure


#----------------------------------------------------------------------
#   Procedure: fib
#       
#   Frame is 4 words long, as follows:
#     -- previous ra
#     -- nothing
#     -- previous s1
#     -- previous s0
#
#   Arguments:
#     $a0 - n
#
#   Returns:
#     $v0 - fib(n)
#
#   Register allocations:
#     $s0 - n
#     $s1 - fib(n-1)
#
#----------------------------------------------------------------------

fib:
	##base cases
	#this will fail for negatives...
	bne 	$a0, $0, CASE1	#go to check next base if n != 0
	ori 	$v0, $0, 0	#return 0
	jr 	$ra
	
CASE1:	ori 	$t1, $0, 1	#set t1 = 1
	bne 	$a0, $t1, CALC	#go do calculation if n != 1
	ori 	$v0, $0, 1	#else return 1
	jr 	$ra

CALC:	##build frame
	#Do the stack management 
	#following the procedure calling 
	#conventions here
	addi 	$sp, $sp, -16
	sw	$ra, 12($sp)
	sw	$s1, 4($sp)
	sw	$s0, 0($sp)
	
	
	or 	$s0, $a0, $0	#store n in s0a
	
	##computation
	addi 	$a0, $s0, -1 	#set argument to n-1
	jal 	fib		#calc fib(n-1)
	ori 	$s1, $v0, 0 	#$s1=fib(n-1)
	
	addi 	$a0, $s0, -2 #	set argument to n-2
	jal 	fib 		#calc fib(n-2)
	
	add 	$v0, $s1, $v0 	#add fib(n-1) and fib(n-2)
	
	##deconstruct frame
	#do your stack management cleanup here
	lw	$ra, 12($sp)
	lw	$s1, 4($sp)
	lw	$s0, 0($sp)
	addi 	$sp, $sp, 16
	

	jr	$ra #return the calculated value
