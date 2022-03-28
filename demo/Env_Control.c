#include <REGX52.H>

//端口配置
sbit TempretureDown = P3^1;
sbit TempretureUp = P3^2;
sbit Drying = P3^3;
sbit Moisturize = P3^4;

//函数定义
void EnvController_Init(){
    TempretureDown = 0;
    TempretureUp = 1;
    Drying = 1;
    Moisturize = 0;
}

/**
  * @brief 环境控制器：温度降低，对应P3.1/TXD 1使能
  * @param 使能控制 1 启用 0 禁用
  */
void EnvController_TempretureDown(sbit EN){
    switch (EN)
    {
    case 1:
        TempretureDown = 1; //启用
        break;
    case 0:
        TempretureDown = 0; //禁用
        break;
    default:
        break;
    }
}

/**
  * @brief 环境控制器：温度增加，对应P3.2/INT0 0使能
  * @param 使能控制 1 启用 0 禁用
  */
void EnvController_TempretureUp(sbit EN){
    switch (EN)
    {
    case 1:
        TempretureUp = 0; //启用
        break;
    case 0:
        TempretureUp = 1; //禁用
        break;
    default:
        break;
    }
}

/**
  * @brief 环境控制器：湿度降低，对应P3.3/INT1 0使能
  * @param 使能控制 1 启用 0 禁用
  */
void EnvController_Drying(sbit EN){
    switch (EN)
    {
    case 1:
        Drying = 0; //启用
        break;
    case 0:
        Drying = 1; //禁用
        break;
    default:
        break;
    }
}

/**
  * @brief 环境控制器：湿度增加，对应P3.4/T0 1使能
  * @param 使能控制 1 启用 0 禁用
  */
void EnvController_Moisturize(sbit EN){
    switch (EN)
    {
    case 1:
        Moisturize = 1; //启用
        break;
    case 0:
        Moisturize = 0; //禁用
        break;
    default:
        break;
    }
}