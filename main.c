#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

//variables
//index to keep track of where we are in the program
int instructionPointer = 0;
int stackPointer = -1;
int stack[256];
int programCounter = 0;
//Instruction Set enum
typedef enum {
     PSH,
     ADD,
     POP,
     SET,
     HLT,
     MUL,
     DIV,
     SUB,
     MOV,
     LOG,
     IF,
     RET,
     JMP,
     CALL
} InstructionSet;

typedef enum {
     A, B, C, D, E, F,
     NUM_REGISTERS
} Registers;




//fairly simple - will just add 2 and 4, pop them from the stack and HLT will quit the program
const int program[] = {
     PSH, 5,
     PSH, 6,
     ADD,
     POP,
     PSH, 6,
     PSH, 2,
     DIV,
     HLT
};

int running = true;
int poppedValue = 0;
//evaluates the instruction
//quits if HLT is called
void eval(int instruction) {
     switch (instruction)
     {
     case HLT: {
          running = false;
          break;
     }
     case PSH: {
          //push something to the stack
          //increment stack pointer
          stackPointer++;
          //set the value of the stack to the next value
     
          stack[stackPointer] = program[++instructionPointer];
          break;
     }
     case POP: {
          int poppedValue = stack[stackPointer--];
          //stackPointer--;
          //remove the topmost value
          printf("Value popped: %d ", poppedValue);
     }
     case ADD: {
          int firstVal = stack[stackPointer--];
          int secondVal = stack[stackPointer--];
          int resultVal = firstVal + secondVal;
          stackPointer++;
          stack[stackPointer] = resultVal;
          break;
     case DIV: {
          int firstVal = stack[stackPointer--];
          int secondVal = stack[stackPointer--];
          int resultVal = firstVal  /secondVal;
          stackPointer++;
          stack[stackPointer] = resultVal;
          printf("Divided result: %d", resultVal);
          break;
     }
     case MUL: {
          int firstVal = stack[stackPointer--];
          int secondVal = stack[stackPointer--];
          int resultVal = firstVal  * secondVal;
          stackPointer++;
          stack[stackPointer] = resultVal;
          printf("Value multiplied: %d", resultVal);
          break;
     }
     default:
          break;
     }
}
}

int fetch(){
     return program[instructionPointer];
}


int main(void){
     while(running){
     eval(fetch());
     instructionPointer++;
     printf("Instruction Pointer: %d\n", instructionPointer);
     }
     printf("Program Exited with code 0\n");
     return 0;
     


}

