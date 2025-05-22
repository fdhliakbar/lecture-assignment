## 📌 Table of Contents

1. [Perhitungan Convolution](#-perhitungan-convolution)
2. a


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
```bash
Posisi 1 (top-left):

Input:   Kernel:
1 2     x   1 0
4 5         0 -1
(1×1) + (2×0) + (4×0) + (5×-1) = 1 + 0 + 0 - 5 = -4

Posisi 2 (top-right):

Input:   Kernel:
2 0     x   1 0
5 6         0 -1
(2x1) + (0x0) + (5x0) + (6x-1) = 2 + 0 + 0 - 6 = -4
Sampai selesai(end)

Hasil

-4 -4
-4 -4
```

## MaxPooling
MaxPooling bertujuan mengurangi ukuran (dimensi) sambil mempertahankan informasi penting dengan mengambil nilai maksimum dari window tertentu.
Stride adalah berapa langkah (step) filter berpindah saat melakukan operasi convolution atau max pooling.
Stride = 1 → filter bergeser 1 piksel per langkah (lebih detail).
Stride = 2 → filter bergeser 2 piksel per langkah (lebih cepat, lebih kecil output-nya).
Misal input hasil dari layer sebelumnya (4x4):
```bash
1  3  2  1  
4  6  5  0  
7  8  9  3  
2  4  1  5  
Dengan:

Ukuran kernel (pool size): 2x2
Stride: 2

Result:
6 5
8 9
```

## Arsitektur CNN
![image](https://github.com/user-attachments/assets/0b25b218-cfd8-4624-9328-2417c8056c74)


## Tahap Transfer Learning
1. Pilih pre-trained model
   - misalkan VGG16, MobileNet, EfficientNet dll
3. Load model
   - gunakan model yang sudah disediakan framework seperri keras.applications
4. Freeze layer
   - jangan latih layer awal atau fitur umu, supaya tidak hilang
5. Tambahkan layer output baru
   - tambahkan layer sesuai sesuai jumlah kelas dataset (misalnya 3 kelas: anjing,kucing,monyet)
6. Train model
   - Latih model dengan dataset baru yang lebih kecil

## Kapan Transfer Learning Digunakan?
Kondisi | Transfer Learning Cocok?
Data latih kecil (< 1000 gambar) | ✅ Sangat cocok
Komputasi terbatas (CPU/GPU) |	✅ Cocok
Butuh hasil cepat	| ✅ Cocok
Dataset mirip ImageNet	| ✅ Sangat optimal

Perbandingan Ringkas:
Aspek	Image Classification	Object Detection	Image Segmentation
Input	Gambar penuh	Gambar penuh	Gambar penuh
Output	Label	Label + Bounding Box	Label untuk setiap piksel
Berapa objek?	1	Banyak	Banyak
Apakah tahu posisi?	❌ Tidak	✅ Bounding Box	✅ Sangat detail (per piksel)
Contoh Model	VGG, ResNet	YOLO, SSD, Faster R-CNN	U-Net, DeepLab, Mask R-CNN
Aplikasi	Klasifikasi gambar	Deteksi objek (mobil, orang)	Medis, jalan, satelit, deteksi tumor
