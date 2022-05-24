/*
 * old_main.h
 *
 *  Created on: May 23, 2022
 *      Author: hyrel
 */

#ifndef OLD_MAIN_H_
#define OLD_MAIN_H_


#ifndef COMPILE_FOR_SYSTEM
#define COMPILE_FOR_SYSTEM
#endif

#if (SOFTWARE_TWEAK_REVISION == 'z')
#if defined(USE_HYREL_IO)
#define PLATFORM_STRING       "DEBUG_EngineSR_30M"
#elif defined(USE_HYDRA_IO)
#define PLATFORM_STRING       "DEBUG_EngineHR_Hydra"
#else
#define PLATFORM_STRING       "DEBUG_UNKNOWN_TARGET"
#endif
#else //!(SOFTWARE_TWEAK_REVISION == 'z')
#if defined(USE_HYREL_IO)
#define PLATFORM_STRING       "hydra_SR_HR_22_"
#elif defined(USE_HYDRA_IO)
#define PLATFORM_STRING       "EngineHR_Hydra"
#else
#define PLATFORM_STRING       "UNKNOWN_TARGET"
#endif
#endif //!(SOFTWARE_TWEAK_REVISION == 'z')

#define USE_CAN2    // enable use of second canbus controller, CAN2
//#ifdef USE_HYREL_IO
//#undef USE_CAN2     // HYREL build does not USE CAN2
//#endif //USE_HYREL_IO

#ifdef HYDRA_DIAGS
//#define GB_DIAGS_NEED_SWD_PINS_FOR_DEBUG
#endif

#ifdef USE_HYDRA_IO
#define USE_AB_ENCODER      // affects IO definitions
#endif //USE_HYDRA_IO

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"
#include "hyrel.h"
#include "hyrel_can.h"
#include "util.h"
#include "bootloader.h"
#include "string.h" // random utilities (including bzero)
#include "headSetup.h"
#include "pins.h"
#ifdef ADD_ON_SPI_DISPLAY
#include "lcd.h"
#endif //ADD_ON_SPI_DISPLAY

////////////////////////////////////////////////////////////////////////////////
//  main specific global defines and macros needed by other modules
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
////  "NEW" FEATURE ifdef's -- one accepted, then remove from code
////////////////////////////////////////////////////////////////////////////////

// defined starting in 4.100c

#define BALANCED_TIME

#ifdef GB_DEBUGGING
#define ALLOW_NATIVE_LIGHTBURN  // not for public consumption yet
#endif //GB_DEBUGGING

//#define ALLOW_JOGGING_HEAD_MOTOR_WITH_CAN_STEP    // enable if karl decides to let jog wheel control the head motor
//#define NEW_MCODE_TOOL_USE                        // enable if karl decides to use one of the new mappings he requested
//LEGACY
// end of new 4.100c items

//defined in 4.100e
//#define USE_NEW_SOAPSTRING_DELIMTER_AND_STRIP_COMMENTS    // enable to change soapstring delimeter from ';' to another char ('?')
															// and then auto strip ALL comments before hitting the rx buffer.
#define CHECK_FOR_COLD_EXTRUDE
#define COLLECT_METRICS
#define ENABLE_CRASH_LOGGING

//#define SKIP_M190 // wait for hotbed temperature
//#define SKIP_M191 // wait for chamber temperature
//#define LASER_LOCAL_CONTROL_TESTING_ON_SYS30
//#define GB_FAST_UART                   // crank up the UART rate to 115K


////////////////////////////////////////////////////////////////////////////////
//  END OF DEBUG DEFINTIONS --- SHOULD BE DISABLED WHEN COMPILER FOR RELEASE
////////////////////////////////////////////////////////////////////////////////

#define GB_STRING_MOTION            0x000001    // 1
#define GB_STRING_PRIME             0x000002    // 2
#define GB_STRING_PRIME_RUN         0x000004    // 4
#define GB_STRING_EXTRUSION         0x000008    // 8

#define GB_STRING_COMM_ACK_CHECK    0x000010    // 16
#define GB_STRING_CMD_QUE           0x000020    // 32
#define GB_STRING_FLOW              0x000040    // 64
#define GB_STRING_RATE              0x000080    // 128

#define GB_STRING_CANBUS            0x000100    // 256
#define GB_STRING_DUMP_ON_START     0x000200    // 512
#define GB_STRING_ADD_MOTIONQ       0x000400    // 1024
#define GB_STRING_ECHO_COMM         0x000800    // 2048

#define GB_STRING_WORKBUFFER        0x001000    // 4096
#define GB_STRING_STEPS_PER_NL      0x002000    // 8192
#define GB_STRING_LOOKAHEAD         0x004000    // 16384
#define GB_STRING_ARC_INFO          0x008000    // 32768

#define GB_STRING_RASTER            0x010000    // 65536
#define GB_STRING_JOG_INFO          0x020000    // 131072
#define GB_STRING_CYL_INFO          0x040000    // 262144
#define GB_STRING_CLS_IFO           0x080000    // 524288

#define GB_STRING_CYL_INFO_SUBMASK_MOVE_SETUP   0x0001
#define GB_STRING_CYL_INFO_SUBMASK_MOVE_COORDS  0x0002
#define GB_STRING_CYL_INFO_SUBMASK_MQ_INFO      0x0004
#define GB_STRING_CYL_INFO_SUBMASK_MQ_SPEED     0x0008

#define GB_STRING_JOG_INFO_SUBMASK_1            0x0001
#define GB_STRING_JOG_INFO_SUBMASK_2            0x0002

#define GB_STRING_RASTER_SUBMASK_DETAILS		0x0001
#define GB_STRING_RASTER_SUBMASK_CALIB			0x0002

#define GB_STRING_CLS_SUBMASK_EXTRA_RT_FIELDS	0x0001

////////////////////////////////////////////////////////////////////////////////

// PICK ONE
#define DEFAULT_FLASHER_VAR_SEL     FLASHER_VAR_SEL_NONE
//#define DEFAULT_FLASHER_VAR_SEL       FLASHER_VAR_SEL_ERROR
//#define DEFAULT_FLASHER_VAR_SEL       FLASHER_VAR_SEL_CMD_RECEIVED
//#define DEFAULT_FLASHER_VAR_SEL       FLASHER_VAR_SEL_ACK_PENDING
//#define DEFAULT_FLASHER_VAR_SEL       FLASHER_VAR_SEL_ABORTING

//PICK ONE
#define DEFAULT_FLASHER_LIGHT_SEL   FLASHER_LIGHT_SEL_NONE
//#define DEFAULT_FLASHER_LIGHT_SEL FLASHER_LIGHT_SEL_LED
//#define DEFAULT_FLASHER_LIGHT_SEL FLASHER_LIGHT_SEL_DDL
//#define DEFAULT_FLASHER_LIGHT_SEL FLASHER_LIGHT_SEL_BOTH

// if forgot to select one, set the default to OFF
#ifndef DEFAULT_FLASHER_VAR_SEL
#define DEFAULT_FLASHER_VAR_SEL     FLASHER_VAR_SEL_NONE
#endif
#ifndef DEFAULT_FLASHER_LIGHT_SEL
#define DEFAULT_FLASHER_LIGHT_SEL   FLASHER_LIGHT_SEL_NONE
#endif
#define FLASHER_ON_COUNT 2

////////////////////////////////////////////////////////////////////////////////

//#define RESET_ABORT_MOVE_ON_JOB_END
#define LED_COUNTER_START_VALUE_FOR_ONE_SHOT_FLASH              2
#define REPETREL_COMM_WATCHDOG_START_VALUE (5 * 60)  // each ping is once per minute.... will countdown each second -- 5 minute timeout
#define CLEAR_STICKY_ERROR_RATE 300  // allow repeat error messages ever N seconds
#define MAX_MANUAL_LASER_PULSE_TIME_MS 1000 // 1 second
#define MAX_MANUAL_UV_LIGHTRAY_PULSE_TIME_MS 60000 // 60 seconds
#define LASER_ENABLED               (_gs._laser.enabled)
#define MAX_MOTION_WATCHDOG_MS       700000 // 700 seconds (700mm @ 1mm sec)
#define LASER_LOCAL_PWM_CONTROL     (_gs._laser.enabled && _gs._laser.localControl)   // ensures current device is a laser and under local control

#define KARLS_PASSWORD ((uint32_t)666)
#define DEFAULT_HOT_HEAD        11
#define DEFAULT_HOT_BED         91

#define SIZE_OF_COMMAND_QUEUE   60
#define SIZE_OF_DEFERRED_COMMAND_QUEUE   15
#define SIZE_OF_MOTION_QUEUE    30
#define NUM_HEAD_OFFSETS        60
#define NUM_FIXTURE_OFFSETS     16
#define NUM_TOOL_OFFSETS        60
#define NUM_Z_CALIBRATION_SENSORS 5
#define HOST_WATCHDOG_TIMEOUT_MS 30000

#define ALIAS_TABLE_SIZE 256    // used to map incoming HH device number to diff number
#define DLY_100US  450

// ALL IN 10Hz loop
#define PNP_WAIT_FOR_MOTION_TO_COMPLETE_TIME    150 // 10Hz loop countdown (15 seconds)
#define PNP_WAIT_REEL_ADVANCE_DEFAULT_TIME_MS	100
#define CANBUS_PROBE_ARM_COMPLETION_TIME        10  // way more than enough time
#define CANBUS_HOMING_COMPLETION_TIME			40	// heads check in every second when they are homing
#define GUI_WAIT_FOR_CMD_TO_COMPLETE_TIME	20	// 2 sec
#define CAN_WAIT_FOR_LOOPBACK_TIME				30	// 3 sec

