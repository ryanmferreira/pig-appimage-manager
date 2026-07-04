#!/usr/bin/env bash

source "$(dirname "$0")/common.sh"

cd_project

PIG="$PROJECT_ROOT/build/Debug/x86_64/pig"
COPY_FILE="$HOME/Documents/Testing/DuckStation-x64.appimage"

[[ -x "$PIG" ]] || die "Executable not found: $PIG"
[[ -f "$COPY_FILE" ]] || die "File not found: $COPY_FILE"

info "Copying..."

"$PIG" copy "$COPY_FILE"