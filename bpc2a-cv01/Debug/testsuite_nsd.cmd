@echo off
rem # testsuite_nsd v1.1(windows), Milos & Pety, 2015
rem # $Id: testsuite_nsd.cmd 194 2016-02-16 14:39:18Z petyovsky $

rem cls

rem # Nazev souboru, pripony vstupniho vystupniho a vzoroveho souboru
rem # Navratova hodnota programu,
call ./testcase ./mainsd.exe delitel_05 2
rem if not "%errorlevel%" == "0" echo "Chyba"
call ./testcase ./mainsd.exe delitel_04 1
call ./testcase ./mainsd.exe delitel_01 0
call ./testcase ./mainsd.exe delitel_02 0
call ./testcase ./mainsd.exe delitel_03 0
