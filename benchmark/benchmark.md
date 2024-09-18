## Benchmarking Report
---

The images used for the tests are from [Pexels](https://www.pexels.com/ro-ro/).

While by using this application you can get virtually up to a 99.999% compression rate (if we are talking about monochromatic high-resolution images which will always be only 8kb in compressed form), I did some testing to find out the application's capabilities in real-life situations.

Using 20 complex images with 1024x1024 dimensions, I reached the following conclusions:
- 16/20 images were larger in compressed form when using the compression factor 0 due to the additional information required for constructing back the compression tree(since the majority of the images used didn't have large portions with the exact same hue)
- using a compression factor of __10__, 18/20 images were smaller in compressed form, ___reaching up to 80% compression___
- using a compression factor of __25__, 19/20 images were smaller in compressed form, ___reaching up to 87% compression___
- using a  compression factor of __50__, all the images were smaller in compressed form, ___reaching up to 91% compression___

_Note_: The script ``benchmark.sh`` can be used for benchmarking ppm images. PPM pictures aren't included in this repo, since they cannot be previsualized on Github. For converting jpg to ppm p6 images I wrote the script ``convert.sh``.

---

### __My results__

---

__TEST00__

<img src="pictures/pexels-amirabbas-rahbar-modami-724205826-28238934 (1).jpg" width=200> <img src="my_results/my_results_10/test00.jpg" width=200> <img src="my_results/my_results_25/test00.jpg" width=200> <img src="my_results/my_results_50/test00.jpg" width=200>

``Compression factor 0: 140.97%
Compression factor 10: 107.00%
Compression factor 25: 65.28%
Compression factor 50: 21.81%
``

__TEST01__

<img src="pictures/pexels-carstenkohler-9248674 (1).jpg" width=200> <img src="my_results/my_results_10/test01.jpg" width=200> <img src="my_results/my_results_25/test01.jpg" width=200> <img src="my_results/my_results_50/test01.jpg" width=200>

``Compression factor 0: 120.04%
Compression factor 10: 24.13%
Compression factor 25: 13.11%
Compression factor 50: 8.77%
``

__TEST02__

<img src="pictures/pexels-damir-28251766 (1).jpg" width=200> <img src="my_results/my_results_10/test02.jpg" width=200> <img src="my_results/my_results_25/test02.jpg" width=200> <img src="my_results/my_results_50/test02.jpg" width=200>

``Compression factor 0: 128.00%
Compression factor 10: 80.19%
Compression factor 25: 64.70%
Compression factor 50: 53.28%
``

__TEST03__

<img src="pictures/pexels-didsss-27792993 (1).jpg" width=200> <img src="my_results/my_results_10/test03.jpg" width=200> <img src="my_results/my_results_25/test03.jpg" width=200> <img src="my_results/my_results_50/test03.jpg" width=200>

``Compression factor 0: 127.20%
Compression factor 10: 85.49%
Compression factor 25: 71.53%
Compression factor 50: 61.26%
``

__TEST04__

<img src="pictures/pexels-dqnguyen15-22696600 (1).jpg" width=200> <img src="my_results/my_results_10/test04.jpg" width=200> <img src="my_results/my_results_25/test04.jpg" width=200> <img src="my_results/my_results_50/test04.jpg" width=200>

``Compression factor 0: 83.36%
Compression factor 10: 34.14%
Compression factor 25: 26.31%
Compression factor 50: 22.21%
``

__TEST05__

<img src="pictures/pexels-ivan-rojas-1655669943-28487712 (1).jpg" width=200> <img src="my_results/my_results_10/test05.jpg" width=200> <img src="my_results/my_results_25/test05.jpg" width=200> <img src="my_results/my_results_50/test05.jpg" width=200>

``Compression factor 0: 99.11%
Compression factor 10: 24.77%
Compression factor 25: 12.99%
Compression factor 50: 7.27%
``

__TEST06__

<img src="pictures/pexels-koushalya-karthikeyan-605468635-17242708 (1).jpg" width=200> <img src="my_results/my_results_10/test06.jpg" width=200> <img src="my_results/my_results_25/test06.jpg" width=200> <img src="my_results/my_results_50/test06.jpg" width=200>

``Compression factor 0: 136.53%
Compression factor 10: 37.7%
Compression factor 25: 23.91%
Compression factor 50: 15.94%
``

__TEST07__

<img src="pictures/pexels-koushalya-karthikeyan-605468635-17242710 (1).jpg" width=200> <img src="my_results/my_results_10/test07.jpg" width=200> <img src="my_results/my_results_25/test07.jpg" width=200> <img src="my_results/my_results_50/test07.jpg" width=200>

``Compression factor 0: 123.35%
Compression factor 10: 20.00%
Compression factor 25: 14.66%
Compression factor 50: 11.25%
``

__TEST08__

<img src="pictures/pexels-koushalya-karthikeyan-605468635-17377648 (1).jpg" width=200> <img src="my_results/my_results_10/test08.jpg" width=200> <img src="my_results/my_results_25/test08.jpg" width=200> <img src="my_results/my_results_50/test08.jpg" width=200>

``Compression factor 0: 124.93%
Compression factor 10: 43.57%
Compression factor 25: 28.60%
Compression factor 50: 19.02%
``

__TEST09__

<img src="pictures/pexels-koushalya-karthikeyan-605468635-17493532 (1).jpg" width=200> <img src="my_results/my_results_10/test09.jpg" width=200> <img src="my_results/my_results_25/test09.jpg" width=200> <img src="my_results/my_results_50/test09.jpg" width=200>

``Compression factor 0: 140.36%
Compression factor 10: 67.38%
Compression factor 25: 37.85%
Compression factor 50: 27.94%
``

__TEST10__

<img src="pictures/pexels-nathanjhilton-9462841 (1).jpg" width=200> <img src="my_results/my_results_10/test10.jpg" width=200> <img src="my_results/my_results_25/test10.jpg" width=200> <img src="my_results/my_results_50/test10.jpg" width=200>

``Compression factor 0: 92.92%
Compression factor 10: 33.96%
Compression factor 25: 25.41%
Compression factor 50: 19.44%
``

__TEST11__

<img src="pictures/pexels-phamthe-27745133 (1).jpg" width=200> <img src="my_results/my_results_10/test11.jpg" width=200> <img src="my_results/my_results_25/test11.jpg" width=200> <img src="my_results/my_results_50/test11.jpg" width=200>

``Compression factor 0: 138.08%
Compression factor 10: 53.58%
Compression factor 25: 30.17%
Compression factor 50: 18.77%
``

__TEST12__

<img src="pictures/pexels-roshan-dadhe-55954452-28201415 (1).jpg" width=200> <img src="my_results/my_results_10/test12.jpg" width=200> <img src="my_results/my_results_25/test12.jpg" width=200> <img src="my_results/my_results_50/test12.jpg" width=200>

``Compression factor 0: 70.15%
Compression factor 10: 41.72%
Compression factor 25: 33.35%
Compression factor 50: 25.61%
``

__TEST13__

<img src="pictures/pexels-ruxandra-scutelnic-1470184397-27025433 (1).jpg" width=200> <img src="my_results/my_results_10/test13.jpg" width=200> <img src="my_results/my_results_25/test13.jpg" width=200> <img src="my_results/my_results_50/test13.jpg" width=200>

``Compression factor 0: 143.11%
Compression factor 10: 95.37%
Compression factor 25: 35.79%
Compression factor 50: 24.19%
``

__TEST14__

<img src="pictures/pexels-sheri-baldner-341169086-14146070 (1).jpg" width=200> <img src="my_results/my_results_10/test14.jpg" width=200> <img src="my_results/my_results_25/test14.jpg" width=200> <img src="my_results/my_results_50/test14.jpg" width=200>

``Compression factor 0: 136.51%
Compression factor 10: 88.12%
Compression factor 25: 65.27%
Compression factor 50: 47.32%
``

__TEST15__

<img src="pictures/pexels-sheri-baldner-341169086-14189055 (1).jpg" width=200> <img src="my_results/my_results_10/test15.jpg" width=200> <img src="my_results/my_results_25/test15.jpg" width=200> <img src="my_results/my_results_50/test15.jpg" width=200>

``Compression factor 0: 137.09%
Compression factor 10: 120.34%
Compression factor 25: 111.09%
Compression factor 50: 98.60%
``

__TEST16__

<img src="pictures/pexels-sheri-baldner-341169086-17203843 (1).jpg" width=200> <img src="my_results/my_results_10/test16.jpg" width=200> <img src="my_results/my_results_25/test16.jpg" width=200> <img src="my_results/my_results_50/test16.jpg" width=200>

``Compression factor 0: 123.74%
Compression factor 10: 56.39%
Compression factor 25: 38.83%
Compression factor 50: 28.88%
``

__TEST17__

<img src="pictures/pexels-suedadilli-25858460 (1).jpg" width=200> <img src="my_results/my_results_10/test17.jpg" width=200> <img src="my_results/my_results_25/test17.jpg" width=200> <img src="my_results/my_results_50/test17.jpg" width=200>

``Compression factor 0: 103.41%
Compression factor 10: 74.61%
Compression factor 25: 60.59%
Compression factor 50: 48.82%
``

__TEST18__

<img src="pictures/pexels-suedadilli-27911020 (1).jpg" width=200> <img src="my_results/my_results_10/test18.jpg" width=200> <img src="my_results/my_results_25/test18.jpg" width=200> <img src="my_results/my_results_50/test18.jpg" width=200>

``Compression factor 0: 134.87%
Compression factor 10: 24.42%
Compression factor 25: 13.59%
Compression factor 50: 9.07%
``

__TEST19__

<img src="pictures/pexels-suedadilli-28468506 (1).jpg" width=200> <img src="my_results/my_results_10/test19.jpg" width=200> <img src="my_results/my_results_25/test19.jpg" width=200> <img src="my_results/my_results_50/test19.jpg" width=200>

``Compression factor 0: 141.16%
Compression factor 10: 95.46%
Compression factor 25: 75.48%
Compression factor 50: 57.51%
``

---