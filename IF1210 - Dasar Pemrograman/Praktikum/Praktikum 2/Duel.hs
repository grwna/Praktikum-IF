module Duel where

-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
konso :: String -> [String] -> [String]
{- konso e li menghasilkan sebuah list of integer dari e (sebuah integer) dan li 
   (list of integer), dengan e sebagai elemen pertama: e o li -> li' -}
-- REALISASI
konso e li = [e] ++ li

--DEFINISI DAN SPESIFIKASI
duel :: [String] -> [String]
--REALISASI
duel ls
 | null ls = []
 | head ls == "desperado" = konso ("BANG") (duel(tail ls))
 | otherwise = konso (head ls) (duel(tail ls))