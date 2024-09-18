#!/bin/bash

CNT=0

INPUT_DIR="pictures"
OUTPUT_DIR="tests"

mkdir -p $OUTPUT_DIR

for img in $INPUT_DIR/*.jpg; do
    echo "Converting $(basename $img) to PPM format."
    output="${OUTPUT_DIR}/test$(printf %02d $CNT).ppm"
    convert "$img" -resize 1024x1024 "$output"
    CNT=$((CNT + 1))
done