# Shattered Fates - Setup Script
# This script helps set up the development environment

Write-Host "=== Shattered Fates Development Setup ===" -ForegroundColor Cyan
Write-Host ""

# Check for Unreal Engine
Write-Host "Checking for Unreal Engine 5.7..." -ForegroundColor Yellow
$UEPath = "C:\Program Files\Epic Games\UE_5.7"
if (Test-Path $UEPath) {
    Write-Host "? Unreal Engine 5.7 found" -ForegroundColor Green
} else {
    Write-Host "? Unreal Engine 5.7 not found at $UEPath" -ForegroundColor Red
    Write-Host "  Please install Unreal Engine 5.7 from Epic Games Launcher" -ForegroundColor Yellow
    exit 1
}

# Check for Visual Studio
Write-Host "Checking for Visual Studio..." -ForegroundColor Yellow
$VSWherePath = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
if (Test-Path $VSWherePath) {
    $VSPath = & $VSWherePath -latest -property installationPath
    if ($VSPath) {
        Write-Host "? Visual Studio found at $VSPath" -ForegroundColor Green
    }
} else {
    Write-Host "? Visual Studio not found" -ForegroundColor Red
    Write-Host "  Please install Visual Studio 2022 with C++ development tools" -ForegroundColor Yellow
    exit 1
}

# Check for Git
Write-Host "Checking for Git..." -ForegroundColor Yellow
$GitPath = Get-Command git -ErrorAction SilentlyContinue
if ($GitPath) {
    Write-Host "? Git found" -ForegroundColor Green
} else {
    Write-Host "? Git not found" -ForegroundColor Red
    Write-Host "  Please install Git from https://git-scm.com/" -ForegroundColor Yellow
    exit 1
}

Write-Host ""
Write-Host "=== Generating Project Files ===" -ForegroundColor Cyan

# Generate project files
$ProjectFile = "Shattered_Fates.uproject"
if (Test-Path $ProjectFile) {
    Write-Host "Generating Visual Studio project files..." -ForegroundColor Yellow
    
    $UBTPath = "$UEPath\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe"
    if (Test-Path $UBTPath) {
        & $UBTPath -projectfiles -project="$PWD\$ProjectFile" -game -rocket -progress
        
        if ($LASTEXITCODE -eq 0) {
            Write-Host "? Project files generated successfully" -ForegroundColor Green
        } else {
            Write-Host "? Failed to generate project files" -ForegroundColor Red
            exit 1
        }
    } else {
        Write-Host "? UnrealBuildTool not found" -ForegroundColor Red
        exit 1
    }
} else {
    Write-Host "? Project file not found: $ProjectFile" -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "=== Configuring Git ===" -ForegroundColor Cyan

# Setup Git LFS if available
$GitLFS = Get-Command git-lfs -ErrorAction SilentlyContinue
if ($GitLFS) {
    Write-Host "Setting up Git LFS..." -ForegroundColor Yellow
    git lfs install
    Write-Host "? Git LFS configured" -ForegroundColor Green
} else {
    Write-Host "? Git LFS not found (optional but recommended)" -ForegroundColor Yellow
    Write-Host "  Install from https://git-lfs.github.com/" -ForegroundColor Yellow
}

# Check if in a git repository
if (Test-Path ".git") {
    Write-Host "? Git repository detected" -ForegroundColor Green
} else {
    Write-Host "? Not a git repository" -ForegroundColor Yellow
    Write-Host "  Run 'git init' to initialize a repository" -ForegroundColor Yellow
}

Write-Host ""
Write-Host "=== Checking Game Configuration ===" -ForegroundColor Cyan

# Check DefaultEngine.ini
$EngineIni = "Config\DefaultEngine.ini"
if (Test-Path $EngineIni) {
    $IniContent = Get-Content $EngineIni -Raw
    if ($IniContent -match "GameInstanceClass=/Script/Shattered_Fates.ShatteredFatesGameInstance") {
        Write-Host "? GameInstance configured correctly" -ForegroundColor Green
    } else {
        Write-Host "? GameInstance not configured" -ForegroundColor Yellow
        Write-Host "  Add this to $EngineIni under [/Script/EngineSettings.GameMapsSettings]:" -ForegroundColor Yellow
        Write-Host "  GameInstanceClass=/Script/Shattered_Fates.ShatteredFatesGameInstance" -ForegroundColor White
    }
} else {
    Write-Host "? DefaultEngine.ini not found" -ForegroundColor Yellow
}

Write-Host ""
Write-Host "=== Setup Complete! ===" -ForegroundColor Green
Write-Host ""
Write-Host "Next Steps:" -ForegroundColor Cyan
Write-Host "1. Open Shattered_Fates.sln in Visual Studio" -ForegroundColor White
Write-Host "2. Build the solution (Ctrl+Shift+B)" -ForegroundColor White
Write-Host "3. Open Shattered_Fates.uproject in Unreal Editor" -ForegroundColor White
Write-Host "4. Read 5_MINUTE_QUICK_START.md for setup instructions" -ForegroundColor White
Write-Host ""
Write-Host "Documentation:" -ForegroundColor Cyan
Write-Host "- README.md - Project overview" -ForegroundColor White
Write-Host "- 5_MINUTE_QUICK_START.md - Quick start guide" -ForegroundColor White
Write-Host "- CONTROLS_GUIDE.md - Controls reference" -ForegroundColor White
Write-Host "- CONTRIBUTING.md - How to contribute" -ForegroundColor White
Write-Host ""
Write-Host "Happy coding! ??" -ForegroundColor Magenta
