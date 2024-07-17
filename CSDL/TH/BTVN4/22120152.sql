use QLDT1

--1.Cho biết tên những giáo viên khoa CNTT chưa bao giờ tham gia đề tài thuộc chủ đề "Quản lý giáo dục"
select gv.HOTEN
from GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM
				 join KHOA k on bm.MAKHOA = k.MAKHOA
				 join THAMGIADT tgdt on gv.MAGV = tgdt.MAGV
				 join DETAI dt on dt.MADT = tgdt.MADT
				 join CHUDE cd on dt.MACD = dt.MACD
where k.MAKHOA = 'CNTT' and cd.MACD = 'QLGD'
group by gv.HOTEN
having not exists (select CHUDE.MACD
				   from CHUDE
				   where CHUDE.MACD = 'QLGD')

--2. Tìm tên trưởng bm không thuộc khoa CNTT đã tham gia đề tài "Thành Phố Thông Minh"
select gv.HOTEN
from GIAOVIEN gv join BOMON bm on gv.MAGV = bm.TRUONGBM
				 join KHOA k on bm.MAKHOA = k.MAKHOA
				 join THAMGIADT tgdt on gv.MAGV = tgdt.MAGV
				 join DETAI dt on tgdt.MADT = dt.MADT
where dt.TENDT = N'Thành phố thông minh'
and gv.MAGV not in(select trgbm.MAGV
				   from GIAOVIEN trgbm join BOMON bm1 on trgbm.MAGV = bm1.TRUONGBM
										join KHOA k1 on k1.MAKHOA = bm1.MAKHOA
					where k1.MAKHOA = 'CNTT')


--3.Trong các giáo viên của bộ môn Hệ thống thống tin, gv nào (magv) có lương lớn nhất
select gv.MAGV
from GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM
where bm.MABM = 'HTTT'
group by gv.MAGV
having max(gv.LUONG) = (select max(gv2.LUONG)
						from GIAOVIEN gv2 join BOMON bm2 on gv2.MABM = bm2.MABM
						where bm2.MABM = 'HTTT')

--4. Với mỗi giáo viên (magv, hoten) khoa công nghệ thông tin,
-- cho biết số lượng đề tài do trưởng khoa CNTT chủ nhiệm mà gv đó tham gia.
select gv.MAGV, gv.HOTEN, count(distinct tg.MADT) as SLDT
from GIAOVIEN gv join THAMGIADT tg on gv.MAGV = tg.MAGV
				 join BOMON bm on gv.MABM = bm.MABM
				 join KHOA k on bm.MAKHOA = k.MAKHOA
				 join DETAI dt on tg.MADT = dt.MADT
				 --Lay ra bang giao vien chu nhiem de tai la truong khoa cntt
				 join(select distinct gvcn.MAGV
					  from GIAOVIEN gvcn join DETAI cndt on gvcn.MAGV = cndt.GVCNDT
										 join KHOA truongkhoa on gvcn.MAGV = truongkhoa.TRUONGKHOA
					  where truongkhoa.MAKHOA = 'CNTT') as cn on dt.GVCNDT = cn.MAGV
where k.MAKHOA = 'CNTT'
group by gv.MAGV, gv.HOTEN

--5. Cho biết giáo viên (magv, hoten) nào của khoa công nghệ thông tin 
-- tham gia nhiều đề tài do trưởng khoa CNTT chủ nhiệm nhất
select gv.MAGV, gv.HOTEN, count(distinct tgdt.MADT) as SLDT
from GIAOVIEN gv join THAMGIADT tgdt on gv.MAGV = tgdt.MAGV
			     join BOMON bm on gv.MABM = bm.MABM
				 join KHOA k on bm.MAKHOA = k.MAKHOA
				 join DETAI dt on tgdt.MADT = dt.MADT
				 
				 join(select distinct gvcn.MAGV
					  from GIAOVIEN gvcn join DETAI cndt on gvcn.MAGV = cndt.GVCNDT
										 join KHOA truongkhoa on gvcn.MAGV = truongkhoa.TRUONGKHOA
					  where truongkhoa.MAKHOA = 'CNTT') as cn on dt.GVCNDT = cn.MAGV
where k.MAKHOA = 'CNTT'
group by gv.MAGV, gv.HOTEN
having count(distinct tgdt.MADT) >= all(select count(distinct tgdt1.MADT)
										from GIAOVIEN gv1 join THAMGIADT tgdt1 on gv1.MAGV = tgdt1.MAGV
														  join BOMON bm1 on gv1.MABM = bm1.MABM
														  join KHOA k1 on bm1.MAKHOA = k1.MAKHOA
														  join DETAI dt1 on tgdt1.MADT = dt1.MADT
				 
														  join(select distinct gvcn1.MAGV
															   from GIAOVIEN gvcn1 join DETAI cndt1 on gvcn1.MAGV = cndt1.GVCNDT
																				   join KHOA truongkhoa1 on gvcn1.MAGV = truongkhoa1.TRUONGKHOA
															   where truongkhoa1.MAKHOA = 'CNTT') as cn1 on dt1.GVCNDT = cn1.MAGV
										where k1.MAKHOA = 'CNTT'			 
										group by gv1.MAGV, gv1.HOTEN)

