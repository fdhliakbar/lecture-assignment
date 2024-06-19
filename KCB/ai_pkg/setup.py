import setuptools

# Membaca deskripsi panjang dari README.md
with open("README.md", "r", encoding="utf-8") as fh:
    long_description = fh.read()

# Konfigurasi setup
setuptools.setup(
    name="ai_pkg",  # Nama paket
    version="0.0.1",  # Versi paket
    author="Example Author",  # Nama penulis
    author_email="author@example.com",  # Email penulis
    description="A small example package",  # Deskripsi singkat
    long_description=long_description,  # Deskripsi panjang dari README.md
    long_description_content_type="text/markdown",  # Jenis konten deskripsi panjang
    url="https://github.com/pypa/sampleproject",  # URL proyek
    packages=setuptools.find_packages(),  # Paket yang akan disertakan
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",  # Perbaikan: Ditulis dalam satu baris
        "Operating System :: OS Independent",
    ],
)
