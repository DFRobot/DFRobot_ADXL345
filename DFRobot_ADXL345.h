/*!
 * @file DFRobot_ADXL345.h
 * @brief 这是一个六自由度传感器库
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      PengKaixing(kaixing.peng@dfrobot.com)
 * @version  V2.0.0
 * @date  2022-02-22
 * @url https://github.com/DFRobot/DFRobot_ADXL345
 */
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

/* -- ADXL345 addresses --*/
// ADXL345 address when SDO is connected to HIGH
#define ADXL345_ADDR_ALT_HIGH 0x1D
// ADXL345 address when SDO is connected to LOW
#define ADXL345_ADDR_ALT_LOW  0x53 
#define TO_READ 6
/* -- register --*/
#define ADXL345_DEVID 0x00
#define ADXL345_RESERVED1 0x01
#define ADXL345_THRESH_TAP 0x1d
#define ADXL345_OFSX 0x1e
#define ADXL345_OFSY 0x1f
#define ADXL345_OFSZ 0x20
#define ADXL345_DUR 0x21
#define ADXL345_LATENT 0x22
#define ADXL345_WINDOW 0x23
#define ADXL345_THRESH_ACT 0x24
#define ADXL345_THRESH_INACT 0x25
#define ADXL345_TIME_INACT 0x26
#define ADXL345_ACT_INACT_CTL 0x27
#define ADXL345_THRESH_FF 0x28
#define ADXL345_TIME_FF 0x29
#define ADXL345_TAP_AXES 0x2a
#define ADXL345_ACT_TAP_STATUS 0x2b
#define ADXL345_BW_RATE 0x2c
#define ADXL345_POWER_CTL 0x2d
#define ADXL345_INT_ENABLE 0x2e
#define ADXL345_INT_MAP 0x2f
#define ADXL345_INT_SOURCE 0x30
#define ADXL345_DATA_FORMAT 0x31
#define ADXL345_DATAX0 0x32
#define ADXL345_DATAX1 0x33
#define ADXL345_DATAY0 0x34
#define ADXL345_DATAY1 0x35
#define ADXL345_DATAZ0 0x36
#define ADXL345_DATAZ1 0x37
#define ADXL345_FIFO_CTL 0x38
#define ADXL345_FIFO_STATUS 0x39
/* -- data rate --*/
#define ADXL345_BW_1600 0xF // 1111
#define ADXL345_BW_800 0xE  // 1110
#define ADXL345_BW_400 0xD  // 1101
#define ADXL345_BW_200 0xC  // 1100
#define ADXL345_BW_100 0xB  // 1011
#define ADXL345_BW_50 0xA   // 1010
#define ADXL345_BW_25 0x9   // 1001
#define ADXL345_BW_12 0x8   // 1000
#define ADXL345_BW_6 0x7    // 0111
#define ADXL345_BW_3 0x6    // 0110
/* -- interrupt PIN--*/
#define ADXL345_INT1_PIN 0x00
#define ADXL345_INT2_PIN 0x01
/* -- interrupt BIT--*/
#define ADXL345_INT_DATA_READY_BIT 0x07
#define ADXL345_INT_SINGLE_TAP_BIT 0x06
#define ADXL345_INT_DOUBLE_TAP_BIT 0x05
#define ADXL345_INT_ACTIVITY_BIT 0x04
#define ADXL345_INT_INACTIVITY_BIT 0x03
#define ADXL345_INT_FREE_FALL_BIT 0x02
#define ADXL345_INT_WATERMARK_BIT 0x01
#define ADXL345_INT_OVERRUNY_BIT 0x00
/* -- interrupts mask--*/
#define ADXL345_DATA_READY 0x07
#define ADXL345_SINGLE_TAP 0x06
#define ADXL345_DOUBLE_TAP 0x05
#define ADXL345_ACTIVITY 0x04
#define ADXL345_INACTIVITY 0x03
#define ADXL345_FREE_FALL 0x02
#define ADXL345_WATERMARK 0x01
#define ADXL345_OVERRUNY 0x00

// initial state
#define ADXL345_NO_ERROR 0
// problem reading accel
#define ADXL345_READ_ERROR 1
// bad method argument
#define ADXL345_BAD_ARG 2    

