@echo off
rem # testcase v1.1(windows), Milos & Pety, 2015
rem # $Id: testcase.cmd 194 2016-02-16 14:39:18Z petyovsky $

rem # usage: ./testcase program_name test_file_name expected_exit_code

setlocal EnableDelayedExpansion
set argc=0
for %%i in (%*) do set /a argc+=1

if not %argc% == 3 (
	echo "%0: param_error: Bad number of parameters"
	echo "usage:"
	echo "    %0 <program_name> <testfile_name> <expected_exit_code>"
	exit /b 1
)
set program_name=%~1
set testfile_name=%~2
set expected_exit_code=%~3

rem # Execute tested program and generate outputfile retargeting stdout and stderr to the .stdout file
if not exist "%program_name%" (
	echo "%0: param_error: Cannot execute program: %program_name%"
	exit /b 2
)
if not exist "%testfile_name%.stdin" (
	echo "%0: param_error: Cannot found readable input file: %testfile_name%.stdin"
	exit /b 3
)
if not exist "%testfile_name%.stdout.ref" (
	if not exist "%testfile_name%.stderr.ref" (
		echo "%0: internal_error: Cannot found reference file: %testfile_name%.stdout.ref or %testfile_name%.stderr.ref"
		exit /b 4
	)
)

"%program_name%" < "%testfile_name%.stdin" >"%testfile_name%.stdout" 2>"%testfile_name%.stderr"

set program_exit_code=%errorlevel%

rem # Executed program exit code test
if not %program_exit_code% == %expected_exit_code% (
	echo "%0: test_error: Program: %program_name% <%testfile_name%.stdin exit value:(%program_exit_code%), expected value:(%expected_exit_code%)"
	exit /b 5
)

rem # Executed program stderr file test
if exist "%testfile_name%.stderr.ref" (
	if not exist "%testfile_name%.stderr" (
		echo "%0: test_error: Cannot found file: %testfile_name%.stderr"
		exit /b 6
	)
	fc "%testfile_name%.stderr" "%testfile_name%.stderr.ref" >NUL 2>&1
	set fc_stderr_exit_code=!errorlevel!
	if !fc_stderr_exit_code! == 0 (
		rem # echo "%0: message: Testcase for stderr passed. Cool. ;-)"
		del /f "%testfile_name%.stderr"
	) else (
		if !fc_stderr_exit_code! == 1 (
			echo "%0: test_error: Files: %testfile_name%.stderr and %testfile_name%.stderr.ref differ"
			exit /b 7
		) else (
			echo "%0: internal_error: There is something wrong with the fc command and files: %testfile_name%.stderr and %testfile_name%.stderr.ref"
			exit /b 8
		)
	)
)

rem # Executed program stdout file test
if exist "%testfile_name%.stdout.ref" (
	if not exist "%testfile_name%.stdout" (
		echo "%0: test_error: Cannot found file: %testfile_name%.stdout"
		exit /b 9
	)
	fc "%testfile_name%.stdout" "%testfile_name%.stdout.ref" >NUL 2>&1
	set fc_stdout_exit_code=!errorlevel!
	if !fc_stdout_exit_code! == 0 (
		rem # echo "%0: message: Testcase for stdout passed. Cool. ;-)"
		if exist "%testfile_name%.stderr" del /f "%testfile_name%.stderr"
		del /f "%testfile_name%.stdout"
	) else (
		if !fc_stdout_exit_code! == 1 (
			echo "%0: test_error: Files: %testfile_name%.stdout and %testfile_name%.stdout.ref differ"
			exit /b 10
		) else (
			echo "%0: internal_error: There is something wrong with the fc command and files: %testfile_name%.stdout and %testfile_name%.stdout.ref"
			exit /b 11
		)
	)
)

exit /b 0