#define BOOTUP_HIGH_VOLTAGE_SETTLING_TIME_MS        2000    // give 2 seconds of settling
#define EMO_HIGH_VOLTAGE_SETTLING_TIME_MS           1000    // give 1 seconds of settling

#define IGNORE_EMO_DURING_BOOT_TIME_MS              BOOTUP_HIGH_VOLTAGE_SETTLING_TIME_MS

#define OVERRIDE_PCT_MAX    (15.99f) // (1.99f) // must be below 2.0f
#define OVERRIDE_PCT_MIN    (0.0f) // (0.5f)

////////////////////////////////////////////////////////////////////////////////
//
//  system mem map of 407
//  sector0 - 16KB - start of real program (up to 896KB total)
//  sector1 - 16KB
//  sector2 - 16KB
//  sector3 - 16KB
//  sector5 - 128KB
//  sector6 - 128KB
//           :               :
//  sector10 - 128KB - max end of real program
//  sector11 - 128KB - soapstring


#define MCU_DEVICE_407 0x413
#define MCU_DEVICE_429 0x419

#define NVIC_VECTOR_OFFSET      0x00000000  // Set the Vector Table base location at 0x08000000

#define NVIC_PREMPTION_PRIORITY_MEASURE_ISR_RATE        0   // debug/test only
#define NVIC_PREMPTION_PRIORITY_UARTS                   1
#define NVIC_PREMPTION_PRIORITY_USB                     2
#define NVIC_PREMPTION_PRIORITY_XTAL_TIMING_CHECK       3   // (boot time only)
#define NVIC_PREMPTION_PRIORITY_SLICETIME_MEASURE       4   // debug/test only
#define NVIC_PREMPTION_PRIORITY_TOUCH_PROBE             5
//#define NVIC_PREMPTION_PRIORITY_                          6
#define NVIC_PREMPTION_PRIORITY_MASTER_MOTION_TIMER     7
#define NVIC_PREMPTION_PRIORITY_STEP_TIMER              8
#define NVIC_PREMPTION_PRIORITY_MASTER_ACCEL_CALC       9
#define NVIC_PREMPTION_PRIORITY_STEP_ZJOG               10
//#define NVIC_PREMPTION_PRIORITY_                          11
//#define NVIC_PREMPTION_PRIORITY_                          12
#define NVIC_PREMPTION_PRIORITY_DELAY                   13
#define NVIC_PREMPTION_PRIORITY_SYSTICK                 14
#define NVIC_PREMPTION_PRIORITY_SYSTICK_MEASURE         15  // debug/test only
#define NVIC_PREMPTION_PRIORITY_LOWEST                  15

#define TIM_INDEX_DELAY					3
#define DELAY_TIMER						TIM3

////////////////////////////////////////////////////////////////////////////////

#define NUM_1000HZ              8
#define NUM_100HZ               10      // must remain 10 otherwise loop timing will not be correct
#define NUM_10HZ                10      // must remain 10 otherwise loop timing will not be correct
#define NUM_1HZ                 10      // must remain 10 otherwise loop timing will not be correct

#define SYSTICKS_PER_SECOND     (NUM_1000HZ * NUM_100HZ * NUM_10HZ * NUM_1HZ)

typedef enum {
	HZ_1000 = 0,
	HZ_100  = 1,
	HZ_10   = 2,
	HZ_1    = 3
} indexType;

#define HEARTBEAT_MODE_BOOT         5  // 10 bps
#define HEARTBEAT_MODE_ABORT        10  // 5 bps
#define HEARTBEAT_MODE_PENDING_ACK  25  // 2 bps bps
#define HEARTBEAT_MODE_NORMAL       100  // 0.5 bps

////////////////////////////////////////////////////////////////////////////////

typedef enum {
	FORMAT_U8_DEC   = 0,
	FORMAT_I8_DEC   = 1,
	FORMAT_U16_DEC  = 2,
	FORMAT_I16_DEC  = 3,
	FORMAT_U32_DEC  = 4,
	FORMAT_I32_DEC  = 5,
	FORMAT_U64_DEC  = 6,
	FORMAT_I64_DEC  = 7,
	FORMAT_FLT      = 8,
	FORMAT_DOUB     = 9,
	FORMAT_U8_HEX   = 10,
	FORMAT_I8_HEX   = 11,
	FORMAT_U16_HEX  = 12,
	FORMAT_I16_HEX  = 13,
	FORMAT_U32_HEX  = 14,
	FORMAT_I32_HEX  = 15,
	FORMAT_U64_HEX  = 16,
	FORMAT_I64_HEX  = 17,
	FORMAT_INT_TEMP = 18,
	FORMAT_FLT_TEMP = 19,
	FORMAT_ADDR     = 20,
	FORMAT_CAL      = 21,
	FORMAT_I8_CHAR  = 22
} formatType;

#define CRASHLOG_START ((uint32_t)0xDEADBEEF)
#define CRASHLOG_END   ((uint32_t)0xFEEDF00D)

typedef struct {
	char label[32];
	formatType format;
	byte *addr;
} crashLog_struct;

typedef enum {
	FLASHER_VAR_SEL_NONE                    = 0,
	FLASHER_VAR_SEL_ERROR                   = 1,
	FLASHER_VAR_SEL_CMD_RECEIVED            = 2,
	FLASHER_VAR_SEL_ACK_PENDING             = 3,
	FLASHER_VAR_SEL_G4_DWELL_TIMER          = 4,
	FLASHER_VAR_SEL_GCODE_PAUSED            = 5,
	FLASHER_VAR_SEL_ABORTING                = 6,
	FLASHER_VAR_SEL_BLOCK_ALL_MOTION        = 7,
	FLASHER_VAR_SEL_BLOCK_ABS_MOTION        = 8,
	FLASHER_VAR_SEL_MOTION_OCCURRED         = 9,
	FLASHER_VAR_SEL_VALID_KEY               = 10,

	FLASHER_VAR_SEL_HOME_STATE_X            = 21,
	FLASHER_VAR_SEL_FAULT_STATE_X           = 22,
	FLASHER_VAR_SEL_LIMIT1_STATE_X          = 23,
	FLASHER_VAR_SEL_LIMIT2_STATE_X          = 24,

	FLASHER_VAR_SEL_HOME_STATE_Y            = 31,
	FLASHER_VAR_SEL_FAULT_STATE_Y           = 32,
	FLASHER_VAR_SEL_LIMIT1_STATE_Y          = 33,
	FLASHER_VAR_SEL_LIMIT2_STATE_Y          = 34,

	FLASHER_VAR_SEL_HOME_STATE_Z            = 41,
	FLASHER_VAR_SEL_FAULT_STATE_Z           = 42,
	FLASHER_VAR_SEL_LIMIT1_STATE_Z          = 43,
	FLASHER_VAR_SEL_LIMIT2_STATE_Z          = 44,

	FLASHER_VAR_SEL_HOME_STATE_A            = 51,
	FLASHER_VAR_SEL_FAULT_STATE_A           = 52,
	FLASHER_VAR_SEL_LIMIT1_STATE_A          = 53,
	FLASHER_VAR_SEL_LIMIT2_STATE_A          = 54,

	FLASHER_VAR_SEL_HOME_STATE_B            = 61,
	FLASHER_VAR_SEL_FAULT_STATE_B           = 62,
	FLASHER_VAR_SEL_LIMIT1_STATE_B          = 63,
	FLASHER_VAR_SEL_LIMIT2_STATE_B          = 64,

	FLASHER_VAR_SEL_HOME_STATE_C            = 71,
	FLASHER_VAR_SEL_FAULT_STATE_C           = 72,
	FLASHER_VAR_SEL_LIMIT1_STATE_C          = 73,
	FLASHER_VAR_SEL_LIMIT2_STATE_C          = 74,
} flasherVarSel_t;


typedef enum {
	FLASHER_LIGHT_SEL_NONE      = 0,
	FLASHER_LIGHT_SEL_LED       = 1,
	FLASHER_LIGHT_SEL_DDL       = 2,
	FLASHER_LIGHT_SEL_BOTH      = 3,
} flasherLightSel_t;

typedef struct {
	flasherLightSel_t   lightSel;
	flasherVarSel_t     varSel;
	int                 *varPtr;
	int                 error;
	int                 cmd_received;
	int                 ack_pending;
	//int                   aborting; //use live variable since not 'flashing'
} flasherStruct;

typedef enum {
	UNKNOWN_BUFFER    = 0,
	SOAPSTRING_BUFFER = 1,
	URGENT_BUFFER     = 2,
	NORMAL_BUFFER     = 3
} buffer_t;

typedef enum {
	UNKNOWN_MASTER  = 0,
	UART3_MASTER    = 1,
	UART4_MASTER    = 2,
	UART6_MASTER    = 3,
	USB_MASTER      = 4,
	BOOTUP          = 5
} masterPort_t;

#define ABORT_TIME 5 // 5 second watchdog to complete abort process.
typedef enum {
	FLUSH_THEN_ABORT,   // used for real abort --
	FLUSH_THEN_CONTINUE, // used for touch probe
} flushAction_t;

////////////////////////////////////////////////////////////////////////////////

//void (*callback)(void *);//define cast for call back type
#define EXTRUDE_CONTINUOUS_FORWARD   1000000000.0
#define EXTRUDE_CONTINUOUS_REVERSE  -1000000000.0

#define WAIT_FOR_TEMP_ALLOWABLE_SHORTFALL   1

