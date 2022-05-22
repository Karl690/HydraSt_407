echo off

REM - call this .bat with three args:   <project name> <compile TARGET name> <project folder>

set project=%1
set target=%2
set folder=%3
set drive=%~d2%

IF "A"=="A" (
    echo project=%project%
    echo target=%target%
    echo folder=%folder%
    echo drive=%drive%
)

for /f "tokens=3" %%a in ('findstr "SOFTWARE_MAJOR_REVISION" %folder%\inc\main.h') do (
    set major=%%a
)

for /f "tokens=3" %%b in ('findstr "SOFTWARE_MINOR_REVISION" %folder%\inc\main.h') do (
    IF %%b LSS 1000 (
       set minor=%%b
    )
    IF %%b LSS 100 (
       set minor=0%%b
    )
    IF %%b LSS 10 (
       set minor=00%%b
    )
    IF %%b LSS 1 (
       set minor=000
    )
)

for /f "tokens=2,3" %%c in ('findstr SOFTWARE_TWEAK_REVISION %folder%\inc\main.h') do (
    IF "%%c"=="SOFTWARE_TWEAK_REVISION" (
        set tweak=%%d
    )
)

for /f "tokens=2,3" %%c in ('findstr SOFTWARE_DEBUG_REVISION %folder%\inc\main.h') do (
    IF "%%c"=="SOFTWARE_DEBUG_REVISION" (
        set debug=%%d
    )
)

set tweak=%tweak:'=%
set debug=%debug:'=%
set experimental=exp_

set installpath=C:\Repetrel\Bin\Firmware
set binpath=%folder%\%target%\Debug\bin

set i_binfile=%project%.bin
set i_elffile=%project%.elf
IF "%tweak%"=="z" (
    set o_dfufile=%experimental%%target%_%major%.%minor%%tweak%_%debug%.dfu
) ELSE (
    set o_dfufile=%target%_%major%.%minor%%tweak%.dfu
)
set o_txtfile=%target%_%major%.%minor%%tweak%.txt

%folder%\bin2dfu.exe --i %binpath%\%i_binfile% --a 0x08000000 --o %binpath%\%o_dfufile%
copy %binpath%\%o_dfufile% %installpath%\%o_dfufile%

set travelling=0
IF "%COOCOX_USER%"=="buchner" (
    IF %travelling%==1 (
        IF "%tweak%"=="z" (
        copy %binpath%\%o_dfufile% Y:\000GregsSandbox\firmware\%o_dfufile%
        ) ELSE (
        copy %binpath%\%o_dfufile% Y:\000GregsSandbox\firmware\%o_dfufile%
        REM copy %binpath%\%o_dfufile% Y:\repetrel\bin\firmware\%o_dfufile%
        )
    ) ELSE (
        copy %binpath%\%o_dfufile% M:\Greg\DROPBOX\%o_dfufile%
           REM "C:\Program Files (x86)\GNU Tools ARM Embedded\6 2017-q1-update\bin\arm-none-eabi-objdump.exe" -D %binpath%\%i_elffile% > %binpath%\%o_txtfile%
    )
)

