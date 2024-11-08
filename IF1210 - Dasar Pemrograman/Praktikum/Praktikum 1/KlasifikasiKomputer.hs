module KlasifikasiKomputer where

--DEFINISI DAN SPESIFIKASI 
klasifikasi :: Int -> Int -> Int -> Int
{-Mengklasifikasikan Komputer berdasarkan spesifikasi mesinnya-}

--REALISASI
klasifikasi cpu gpu hd
    | cpu < 2 || gpu < 2 || hd < 2 = 1
    | cpu < 5 || gpu < 5 = 2
    | cpu <= 7 && gpu <= 7 && hd <= 7 = 3
    | cpu > 7 && gpu > 7 && hd > 7 = 5
    | otherwise = 4

--APLIKASI
--klasifikasi 8 9 4