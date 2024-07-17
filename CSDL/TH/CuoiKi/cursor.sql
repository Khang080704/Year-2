use QLHV2222
create proc studentlist
	@classID varchar(50)
as
begin
	declare @beginYear int
	declare @EndYear int
	select @beginYear = Class.BeginYear, @EndYear = Class.EndYear
	from Class where Class.ID = @classID
	print 'Class ID: '+ @classID + ' Begin year: '+cast(@beginYear as varchar(20))+' End year: '+cast(@EndYear as varchar(20))

	declare c cursor for
	(select Student.ID, Student.Birthday, Student.Name
	from Student
	where ClassID = @classID)

	open c

	declare @ID nchar(10)
	declare @birthDay datetime
	declare @name nvarchar(50)
	
	fetch next from c into @ID, @birthDay, @name
	declare @i int
	set @i = 1
	while(@@FETCH_STATUS = 0)
	begin
		print cast(@i as varchar(10))+'. Name: '+cast(@name as nvarchar(50))
		+ '. ID: '+cast(@ID as varchar(50))

		fetch next from c into @ID, @birthDay, @name
		set @i = @i + 1
	end

	set @i = @i - 1
	print 'Total: '+cast(@i as varchar(20))+' students'
	close c
	deallocate c
end
exec studentlist 'LH000005'

create proc subjectList
	@studentID nchar(10)
as
begin
	declare d cursor for
	(select sub.Name, sub.Credits, res.Mark
	from Student stu, Result res, Subject sub
	where stu.ID =@studentID and stu.ID = res.StudentID and res.SubjectID = sub.ID
	and res.Mark >= 5 and res.Times >= all(select res2.Times
					  from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID))
	open d

	declare @subName nvarchar(50)
	declare @credits int
	declare @mark float
	declare @i int
	set @i = 1
	fetch next from d into @subName, @credits ,@mark

	while(@@FETCH_STATUS = 0)
	begin
		print cast(@i as varchar(3))+'. Name: '+@subName+'. Credits: '+cast(@credits as varchar(3))
		+'. Mark: '+cast(@mark as varchar(10))
		set @i = @i +1
		fetch next from d into @subName, @credits ,@mark
	end
	close d
	deallocate d
end

exec subjectList 'HV000002'

create proc subList
	@studentID varchar(50)
as
begin
	declare d cursor for
	(select sub.Name, res.Mark
	from Result res, Subject sub, Student stu
	where stu.ID = @studentID and stu.ID = res.StudentID and res.SubjectID = sub.ID
	and res.Mark >= 5 and res.Times >=all(select res2.Times
					  from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID))

	open d
	declare @name nvarchar(50)
	declare @mark float
	fetch next from d into @name, @mark
	while(@@FETCH_STATUS = 0)
	begin
		print'SubName: '+@name+'. Mark: '+cast(@mark as varchar(10))
		fetch next from d into @name, @mark
	end

	close d
	deallocate d
end

create proc stuList
	@classID  varchar(50)
as
begin
	declare @beginYear int
	declare @endYear int
	select @beginYear = Class.BeginYear, @endYear = Class.EndYear
	from Class
	where Class.ID = @classID

	print 'Class ID: '+ @classID + ' Begin year: '+cast(@beginYear as varchar(20))
	+' End year: '+cast(@EndYear as varchar(20))

	declare c cursor for
	(select Student.ID,Student.Name, Student.Birthday
	from Student
	where Student.ClassID = @classID)
	open c
	declare @stuID varchar(50)
	declare @name nvarchar(50)
	declare @birth datetime
	declare @i int
	set @i = 1
	fetch next from c into @stuID,@name,@birth
	while(@@FETCH_STATUS = 0)
	begin
		print cast(@i as varchar(10))+'. Name: '+cast(@name as nvarchar(50))
		+ '. ID: '+cast(@stuID as varchar(50))+'. BirthDay: '+cast(@birth as varchar(50))
		print '-Passed subject:'
		exec subjectList @stuID

		fetch next from c into @stuID,@name,@birth
		set @i = @i + 1
	end
	set @i = @i - 1
	print 'Total: '+cast(@i as varchar(10))


	close c
	deallocate c
end
exec stuList 'LH000002  '

--print the student of class ID
create proc Average
	@studentID nvarchar(30), @mark float output
as
begin
	select @mark = sum(sub.Credits * res.Mark)/sum(sub.Credits)
	from Student stu, Result res, Subject sub
	where stu.ID = @studentID and stu.ID = res.StudentID and sub.ID = res.SubjectID
	and res.Mark >= 5 and res.Times >= all(select res2.Times
					  from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID)
end

create proc ABC
	@classID varchar(20)
as
begin
	declare @managerid varchar(20)
	declare @managername nvarchar(50)
	select @managerid = Class.ManagerID, @managername = Teacher.Name
	from Class, Teacher
	where Class.ID = @classID and Class.ManagerID = Teacher.ID
	print 'ClassID: '+@classID+' MangerID: '+@managerid+' ManagerName: '+@managername
	declare c cursor for
	(select stu.ID, stu.Name
	from Student stu
	where stu.ClassID = @classID)
	
	open c
	declare @ID varchar(20)
	declare @name nvarchar(50)
	declare @i int
	set @i = 1
	fetch next from c into @ID,@name
	while(@@FETCH_STATUS = 0)
	begin
		declare @average float
		exec Average @ID, @average output
		print cast(@i as varchar(4))+'.'+@ID+'   '+@name+cast(@average as varchar(10))
		set @i = @i +1
		fetch next from c into @ID,@name
	end

	close c
	deallocate c
end
exec ABC 'LH000003'