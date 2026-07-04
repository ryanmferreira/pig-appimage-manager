#!/usr/bin/env bash

source "$(dirname "$0")/common.sh"

info "Cleaning build artifacts..."

for file in build build.ninja .ninja_log .ninja_deps; do
    rm -rf -- "$file"
done

info "Cleaning test application directory..."
rm -rf -- "$HOME/Programs/AppImages"