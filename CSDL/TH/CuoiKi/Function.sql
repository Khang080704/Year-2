use QLHV2222

create function getAvg (@stuID varchar(20))
returns float
as
begin
	declare @gpa float
	select @gpa = sum(res.Mark * sub.Credits)/sum(sub.Credits)
	from Student stu, Subject sub, Result res
	where stu.ID = res.StudentID and res.SubjectID = sub.ID and stu.ID = @stuID
	and res.Times >= all(select res2.Times
					  from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID)
	return @gpa
end

declare @gpa float
set @gpa = dbo.getAVG('HV000006')
print cast(@gpa as varchar(20))

select ID, isnull(dbo.getAVG(ID),0) as DiemTB
from Student