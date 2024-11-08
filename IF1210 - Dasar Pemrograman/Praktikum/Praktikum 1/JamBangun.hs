
module JamBangun where

--DEFINISI DAN SPESIFIKASI
jamBangun :: Int -> Int -> Int -> (Bool,Int,Int,Int)
{-Menentukan apakah Jane bangun telat sesua ham pertemuan
  dosen yang dimasukkan-}

--REALISASI
jamBangun j m d =
    let detikBangun = 7 * 60 * 60 + 45 * 60 + 0
        detikDosen = j * 60 * 60 + m * 60 + d
        selisih = 
          if detikBangun > detikDosen then detikBangun - detikDosen
          else detikDosen - detikBangun
    in
            if detikBangun > detikDosen then (True,div selisih (60*60), mod (div selisih 60) 60, mod selisih 60 )
            else (False,div selisih (60*60), mod (div selisih 60) 60, mod selisih 60 )

--APLIKASI
--jamBangun 07 15 00
