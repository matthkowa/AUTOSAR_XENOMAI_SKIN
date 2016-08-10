/**
 *
 *	\file os_appmode.h
 *	\brief AppMode header
 *	\author  Matthieu K.
 *	\version 0.1
 *	\date 29 Juin 2016
*/
#ifndef _AUTOSAR_APPMODE_H
#define _AUTOSAR_APPMODE_H
#include "os_types.h"
/*
 *	\struct OsAppMode
 *	\brief Application Mode structure 
 */
struct OsAppMode {
	EcucStringParamDef OsAppModeName;	/*!< Name of the OSEK application mode */
	uint64 OsAppModeID;			/*!< Identifiant of the OSEK application mode */
};

#endif
