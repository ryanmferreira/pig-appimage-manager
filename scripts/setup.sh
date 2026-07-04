#!/usr/bin/env bash

source "$(dirname "$0")/common.sh"

cd_project

for command in premake5 ninja; do
    command -v "$command" >/dev/null || die "$command not found"
done

info "Generating build files..."
premake5 ninja

info "Running ninja..."
ninja