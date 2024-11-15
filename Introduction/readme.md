README.md

Chapter 1: Introduction to Reverse Engineering with 0DE5

This chapter introduces you to basic programming in C and reverse engineering using tools like objdump and radare2. It emphasizes understanding how high-level code translates into low-level machine instructions and teaches you to manipulate compiled binaries directly.

Goals of This Chapter

	1.	Write a Simple C Program
	•	Write, compile, and run a basic C program.
	•	Understand the compilation process and execute a binary in the terminal.
	2.	Reverse Engineer the Executable
	•	Analyze and modify the behavior of the compiled program without editing the source code.
	•	Utilize tools like objdump and radare2 to explore the compiled binary.
	3.	Modify Program Behavior
	•	Use a hex editor to alter assembly code.
	•	Learn about opcodes, instructions, and system architecture (e.g., x86-64 or ARM).
	•	Manipulate branches and jumps in assembly to change program logic.

Step 1: Write and Compile a C Program

Example Code

#include <stdio.h>

int main() {
    char input;
    printf("Enter the single character: \n");
    scanf("%c", &input);
    if (input == 'Q') {
        printf("Welcome to 0DE5!\n");
    } else {
        printf("You input must be Q!\n");
    }
    return 0;
}

Compilation Command

gcc -O0 -g -o my_program my_program.c
./my_program

	•	Flags used:
	•	-O0: Disables optimizations to simplify assembly code for analysis.
	•	-g: Includes debugging information.
	•	-o: Specifies the output filename.

Step 2: Disassemble the Executable

Use objdump to Analyze Assembly

objdump -d my_program

	•	objdump displays the assembly instructions of your compiled binary.
	•	Look for conditions or branches (j, b) and corresponding instructions.

Step 3: Modify Executable Behavior

Plan the Modification

	1.	Identify the conditional check in the assembly (e.g., the comparison between the input and 'Q').
	2.	Redirect or remove the branch so that the program always executes the "Welcome to 0DE5!" logic.

Use radare2 for Hex Editing

	1.	Open the binary in radare2:

r2 -w my_program


	2.	Analyze the code:

aaa
pdf @ main


	3.	Find the opcode for the condition (e.g., je for “jump if equal”) and replace it with a NOP (no operation).

Save and Exit

After making changes, save the file and test the modified executable.

Concepts Introduced

1. Assembly Language Basics

	•	Instructions: Operations like mov, cmp, jmp.
	•	Registers: Storage units in the CPU (e.g., eax, rsp).
	•	Endianness: Byte-order differences (e.g., little-endian vs. big-endian).

2. Reverse Engineering Tools

	•	objdump: Disassembles and provides assembly-level view of the binary.
	•	radare2: Hex editor and binary analysis tool.

3. Hexadecimal Editing

	•	Use NOP (0x90 on x86, 1f 20 03 d5 on ARM64) to neutralize unwanted instructions.
	•	Modify jumps to control the program flow.

Practice Exercises

	1.	Modify the program so it prints "Welcome to 0DE5!" regardless of input.
	2.	Experiment with altering other outputs or conditions in the binary.
	3.	Compare the assembly of an optimized (-O2) vs. non-optimized (-O0) binary.

Tips for Success

	•	Start with a clean, unmodified executable when errors arise.
	•	Use resources like online opcode translators to understand instructions.
	•	Watch tutorials or refer to architecture-specific manuals for further guidance.

Happy coding and reverse engineering! 🚀



Here’s a deeper dive into using radare2 and understanding its commands for reverse engineering:

Using radare2 for Reverse Engineering

radare2 is a powerful open-source framework for analyzing and modifying binaries. This section will help you navigate and modify your program using radare2 effectively.

Basic Workflow with radare2

	1.	Open the Binary in Write Mode

r2 -w my_program

	•	The -w flag allows you to write changes to the binary.

	2.	Analyze the Binary
Once inside the radare2 shell, use the following commands for initial analysis:
	•	Analyze All Code:

aaa

Performs an in-depth analysis, identifying functions, basic blocks, and control flow.

	•	List Functions:

afl

Displays all discovered functions, their addresses, and sizes.

	•	View Function Details:

pdf @ main

Displays the disassembled instructions of the main function. You can replace main with the address of other functions.

Understanding the Disassembly

When viewing a function with pdf, you’ll see:
	1.	Addresses: Memory locations where instructions are loaded (e.g., 0x00401100).
	2.	Opcodes: The hexadecimal representation of the machine instructions (e.g., 0x74 0x0a).
	3.	Assembly Instructions: Human-readable assembly code (e.g., je 0x00401120 for “jump if equal”).
	4.	Comments: Additional information or hints provided by radare2.

Modifying the Binary

1. Find the Conditional Jump

Look for instructions like je, jne, jmp, or call. For example:

0x00401120   74 0a      je 0x0040112c  ; Jump if equal

Here, je means “jump if the comparison result is equal.” Your goal is to replace this with something that forces the desired behavior.

2. Replace with a NOP

	•	NOP Instruction:
	•	On x86-64, the opcode for NOP is 0x90.
	•	On ARM64, the opcode for NOP is 1f 20 03 d5.

To replace the je instruction with NOP:
	1.	Navigate to the address using:

s 0x00401120

This sets the cursor to the specific address.

	2.	Write the NOP:

wx 90

For ARM64:

wx 1f2003d5



3. Redirect the Jump

If you want to force the program to always print “Welcome to 0DE5!”, find the printf function call and direct the jump to that address.
	1.	Identify the target instruction address:

pdf @ main

Look for the printf instruction’s address.

	2.	Replace the je instruction with an unconditional jump (jmp):
	•	On x86-64:
	•	Opcode for jmp: EB.
	•	Example:

wx ebXX

Replace XX with the number of bytes to jump forward/backward.

	•	On ARM64:
	•	Opcode for b: 14.

Testing Changes

	1.	Save Changes:

wq

This writes the modifications and exits the radare2 shell.

	2.	Run the Modified Program:

./my_program

Test if the program behaves as expected.

Advanced Commands

	1.	Hexdump View:

px @ address

Displays the raw hexadecimal bytes at the specified address.

	2.	Seek Through the File:

s [address]

Moves the cursor to a specific address.

	3.	Search for Strings:

iz

Lists all strings in the binary, useful for identifying locations of messages like "Welcome to 0DE5!".

	4.	Search for Instructions:

/c je

Searches for occurrences of je in the binary.

	5.	View Call Graph:

agf @ main

Displays the call graph for a specific function.

Key Concepts

	•	NOP (No Operation): A filler instruction that does nothing, often used to neutralize existing instructions.
	•	Branch Instructions: je, jne, jmp, and others control the flow of execution.
	•	Endianess: Pay attention to how bytes are stored (little-endian for most architectures).

Practice Exercises with radare2

	1.	Replace the jump in the program so it always prints "Welcome to 0DE5!" regardless of input.
	2.	Explore how radare2 displays strings and functions and use this to locate specific output calls.
	3.	Experiment with redirecting jumps to other parts of the program to understand how control flow works.

By practicing with these commands and techniques, you’ll develop a strong understanding of binary analysis and modification! 🚀