module LamaTidur where

--DEFINISI DAN SPESIFIKASI
lamaTidur :: Int -> Int -> Int -> (Bool,Int,Int,Int)
{-Menghitung berapa lama panitia arkavidia tidur jika akan bangun
pada pukul 5 pagi-}

--REALISASI
lamaTidur j m d =
    let detikTidur = if j > 5 then (j-24) * 60 * 60 + m * 60 + d
                     else j * 60 * 60 + m * 60 + d
        detik6Jam = 6 * 60 * 60
        detik5 = 5 * 60 * 60
        lmtdr = detik5 - detikTidur
          
    in
            if lmtdr >= detik6Jam then (True,div lmtdr (60*60), mod (div lmtdr 60) 60, mod lmtdr 60 )
            else (False,div lmtdr (60*60), mod (div lmtdr 60) 60, mod lmtdr 60 )