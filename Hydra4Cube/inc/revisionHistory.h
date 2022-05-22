////////////////////////////////////////////////////////////////////////////////

#define SOFTWARE_MAJOR_REVISION     4   // XXX  update when a major change occurs (ie, protocol)
#define SOFTWARE_MINOR_REVISION     000 // XXX  update for major and minor changes
#define SOFTWARE_TWEAK_REVISION    'K'  // XXX  update for small changes ('z' is for experimental ONLY)

#define SOFTWARE_DEBUG_REVISION    'D'  // XXX  char update for debug versions  (applies to 'z' versions only  is for experimental ONLY) (display with M115)

#if (SOFTWARE_TWEAK_REVISION == 'z')
#define GB_DEBUGGING
#endif

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2013  HYREL 3D, LLC.   All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////
//
// since this is the main project include file, also include files the ALL modules
// will need.  Do not list includes that only a few of the modules will need, let
// those modules include those files.
//
////////////////////////////////////////////////////////////////////////////////
///
// File:    main.h
//
////////////////////////////////////////////////////////////////////////////////
//
// Purpose: Contains main specific defines, global references, and method prototypes
//
// Code Revision History:
//
// 4.000a - Initial release (similar level to 3.083m
//      - added CATASTROPHIC abort on bad arcs and motion exceeding scaled limits (M91 ArgS)
//////////RELEASED 2019/05/16
// 4.000b
//      - added to  M686 to also return the key seed as
//        >MC:M686:"seed_value"
//////////RELEASED 2019/05/16
// 4.000c
//      - add to M687 to also return the key that was used to unlock motion
//        >MC:M687:"key_value"
//        >MC:M687:INVALID-"key_value"
//      - return "fake" >MC:M687 whenever connection string is sent to the host containing the last
//        key that was used to (attempt) to unlock motion
//      - change G12 and G13 to single step
//        change ExecuteG2G3PointMove() to not execute until at least 2 spots are open in the motionQ
//      - added GB_STRING for debugging multicycle routines (ie G12 G13)
//////////RELEASED 2019/05/17
// 4.000d
//      - added error throttle per print job... first 25 can go as fast as possible....after than, limit is one per second.
//      - fixed bug with # bytes for CAN_MSG_EXTREMES to V0 heads
//      - started adding code to handle alias to mixture of V0 / V1 heads - does not look promising
//      - fixed case where USING_E_VALUES was not handled during an abort (E_Pulsees nor zeroed out)
//      - fixed bug in V0 heads for setting type/subtype/etc from soap string (assumes ALL heads will get a new soapstring)
//      - changed strings for reading device info to be more terse and less caps to better fit in the small window.
//      - moved >RG: string to after soapstring has been read.
//////////RELEASED 2019/05/18
// 4.000e
//      - changed default behavior for logical devices to be CANBUS_FORMAT_V1 and not CANBUS_FORMAT_V0
//      - added warning when a pre-4.x head registers that logical address may not work
//      - added support for addition subtypes for DIODE lasers (open drain and no cooldown fan)
//      - tweak PICK_N_PLACE to PICKNPLACE to match head definitions
//////////RELEASED 2019/05/19
// 4.000f
//      - changed master.c to autosend seed as >MC along with connection string to auto populaste the seed in the GUI
//      - limit M91 S arg to >= 1.0f; (bounding box scaling)
//      - add check to not write to flash if (validLicenseKey && soap[R1_AREA+0]='*M687"). an error is sent to
//        alert the user
//      - changed M762 to explicity require R=1.0 for talking to new restricted area for firmware key
//      - special case M623 to allow long pulse time for UV Light Rays headtype (which is overloading the LASER code path)
//      - added support for new 3PH_spindle tool.
//      - changed heartbeat led rate to 0.5 bps and abort rate to 5 bps
//      - changed function and name of ERROR_LED to CAN_TX_LED to show canbus RX traffic instead of ERROR conditions to
//      - changed tambora default settings for maxDc from 80 to 100 (per joe & karl) 8amp fuse for customer to install
//      - tweak PICK_N_PLACE to PICKNPLACE to match head definitions
//////////RELEASED 2019/05/21
// 4.000g
//      - changed M98 axis C to enable/disable EMO.  removed EMO control from M96 (backdoor)
//      - added M220 to allow connecting a head to any axis for motion where a CAN_STEP packet will be sent to the head
//        each time the motor steps.  NOTE: the motor does not physically need to be installed, but does need to be
//        properly set up the Machine I/O tab of repetrel
//      - added new deviceType SOAP_DEV_TYPE_GENERIC_HEAD (first use is weathervaning)
//      - added generic head switch control functions for off, on, dc, temp, and pwm M240-M244
//      - change devCodebases Medusa/PickNPlace to Medusa4/PickNPlace4 in headSetup.c
//////////RELEASED 2019/05/23
// 4.000h
//      - fixed bugs with mechanism to store to 2 diff areas of flash, keep one persistent across an erase, have
//        separate read/write control to each, and to prevent users from trying to reflash a firmware key multiple times
//        if they already have a valid key flashed.
//////////RELEASED 2019/05/23
// 4.000i
//      - added init fields for allowable add-ons (probes, am2303, hx711) and allowable PCBs
//      - change M763 to also clear system error flags is ARG_T == 0
//      - change M678 to turn on head 11 AUX for laser cross hair
//      - M240-M245 cleanup
//      - fix AbortTravelScaling calc such that resulting range of a given axis is range*scale, centered on the midpoint
//        of the original axis range.  prior code extended the range in each direction but the amount of scale*range.
//      - reformatted head registration/INF string to better fit in the GUI "Read Params" textbox -- and to match Karl's
//        formatting (newline) option replacing '~' in the string with a newline.
//      - added abort motion call if lost comm with a head AND that head is the current active head
//      - pulled M237 from 2017 attempt at Hydra4 and merged into M245 (switch control)
//      - G2.1 and G3.1 now no longer return to the origin of the move, but rather stop at the end of the archimedes spiral
//        users can then add code to lift Z and move out of the frog toe back to the origin (or where else they need to go)
//        THIS IS A MAJOR CHANGE IN BEHAVIOR
//      - G2.1/G3.1 - added optional ArgR which causes the path of the spiral to be reversed.  A non-printing move is added
//        to get to the new starting point (former end point without R) and the spiral is made backwards with the final
//        position being equal to the start position.
//      - G2/G3 -- if using E, then E = amount for entire arc  if using ArgS to limit # of sides, then E is NOW auto scaled by
//        the ratio of the perimeter length of the inscribed N-sided figure to the circumference of the circle defined by the
//        I/J displacement.
//      - fix issue where very small negative unprime time combined with slow speeds could result in unprimes not being issued.
//////////RELEASED 2019/06/02
// 4.000j
//      - fix bug in head combo checking.  PCB_ALL option was missed.
//////////RELEASED 2019/06/03
// 4.000k
//      - found severe bug in abort code.... if the abort occurred during the motionQ_addCommand call, the 'newest' entry in the
//        queue could be incomplete, because the newest location in the Q was being built live (get a pointer to open spot in the queue
//        and then fill it in.   because of this, a scratchpad piece of memory is now being used to fill in the entry and only once complete
//        will it be copied into the actua queue.   this might clear up a few anomolous aborts that occasionally occur
//      - limit accelerationConstant to a min of 0.01 in M208 to avoid div by 0
//      - added band-aid of a watchdog on an abort to clear everything after 5 seconds ... just in case
//      - dropped the reset of processSoapstringCommands from ResetProcess() as the self init was aborting sometimes if
//        repretrel pinged at the wrong time.  this prevented the license key from being seen as well as other self init
//        code from the soap area
//      - change alert char to repetrel from 8 to 9 (ABORT_CHAR to 911_CHAR --> CATASTROPIC_ERROR_ALERT_CHAR)
//      - change abort code to only send 911_CHAR if self inflicted abort, not a requested abort to a avoid a death
//        spiral of aborts between rep and the MC
//      - limited burst error messages to 3, then once per second after that until reset (was burst of 25)
//      - added gcode line number to all system generated error messages (not head originating messages)
//      - changed self-init code to block incoming RX until the self-init is done.  too many paths wish special chars (ABORT_CHAR) that
//        could step on the processing.
//      - change warning about 3.x heads registering to an ERROR.
//////////RELEASED 2019/06/04
// 4.000l
//      - EXTRUDERS: fixed bug in PCB check in checkForValidDeviceCombination()   PCB_MJ was wrong (excluded wrong board)
//      - fix formatting for line number on motionErrors
//      - fix bug introduced with cleaning up abort code in motionQ_addCommand -- missed propogating "lastInSequence" into the Q if the new
//        move did not get added to the queue, but that move was supposed to be last in sequence
//      - fix bug introduced with cleaning up abort code in motionQ_addCommand -- screwed up start speed limit
//////////RELEASED 2019/06/04
// 4.000m
//      - added option to tracking commands rcvd and acks sent to track down issue where repetrel and the MC are getting out of sync at times
//        counters are reset each GUI Reset; at powerup, and if a control char '6' is sent (ASCII_ACK)  hijacked GB_STRING_HEARTBEAT (0x10) to enable
//        dump of information.
//                  >GB: COM: lineNum: cmds_rcvd: sum_acks_send+pending: acks_sent: acks_pending: charsRcvd: checksum32:
//        the checksum is literally a 32-bit unsigned int summation of each character arriving  (checksum32 += newChar).   in rough terms, about 50M chars
//        can be received before the counter rolls over.
//      - added code sync tge sending of the fake M687 completion code to the systick call as it was happening async to everything
//      - removed _gcodeLineNumber=0 from M30 call.  no more auto changing it...up to user to insert N=xxxx in their code
//////////RELEASED 2019/06/09
// 4.000n
//      - added standard gcode per-line checksum calc qith a "*XX" at the end of line.   all chars before the '*' are part of the checksum.
//        the ascii digits after the '*' are the one byte checksum displayed as a decimal integer in ascii.
//              int cs = 0;
//              for(i = 0; i<parseIndex; i++)
//                  cs = cs ^ cmd[i];
//      - undefined ALLOW_DIRECT_BUFFER_FOR_RASTER_DATA as part of hunt for dropped acks
//      - changed GB_STRING_HEARTBEAT to GB_STRING_COMM_ACK_CHECK (0x10)
//      - re-enabled COLLECT_METRICS #define ..... add a M772 S31 as fist line of a print job... will auto dump all stats on M30.
//////////RELEASED 2019/06/11
// 4.000o
//      - fixed CRITCAL bug in the calculation for when to unprime during the move.  the case for the unpriming occuring during the cruise
//        portion of the move was missing a term (axisScale) and the calc resulted in a pulse count that was outside of the move.  the term
//        was added in AND a safety check was added to ensure the pulsecount was inside of the move.
//////////RELEASED 2019/06/11
// 4.000p
//      - added options to M797 (P and R) to enable echo-ing on serial data to a specified port. select port with P and chars processed to
//        parse ascii commands are echoed (excludes single 'special' char commands.   if port is selected with an R, the ALL chars are echoed
//        as received. ports 0=none/off; 1=usb, 3/4/6 = uart3/4/6;)
//      - changed per-line ascii checksum to use a 2-byte summation instead of the not-so-good) unshifted xor reprap method
//      - added THREE temporary ERROR messages for CAN_E_VALES for negative E movement to help debug unwinding of material
//////////RELEASED 2019/06/13
// 4.000q
//      - added outbut buffer on serial echo path
//////////RELEASED 2019/06/13
// 4.000r
//      - added fakeMcodeCompletion notices for M104 and M106 when a head registers to try to get the GUI in sync;
//      - added fakeMcodeCompletion notices for M670 after boot/reset to try to get the GUI in sync;
//      - added a C option to M703 (add alias).  if C=1, then the selected head's (T) data structure is copied to the structure for the alias
//        this should ease the burden of greating groups.
//      - CRITICAL CHANGE: moved serialProcessor back from loop in main back it's own slice time
//      - added echoBuffer variables to resetSerialOutputBuffer()  {echo failed after a reset}
//////////RELEASED 2019/06/16
// 4.000s
//      - fixed fake M670 return for default DDL behavior after reset
//      - change heartbeart 2bps for case where pending ACKs, 0.5pbs otherwise
//      - move more of foregroup tasks from main() while(1) to slices
//////////RELEASED 2019/06/17
// 4.000t
//      - identical to 's' but with 19.2K baud
//////////RELEASED 2019/06/17
// 4.000u
//      - returned to 38.4K baud
//      - special build with license key debug
//////////RELEASED TO DAVO ONLY 2019/06/17
// 4.000v
//      - move executeMove out of processRawBuffer() when pause ends.flag set to next call to sequenceEngine motion will restart (at most a 1ms delay)
//      - cleanup legacy code in sendChar (took out legacy crap to try to stuff a few extra chars in a full tx queue)
//      - added tracking of tx chars rejected.  will report as last field in GB_STRING 0x10 and with "metrics".  if will NOT report otherwise (so no error msg)
//      - redo sendAck code to make ALL ack's pending and use printCheck() to send acks
//      - ASCII_ACKS are now sent at PrintCheck() time only (if room in serialRX buffer).  if no ACK is sent, then a regular char is sent.
//        pendinAck counter is no longer "protected" with incr/decr as ProcessRawRxBuffer() and PrintCheck() are both called from SysTick.
//      - EMO changes still work in progress -- EMO turned off
//////////RELEASED 2019/06/18
// 4.000w
//      - HOTBEDS:  init table was wrong for chamber heater (was incorrectly set to active low); fix default prescale for chamber in MCode.c
//      - change min/max for all OverridePct to 0 to 15.999
//      - added fake mcode completion notice for M723 to get GUI in sync after comm timeout OR after a reset
//      - add second option for all HOTBEDS to control whether they drive via LIMIT1 or the HTR_HSS
//              HOTBED_100 (Std/Opt0 = LIMIT1; Opt1 = HSS)
//              HOTBED_120, HOTBED_200  (Std/Opt0 = HSS;  Opt1 = LIMIT1)    {LIMIT1 used by engineHR)
//      - cleaned up error message for missing RTD selection on heated heads
//      - clean up naming for default (unnamed) device subtypes
//      - WARNING START BUTTON/EMO/MOTOR FAULTS are DISABLED in the version
//////////RELEASED 2019/06/19
// 4.000x
//      - swap option0/option1 subtype for CO2 laser
//      - change CO2_LASER_LENS check from forced in slot 11 to being the leftmost installed device
//      - added Co2 lasers to "useCooldown" init and change from useDC to UseOn
//      - allow M686/M687/M688 to take extra slice time for security key stuff (only occurs at boot or reset time)
//      - moved up sending home state and m686/m687 completion codes in sendRevisionString() to BEFORE the connection
//        string to avoid issues from Repetrel sending multiple back to back resets/pings
//      - added M238 to allow any axis to copy the E value in a line of GCODE to use as it's position
//      - added option to press physical START button on Hydra control panel to dump all of metrics if GB_STRING 0x10 is enabled (COMM)
//      - reinstated checks on StartButton, EMO, Motor Sensors Fault, L1, and L2
//        more robust noise rejection and a unified routing for all motor sensors
//      - unified naming on HYREL StallSense and HYDRA FaultSense to FaultSense
//////////RELEASED 2019/06/21
// 4.001a
//      - KEYS:  fixed severe bug where some seed data was stepped on causing aliasing of keys.
//      - KEYS:  changed list of key gen from firmwareKey to UUID based
//////////RELEASED 2019/06/24
// 4.001b
//      - fix bug in USB which was introduced in 4.000v
//      - KEY: removed ENABLE_SECURITY (made permanent)
//////////RELEASED 2019/06/24
// 4.001c
//      - added debug options for Karl to allow selecting from a small list of variables that when set will cause a selected light to blink (_gs._flasher)
//      - added code to reset sticky errors each time and M620 E1 is issued
//      - changed minTemp init for LASERS to be threshold for turning on cooling (set to 35C)
//////////RELEASED 2019/06/24
// 4.001d
//      - no behavior change, just code opt for sending EMO message
//      - changed default for HYDRA to disable EMO.  must be enabled with M98 C0 or C1 (active low or active high) ...
//      - additional coding on 3D arc
//      - changed ARC_TOLERANCE from 0.1f to 0.002f per the RS374/NGC Interpreter spec
//      - added G16-G19 to control work plane for G2/G3 arcs (default is PLANE_XY)
//      - added controlWord bit to enable/disable heads from sending strings via canbus (controlled via M719)
//        needed for CO2 laser power supply with UART.
//      - fix bug where a tripped EMO at boot time did not aabort motion
//      - RASTER: Changed M624 to take dots/mm instead of mm_per_dot
//      - RASTER: copied code from original Hydra4 project
//      - RASTER: ALLOW_DIRECT_BUFFER_FOR_RASTER_DATA is STILL UNDEFINED (no RASTER)
//////////RELEASED 2019/07/02
// 4.001e
//      - RASTER: continued debug of code merge
//      - RASTER: added protection so if a '$' (DIRECT_CHAR_START) appears in a comment, it will not trigger
//        a switch to used the direct buffer
//      - RASTER: added protection such that a ';' in a direct char stream will not trigger a comment
//      - RASTER: #define ALLOW_DIRECT_BUFFER_FOR_RASTER_DATA  reinstated for this release.
//////////RELEASED 2019/07/03
// 4.002a --- SYNC RELEASE WITH MEDUSA4.002A  (format change)
//      - change from a 0.16/0.8 to 1.15/1.7 for powerLevelPct
//      - SPINDLE/LASER: changed scaling on powerPct from 0.16 to 1.15 to allow for a true 1.0 to be sent.  coincides
//        with MEDUSA4.002a
//      - increased maxPwmRate to 5000 for spindle tools (default is 2K)
//////////RELEASED 2019/07/03
// 4.002b
//      - RASTER: for bidir scanning, add the DEF startAdjust value to user input instead of replacing the def with user
//        input.
//      - fix issue in SetupLasetToRun for local control (1) power to head 41 set to 0 (2) vector power was incorrectly used
//        to setup CCR for timer instead of requested power (input to method)
//      - change default for pierce power to be vector power (M621) when argD is omitted
//      - fixed bug with pierce power and local control
//////////RELEASED 2019/07/12
// 4.002c
//      - added 2 more "flasher" variable (M797 Vx) for debug (_gcodePaused and BlockAllMotion)
//      - changed "EMO Released" to clear the BlockAllMotion flag (still requires homing, but will all relative moves and NOT
//        require a "RESET" (from GUI)
//      - fix bug in reporting of subtype for HOTBED120/200 (inadvertantly keyed off deviceType instead of deviceSubtype)
//      - added small dwell (50ms) between trying to add commands to motion Q when motion is blocked to prevent repetrel from
//        becoming non-responsive (lines are being sent and acked fast and "clicks" (ie, Kill) get buffered in the GUI but
//        were not sent to the hardward --- THIS WOULD LOOK LIKE A MOTION CONTROLLER HANG, when in fact it was the GUI.
//      - added flag ("homingFailed" for when pop off fails to make sure "axisHomed" does not get set if this pop off failed
//      - added extra checks in abort when safe to flag if 'curr' pointer was getting out of range
//      - fixed nagging bug with arc commands sometimes generating a bad move.   two-fold issue (though one may only have been an
//        issue because of the other.    in seq eng, there was a return for "geG2Flag > 0" but should have also checked for G203State
//        being non zero.     in execcuteG2G3PointMove, ExecutionPtr was not reloaded in the case of G2G3Flag == 0.
//      - changed G2.1 to calc finish position of the sprial and use that as last point instead of skipping move back to start
//      - revert change executeG2G3PointMove to exit on motionQ_full (instead of almostFull)
//////////RELEASED 2019/07/29
// 4.002d
//      - updated new ExecuteArcPointMove to match changes made in 4.002c for multi move commands
//      - added more variables to crashLog and to value to map to DDL  (for Kill/Reset lockup issue
//      - changed loading to urgent buffer take priority over loading direct buffer (raster)
//      - clear M238 (M->SubstituteAxisArgWithArgE) on kill/reset
//      - G38 added Oarg to specify an addition offset for toolOffset (H=Z+O)
//////////RELEASED 2019/08/06
// 4.002e
//      - fixed cut and paste error with G38 change.
//////////RELEASED 2019/08/06
// 4.002f
//      - changed info message for G38 setting toolIndex H value
//      - clean up error messages originating from heads
//      - added M797 I1 option to dump state of certain I/O (all motor IO)
//      - force 5 second wait when enabling CO2 power supply to give time for water pressure to build. (M620)
//      - recovered 3 head control word bits (ignoreRTDx) ..  ignoreRTD3 repuposed as debugRTD flag going to heads
//      - retired M710/711/712 (ignoreRTDx control).   M712 converted to code to set debugRTD flag (M712 S1)
//      - replaced raster format with new one relying on simple binary number of bits per pixel;
//      - added color index table (M626) for translating raster data
//      - added gamma option for modifying raster data to tube (similar to crt monitor gamma function)
//        newLaserPower = oldLaserPower ^ (1.0/gammaVal);   (laserPower values in range of 0.0 to 1.0
//      - added optimization for laser raster data to non print (or move over) '0' values on left and right
//        sides of an image.
//////////RELEASED 2019/08/08
// 4.002g
//      - raster - added imageInvertData option
//      - fixed typo in M245 -- "onWhenExtruding" referenced wrong arg; also in M245 fixed wrong "area" passed to devInit method
//      - fixed bug in decision op in canWriteSwitchFlag_onOnlyWhenExtruding that would result in the flag being set in
//        wrong switch
//////////RELEASED 2019/08/09
// 4.002h
//      - more raster cleanup for optimizations for non-printing leading and trailing portions of a scan line
//      - started mucking with USB code (flow control in USB lib for tx data (hydra to PC) is non-existant (and hydra code called
//        the one and only (but wrong) method for flow control)
//      - MAJOR overhaul of the USB code.  removed all of TM's code and redid part of stm_lib's to remove
//        redundant data buffering and to add working flow control.  this code is less generic than it was (strictly
//        a FULL SPEED, Virtual Comm Port.
//      - remaining issue with this is REPETREL needs to respond to a 0x7 (PING/ANNOUNCE CHAR) with a PING in order to set the comm
//        master at boot/hw_reset time
//      - the new implementation has a different sw burden (ReceiveChar and ProcessRaxRx have a more bursty load, though total CPU load is
//        reduced
//////////RELEASED 2019/08/18
// 4.002i
//      - changed "ANNOUNCE CHAR" (HELLO_WORLD) from 0x7 to 0x4
//      - -added lathe mode for A/B axis using M3/4/5
//      - switched around all motor timers so that TIM9 could be used for direct output for STEP from TIM9_CH2 for lathe mode
//      - limited lathe mode to axis A for HYREL and axis B for Hydra (only available STEP pins connected to a useable timer
//      - aded PULLUPs in pin def fro CANx_RX pins to all bench testing of just ram 407/429 parts and be able to look at the CAN_TX line
//        (which will get killed in CAN_RX ever sees a 0 when CAN_TX is driving a 1.
//      - slight cleanup of CAN_Config()  [no functional change]
//      - added M633 Ex to enable/disable the use of CAN2 -- power on default is enabled to match prior behavior.
//////////RELEASED 2019/08/22
// 4.002j
//      - added SOFTWARE_DEBUG_REVISION to allow embedding a revision for 'z' version.   M115 can be used to send out the value in the interface window
//      - when lathe mode switched from ISR to direct step created from timer, the ability to send the step over the canbus for this mode
//        was lost...but the mode change to the head was still sent.  this mode change init to the can device has been removed.
//      - change lathe mode to allow change of direction without having user stop spindle first
//      - add separate max PPS check for timers for raster mode (can be set with an M212 Rxx
//      - change max time for M623 for a UVATA (UVLIGHT_RAY) head from 10 seconds to 60 seconds.
//      - change HYREL build target to not enable CAN2 (new 100094 rev 9 board is CAN1 only)
//      - removed M633 now that CAN2 issue is resolved on the rev9 100094 board (was added for ease of debug)
//      - change M106 Cxxx (_M106_fanDutyCycleRange) to reset to 100 on a job kill.  was reset after an M30, but missed on the kill.
//////////RELEASED 2019/08/28
// 4.003a
//      - added support for DEVICE_TARGET_MEDUSA_407
//      - changed pageDef reporting for medusa 4.003 or greater to only report page or sector for the soapstring
//      - complete remapping of bit positions in pin defs to allow use of bitfields (adopting Medusa methods) to make it cleaner
//        to support a dual 103/407 ... now allows sharing of the gpio code between the two projects.
//      - added support for two addition rtd types (4-20ma and adcRaw).
// 4.003b
//      - change all TEMP controlled heads to SLAM ON.
//////////RELEASED 2019/09/26
// 4.003c
//      - added RH_SYRINGE head type (refrigerated & heated syringe head)
//      - added repetrel comm watchdog, but did not enable head reset until time to test
//////////RELEASED 2019/10/16
// 4.003d
//      - reinstated call to initKey(FALSE) in main() that was inadvertantly deleted in version 4.002h with the net result of
//        keeping key generators from working.
//      - change LARGEST_SPECIAL_CHAR to 31 (0x1f) to provide headroom for future use
//      - fix UVLIGHT_RAY setup info (maxPwmFree was 0 instead of 10000)
//      - added software based millisecond counter for debug
//      - fixed bug in MotionIsNotComplete() (now renamed to AnyPotentialMotion()) .... which was used by the Homing sequence
//        to know to move on the next step.  Needed to also check if a the start of a move was deferred by N milliseconds for either
//        first move in the queue or for enabling the MOTOR_ENABLE
//      - changed shortcut for the first mQ entery aging to not abort the wait for longer waits (such as the MOTOR_EN wait)
//////////RELEASED 2019/10/24
// 4.003e
//      - added M800 for sonicator control
//      - added sonicator head type
//      - moved call to initInboxStruct() to after sending reset in checkForMia()
//      - added watchdog value to packet sent to extruders to run so that cases where laser_family (ie UVATA) devices are cloned
//        to an extruder.
//////////RELEASED 2019/11/11
// 4.004a
//      - fixed two bug in "pause at end of next move" code. (1) failed to properly insert a "prime" command when motion
//        resumed (wrong pointer in queue was referenced) and (2) _requestToPauseAtEndOfMove was not set to FALSE immediately
//        after the motionQ was modifed for the pause (and that method was called multiple times).
//      - fixed offset by 1 issue with prescale count for sending heartbeat status message back to the host (tied to M719)
//      - added per axis semaphores for L1/L2 sensors to block neg/pos relative moves (in addition to absolute moves) if sensor is tripped
//      - increase motionQ size from 15 to 30 (faster arc speed for G2/G3)
//      - reworked compiler targets based on new naming scheme
//      - fixed bug in checkMotorSensor() (typo '=' instead of '==' in check for motor 'C" and L1 sensor (highjacked for EMO)
//      - increased NORMAL_RX_HEADROOM from 1K to 2K
//      - major rework of sensor handling
//      - major rework of motionQ_addCommand relatively to blocked moves (abs, rel, etc)
//      - revamped M780/PO position reporting
//      - added more control to M719 to allow XYZ, tiem, etc to be printed along with status reporting
//      - changed M791 and friedns (M710) to use reriod instead of rate
//////////RELEASED 2019/11/20
// 4.004b
//      - fixed bug in check for blocked absolute motion
//      - added more error messages for when motion is attempted during different blocked conditions
//      - add JOGGING speed (set with M234) and added a G0.1 move to to a RELATIVE move at the jogging rate
//        laying groundwork for smoother motion with the job wheel
//////////RELEASED 2019/11/21
// 4.004c
//      - added Gxx code for cylindrical surface build using a rotary axis
//      - improved M235
//      - fixed bug in G928 last release force it to be an incremental move, but failed to set the Q_LastRequestedPositionInUnits variable.
//        (prior code assumed it was operating in absulute mode, even though G91 could have been in effect).
//      - fix bug in Mcode/Gcode generic error reporting methods... they were relying on _errorStr, which should
//        not have been the case as the calling routine may have also used _errorStr. changed to a local string.
//////////RELEASED 2019/11/26
// 4.004d
//      - expanded and renamed the cylinder move to karl's choice of G702 (CW) and G703 (CCW)
//      - added argC to M797 for a submask (_sendingGBStringsSubMask)
//      - changed ROTARY code to allow infinite distance, but keep view of position to code/world as 0 to 360
//      - changed clamp and warn code to check rotary if MAX_TRAVEL is not 0
//      - fix bug in M6 that would have screwed up the position if a tool change had occurred during a G91 mode (incremental)
//      - fix bug with 30M version that references FAULT_SENSOR.
//      - initial code to re-instate CAN_EVENT_MANUAL_Z_MOVE control from hotbeds
//////////RELEASED 2019/12/01
// 4.004e
//      - fix bug in unitVector assignment in motionQ_addCommand for ROTARY that was causing a speed limit error
//      - adding separate mechanism for jogging.  relies on recently added G0.1 and Jogging rate and CAN_EVENT_MANUAL_Z_MOVE.
//      - fix typo in M719 for setting which axis to report (had an X in one place that should have been a Y)
//      - added argP to M785 to allow controlling the period for updates of the manual switch on the head.
//      - added M224/M225/M226/M796 to facilitate new jogging capability
//      - changed acceleration calc for coordinated moves to just calc next move time based on accel/decel rather than trying
//        to limit change to once per millisecond (effectively makes DominantAxis timer a one shot when accelerating/deceleration
//        and a constant interval timer when at cruise speed.   removed SpeedControl();
//      - fixed long existing bug that would lock up the motion controller.  occurred in the uart ISRs.... if an overrun was detected
//        (UARTx->SR.ORE_FLAG set).  to clear it, a read of SR followed by a read of DR was needed.  the DR read was not in the code, so
//        stuck in a loop of servicing the ISR for uart over and over...
//      - misc rotary cleanup
//////////RELEASED 2019/12/08
// 4.004f
//      - change EMO released message from an ERROR to INFO
//      - increased wait for high voltage to 3 seconds
//      - fixed bug in accel code ... 4.004e moved next accel calc to bottom of TIM1 ISR, which caused a delay in setting up the timer for
//        the next TIM1 pulse.   restored call to the top of the TIM1 ISR, but kept the change for the CALC of the next timer values that
//        the bottom to greatly speed up the time to get the timer set up for the next pulse
//      - created UnitsPerPulse value in each motor structure and got rid of ALL divides of PulsesPerUnit and replace with mult of UnitsPerPulse
//        (each replacement saves 13 cycles).... several of which were in time critical places
//      - fix bug in cylinder 90 degree (perpendicular case ... perpOfs move did not occur)
////////////RELEASED 2019/12/10
// 4.004g
//      - reduced wait for high voltage after emo released to 1 second.   Z_STEP issue resolved with added 10K pullup on board, so this should be ok.
//      - gave M718 new life as a sync mechanism for repetrel
//      - change 'a' to 'V' for actual vector velocity.
////////////RELEASED 2019/12/12
// 4.004h
//      - redo M719 and M780 reporting (changes for F, E, V, and adding Line number reporting)
////////////RELEASED 2019/12/12
// 4.004i
//      - added more debug info to error report if E rate exceeds dominant axis rate.
//      - tweaked ISR priority for "probe" commands
//      - fix bug where the outbox canbusFormat was not set to CANBUS_FORMAT_V1 by default for all aliases
//      - fixed issue with using checksum for "urgent" commands (the urgent char was part of repetrel checksum, but was stripped off
//        before the serial processors calculated the checksum
//      - changed catastrophic failure for active head being lost to only reset if active head lost and Que's not empty
//      - reduced head comm watchdog from 15 to 10 seconds
//      - added code to allow users to select Tx mapping for standalone Tx command AND mapping for Tx arguments on mcodes -- ifdef'd OUT
//        (code is not tested -- ON HOLD PENDING DECISION FROM KARL)
////////////RELEASED 2020/01/08
// 4.004j
//      - move call to NVIC_PriorityGroupConfig() in main() up to prior to all the hw init calls to get around a bug in the st libs
//        for setting the interrupt priority
//      - change USB code to no longer change the split the preemptive/sub priority bits diff from the programs selection (was bad form
//        of the USB driver to do this)
////////////RELEASED 2020/01/22
// 4.004k
//      - moved irq disable/enable code in to inline function calls to ensure uniform code for all off/on and to allow optional
//        debug code to be uniformly added
//      - tweaked print format for SendCurrentMcodeExecutionNotice() to use %d instead of %3d, etc
//      - moved UARTs to Preemption Priority from 1 to 0 and IWDG from 0 to 1 when checking xtal speed
//      - revamp GB_DEBUG_PINs to use newly wired PANEL interface
//      - fix bug in NVIC_Init that did not handle all the legal states of the SCB->AIRCR reg (including it's default reset state!).  this
//        was the root cause of Serial Overrun errors, as the UART did not have highest priority as intended
//      - changed way deferred commands are processed.  now instead of immediately processing all deferred linked to a just-finished move
//        in processMotion, they are processed once per call to SequenceEngine() (NEW_DEFERRED)
//      - changed way the next move is called after the last pulse is issued for a move.  instead of in processMotion, it is called in
//        in SequenceEngine() (NEW_DEFERRED)
//      - started adding code to support scripting (ALLOW_GCODE_SCRIPTS)
//      - started inserting code for AB-select encoder (NEW_4_LAYER_PCB)
//      - added check for a gcode arg with just a letter and no number.
//      - fixed bug in setting up start speed for moves that "prime" .... was not staying at noRamp speed and could jump off too fast
//      - removed some very old "NUKE" code and many unused sections of #ifdef'd out debug code
//      - added compile time code option (MEASURE_TIME_SLIPPAGE) to measure real time vs systck time to see if there is any time slippage
//        in the systick control loop (slices taking too long, etc)
//      - added call to XXXXX in Timer init routines to limit interrupt source to over/underflow and DMA
//      - some more cleanup of crufty pin defs for DEBUG and compatibility between build targets (MEASURE_TIME_SLIPPAGE)
////////////RELEASED 2020/01/24
// 4.100a
//      - rebranded 4.004k to signify semi-major release (improved serial port comm)
////////////RELEASED 2020/01/24
// 4.100b
//      - undo part of the NEW_DEFERRED.  instead of delaying move end to next move to a call to commandProcessor from ProcessMotion
//        revert to pre-4.004k behavior of just immediately starting the next move.  however, still retain the change in 4.004k of
//        pushing deferred mcode processing through commandProcessor
////////////RELEASED 2020/01/25
// 4.100c
//      - enabled sw reset of all heads if comm with repetrel (or any host) is lost for than 5 minutes)
//      - changed a few of the messages that occur during an abort from sendError() to sendInfo()
//      - added 2 routines to convert from toolNumber to device and vice versa
//      - slight tweak to _gs._errorCount (error throttling)... still limits to once a second when bursting, but if no errors for a while
//        will allow more than one error
//      - split NEW_4_LAYER_PCB into two ifdefs (USE_HYDRA_IO):  USE_AB_ENCODER and USE_6_TO_ONE_SELECT
//      - making USE_AB_ENCODER the default  -- WARNING -- this moves the CO2 direct laser control from TIM5/PA1 to TO TIM2/PA3
//      - added code to throttle speed based on total time needed to service the ISR routines for motion (LIMIT_SPEED_DUE_TO_ISR_LIMITS)
//      - reworked some of the I/O routines to add a path for "fast" I/O access (GPIOx and bit mask are stored in ram at init time)
//        used primarily for the STEP/DIR, sensors, and HSS (and debug pins).  saves close to 0.5usec per I/O access (USE_FAST_IO)
//      - removed all min/max related macros.  found issue if an arg to the min/max was a calculation, the calc was repeated multiple
//        times (once for the "if" and once for the "assign").  replaced all with corresponding math func calls (fminf/fmaxf) or user
//        create imin/minx and iFitWithinRange, fFitWithinRangth.  In one example, a range check in the accel calc resulted in the
//        sqrtf function being called 4 times instead of just once.
//      - reinstated balanced math calls in TIM1 to minimize jitter of the dom axis pulse (saves about 2usec of jitter) (BALANCED_TIME)
//      - simplified the arr/psc calc in several routines (NEW_TIMER_ARR_PSC_CALC)
//      - reordered ISR priority to accomodate using TIM7 as part of the motion timers.  changed priority assignments to a set
//        of #defines to allow easier tweaking in the future
//      - moved accel/timer calc for Dominant timer (TIM1) ouuside of the TIM1 ISR to a lower priority ISR (using TIM7 to kick
//        off calc....  this removes some jitter in the step positioning (USE_TIM7_FOR_ACCEL_ISR)
//      - changed default value for CentripetalAccelRadius from 0.02 to 0.005 (user changeable with M222)
//      - added compiler option  -ffast-math
//      - added compiler option: -no-strict-aliasing
//      - added replacement for sqrtf() -- fpu_sqrtf() that takes advantage of the FPU's built in 32-bit sqrt.f32 function (14 cycles)
//        vs 336 cycles in the software math.o reoutine for sqrtf.  (tried a bunch of things to get the compiler/lib to use the
//        FPU instruction to no avail. (USE_FPU_BASED_SQRTF)
//      - started  native Lightburn mode.    (to enable:   power-on or HW reset + "run" button held in for 5 seconds)
//        must compile with ALLOW_NATIVE_LIGHTBURN.   changes to code in the mode include:
//          - per line ack is "ok\n"
//          - M106 Sx to set vector power {auto convert to M621)
//          - all G1's have an implied E1 (auto add E1)
//          - some G0's have argF=0 (auto remove arg F)
//          - M620 has to be auto inserted for CO2???? (Use one of the 6 macros for this)
//          - disabled all sendInfo/etc only directed msgs (sendstring) and sendErr messages will go out
//        enabled under GB_DEBUGGING for now (#define ALLOW_NATIVE_LIGHTBURN)
//      - modifed code to fully pre-load the can packet for generating a can step pulse in StartMove rather than modifying for device/dir
//        in ProcessMotion  (PRELOAD_CAN_STEP_PACKET)
//      - modified code to preload laser device in pre canned laser canbus packet (PRELOAD_LASER_PACKET)
//      - added pointers for first and last motors involved in a move to reduce processing time in the TIM1 isr (shorten for loop)
//        (FirstAxisMotorPtrInvolvedInMove and LastAxisMotorPtrInvolvedInMove).  update in motionQ_exectuteMOve() and joggingUpdatePulses()
//      - increased debounce mask on "Fault" sensor to try to cut down on spurious triggers when EMO is released (and not monitoring EMO)
//        downside is greater time to detect an actual fault
//      - cleaned up the code for keeping the homeSensor state up to date when not homing
////////////RELEASED 2020/02/02
// 4.100d
//      - added more motorStructure variables to the reset list in initGCodeSequenceEngine()
//      - modified printout for GB_STRING_FLOW to aid debug of flakey "slow motion" issue
////////////RELEASED 2020/02/05
// 4.100e
//      - swapped out FirstAxisMotorPtrInvolvedInMove/LastAxisMotorPtrInvolvedInMove for an array of motor pointers involved in the move
//        which improves upon the prior method as only moving axis are in the list (say MY and MC, where as the prior would have still had
//        all but MX.  s_movingAxesPtrs and _numMovingAxes.
//      - made USE_FPU_BASED_SQRTF permanent and replace ALL sqrtf usage in the codebase (instead of just inside of calcVelocity() method)
//      - added sendstringCr(">ER:  0: Motion Error"); in front of sending a motion error as Repetrel was not turning on the Error flag with
//        the normal motion error message
//      - added Direction bit to "USE_FAST_IO" list
//      - removed restriction on axis C to have fewer pulses than the dominant axis.
//      - added to isr throttling to include M_C when using canbus step -- both for step count AND for canbus utilization (limited to 75% usage)
//      - scrubbed motionQ_execute() to minimize time spent in this routine (critical timing for inter move timing.  pushed all (non-head-based)
//        flow scaling to motionQ_addCommand() (non-real-time).
//      - changed INKJET code to allow use of M_C for sdrop by drop control via can to truly match motion (with M229 to enable) instead of just
//        setting a rate on the head (should provide for better cornering)
//      - removed (made permanent): USE_TIM7_FOR_ACCEL_ISR, NEW_TIMER_ARR_PSC_CALC, LIMIT_SPEED_DUE_TO_ISR_LIMITS, PRELOAD_CAN_STEP_PACKET,
//        PRELOAD_LASER_PACKET, USE_FAST_IO
//      - added M716, M717 for controlling data logging on the aux serial port
//      - fixed bug affecting backdoor Zjog and lathe modes.   error in timer calc introduced with NEW_TIMER_ARR_PSC_CALC in in 4.100c
//      - added USE_NEW_SOAPSTRING_DELIMTER_AND_STRIP_COMMENTS but left turned off.   enable to change soapstring delimeter from ';'
//        to another char ('?') and then auto strip ALL comments before hitting the rx buffer.
//      - move called isAutoPrimeoOrUnprimeNeeded later in motionQ_AddCommand. durng code opt, it inadvertantly was moved ahead of
//        the point in which the moveTime was known (and it relies on move time)
//      - converted several common small motionQ status methods to inline macros (ie, motionQ_empty())
//      - added M219 to allow changing the baudrate of the UARTs
//      - added G2,2.G3,2 commands to be a better behaved version of G2.1/G3.1 (actually end at the spec'd XY ... unlike the kludge added in 4.001i
//        this allows for an inductor build in 3 lines of gcode with no Z lift.
////////////RELEASED 2020/02/10
// 4.100f
//      - in last release, moving isAutoPrimeoOrUnprimeNeeded() left hadAnE unset at the time it was checked for TurboMode.  Added code
//        to SetFlowInfo to set hadAnE, so now it's set before it's used
//      - added additional option to reversing in G2.1/G3.1 currently, R1 does an inward jump, then spirals out to the currnent position.   added R2
//        which goes from current position and works out from there
////////////RELEASED 2020/02/10
// 4.100g
//      - changed M632 (PnP commands) to not block motion unless a new arg, ARG_W==1
//      - modified NEW_DREFERRED as follows:
//          - no longer insert a break in motion (slow down/speed up) {and this did not unprime/prime, but did put a break in motion)
//          - next move is started immediately after prior move completes, rather than after deferred commands complete.
//          - the deferred commands are posted and will be serviced with priority with each subsequent all to SequenceEngine()
//      - change M221/756/757/758/230/231/232 to IMPACT_DESTINATION_CALC ... the result of these is used by motionQ_addCommand (had been used
//        in motionQ_execute() prior to Hyrda4.100e.   so this was an oversight to have left them as SYNCS_WITH_MOTION
//      - change M625/628/630 to SINGLE_STEP... these must complete before the next move starts, which can't be guaranteed with the
//        the NEW_DEFERRED path where the deferred mcodes are processed some time (1ms or so) after the next move starts (and therefore can not
//        apply to the flow calcs, probe arming, etc)
//      - change M233 to SINGLE_STEP. this had been incorrectly set to SYNCS_WITH_MOTION
//      - changed default value for CentripetalAccelRadius 0.010 (user changeable with M222) -- this had been 0.020 for all of time
//        except for 4.100c to now where it was dropped to 0.005
////////////RELEASED 2020/02/22
// 4.101a
//      - unify use of ARG_x in GCode.c (replaced legacy access via ExecutionPtr->x)
//      - remove unused _skipFinalArcMove variable (always FALSE) and associate unused code
//      - unified "common" with Medusa4 after adding SPI display support
//      - added spi display to Hydra with first few test screens
//      - added M246 to support display control of remote head and control local display
//      - added basic use of AB encoder to select display page
////////////RELEASED 2020/03/08
// 4.101b
//      - fix bug in 5th entry of CO2 laser heartbeat reporting (had >> 1 instead of >> 13)
//      - move change for motor direction lower in motionQ_execute to increase hold time relative to last step
//      = added two additonal options to M797 to allow booking of X steps after each layer.  (REMOVE WHEN FINISHED)
//      - added MOVE_DIRECTION_CHANGE to change where in motionQ_execute() the change of direction bits occur.  this is in an
//        attempt to increase hold time from the last step of the prior move.
////////////RELEASED 2020/03/24
// 4.101c
//      - made MOVE_DIRECTION_CHANGE from 4.101b permanent (removed #ifdefs).  change added enough hold time from  last step to dir change.
//      - removed debug code added in 4.101b for "X-shift" issue (added two additonal options to M797 to allow booking of X steps after each layer)
//      - made delayMs and delayUsec always exist and not just available when ADD_SPI_DISPLAY was defined
//      - added M73 to be compatible with Prusa Slic3r's time remaining and % complete report.  forwards info to repetrel and also sends a GB string
//      - added M627 to allow setting of a relative and absolute destination to occur on a job kill (much faster response than repetrel trying to
//        accomplish the same thing, which is handcuffed waiting for the full abort/reset sequence to finish
//      - change G38 to allow pin selection for the probe connection on the head
//      - change headSetup for PnP to not allow contact probe
//      - fix bug in GUI code for changing pages with the AB encoder.   accidently put the DrawPage call in a ISR based  routine instead of the foreground process
////////////ESCAPED FROM QUARANTINE - 2020/04/06
// 4.101d
//      - cleaned up the ability to seed a group/alias with the settings from a given head so that it is much easier to create a new group can then contain
//        a set of heads and still be able to individually talk to each head (no "master, so no worries about affecting other heads), while being able to
//        talk to all of them via the group identifier (51-59, 50 is all groups with any %x group).   to "copy" settings to a group, use M703 Tx Sx C1 (which
//        will copy physical head Tx's current settings to group Sx.
//      - update registration code to send out fake completion notices when a head registers to try to get the GUI to match reality (Repetrel really should
//        reset the gui for each device to "unused" when it sees the >RM notice
//      - added code throughout to better attempt to keep repetrel in sync.  still work to go (see Repetrel list below)
//      - changed SendCurrentMcodeExecutionNotice() to handle aliases for the device .... in cases where it's an alias, multiple notices are
//        sent, one for each head matching the alias.
//      - add option to M106 to set the Range of numbers in a non-persistent fashion.  this is meant to be used by repetrel, so the GUI
//        can always operation in 0-100 range, independent of the range set by the used with the persistent M106 Cxxx setting
////////////RELEASED - 2020/04/09
// 4.101e
//      - fix issue with shutting off GUI for manually running the extruder when starting a print job
////////////RELEASED - 2020/04/09
// 4.101f
//      - fixed bug where variables use by M627 should have been initialized to INVALID_ARG_VALUE instead of 0.0f
//      - fixed bug where _hijackAxisC was not reset to FALSE after a job kill
//      - force "USE_E_VALUES" related variables to "off" after an M30 (not persistant across jobs)
//        this has likely caused grief for a while for anyone mixing print jobs with and with using E values
//        and jobs that had no M229 would inherit the prior jobs state.  if it was a kill job between jobs,
//        the only part of state of the prior M229 was inherited (due to prior bug)
////////////RELEASED - 2020/04/10
// 4.101g
//      - re-sync "common" after changes to Medusa for the new 405 board.
//      - update key generator list to move away from 407 board to use the devebox mcudev board (4 made).  obsoleted prior key generators
////////////LIMITED RELEASED - 2020/04/27 (only released in new key generators
// 4.101h
//      - tweaked calc for "filament used" in M773 to use volumetric calc instead of linear off a guess of the hobbed diam.  makes assumption
//        for 1.75 fillament and that the head is programmed with volumetric pulses/unit
//      - no longer send Ex in the SendCurrentMcodeExecutionNotice() for an M620 [GUI will key off S]
//      - added SendCurrentMcodeExecutionNotice() to M678 (laser cross hair)
//      - update tryToCleanUpGuiAfterDeviceRegistration() for M678
//      - G28 - have Ix rapid move apply to all axis specified, not just those with home sensors
//      - G38 fix bug where feedrate for move (ARG_F) was ignored
//      - minor cleanup (mostly comments) for G2/G3 family
//      - fixed bug in G4 where Sarg was taken as an integer number of seconds only instead of float (ie, 3.5 seconds)
////////////RELEASED - 2020/05/02
// 4.200a
//      - cleanup before fork to 5.0 (remove NUKE, CAN_V0)
//      - remove NEW_DEFERRED
//      - re-expand tabs
//////////// RELEASED - 2020/05/03
// 4.200b
//      - add clone tracking for each registered device in order to know whether an different" head type is cloned to the active head (such as
//        a UV_LIGHT_RAY) and if so, to send controls (like watchdogs) to that device.
//        function updateCloneList()called in RETURN_DATA for USER_ALIAS list,
//        added code in CheckForNewFlowRate() to check in a UVATA is cloned to the current selected head and if so, send out a LaserControl packet
//      - setupHssPwm() was missing processing for ARG_P  (same processing from M619)
//      - modified M797 Ix output for showing state information
//      - redid tab expansion as some print strings ended up with tabs.
//      - output deasserted Step pin when polarity is set via M97
//      - output FORWARD direction on Dir pin when polarity is set via M94
//////////// RELEASED - 2020/05/08
// 4.200c (mimic a few things added to Hydra5.000a
//      - redid tab expansion as some print strings ended up with tabs.
//      - created M253/M254/M255 for lathe mode and put in "legacy" warning for M3/M4/M5 (warning in V5 only)
//      - cleaned up M773-M776, M779 reports to give a common look
//      - added check for I==1 to enable move to G28 intermediate location
//      - move M246 to M260 (gui)
//      - added M702 for setting up group (seeded from a physical device)
//////////// RELEASED - 2020/05/20
// 4.200d
//      - redid tab expansion
//////////// RELEASED - 2020/05/20
// 4.200e
//      - fixed bug in getMotionRateInUPS() which did not return the correct rate when in raster mode
//		- fixed bug in initiializing the JOGGING rate in motionQ_addCommand to MAX_FLOAT (was wrongly set to the rasterRate)
//		- fix issue where last segment in a spiral arc lost it's E value
//		- changed inkjet code to ensure at least one dot is output on small views (when dist * dots/mm would have been < 1)
//		- fixed M229 argP ... when it was dumbed down to not accept non-AUTO choices, broke the ability to turn it off. restored.
//		- make sure M723 only works with extruders to ensure to accidental turn on of laser/uvata heads
//		- added option to test using the AB encoder to track filament.... using M227 to set the non-jogging behavior of the encoder
//		  to either be GUI or free-running+reporting as T16 in the RT> report
//////////// RELEASED - 2020/07/28
// 4.200f
//      - change raster code to send raster value to laser on process of first step of the dot instead of while processing
//		  the last step of the prior dot (which had been done to try to cancel some of the canbus time).  not good for direct
//		  drive or for dealing with speed related variability with the bidir option
//		- minimized "extra" front porch pixels for raster (had padded with 10 dots ... way too many when running slow)
//		- flipped polarity on bidir adjust. negative now moves to 0
//		- increased max allowable rate for diode lasers to 30000
//////////// RELEASED - 2020/08/04
// 4.200g
//		- re-wrote usb_lib processing for raw chartio input.   now better behaved and is processed in a slice rather an in the usb_libs ISR.
//		- changed INKJET pwm rate to coincide with raster scan rate and image_dpmmX
//		- using CAN_MSG_STEP for inkjet raster processing since no grayscale exists for the inkjets (fixed dot size)
//////////// RELEASED - 2020/08/05
// 4.200h
//		- changed inkjet raster to only send can packet on "spew" packet instead of at dot rate.
//		- major rework of raster step process/ISR code.
//		- send inkjet raster "spew" at center subdot-step instead of start subdot-step
//		- added 100 ohm PRTD option for heads
//////////// RELEASED - 2020/08/14
// 4.200i
//		- enabled CCM SRAM for use with data and moved a bunch of data there to free up space in the main SRAM
//		- fixed warning on M5 checking for legacy use
//////////// RELEASED - 2020/10/05
// 4.200j
//		- added PNP REEL ADVANCE controls to M632
//////////// RELEASED - 2020/10/24
// 4.200k
//		- remove CCRAM ... linker issue ... builds a huge .bin that then fails to convert to a .dfu for the usb bootloader
//////////// RELEASED - 2020/11/04
// 4.200l
//		- merged in changes from "common" (changed hard coded delay countdown value in for flashing LEDs to a #def (from
//		  medusa inkjet change to show spewing ink in raster mode
//		- fix bug where DominantAxisPtr was not initialized at POR time and was inadvertently accessed in an
//		  unintended call to TIM7 ISR prior to when it would have normally been set to the correct axis.   This
//		  former was a mistake when setting things up for the CCRAM. The latter was the result of not checking
//		  a flag in the ISR.     THE RESULT OF THE BUGS was that the FLASH controller threw an error which was
//		  not cleared and resulted in blocking any soapstring writes (system soap, which included license keys)
//////////// RELEASED - 2020/12/07
// 4.200mz
//		- fixed case where lastRequestedQPoisition was set wrong if poistion has been clamped due to exceding print limits (V5-done)
//		- reset TurboModeDistance=MAXFLOAT after an M30 (V5-done)
//		- add check for (_MailBoxes._inbox[i].deviceFamily == DEVICE_FAMILY_HEATED_EXTRUDER)) in waitingForExtruderTemp check so it
//		  will not check for non-heater extruders (V5 TODO)
//		- initial pass at adding canMotor head type -- PERVASIVE change.
// 4.200nz
//		- fixed (along with medusa 4.050hz and is with L1/L2 state getting hosed across a job kill.
//		- tweaked M627 to clamp the relative move amounts to not exceed the printing volume (to avoid needless error message) (V5 TODO)
//////////// RELEASED - 2020/12/28
// 4.200oz
//		- putting in can_motor and new 405 based force feedback head into medusa project for real.
//		- reverting "force" control from mA back to % (M785 Cxxx is now pct 0 to 100)
//		- M787 now requires a C1 to calibrate and/or an F1 to restore factory defaults.  both can be issued at the same time if desired
//        no full release
// 4.201a
//		- cleanup for canMotor and new 405 board
//		- support NEW PCB list/order
//		- pass-thru "Debug" revision from head and display with showParams
//////////// RELEASED - 2021/01/09
// 4.201b
//		- remove remote HOME sensors option for CanMotors (now need #define USE_CAN_MOTOR_HOME_SENSOR)
//		- added extra device event so closed loop steppers can easily ping the MC during calibration
//////////// RELEASED - 2021/01/11
// 4.201c
//		- fixed bug in move for AbortRelativePosition that was introduced in 4.200nz
//		- set AbortRelativePosition/AbortAbsolutePosition to INVALID_ARG_VALUE after a job end or job kill
//////////// RELEASED - 2021/01/12
// 4.201d
//		- blocked canMotor update of sensor state in HydraCan.c (EVENT reporting) (forgot to remove this in 4.201b)
//		- fix bug adding in 4.200m which caused an illegal access to flash (tied to adding flags to the init struct for a head) for
//		  knowing if a head had a heater.   removed bad code that was inadvertently left in place (from original attempt to solve problem)
//		- added check for a FLASH controller error just prior to the soapstring erase ....   if prior error had occurred, it will send an
//		  error, then try to clear it so that the flash erase for the soap can proceed (it would fail otherwise).
//////////// RELEASED - 2021/01/12
// 4.202a
//		- modify the reporting for the "force" field for CanMotor and 405 Heads.
//		- adding holding torgue (min current) to closed loop steppers   *REQUIRES Medusa 4.052a or higher on CLS motors
//		- fixed bug with M627 (abort/job kill relative/absolute move) which was introduced in 4.201c when attempting to
//		  set the values to INVALID_ARG_VALUE after a job end or job kill .... which they were, except they were set to INVALID
//		  BEFORE the abort move was generated.   now they are set to INVALID after the abort move occurs OR with an M30
//		  added option #define RESET_ABORT_MOVE_ON_JOB_END for whether or not to INVALIDATE the abort move after and abort or M30
//		  currently not defined, so values will be persistent
//////////// RELEASED - 2021/01/18
// 4.202b
//		- added C8 option to M800 for experimental waveformGeneration mode on using the new 405 board.
//////////// RELEASED - 2021/01/21
// 4.202c
//		- changed M788 to no longer need a password.    also added two args:
//			argA --- if A==1, then perform a full reset of the CLS head
//			argP --- if P==1, then reset the current position to match the encoder position (resets error to 0, etc)
//////////// RELEASED - 2021/01/21
// 4.203a
//		- added E and F args to M785 to allow setting the autoCal and prediction modes for the TLE5012 in the CLS setup.
//		- added L arg to M785 to allow setting the angular error reporting limit for canAxisMotors
//		  WARNING!!!!  THE VALUES MUST BE SAVED TO FLASH AND THEN FULLLY RESTART THE CLS DEVICE
//		- one more revamp of M788 ... covers all levels of resets not for canAxisMotors
//		      MCODE M788 <"T" toolSelector> [F restoreFactoryDefaults] [D deviceReset] [P resetPosition] [C canReset]
//		- added G28.1 to locally home canAxisMotors either to the sensor or until the force limit is reached/
//		- added M789 for locally sending sideband step pulses to a specific canAxisMotor (similar to M868/M869 or
//		  sending in crtl char #11/#12, but NOT restricted to the Z axis.
//		- added M698 for filament dispenser control (AM2302)
//		- added M699 for filament dispenser control (HX711 calibration, tare, etc)
//		- changed G2.2 to allow full disk spiral in/out by allow center to be either the start or end point.
//		- fixed lastRequestedQPoisition change from 4.200mz.  inadvertanlty this was set to a reverse calc of the position
//		  rather than the user's requested position (often different do to one being at the resolution of the step grid).
//		- fixed bug introduced about 4.200g with per-dot flow control on inkjets
//		- fixed bug in error throttling for sendMotionError().... errorCnt was not incremented
//		- change M723 in two ways:  (1) if ARG_E exceeds 65535 it is clamped to 65535 (max supported) (2) added C1 option
//		  to force continuous extrude (30 second timeout still applies)
//		- added thread pitch control to G84/G84.1 (request from Karl)
//		- changed heartbeat for anything with closed loop stepper that is not a canAxisMotor to get an additional 4 values
//		- printed in the message to repetrel (forces, error, v12-voltage, v12-amperage
//		- in initFromSoapstring(), fixed countdown variable.... had been executing when count was non-zero, rather then on
//		  on the transition to zero.
//		- added a "wiggle" all Motor direction pins to work around a bug in the BTT V1 motors in that they need to see an
//		  edge transition to properly go the correct direction.  this is ONLY for their code and noy hyrel's code that
//		  runs on their hardware.
//		- changed two checked for the home sensor in Motordrivers.c from ==TRIPPED to !=OPEN ... in order to safely cover
//		  other possible cases (like UNKNOWN).
//		- using CCMRAM again via pointer access to get around Coocox CoFlash bug. ALL serial buffers are now in CCMRAM.
//      - RASTER: #define ALLOW_DIRECT_BUFFER_FOR_RASTER_DATA  removed all ifdefs, made permanent
//		- enables modifed M253/M254/M255 to work with canMotors.   the critical issue is M255 REQUIRES an axis arg IF trying
//		  to shut down a can axis motor
//		- added a check and "fix" of the FLASH->SR reg which will show illegal address access.  the error is "sticky" and
//		  reports the last slice that executed to help with tracking down issues.  by adding this, it will hopefully prevent
//		  cases were we fail to write the soapstring due to a prior error (if the FLASH->SR shows issues, erases and writes
//		  are blocked until the SR is cleared.
//		- major overhaul of the diplay and GUI code (currently if'defed out) as work is not complete.   matching new look and
//		  feel of the head code and far more code is now shared between the projects.
//		- merged a lot of code from medusa into util.c in the common folder
//		- added several new display pages for SPI_DISPLAY
//		- created new .o for master.o to separate v4 from v5 to support the link file change to get the CCMRAM working
//		- ported M784 from Hydra5 to provide a report of installed devices as part or the end of job metrics
//		- added a couple of new metrics....to show the "best case" print time had accel rate been infinite.  also shows
//		  the average print and non-print speeds in this ideal cases
//////////// RELEASED - 2021/03/15
// 4.203b
//      - cleanup a few unused variables and code improvements found while creating the print time calculator code for repetrel.
//////////// RELEASED - 2021/04/25 -------------
// 4.203c
//		- fixed bug for temperature report for chamber (4.203a revamped the reporting code based on head type to more cleanly support
//		  several new head types.   chamber temp was inadvertantly divided by 32)
//////////// RELEASED - 2021/07/07 -------------
////
//4.203D
//changed maximum temp for hotbed 100 to 120c