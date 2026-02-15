#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: ./compile.sh <file.c>"
    exit 1
fi

# Nom de l'exécutable sans l'extension .c
output_name="${1%.c}"

gcc "$1" -o "$output_name" -Iinclude -Llib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11