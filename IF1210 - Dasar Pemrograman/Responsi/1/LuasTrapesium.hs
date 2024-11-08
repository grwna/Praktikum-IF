module LuasTrapesium where
--DEFINISI DAN SPESIFIKASI
luasTrapesium :: Float -> Float -> Float -> Float
{-Menghitung luas trapesium berdasarkan ukuran dimensi yang dimasukkan-}

--REALISASI
luasTrapesium t s1 s2 = (1/2) * t * (s1+s2)

--APLIKASI
--luasTrapesium 2 4 3