class DFRobot_ADXL345
{
  public:
    /**
    * @struct sRP_t
    * @brief Roll & Pitch are the angles which rotate by the axis X and y
    */
    typedef struct
    {
      double roll;
      double pitch;
    }sRP_t;

    /**
     * @fn begin
     * @return bool类型，表示返回初始化的状态
     * @retval true 初始化成功
     * @retval false 初始化失败
     */
    bool begin(void);

    /**
     * @fn powerOn
     * @brief 使能ADXL345模块
     */
    void powerOn(void);

    /**
     * @fn readAccel(int *xyz)
     * @brief 获取加速度
     * @param xyx 存储x轴,y轴,z轴数据
     */
    void readAccel(int *xyz);

    /**
     * @fn setTapThreshold
     * @brief 设置敲击触发阈值
     * @param tapThreshold 阈值
     */
    void setTapThreshold(int tapThreshold);

    /**
     * @fn getTapThreshold
     * @brief 获取敲击触发阈值
     * @return int类型 返回敲击触发阈值
     */
    int getTapThreshold(void);

    /**
     * @fn setTapDuration
     * @brief 设置敲击持续时间
     * @param tapDuration 持续时间
     */
    void setTapDuration(int tapDuration);

    /**
     * @fn getTapDuration
     * @brief 获取敲击持续时间
     * @return int类型 表示持续时间
     */
    int getTapDuration(void);

    /**
     * @fn setDoubleTapLatency
     * @brief 设置双击延迟时间
     * @param floatTapLatency 延迟时间
     */
    void setDoubleTapLatency(int floatTapLatency);

    /**
     * @fn getDoubleTapLatency
     * @brief 获取双击延迟时间
     * @return int类型 表示延迟时间
     */
    int getDoubleTapLatency(void);

    /**
     * @fn setDoubleTapWindow
     * @brief 设置双击窗
     * @param floatTapWindow 双击窗
     */
    void setDoubleTapWindow(int floatTapWindow);

    /**
     * @fn getDoubleTapWindow
     * @brief 获取双击窗
     * @return int类型 表示点击窗
     */
    int getDoubleTapWindow(void);

    /**
     * @fn setActivityThreshold
     * @brief 设置活动阈值
     * @param activityThreshold 活动阈值
     */
    void setActivityThreshold(int activityThreshold);

    /**
     * @fn getActivityThreshold
     * @brief 获取活动阈值
     * @return int类型 表示活动阈值
     */
    int getActivityThreshold(void);

    /**
     * @fn setInactivityThreshold
     * @brief 设置缺乏运动阈值
     * @param inactivityThreshold 缺乏运动阈值
     */
    void setInactivityThreshold(int inactivityThreshold);

    /**
     * @fn getInactivityThreshold
     * @brief 获取缺乏运动阈值
     * @return int类型 表示缺乏运动阈值
     */
    int getInactivityThreshold(void);

    /**
     * @fn setTimeInactivity
     * @brief 设置不活动时间
     * @param timeInactivity 不活动时间
     */
    void setTimeInactivity(int timeInactivity);

    /**
     * @fn getTimeInactivity
     * @brief 获取不活动时间
     * @return int类型 表示不活动时间
     */
    int getTimeInactivity(void);

    /**
     * @fn setFreeFallThreshold
     * @brief 设置自由落体阈值
     * @param timeInactivity 自由落体阈值
     */
    void setFreeFallThreshold(int freeFallthreshold);

    /**
     * @fn getFreeFallThreshold
     * @brief 获取自由落体阈值
     * @return int 自由落体阈值
     */
    int getFreeFallThreshold(void);

    /**
     * @fn setFreeFallDuration
     * @brief 设置自由落体持续时间
     * @param timeInactivity 自由落体持续时间
     */
    void setFreeFallDuration(int freeFallDuration);

    /**
     * @fn getFreeFallThreshold
     * @brief 获取自由落体持续时间
     * @return int类型 表示自由落体持续时间
     */
    int getFreeFallDuration(void);

    /**
     * @fn isActivityXEnabled
     * @brief 是否启用活动X轴
     * @return bool类型，表示是否启用活动X轴
     * @retval true 启用
     * @retval false 不启用
     */
    bool isActivityXEnabled(void);

    /**
     * @fn isActivityYEnabled
     * @brief 是否启用活动Y轴
     * @return bool类型，表示是否启用活动Y轴
     * @retval true 启用
     * @retval false 不启用
     */
    bool isActivityYEnabled(void);

