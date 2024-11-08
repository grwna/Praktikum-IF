module NbKelipatanX where

--DEFINISI DAN SPESIFIKASI
nbKelipatanX :: Int -> Int -> Int -> Int
{-Menentukan berapa banyak kelipatan x diantara bilangan m hingga n-}

--REALISASI
nbKelipatanX m n x 
    | m == n && mod m x == 0 = 1
    | m == n && mod m x /= 0 = 0
    | m /= n && mod m x == 0 = 1 + nbKelipatanX (m+1) n x
    | otherwise = nbKelipatanX (m+1) n x

--APLIKASI
--nbKelipatanX 5 14 3