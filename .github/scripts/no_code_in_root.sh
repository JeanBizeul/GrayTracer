#!/usr/bin/env bash

if ls *.hpp 1> /dev/null 2>&1 || ls *.cpp 1> /dev/null 2>&1; then
    echo "::error title=Source code found in root directory!::"
    exit 1
fi