#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "notes.h"

static int toggleRed = 0;
static int toggleGreen = 0;

void redDim25()
{
  switch (toggleRed){
  case 0:
    redOn(0);
    toggleRed++;
  case 1:
    toggleRed++;
  case 2:
    toggleRed++;
    break;
  case 3:
    redOn(1);
    toggleRed = 0;
    break;
  default:
    break;
  }
}


void redDim50()
{
  switch (toggleRed){
  case 0:
    redOn(1);
    toggleRed++;
    break;
  case 1:
    redOn(0);
    toggleRed++;
    break;
  case 2:
    toggleRed++;
    break;
  case 3:
    redOn(1);
    toggleRed = 0;
  default:
    break;
  }
}


void redDim75()
{
  switch(toggleRed){
  case 0:
    redOn(0);
    toggleRed++;
    break;
  case 1:
    toggleRed++;
    break;
  case 2:
    toggleRed++;
    break;
  case 3:
    redOn(1);
    toggleRed = 0;
    break;
  default:
    break;
  }
}


void greenDim25()
{
  switch (toggleGreen){
  case 0:
    greenOn(0);
    toggleGreen++;
  case 1:
    toggleGreen++;
  case 2:
    toggleGreen++;
    break;
  case 3:
    greenOn(1);
    toggleGreen = 0;
    break;
  default:
    break;
  }
}


void greenDim50()
{
  switch (toggleGreen){
  case 0:
    greenOn(1);
    toggleGreen++;
    break;
  case 1:
    greenOn(0);
    toggleGreen++;
    break;
  case 2:
    toggleGreen++;
    break;
  case 3:
    greenOn(1);
    toggleGreen = 0;
  default:
    break;
  }
}


void greenDim75()
{
  switch(toggleGreen){
  case 0:
    greenOn(0);
    toggleGreen++;
    break;
  case 1:
    toggleGreen++;
    break;
  case 2:
    toggleGreen++;
    break;
  case 3:
    greenOn(1);
    toggleGreen = 0;
    break;
  default:
    break;
  }
}

void playSong()
{
  static char currNote = 0;  // Keep track of state

  switch(currNote) {
        case 0:
            buzzer_set_period(C);
            altLEDS(1);  // LED on
            currNote++;
            break;
        case 1:
            buzzer_set_period(0);
            altLEDS(0);  // LED off
            currNote++;
            break;
        case 2:
            buzzer_set_period(C);
            altLEDS(1);
            currNote++;
            break;
        case 3:
            buzzer_set_period(C);
            altLEDS(0);
            currNote++;
            break;
        case 4:
            buzzer_set_period(A);
            altLEDS(1);
            currNote++;
            break;
        case 5:
            buzzer_set_period(A);
            altLEDS(0);
            currNote++;
            break;
        case 6:
            buzzer_set_period(G);
            altLEDS(1);
            currNote++;
            break;
        case 7:
            buzzer_set_period(0);
            altLEDS(0);
            currNote++;
            break;
        case 8:
            buzzer_set_period(0);
            altLEDS(1);
            currNote++;
            break;
        case 9:
            buzzer_set_period(C);
            altLEDS(0);
            currNote++;
            break;
        case 10:
            buzzer_set_period(G);
            altLEDS(1);
            currNote++;
            break;
        case 11:
            buzzer_set_period(G);
            altLEDS(0);
            currNote++;
            break;
        case 12:
            buzzer_set_period(A);
            altLEDS(1);
            currNote++;
            break;
        case 13:
            buzzer_set_period(A);
            altLEDS(0);
            currNote++;
            break;
        case 14:
            buzzer_set_period(C);
            altLEDS(1);
            currNote++;
            break;
        case 15:
            buzzer_set_period(C);
            altLEDS(0);
            currNote++;
            break;
	case 16:
            buzzer_set_period(B);
            altLEDS(0);
            currNote++;
            break;
	case 17:
            buzzer_set_period(0);
            altLEDS(0);
            currNote++;
            break;
	case 18:
            buzzer_set_period(B);
            altLEDS(0);
            currNote++;
            break;
	case 19:
            buzzer_set_period(B);
            altLEDS(0);
            currNote++;
            break;
	case 20:
            buzzer_set_period(A);
            altLEDS(0);
            currNote++;
            break;
	case 21:
            buzzer_set_period(A);
            altLEDS(0);
            currNote++;
            break;
	case 22:
            buzzer_set_period(G);
            altLEDS(0);
            currNote++;
            break;
        case 23:
            buzzer_set_period(0);  // End of song, turn off buzzer
            ledsOn(0);  // Turn off LEDs
            currNote = 0;  // Reset to start
            break;
        default:
            currNote++;
            break;
    }
}	    


void playSong2()
{
  static char currNote = 0;
  
  
  switch(currNote){
    case 0:
      buzzer_set_period(HIGH);
      currNote++;
      break;
    case 5:
      buzzer_set_period(LOW);
      currNote++;
      break;
    case 10:
      buzzer_set_period(HIGH);
      currNote++;
      break;
    case 15:
      buzzer_set_period(LOW);
      currNote++;
      break;
    case 20: 
      buzzer_set_period(HIGH);
      currNote++;
      break;
    case 25: 
      buzzer_set_period(0);
      currNote = 0;
      break;
    default:
      currNote++;
      break;
   }
}

