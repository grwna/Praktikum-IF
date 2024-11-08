module KonversiSuhu where
--DEFINISI DAN SPESIFIKASI
konversiSuhu :: Float -> Char -> Float
{-Mengkonversi suhu dari Celcius ke satuan suhu lainnya-}

--REALISASI
konversiSuhu c k
    | k == 'R' = (4/5) * c
    | k == 'F' = ((9/5)*c) + 32
    | k == 'K' = c + 273.15

--APLIKASI
--konversiSuhu 25 'R'
--konversiSuhu 47.6 'K'