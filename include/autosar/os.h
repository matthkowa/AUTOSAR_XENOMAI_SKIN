
/*****************************************************************
 * 						Generated by Xpand Eclipse
 *						File :	os.h
 *						Date : 
 *						Author : Matthieu Kowalewski
 *						License : GPLv2
 ****************************************************************/
#ifndef _XENOMAI_AUTOSAR_OS_H
#define _XENOMAI_AUTOSAR_OS_H

#include <stdint.h>
#include "Std_Types.h"
#include "Rte_Type.h"
#include "Os_MemMap.h"
#include "Os_Cfg.h"

typedef uintptr_t AppModeType;

typedef uint8 StatusType;
#ifndef STATUSTYPEDEFINED 
#define STATUSTYPEDEFINED 
#define E_OK 							0
#endif

#define E_OS_ACCESS						1
#define	E_OS_CALLEVEL					2
#define	E_OS_ID							3
#define	E_OS_LIMIT						4
#define	E_OS_NOFUNC						5
#define	E_OS_RESOURCE					6
#define	E_OS_STATE						7
#define	E_OS_VALUE						8	


extern AppModeType GetActiveApplicationMode(void);

extern void StartOS (AppModeType mode);

extern void ShutdownOS (StatusType Error);

/********************************** TASK *********************************/

#define RUNNING 						0
#define WAITING 						1
#define READY							2
#define SUSPENDED						3
#define INVALID_TASK					-1


#define TASK(taskID) void taskID##_function()
#define DeclareTask(taskID) extern const TaskType taskID;

typedef uintptr_t TaskType;

typedef TaskType * TaskRefType;

typedef uintptr_t TaskStateType;

typedef TaskStateType * TaskStateRefType; 


extern StatusType ActivateTask(TaskType taskId);

extern StatusType TerminateTask(void);

extern StatusType ChainTask(TaskType taskId);

extern StatusType Schedule(void);

extern StatusType GetTaskID(TaskRefType taskId);

extern StatusType GetTaskState(TaskType taskId, TaskStateRefType state);

/****************************** END OF TASK ******************************/
/********************************** ALARM ********************************/
#define DeclareAlarm(alarmID) extern AlarmType alarmID;
typedef uintptr_t TickType;
typedef TickType * TickRefType;
typedef struct AlarmBaseType AlarmBaseType;
struct AlarmBaseType{
	TickType maxallowedvalue;
	TickType ticksperbase;
	TickType mincycle;
};

typedef AlarmBaseType * AlarmBaseRefType;
typedef uintptr_t AlarmType;

extern StatusType GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info);

extern StatusType GetAlarm(AlarmType AlarmID, TickRefType Tick);

extern StatusType SetRelAlarm(AlarmType AlarmID, TickType increment, TickType cycle);

extern StatusType SetAbsAlarm(AlarmType AlarmID, TickType start, TickType cycle);

extern StatusType CancelAlarm(AlarmType AlarmID);
/****************************** END OF ALARM *****************************/
/******************************** COUNTER ********************************/

typedef uintptr_t CounterType;
#define DeclareCounter(counterID) extern const CounterType counterID;
extern StatusType IncrementCounter(CounterType counterID);
extern StatusType GetCounterValue(CounterType CounterID,TickRefType Value);
extern StatusType GetElapsedValue(CounterType CounterID,TickRefType Value,TickRefType ElapsedValue);

/***************************** END OF COUNTER ****************************/
/******************************** RESOURCE *******************************/
typedef uintptr_t ResourceType;
#define DeclareResource(resourceID) extern const ResourceType resourceID;

extern StatusType GetResource(ResourceType ResID);

extern StatusType ReleaseResource(ResourceType ResID);

/**************************** END OF RESOURCE ****************************/
/********************************** ISR **********************************/
#define ISR(ISRType) void ISRType##_routine()
typedef uintptr_t ISRType;

extern ISRType GetISRID(void);
extern void EnableAllInterrupts(void);
extern void DisableAllInterrupts(void);
extern void ResumeAllInterrupts(void);
extern void SuspendAllInterrupts(void);
extern void ResumeOSInterrupts(void);
extern void SuspendOSInterrupts(void);

