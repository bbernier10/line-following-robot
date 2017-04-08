void main()
{
    int a = 50;                 // declares integers to change speeds
    int b = 100;
    while(!start_button());     // waits for start button to be pressed
    while(1)
    {
        if(analog(4)<190)
        {
            if(analog(6)<180)   // go forward
            { 
                motor(1,a);
                motor(3,a);
            }
            else
            {
                motor(1,b);     // turn right
                motor(3,-b);
            }
        }
        else
        {
            if(analog(6)<180)   // turn left
            { 
                motor(1,-b);
                motor(3,b);
            }
            else
            {
                motor(1,-100);  // make the u-turn
                motor(3,-100);
                sleep(0.3);
                motor(1,b);
                motor(3,-b);
                sleep(0.5);
                while(analog(4)<190)
                {
                    motor(1,b);
                    motor(3,-b);
                }
                break;          // breaks while loop after u-turn to continue to new while loop
            }
        }
    }
    while(1)                    // new while loop allows robot to navigate back to starting point
    {  
        if(analog(4)<190)
        {
            if(analog(6)<180)   // go forward
            { 
                motor(1,a);
                motor(3,a);
            }
            else                //  turn right
            {
                motor(1,b); 
                motor(3,-b);
            }
        }
        else
        {
            if(analog(6)<180)   // turn left
            { 
                motor(1,-b);
                motor(3,b);
            }
            else                // reverses motors extremely fast to immediately stop them rather than continuing to roll forward
            {
                motor(1,-100);
                motor(3,-100);
                sleep(.2);
                break;
             }
         }
     }
    ao();                       // all motors off once back at starting line
}