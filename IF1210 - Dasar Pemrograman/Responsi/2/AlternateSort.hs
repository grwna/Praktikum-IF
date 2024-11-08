module AlternateSort where
alternateSort :: [Int] -> [Int]

konso :: Int -> [Int] -> [Int]
konso e li = [e] ++ li

elmMin :: [Int] -> Int
elmMin l
 | tail l == [] = head l
 | head l < elmMin (tail l) = head l
 | otherwise = elmMin (tail l)

delElm ::Int ->  [Int] -> [Int]
delElm e l
 | null l = l 
 | e == head l = tail l
 | otherwise = konso (head l) (delElm e (tail l))

sorter :: [Int] -> [Int]
sorter l
 | null l = l
 | otherwise = konso (elmMin l) (sorter(delElm(elmMin l) l))

alternateSort l
 | null l || tail l == [] = l
 | otherwise = konso (head (sorter l)) (konso(last(sorter l))(alternateSort(tail(init(sorter l)))))
