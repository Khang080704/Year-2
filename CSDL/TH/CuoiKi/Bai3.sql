use QLHV2222
create proc Bai3_step1
	@subjectID varchar(20)
as
begin
	declare @i int
	set @i = 0
	select @i = count(*)
	from Student stu, Subject sub, Result res
	where stu.ID = res.StudentID and res.SubjectID = sub.ID and sub.ID = @subjectID
	and res.Mark >= 5 and res.Times >= all(select res2.Times
					  from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID)

	declare @sum int
	select @sum = count(*)
	from Student stu, Subject sub, Result res
	where stu.ID = res.StudentID and res.SubjectID = sub.ID and sub.ID = @subjectID
	and res.Times >= all(select res2.Times
					  from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID)

	if(@i >= @sum/2.0)
	begin
		update Subject set evaluation = N'Đạt' where ID = @subjectID
	end
	else
	begin
		update Subject set evaluation = N'Không Đạt' where ID = @subjectID
	end
end

create proc Bai3_fillall
as
begin
	declare c cursor for select ID from Subject
	open c
	declare @subID varchar(20)
	fetch next from c into @subID
	while(@@FETCH_STATUS = 0)
	begin
		exec Bai3_step1 @subID
		fetch next from c into @subID
	end

	close c
	deallocate c
end

exec Bai3_fillall