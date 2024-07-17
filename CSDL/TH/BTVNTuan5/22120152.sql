use QLDT1
--Q1. Cho biet ho ten va muc luong cua giao vien nu
select gv.HOTEN, gv.LUONG
from GIAOVIEN gv
where gv.PHAI = N'Nữ'

--Q2. Cho biet ho ten giao vien va luong cua ho sau khi tang 10%
select gv.HOTEN, gv.LUONG * 1.1 as luongSauKhiTang
from GIAOVIEN gv

--Q3. Cho biết mã các giáo viên có họ tên bắt đầu bằng "Nguyễn" lương trên 2000 hoặc
--    giáo viên là trưởng bộ môn nhận chức sau 1995
select distinct gv.MAGV
from GIAOVIEN gv join BOMON bm on bm.TRUONGBM = gv.MAGV and year(bm.NGAYNHANCHUC) > 1995
or gv.HOTEN like N'%Nguyễn%' and gv.LUONG > 2000

--Q4. Cho biết những giáo viên của khoa công nghệ thông tin
select gv.*
from GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM
				 join KHOA on bm.MAKHOA = KHOA.MAKHOA
where KHOA.MAKHOA = 'CNTT'

--Q5. Cho biết thông tin của bộ môn cùng thông tin của giảng viên làm trưởng bộ môn đó
select bm.*,truongbm.*
from BOMON bm left join GIAOVIEN truongbm on bm.TRUONGBM = truongbm.MAGV

--Q6. Với mỗi giáo viên, cho biết thông tin của bộ môn mà họ đang làm việc
select gv.*, bm.*
from GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM

--Q7. Cho biết tên đề tài và giáo viên chủ nhiệm đề tài
select dt.TENDT, gv.*
from DETAI dt join GIAOVIEN gv on dt.GVCNDT = gv.MAGV

--Q8. Với mỗi khoa cho biết thông tin trưởng khoa
select khoa.TENKHOA, gv.*
from KHOA join GIAOVIEN gv on KHOA.TRUONGKHOA = gv.MAGV

--Q9. Cho biết các giáo viên của bộ môn "Vi Sinh" có tham gia đề tài 006
select distinct gv.*
from GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM and bm.TENBM = 'Vi Sinh'
				 join THAMGIADT tg on gv.MAGV = tg.MAGV and tg.MADT = '006'

--Q10. Với những đề tài thuộc cấp quản lí "Thành phố", cho biết mã đề tài, tên đề tài thuộc
--     về chủ đề nào, họ tên người chủ nhiệm đề tài cùng với ngày sinh và địa chỉ của người ấy
select dt.MADT, dt.TENDT, cd.TENCD, gv.HOTEN, gv.NGSINH, gv.DIACHI
from DETAI dt join CHUDE cd on dt.MACD = cd.MACD
			  join GIAOVIEN gv on dt.GVCNDT = gv.MAGV
where dt.CAPQL = 'Thành phố'

--Q11. Tìm họ tên của từng giáo viên và người phụ trách chuyên môn trực tiếp của giáo viên đó
select gv.HOTEN, qlcm.*
from GIAOVIEN gv join GIAOVIEN qlcm on gv.GVQLCM = qlcm.MAGV

--Q12. Tìm họ tên của giáo viên được "Nguyễn Thanh Tùng" phụ trách trực tiếp
select gv.HOTEN
from GIAOVIEN gv join GIAOVIEN qlcm on gv.GVQLCM = qlcm.MAGV
where qlcm.HOTEN = N'Nguyễn Thanh Tùng'

--Q.13 Cho biết giáo viên là trưởng bộ môn hệ thống thông tin
select gv.*, bm.TENBM
from GIAOVIEN gv join BOMON bm on gv.MAGV = bm.TRUONGBM
where bm.TENBM = N'Hệ thống thông tin'

--Q14. Cho biết tên người chủ nhiệm đề tài của những đề tài thuộc chủ đề quản lí giáo dục
select gv.HOTEN
from GIAOVIEN gv join DETAI dt on gv.MAGV = dt.GVCNDT
				 join CHUDE cd on dt.MACD = cd.MACD
where cd.MACD = 'QLGD'

--Q15. Cho biết tên các công việc đề tài HTTT quản lí các trường đại học có thời gian bắt đầu 
--     trong tháng 3/2008
select cv.*, dt.*
from CONGVIEC cv join DETAI dt on cv.MADT = dt.MADT 
where dt.TENDT = N'HTTT quản lí các trường ĐH' and MONTH(cv.NGAYBD) = 3 and YEAR(cv.NGAYBD) = 2008

--Q16. Cho biết tên giáo viên và tên người quản lí chuyên môn của giáo viên đó
select gv.HOTEN, qlcm.HOTEN
from GIAOVIEN gv join GIAOVIEN qlcm on gv.GVQLCM = qlcm.MAGV

