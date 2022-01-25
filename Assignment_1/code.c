#include <stdio.h>

//2-Input NAND operation function
unsigned int NAND (unsigned int A, unsigned int B) {
    return ~(A & B);    
}

int main() {
    unsigned char F_nand; //output
    unsigned int F[8]={1,0,0,1,1,0,0,1}; 
    unsigned char one = 0x01;//used for displaying the output in bit
    printf("\nBinary Input F_Output NAND Output \n");
    for (n = 0x00; n<0x08; n++)              
    {
        //Binary inputs
        P = n>>2;    
        Q = n>>1;    
        R = n>>0;

    // Implementation using NAND
    //F = ~((~((~Q)&(~R)))&(~(Q&R)));
    F_nand = NAND(NAND(NAND(Q,Q),NAND(R,R)),NAND(Q,R));
 
    printf("    %x %x %x      %d        %x\n", one&P, one&Q, one&R, F[n], one&F_nand);

    }
    return 0;
}
