#define INPUTS (~PINA & 0x07)
#define C (~PINA & 0x04)
#define D (~PINA & 0x02)
#define E (~PINA & 0x01)

enum States {WAIT, C_PRESSED, D_PRESSED E_PRESSED, C_HELD, D_HELD, E_HELD} state;

void tick(){
   switch(state){  //Transitions
   }
}
