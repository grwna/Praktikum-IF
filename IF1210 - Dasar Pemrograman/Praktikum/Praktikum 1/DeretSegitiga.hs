module DeretSegitiga where

--DEFINISI DAN SPESIFIKASI
deretSegitiga :: Int -> Int
{-Menentukan nilai dari suku ke-n pada DeretSegitiga-}

--REALISASI
deretSegitiga n
    | n == 1 = 1
    | otherwise = deretSegitiga (n-1) + n

--APLIKASI 
--deretSegitiga 7