#ifdef GB_DEBUG_ARC
#define ARC_LENGTH_PER_SEGMENT 20 //(0.33333f)
#else   //!GB_DEBUG_ARC
#define ARC_LENGTH_PER_SEGMENT (0.33333f)
#endif //!GB_DEBUG_ARC
#define ARC_TOLERANCE   (0.005f) // 0.005 mm  per RS274/NGC Interpreter spec  was:(0.1f)
#define G2G3_THREAD_PITCH_TOLERANCE (0.05f)
#define CYL_TOLERANCE   (0.01f)
// could be an enum instead
#define NO_OK           0
#define FRONT_DOOR_OK   1
#define BACK_DOOR_OK    2
#define BOTH_OK         3

#define FLOW_RATE_CREATED_ON_HEAD       (!_hijackAxisC)     //(!(_canbusStepForE || _directStepForE))
#define FLOW_RATE_CREATED_ON_MOTORC     (_hijackAxisC)      //(_canbusStepForE || _directStepForE)
#define USING_E_VALUES                  (_extrusionControl == USE_E_VALUES)
#define IGNORING_E_VALUES               (_extrusionControl == IGNORE_E_VALUES)

////////////////////////////////////////////////////////////////////////////////

#define INVALID_ARG_VALUE ((float)-999999) // replace extern float Invalid;

#define ARG_A   (ExecutionPtr->A)
#define ARG_B   (ExecutionPtr->B)
#define ARG_C   (ExecutionPtr->C)
#define ARG_D   (ExecutionPtr->D)
#define ARG_E   (ExecutionPtr->E)
#define ARG_F   (ExecutionPtr->F)
#define ARG_G   (ExecutionPtr->G)
#define ARG_H   (ExecutionPtr->H)
#define ARG_I   (ExecutionPtr->I)
#define ARG_J   (ExecutionPtr->J)
#define ARG_K   (ExecutionPtr->K)
#define ARG_L   (ExecutionPtr->L)
#define ARG_M   (ExecutionPtr->M)
#define ARG_N   (ExecutionPtr->N)
#define ARG_O   (ExecutionPtr->O)
#define ARG_P   (ExecutionPtr->P)
#define ARG_Q   (ExecutionPtr->Q)
#define ARG_R   (ExecutionPtr->R)
#define ARG_S   (ExecutionPtr->S)
#define ARG_T   (ExecutionPtr->T)
#define ARG_U   (ExecutionPtr->U)
#define ARG_V   (ExecutionPtr->V)
#define ARG_W   (ExecutionPtr->W)
#define ARG_X   (ExecutionPtr->X)
#define ARG_Y   (ExecutionPtr->Y)
#define ARG_Z   (ExecutionPtr->Z)
#define ARG_CS  (ExecutionPtr->CS)

#define ARG_A_PRESENT   (ARG_A != INVALID_ARG_VALUE)
#define ARG_B_PRESENT   (ARG_B != INVALID_ARG_VALUE)
#define ARG_C_PRESENT   (ARG_C != INVALID_ARG_VALUE)
#define ARG_D_PRESENT   (ARG_D != INVALID_ARG_VALUE)
#define ARG_E_PRESENT   (ARG_E != INVALID_ARG_VALUE)
#define ARG_F_PRESENT   (ARG_F != INVALID_ARG_VALUE)
#define ARG_G_PRESENT   (ARG_G != INVALID_ARG_VALUE)
#define ARG_H_PRESENT   (ARG_H != INVALID_ARG_VALUE)
#define ARG_I_PRESENT   (ARG_I != INVALID_ARG_VALUE)
#define ARG_J_PRESENT   (ARG_J != INVALID_ARG_VALUE)
#define ARG_K_PRESENT   (ARG_K != INVALID_ARG_VALUE)
#define ARG_L_PRESENT   (ARG_L != INVALID_ARG_VALUE)
#define ARG_M_PRESENT   (ARG_M != INVALID_ARG_VALUE)
#define ARG_N_PRESENT   (ARG_N != INVALID_ARG_VALUE)
#define ARG_O_PRESENT   (ARG_O != INVALID_ARG_VALUE)
#define ARG_P_PRESENT   (ARG_P != INVALID_ARG_VALUE)
#define ARG_Q_PRESENT   (ARG_Q != INVALID_ARG_VALUE)
#define ARG_R_PRESENT   (ARG_R != INVALID_ARG_VALUE)
#define ARG_S_PRESENT   (ARG_S != INVALID_ARG_VALUE)
#define ARG_T_PRESENT   (ARG_T != INVALID_ARG_VALUE)
#define ARG_U_PRESENT   (ARG_U != INVALID_ARG_VALUE)
#define ARG_V_PRESENT   (ARG_V != INVALID_ARG_VALUE)
#define ARG_W_PRESENT   (ARG_W != INVALID_ARG_VALUE)
#define ARG_X_PRESENT   (ARG_X != INVALID_ARG_VALUE)
#define ARG_Y_PRESENT   (ARG_Y != INVALID_ARG_VALUE)
#define ARG_Z_PRESENT   (ARG_Z != INVALID_ARG_VALUE)

#define ARG_A_MISSING   (ARG_A == INVALID_ARG_VALUE)
#define ARG_B_MISSING   (ARG_B == INVALID_ARG_VALUE)
#define ARG_C_MISSING   (ARG_C == INVALID_ARG_VALUE)
#define ARG_D_MISSING   (ARG_D == INVALID_ARG_VALUE)
#define ARG_E_MISSING   (ARG_E == INVALID_ARG_VALUE)
#define ARG_F_MISSING   (ARG_F == INVALID_ARG_VALUE)
#define ARG_G_MISSING   (ARG_G == INVALID_ARG_VALUE)
#define ARG_H_MISSING   (ARG_H == INVALID_ARG_VALUE)
#define ARG_I_MISSING   (ARG_I == INVALID_ARG_VALUE)
#define ARG_J_MISSING   (ARG_J == INVALID_ARG_VALUE)
#define ARG_K_MISSING   (ARG_K == INVALID_ARG_VALUE)
#define ARG_L_MISSING   (ARG_L == INVALID_ARG_VALUE)
#define ARG_M_MISSING   (ARG_M == INVALID_ARG_VALUE)
#define ARG_N_MISSING   (ARG_N == INVALID_ARG_VALUE)
#define ARG_O_MISSING   (ARG_O == INVALID_ARG_VALUE)
#define ARG_P_MISSING   (ARG_P == INVALID_ARG_VALUE)
#define ARG_Q_MISSING   (ARG_Q == INVALID_ARG_VALUE)
#define ARG_R_MISSING   (ARG_R == INVALID_ARG_VALUE)
#define ARG_S_MISSING   (ARG_S == INVALID_ARG_VALUE)
#define ARG_T_MISSING   (ARG_T == INVALID_ARG_VALUE)
#define ARG_U_MISSING   (ARG_U == INVALID_ARG_VALUE)
#define ARG_V_MISSING   (ARG_V == INVALID_ARG_VALUE)
#define ARG_W_MISSING   (ARG_W == INVALID_ARG_VALUE)
#define ARG_X_MISSING   (ARG_X == INVALID_ARG_VALUE)
#define ARG_Y_MISSING   (ARG_Y == INVALID_ARG_VALUE)
#define ARG_Z_MISSING   (ARG_Z == INVALID_ARG_VALUE)

typedef enum {
	//NOTE: items 2 and 3 behave the same, but commands should be defined as one or the other for possible future enhancements.
	UNDEFINED                     = 0,
	SINGLE_STEP                   = 1,  // single step .... wait for empty queue, set ForceQToEmpty, process, reset ForceQToEmpty
	ADD_TO_MQ                     = 2,  // add to Q or process in order with Q (tag as processed if not added to Q, ie G90)
	IMPACTS_DESTINATION_CALC      = 3,  // ONLY affects position (ie, change of offsets) or has no impact on position/motion and does not need to be synced
	SYNCS_WITH_MOTION             = 4   // skip, but tag, until prior motion complete...unless Q is empty, the just process
} command_t;

#define UNPROCESSED -1 // used to init cmdLink on cmdQue

typedef struct {
	unsigned A : 1;
	unsigned B : 1;
	unsigned C : 1;
	unsigned D : 1;
	unsigned E : 1;
	unsigned F : 1;
	unsigned G : 1;
	unsigned H : 1;
	unsigned I : 1;
	unsigned J : 1;
	unsigned K : 1;
	unsigned L : 1;
	unsigned M : 1;
	unsigned N : 1;
	unsigned O : 1;
	unsigned P : 1;
	unsigned Q : 1;
	unsigned R : 1;
	unsigned S : 1;
	unsigned T : 1;
	unsigned U : 1;
	unsigned V : 1;
	unsigned W : 1;
	unsigned X : 1;
	unsigned Y : 1;
	unsigned Z : 1;
} flag_t;

typedef struct {
	float A;    // motor A, 4th axis
	float B;    // motor B, 4th axis
	float C;    // motor C, 4th axis
	float D;    // tool working diameter offset
	float E;    // used for extrusion value
	float F;
	float G;    // gcode
	float H;    // Tool working length offset
	float I;    // used for circular arc commands, defines offset to center of circles
	float J;    // used for circular arc commands, defines offset to center of circle
	float K;
	float L;
	float M;    // mcode
	float N;
	float O;
	float P;
	float Q;
	float R;
	float S;
	float T;    // tool number
	float U;
	float V;
	float W;
	float X;    // motor X, 1st axis
	float Y;    // motor Y, 2nd axis
	float Z;    // motor Z, 3rd axis
	float CS;
	//union {
	//   flag_t flag;
	//   unsigned int flags;
	//} valid;
	command_t cmdType;  // defined type indicating how this type of command interracts with the motionQ
	int cmdLink;        // index to parent command (link to motionQ from deferredQ)
} GMCommandStructure;

