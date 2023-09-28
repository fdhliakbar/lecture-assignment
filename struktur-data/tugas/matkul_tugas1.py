def delArray(arr):
    # Buat list baru yang hanya berisi elemen non-null
    result = [x for x in arr if x != 0]
    return result

def insert_array(arr, element):
    # Buat list baru yang merupakan salinan dari arr dan tambahkan elemen baru
    result = arr.copy()
    result.append(element)
    return result

# Array awal
array = [72, 110, 12, 66, 90]

# Menghapus elemen null dan membuat list baru
new_array = delArray(array)

# Memasukkan elemen baru dan membuat list baru lagi
new_element = 42
new_array = insert_array(new_array, new_element)

# Menampilkan hasil list
print(new_array)
