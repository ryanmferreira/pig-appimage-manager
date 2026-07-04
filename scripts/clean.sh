#!/usr/bin/env bash

echo -e "Cleaning build artifacts...\n"
rm -rf build/
rm -rf *ninja* .*ninja*

echo -e "Cleaning test application directory...\n"
rm -rf /home/ryanf/Programs/AppImages/