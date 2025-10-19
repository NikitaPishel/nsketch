#!/bin/bash
set -e  # Exit on any error

# Variables
TEX_DIR="./data/textures"
BUILD_DIR="./build/texEditor"

./devBuild.sh

# Delete old textures
mkdir -p "$TEX_DIR"
rm -f "$TEX_DIR"/*

"$BUILD_DIR"/textureBuildDark
"$BUILD_DIR"/textureBuildLight