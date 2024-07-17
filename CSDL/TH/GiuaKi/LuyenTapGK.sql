create database QLLH
use QLLH
create table LopHoc(
	IDLopHoc char(5) not null,
	TenLop nvarchar(20) not null,
	HSTieuBieu char(5),
	LopTruong char(5),
	primary key(IDLopHoc)
)
create table HocSinh(
	IDLop char(5) not null,
	IDHocSinh char(5) not null,
	TenHS nvarchar(30),
	NgaySinh Date,
	GioiTinh char(3),
	primary key(IDLop, IDHocSinh)
)
create table HoatDong(
	IDHoatDong char(5) not null,
	TenHD nvarchar(30),
	NgayToChuc Date,
	SoHSThamGia int,
	primary key(IDHoatDong)
)
create table ThamGia(
	IDLopHoc char(5),
	IDHocSinh char(5),
	IDHoatDong char(5), 
	Diem int,
	primary key(IDLopHoc, IDHocSinh, IDHoatDong)
)

alter table LopHoc add
	constraint FK_LopHoc_HSTieuBieu foreign key(IDLopHoc,HSTieuBieu)
		references HocSinh(IDLop,IDHocSinh)

alter table LopHoc add
	constraint Fk_LopHoc_LopTruong foreign key(IDLopHoc,LopTruong)
		references HocSinh(IDLop,IDHocSinh)

alter table HocSinh add
	constraint FK_HocSinh_LopHoc foreign key(IDLop)
		references LopHoc(IDLopHoc)

alter table ThamGia add
	constraint FK_ThamGia_HocSinh foreign key(IDLopHoc,IDHocSinh)
		references HocSinh(IDLop,IDHocSinh)
alter table ThamGia add
	constraint Fk_ThamGia_HoatDong foreign key(IDHoatDong)
		references HoatDong(IDhoatDong)

insert into HoatDong (IDHoatDong,TenHD,NgayToChuc,SoHSThamGia)
values
	('HD01',N'Vở sạch chữ đẹp','2021/04/04',2),
	('HD02',N'HS Giỏi toán cấp trường','2022/04/04',2),
	('HD03',N'HS giỏi văn cấp trường',null,null)

insert into LopHoc(IDLopHoc,TenLop,HSTieuBieu,LopTruong)
values
	('LH01',N'Lớp 1A',null,null),
	('LH02',N'Lớp 1B',null,null),
	('LH03',N'Lớp 2A',null,null)

insert into HocSinh (IDLop,IDHocSinh,TenHS,NgaySinh,GioiTinh)
values
	('LH01','HS01',N'Trần Thanh Minh','2016/02/12',null),
	('LH01','HS02',N'Nguyễn Lan Chi','2016/02/14',null),
	('LH02','HS01',N'Ngô Quang Khải','2016/07/22',null),
	('LH02','HS02',N'Phạm Minh Ánh','2016/09/14',null),
	('LH03','HS01',N'Nguyễn Tuyết Lan','2015/08/15',null)

update LopHoc set HSTieuBieu = 'HS01' where IDLopHoc ='LH01'
update LopHoc set LopTruong = 'HS02' where IDLopHoc = 'LH01'
update LopHoc set HSTieuBieu = 'HS02' where IDLopHoc ='LH02'
update LopHoc set LopTruong = 'HS02' where IDLopHoc = 'LH02'
update LopHoc set LopTruong = 'HS01' where IDLopHoc = 'LH03'

insert into ThamGia (IDLopHoc,IDHocSinh,IDHoatDong,Diem)
values
	('LH01','HS01','HD01',9),
	('LH01','HS02','HD01',8),
	('LH02','HS01','HD02',7),
	('LH01','HS01','HD02',8)

select HoatDong.*
from HoatDong
where HoatDong.SoHSThamGia is null

--2.Cho danh sách các học sinh <=7 tuổi có tham gia hoạt động và đạt điểm 8 trở lên
select distinct hs.*
from HocSinh hs join ThamGia tg on hs.IDHocSinh = tg.IDHocSinh and hs.IDLop = tg.IDLopHoc
where tg.Diem >= 8 and (2023 - year(hs.NgaySinh)) <= 7

--3.Cho danh sách học sinh có tham gia cả hai hoạt động HD01 và HD02.
select hs.*
from HocSinh hs join ThamGia tg on hs.IDHocSinh = tg.IDHocSinh and hs.IDLop = tg.IDLopHoc
where tg.IDHoatDong = 'HD01'
intersect
select hs.*
from HocSinh hs join ThamGia tg on hs.IDHocSinh = tg.IDHocSinh and hs.IDLop = tg.IDLopHoc
where tg.IDHoatDong = 'HD02'