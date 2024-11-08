module ListOfCharacter where
-- DEFINISI DAN SPESIFIKASI LIST
{- type List of Char: [ ] atau [e o List] atau [List o e]
    Definisi type List of Char
    Basis: List of Char kosong adalah list of Char
    Rekurens: 
    List tidak kosong dibuat dengan menambahkan sebuah elemen bertype Char di awal 
    sebuah list atau
    dibuat dengan menambahkan sebuah elemen bertype Char di akhir sebuah list -}

-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
konso :: Char -> [Char] -> [Char]
{- konso e lc menghasilkan sebuah list of character dari e (sebuah character)  
    dan lc (list of integer), dengan cc sebagai elemen pertama: e o lc -> lc' -}
-- REALISASI
konso e lc = [e] ++ lc

konsDot :: [Char] -> Char -> [Char]
{- konsDot(lc,cc) menghasilkan sebuah list of character dari lc (list of 
    character) dan e (sebuah character), dengan e sebagai elemen terakhir: 
    lc o e -> lc' -}
-- REALISASI
konsDot lc e = lc ++ [e]

-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- head :: [Char] -> Char
-- head l menghasilkan elemen pertama list l, l tidak kosong

-- tail :: [Char] -> [Char]
-- tail l menghasilkan list tanpa elemen pertama list l, l tidak kosong

-- last :: [Char] -> Char
-- last l  menghasilkan elemen terakhir list l, l tidak kosong

-- init :: [Char] -> [Char]
-- init(l) menghasilkan list tanpa elemen terakhir list l, l tidak kosong

-- DEFINISI DAN SPESIFIKASI PREDIKAT
isEmpty :: [Char] -> Bool
-- isEmpty l true jika list of character l kosong
-- REALISASI
isEmpty l = null l

isOneElmt :: [Char] -> Bool
-- isOneElmt l true jika list of character l hanya mempunyai satu elemen
-- REALISASI
isOneElmt l = (length l) == 1 

isMember :: [Char] -> Char -> Bool
--REALISASI
isMember l c
 | isEmpty l = False
 | (head l) == c = True
 | otherwise = isMember (tail l) c 


--Konkat
konkat :: [Char] -> [Char] -> [Char]
--REALISASI
konkat l1 l2
 | isEmpty l2 = l1
 | isEmpty l1 = l2
 | otherwise = konkat (konsDot l1 (head l2)) (tail l2)

isPalindrom :: [Char] -> Bool
isPalindrom lc
 | isEmpty lc = True
 | isOneElmt lc = True
 | head lc /= last lc = False
 | otherwise = isPalindrom(init(tail lc))

--Pajak Makan
pajakMakan :: [Char] -> [Int] -> [Char]
--REALISASI
pajakMakan lc li
 | isEmpty lc = []
 | (fromIntegral(head li * 110)/100) <= 200 = konso (head lc) (pajakMakan (tail lc) (tail li))
 | otherwise = pajakMakan (tail lc) (tail li)

splitAlternate :: [Char] -> ([Char],[Char])
splitAlternate a =
 let
 lengthParity = mod (length a) 2
 oddArr t
    | isEmpty t = t
    | mod (length t) 2 == lengthParity = konso (head t) (oddArr(tail t)) 
    | otherwise = oddArr(tail t) 
 evenArr t
    | isEmpty t = t
    | mod (length t) 2 == lengthParity = evenArr(tail t) 
    | otherwise = konso (head t) (evenArr(tail t)) 
 in
 (oddArr a, evenArr a)


  