typedef enum {
	DEFERRED_CMD_INVALID = 0,
	DEFERRED_CMD_VALID_BUT_NOT_READY_TO_PROCESS,
	DEFERRED_CMD_VALID_AND_READY_TO_PROCESS,
} deferred_cmd_t;

typedef struct {
	GMCommandStructure  cmd;
	deferred_cmd_t      cmdState;
} GMDeferredCommandStructure;

////////////////////////////////////////////////////////////////////////////////

typedef enum {
	NO  = 0,
	YES = 1
} yes_no_t;

typedef enum {
	HOME_TOWARD_ZERO = 0,
	HOME_AWAY_FROM_ZERO = 1
} homingDirection_t;

typedef enum {
	DIRECTION_FORWARD = 0,
	DIRECTION_REVERSE = 1
} direction_t;

typedef enum {
	SENSOR_INDEX_NONE = 0,
	SENSOR_INDEX_FAULT,
	SENSOR_INDEX_LIMIT1,
	SENSOR_INDEX_LIMIT2,
	SENSOR_INDEX_START,
	SENSOR_INDEX_EMO,
	SENSOR_INDEX_HOME,
	SENSOR_INDEX_ABSEL,
} sensorIndex_t;

#define DEFAULT_SENSOR_DEBOUNCE_READS	3   // N consectutive reads of same value to be valid state.. one or two reads of alternate value will be rejected
#define FAULT_SENSOR_DEBOUNCE_READS 	15 	// N consectutive reads of same value to be valid state.. a few reads of alternate value will be rejected

typedef struct {
	sensorIndex_t   SensorIndex;            // which sensor;
	uint32_t        Bit;                    // bit definition for pin/port
	HYREL_GPIO_TypeDef    *gpioPort;
	uint32_t        gpioMask;
	char            Name[8];                // give bit a name for error reporting
	polarity_t      Polarity;               // acitive hi/low
	int             NumDebounceMaskBits;    // number of successive consistent reads needed to debounce and get a valid state
	uint32_t        DebounceMask;           // mask of how many successive consistent reads are needed to debounce (ie, 0x007 for 3 reads)
	sensorState_t   State;                  // last read state
	uint32_t        History;                // optionally used for debounce, record of last 32 "states"
	boolean         Enabled;                // TRUE is sensor is being checked
	boolean         ErrorMessageSent;       // TRUE when message sent to host that the sensor was tripped
	boolean         StateChangeDetected;    // last read of sensor caused a change of state (ie, OPEN to CLOSED/TRIPPED
	boolean         TransientDetected;      // flag to indicate the a non-uniform (history & mask) so either noise OR a tranisition starting
} sensorStruct;

typedef struct {
	uint32_t        Bit;
	HYREL_GPIO_TypeDef    *gpioPort;
	uint32_t        gpioMask;
	polarity_t      Polarity;
} controlBitStruct;

typedef struct {
	uint32_t        Bit;
	HYREL_GPIO_TypeDef    *gpioPort;
	uint32_t        gpioMask;
	yes_no_t        InvertDefault;
} directionBitStruct;

typedef enum {
	IGNORE_E_VALUES     = 0,  // calculate flow based on layer H, W and motion
	USE_E_VALUES        = 1,
	INVALID_E_CONTROL   = 2
} E_control_t;

typedef enum {
	MOTION_FLOW_USE_FEEDRATE        = 0,    // calculate flow rate based on requested Feedrate (Gx Fxxx)
	MOTION_FLOW_USE_CRUISE_SPEED    = 1,    // calculate flow rate based on cruising speed for each move
	MOTION_FLOW_USE_AVG_SPEED       = 2,    // calculate flow rate based on average speed for each move
} motionForFlowControl_t;

typedef enum {
	AUTO_UNPRIME_PRIME = 0,
	GCODE_UNPRIME_PRIME = 1,
	MCODE_UNPRIME_PRIME = 2,
	E_ARG_UNPRIME_PRIME = 3,
	NO_UNPRIME_PRIME    = 4
} unprime_prime_control_t;

typedef enum {
	ARC_CW = 0,
	ARC_CCW = 1,
} arcDir_t;

typedef enum {
	ARC_PLANE_NONE = 0,
	ARC_PLANE_XY = 1,
	ARC_PLANE_XZ = 2,
	ARC_PLANE_YZ = 3,
} arcPlane_t;

typedef enum {
	ARC_STATE_IDLE = 0,
	ARC_STATE_1 = 1,
	ARC_STATE_2 = 2,
	ARC_STATE_3 = 3,
} arcState_t;

typedef struct {
	float X;
	float Y;
	float Z;
} pointStruct;

typedef struct {
	float X;
	float Y;
	float Z;
	float mag;
} vectorStruct;

typedef struct {
	pointStruct     centerOffset;
	pointStruct     startPt;
	pointStruct     endPt;
	pointStruct     endPtABC;
	pointStruct     centerPt;
	pointStruct     deltaABC;
	float           radius;
	float           sweepAngle;
	int             segments;
	int             fullCircleSegments;
	int             numFullThreads;

	vectorStruct    center2startV;      //vector from center to start point
	vectorStruct    center2startUV;     //unit vector from center to start point
	vectorStruct    center2endV;        //vector from center to end point
	vectorStruct    center2endUV;       //unit vector from center to end point
	vectorStruct    rotationNormalUV;
	vectorStruct    derivedNormalUV;
	vectorStruct    reverseDerivedNormalUV;
	vectorStruct    displacementV;      // temp variable used in point gen loop


	vectorStruct    ortho2center2startUV; //unit vector orthogonal to center2startUV
	arcPlane_t      plane;
	arcDir_t        dir;
	float           displacement;   // helical displacement along normal
	float           dotCheck;

	boolean         sweepIsMultipleOf180Degrees;
	boolean         normalsSameDir;
	boolean         normalsOppoDir;
	boolean         skipFinalArcMove;   // used for frogToe;
	boolean         fullCircle;
	boolean         inscribedShape;     // true when full circle and ARG_S specified
	boolean         normalWasSpecified;
	boolean         threadingOK;

	GMCommandStructure  *saveExecutionPtr;
	boolean         saveIncrementalMove;
	boolean         saveIncrementalEMove;
	E_control_t     saveExtrusionControl;

	int             index;
	arcState_t      state;
} arcStruct;

////////////////////////////////////////////////////////////////////////////////

typedef struct {
	float ToolLength;
	float ToolDiameter;
} ToolOffsetStructure;

typedef enum {
	AXIS_MIN    = 0,    // machine min rate for this axis in raw units per second (UPS)
	AXIS_MAX    = 1,    // machine max rate for this axis in raw units per second (UPS)
	NO_RAMP     = 2,    // speeds at or below this do not need acceleration  in raw units per second (UPS)
	RAPID       = 3,    // aka G0 travel rate for this axis in raw units per second (UPS)
	HOMING      = 4,    // aka G28 and Jog rate for this axis in raw units per second (UPS)
	REHOMING    = 5,    // speed for second pass homing
	JOG_NO_RAMP = 6,    // no ram speed for jogging
	JOGGING     = 7,    // speed for jogging
	NUM_RATES
} rate_t;

#define VECTOR_MOTION_RATE     0.0f
#define RAPID_MOTION_RATE     -1.0f
#define HOMING_MOTION_RATE    -2.0f
#define REHOMING_MOTION_RATE  -3.0f
#define RASTER_MOTION_RATE    -4.0f
#define JOGGING_MOTION_RATE   -5.0f
//#define ONESHOT_MOTION_RATE   -5.0f

#define RASTER_REVERSE_SCAN_TWEAK 0 //-0.125    // offset from end position of positive dir line to start return line
#define RASTER_FRONT_PORCH_EXTRA_PIXELS_MULTIPLIER 1.4f  // force extra (1.2 = 20%)front porch to make sure motion really at speed

typedef enum {
	LINEAR = 0,
	ROTARY
} axis_t;


#define SWITCH_PRESCALE_1       1
#define SWITCH_PRESCALE_10      10
#define SWITCH_PRESCALE_100     100
#define SWITCH_PRESCALE_500     500

#define TICKS_PER_SEC_1000HZ_LOOP 1000 // 1000 Hz loop
#define TICKS_PER_SEC_100HZ_LOOP  100  // 100 Hz loop
#define TICKS_PER_SEC_10HZ_LOOP   10   // 10 Hz loop
#define TICKS_PER_SEC_1HZ_LOOP    1    // 1 Hz loop

#define DONT_CHANGE_PERIOD -1

typedef enum  {
		NO_HSS_PIN_INDEX = 0,
#ifdef USE_HYREL_IO
		X_HSS1_INDEX = 1,
		X_HSS2_INDEX = 2,
		Y_HSS1_INDEX = 3,
		Y_HSS2_INDEX = 4,
		Z_HSS1_INDEX = 5,
		Z_HSS2_INDEX = 6,
		W_HSS1_INDEX = 7,
		W_HSS2_INDEX = 8,
#elif defined(USE_HYDRA_IO)
		HSS_AUX_PWR1_INDEX = 1,
		HSS_AUX_PWR2_INDEX = 2,
		HSS_AUX_PWR4_INDEX = 3,
		HSS_AUX_PWR5_INDEX = 4,
		HSS_AUX_PWR6_INDEX = 5,
		HSS_AUX_PWR7_INDEX = 6,
		HSS_AUX_PWR8_INDEX = 7,
		HSS_AUX_PWR9_INDEX = 8,
		DRAIN1_INDEX = 9,
		DRAIN2_INDEX = 10,
		DRAIN3_INDEX = 11,
		DRAIN4_INDEX = 12,
#endif
		NUM_HSS_PINS
} hssPin_t;

