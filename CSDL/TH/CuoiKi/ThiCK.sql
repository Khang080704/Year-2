use QLHV2222
select count(*)
from Course join Teacher on Course.TeacherID = Teacher.ID
where ClassID = 'LH0004' and Teacher.Name = N'Nguyễn Văn An'

--list the student who pass computer network
select stu.*
from Result res join Subject sub on res.SubjectID = sub.ID
			    join Student stu on res.StudentID = stu.ID
where sub.Name = N'Cơ sở dữ liệu' and res.Mark >= 5
and res.Times >= all (select res2.Times
					  from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID)


--voi moi mon hoc, cho biet so luong sinh vien pass mon
select  sub.Name,count(res.StudentID)
from Subject sub, Result res
where sub.ID = res.SubjectID and 
res.Mark >= 5 and res.Times >= all(select res2.Times
					  from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID)
group by sub.ID,sub.Name
having count(res.StudentID) >=4

--tinh gpa cua nguyen van a
select sum(res.Mark * sub.Credits)/sum(sub.Credits) as gpa
from Result res, Student stu, Subject sub
where res.StudentID = stu.ID and res.SubjectID = sub.ID and res.Mark >= 5 and stu.ID = 'HV000001'
and res.Times >= all(select res2.Times
					  from Result res2 
					  where res2.StudentID = res.StudentID and res2.SubjectID = res.SubjectID)
