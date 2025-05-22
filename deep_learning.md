# Deep Learning CNN Concepts

## 📌 Table of Contents
1. [Perhitungan Convolution](#-perhitungan-convolution)
2. [MaxPooling](#-maxpooling)
3. [Arsitektur CNN](#-arsitektur-cnn)
4. [Transfer Learning](#-transfer-learning)
5. [Perbandingan Computer Vision Tasks](#-perbandingan-computer-vision-tasks)

---

## 🔢 Perhitungan Convolution

Convolution menghitung hasil dengan menggeser filter (kernel) di atas input dan melakukan perkalian elemen-per-elemen, lalu menjumlahkannya.

### Contoh Perhitungan

**Input 3x3:**
```
1  2  0  
4  5  6  
7  8  9 
```

**Filter/Kernel (2x2):**
```
1   0  
0  -1  
```

### Langkah-langkah (stride 1, tanpa padding):

**Posisi 1 (top-left):**
```
Input:   Kernel:
1 2     ×   1  0
4 5         0 -1

(1×1) + (2×0) + (4×0) + (5×-1) = 1 + 0 + 0 - 5 = -4
```

**Posisi 2 (top-right):**
```
Input:   Kernel:
2 0     ×   1  0
5 6         0 -1

(2×1) + (0×0) + (5×0) + (6×-1) = 2 + 0 + 0 - 6 = -4
```

**Hasil Akhir:**
```
-4  -4
-4  -4
```

---

## 🔽 MaxPooling

MaxPooling bertujuan mengurangi ukuran (dimensi) sambil mempertahankan informasi penting dengan mengambil nilai maksimum dari window tertentu.

### Stride
- **Stride = 1** → filter bergeser 1 piksel per langkah (lebih detail)
- **Stride = 2** → filter bergeser 2 piksel per langkah (lebih cepat, output lebih kecil)

### Contoh MaxPooling

**Input (4x4):**
```
1  3  2  1  
4  6  5  0  
7  8  9  3  
2  4  1  5  
```

**Parameter:**
- Pool size: 2x2
- Stride: 2

**Hasil:**
```
6  5
8  9
```

---

## 🏗️ Arsitektur CNN

![CNN Architecture](https://github.com/user-attachments/assets/0b25b218-cfd8-4624-9328-2417c8056c74)

### Komponen Utama:
1. **Convolutional Layer** - Ekstraksi fitur
2. **Activation Function (ReLU)** - Non-linearitas
3. **Pooling Layer** - Downsampling
4. **Fully Connected Layer** - Klasifikasi

---

## 🔄 Transfer Learning

### Tahapan Transfer Learning:

1. **Pilih Pre-trained Model**
   - Contoh: VGG16, MobileNet, EfficientNet

2. **Load Model**
   - Gunakan model dari framework seperti `keras.applications`

3. **Freeze Layer**
   - Jangan latih layer awal/fitur umum supaya tidak hilang

4. **Tambahkan Layer Output Baru**
   - Sesuaikan dengan jumlah kelas dataset (misal: 3 kelas - anjing, kucing, monyet)

5. **Train Model**
   - Latih model dengan dataset baru yang lebih kecil

### Kapan Transfer Learning Digunakan?

| Kondisi | Transfer Learning Cocok? |
|---------|-------------------------|
| Data latih kecil (< 1000 gambar) | ✅ Sangat cocok |
| Komputasi terbatas (CPU/GPU) | ✅ Cocok |
| Butuh hasil cepat | ✅ Cocok |
| Dataset mirip ImageNet | ✅ Sangat optimal |

---

## 📊 Perbandingan Computer Vision Tasks

| Aspek | Image Classification | Object Detection | Image Segmentation |
|-------|---------------------|------------------|-------------------|
| **Input** | Gambar penuh | Gambar penuh | Gambar penuh |
| **Output** | Label | Label + Bounding Box | Label untuk setiap piksel |
| **Berapa objek?** | 1 | Banyak | Banyak |
| **Apakah tahu posisi?** | ❌ Tidak | ✅ Bounding Box | ✅ Sangat detail (per piksel) |
| **Contoh Model** | VGG, ResNet | YOLO, SSD, Faster R-CNN | U-Net, DeepLab, Mask R-CNN |
| **Aplikasi** | Klasifikasi gambar | Deteksi objek (mobil, orang) | Medis, jalan, satelit, deteksi tumor |

---

## 📝 Kesimpulan

Dokumen ini merangkum konsep-konsep dasar dalam Deep Learning CNN, mulai dari operasi matematika dasar hingga aplikasi praktis dalam berbagai tugas Computer Vision.