typedef enum {
	NO_FUNCTION_HSS         = 0,
	SPINDLE_COOLANT_HSS     = 1,
	FLOOD_COOLANT_HSS       = 2,
	DANGER_LIGHT_HSS        = 3,
	DDLIGHT_HSS             = 4,
	RESPONSE_HSS            = 5,
	BUZZER_HSS              = 6,
	CHAMBER_FAN_HSS         = 7,
	LASER_XHAIR_HSS         = 8,
	EXHAUST_FAN_HSS         = 9,
	VACUUM_HSS              = 10,
	AIR_ASSIST_HSS          = 11,
	ULTIMUS_HSS             = 12,
	CO2_POWER_SUPPY_HSS     = 13,
	NUM_HSS_FUNC
} hssFunc_t;

typedef struct {
	controlBitStruct Output;

	boolean oneShot;
	float DutyCycle;
	float PeriodInSec;
	int TicksPerSecond;  // ticks=100 for 100Hz loop; 10 for 10Hz loop, 1 for 1Hz loop, etc
	int TerminalCount;
	int CompareValue;
	int Counter;
	hssPin_t index;
} HssPwmStruct;

#define HSS_DUTY_CYCLE_ON     100.0f
#define HSS_DUTY_CYCLE_OFF    0.0f

#define HOMING_MOTORS (TRUE)
#define NOT_HOMING_MOTORS (FALSE)

//#undef M_E      // was defined in math.h for "e" #define M_E 2.7182818284590452354

typedef enum {   // used for motor array indices
	M_X = 0,
	M_Y = 1,
	M_Z = 2,
	M_A = 3,
	M_B = 4,
	M_C = 5,
	MAX_NUMBER_OF_MOTORS
} motorIndex_t;


typedef enum {
	LATHE_MODE_OFF          = 0,
	LATHE_MODE_ON           = 1,
} latheMode_t;

typedef struct MotorStructure MotorStructure;   // forward declaration of struct so we can declare a ptr inside struct
typedef void (*MotorStructureFunc)(MotorStructure *);

#define MAX_NUM_CAN_MOTORS_PER_AXIS 4
typedef struct {
	byte canAddress;				// list of physical canbus addresses for motor driving this axis
	boolean selfHomingInProgress;	// individual canAxisMotor is in the process of homing
	boolean selfHomed;				// individual canAxisMotor has been self homed
} canMotorState_t;

typedef struct MotorStructure {
	uint32_t Axis;                      // array index
#ifdef GB_DEBUG_MOTION_Q
	float debugArgDValue;
	int lineNumber;
#endif
	uint32_t GCodeArgOffset;            // byte offset to this motor's GCodeArg in the GMCommandStructure
	axis_t AxisType;                    // LINEAR or ROTARY;
	char AxisLabel;                     // single char label for axis used for reporting

	boolean canMotor;					// TRUE is axis is controlled via canbus
	int32_t maxCanMotors;				// per axis limit on # can motors allowed
	boolean axisSelfHomingInProgress;	// tag that the axis as a whole was homing .. save processing at the end
	canMotorState_t canMotors[MAX_NUM_CAN_MOTORS_PER_AXIS];

	boolean MotorInstalled;             // TRUE if motor/axis is installed and operational
	boolean SendStepViaCanbus;          // if TRUE, when motor steps, it will send out a step message via the canbus to specified device
	//NUKE byte DeviceForCanStep;              // destination address of device to receive canStep packet
	boolean SubstituteAxisArgWithArgE;  // flag to indicate whether to substitute the E value for this axis' value in a gcode line

	int32_t POSITION;                   // absolute position in pulses of the current position (must be signed int for JogMotor)
	int32_t DIRECTION;                  // == 1 for forward and == -1 for reverse
	int32_t PULSES_TO_GO;               // pulses remaining in this step
	int32_t PULSES_IN_MOVE;             // total pulses needed for the move (stays constant during the move)
	float RatesInUPS[NUM_RATES];        // contains all of the various rate limits and targets
	int32_t LastReportedPosition;

	float Q_LastRequestedPositionInUnits;   // last actual location without offets in mm or deg added to the motionQ
	int32_t Q_POSITION;                 // last absolute FINAL position in pulses of a move added to the mo
	int32_t TouchPosition;              // recorded position when using touch probe

	float startVelocity;                // starting velocity for move (used when homing or dominant)
	float cruiseVelocity;               // "at speed" velocity for move (used when homing or dominant)
	float cruiseVelocitySquared;
	float endVelocity;                  // final velocity for move (used when homing or dominant)
	float currentVelocity;              // velocity at the current moment for move (used when homing or dominant)

	int32_t AccelerationPulses;         // number of pulses to accelerate from startVelocity to cruiseVelocity (used when homing or dominant)
	int32_t DecelerationPulses;         //  number of pulses to decell from cruiseVelocity to endVelocity (used when homing or dominant)
	float AccelerationScaled;           // acceleration rate for the current move (scaled from the AccelerationConstant) (used when homing or dominant)
	float AccelerationScaledTimes2;
	float MotionRateInSPP;              // motion rate in seconds / pulse (inverted)
	float unitVector;                   // component of unit vector
	float scaleDegreesToMm;             // used to convert speed on rotary axis from deg to mm to match feedrate

	float Dominant2AxisPulseRatio;      // simple ratio pulses in the dominant axis to the current axis ... used to schedule "next" pulses.
	float AxisFirstPulseOffset;         // offset for when the first pulse will occur
	boolean PulsePending;               // marks that the next pulse has been scheduled but not yet occurred

	float RotaryOffset[MAX_NUMBER_OF_MOTORS]; // insection point of the rotary axis plane  axis of the cylinder

	int32_t unprimePulseToGo;           // pulse to match to PULSES_TO_GO at the time to issue the unprime to the hothead
	int32_t residualUnprimeTime;        // time in ms remaining for the unprime AFTER the move completes

	float AccelerationConstant;         // SPEC'D: "constant" to calc initial accel relative to velocity (units/sec/sec)
	float AbortDecelerationRate;        // SPEC'D: "constant" to calc final deceleration relative to velocity (units/sec/sec) when motion is aborted so that the motion can be gracefully (but agressively) stopped

	float JogAccelerationConstant;      // SPEC'D: "constant" to calc initial accel relative to velocity (units/sec/sec)
	float JogIncrement;
	int32_t JogPauseTimeMs;
	struct {
		unsigned    JOG_NO_RAMP : 1;
		unsigned    JOGGING : 1;
		unsigned    ACCEL : 1;
	} joggingRatesSet;

	float PulsesPerUnit;                // SPEC'D: pulses per mm of travel - if changed, all other rates need to be updated
	float UnitsPerPulse;                // inverse of PulsesPerUnit (allows use of multiply instead of divide saving 13 cycles)
	int32_t PulsesPerRevolution;            // inferred for rotary axis
	float MaximumTravelInUnits;         // SPEC'D: software limit for each axis in travel in mm or deg
	int MaximumTravelInPulses;          // DERIVED: software limit for each axis in travel in pulses

	float AbortTravelScaling;
	float MinimumAbortTravelInUnits;
	float MaximumAbortTravelInUnits;
	int32_t MinimumAbortTravelInPulses;
	int32_t MaximumAbortTravelInPulses;

	float AbortAbsolutePosition;
	float AbortRelativePosition;

	float G92Offset;                            // SPEC'D: G92offset in mm or degrees
	float FixtureOffsets[NUM_FIXTURE_OFFSETS];  // SPEC'D: tool offsets in mm or degrees
	float HeadOffsets[NUM_HEAD_OFFSETS];        // SPEC'D: head offsets in mm or degrees

	// HomingStart and End Point allow flipping the coordinate system and putting "Home" opposite from 0
	boolean SearchingForHomeSensor;     // used for homing routine. set high to start; cleared when home detected
	homingDirection_t HomingDirection;  // whether to home toward 0 or away from 0
	float HomeDestinationInUnits;       // need to store in case pulse/unit changes so able to recalc HomeDestinationInPulses
	int32_t HomeDestinationInPulses;        // motor POSITION after the homing sequence finishes
	float HomeHysteresisInUnits;        // SPEC'D: distance from first tripping sensor to actual zero position
	float HomePopOffDistanceInUnits;    // SPEC'D: distance to pop off from home during the remhoming pass

	boolean HasBeenHomed;               // true if axis has been home (set false again on "unlock motors" and EMO press (if wired)
	boolean HasBeenHomed_BlockedMsgSent; // true is error message has already been sent about moves being rejected if not homed
	boolean HomingFailed;               // temp variable to indicate homing procedure had an issue (ie, insufficient pop off)

	boolean autoReportPosition;
	boolean reportPositionWithStatus;

	latheMode_t latheMode;
	float latheAccelPer10ms;
	float latheTargetSpeedPPS;
	float latheCurrSpeedPPS;

	sensorStruct HomeSense;
	sensorStruct FaultSense;
	sensorStruct Limit1Sense;
	sensorStruct Limit2Sense;

	controlBitStruct Enable;
	controlBitStruct Step;
	directionBitStruct Direction;

	TIM_TypeDef* TimerBase;             // pointer to Timer HW that this motor will use for it's step pulse generation
	float TimerFreq;                    // raw input clock frequency to the timer
	uint32_t TimerPSC;                  // timer PSC load value (already offset by 1)  - used when homing
	uint32_t TimerARR;                  // timer ARR load value (already offset by 1)) - used when homing

	//DEPRECATED - NUKE?????  SAVE FOR SOMEDAY
	// these are unused at the moment....useful if there are unique per motor things that need to be done
	//GX XXX FIX void (*CallBackHomeSense)(MotorStructure*);    //method for checking Home status
	//typedef void (*myFuncDef)(MotorStructure *);
	//void (*CallBackHomeSense)(void);  //method for checking Home status
	//MotorStructureFunc CallBackHomeSense;   //ptr to a func with one arg void func(MotorStructure *);
	//void (*CallBackPrimeRun)(void);   //signals when to restart the flow of material after a non extrude move or event
	//void (*CallBackRetract)(void);    //signals when to start retracting the material to stop the flow sharply.
	//void (*MotionCallBack)(void);     // called after EVERY motor step issue
	//void (*CallBackHomeComplete)(void);   //man I really hope this works, we can add a lot of routines
} MotorStructure;

