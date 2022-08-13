#include <Arduino.h>

//Send and receive periodic inverter commands
void serviceInverter();
bool sendCommand(String com);
void sendMNCHGC(int val);
void sendMUCHGC(int val);


enum qCommand
{
  QPI,
  QID,
  QVFW,
  QVFW2,
  QPIRI,
  QFLAG,
  QPIGS,
  QMOD,
  QPIWS,
  QDI,
  QMCHGCR,
  QMUCHGCR,
  QBOOT,
  QOPM,
};

void requestInverter(qCommand);

struct QpiMessage
{
  byte protocolId;
};

struct QpigsMessage
{
  short gridV;
  short gridHz;
  short acOutV;
  short acOutHz;
  short acOutVa;
  short acOutW;
  short acOutPercent;
  short battV;  
  short battV_SCC;
  short battV_SCC_2;
  short battDischargeA;
  short battChargeA;
  short battPercent;
  short heatSinkDegC;
  short MPPT1_charger_temp;
  short MPPT2_charger_temp;
  short solarW_PV1;
  short solarW_PV2;
  short solarV_PV1;
  short solarV_PV2;
  short ConfigurationState;
  short MPPT1_Status;
  short MPPT2_Status;
  short LoadConn;
  short battDirection;
  short DC_AC_Direction;
  short LineDirection;
  short Parallel_ID;
};

struct QmodMessage
{
  char mode;
  String operationMode;
  byte operationMode_RAW;
};

struct QpiwsMessage
{
  bool reserved0;
  bool inverterFault;
  bool busOver;
  bool busUnder;
  bool busSoftFail;
  bool lineFail;
  bool opvShort;
  bool overTemperature;
  bool fanLocked;
  bool batteryVoltageHigh;
  bool batteryLowAlarm;
  bool reserved13;
  bool batteryUnderShutdown;
  bool reserved15;
  bool overload;
  bool eepromFault;
  bool inverterOverCurrent;
  bool inverterSoftFail;
  bool selfTestFail;
  bool opDcVoltageOver;
  bool batOpen;
  bool currentSensorFail;
  bool batteryShort;
  bool powerLimit;
  bool pvVoltageHigh;
  bool mpptOverloadFault;
  bool mpptOverloadWarning;
  bool batteryTooLowToCharge;
  bool reserved30;
  bool reserved31;
};

struct QflagMessage
{
  bool disableBuzzer;
  bool enableOverloadBypass;
  bool enablePowerSaving;
  bool enableLcdEscape;
  bool enableOverloadRestart;
  bool enableOvertempRestart;
  bool enableBacklight;
  bool enablePrimarySourceInterruptedAlarm;
  bool enableFaultCodeRecording;
};

//QPIRI<cr>: Device Rating Information inquiry
struct QpiriMessage
{
  float gridRatingV;   //Grid rating voltage
  float gridRatingA;   //Grid rating current
  float acOutRatingV;  //AC output rating voltage
  float acOutRatingHz; //AC output rating frequency
  float acOutRatingA;  //AC output rating current
  float acOutRatungVA; //AC output rating apparent power
  float acOutRatingW;  //AC output rating active power
  float battRatingV;   //Battery rating voltage
  float battreChargeV; //Battery re-charge voltage
  float battUnderV;    //Battery under voltage
  float battBulkV;     //Battery bulk voltage
  float battFloatV;    //Battery float voltage
  String battType;     //Battery type
  byte battMaxAcChrgA; //Current max AC charging current
  byte battMaxChrgA;   //Current max charging current
};
//for future use
struct QmdMessage
{
};

struct QidMessage
{
  char id[16];
};
struct QchgcrMessage
{
  byte chargeModes[12];
  byte uChargeModes[12];
};

//for raw answer from inverter
struct QRaw
{
  String QPIGS;
  String QPIRI;
  String QMOD;
  String QPIWS;
  String QFLAG;
  String QID;
  String QPI;
  String QET;
  String QT;
  String QMCHGCR;
  String QMUCHGCR;
  String P006FPADJ;
};
/*
struct QAv //Query Avaible
{
  bool QPIGS = true;
  bool QPIRI = true;
  bool QMOD = true;
  bool QPIWS = true;
  bool QFLAG = true;
  bool QID = true;
  bool QPI = true;
  bool QET = true;
  bool QT = true;
};*/
