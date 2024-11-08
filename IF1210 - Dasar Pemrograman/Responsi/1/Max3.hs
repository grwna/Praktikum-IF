module Max3 where

--DEFINISI DAN SPESIFIKASI
max3 :: Int -> Int -> Int -> Int
{-Menghitung nilai maksimum diantara 3 bilangan integer-}

--REALISASI
max3 a b c
    | a > b  && a > c = a
    | b > a && b > c = b
    | c > b && c > a = c
    | otherwise = a
 --APLIKASI
 --max3 5 9 6