--Q17. Cho biết các công việc bắt đầu từ khoảng 01/01/2007 đến 01/08/2007
select cv.*
from CONGVIEC cv
where year(cv.NGAYBD) = 2007 and DAY(cv.NGAYBD) = 1 and MONTH(cv.NGAYBD) = 1 and month(cv.NGAYKT) = 8
	and year(cv.NGAYKT) = 2007

--Q18. Cho biết họ tên giáo viên cùng bộ môn với giáo viên "Trần Trà Hương"
select gv.HOTEN
from GIAOVIEN gv join GIAOVIEN cungBoMon on gv.MABM = cungBoMon.MABM
where cungBoMon.HOTEN = N'Trần Trà Hương'

--Q19. Tìm những giáo viên vừa là trưởng bộ môn vừa chủ nhiệm đề tài
select distinct gv.*
from GIAOVIEN gv join BOMON bm on gv.MAGV = bm.TRUONGBM
				 join DETAI dt on gv.MAGV = dt.GVCNDT

--Q20. Cho biết những giáo viên vừa là trưởng khoa vừa là trưởng bộ môn
select gv.*
from GIAOVIEN gv join BOMON truongbm on gv.MAGV = truongbm.TRUONGBM
				 join KHOA k on gv.MAGV = k.TRUONGKHOA

--Q21. Cho biết tên những trưởng bộ môn mà chủ nhiệm đề tài
select distinct gv.HOTEN
from GIAOVIEN gv join BOMON bm on gv.MAGV = bm.TRUONGBM
				 join DETAI dt on gv.MAGV = dt.GVCNDT

--Q22. Cho biết mã số của các trưởng khoa có chủ nhiệm đề tài
select distinct gv.MAGV
from GIAOVIEN gv join KHOA on gv.MAGV = KHOA.TRUONGKHOA
				 join DETAI dt on gv.MAGV = dt.GVCNDT

--Q23. Cho biết mã số của các giáo viên thuộc bộ môn 'HTTT' hoặc có tham gia đề tài mã 001
select gv.MAGV
from GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM
where bm.MABM = 'HTTT'
union
select gv.MAGV
from GIAOVIEN gv join THAMGIADT tg on gv.MAGV = tg.MAGV
where tg.MADT = '001'

--Q24. Cho biết giáo viên làm việc cùng bộ môn với giáo viên 002
select gv.*
from GIAOVIEN gv join GIAOVIEN cungbomon on gv.MABM = cungbomon.MABM
where cungbomon.MAGV = '002'

--Q25. Tìm những giáo viên là trưởng bộ môn
select gv.*
from GIAOVIEN gv join BOMON bm on gv.MAGV = bm.TRUONGBM

--Q26. Cho biết họ tên và mức lương giáo viên
select HOTEN, LUONG
from GIAOVIEN

--Q27. Cho biết số lượng giáo viên và tổng lương của họ
select count(*) SLGV, sum(GIAOVIEN.LUONG) as luong
from GIAOVIEN

--Q28. Cho biết số lượng giáo viên và lương trun bình của từng bộ môn
select bm.MABM, count(*) SLGV, AVG(gv.LUONG) LuongTB
from GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM
group by bm.MABM

--Q29. Cho biết tên chủ đề và số lượng đề tài thuộc về chủ đề đó
select cd.TENCD, count(cd.TENCD) as SLDT
from CHUDE cd join DETAI dt on cd.MACD = dt.MACD
group by cd.TENCD

--Q30. Cho biết tên giáo viên và số lượng đề tài giáo viên đó tham gia
select gv.HOTEN, count(distinct tg.MADT) as SLDT
from GIAOVIEN gv join THAMGIADT tg on gv.MAGV = tg.MAGV
group by gv.HOTEN

--Q31. Cho biết tên giáo viên và số lượng đề tài giáo viên đó làm chủ nhiệm
select gv.HOTEN, count(dt.MADT) as ChuNhiem
from GIAOVIEN gv join DETAI dt on gv.MAGV = dt.GVCNDT
group by gv.HOTEN

--Q32. Với mỗi giáo viên cho biết tên giáo viên và số người thân của giáo viên đó
select gv.HOTEN, count(gv.MAGV) SLNT
from GIAOVIEN gv join NGUOITHAN nt on gv.MAGV = nt.MAGV
group by gv.HOTEN

--Q33. Cho biết tên những giáo viên tham gia từ 3 đề tài trở lên
select gv.HOTEN
from GIAOVIEN gv join THAMGIADT tg on gv.MAGV = tg.MAGV
group by gv.HOTEN
having count(distinct tg.MADT) >= 3

--Q34. Cho biết số lượng giáo viên tham gia vào đề tài Ứng dụng hóa học xanh
select count(distinct gv.MAGV) SLGV
from GIAOVIEN gv join THAMGIADT tg on gv.MAGV = tg.MAGV
				 join DETAI dt on tg.MADT = dt.MADT
where dt.TENDT = N'Ứng dụng hóa học xanh'