/******************************* END OF ISR ******************************/
/********************************* EVENT *********************************/
/*
typedef uintptr_t EventMaskType;
typedef EventMaskType * EventMaskRefType;

extern StatusType SetEvent(TaskType TaskID, EventMaskType Mask);
extern StatusType ClearEvent(EventMaskType Mask);
extern StatusType GetEvent(TaskType TaskID,EventMaskRefType Event);
extern StatusType WaitEvent(EventMaskType Mask);
*/
/****************************** END OF EVENT *****************************/
/********************************** HOOK *********************************/

typedef uintptr_t OSServiceIdType;
extern OSServiceIdType OSErrorGetServiceId(void);

/* Task */
#define OSServiceId_ActivateTask 				1
#define OSServiceId_TerminateTask 				2
#define OSServiceId_ChainTask 					3
#define OSServiceId_Schedule					4
#define OSServiceId_GetTaskID 					5
#define OSServiceId_GetTaskState				6

extern TaskType OSError_ActivateTask_TaskID(void);
extern TaskType OSError_ChainTask_TaskID(void);
extern TaskType OSError_GetTaskID_TaskID(void);
extern TaskType OSError_GetTaskState_TaskID(void);
extern TaskStateRefType OSError_GetTaskState_State(void);


/* Interrupt */
#define OSServiceId_EnableAllInterrupts 		7
#define OSServiceId_DisableAllInterrupts		8
#define OSServiceId_ResumeAllInterrupts			9
#define OSServiceId_SuspendAllInterrupts		10
#define OSServiceId_ResumeOSInterrupts			11
#define OSServiceId_SuspendOSInterrupts			12

/* Resource */
#define OSServiceId_GetResource					13
#define OSServiceId_ReleaseResource				14

/* Event */
#define OSServiceId_SetEvent					15
#define OSServiceId_ClearEvent					16
#define OSServiceId_GetEvent					17
#define OSServiceId_WaitEvent					18

/* Alarm */
#define OSServiceId_GetAlarmBase				19
#define OSServiceId_GetAlarm					20
#define OSServiceId_SetRelAlarm					21
#define OSServiceId_SetAbsAlarm					22
#define OSServiceId_CancelAlarm					23

extern AlarmType OSError_GetAlarmBase_AlarmID(void);
extern AlarmBaseRefType OSError_GetAlarmBase_Info(void);
extern AlarmType OSError_GetAlarm_AlarmID(void);
extern TickRefType OSError_GetAlarm_Tick(void);
extern AlarmType OSError_SetRelAlarm_AlarmID(void);
extern TickType OSError_SetRelAlarm_increment(void);
extern TickType OSError_SetRelAlarm_cycle(void);
extern AlarmType OSError_SetAbsAlarm_AlarmID(void);
extern TickType OSError_SetAbsAlarm_start(void);
extern TickType OSError_SetAbsAlarm_cycle(void);
extern AlarmType OSError_CancelAlarm_AlarmID(void);


/* OS */
#define OSServiceId_GetActiveApplicationMode	24
#define OSServiceId_StartOS						25
#define OSServiceId_ShutdownOS					26


/****************************** END OF HOOK ******************************/
/********************************** DIO **********************************/

typedef uint32 Dio_ChannelType;
typedef uint32 Dio_PortType;

struct Dio_ChannelGroup {
        uint32 mask;
        uint8 offset;
        Dio_PortType port;
};

typedef struct Dio_ChannelGroup Dio_ChannelGroupType;

typedef uint8 Dio_LevelType;
//#define STD_LOW         (Dio_LevelType)0
//#define STD_HIGH        (Dio_LevelType)1
typedef uint32 Dio_PortLevelType;

struct Dio_ConfigType {


};

extern Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
extern void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level);
extern Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
extern void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);
extern Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType * ChannelGroupIdPtr);
extern void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);
extern void Dio_GetVersionInfo(Std_VersionInfoType * VersionInfo);
extern Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
/****************************** END OF DIO *******************************/


#endif /* _XENOMAI_AUTOSAR_OS_H */
