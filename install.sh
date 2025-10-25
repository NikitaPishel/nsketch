#!/bin/bash
set -e  # Exit on any error

# Variables
EXECUTABLE="nsketch"

BUILD_DIR="./build"
SOURCE_DIR="."

PROJECT_DIR="$HOME/.nsketch"
EXE_PATH="$PROJECT_DIR/$EXECUTABLE"
BASHRC="$HOME/.bashrc"

PATH_LINE="export PATH=\"$PROJECT_DIR:\$PATH\""
ALIAS_LINE="alias $EXECUTABLE=$EXE_PATH"

BUILD_TESTS="${TESTS:-OFF}"

# Create build directory if it doesn't exist
mkdir -p "$BUILD_DIR"

# Configure CMake and build the project
cmake -B "$BUILD_DIR" -S "$SOURCE_DIR" -DNSK_BUILD_TESTS=$BUILD_TESTS
cmake --build "$BUILD_DIR"
sudo cmake --install "$BUILD_DIR"

find "$SOURCE_DIR/data/textures" -type f -delete 2>/dev/null || true

"$BUILD_DIR"/texEditor/textureBuildDark
"$BUILD_DIR"/texEditor/textureBuildLight

# Check if project dir already exists
if [ ! -d "$PROJECT_DIR" ]; then
    mkdir "$PROJECT_DIR"
    echo "Created installation directory: $PROJECT_DIR"
fi

cp -fr "$BUILD_DIR/$EXECUTABLE" "$PROJECT_DIR"
cp -fr ./data "$PROJECT_DIR"

# Check if there's path modification
if grep -q "$PROJECT_DIR" "$BASHRC"; then
    echo "PATH modification for $EXECUTABLE already exists in $BASHRC."
else
    # Append the PATH line to .bashrc
    echo "" >> "$BASHRC"
    echo "# --- Custom PATH added for $EXECUTABLE ---" >> "$BASHRC"
    echo "$PATH_LINE" >> "$BASHRC"
    echo "Added PATH modification for $PROJECT_DIR to $BASHRC."
fi

# Check if the alias is ALREADY in .bashrc
if grep -q "$EXECUTABLE" "$BASHRC"; then
    echo "Alias '$EXECUTABLE' already exists in $BASHRC."
else
    # Append the alias to .bashrc
    echo "" >> "$BASHRC"
    echo "# --- Custom Alias added for $EXECUTABLE ---" >> "$BASHRC"
    echo "$ALIAS_LINE" >> "$BASHRC"
    echo "Added alias '$EXECUTABLE' to $BASHRC."
fi

echo ""
echo "Configuration complete."
echo "Please open a new terminal or run 'source $BASHRC' manually to apply changes instantly."