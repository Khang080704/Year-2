use QLHV2222
--Cau 1:them 1 cot evaluation vao bang student: evaluation nvarchar(50)
alter table Student add evaluation nvarchar(50)
--Cau 2
create proc Step1
	@StudentID varchar(50), @result int output
as
begin
	declare @i int
	set @i = 0
	select @i = count(*)
	from Student
	where Student.ID = @StudentID
	if(@i != 0)
		set @result = 1
	else
		set @result = 0
end

create proc FillInEvaluation
	@StudentID varchar(30), @evaluation nvarchar(50) output
as
begin
	declare @kq int
	exec Step1 @StudentID, @kq output
	if(@kq = 1)
	begin
		declare @tinchi int
		select @tinchi = sum(sub.Credits)
		from Student stu, Result res, Subject sub
		where stu.ID = @StudentID and stu.ID = res.StudentID and sub.ID = res.SubjectID
		and res.Mark >=5 and res.Times >= all(select res2.Times
					  from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID)

		if(@tinchi < 20)
			set @evaluation = N'Không đạt'
		else
		begin
			declare @mark float
			select @mark = res.Mark
			from Student stu, Result res, Subject sub
			where stu.ID = @StudentID and stu.ID = res.StudentID and sub.ID = res.SubjectID
			and res.Mark >=5 and sub.Name = N'Cơ sở dữ liệu' and res.Times >= all(select res2.Times
												from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID)
			if(@mark > 8)
				set @evaluation = N'Giỏi'
			else
				set @evaluation = N'Khá'
		end
		update Student set evaluation = @evaluation where ID = @StudentID
		print @evaluation
	end
	else
		return
end
--drop proc FillInEvaluation
declare @eva nvarchar(50)
exec FillInEvaluation 'HV000004',@eva output

create proc fillAll
as
begin
	declare @stuID varchar(20)
	declare c cursor for
	(select ID from Student)
	declare @kq nvarchar(50)

	open c
	fetch next from c into @stuID
	while(@@FETCH_STATUS = 0)
	begin
		exec FillInEvaluation @stuID, @kq
		fetch next from c into @stuID
	end
	close c
	deallocate c
end
exec fillAll

