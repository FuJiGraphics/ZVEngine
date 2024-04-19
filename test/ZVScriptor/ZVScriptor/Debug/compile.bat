@echo off
REM 이 스크립트는 g++를 사용하여 사용자가 지정한 파일을 컴파일하고 DLL 파일을 생성합니다.

REM 입력된 인자가 있는지 확인
if "%~1"=="" (
    echo 파일 이름이 지정되지 않았습니다.
    exit /b 1
)

REM 사용자가 지정한 파일 이름을 변수에 저장
set FILENAME=%~1

REM MinGW의 bin 폴더 경로 설정
set MINGW_PATH=..\Vendor\mingw\bin

REM 컴파일러 명령 설정
set COMPILER=%MINGW_PATH%\g++

REM 컴파일 옵션 설정
set COMPILE_OPTIONS=-c

REM 컴파일 및 링크 옵션 설정
set LINK_OPTIONS=-shared -lstdc++ -o %FILENAME%.dll %FILENAME%.cpp -Wl,--output-def,%FILENAME%.def,--out-implib,%FILENAME%.a

REM 컴파일러 호출
%COMPILER% %COMPILE_OPTIONS% %FILENAME%.cpp

REM DLL 생성
%COMPILER% %LINK_OPTIONS%

pause