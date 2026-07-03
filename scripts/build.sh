#!/usr/bin/env bash

echo -e "Removing folder /home/ryanf/Programs/AppImages/...\n"
rm -rf /home/ryanf/Programs/AppImages/

echo -e "Running ninja...\n"
ninja
