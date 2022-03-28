#ifndef __ENV_CONTROL_H__
#define __ENV_CONTROL_H__

void EnvController_Init();

/**
  * @brief 环境控制器：温度降低，对应P3.1/TXD 1使能
  * @param 无
  * @retval 无
  */
void EnvController_TempretureDown(sbit EN);

/**
  * @brief 环境控制器：温度增加，对应P3.2/INT0 0使能
  * @param 无
  * @retval 无
  */
void EnvController_TempretureUp(sbit EN);

/**
  * @brief 环境控制器：湿度降低，对应P3.3/INT1 0使能
  * @param 无
  * @retval 无
  */
void EnvController_WedDown(sbit EN);

/**
  * @brief 环境控制器：湿度增加，对应P3.4/T0 1使能
  * @param 无
  * @retval 无
  */
void EnvController_Moisturize(sbit EN);

#endif