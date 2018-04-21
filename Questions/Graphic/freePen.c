#include "graphics.h"  
#include "extgraph.h"  

void MouseEventProcess(int x, int y, int button, int event){   
    static double lx = 0, ly = 0;  
    double px, py; 
	 
    px = ScaleXInches(x);
    py = ScaleYInches(y);
     
     static bool isDraw = FALSE;  
   
     switch (event) {  
        case BUTTON_DOWN:  
            if (button == LEFT_BUTTON){  
                isDraw = TRUE;      
            }   
              break;  
        case BUTTON_UP:  
              if (button == LEFT_BUTTON) 
              isDraw = FALSE;  
              break;  
        case MOUSEMOVE:  
              if (isDraw) {  
                  DrawLine(px - lx, py - ly);  
                  MovePen(px, py);  
              }   
              break;  
        default: break;
    }    
    lx = px;  
    ly = py;  
}  
  
  
void Main (){  
    InitGraphics();           
    registerMouseEvent(MouseEventProcess);  
    SetPenSize(1);
} 
