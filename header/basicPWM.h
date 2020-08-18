#define A ~PINA

#define A2 (A & 0x04)
#define A1 (A & 0x02)
#define A0 (A & 0x01)

#define C_FREQ 261.63
#define D_FREQ 293.66
#define E_FREQ 329.63

#define HLD_T 4 //how long to hold button

enum States {WAIT, C_PRESSED, D_PRESSED, E_PRESSED, C_HELD, D_HELD, E_HELD} state;
static unsigned char cnt = 0;

void tick(){
   switch(state){  //Transitions
		case WAIT:
			if (A2){
				state = C_PRESSED;
			}
			else if (A1){
				state = D_PRESSED;
			}
			else if (A0){
				state = E_PRESSED;
			}
			else {
				state = WAIT;
			}
			break;
		   
		case C_PRESSED:
			if (cnt < HLD_T){
				state = (A2) ? C_PRESSED : WAIT;
			}
			else {
				state = (A2) ? C_HELD : WAIT;
			}
			break;
		
		case D_PRESSED:
			if (cnt < HLD_T){
				state = (A1) ? D_PRESSED : WAIT;
			}
			else {
				state = (A1) ? D_HELD : WAIT;
			}
			break;
		
		case E_PRESSED:
			if (cnt < HLD_T){
				state = (A0) ? E_PRESSED : WAIT;
			}
			else {
				state = (A0) ? E_HELD : WAIT;
			}
			break;
		
		case C_HELD:
			state = (A2) ? C_HELD : WAIT; 
			break;
		
		case D_HELD:
			state = (A1) ? D_HELD : WAIT;
			break;
		
		case E_HELD:
			state = (A0) ? E_HELD : WAIT;
			break;
		
   }
   switch(state){  //Actions
		case WAIT:
			cnt = 0;
		   	set_PWM((double)0);
			break;
			
		case C_PRESSED:
			cnt++;
			break;
		
		case D_PRESSED:
			cnt++;
			break;
		
		case E_PRESSED:
			cnt++;
			break;
		
		case C_HELD:
			cnt = 0;
			set_PWM(C_FREQ);
			break;
		
		case D_HELD:
			cnt = 0;
			set_PWM(D_FREQ);
			break;
		
		case E_HELD:
			cnt = 0;
			set_PWM(E_FREQ);
			break;
		   
   }
}
