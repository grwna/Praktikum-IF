module SumKelipatanX where

--DEFINISI DAN SPESIFIKASI
sumKelipatanX :: Int -> Int -> Int -> Int
{-Menghitung jumlah kelipatan x pada interval [m,n] -}

--REALISASI
sumKelipatanX m n x
    | m == n && mod m x == 0 = m
    | m == n && mod m x /= 0 = 0
    | m /= n && mod m x == 0 = m + sumKelipatanX (m+1) n x
    | otherwise = sumKelipatanX (m+1) n x

--APLIKASI
--sumKelipatanX 1 10 2