void playSong3()
{
  static char currNote = 0;

  switch(currNote) {
        case 0:
            buzzer_set_period(G);   
            altLEDS(1);             
            currNote++;
            break;
        case 1:
            buzzer_set_period(G);   
            altLEDS(0);             
            currNote++;
            break;
        case 2:
            buzzer_set_period(0);   
            altLEDS(1);             
            currNote++;
            break;
        case 3:
            buzzer_set_period(A);   
            altLEDS(0);             
            currNote++;
            break;
        case 4:
            buzzer_set_period(0);   
            altLEDS(1);             
            currNote++;
            break;
        case 5:
            buzzer_set_period(G);   
            altLEDS(0);             
            currNote++;
            break;
        case 6:
            buzzer_set_period(0);   
            altLEDS(1);             
            currNote++;
            break;
        case 7:
            buzzer_set_period(C);   
            altLEDS(0);             
            currNote++;
            break;
        case 8:
            buzzer_set_period(0);   
            altLEDS(1);             
            currNote++;
            break;
        case 9:
            buzzer_set_period(B);   
            altLEDS(0);             
            currNote++;
            break;
        case 10:
            buzzer_set_period(0);   
            altLEDS(1);             
            currNote++;
            break;
        case 11:
            buzzer_set_period(G);   
            altLEDS(0);             
            currNote++;
            break;
        case 12:
            buzzer_set_period(G);   
            altLEDS(1);             
            currNote++;
            break;
        case 13:
            buzzer_set_period(0);   
            altLEDS(0);             
            currNote++;
            break;
        case 14:
            buzzer_set_period(A);   
            altLEDS(1);             
            currNote++;
            break;
        case 15:
            buzzer_set_period(0);   
            altLEDS(0);             
            currNote++;
            break;
        case 16:
            buzzer_set_period(G);   
            altLEDS(1);             
            currNote++;
            break;
        case 17:
            buzzer_set_period(0);   
            altLEDS(0);             
            currNote++;
            break;
        case 18:
            buzzer_set_period(D);   
            altLEDS(1);             
            currNote++;
            break;
        case 19:
            buzzer_set_period(C);   
            altLEDS(0);             
            currNote++;
            break;
        case 20:
	  buzzer_set_period(0);   
            altLEDS(1);             
            currNote++;
            break;
        case 21:
            buzzer_set_period(G);   
            altLEDS(0);             
            currNote++;
            break;
        case 22:
            buzzer_set_period(G);   
            altLEDS(1);             
            currNote++;
            break;
        case 23:
            buzzer_set_period(0);   
            altLEDS(0);             
            currNote++;
            break;
	case 24:
            buzzer_set_period(G);
            altLEDS(1);
            currNote++;
            break;
        case 25:
            buzzer_set_period(E);
            altLEDS(0);
            currNote++;
            break;
	case 26:
	  buzzer_set_period(0);
            altLEDS(1);
            currNote++;
            break;
        case 27:
            buzzer_set_period(0);
            altLEDS(0);
            currNote++;
            break;
        case 28:
            buzzer_set_period(C);  
            ledsOn(0);             
            currNote = 0;         
            break;
	case 29:
            buzzer_set_period(B);
            altLEDS(1);
            currNote++;
            break;
        case 30:
            buzzer_set_period(A);
            altLEDS(0);
            currNote++;
            break;
	case 31:
            buzzer_set_period(0);
            altLEDS(1);
            currNote++;
            break;
        case 32:
            buzzer_set_period(F);
            altLEDS(0);
            currNote++;
            break;
	case 33:
            buzzer_set_period(F);
            altLEDS(1);
            currNote++;
            break;
        case 34:
            buzzer_set_period(0);
            altLEDS(0);
            currNote++;
            break;
	case 35:
            buzzer_set_period(E);
            altLEDS(1);
            currNote++;
            break;
        case 36:
            buzzer_set_period(0);
            altLEDS(0);
            currNote++;
            break;
	case 37:
            buzzer_set_period(C);
            altLEDS(1);
            currNote++;
            break;
        case 38:
            buzzer_set_period(0);
            altLEDS(0);
            currNote++;
            break;
	case 39:
            buzzer_set_period(D);
            altLEDS(1);
            currNote++;
            break;
        case 40:
            buzzer_set_period(0);
            altLEDS(0);
            currNote++;
            break;
	case 41:
            buzzer_set_period(C);
            altLEDS(1);
            currNote++;
            break;
        case 42:
            buzzer_set_period(0);
            altLEDS(0);
            currNote==0;
            break;
        default:
            currNote++;
            break;
    }
}


