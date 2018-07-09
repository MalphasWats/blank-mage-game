#include <avr/io.h>

#include "main.h"

word t = 0;
word btn_timer = 0;

int main (void) 
{    
    initialise();
        
    display_image(&LOGO[0], 3, 3, 10, 2);
    crap_beep(_A5, 140);
    delay_ms(5);
    crap_beep(_A8, 60);
    
    delay_ms(SPLASH_DELAY);
    
    for(ever)
    {
        t = millis();
        
        word btn_val = read_buttons();
        if (btn_timer == 0)
        {
            if (btn_val >= _UP-BTN_THRESHOLD && btn_val <= _UP+BTN_THRESHOLD)
            {
                click();
                btn_timer = t+BTN_DELAY;
            }
            else if(btn_val >= _DOWN-BTN_THRESHOLD && btn_val <= _DOWN+BTN_THRESHOLD)
            {
                click();
                btn_timer = t+BTN_DELAY;
            }
            else if(btn_val >= _LEFT-BTN_THRESHOLD && btn_val <= _LEFT+BTN_THRESHOLD)
            {
                click();
                btn_timer = t+BTN_DELAY;
            }
            else if(btn_val >= _RIGHT-BTN_THRESHOLD && btn_val <= _RIGHT+BTN_THRESHOLD)
            {
                click();
                btn_timer = t+BTN_DELAY;
            }
            else if(btn_val >= _A-BTN_THRESHOLD && btn_val <= _A+BTN_THRESHOLD)
            {
                click();
                btn_timer = t+BTN_DELAY;
            }
            else if(btn_val >= _B-BTN_THRESHOLD && btn_val <= _B+BTN_THRESHOLD)
            {
                click();
                btn_timer = t+BTN_DELAY;
            }
            else if(btn_val >= _C-BTN_THRESHOLD && btn_val <= _C+BTN_THRESHOLD)
            {
                click();
                btn_timer = t+BTN_DELAY;
            }
        }
        
        if (t >= btn_timer)
            btn_timer = 0;
        
        set_display_col_row(0, 0); // Technically not needed with SSD1306
        for (byte row=0 ; row<SCREEN_ROWS ; row++)
        {
            for (byte col=0 ; col<SCREEN_COLUMNS ; col++)
            {
                shift_out_block(&GLYPHS[MAP[ SCREEN_COLUMNS * row + col ]*8], FALSE);
            }
        }
    }
}
