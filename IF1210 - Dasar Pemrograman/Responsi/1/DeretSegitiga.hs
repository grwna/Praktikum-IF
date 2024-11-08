module DeretSegitiga where

--DEFINISI DAN SPESIFIKASI
deretSegitiga :: Int -> Int
{-Menentukan nilai suku ke-n dari DeretSegitiga-}

--REALISASI
deretSegitiga n
    | n == 1 = 1
    | otherwise = deretSegitiga (n-1) + n

--APLIKASI 
--deretSegitiga 100