use QLHV2222
create proc bai5_step1
	@stuID varchar(20),@subID varchar(20), @mark float
as
begin
	if(not exists(select* from Student where ID = @stuID))
	begin
		print 'Khong ton tai hoc vien'
		return
	end
	if(not exists(select* from Subject where ID = @subID))
	begin
		print 'Khong ton tai mon hoc'
		return
	end
	if(@mark > 10 and @mark < 0)
	begin
		print'Diem khong hop le'
		return
	end

	--Lay ra lan thi moi nhat
	declare @lanthi int
	select @lanthi = res.Times + 1
	from Subject sub, Result res, Student stu
	where res.StudentID = @stuID  and res.SubjectID = @subID and res.Times >= all(select res2.Times
					  from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID)

	insert into Result (StudentID,SubjectID,Times,Mark) values (@stuID,@subID,isnull(@lanthi,1),@mark)
	print 'Them thanh cong'
end


exec bai5_step1 'HV000001','MH00001',6
exec bai5_step1 'HV000001','MH00002',4
exec bai5_step1 'HV000001','MH00002',8
exec bai5_step1 'HV000005','MH00009',10
