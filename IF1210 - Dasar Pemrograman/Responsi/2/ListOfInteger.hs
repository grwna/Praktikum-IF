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

isMember :: [Int] -> Int -> Bool
--REALISASI
isMember l c
 | isEmpty l = False
 | (head l) == c = True
 | otherwise = isMember (tail l) c 

isEqual :: [Int] -> [Int] -> Bool
isEqual l1 l2
 | length l1 /= length l2 = False
 | isEmpty l1 && isEmpty l2 = True
 | head l1 /= head l2 = False
 | otherwise = isEqual (tail l1) ( tail l2)

--Number of Occurence
nbX:: Int -> [Int] -> Int
--REALISASI
nbX x l
 | isEmpty l = 0
 | x == (head l) = 1 + nbX x (tail l) 
 | otherwise = nbX x (tail l) 

maxList :: [Int] -> Int
maxList l 
 | isOneElmt l = head l
 | head l > maxList (tail l) = head l
 | otherwise = maxList (tail l)

maxNb :: [Int] -> (Int,Int)
maxNb l
 | isOneElmt l = (head l,1)
 | otherwise = (maxList l,nbX (maxList l)l)

minList :: [Int] -> Int
minList l 
 | isOneElmt l = head l
 | head l < minList (tail l) = head l
 | otherwise = minList (tail l)


jmlMin :: [Int] -> (Int,Int)
jmlMin l = (minList l, nbX  (minList l)l)

--Pecah List Ganjil Genap
pecahListPosNeg :: [Int] -> ([Int],[Int])
pemecahListNeg :: [Int] -> [Int]
pemecahListPos :: [Int] -> [Int]


--REALISASI
pemecahListNeg l
 |isEmpty l = []
 |(head l) < 0 = konso (head l) (pemecahListNeg (tail l))
 | otherwise = pemecahListNeg(tail l)

pemecahListPos l
 |isEmpty l = []
 |(head l) >= 0 = konso (head l) (pemecahListPos (tail l))
 | otherwise = pemecahListPos(tail l)

pecahListPosNeg l
 | isEmpty l = ([],[]) 
 | otherwise = (pemecahListPos l,pemecahListNeg l)