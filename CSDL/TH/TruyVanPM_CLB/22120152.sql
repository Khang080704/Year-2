-- CSDL Phòng máy
use QuanLyMayTinh5
--a. Cho biết manv và tennv của nhân viên quản lý phòng máy có máy không sử dụng được
select nv.MaNV, nv.TenNV
from NHANVIEN nv join PHONGMAY pm on pm.MaNVQL = nv.MaNV
				 join MAYTINH mt on pm.MaPhong = mt.MaPM and pm.MayChu = mt.MaMT
where mt.TinhTrang = 0
--b. Cho biến mamt và mapm của các máy gateway trong phòng tên là I53.select mt.MayGateWay, mt.MaPMfrom MAYTINH mayGateWay join MAYTINH mt on mayGateWay.MaPM = mt.MaPM and mayGateWay.MaMT = mt.MaMT						join PHONGMAY pm on mayGateWay.MaPM = pm.MaPhong						where pm.TenPhong='I53'--CSDL QL CLB cờ vuause CLBCOVUA--a. Cho biết danh sách các đội (IDCLB, TênDoi) có học viên sinh từ năm 1988--  trở về sau select DOI.IDCLB, DOI.TenDoifrom DOI join HOIVIEN hv on DOI.IDCLB = hv.IDCLB and DOI.IDDoi = hv.IDDoiwhere YEAR(hv.NgaySinh) >= 1988--b. Cho biết danh sách các học viên (IDCLB, HoTen) có người cùng tập luyện
--	bằng tuổi. 
select hv.IDCLB, hv.HoTen
from HOIVIEN hv join HOIVIEN banTapLuyen on hv.IDCLB = banTapLuyen.IDCLB 
											and hv.IDBanCungTapLuyen = banTapLuyen.IDHoiVien
where (year(hv.NgaySinh) = year(banTapLuyen.NgaySinh))