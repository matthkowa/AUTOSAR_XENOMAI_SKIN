/*****************************************************************
 * 						Generated by Xpand Eclipse
 *						File :	Os_Cfg.h
 *						Date : 
 *						Author : Matthieu Kowalewski
 *						License : GPLv2
 ****************************************************************/
#ifndef _XENOMAI_AUTOSAR_OS_CFG_H
#define _XENOMAI_AUTOSAR_OS_CFG_H
/*********************** AppMode ***********************/
#define OsAppModeDefault_ID			1u	

#define OsAppModeDefault				(AppModeType)OsAppModeDefault_ID	

/************************ Tasks ************************/
#define OsTask_100ms_ID			1u	
#define OsTask_5ms_ID			2u	

#define OsTask_100ms				(TaskType)OsTask_100ms_ID	
#define OsTask_5ms				(TaskType)OsTask_5ms_ID	

/********************** Counters **********************/
#define SystemCounter_ID			1u	

#define SystemCounter				(CounterType)SystemCounter_ID	

/*********************** Alarms ***********************/
#define OsAlarm_100ms_ID			1u	
#define OsAlarm_5ms_ID			2u	

#define OsAlarm_100ms				(AlarmType)OsAlarm_100ms_ID	
#define OsAlarm_5ms				(AlarmType)OsAlarm_5ms_ID	

#endif //_XENOMAI_AUTOSAR_OS_CFG_H
