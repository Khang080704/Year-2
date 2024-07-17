use QLHV2222
--Cau 1
select tea.*
from Teacher tea, Ability ab, Subject sub
where tea.ID = ab.TeacherID and ab.SubjectID = sub.ID
and sub.Credits = 4

--Cau 2
create proc Cau2
	@stuID varchar(20), @kq nvarchar(20) output
as
begin
	declare @a int
	select @a = count(*)
	from Class c, Student stu, Course
	where c.ID = stu.ClassID and stu.ID = @stuID
	and c.ID = Course.ClassID

	declare @b int
	select @b = count(*)
	from Class c, Student stu, Course, Result res, Subject sub
	where stu.ID = @stuID and c.ID = stu.ClassID and res.StudentID = stu.ID and Course.ClassID = c.ID
	and Course.SubjectID = sub.ID and res.SubjectID = sub.ID
	and res.Mark >= 5 and res.Times >= all(select res2.Times
					  from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID)
	
	if(@b > @a/2.0)
		set @kq = 'Dat'
	else
		set @kq = 'Khong dat'
end

--cau 3
alter table Student add danhgia nvarchar(30)

create proc cau3
	@teacherID varchar(20)
as
begin
	declare @classID varchar(20)
	declare d cursor for(
		select Class.ID
		from Teacher, Class
		where Teacher.ID = Class.ManagerID and Teacher.ID = @teacherID)
	open d
	fetch next from d into @classID
	while(@@FETCH_STATUS = 0)
	begin
		declare c cursor for
		(select Student.ID
		from Student where Student.ClassID = @classID)
		declare @stuID varchar(20)
		open c

		fetch next from c into @stuID
		while(@@FETCH_STATUS = 0)
		begin
			declare @kq varchar(20)
			exec Cau2 @stuID, @kq output
			update Student set danhgia = @kq where ID = @stuID
			fetch next from c into @stuID
		end

		close c
		deallocate c
		fetch next from d into @classID
	end

	close d
	deallocate d

end


exec cau3 'GV000010'

