#!/bin/bash

APP="./../quadtree"
INPUT_DIR="./tests"
OUTPUT_DIR="./results"
LOG_FILE="benchmark.txt"

mkdir -p $OUTPUT_DIR

cd ../ && make build
cd benchmark/

rm results/*
# rm $LOG_FILE

echo "------------------------------------" >> $LOG_FILE

for img in $INPUT_DIR/*.ppm; do
    name=$(basename $img)
    out_compressed="$OUTPUT_DIR/${name%.ppm}.out"
    out_img="${out_compressed%.out}.ppm"

    echo "Benchmarking $name."
    
    $APP -c2 $1 $img $out_compressed
    $APP -d $out_compressed $out_img

    original_size=$(stat -c '%s' "$img")
    compressed_size=$(stat -c '%s' "$out_compressed")
    ratio=$(echo "scale=2; $compressed_size / $original_size * 100" | bc)

    echo "Image: $name" >> $LOG_FILE
    echo "Original size: $original_size bytes" >> $LOG_FILE
    echo "Compressed size: $compressed_size bytes" >> $LOG_FILE
    echo "Compression ratio: $ratio %" >> $LOG_FILE
    echo "------------------------------------" >> $LOG_FILE

done

cd ../ && make clean

echo "Benchmark completed. Results are stored in $LOG_FILE."
