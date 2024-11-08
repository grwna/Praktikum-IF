module HitungBensin where

--DEFINISI DAN SPESIFIKASI
hitungBensin :: Int -> Int -> Int
{-Menghitung total pengeluaran bensin pada perjalanan posisi A ke B-}

unitBensin :: Int -> Int
{-Menghitung pengeluaran bensin dalan satu perjalanan-}

--REALISASI
unitBensin x
    | x == 1 = 0
    | mod x 2 == 0 = 1 + unitBensin (div x 2)
    | otherwise = 1 + unitBensin (x*3 + 1)
    
hitungBensin a b
    | a == b = unitBensin a
    | otherwise = unitBensin b + hitungBensin a (b-1)

--APLIKASI
--hitungBensin 11 11