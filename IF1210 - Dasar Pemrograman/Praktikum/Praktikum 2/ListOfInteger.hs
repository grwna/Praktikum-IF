module ListOfInteger where
-- DEFINISI DAN SPESIFIKASI LIST
{- type List of Int: [ ] atau [e o List] atau [List o e]  
   Definisi type List of Int
   Basis: List of Int kosong adalah list of Int 
   Rekurens: 
   List tidak kosong dibuat dengan menambahkan sebuah elemen bertype Int di awal 
   sebuah list atau
   dibuat dengan menambahkan sebuah elemen bertype Int di akhir sebuah list -}

-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
konso :: Int -> [Int] -> [Int]
{- konso e li menghasilkan sebuah list of integer dari e (sebuah integer) dan li 
   (list of integer), dengan e sebagai elemen pertama: e o li -> li' -}
-- REALISASI
konso e li = [e] ++ li

konsDot :: [Int] -> Int -> [Int]
{- konsDot li e menghasilkan sebuah list of integer dari li (list of integer) dan 
   e (sebuah integer), dengan e sebagai elemen terakhir: li o e -> li' -}
-- REALISASI
konsDot li e = li ++ [e]

-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- head :: [Int] -> Int
-- head l menghasilkan elemen pertama list l, l tidak kosong

-- tail :: [Int] -> [Int]
-- tail l menghasilkan list tanpa elemen pertama list l, l tidak kosong

-- last :: [Int] -> Int
-- last l menghasilkan elemen terakhir list l, l tidak kosong

-- init :: [Int] -> [Int]
-- init l menghasilkan list tanpa elemen terakhir list l, l tidak kosong

-- DEFINISI DAN SPESIFIKASI PREDIKAT
isEmpty :: [Int] -> Bool
-- isEmpty l  true jika list of integer l kosong
-- REALISASI
isEmpty l = null l

isOneElmt :: [Int] -> Bool
-- isOneElmt l true jika list of integer l hanya mempunyai satu elemen
-- REALISASI
isOneElmt l = (length l) == 1 



--IS MEMBER
isMember :: [Int] -> Int -> Bool
{-Mengecek apakah elemen c termasuk dalam list l-}
--REALISASI
isMember l c
 | isEmpty l = False
 | (head l) == c = True
 | otherwise = isMember (tail l) c 

--jmlMin
jmlMin :: [Int] -> (Int,Int)

--FUNGSI ANTARA
nbX :: Int -> [Int] -> Int
minList :: [Int] -> Int

--REALISASI
nbX x l
 | isEmpty l = 0
 | x == (head l) = 1 + nbX x (tail l) 
 | otherwise = nbX x (tail l)

minList l
 | tail l == [] = head l
 | head l < minList (tail l) = head l
 | otherwise = minList (tail l)

jmlMin l = (minList l, nbX (minList l) l)

--Pecah List Ganjil Genap
pecahListGanjilGenap :: [Int] -> ([Int],[Int],[Int])
pemecahListNeg :: [Int] -> [Int]
isPosGen :: Int -> Bool
isPosGan :: Int -> Bool
pemecahListPosGen :: [Int] -> [Int]
pemecahListPosGan :: [Int] -> [Int]
--FUNGSI ANTARA
isPosGen x = x > 0 && mod x 2 == 0
isPosGan x = x > 0 && mod x 2 /= 0
--REALISASI
pemecahListNeg l
 |isEmpty l = []
 |(head l) <= 0 = konso (head l) (pemecahListNeg (tail l))
 | otherwise = pemecahListNeg(tail l)

pemecahListPosGan l
 |isEmpty l = []
 |isPosGan (head l) = konso (head l) (pemecahListPosGan (tail l))
 | otherwise = pemecahListPosGan(tail l)

pemecahListPosGen l
 |isEmpty l = []
 |isPosGen (head l) = konso (head l) (pemecahListPosGen (tail l))
 | otherwise = pemecahListPosGen(tail l)

pecahListGanjilGenap l
 | isEmpty l = ([],[],[]) 
 | otherwise = (pemecahListNeg l,pemecahListPosGan l,pemecahListPosGen l)

