# SPMS 学生成绩管理系统 - PowerShell 启动脚本

Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "  学生成绩管理系统 (SPMS)" -ForegroundColor Cyan
Write-Host "  Student Performance Management System" -ForegroundColor Cyan
Write-Host "========================================`n" -ForegroundColor Cyan

# 获取脚本所在目录
$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$uiFile = Join-Path $scriptDir "ui.html"

# 检查文件存在性
if (-not (Test-Path $uiFile)) {
    Write-Host "❌ 错误：找不到 ui.html 文件" -ForegroundColor Red
    Write-Host "请确保 ui.html 在以下位置：$uiFile" -ForegroundColor Red
    Read-Host "按 Enter 键退出"
    exit 1
}

Write-Host "✅ 正在启动用户界面..." -ForegroundColor Green
Write-Host ""

# 使用默认浏览器打开 html 文件
Start-Process -FilePath $uiFile

Write-Host "✅ 界面已在浏览器中打开" -ForegroundColor Green
Write-Host ""
Write-Host "如果浏览器没有自动打开，请手动访问：" -ForegroundColor Yellow
Write-Host "$uiFile" -ForegroundColor Yellow
Write-Host ""
Read-Host "按 Enter 键退出"