typedef enum { // used in countdown fashion
	G28_FINISHED_MULTIPASS_HOME         = 0,
	G28_SET_DESTINATION_REHOME          = 1,
	G28_PASS_REHOME                     = 2,
	G28_PASS_LEAVE_HOME                 = 3,
	G28_SET_DESTINATION_HOME            = 4,
	G28_PASS_HOME                       = 5,
	G28_PASS_MOVE_INTERMEDIATE_POINT    = 6,
	G28_START_MULTIPASS_HOME            = 7
} g28Pass_t;

typedef enum { // used in countdown fashion
	G38_FINISHED_MULTIPASS_PROBING      = 0,
	G38_MOVE_TO_NEXT_XY                 = 1,
	G38_RAISE_PROBE                     = 2,
	G38_WAIT_FOR_RESULTS                = 3,
	G38_READ_DEPTH                      = 4,
	G38_PAUSE_BEFORE_READING            = 5,
	G38_LOWER_PROBE                     = 6,
	G28_ARM_PROBE                       = 7,
	G38_START_MULTIPASS_PROBING         = 8
} g38Pass_t;

#define MIN_VECTOR_SPEED 0.01f  // minimum vector speed (include start and end speed) ie, 0.25f = 0.25mm/spec == 0.59 inch/min

typedef struct MotionEntryStruct {
	 int lineNumber;         // try to track gcode line number through the Q
#ifdef GB_DEBUG_MOTION_Q
	float debugArgDValue;   // gcode "D" arg value -- used to trip a breakpoint on a given line
#endif
#ifdef GB_DEBUG_ARC
	int TAG;
#endif
	int cmdQueIndex;        // index of cell this command occupied in the command queue
	struct {
		unsigned needToPrimeBeforeMove   : 1; // flag to indicate a need to issue a extrusion "prime" before this move
		unsigned needToUnprimeAfterMove  : 1; // flag to indicate a need to issue a extrusion "upprime" after this move
		unsigned needToUnprimeDuringMove : 1; // flag to indicate a need to issue a extrusion "upprime" during this move
		unsigned unprimeIssued           : 1; // flag to indicate the unprime can message has been sent
		unsigned hadAnE                  : 1; // flag to indicate an "E" value was present with the line of Gcode leading to the move
		unsigned homingMove              : 1; // flag to indicate this move is a homing move in search of the home sensors
		unsigned rasterMove              : 1; // flag to indicate the move is a rasterizing move (ie, inkjet or laser)
		unsigned dominantAxis            : 3; // axis index of the dominant axis
		unsigned inMotion                : 1; // flag to indicate motion has already started (can't be updated; and speedControl can start
		unsigned lastInSequence          : 1; // flag to indicate the move is the last of a sequence (needed in order to know when it is
											  // time to process deferred commands)
		unsigned needToPuffBeforeMove    : 1; // flag used in G81/G83/G84 to tag moves that start with a "puff" (turning on a HSS)
		unsigned pauseAfterThisMove      : 1; // flag used to tell sequence engine to stop moving until a restart is issued;
		unsigned abortAfterThisMove      : 1; // flag used to tell sequence engine to stop moving until a restart is issued;
		unsigned hasDeferredCommands         : 1; // flag to indicate there are deferred commands to process after this command
	} flags;

	int8_t direction[MAX_NUMBER_OF_MOTORS]; // == 1 for forward and == -1 for reverse (0 for not moving)
	int32_t PULSES_TO_GO[MAX_NUMBER_OF_MOTORS]; // pulses remaining in this move === WILL BE NEGATIVE TEMPORARILY, so leave as "int"
	float unitVector[MAX_NUMBER_OF_MOTORS]; // unit vector along the path from the prior dest to the dest of this move
	float requestedFeedrate;            // pass through for ReportXYZ
	float moveTime;                     // move time .. used for unprime/prime removal (starts without accel/decel, but added later)
	float perfectMoveTime;				// move time .. with INFINITE acceleration -- used for metrics
	float distance;                     // in "units"   -- distance of travel for the move
	float speed;                        // in units/sec -- cruising speed
	float startSpeed;                   // in units/sec -- speed to start the move
	float startSpeedLimit;              // in units/sec -- max start speed based on intersection with prior move and prior moves' speed
	float noRampSpeed;                  // in units/sec -- safe starting speed (no need to accearate to this value .. just start with this)
	float acceleration;                 // in units/sec/sec -- acceleration for the move (along the vector)
	float scaleDegreesToMm;             // used to convert speed on rotary axis from deg to mm to match feedrate
	float flowOverridePct;              // composite of all flow mutipliers at the time adding the move to the motionQ
	float flowCrossSectionTimesPPU;     // if !USING_E, will be cross section of volume (W*H) times the PPuL -- just need motion rate to get pulse rate, 0 otherwise
	int32_t flowPulses;                   // if USING_E, will be number of E steps; otherwise 0
	E_control_t extrusionControl;   // need to pass this through to execute so commands can more easily save/restore (ie, G2.1)

	// WARNING!!!!
	// index, next and prev pointers MUST be declared at the end of the struct so it's easy to bzero rest of struct
	 int index;              // physical entry position to make it easier to peek into memory
	struct MotionEntryStruct *next; // pointer to next physical entry (not necessarily valid entry)
	struct MotionEntryStruct *prev; // pointer to prior physical entry (not necessarily valid entry)
} motionEntryStruct;
#define MOTION_ENTRY_STRUCT_BYTES_TO_PRESERVE   12

typedef struct {
	int validEntries;
	int countdownDelayToExecuteMove; // ms countdown timer to allow "aging" first few entries in the motionQ to allow forward planning
	motionEntryStruct entries[SIZE_OF_MOTION_QUEUE];
	motionEntryStruct *oldest;  // pointer to oldest addition to the motionQ
	motionEntryStruct *newest;  // pointer to newest addition to the motionQ
	motionEntryStruct *planned; // pointer to the oldest entry that still needs to be planned
} motionQStruct;

typedef struct {
	float time;
	float dist;
	float perfectTime;	//used in print/non-print tallies to tabulate "infinite accelerating" time
} timeDistStruct;

typedef struct outboxStruct outboxStruct;   // forward declaration of struct so we can declare a ptr inside struct

typedef struct {
	byte device;
	outboxStruct  *outboxPtr;
	boolean enabled;
	polarity_t polarity;
	int   watchdogMs;
	int   cooldown;
	boolean localControl;
	int   pwmFreq;

	float vectorPowerPct;
	float piercePowerPct; //power pct for pierce (during prime)

	int rasterBitsPerDot;
	int rasterImageDotsPerBinaryValue;
	int rasterPulsesPerDot;  // how man motor steps per pixel (width of pixel in steps)
	int rasterPulseToFireOn; // which subDot step to send out packet to head (inkjet should be in the middle, laser at the start)
	int rasterPulsesPerDotCounter;
	int rasterFrontPorchDots; // number of pixels to wait for before starting raster data
	int rasterFrontPorchDotsCounter;
	int rasterLineCounter;

	boolean rasterReverseDirection;
	int rasterTotalTraverseDots;
	int rasterFirstTraverseDot;
	int rasterLastTraverseDot;
	int rasterFirstActiveDot;
	int rasterLastActiveDot;
	int rasterTraverseDotCounter;
	int rasterActiveBinaryValue;
	unsigned int rasterBinaryValueMask;

	float rasterScanFeedrate;
	float rasterImageOriginMmX;
	float rasterImageOriginMmY;
	float rasterImageDotsPerMmX;
	float rasterImageDotsPerMmY;

	int rasterImageDotsX;
	int rasterImageDotsXmod;    // round up to match groupings of 8 pixels
	int rasterBytesPerFullLine;
	float rasterTotalLineLength;
	int rasterImageDotsY;
	int rasterImageLineCmdEndIndex;
	float rasterMaxPowerPercent;

	int rasterOffValue;
	int rasterOffValueLastWord;
	int rasterLineExcessDots;
	byte rasterColorIndexTable[256];
	float gammaValue;
	float rasterBidirReturnStartAdjust;
	float nextValue;

	boolean rasterBidirectionalScan;
	boolean rasterUseColorIndexTable;
	boolean rasterSkipBlankBorders;
	boolean rasterInvertData;
	boolean rasterizeCurrentMove;
	boolean fireLaserOnNextStep;
	boolean rasterLineComplete;

	TIM_TypeDef *TimerBase;
} laserStruct;

typedef struct {
	float   desiredPowerPct;
	int     pwmFreq;
} spindleStruct;

typedef struct {
	float     dropletsPerMm;
} inkjetStruct;

