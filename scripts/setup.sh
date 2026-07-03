#!/usr/bin/env bash

set -e

echo "Generating build files with Premake...\n"
premake5 ninja

echo -e "Running ninja...\n"
ninja
