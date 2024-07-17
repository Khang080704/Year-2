use QLHV2222
create proc isPrime
	@in int
as
begin
	declare @i int
	set @i = 1
	while(@i < @in)
	begin
		if(@in % @i = 0)
		print cast(@in as nchar(10)) + 'khong phai so nguyen to'
		break
	end
	print cast(@in as nchar(10)) + 'la so nguyen to'
end
alter proc isPrime
	@in int, @kq int output
as
begin
	if(@in = 1)
	begin
		set @kq = 0
		return
	end
	declare @i int
	set @i = 2
	while(@i < @in)
	begin
		if(@in % @i = 0)
		begin
			set @kq = 0
			return
		end
		set @i = @i + 1
	end
	set @kq = 1
end

alter proc tongNguyenTo
	@n int
as
begin
	declare @i int
	set @i = 1
	declare @sum int
	set @sum = 0
	while(@i <= @n)
	begin
		declare @kq int
		exec isPrime @i, @kq output
		if(@kq = 1)
		begin
			set @sum = @sum + @i
		end
		set @i = @i + 1
	end
	print cast(@sum as varchar(10))
end
exec tongNguyenTo 9

alter proc getTeacherName
	@TeacherID nchar(10)
as
begin
	declare @name nvarchar(50)
	select @name = Teacher.Name
	from Teacher
	where Teacher.ID = @TeacherID
	print @name
end
exec getTeacherName 'GV00006'

alter proc tinhgiaithua
	@n int, @f int output
as
begin
	declare @i int
	set @i = 1
	while(@i <= @n)
	begin
		set @f = @f * @i
		set @i = @i + 1
	end
end

alter proc cauC
	@n int
as
begin
	declare @sum int
	set @sum = 0
	declare @i int
	set @i = 1
	while(@i <= @n)
	begin
		declare @out int
		exec tinhgiaithua @i, @out output
		set @sum = @sum + @out
		set @i = @i + 1
	end
	print 'Ket qua la: '+ cast(@sum as varchar(20))
end
exec cauC 6


create proc pass
	@subjectName nvarchar(50)
as
begin
	
	select stu.*
	from Subject sub, Student stu, Result res
	where sub.ID = res.SubjectID and stu.ID = res.StudentID and res.Mark >= 5
	and sub.Name = @subjectName
	and res.Times >= all(select res2.Times
					  from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID)
end
exec pass N'Phân tích thiết kế hệ thống thông tin'

create proc getAverage
	@studentName nvarchar(50), @kq float output
as
begin
	select @kq = sum(res.Mark * sub.Credits)/sum(sub.Credits)
	from Student stu, Result res, Subject sub
	where stu.ID = res.StudentID and sub.ID = res.SubjectID and stu.Name = @studentName
	and res.Mark >=5 and res.Times >= all(select res2.Times
					  from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID)
	print cast(@kq as varchar(20))
end
declare @mark float
exec getAverage N'Nguyễn Thị Kiề Trinh',@mark output