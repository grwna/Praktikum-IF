module Fibonacci where

--DEFINISI DAN SPESIFIKASI
fibonacci :: Int -> Int
{-Menentukan suku ke n dari sekuens Fibonacci-}

--REALISASI
fibonacci n
    | n <= 0 = 0
    | n == 1 || n == 2 = 1
    | otherwise = (fibonacci (n-1)) + (fibonacci (n-2)) 

--APLIKASI