use QLHV2222
alter table Class add evaluation nvarchar(50)
create proc tontai
	@classID varchar(20), @kq int output
as
begin
	if(exists(select* from Class where Class.ID = @classID))
		set @kq = 1
	else
		set @kq = 0
end

create proc danhGia
	@classID varchar(20), @evaluation nvarchar(50) output
as
begin
	declare @kq int
	exec tontai @classID,@kq output
	if(@kq = 0)
		print 'Khong ton tai'
	else
	begin
		declare @i int
		select @i = count(*)
		from Student stu, Subject sub,Result res
		where stu.ID = res.StudentID and res.SubjectID = sub.id and res.Mark >= 5 and sub.Name=N'Cơ sở dữ liệu'
		and stu.ClassID = @classID and res.Times >= all(select res2.Times
					  from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID)

		declare @sum int
		select @sum = Class.NumofStude
		from class
		where Class.ID = @classID
		if(@i < @sum/2.0)
			set @evaluation = N'Không đạt'
		else
			set @evaluation = N'Đạt'

		update Class set evaluation = @evaluation where ID = @classID
	end
end


create proc dienHet
as
begin
	declare c cursor for select ID from Class
	open c
	declare @id nchar(10)
	fetch next from c into @id
	while(@@FETCH_STATUS = 0)
	begin
		declare @evaluation nvarchar(50)
		exec danhGia @id, @evaluation output
		fetch next from c into @id
	end

	close c
	deallocate c
end
exec dienHet

