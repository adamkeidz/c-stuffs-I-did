// Task 5.2: Counter/Timer
//
// Explain purpose of the program here and how it works
// Be brief but complete
//
// Inputs: User button
// External button <-- PC_3
//
// Outputs: 7-segment disp 1 --> A_PA_0, B_PA_1, C_PA_4, D_PC_2, E_PC_3, F_PC_15, G_PC_14, DP_PB_0
//          7-segment disp 2 --> A_PC_6, B_PC_5, C_PC_8, D_PB_8, E_PB_9, F_PA_6, G_PA_5, DP_PC_9, 
// 
//
// Due Date : 29/10/2020
// Name : Ahmad Adam Bin Che Alang Idin
// Matric : 17003571

#include "mbed.h"
#include "TextLCD.h"
#include "buzzer.h"
#include "keypad.h"
//declaring port for each seven segment
TextLCD lcd(PC_0,PC_1,PB_13,PB_14,PB_15,PB_1, TextLCD::LCD16x2);
BusOut sevseg1(PC_10, PB_7, PA_8, PC_3, PC_2, PA_4, PA_1, PA_0);
BusOut sevseg2(PC_9, PC_7, PA_7, PB_9, PB_8, PC_8, PC_5, PC_6);
//DigitalOut krow[4] = {PC_4,PA_10,PA_2,PA_3};
                //    r1,  r2,  r3,  r4
//DigitalIn kcol[4] = {PB_3,PB_5,PB_4,PB_10};
                //   c1,  c2,  c3,  c4
DigitalOut myled(PA_13);
DigitalOut myled1(PB_2);

Beep buz(PA_9);
DigitalIn sens(PB_0);
Keypad kiped(PB_3,PB_5,PB_4,PB_10,PC_4,PA_10,PA_2,PA_3);
//float F_4 = 1000000/Fa4;
//int tones = F_4;


//char Data[16];
//int data_count = 0;

/*unsigned char keytable[]={ //keypad buttons char
    '1','2','3','A',
    '4','5','6','B',
    '7','8','9','C',
    '*','0','#','D'
};*/

/*char read_keypad(){     //function for read of keypad
    for(int r=0; r<4; r++){
        krow[r] = 0;
        for(int c=0; c<4; c++){
            if( !kcol[c] ){
                return keytable[r*4+c];
            }
        }
        krow[r] = 1;
    }
    return 0;
}*/
char key;                   //variable for keypad

void testKeypad(){

    kiped.enablePullUp();
    //printf("Please touch a key on the keypad\n\r");
    char key;
    int v =0;
    while (v != 16) {
        key = kiped.getKey();
        if(key != KEY_RELEASED){
        //printf("%c\r\n",key);
        lcd.locate(0,0);
        lcd.printf("Pressed %c\r\n",key);
        wait_us(500000);
        v++;
        }
        
        if (key=='0') {
            break;
        }
    }
}

const char bcd7sd[10]={           //Assign numbers to the arrays
                                    0b00000011, //0
                                    0b10011111, //1
                                    0b00100101, //2
                                    0b00001101, //3
                                    0b10011001, //4
                                    0b01001001, //5
                                    0b01000001, //6
                                    0b00011111, //7
                                    0b00000001, //8
                                    0b00001001  //9
                                    };
void testroutine(){
    sevseg1=bcd7sd[1];
    sevseg2=bcd7sd[1];
    myled = 0;
    myled1= 0;        

    lcd.locate(0,0);
    lcd.printf("halo");
    lcd.locate(0,1);
    lcd.printf("olah");
    /*if(k == 1){
    lcd.printf("Hello");
    } else {
        lcd.printf("Hi");
        }*/
    
    //Tune(buz, F_4, 4);
    wait_us(100000);
    //Stop_tunes(buz);
    /*for(int i=0; i<=9; i++){
         sevseg1 = bcd7sd[i]; 
         sevseg2 = bcd7sd[i];
         wait_us(5000000); 
         }*/
       // myled = 1;
        //myled1= 1;
    
    float k = sens.read();

    while(1){
    testKeypad();
    if(k != 0){
    lcd.printf("Hello");
    sevseg1=bcd7sd[8];
    sevseg2=bcd7sd[1];
    } else {
        lcd.printf("Hi");
        sevseg2=bcd7sd[8];
        sevseg1=bcd7sd[1];
        }
        

            
        }
    }
    
int cne =0;
void chek(){
    key = kiped.getKey();
    char kiy = kiped.getKey();
    while (1)
    if(key != KEY_RELEASED){
        if (key != '1'){
            chek();     
        }else{
            if(kiy == 9){
            cne =50;
            break;
            }    
        }
    }
}

bool isEven(int x){
    if (x % 2 == 0){
        return true;    
    }else{
        return false;
    }
}
void closed(){
    int b,u,v =0;
    lcd.cls();
    while (1){
        b++;
        lcd.locate(0,0);
        lcd.printf("Door is closed");
        lcd.locate(0,1);
        lcd.printf("%d seconds", b);
        if(isEven(b)){
            myled = 0;
            myled1 = 1;
        }else{
            myled = 1;
            myled1 = 0;
        }
        u = b /10;
        v = b %10;
        sevseg1 = bcd7sd[u];
        sevseg2 = bcd7sd[v];
        wait_us(1000000);
    }
}

void openn(){
    int t,u,v=0;
    key = kiped.getKey();
    char kiy = kiped.getKey();
    sevseg1 = bcd7sd[8];
    sevseg2 = bcd7sd[8];
    
    //buz.beep(1000,4);
    //timmer(15);
    
    while (cne==0){
        //t = v;
        lcd.locate(0,0);
        lcd.printf("Door is opened");
        lcd.locate(0,1);
        lcd.printf("%d seconds", t);
        if(isEven(t)){
            myled = 0;
            myled1 = 1;
        }else{
            myled = 1;
            myled1 = 0;
        }
        t++;
        wait_us(1000000);
        //chek();
        if(key != KEY_RELEASED){
        //wait_us(5000000);
            continue;
        }else{
            lcd.cls();
            lcd.printf("insert");
            wait_us(5000000);
            //cne=50;
            if (key != '1'){
                continue;     
            }else{
                lcd.cls();
                lcd.printf("Another 1");
                if(kiy == '1'){
                    cne =50;
                    continue;
                }else{
                    break;
                }    
            }     
        }
        //v = t;
    }
    //t=0;
    //lcd.cls();
    //closed();   
}
//declaring button 
InterruptIn btn1(BUTTON1);


//main starts here
int main(){
    /* Optional: set mode as PullUp/PullDown/PullNone/OpenDrain */
    sens.mode(PullNone);
    int r = sens.read();
    //timmer(10);
    while (1){
        if (r == 0){
            closed();
            //openn();
        }else{
            openn();
            //closed();   
        }
        
    }
    //testKeypad();
}