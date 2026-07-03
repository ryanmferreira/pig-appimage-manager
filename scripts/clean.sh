#!/usr/bin/env bash

echo -e "Cleaning build artifacts...\n"
ninja -t clean 2>/dev/null || rm -rf build/

echo -e "Cleaning test application directory...\n"
rm -rf /home/ryanf/Programs/AppImages/