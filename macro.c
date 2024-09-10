// Include required header files

#include <stdio.h>
#include <stdint.h>

// Setup up memory

#define MAX_MEMORY (1<<16)
uint16_t memory[MAX_MEMORY]; /* 65536 locations*/

// Setup registers

enum 
{
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC, /* Program counter*/
    R_COND,
    R_COUNT
};

uint16_t reg[R_COUNT];

// Setup opcode as instruction set of LC-3

enum
{
    OP_BR = 0, /* branch*/
    OP_ADD,    /* add   */
    OP_LD,     /* load  */
    OP_ST,     /* store */
    OP_JSR,    /* jump register*/
    OP_AND,    /* bitwise AND */
    OP_LDR,    /* load register*/
    OP_STR,    /* store register*/
    OP_RTI,    /* unused*/
    OP_NOT,    /* bitwise NOT*/
    OP_LDI,    /* load indirect*/
    OP_STI,    /* store indirect*/
    OP_JMP,    /* jump*/
    OP_RES,    /* reserved */
    OP_LEA,    /* load effective address*/
    OP_TRAP    /* execute trap*/
};

// Setup conditional flags

enum
{
    FLA_POS = 1 << 0, /* P */
    FLA_ZRO = 1 << 1, /* Z */
    FLA_NEG = 1 << 2  /* N */
};

// Main function loop code

int main(int argc, const char* argv[])
{
    /*Load arguements*/
    if (argc < 2)
    {
        /* show usage string*/
        printf("lc3 [image-file1] ... \n");
        exit(2);
    }

    for (int j = 1; j < argc; ++j)
    {
        if(!read_image(argv[j]))
        {
            printf("failed to load image: %s\n", argv[j]);
            exit(1);
        }
    }
    /*Initial the conditional flag to Z as atleast one flag should be set at a time*/
    reg[R_COND] = FLA_ZRO;

    /*Set the PC to staring position*/
    /*0x3000 is default*/
    enum {PC_START = 0x3000};

    reg[R_PC] = PC_START;

    int running = 1;

    while(running)
    {
        /*Fetch*/
        uint16_t instr = mem_read(reg[R_PC]);
        uint16_t op = instr >> 12;

        switch(op)
        {
            case OP_ADD:
            break;
            case OP_AND:
            break;
            case OP_BR:
            break;
            case OP_JMP:
            break;
            case OP_JSR:
            break;
            case OP_LD:
            break;
            case OP_LDI:
            break;
            case OP_LDR:
            break;
            case OP_LEA:
            break;
            case OP_NOT:
            break;
            case OP_ST:
            break;
            case OP_STI:
            break;
            case OP_STR:
            break;
            case OP_TRAP:
            break;
            case OP_RES:
            case OP_RTI:
            default:
            break;

        }
    }

    printf("%d\n",PC_START);
    return 0;
}