__Image compression using quadtree data structures__
---

#### Description

An application designed for compressing and decompressing PPM images using __quadtree__ data structures to ___efficiently reduce file size___ while preserving image quality.

---

#### Usage
The executable can be built using the following command:
```
make build
```

The flag `-c1` can be used to display information regarding the compression tree for an image:
```
./quadtree -c1 <factor> <input_file> <output_file>
```

The flag `-c2` is used to create the compressed file for an image:
```
./quadtree -c2 <factor> <input_file> <output_file>
```

The flag `-d` is used for decompressing an already compressed image:
```
./quadtree -d <input_file> <output_file>
```

---

#### Implementation details

The quadtree compression algorithm takes a PPM image and builds a hierarchical tree by ___recursively dividing the image___ into quadrants. Each region’s _color similarity is analyzed_; if the colors are sufficiently uniform, a leaf node is created containing the ___average RGB value___. Otherwise, an internal node is added, and the process continues for the four sub-regions. 

For decompression, the quadtree is reconstructed from the compressed file by sequentially reading node types and pixel values, recreating the original image block by block.

The implementation has been generalized for __better code modularity and structure__. This includes _switching to C naming conventions, better file organization_, and ___reducing duplicate code___ in color similarity calculations. The quadtree and queue structures have also been refined, improving flexibility and readability of the code while maintaining compression efficiency.

---

#### Benchmark

___Up to 80% dimension reduction___ can be attained using this application. Full results of the benchmark process can be read [here](benchmark/benchmark.md).

---