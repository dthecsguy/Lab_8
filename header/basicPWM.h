#define INPUTS ~PINA

#define A2 (INPUTS & 0x04)
#define A1 (INPUTS & 0x02)
#define A0 (INPUTS & 0x01)

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
			
			state = (A2) ? C_HELD : WAIT;
			break;
		
		case D_PRESSED:
			state = (A1) ? D_HELD : WAIT;
			break;
		
		case E_PRESSED:
			state = (A0) ? E_HELD : WAIT;
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
		   	set_PWM((double)0);
			break;
			
		case C_PRESSED:
			break;
		
	   	case D_PRESSED:
			break;
		
		case E_PRESSED:
			break;
		
	   	case C_HELD:
			set_PWM(C_FREQ);
			break;
		
		case D_HELD:
			set_PWM(D_FREQ);
			break;
		
		case E_HELD:
			set_PWM(E_FREQ);
			break;
		   
   }
}
