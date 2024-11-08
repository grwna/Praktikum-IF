module UkuranBaju where

--DEFINISI DAN SPESIFIKASI
ukuranBaju :: Int -> Int -> Int 
{-Menentukan ukuran baju yang tepat berdasarkan tinggi dan berat badan-}

--REALISASI
ukuranBaju t b 
    |t <= 150 = 1
    |t > 170 && 60 < b && b <= 80 = 3
    |150 < t && t <= 170 && b <= 80 = 2
    |150 < t && t <= 170 && b > 80 = 3
    |t > 170 && b <= 60 =2
    |otherwise = 4
--APLIKASI
--ukuranBaju 160 75