﻿-- CSDL Phòng máy
use QuanLyMayTinh5
--a. Cho biết manv và tennv của nhân viên quản lý phòng máy có máy không sử dụng được
select nv.MaNV, nv.TenNV
from NHANVIEN nv join PHONGMAY pm on pm.MaNVQL = nv.MaNV
				 join MAYTINH mt on pm.MaPhong = mt.MaPM and pm.MayChu = mt.MaMT
where mt.TinhTrang = 0
--b. Cho biến mamt và mapm của các máy gateway trong phòng tên là I53.
--	bằng tuổi. 
select hv.IDCLB, hv.HoTen
from HOIVIEN hv join HOIVIEN banTapLuyen on hv.IDCLB = banTapLuyen.IDCLB 
											and hv.IDBanCungTapLuyen = banTapLuyen.IDHoiVien
where (year(hv.NgaySinh) = year(banTapLuyen.NgaySinh))