    /**
     * @fn isActivityZEnabled
     * @brief 是否启用活动Z轴
     * @return bool类型，表示是否启用活动Z轴
     * @retval true 启用
     * @retval false 不启用
     */
    bool isActivityZEnabled(void);

    /**
     * @fn isInactivityXEnabled
     * @brief 是否启用不活动X
     * @return bool类型，表示是否启用不活动X
     * @retval true 启用
     * @retval false 不启用
     */
    bool isInactivityXEnabled(void);

    /**
     * @fn isInactivityYEnabled
     * @brief 是否启用不活动Y
     * @return bool类型，表示是否启用不活动Y
     * @retval true 启用
     * @retval false 不启用
     */
    bool isInactivityYEnabled(void);

    /**
     * @fn isInactivityZEnabled
     * @brief 是否启用不活动Z
     * @return 是否启用不活动Z
     * @retval true 启用
     * @retval false 不启用
     */
    bool isInactivityZEnabled(void);

    /**
     * @fn isTapDetectionOnX
     * @brief 是否在X上点击检测
     * @return  bool类型，表示是否点击
     * @retval  1 点击
     * @retval  0 不点击
     */
    bool isTapDetectionOnX(void);

    /**
     * @fn setTapDetectionOnX
     * @brief 设置在X上点击检测
     * @param state 状态
     * @n           1 点击
     * @n           0 不点击
     */
    void setTapDetectionOnX(bool state);

    /**
     * @fn isTapDetectionOnY
     * @brief 是否在Y上点击检测
     * @return  bool类型，表示是否点击
     * @retval  1 点击
     * @retval  0 不点击
     */
    bool isTapDetectionOnY(void);

    /**
     * @fn setTapDetectionOnY
     * @brief 设置在Y上点击检测
     * @param state 状态
     * @n           1 点击
     * @n           0 不点击
     */
    void setTapDetectionOnY(bool state);

    /**
     * @fn isTapDetectionOnZ
     * @brief 是否在Z上点击检测
     * @return  bool类型，表示是否点击
     * @retval  1 点击
     * @retval  0 不点击
     */
    bool isTapDetectionOnZ(void);

    /**
     * @fn setTapDetectionOnZ
     * @brief 设置在Z上点击检测
     * @param state 状态
     * @n           1 点击
     * @n           0 不点击
     */
    void setTapDetectionOnZ(bool state);

    /**
     * @fn setActivityX
     * @brief 设置X活动
     * @param state 活动状态
     * @n           1 活动
     * @n           0 不活动
     */
    void setActivityX(bool state);

    /**
     * @fn setActivityY
     * @brief 设置Y活动
     * @param state 活动状态
     * @n           1 活动
     * @n           0 不活动
     */
    void setActivityY(bool state);

    /**
     * @fn setActivityZ
     * @brief 设置Z活动
     * @param state 活动状态
     * @n           1 活动
     * @n           0 不活动
     */
    void setActivityZ(bool state);

    /**
     * @fn setInactivityX
     * @brief 设置X轴不活动
     * @param state 活动状态
     * @n           0 活动
     * @n           1 不活动
     */
    void setInactivityX(bool state);

    /**
     * @fn setInactivityY
     * @brief 设置Y轴不活动
     * @param state 活动状态
     * @n           0 活动
     * @n           1 不活动
     */
    void setInactivityY(bool state);

    /**
     * @fn setInactivityZ
     * @brief 设置Z轴不活动
     * @param state 活动状态
     * @n           0 活动
     * @n           1 不活动
     */
    void setInactivityZ(bool state);

    /**
     * @fn isActivitySourceOnX
     * @brief 活动源在X上吗
     * @return  是否在X上
     * @retval  1 在
     * @retval  0 不在
     */
    bool isActivitySourceOnX(void);

    /**
     * @fn isActivitySourceOnY
     * @brief 活动源在Y上吗
     * @return  bool类型，表示是否在Y上
     * @retval  1 在
     * @retval  0 不在
     */
    bool isActivitySourceOnY(void);

    /**
     * @fn isActivitySourceOnZ
     * @brief 活动源在Z上吗
     * @return  bool类型，表示是否在Z上
     * @retval  1 在
     * @retval  0 不在
     */
    bool isActivitySourceOnZ(void);

