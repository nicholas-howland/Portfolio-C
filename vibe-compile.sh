#!/usr/bin/env bash
set -euo pipefail

LIB_DIR="lib"
BIN_DIR="bin"
TEMPLATE="$LIB_DIR/00-template.c"
EDITOR_CMD="${VISUAL:-${EDITOR:-nano}}"
CC="${CC:-gcc}"
CFLAGS="${CFLAGS:--Wall -Wextra -O2}"

usage() {
  cat <<EOF
Usage:
  $0                Compile all C files in '$LIB_DIR' to '$BIN_DIR'
  $0 -n <name>      Create new source from template and then compile everything
  $0 -e <name>      Edit an existing source file and then compile everything

Notes:
- <name> may be with or without '.c'. The output binary is placed in '$BIN_DIR' with the same basename.
- The template must be at '$TEMPLATE'. It will be skipped during compilation.
EOF
}


ensure_dirs() {
  [[ -d "$LIB_DIR" ]] || { echo "Error: '$LIB_DIR' directory not found."; exit 1; }
  mkdir -p "$BIN_DIR"
}

normalize_name() {
  local name="$1"
  if [[ "$name" != *.c ]]; then
    name="${name}.c"
  fi
  printf "%s" "$name"
}

create_new() {
  local raw="$1"
  local name
  name="$(normalize_name "$raw")"
  [[ -f "$TEMPLATE" ]] || { echo "Error: Template not found at '$TEMPLATE'."; exit 1; }
  local dest="$LIB_DIR/$name"
  if [[ -e "$dest" ]]; then
    echo "Error: '$dest' already exists."
    exit 1
  fi
  cp "$TEMPLATE" "$dest"
  echo "Created '$dest' from template."
  "$EDITOR_CMD" "$dest" || true
}

edit_existing() {
  local raw="$1"
  local name
  name="$(normalize_name "$raw")"
  local dest="$LIB_DIR/$name"
  [[ -f "$dest" ]] || { echo "Error: '$dest' does not exist."; exit 1; }
  "$EDITOR_CMD" "$dest" || true
}

compile_file() {
  ensure_dirs
  shopt -s nullglob
  local compiled_any=0
  local name="$1"

  for src in "$LIB_DIR"/$name.c; do
    # Skip the template file if present
    if [[ "$(basename "$src")" == "00-template.c" ]]; then
      continue
    fi
    compiled_any=1
    local base
    base="$(basename "$src" .c)"
    local out="$BIN_DIR/$base"
    echo "Compiling: $src -> $out"
    # Add include/lib paths here if you need them (e.g., -Iinclude -Llib -lm)
    if ! $CC $CFLAGS "$src" -o "$out"; then
      echo "Compilation failed for $src"
      exit 1
    fi
  done
  if [[ $compiled_any -eq 0 ]]; then
    echo "No C source files found in '$LIB_DIR' (excluding template)."
  else
    echo "Done. Executing script..."
    $out
  fi
}

main() {
  if [[ $# -eq 0 ]]; then
    useage()
    echo "Please use the -n or -e options"
    exit 0
  fi

  if [[ $# -eq 2 && "$1" == "-n" ]]; then
    create_new "$2"
    compile_file "$2"
    exit 0
  fi

  if [[ $# -eq 2 && "$1" == "-e" ]]; then
    edit_existing "$2"
    compile_file "$2"
    exit 0
  fi

  usage
  exit 1
}

main "$@"