typedef struct {
	uint32_t startTimeSec;
	timeDistStruct nonPrinting;
	timeDistStruct printing;
	timeDistStruct accel;
	timeDistStruct cruise;
	timeDistStruct decel;
	timeDistStruct prime;
	int canbus_e_steps;
	int unprimes;
	int primes;
	int unprime_primes_avoided;
	int numMoves;
	int motionQ_entriesWhenExecuting[SIZE_OF_MOTION_QUEUE+1];
	int cmdQue_entriesWhenReceived[SIZE_OF_COMMAND_QUEUE+1];
	int max_CommandsInQue;
	int max_motionQvalidEntries;
	int max_DeferredCommandsInQue;
	int max_rawRxCharsInBuf;
	int max_rawUsbRxCharsInBuf;

	int max_urgentRxCharsInBuf;
	int max_normalRxCharsInBuf;
	int max_directRxCharsInBuf;

	int max_normalTxCharsInBuf;
	int max_canTxQ_numMsg;
	int max_canRxQ_numMsg;

	int rejected_normalTxChars;

	int total_commandsProcessed;
	int total_motionQprocessed;
	int total_DeferredProcessed;
	int total_charsRx;
	int total_charsTx;
	int total_canRx;
	int total_canTx;
	int flushedRxCharsDuringAbort;
	int autoDumpOnM30;
} metricsStruct;

#define NUM_SLICE_TIME_ENTRIES  (NUM_1000HZ + NUM_100HZ + NUM_10HZ + NUM_1HZ)

typedef struct {
	char name[16];
	int minTime;
	int maxTime;
	int motionTimerCalls;
} sliceStruct;

typedef struct {
	int matchSlice;
	float counterPeriod;
	uint32_t pin;
	sliceStruct slices[NUM_SLICE_TIME_ENTRIES];
} sliceTimingStruct;

typedef struct {
	union {
		uint32_t u32;
		struct
		{
			unsigned canNumBytesMismatch            : 1;
			unsigned canDestinationUnknown          : 1;
			unsigned canTxFull                      : 1;
			unsigned canRxFull                      : 1;

			unsigned rawRxBufferOverrun             : 1;
			unsigned directRxBufferUnderrun         : 1;
			unsigned directRxBufferOverrun          : 1;

			unsigned urgentRxBufferUnderrun         : 1;
			unsigned urgentRxBufferOverrun          : 1;
			unsigned normalRxBufferUnderrun         : 1;
			unsigned normalRxBufferOverrun          : 1;

			unsigned machineLimitsMaxRateInUPS      : 1;
			unsigned machineLimitsMinRateInUPS      : 1;

			unsigned illegalUseOfAxisC              : 1;
			unsigned unknownDeviceRegistering		: 1;
			unsigned flashStatusErrorDectected		: 1;
			unsigned guiQueueFull					: 1;
		} flags;
	} sent;
} errorSentStruct;

typedef enum {
	PRECANNED_STEP = 0,
	PRECANNED_LASER = 1,
	NUM_PRECANNED,
} preCannedIndex_t;

#ifdef ADD_ON_SPI_DISPLAY
#define GUI_DISPLAY_SPI SPI2
#endif //ADD_ON_SPI_DISPLAY

//NUKE
//#ifdef ADD_ON_SPI_DISPLAY
//#define GUI_DISPLAY_SPI SPI2
//typedef struct {
//	offOn_t             offOnState;
//	boolean             invertedState;
//	int                 page;
//	int                 nextPage;
//	int                 maxPage;
//	byte                rotation;
//	int                 updateIntervalCountMs;
//	int                 updateIntervalMs;
//	int                 vOfs;
//	int                 hOfs;
//	int                 debouceCnt;
//} displayStruct;
//#endif //ADD_ON_SPI_DISPLAY

typedef struct {
	union {
		uint32_t u32;
		struct {
			unsigned led0       : 1;
			unsigned led1       : 1;
			unsigned led2       : 1;
			unsigned led3       : 1;
			unsigned led4       : 1;
			unsigned led5       : 1;
			unsigned led6       : 1;
			unsigned led7       : 1;
		} generic;
		struct {
			unsigned moving     : 1;
			unsigned paused     : 1;
			unsigned blockAbs   : 1;
			unsigned blockAll   : 1;
			unsigned error      : 1;
			unsigned canRx      : 1;
			unsigned canTx      : 1;
			unsigned heartbeat  : 1;
		} baseline;
		struct {
			unsigned lower4     : 4;
			unsigned upper4     : 4;
		} mgmt;
	} currValue;
	uint32_t    lastLcdLedValue;
	int16_t     canRxLedCnt;            // counter to know when to turn off Rx can bus activity indicator
	int16_t     canTxLedCnt;            // counter to know when to turn off Tx can bus activity indicator
	int16_t     usageLedCnt;            // counter to know when to fire generic "usage" LED (step, spew, etc)
	int			heartbeatState;
} ledStruct;

////////////////////////////////////////////////////////////////////////////////

typedef struct
{
	byte            _ctrlIndex[4];              // index values for each of the control loops
	uint32_t        _sliceCnt;                  // count of slices executed
	int				_sliceNum;					// which slice number is executing

	uint32_t        _milliseconds;
	uint32_t         _seconds;                   // number of seconds since powerup (more accurately, number of times through the systick loop)

	int32_t         _extendedSliceTimeNeeded;   // counter for number of extra slices needed by long routines

	canStruct       _canImmediateRx; // buffer to hold next can message to process
	boolean         _canImmediateRxIsAvail;
	canStruct       _canRx; // buffer to hold next can message to process
	boolean         _canRxIsAvail;
	rxQueueStruct   _canRxQ;
	txQueueStruct   _canTxQ;
	uint32_t        _canTransmitMailboxErrorCount[NUM_CAN_HW_UNITS][NUM_CAN_TRANSMIT_MAILBOXES];
	uint32_t        _canTransmitAbortedPackets[NUM_CAN_HW_UNITS][NUM_CAN_TRANSMIT_MAILBOXES];
	byte            _preDefinedAliases[NUM_PRE_DEFINED_ALIASES];        // needed for can routines....in the future, the system can have aliases too!
	byte            _userDefinedAliases[NUM_USER_DEFINED_ALIASES];  // needed for can routines....in the future, the system can have aliases too!
	deviceBootloaderStruct  _bl;
	int16_t         _calibrationTemp;
	byte            _reportCalibrationTemperatureDevice;
	boolean         _reportCalibrationTemperature;
	uint32_t        _reportCalibrationTemperatureRate;
	boolean         _scannerAttached;
	boolean         _jumpToApplicationMain;
	laserStruct     _laser;
	inkjetStruct    _inkjet;
	spindleStruct   _spindle;
	//NUKE int             _preCannedLaserPending;
	int             _preCannedStepPending;
	canSwStruct     _preCannedPackets[NUM_PRECANNED]; // canStep, canLaserPower
	int             _errorCount;
	int				_errorThrottledCount;
	ledStruct		_led;
	flasherStruct   _flasher;
	arcPlane_t      _selectedArcPlane;
	MotorStructure *latheMotor;
	int             _totalMarginedMoveTimeMs;
//#ifdef ADD_ON_SPI_DISPLAY
//   char             _revStr[16];
//NUKE 	displayStruct   _display;
	boolean			_displayIsAlive;
	boolean			_displayForceRedraw;
	int				_displaySelectDebounceCnt;
//#endif //ADD_ON_SPI_DISPLAY
} globalStruct;

#define MAX_ERROR_MESSAGES  5
////////////////////////////////////////////////////////////////////////////////
//  SIMPLE MACROS
////////////////////////////////////////////////////////////////////////////////

#define sqr(X) ((X) * (X))
//#define max(a,b) (((a) > (b)) ? (a) : (b))
//#define min(a,b) (((a) < (b)) ? (a) : (b))

////////////////////////////////////////////////////////////////////////////////
//  Global Variables defined in main that can be referenced by other modules
////////////////////////////////////////////////////////////////////////////////
extern masterPort_t masterCommPort;
extern globalStruct _gs;                      // control index, canbus ques and other stuff
extern motionQStruct motionQ;
extern GMCommandStructure cmdQue[SIZE_OF_COMMAND_QUEUE];
extern GMDeferredCommandStructure deferredCmdQue[SIZE_OF_DEFERRED_COMMAND_QUEUE];
extern int NextDeferredCommandIndex;         // index of the next command to be executed (the one after Current), initially set to 2 after the first command is received and parsed
extern int NextDeferredCommandInsertionIndex;// index of the next free location to add an incomming command
extern boolean DeferredCmdReadyToProcess;

