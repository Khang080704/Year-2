use QLHV2222
create proc tinhTrungBinh
	@studentID nchar(20), @dtb float output
as
begin
	select @dtb = sum(res.Mark * sub.Credits)/sum(sub.Credits)
	from Subject sub, Result res, Student stu
	where sub.ID = res.SubjectID and res.StudentID = stu.ID and stu.ID = @studentID
	and res.Times >= all(select res2.Times
					  from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID)

end

create proc Bai4
	@studentID nchar(20)
as
begin
	declare @ten nvarchar(50)
	select @ten = Student.Name from Student where Student.ID = @studentID
	--ho ten
	print 'Ho ten: '+@ten
	--dtb:
	declare @dtb float
	exec tinhTrungBinh @studentID,@dtb output
	print 'Diem trung binh: '+cast(round(@dtb,2) as varchar(10))
	if(@dtb >= 8)
		print 'Xep loai: Gioi'
	else
	begin
		if(@dtb >= 7)
			print 'Xep loai: Kha'
		else
			print 'Xeo loai: Trung binh'
	end
	print 'Ket qua hoc tap: '
	declare c cursor for
	(select sub.Name, sub.Credits, res.Mark
	from Student stu, Subject sub, Result res
	where stu.ID = res.StudentID and res.SubjectID = sub.ID and stu.ID = @studentID and res.Mark is not null
	and res.Times >= all(select res2.Times
					  from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID))

	declare @i int
	set @i = 1
	declare @tenmonhoc nchar(50)
	declare @sotinchi int
	declare @diem float
	open c
	fetch next from c into @tenmonhoc,@sotinchi,@diem
	while(@@FETCH_STATUS = 0)
	begin
		print'STT: '+cast(@i as varchar(10))+'. Ten mon hoc: '+@tenmonhoc
		+'. STC: '+cast(@sotinchi as varchar(4))+'. Diem: '+cast(@diem as varchar(4))
		set @i =@i + 1
		fetch next from c into @tenmonhoc,@sotinchi,@diem
	end

	close c
	deallocate c

end

exec Bai4 'HV000003'