use QLDeTai
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
--   quản lý để ký hiệu “-”) của các giáo viên có tham gia đề tài được chủ nhiệm bởi giáo --   viên khác bộ môn.select distinct dt.MADT,gv.MAGV, gv.HOTEN, ISNULL(cndt.MAGV,'-') as gvcndt, cndt.HOTENfrom GIAOVIEN gv join THAMGIADT tg on gv.MAGV = tg.MAGV				 join CONGVIEC cv on cv.MADT = tg.MADT and cv.SOTT = tg.STT				 join DETAI dt on dt.MADT = cv.MADT				 join GIAOVIEN cndt on cndt.MAGV = dt.GVCNDTwhere gv.MABM != cndt.MABM--6. Xuất mã, họ tên giáo viên và tổng số lượng giáo viên mà họ quản lý chuyên môn (nếu --   không quản lý ai, giá trị xuất ra là 0).select gv.MAGV, gv.HOTEN, count(qlcm.GVQLCM) SLGV	from GIAOVIEN gv join GIAOVIEN qlcm on gv.MAGV = qlcm.GVQLCMgroup by qlcm.GVQLCM, gv.MAGV, gv.HOTEN--7. Xuất mã, họ tên giáo viên, tên khoa mà giáo viên thuộc về của các giáo viên từng chủ--   nhiệm trên 2 đề tài có kinh phí >= 100 triệuselect gv.MAGV, gv.HOTEN, KHOA.TENKHOAfrom GIAOVIEN gv join DETAI dt on gv.MAGV = dt.GVCNDT				 join BOMON bm on gv.MABM = bm.MABM				 join KHOA on bm.MAKHOA = khoa.MAKHOAwhere dt.KINHPHI >= 100group by gv.MAGV, gv.HOTEN, khoa.TENKHOAhaving count(gv.MAGV) >= 2 --8. Xuất mã, tên đề tài, tên và STT công việc có đông giáo viên tham gia nhất.select dt.MADT, dt.TENDT, cv.TENCV, cv.SOTTfrom DETAI dt join CONGVIEC cv on dt.MADT = cv.MADT			  join THAMGIADT tg on tg.MADT = cv.MADT and tg.STT = cv.SOTTgroup by dt.MADT, dt.TENDT, cv.TENCV,cv.SOTThaving count(tg.MAGV)>= all(select count(tg2.MAGV)						   from DETAI dt2 join CONGVIEC cv2 on dt2.MADT = cv2.MADT										 join THAMGIADT tg2 on tg2.MADT = cv2.MADT and tg2.STT = cv2.SOTT						   group by dt2.MADT, dt2.TENDT, cv2.TENCV, cv2.SOTT							)order by dt.MADT, cv.SOTT--9. Xuất mã và họ tên giáo viên có lương lớn nhất ở từng khoa theo các yêu cầu sau:--  Cách 1: Có dùng lượng từ ALL hoặc hàm kết hợp MAX.select gv.MAGV, gv.HOTEN, KHOA.TENKHOAfrom GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM				 join KHOA on bm.MAKHOA = khoa.MAKHOAgroup by gv.MAGV,gv.HOTEN, khoa.TENKHOA, gv.LUONG, khoa.MAKHOAhaving (gv.LUONG >= all (select gv2.LUONG						from GIAOVIEN gv2 join BOMON bm2 on gv2.MABM = bm2.MABM										 join KHOA k2 on bm2.MAKHOA = k2.MAKHOA						where khoa.MAKHOA = k2.MAKHOA						group by gv2.LUONG))order by KHOA.TENKHOA, gv.MAGV-- Cách 2: Cách 2: Không dùng bất cứ lượng từ hay hàm kết hợp nào.select gv.MAGV, gv.HOTEN, KHOA.TENKHOAfrom GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM				 join KHOA on bm.MAKHOA = khoa.MAKHOAgroup by khoa.MAKHOA, gv.MAGV, gv.HOTEN, khoa.TENKHOAhaving gv.MAGV = (select top 1 gv2.MAGV				  from GIAOVIEN gv2 join BOMON bm2 on gv2.MABM = bm2.MABM									join KHOA k2 on bm2.MAKHOA = k2.MAKHOA				  where khoa.MAKHOA = k2.MAKHOA				  group by k2.MAKHOA, gv2.MAGV, gv2.LUONG				  order by gv2.LUONG desc)order by KHOA.TENKHOA, gv.MAGV--10. Xuất mã và tên khoa có đông giáo viên từng chủ nhiệm đề tài nhất.select khoa.MAKHOA, khoa.TENKHOAfrom GIAOVIEN gv join DETAI dt on dt.GVCNDT = gv.MAGV				 join BOMON bm on gv.MABM = bm.MABM				 join khoa on khoa.MAKHOA = bm.MAKHOAgroup by khoa.MAKHOA, khoa.TENKHOAhaving count(dt.GVCNDT) >= all(select count(dt2.GVCNDT)							   from GIAOVIEN gv2 join DETAI dt2 on dt2.GVCNDT = gv2.MAGV												join BOMON bm2 on gv2.MABM = bm2.MABM												join khoa k2 on k2.MAKHOA = bm2.MAKHOA								group by k2.MAKHOA)--11. Xuất mã và tên bộ môn có nhiều giáo viên có quản lý chuyên môn nhất.select bm.MABM, bm.TENBMfrom GIAOVIEN gv join GIAOVIEN gvqlcm on gv.GVQLCM = gvqlcm.MAGV				 join BOMON bm on gvqlcm.MABM = bm.MABMgroup by bm.MABM, bm.TENBMhaving count(gvqlcm.MAGV) >= all(select count(gvqlcm2.MAGV)								 from GIAOVIEN gv2 join GIAOVIEN gvqlcm2 on gv2.GVQLCM = gvqlcm2.MAGV												 join BOMON bm2 on gvqlcm2.MABM = bm2.MABM								 group by bm2.MABM)--12. Xuất mã, họ tên giáo viên và tổng tiền phụ cấp mà giáo viên nhận được theo từng năm. --    Biết rằng tiền phụ cấp được tính từ hệ số phụ cấp cho các công việc mà giáo viên tham --    gia trong năm đó (có ngày kết thúc trong năm đang xét) với các quy định như sau:--		+ Kết quả “Đạt”, Phụ cấp = Hệ số * Lương tháng--		+ Còn lại, Phụ cấp = Hệ số * (1/2 Lương tháng).select gv.magv, gv.hoten, isnull(year(T.NGAYKT), 0) as nam, isnull(sum(T.PHUCAP), 0) as sl_cv
from giaovien gv left join (select tg.magv, tg.madt, tg.stt, tg.ketqua, cv.ngaykt,
                                                  case 
                                                       when tg.ketqua = N'Đạt' then tg.phucap * gv.luong
                                                       when tg.ketqua is null then 0
                                                  else (tg.phucap * gv.luong)/2
                                             end as PHUCAP
                            from thamgiadt tg join congviec cv on cv.madt = tg.madt and tg.stt = cv.SOTT
                                              join giaovien gv on tg.magv = gv.magv) T on gv.magv = T.magv