extern MotorStructure Motors[];
extern GMCommandStructure *ExecutionPtr;   //executionPtr=&cmdQue[CurrentCommandPointer];
extern boolean ForceReportXYZLocation;
extern boolean AutoReportXYZLocation;   // GB XXX FLAG
extern boolean AutoReportFeedRate;   // GB XXX FLAG
extern boolean AutoReportLineNum;
extern boolean StatusReportXYZLocation;   // GB XXX FLAG
extern boolean StatusReportVelocity;   // GB XXX FLAG
extern boolean StatusReportFlowRate;   // GB XXX FLAG
extern boolean StatusReportLineNum;
extern boolean _printAir; // GB XXX FLAG
extern float _autoReverseAndPrimeMinTime;
extern E_control_t _extrusionControl;
extern E_control_t _saveExtrusionControl;
extern motionForFlowControl_t _motionForFlowControl;
extern unprime_prime_control_t _unprimePrimeControl;
extern boolean _hijackAxisC;
extern boolean _canbusStepForE;
extern boolean _directStepForE;
extern float E_Q_LastRequestedPositionInUnits;
extern int E_Q_POSITION;
extern float TurboModeDistance;
extern int G1Flag;
extern int G0Flag;
extern boolean _reverseFrogToe;
extern boolean _spiralRoughingPass; // SPIRAL
extern float _deltaRForPass; // SPIRAL
extern int G2G3Flag;
extern int G203State;
extern boolean _motionQ_LookAheadDisabled; //GB XXX FLAG
extern boolean _motionQ_ForceQtoEmpty; //GB XXX FLAG
extern boolean _blockImmediateMoveOnToolChange; //GB XXX FLAG
extern int dump407SoapstringFlag;
extern int CurrentLayer;
extern int _gcodeLineNumber;
extern int _gcodeMotionLineNumber;
extern int DDLightFunction;
extern int PrimeTimer;
extern int UnPrimeTimer;
extern ToolOffsetStructure ToolOffsets[NUM_TOOL_OFFSETS];
extern int currentToolIndex;
extern int currentFixtureIndex;
extern int currentHeadIndex;
extern GMCommandStructure *CannedCyclePtr;
extern int CannedCycleLastMove;
extern int CannedCycleFlag;
extern int CannedCycleStep;
extern float CannedCycleZFeedRateInMmPerSec;
extern float CannedZDepthInMM;
extern float CannedZDesiredDepth;
extern float CannedZIncrement;
extern float CannedZQIncrement;
extern float CannedThreadPitch;
extern float CannedZClearInMM;
extern int CannedLinearAxis;
extern int CannedRotaryAxis;
extern HssPwmStruct *CannedHssPtr;
extern boolean CannedCyclePuffFlag;
extern int _repetrelCommWatchCount;
extern boolean _waitingForGuiCommand;
extern int _abortInProgress;
extern int _abortCameFromRx;
extern boolean _abortFinisedNeedToResetProcessSynchronously;
extern uint32_t _g4DwellTimer;
extern boolean _gcodePaused;
extern boolean _blockAllMotion;
extern boolean _blockAbsoluteMotion;
extern boolean _blockAllMotionMessageSent;
extern boolean _blockAbsoluteMotionMessageSent;
extern boolean _blockMotionForJoggingMessageSent;
extern boolean _blockMotionForHighVoltageMessageSent;
extern boolean _blockJoggingForMotionMessageSent;
extern boolean _motionSensorTripped;
extern boolean _validFirmwareKey;
extern char GCodeArgComment[];
extern char _GcodeArgStringParam[];
extern boolean _requestToPauseAtEndOfMove;
extern boolean _requestToPauseAtEndOfLayer;
extern boolean _requestToAbortAtEndOfMove;
extern boolean _abortOccurredWhileMoving;
extern int32_t _needToWiggleDirectionPins;
extern GMCommandStructure *G1UnprimePtr;
extern GMCommandStructure *LookAheadPointer;
extern int PreProcessNextCodeFlag;
extern int CommandsInQue;
extern int DeferredCommandsInQue;
extern int LastCmdQueIndexAddedToMotionQ;
extern boolean _needToProcessDeferredCommands;
extern boolean _needToDeleteAndExecuteNextMove;

extern boolean _Tim7StillCalculating;
#ifdef ALLOW_NATIVE_LIGHTBURN
extern boolean _lightburnModeEnabled;
#endif //ALLOW_NATIVE_LIGHTBURN
extern sensorStruct startButton;
extern sensorStruct EMO;
#ifdef USE_AB_ENCODER
extern sensorStruct ABEncoderSelectButton;
#endif //USE_AB_ENCODER
extern int _highVoltageIsNotStableCoundownMs;

#ifdef COLLECT_METRICS
extern metricsStruct _metrics;
#endif //COLLECT_METRICS

//#ifdef MEASURE_TIME_SLIPPAGE
extern int _timeSlipTimer2Passes;
extern boolean _sendTimeSlippageData;
//#endif //MEASURE_TIME_SLIPPAGE

extern boolean _TouchProbeMoveActive;
extern byte _TouchProbeCanDevice;
extern int _TouchProbeEXTI_Line;
extern uint8_t _TouchProbeNVIC_IRQChannel;

extern boolean _edgeTriggerArmed;
extern boolean _edgeTriggerDetected;
extern float _edgeTriggerDisplayRateHz;

extern int pendingAcknowledge;
extern int _gcodeCmdsReceived;
extern int _gcodeAcksSent;
extern unsigned int _asciiChecksum32;
extern unsigned int _rejected_normalTxChars;
extern unsigned int _asciiCharsRcvd;
extern int normalRxBufHeadroom;
extern float _FlowRateOverridePct;
extern float _FeedRateOverridePct;
extern float _MotionRateOverridePct;
extern float _CompositeFlowOverridePct;
extern float _CompositeMotionOverridePct;
extern const crashLog_struct _crashLog[];
extern const int NUM_CRASHLOG_ENTRIES;
extern sliceTimingStruct _sliceTiming;
extern int _motionTimerCalls;
extern errorSentStruct _errors;
extern int HostConnectionWatchDog;
#ifdef ENABLE_CRASH_LOGGING
extern char crash_source[];
extern char blankChar;
extern int SerialPortOverRunCnt;
#endif
extern char resetSourceStr[];

extern int _heartbeatRateControl;
extern int32_t lsiActualFreq;
extern uint32_t lsiCC4sampleIndex;
extern uint32_t lsiCC4samples[];

extern int hssFuncToPinIndex[];
extern HssPwmStruct HighSideSwitches[];

extern char _bootupAlertHostChar;
extern boolean _sendBootupAlertHostChar;

extern pinType HEARTBEAT_PIN;

////////////////////////////////////////////////////////////////////////////////
//  Public Methods available in main
////////////////////////////////////////////////////////////////////////////////

extern uint32_t interruptsOff(void);
extern void interruptsOn(uint32_t);
extern void setTouchPositionToCurrentPosition(void);
extern void TouchProbeSendResults(probeResults_t, probeType_t, int);
extern void TouchProbeFinished(probeResults_t, probeType_t, int);
extern void TouchProbeProcessContact(probeType_t, int);
extern int getSliceCnt(void);
extern void pingReply (void);
extern int32_t getCurrentExecutingLineNumber(void);
extern void ReportXYZLocation(void);
extern void wait100ns(void);
extern void SendNext407SoapString(void);
extern void setPauseGcodeFlag(char);
extern void ResetProcess(boolean);
extern boolean anyAxisNeedingToBeHomed(void);
extern sensorState_t readSensorBit(sensorStruct *);
extern void outputControlBit(controlBitStruct *, assertValue_t);
extern void assertControlBit(controlBitStruct *);
extern void deassertControlBit(controlBitStruct *);
extern int readControlBitValue(controlBitStruct *);
extern assertValue_t readControlBitState(controlBitStruct *);
extern void outputDirectionBit(directionBitStruct *, pinStateValue_t);
extern int readDirectionBitValue(directionBitStruct *);
extern direction_t readDirectionBitState(directionBitStruct *outputPtr);
extern int readSensorBitValue(sensorStruct *sensorPtr);
extern sensorState_t readSensorBitState(sensorStruct *);
extern void setSensorBitState(sensorStruct *sensorPtr, uint32_t value);
extern boolean sensorEnabledAndTripped(sensorStruct *sensorPtr);
extern int getNextDeferredCommandIndex(int);

extern void initSensor(sensorStruct *, sensorIndex_t, char *, boolean, polarity_t, pinType, int);
extern void setSensorToUnknownState(sensorStruct *);
extern sensorState_t readDebouncedSensorState(sensorStruct *);
extern sensorState_t fastReadDebouncedSensorState(sensorStruct *);
extern void updateSensorHistoryIfEnabledWithoutIrq(sensorStruct *);
extern void setSensorEnable(sensorStruct *, boolean);
extern void setSensorPolarityAndEnable(sensorStruct *, polarity_t, boolean);
extern sensorStruct *getMotorSensorPtr( MotorStructure *, sensorIndex_t);
extern float fpu_sqrtf(float);

extern boolean almostTheSameByPct(float, float, float);
extern boolean notAlmostTheSameByPct(float, float, float);
extern boolean almostTheSameByDelta(float, float, float);
extern boolean notAlmostTheSameByDelta(float, float, float);

extern void resetVariableOnJobEnd(boolean realJobEnd);
extern void puff(void);
extern void processCannedCycle(void);
extern void ProcessG28MultipassHoming(void);
extern void SetAxisHomePosition(MotorStructure *);
extern void SetAllAxisHomePosition(boolean);
extern void updateHssPwm(HssPwmStruct *);
extern void changeHssDuty(HssPwmStruct *, float);
extern void initAllHss(void);
extern int convertToolNumberToDevice(int toolNumber);
extern int convertDeviceToToolNumber(int device);
extern boolean cmdQueIsEmpty(void);
extern void processCommand(GMCommandStructure *);
extern void InvalidateAllCmdArgs(GMCommandStructure *);
extern boolean deferredCmdQueueFull(void);
extern void copyCmdQueEntryToDeferredCmdQue(GMCommandStructure *);
extern void processDeferredCommands(void);
extern void sendAxisHomedStatus(MotorStructure *);
extern void sendAllAxisHomedStatus(void);
extern char *getUIDString(char *);
extern void sendFakeM687CompleteCode(void);
extern void sendRevisionString(char *);
extern boolean ArmTouchProbe(int, probeType_t);
extern void ProcessTouchProbeAfterContact(void);
extern void Crash_Handler(char *);
extern void checkAndClearFlashStatus(void);
extern void protectedIncrement(int *);
extern void protectedDecrement(int *);
extern void catastrophicError(char *);
extern void catastrophicErrorWithDebugInfo(char *);
extern void requireAllAxesToHome(void);
extern void sendEmoMessage(void);
extern void EdgeTriggerSendResults(void);
//extern boolean SetupEXTI(int, probeType_t, EXTITrigger_TypeDef, int);
extern void DisableEXTI(void);

////////////////////////////////////////////////////////////////////////////////


#endif /* OLD_MAIN_H_ */
