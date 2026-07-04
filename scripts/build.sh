#!/usr/bin/env bash

source "$(dirname "$0")/common.sh"

cd_project

APP_DIR="$HOME/Programs/AppImages"

info "Removing $APP_DIR..."
rm -rf -- "$APP_DIR"

info "Building..."
ninja