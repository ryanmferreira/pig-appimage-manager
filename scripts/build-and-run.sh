#!/usr/bin/env bash

source "$(dirname "$0")/common.sh"

info "Building project..."
"$SCRIPT_DIR/build.sh"

info "Running project..."
"$SCRIPT_DIR/run.sh"