void playSong4()
{
  static char currNote = 0;

  switch(currNote) {
        case 0:
            buzzer_set_period(G);
            currNote++;
            break;
        case 1:
            buzzer_set_period(G);
            currNote++;
            break;
        case 2:
            buzzer_set_period(E);
            currNote++;
            break;
        case 3:
            buzzer_set_period(E);
            currNote++;
            break;
        case 4:
            buzzer_set_period(F);
            currNote++;
            break;
        case 5:
            buzzer_set_period(F);
            currNote++;
            break;
        case 6:
            buzzer_set_period(0);
            currNote++;
            break;
        case 7:
            buzzer_set_period(0);
            currNote++;
            break;
        case 8:
            buzzer_set_period(0);
            currNote++;
            break;
        case 9:
            buzzer_set_period(G);
            currNote++;
            break;
        case 10:
            buzzer_set_period(G);
            currNote++;
            break;
        case 11:
            buzzer_set_period(E);
            currNote++;
            break;
        case 12:
            buzzer_set_period(E);
            currNote++;
            break;
        case 13:
            buzzer_set_period(F);
            currNote++;
            break;
        case 14:
            buzzer_set_period(F);
            currNote++;
            break;
        case 15:
            buzzer_set_period(0);
            currNote++;
            break;
        case 16:
	  buzzer_set_period(0);
            currNote++;
            break;
        case 17:
            buzzer_set_period(0);
            currNote++;
            break;
        case 18:
            buzzer_set_period(F);
            currNote++;
            break;
        case 19:
            buzzer_set_period(F);
            currNote++;
            break;
        case 20:
          buzzer_set_period(D);
            currNote++;
            break;
        case 21:
            buzzer_set_period(D);
            currNote++;
            break;
        case 22:
            buzzer_set_period(E);
            currNote++;
            break;
        case 23:
            buzzer_set_period(E);
            currNote++;
            break;
        case 24:
            buzzer_set_period(0);
            currNote++;
            break;
        case 25:
            buzzer_set_period(0);
            currNote++;
            break;
        case 26:
          buzzer_set_period(0);
            currNote++;
            break;
        case 27:
            buzzer_set_period(F);
            currNote++;
            break;
        case 28:
            buzzer_set_period(F);
            currNote = 0;
            break;
        case 29:
            buzzer_set_period(D);
            currNote++;
            break;
        case 30:
            buzzer_set_period(D);
            currNote++;
            break;
        case 31:
            buzzer_set_period(E);
            currNote++;
            break;
        case 32:
            buzzer_set_period(E);
            currNote++;
            break;
        case 33:
            buzzer_set_period(0);
            currNote++;
            break;
        case 34:
            buzzer_set_period(0);
            currNote++;
            break;
        case 35:
            buzzer_set_period(0);
            currNote++;
            break;
        case 36:
            buzzer_set_period(E);
            currNote++;
            break;
        case 37:
            buzzer_set_period(D);
            currNote++;
            break;
        case 38:
            buzzer_set_period(C);
            currNote++;
            break;
        case 39:
            buzzer_set_period(B);
            currNote++;
            break;
        case 40:
            buzzer_set_period(0);
            currNote++;
            break;
        case 41:
            buzzer_set_period(E);
            currNote++;
            break;
	case 42:
            buzzer_set_period(0);
            currNote++;
            break;
        case 43:
            buzzer_set_period(D);
            currNote++;
            break;
        case 44:
            buzzer_set_period(0);
            currNote++;
            break;
	case 45:
            buzzer_set_period(A);
            currNote++;
            break;
        case 46:
            buzzer_set_period(0);
            currNote++;
            break;
        case 47:
            buzzer_set_period(G);
            currNote++;
            break;
	case 48:
            buzzer_set_period(0);
            currNote++;
            break;
        case 49:
            buzzer_set_period(E);
            currNote++;
            break;
        case 50:
            buzzer_set_period(G);
            currNote++;
            break;
	case 51:
            buzzer_set_period(F);
            currNote++;
            break;
        case 52:
            buzzer_set_period(E);
            currNote++;
            break;
        case 53:
            buzzer_set_period(B);
            currNote++;
            break;
	case 54:
            buzzer_set_period(A);
            currNote++;
            break;
        case 55:
            buzzer_set_period(G);
            currNote++;
            break;
        case 56:
            buzzer_set_period(0);
            currNote++;
            break;
	case 57:
            buzzer_set_period(E);
            currNote++;
            break;
        case 58:
            buzzer_set_period(0);
            currNote++;
            break;
        case 59:
            buzzer_set_period(C);
            currNote++;
            break;
        case 60:
            buzzer_set_period(0);
            currNote++;
            break;
        case 61:
            buzzer_set_period(B);
            currNote++;
            break;
	case 62:
            buzzer_set_period(0);
            currNote++;
            break;
        case 63:
            buzzer_set_period(A);
            currNote++;
            break;
        case 64:
            buzzer_set_period(0);
            currNote++;
            break;
        case 65:
            buzzer_set_period(G);
            currNote++;
            break;
        case 66:
            buzzer_set_period(0);
            currNote==0;
            break;
        default:
            currNote++;
            break;
    }
}


  