group by gv.magv, gv.hoten, year(T.ngaykt)
order by gv.magv, year(T.NGAYKT)--13. Xuất mã và họ tên giáo viên thuộc khoa “Công nghệ thông tin” có tham gia tất cả đề tài
--	  thuộc cấp ĐHQG.select gv.MAGV, gv.HOTENfrom GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM				 join KHOA k on k.MAKHOA = bm.MAKHOA and bm.MAKHOA = 'CNTT'				 join THAMGIADT tg on tg.MAGV = gv.MAGV				 join CONGVIEC cv on cv.MADT = tg.MADT and cv.SOTT = tg.STT				 join DETAI dt on cv.MADT = dt.MADTwhere dt.CAPQL = N'ĐHQG'group by gv.MAGV, gv.HOTENhaving count(distinct dt.MADT) = (select count(DETAI.MADT) as DHQG						 from DETAI where DETAI.CAPQL = N'ĐHQG')--14. Xuất mã, họ tên giáo viên thuộc bộ môn “Mạng máy tính” tham gia tất cả công việc--    liên quan đến đề tài thuộc chủ đề “ứng dụng”.select gv.MAGV, gv.HOTENfrom GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM and bm.MABM = 'MMT'				 join THAMGIADT tg on tg.MAGV = gv.MAGV				 join CONGVIEC cv on cv.MADT = tg.MADT and cv.SOTT = tg.STT				 join DETAI dt on dt.MADT = cv.MADT				 join CHUDE cd on dt.MACD = cd.MACDwhere cd.MACD = N'ƯDCN'group by gv.MAGV, gv.HOTENhaving count(cv.SOTT) = (select count(cv2.SOTT) soCv						 from CONGVIEC cv2 join DETAI dt2 on cv2.MADT = dt2.MADT										   join CHUDE cd2 on cd2.MACD = dt2.MACD						 where cd2.MACD = N'ƯDCN'						 group by dt2.MADT)--15. Xuất mã, họ tên trưởng khoa có các đề tài từng chủ nhiệm bao phủ tất cả các chủ đềselect gv.MAGV, gv.HOTEN, count(gv.MAGV) as SLDTfrom GIAOVIEN gv join KHOA k on gv.MAGV = k.TRUONGKHOA				 join DETAI dt on dt.GVCNDT = gv.MAGVgroup by gv.MAGV, gv.HOTENhaving count(gv.MAGV) = (select count(*)						 from CHUDE)--16. Xuất mã, họ tên trưởng bộ môn có các đề tài từng tham gia liên quan đến tất cả các cấp./*tìm tất cả T trong R thỏa mãn S -> tìm tất cả trưởng bm trong thamgia detai thỏa mãn có liên quanđến tất cả các cấpT: Thương GV(magv)S: Chia detai(madetai) co chứa tất cả các cấpR: Bị chia Thamgiadetai(magv,madt)*/select T.MAGV, T.HOTEN, count(S.CAPQL)from THAMGIADT R join GIAOVIEN T on R.MAGV = T.MAGV				 join DETAI S on R.MADT = S.MADT 				 join BOMON bm on T.MAGV = bm.TRUONGBMgroup by T.MAGV, T.HOTENhaving count(S.CAPQL) = (select count(distinct dt2.CAPQL) sldt						 from DETAI dt2						 )--17.Xuất mã, tên chủ đề có đề tài có tất cả giáo viên có mã tận cùng là số chẵn tham gia.select cd.MACD, cd.TENCDfrom THAMGIADT tg join GIAOVIEN gv on tg.MAGV = gv.MAGV				  join CONGVIEC cv on tg.MADT = cv.MADT and tg.STT = cv.SOTT				  join DETAI dt on cv.MADT = dt.MADT				  join CHUDE cd on dt.MACD = cd.MACDwhere cast(SUBSTRING(gv.MAGV, len(gv.MAGV),1) as int) % 2 = 0group by cd.MACD,cd.TENCDhaving count(distinct gv.MAGV) = (select count(*)								  from GIAOVIEN gv2								  where cast(SUBSTRING(gv2.MAGV, len(gv2.MAGV),1) as int) % 2 = 0)--18. Xuất mã, tên đề tài, tên công việc có tất cả giáo viên có lương 2000-3000 tham giaselect dt.MADT, dt.TENDT, cv.TENCVfrom DETAI dt join CONGVIEC cv on dt.MADT = cv.MADT 			  join THAMGIADT tg on cv.MADT = tg.MADT and cv.SOTT = tg.STT			  join GIAOVIEN gv on gv.MAGV = tg.MAGVwhere gv.LUONG between 2000 and 3000group by dt.MADT,cv.TENCV, dt.TENDThaving count(cv.SOTT ) = (select count(*)						  from GIAOVIEN gv2						  where gv2.LUONG between 2000 and 3000)order by dt.MADT				 


