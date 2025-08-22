@echo off
chcp 65001 >nul
setlocal enabledelayedexpansion

REM =========================================
REM 配置
REM =========================================
set "PROJECT_ROOT=%~dp0"
set "PYTHON_BUILD_PROJ=%PROJECT_ROOT%kbe\src\lib\pythonBuild\pythonBuild.vcxproj"
set "SOLUTION_FILE=%PROJECT_ROOT%kbe\src\kbengine nex.sln"
set "CONFIG=Debug"
set "PLATFORM=x64"
set "LOG_FILE=%PROJECT_ROOT%build.log"

echo =========================================
echo KBEngine-Nex 构建脚本（自动检测 VS）
echo =========================================
echo 项目路径: %PROJECT_ROOT%
echo 编译配置: %CONFIG% ^| 平台: %PLATFORM%
echo 日志文件: %LOG_FILE%
echo.

REM =========================================
REM 1. 检测 VS 环境
REM =========================================
echo [检测] 正在查找 Visual Studio 环境...
set "VSWHERE_PATH=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist "%VSWHERE_PATH%" (
    echo [错误] 未找到 vswhere.exe，请确认已安装 Visual Studio 或 Build Tools
    pause
    exit /b 1
)



REM 提取 VS 安装路径（先存到临时变量，避免括号解析错误）
for /f "usebackq tokens=*" %%i in (`"%VSWHERE_PATH%" -latest -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do (
    set "TMP_VS_PATH=%%i"
)
set "VS_INSTALL_PATH=%TMP_VS_PATH%"

if not defined VS_INSTALL_PATH (
    echo [错误] 未找到安装了 C++ 工具集的 Visual Studio，请确认已安装 C++ 组件
    pause
    exit /b 1
)

echo [找到] Visual Studio 路径: %VS_INSTALL_PATH%



echo [找到] vcvarsall  路径: %VS_INSTALL_PATH%\VC\Auxiliary\Build\vcvarsall.bat





call "%VS_INSTALL_PATH%\VC\Auxiliary\Build\vcvarsall.bat" x64

if errorlevel 1 (
    echo [错误] 无法加载 Visual Studio 编译环境
    pause
    exit /b 1
)



REM =========================================
REM 2. 编译 pythonBuild.vcxproj
REM =========================================
echo.
echo [步骤 1] 编译 pythonBuild.vcxproj ...
echo 日志记录到 %LOG_FILE%
echo.
REM msbuild "%PYTHON_BUILD_PROJ%" /p:Configuration=%CONFIG% /p:Platform=%PLATFORM% >> "%LOG_FILE%" 2>&1
powershell -Command "msbuild '%PYTHON_BUILD_PROJ%' /p:Configuration=%CONFIG% /p:Platform=%PLATFORM% | Tee-Object -FilePath '%LOG_FILE%'"
if errorlevel 1 (
    echo.
    echo [错误] pythonBuild.vcxproj 编译失败，请检查 %LOG_FILE% 获取详细信息！
    pause
    exit /b 1
)

REM =========================================
REM 3. 编译 kbengine nex.sln
REM =========================================
echo.
echo [步骤 2] 编译 kbengine nex.sln ...
echo 日志记录到 %LOG_FILE%
echo.
REM msbuild "%SOLUTION_FILE%" /p:Configuration=%CONFIG% /p:Platform=%PLATFORM% >> "%LOG_FILE%" 2>&1
powershell -Command "msbuild '%SOLUTION_FILE%' /p:Configuration=%CONFIG% /p:Platform=Win64 /m | Tee-Object -FilePath '%LOG_FILE%'"

if errorlevel 1 (
    echo.
    echo [错误] kbengine nex.sln 编译失败，请检查 %LOG_FILE% 获取详细信息！
    pause
    exit /b 1
)

echo.
echo [成功] 全部编译完成！
pause
exit /b 0