--6. Cho biết mã giáo viên vừa lớn tuổi nhất trong 
-- bộ môn của mình vừa có lương lớn nhất trong bộ môn của mình
select gv.MAGV
from GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM
group by gv.MAGV, gv.LUONG, bm.MABM, gv.NGSINH
having gv.LUONG >= all(select gv2.LUONG
				       from GIAOVIEN gv2 join BOMON bm2 on gv2.MABM = bm2.MABM
					   where bm2.MABM = bm.MABM)
	   and (2024 - Year(gv.NGSINH)) >= all (select (2024 - year(gv3.NGSINH))
											from GIAOVIEN gv3 join BOMON bm3 on gv3.MABM = bm3.MABM
											where bm3.MABM = bm.MABM)

--7. Cho biết mã giáo viên mà đã từng tham gia đề tài do trưởng khoa của mình chủ nhiệm
select distinct gv.MAGV
from GIAOVIEN gv join THAMGIADT tg on gv.MAGV = tg.MAGV
				 join DETAI dt on dt.MADT = tg.MADT
				 join BOMON bm on gv.MABM = bm.MABM
				 join khoa k on k.MAKHOA = bm.MAKHOA
				 --Lay ra bang gvcndt la truong khoa
				 join (select distinct gvcn.*
					   from GIAOVIEN gvcn join DETAI cndt on gvcn.MAGV = cndt.GVCNDT
										  join KHOA trgkhoa on gvcn.MAGV = trgkhoa.TRUONGKHOA
					   )as Trgkhoacndt on dt.GVCNDT = Trgkhoacndt.MAGV and gv.MAGV != Trgkhoacndt.MAGV

--8. Cho biết giáo viên (magv, hoten) nào của khoa công nghệ thông tin 
-- tham gia tất cả các đề tài do trưởng khoa CNTT nhất
select gv.MAGV,gv.HOTEN
from GIAOVIEN gv join THAMGIADT tgdt on gv.MAGV = tgdt.MAGV
				 join BOMON bm on bm.MABM = gv.MABM
				 join KHOA k on k.MAKHOA = bm.MAKHOA
where k.MAKHOA = 'CNTT'
group by gv.MAGV, gv.HOTEN
having count(distinct tgdt.MADT) = (select count(cndt.MADT)
									from GIAOVIEN trgkhoa join KHOA k2 on trgkhoa.MAGV = k2.TRUONGKHOA
														  join DETAI cndt on trgkhoa.MAGV = cndt.GVCNDT
									where k2.MAKHOA = 'CNTT'
									group by trgkhoa.MAGV)

--9. Cho biết tuổi trung bình của các giáo viên không bao giờ tham gia đề tài 
-- thuộc chủ đề quản lý giáo dục và không được quản lý bởi Nguyễn Văn An
select avg(2024 - YEAR(gv.NGSINH)) as TuoiTB
from GIAOVIEN gv join THAMGIADT tgdt on gv.MAGV = tgdt.MAGV
				 join DETAI dt on dt.MADT = tgdt.MADT
				 join CHUDE cd on cd.MACD = dt.MACD
				 join GIAOVIEN gvql on gvql.MAGV = gv.GVQLCM
where gvql.HOTEN != N'Nguyễn Văn A'
group by gv.MAGV
having gv.MAGV not in (select gv1.MAGV
						   from GIAOVIEN gv1 join THAMGIADT tg on gv1.MAGV = tg.MAGV
											 join DETAI dt1 on dt1.MADT = tg.MADT
											 join CHUDE cd1 on cd1.MACD = dt1.MACD
							where cd1.MACD = 'QLGD')

--10. Cho biết tên trưởng bm của bm có tất cả giáo viên đều tham gia đề tài

select truongbm.HOTEN 
from GIAOVIEN truongbm join BOMON bm on truongbm.MAGV = bm.TRUONGBM
					   join GIAOVIEN gv on gv.MABM = bm.MABM

group by truongbm.HOTEN, bm.MABM
having count(gv.MABM) = (select count(distinct gvtg.MAGV) as slgv
								from THAMGIADT tg join GIAOVIEN gvtg on tg.MAGV = gvtg.MAGV
												  join BOMON bm1 on gvtg.MABM = bm1.MABM
								where bm.MABM = bm1.MABM
								group by bm1.MABM)

--11. Cho biết giáo viên (mã gv, tên gv) tham gia tất cả đề tài do trưởng BM của mình chủ trì
select gv.MAGV, gv.HOTEN,count(distinct tgdt.MADT) as SLDT, trgbm.MAGV
from GIAOVIEN gv join THAMGIADT tgdt on gv.MAGV = tgdt.MAGV
				 join BOMON bm on bm.MABM = gv.MABM
				 join GIAOVIEN trgbm on trgbm.MAGV = bm.TRUONGBM
				 join DETAI cndt on cndt.GVCNDT = trgbm.MAGV
where cndt.MADT = tgdt.MADT
group by gv.MAGV, gv.HOTEN, trgbm.MAGV
having  count(distinct tgdt.MADT) = (select count(dt.MADT) as SLDT
									 from DETAI dt 
									 where dt.GVCNDT = trgbm.MAGV)
--12. Cho biết giáo viên (mã gv, tên gv) mà tất cả đề tài tham gia đều do trưởng BM của mình chủ trì
select gv.MAGV, gv.HOTEN
from GIAOVIEN gv join THAMGIADT tgdt on gv.MAGV = tgdt.MAGV	 
				 join DETAI dt on tgdt.MADT = dt.MADT

group by gv.MAGV,gv.HOTEN,gv.MABM,dt.GVCNDT
having dt.GVCNDT = (select trgbm.MAGV
				    from GIAOVIEN trgbm join BOMON bm on trgbm.MAGV = bm.TRUONGBM
					where gv.MABM = trgbm.MABM)
