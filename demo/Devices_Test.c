#include <REGX52.H>

#include "Delay.h"
#include "Buzzer.h"
#include "KeyboardIO.h"
#include "Typedef.h"
#include "LCD1602.h"
#include "Env_Control.h"

int main(){
    // LCD 屏幕初始化
    LCD_Init();

    //测试时延
    LCD_ShowString(1,1,"Test Delay");
    Delay(5000);
    //测试完成
    LCD_ShowString(2,1,"Delay Done");
    Delay(1000);

    //测试蜂鸣器
    LCD_ShowString(1,1,"Test Buzzer");
    Buzzer_beep(500);
    //测试完成
    LCD_ShowString(2,1,"Buzzer Done");
    Buzzer_alert();
    Delay(1000);

    //测试键盘
    LCD_ShowString(1,1,"Test Keyboard:");
    while(Keyboard() != KEY_OK){
        LCD_ShowString(1,17,Keyboard());
    }
    //测试完成
    Delay(500);
    Buzzer_alert();
    LCD_ShowString(2,1,"Buzzer Done");
    Delay(1000);

    //测试环境控制器
    LCD_ShowString(1,1,"Test EnvCtrl:");
    //初始化
    EnvController_Init();
    LCD_ShowString(2,1,"Init Done");
    Delay(500);
    
    //升温
    EnvController_TempretureUp(1);
    Delay(5000);
    EnvController_TempretureUp(0);
    LCD_ShowString(2,1,"TempretureUp");
    Delay(500);

    //降温
    EnvController_TempretureDown(1);
    Delay(5000);
    EnvController_TempretureDown(0);
    LCD_ShowString(2,1,"TempretureDown");
    Delay(500);

    //加湿
    EnvController_Moisturize(1);
    Delay(5000);
    EnvController_Moisturize(0);
    LCD_ShowString(2,1,"Moisturize");
    Delay(500);

    //祛湿
    EnvController_Drying(1);
    Delay(5000);
    EnvController_Moisturize(0);
    LCD_ShowString(2,1,"Drying");
    Delay(500);

    //测试完成
    Delay(500);
    Buzzer_alert();
    LCD_ShowString(2,1,"EnvCtrl Done");
    Delay(1000);


    Buzzer_notice();
    LCD_ShowString(1,1,"SelfCheck Done");
    Delay(1000);
    return 0;
}