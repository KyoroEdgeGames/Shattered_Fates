This repository contains a tool to remove large auto-generated Unreal/IDE folders to reduce file count and repo size.

Usage:
- From repository root run: `powershell.exe -ExecutionPolicy Bypass -File .\scripts\cleanup_workspace.ps1`
- To also remove the folders from git tracking (will stage deletions) use: `powershell.exe -ExecutionPolicy Bypass -File .\scripts\cleanup_workspace.ps1 -RemoveFromGit`

Which folders are removed by default:
- Binaries
- Build
- DerivedDataCache
- Intermediate
- Saved
- .vs
- .idea
- .vscode
- .gradle

Note: The script deletes files. Make a backup if unsure.
