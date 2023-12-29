#TODO1 Enter your name
#
#  Your name: Jordan Ansari
#

# This file contains a MIPS assembly language program that uses only the
# instructions introduced in p1.asm and p2.asm plus the following:
#
#   la rdest, address	- Loads a computed address -- not the contents of
#			  the location -- into register rdest.  This
#			  pseduoinstruction actually translates into lui
#			  and ori, which were explained in p2.asm.
#   lw rt, address	- Load the 32-bit quantity (word) at address
#			  into register rt.
#   sw rt, address	- Store the word from register rt at address.
#
# It implements the high-level language statement A[11] = h + A[8]; .
#
# It is intended to help CSSE 232 students familiarize themselves with MIPS.

.globl main			# Make main, A, and h globl so you can
.globl A			# refer to them by name.
.globl h
.globl total			# Make global variable total

.data				# Data section of the program

A:	.word	1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43
h:	.word	40
total:  .word	0
	
.text				# Text section of the program
		
main:				# Label that marks the start of our function
	la	$t0, h		# Register $t0 gets address of h
	la	$t1, A		# Register $t1 gets address of A
	la 	$t7, total	# Register $t7 gets address of total

	lw	$t2, 0($t0)	# Register $t2 gets h
	lw	$t3, 32($t1)	# Register $t3 gets A[8]

	add	$t3, $t2, $t3   # Register $t3 gets h + A[8]

	sw	$t3, 44($t1)	# A[11] gets h + A[8]
	
	#TODO2 			Write the code defined in the lab
	lw 	$t4, 48($t1)	# Register $t4 gets A[12]
	lw	$t5, 52($t1)	# Register $t5 gets A[13]
	lw	$t6, 56($t1)	# Register $t6 gets A[14]
	
	add 	$t4, $t4, $t5	# Register $t4 gets A[12] + A[13]
	add 	$t6, $t6, $t4	# Register $t6 gets A[14] + $t4
	
	sw	$t6, 0($t7)

	
	
	#TODO3 			Uncomment the line below when you are ready to test
	jal	runtests	#run the tests
	
	li	$v0, 10
	syscall

