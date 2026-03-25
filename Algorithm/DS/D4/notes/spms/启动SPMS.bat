@echo off
REM SPMS 学生成绩管理系统 - 启动脚本
chcp 65001 > nul
echo.
echo ========================================
echo    学生成绩管理系统 (SPMS)
echo    Student Performance Management System
echo ========================================
echo.

REM 获取当前脚本所在目录
set "SCRIPT_DIR=%~dp0"
set "UI_FILE=%SCRIPT_DIR%ui.html"

REM 检查 ui.html 是否存在
if not exist "%UI_FILE%" (
    echo ❌ 错误：找不到 ui.html 文件
    echo 请确保 ui.html 在以下位置：%UI_FILE%
    pause
    exit /b 1
)

echo ✅ 正在启动用户界面...
echo.

REM 使用默认浏览器打开 html 文件
start "" "%UI_FILE%"

echo ✅ 界面已在浏览器中打开
echo.
echo 如果浏览器没有自动打开，请手动访问：
echo %UI_FILE%
echo.
pause
