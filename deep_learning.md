## Perhitungan Convolution
Convolution menghitung hasil dengan menggeser filter (kernel) di atas input dan melakukan perkalian elemen-per-elemen, lalu menjumlahkannya.

Misalnya input 3x3
```bash
1  2  0  
4  5  6  
7  8  9 
```
Filter/Kernel (2x2):
```bash
1  0  
0  -1  
```
Langkah-langkah (stride 1, tanpa padding):

Posisi 1 (top-left):
```bash
Input:   Kernel:
1 2     x   1 0
4 5         0 -1
(1×1) + (2×0) + (4×0) + (5×-1) = 1 + 0 + 0 - 5 = -4
```bash

Posisi 2 (top-right):
```bash
Input:   Kernel:
2 0     x   1 0
5 6         0 -1
(2x1) + (0x0) + (5x0) + (6x-1) = 2 + 0 + 0 - 6 = -4
Sampai selesai(end)
```bash

Hasil
```bash
-4 -4
-4 -4
```