    /**
     * @fn isTapSourceOnX
     * @brief 点击源是否在X上
     * @return  bool类型，表示点击源是否在X上
     * @retval  1 在
     * @retval  0 不在
     */
    bool isTapSourceOnX(void);

    /**
     * @fn isTapSourceOnY
     * @brief 点击源是否在Y上
     * @return  bool类型，表示点击源是否在Y上
     * @retval  1 在
     * @retval  0 不在
     */
    bool isTapSourceOnY(void);

    /**
     * @fn isTapSourceOnZ
     * @brief 点击源是否在Z上
     * @return  bool类型，表示点击源是否在Z上
     * @retval  1 在
     * @retval  0 不在
     */
    bool isTapSourceOnZ(void);

    /**
     * @fn isAsleep
     * @brief 点击源是否休眠
     * @return  bool类型，表示休眠状态
     * @retval  1 休眠
     * @retval  0 不休眠
     */
    bool isAsleep(void);

    /**
     * @fn isLowPower
     * @brief 是否处于低功耗模式
     * @return  bool类型，表示模式
     * @retval  0 正常模式
     * @retval  1 低功耗模式
     */
    bool isLowPower(void);

    /**
     * @fn setLowPower
     * @brief 设置低功耗模式
     * @param state 功耗模式
     * @n           0 正常模式
     * @n           1 低功耗模式
     */
    void setLowPower(bool state);

    /**
     * @fn getRate
     * @brief 获取采集速率
     * @return  float类型，表示采集速率
     */
    float getRate(void);

    /**
     * @fn setRate
     * @brief 设置采集速率
     * @param rate 采集速率
     */
    void setRate(float rate);

    /**
     * @fn setBwcode
     * @brief 设置数据速率和功率模式
     * @param bw_code 速率和功率
     * @n             ADXL345_BW_1600 0xF 
     * @n             ADXL345_BW_800 0xE  
     * @n             ADXL345_BW_400 0xD  
     * @n             ADXL345_BW_200 0xC  
     * @n             ADXL345_BW_100 0xB  
     * @n             ADXL345_BW_50 0xA   
     * @n             ADXL345_BW_25 0x9   
     * @n             ADXL345_BW_12 0x8   
     * @n             ADXL345_BW_6 0x7    
     * @n             ADXL345_BW_3 0x6    
     */
    void setBwcode(uint8_t bw_code);

    /**
     * @fn getBwcode
     * @brief 获取数据速率和功率模式
     * @return  uint8_t类型
     */
    uint8_t getBwcode(void);

    /**
     * @fn getInterruptSource(void)
     * @brief 获取中断源
     * @return  uint8_t类型,表示中断源
     */
    uint8_t getInterruptSource(void);

    /**
     * @fn getInterruptSource(uint8_t interruptBit)
     * @brief 获取是否开启中断源
     * @param   interruptBit 中断位
     * @return  bool类型,表示是否开启中断源
     * @retval  true 中断
     * @retval  false 不中断
     */
    bool getInterruptSource(uint8_t interruptBit);

    /**
     * @fn getInterruptMapping
     * @brief 获取中断映射图
     * @param   interruptBit 中断位
     * @return  bool类型，表示获取是否成功
     * @retval  true 成功
     * @retval  false 失败
     */
    bool getInterruptMapping(uint8_t interruptBit);

    /**
     * @fn setInterruptMapping
     * @brief 设置中断映射图
     * @param   interruptBit 中断位
     * @param   interruptPin 中断引脚
     */
    void setInterruptMapping(uint8_t interruptBit, bool interruptPin);

    /**
     * @fn isInterruptEnabled
     * @brief 中断是否使能
     * @param   interruptBit 中断位
     * @return  bool类型，表示中断是否使能
     * @retval  true 使能
     * @retval  false 没使能
     */
    bool isInterruptEnabled(uint8_t interruptBit);

    /**
     * @fn setInterrupt
     * @brief 设置中断是否使能
     * @param   interruptBit 中断位
     * @param   state 状态
     * @n       true  使能
     * @n       false 不使能     
     */
    void setInterrupt(uint8_t interruptBit, bool state);

