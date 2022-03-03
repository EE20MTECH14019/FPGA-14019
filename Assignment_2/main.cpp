#include <Arduino.h>

#define P 2
#define Q 3
#define R 4


//variables
int p, q, r, kmap_output, NAND_output;
//Function for 2input NAND gate
int NAND(int a, int b) {
    return !(a && b);
    }


void setup() {
        pinMode(P, INPUT);
        pinMode(Q, INPUT);
        pinMode(R,INPUT);
        pinMode(LED_BUILTIN, OUTPUT);
        }

void loop() {
        p = digitalRead(P);
        q = digitalRead(Q);
        r = digitalRead(R);

        kmap_output = (q|| !r) && (!q || r);

        NAND_output = NAND(NAND(NAND(q,q),NAND(r,r)),NAND(q,r));

        if(kmap_output == NAND_output)
                digitalWrite(LED_BUILTIN,HIGH);
        else
                digitalWrite(LED_BUILTIN,LOW);
}
