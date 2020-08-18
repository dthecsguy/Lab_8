#define C (~PINA & 0x04)
#define D (~PINA & 0x02)
#define E (~PINA & 0x01)

#define C_FREQ 261.63
#define D_FREQ 293.66
#define E_FREQ 329.63

#define INPUTS (C | D | E)
#define HLD_T 4 //how long to hold button

enum States {WAIT, C_PRESSED, D_PRESSED E_PRESSED, C_HELD, D_HELD, E_HELD} state;

void tick(){
   switch(state){  //Transitions
		case WAIT:
			if (INPUTS == C){
				state = C_PRESSED;
			}
			else if (INPUTS == D){
				state = D_PRESSED;
			}
			else if (INPUTS == E){
				state = E_PRESSED;
			}
			else {
				state = WAIT;
			}
			break;
		case C_PRESSED:
			if (ticks < HLD_T){
				state = (INPUTS == C) ? C_PRESSED : WAIT;
			}
			else {
				state = (INPUTS == C) ? C_HELD : WAIT;
			}
			break;
		
		case D_PRESSED:
			if (ticks < HLD_T){
				state = (INPUTS == D) ? D_PRESSED : WAIT;
			}
			else {
				state = (INPUTS == D) ? D_HELD : WAIT;
			}
			break;
		
		case E_PRESSED:
			if (ticks < HLD_T){
				state = (INPUTS == E) ? E_PRESSED : WAIT;
			}
			else {
				state = (INPUTS == E) ? E_HELD : WAIT;
			}
			break;
		
		case C_HELD:
			state = (INPUTS == C) ? C_HELD : WAIT; 
			break;
		
		case D_HELD:
			state = (INPUTS == D) ? D_HELD : WAIT;
			break;
		
		case E_HELD:
			state = (INPUTS == E) ? E_HELD : WAIT;
			break;
		
   }
   switch(state){  //Actions
		case WAIT:
			tick = 0;
			break;
			
		case C_PRESSED:
			tick++;
			break;
		
		case D_PRESSED:
			tick++;
			break;
		
		case E_PRESSED:
			tick++;
			break;
		
		case C_HELD:
			tick = 0;
			set_PWM(C_FREQ);
			break;
		
		case D_HELD:
			tick = 0;
			set_PWM(D_FREQ);
			break;
		
		case E_HELD:
			tick = 0;
			set_PWM(E_FREQ);
			break;
   }
}
