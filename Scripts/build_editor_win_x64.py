#!/usr/bin/python

# Builds and packages the editor. Make sure you have MSBuild
# installed and the path is valid.

# Usage: "build_editor_win_x64 $Configuration"
# Where: $Configuration - e.g. DebugRelease, Release

import os

msbuildPath = "C:\\Program Files (x86)\\MSBuild\\12.0\\Bin\\amd64"
configuration = 'DebugRelease' #sys.argv[1]
solutionPath = "..\\BansheeEngine.sln"

if not os.path.exists(msbuildPath):
    print("MSBuild path is not valid. Used path {0}: ".format(msbuildPath))
    exit;

os.environ["PATH"] += os.pathsep + msbuildPath
os.system("msbuild {0} /p:Configuration=DebugRelease;Platform=x64".format(solutionPath))
os.system("msbuild {0} /p:Configuration=Release;Platform=x64".format(solutionPath))
os.system("package_editor.py " + configuration)
