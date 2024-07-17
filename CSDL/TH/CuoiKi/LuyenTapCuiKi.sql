use QLDT1
alter table GIAOVIEN add DANHGIA nvarchar(15)

create proc step4
	@ID varchar(20), @kq nvarchar(15) output
as
begin
	declare @SLCV int
	select @SLCV = count(*)
	from GIAOVIEN gv join THAMGIADT tgdt on gv.MAGV = tgdt.MAGV
					 join CONGVIEC cv on tgdt.MADT = cv.MADT and tgdt.STT = cv.SOTT
	where gv.MAGV = @ID

	declare @tong int
	select @tong = count(*)
	from CONGVIEC join DETAI on CONGVIEC.MADT = DETAI.MADT
	where DETAI.MADT in (select THAMGIADT.MADT
					from GIAOVIEN join THAMGIADT on GIAOVIEN.MAGV = THAMGIADT.MAGV
					where GIAOVIEN.MAGV = @ID)
	if(@SLCV = 0 and @tong = 0)
		set @kq = 'Binh thuong'
	else
	begin
		if(@SLCV >= (4.0/5)*@tong)
			set @kq = 'Xuat sac'
		else
			set @kq = 'Binh thuong'
	end
	
end

create proc fillAll
as
begin
	declare c cursor for select MAGV from GIAOVIEN
	open c
	declare @magv varchar(20)
	fetch next from c into @magv
	while(@@FETCH_STATUS = 0)
	begin
		declare @kq nvarchar(15)
		exec step4 @magv, @kq output
		update GIAOVIEN set DANHGIA = @kq where MAGV = @magv
		fetch next from c into @magv
	end
	close c
	deallocate c
end
exec fillAll
select count(cv.SOTT)
	from GIAOVIEN gv join THAMGIADT tgdt on gv.MAGV = tgdt.MAGV
					 join CONGVIEC cv on tgdt.MADT = cv.MADT and tgdt.STT = cv.SOTT
	where gv.MAGV = '005'

select  count(*)
	from CONGVIEC join DETAI on CONGVIEC.MADT = DETAI.MADT
where DETAI.MADT in (select THAMGIADT.MADT
					from GIAOVIEN join THAMGIADT on GIAOVIEN.MAGV = THAMGIADT.MAGV
					where GIAOVIEN.MAGV = '005')