    /**
     * @fn getRangeSetting
     * @brief 获取范围设置项
     * @param   rangeSetting 用来存储范围设置项
     */
    void getRangeSetting(uint8_t *rangeSetting);

    /**
     * @fn setRangeSetting
     * @brief 设置范围设置项
     * @param   val 设置项
     */
    void setRangeSetting(int val);

    /**
     * @fn getInterruptLevelBit
     * @brief 获取INT_INVERT位的状态
     * @return  bool类型，INT_INVERT位状态
     */
    bool getInterruptLevelBit(void);

    /**
     * @fn setInterruptLevelBit
     * @brief 设置INT_INVERT位的状态
     * @param interruptLevelBit INT_INVERT位状态
     */
    void setInterruptLevelBit(bool interruptLevelBit);

    /**
     * @fn getFullResBit
     * @brief 获取FULL_RES位的状态
     * @return  bool类型，FULL_RES位的状态
     */
    bool getFullResBit(void);

    /**
     * @fn setFullResBit
     * @brief 设置FULL_RES位的状态
     * @param fullResBit FULL_RES位的状态
     */
    void setFullResBit(bool fullResBit);

    /**
     * @fn getJustifyBit
     * @brief 获取对齐位的状态
     * @return  bool类型，对齐位的状态
     */
    bool getJustifyBit(void);

    /**
     * @fn setJustifyBit
     * @brief 设置对齐位的状态
     * @param justifyBit 对齐位的状态
     */
    void setJustifyBit(bool justifyBit);

    /**
     * @fn RPCalculate
     * @brief 获取三轴加速度的数据，按照R-xyz旋转顺序时的Roll及Pitch角
     * @param data_buf  三轴加速度实际数据
     */
    void RPCalculate(int*data_buf);

    /**
     * @fn triggered
     * @brief 检测中断触发源
     * @param interrupts 获取到的中断源寄存器的数值
     * @param mask 需要检测的目标掩码
     */
    bool triggered(byte interrupts, int mask);

    /**
     * @fn inactivityInt
     * @brief 设置是否开启中断
     * @param status 获取到的中断源寄存器的数值
     */
    void inactivityInt(bool status);

    /**
     * @fn activityInt
     * @brief 设置是否开启中断
     * @param status 获取到的中断源寄存器的数值
     */
    void activityInt(bool status);

    /**
     * @fn freeFallInt
     * @brief 设置自由落体事件是否开启中断
     * @param status 获取到的中断源寄存器的数值
     */
    void freeFallInt(bool status);

    /**
     * @fn doubleTapInt
     * @brief 设置双击事件是否开启中断
     * @param status 获取到的中断源寄存器的数值
     */
    void doubleTapInt(bool status);

    /**
     * @fn singleTapInt
     * @brief 设置单击事件是否开启中断
     * @param status 获取到的中断源寄存器的数值
     */
    void singleTapInt(bool status);

    sRP_t RP;   
    bool status;     // set when error occurs
    uint8_t error_code; // Initial state
    float gains[3];  // counts to Gs
  private:
    uint8_t _buff[6];
    void readAccel(int *x, int *y, int *z);
    virtual void writeData(uint8_t reg, void *pdata, uint8_t len)=0;
    virtual int16_t readData(uint8_t reg, uint8_t *data, uint8_t len)=0;
    void setRegisterBit(uint8_t regAdress, int bitPos, bool state);
    bool getRegisterBit(uint8_t regAdress, int bitPos);
};

class DFRobot_ADXL345_I2C:public DFRobot_ADXL345
{
  public:
    DFRobot_ADXL345_I2C(TwoWire *pWire = &Wire, uint8_t I2C_addr = 0x53);
    bool begin(void);
    void writeData(uint8_t reg, void *pdata, uint8_t len);
    int16_t readData(uint8_t reg, uint8_t *data, uint8_t len);
  private:
    TwoWire* _pWire;
    uint8_t _I2C_addr;
};

class DFRobot_ADXL345_SPI : public DFRobot_ADXL345
{
  public:
    DFRobot_ADXL345_SPI(SPIClass *spi = &SPI, uint8_t csPin = 10);
    bool begin(void);
  protected:
    void writeData(uint8_t reg, void *pdata, uint8_t len);
    int16_t readData(uint8_t reg, uint8_t *data, uint8_t len);
  private:
    SPIClass *_pSpi;
    uint8_t _csPin;
};