use QLHV2222
create proc Stepa
	@teacherID nchar(10), @result int output
as
begin
	declare @i int
	set @i = 0
	select @i = count(*)
	from Teacher where Teacher.ID = @teacherID
	if(@i = 0)
		set @result = 0
	else
		set @result = 1 
end

create proc Stepb
	@teacherID nchar(10), @evaluation nvarchar(50) output
as
begin
	declare @kq int
	exec Stepa @teacherID, @kq output
	if(@kq =0)
		return
	else --kq != 0
	begin
		declare @sum int
		select @sum = count(Ability.SubjectID)
		from Teacher, Ability
		where Teacher.ID = Ability.TeacherID and Teacher.ID = @teacherID
		if(@sum < 5)
			set @evaluation = N'không đạt'
		else
		begin
			if(exists(select* 
					  from Teacher, Class
					  where Teacher.ID = Class.ManagerID and Teacher.ID = @teacherID))
				set @evaluation = N'giỏi'
			else
				set @evaluation = N'khá'
		end
		update Teacher set evaluation = @evaluation where ID = @teacherID
		print @evaluation
	end
end

create proc stepc
as
begin
	declare @id nchar(10)
	declare c cursor for select ID from Teacher
	open c
	fetch next from c into @id
	while(@@FETCH_STATUS = 0)
	begin
		declare @evaluation nvarchar(50)
		exec Stepb @id,@evaluation output
		fetch next from c into @id
	end

	close c
	deallocate c
	
end
exec stepc