echo OFF
cls

REM nazev souboru, pripony vstupniho vystupniho a vzoroveho souboru
REM navratova hodnota programu, 
call:TestFunc fact_01  1
call:TestFunc fact_02  1
call:TestFunc fact_03  2
call:TestFunc fact_04  2
call:TestFunc fact_05  0
call:TestFunc fact_06  0
call:TestFunc fact_07  0



goto end




REM funkce pro test jednoho pripadu
:TestFunc

REM zjisteni vysledku na zaklade vstupu
cv_01_factorial.exe < %~1.in >%~1.out

REM test navratove hodnoty programu
if NOT %ERRORLEVEL% == %~2 echo Chybny return code %~1 %~2 je %ERRORLEVEL%

REM test vystupu
fc %~1.out %~1.res >x

if NOT %ERRORLEVEL%==0 echo Chybny vystup %~1

goto:eof




:end

echo on
pause