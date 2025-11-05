@echo off
setlocal
REM === FMAT repo cleaner & .gitignore setup ===
REM Run this file in the repository root.

REM 0) move to script's folder
cd /d "%~dp0"

REM 1) sanity checks
git rev-parse --is-inside-work-tree >nul 2>&1
if errorlevel 1 (
  echo [ERROR] このフォルダは Git リポジトリではありません。.git フォルダ直下で実行してください。
  pause
  exit /b 1
)

echo:
echo [1/4] .gitignore を作成/更新します…

REM 2) write .gitignore (backup old if exists)
if exist ".gitignore" (
  copy /y ".gitignore" ".gitignore.bak" >nul
  echo   既存の .gitignore を .gitignore.bak にバックアップしました。
)

> ".gitignore" (
  echo # ===== Visual Studio build folders =====
  echo Debug/
  echo Release/
  echo x64/
  echo x86/
  echo ipch/
  echo obj/
  echo
  echo # ===== Visual Studio generated files =====
  echo .vs/
  echo *.VC.db
  echo *.VC.opendb
  echo *.suo
  echo *.user
  echo *.ipch
  echo *.log
  echo
  echo # ===== Misc temp/backup =====
  echo *.bak
  echo *.tmp
  echo
  echo # ===== Resource intermediates =====
  echo *.aps
)

REM 3) remove local build junk (working tree only; sourceは消しません)
echo:
echo [2/4] ローカルのビルド生成物を削除します（ソースは削除しません）…
for %%D in ("Debug" "Release" "x64" "x86" "ipch" "obj" ".vs") do (
  if exist "%%D" (
    echo   removing "%%D" ...
    rmdir /s /q "%%D"
  )
)
