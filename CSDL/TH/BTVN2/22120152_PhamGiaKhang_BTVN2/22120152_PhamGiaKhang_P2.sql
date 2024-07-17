﻿use QLDeTai
--1. Xuất mã và họ tên giáo viên có tham gia đề tài 
--   do trưởng bộ môn của họ là chủ nhiệm.
select distinct gv.MAGV, gv.HOTEN
from GIAOVIEN gv join THAMGIADT tg on gv.MAGV = tg.MAGV
				 join DETAI dt on dt.MADT = tg.MADT
				 join GIAOVIEN gvcn on gvcn.MAGV = dt.GVCNDT
				 join BOMON bm on bm.TRUONGBM = dt.GVCNDT


--2. Xuất mã, họ tên, và tuổi của các giáo viên đã từng tham gia công việc “thiết kế” hoặc
--   đã từng chủ nhiệm đề tài có công việc liên quan đến “xác định yêu cầu”.
-- Giaovien, congviec, thamgiadetai
select gv.MAGV, gv.HOTEN, DATEDIFF(yy,gv.NGSINH,GETDATE()) as Tuổi
from GIAOVIEN gv join THAMGIADT tgdt on gv.MAGV = tgdt.MAGV
				 join CONGVIEC cv on tgdt.MADT = cv.MADT and cv.SOTT = tgdt.STT
where cv.TENCV like N'%thiết kế%'
union
select gv.MAGV, gv.HOTEN, DATEDIFF(yy,gv.NGSINH,GETDATE()) as Tuổi
from GIAOVIEN gv join DETAI dt on dt.GVCNDT = gv.MAGV
				 join CONGVIEC cv on dt.MADT = cv.MADT and cv.TENCV like N'%xác định yêu cầu'


--3. Xuất mã và họ tên các trưởng khoa có tham gia đề tài thuộc chủ đề “nghiên cứu” nhưng
--   chưa từng tham gia đề tài nào thuộc chủ đề “ứng dụng”
-- giaovien, khoa
select gv.MAGV, gv.HOTEN
from GIAOVIEN gv join KHOA on gv.MAGV = KHOA.TRUONGKHOA
				 join THAMGIADT tg on tg.MAGV = gv.MAGV
				 join CONGVIEC cv on tg.MADT = cv.MADT and tg.STT = cv.SOTT
				 join DETAI dt on cv.MADT = dt.MADT
				 join CHUDE cd on cd.MACD = dt.MACD and cd.TENCD like N'%nghiên cứu%'
except
select gv.MAGV, gv.HOTEN
from GIAOVIEN gv join KHOA on gv.MAGV = KHOA.TRUONGKHOA
				 join THAMGIADT tg on tg.MAGV = gv.MAGV
				 join CONGVIEC cv on tg.MADT = cv.MADT and tg.STT = cv.SOTT
				 join DETAI dt on cv.MADT = dt.MADT
				 join CHUDE cd on cd.MACD = dt.MACD and cd.TENCD like N'%ứng dụng%'

--4. Xuất mã, tên chủ đề, cấp quản lý (capql) và số lượng đề tài có kinh phí từ 100 triệu trở
--   lên theo từng cấp quản lý của mỗi chủ đề.
select  cd.MACD, cd.TENCD, dt.CAPQL, count(dt.MADT) SLDT
from CHUDE cd join DETAI dt on cd.MACD = dt.MACD
where dt.KINHPHI >= 100
group by cd.MACD,cd.TENCD,dt.CAPQL


--5. Xuất mã, họ tên giáo viên, họ tên quản lý chuyên môn của giáo viên (nếu không có 
--   quản lý để ký hiệu “-”) của các giáo viên có tham gia đề tài được chủ nhiệm bởi giáo 
from giaovien gv left join (select tg.magv, tg.madt, tg.stt, tg.ketqua, cv.ngaykt,
                                                  case 
                                                       when tg.ketqua = N'Đạt' then tg.phucap * gv.luong
                                                       when tg.ketqua is null then 0
                                                  else (tg.phucap * gv.luong)/2
                                             end as PHUCAP
                            from thamgiadt tg join congviec cv on cv.madt = tg.madt and tg.stt = cv.SOTT
                                              join giaovien gv on tg.magv = gv.magv) T on gv.magv = T.magv
group by gv.magv, gv.hoten, year(T.ngaykt)
order by gv.magv, year(T.NGAYKT)
--	  thuộc cấp ĐHQG.

