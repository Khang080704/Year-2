create database QLCLBCoVua
use QLCLBCoVua
create table CLB(
	IDCLB char(10) not null,
	TenCLB nvarchar(50),
	DiaChi nvarchar(50),
	primary key (IDCLB)
)
create table DOI(
	IDCLB char(10) not null,
	IDDoi char(10) not null,
	TenDoi nvarchar(50),
	IDDoiTruong char(10) not null,
	primary key(IDCLB,IDDoi)
)
create table HOIVIEN(
	IDCLB char(10) not null,
	IDHoiVien char(10) not null,
	HoTen nvarchar(50),
	NgaySinh Date,
	IDDoi char(10),
	IDBanCungTapLuyen char(10),
	primary key(IDCLB,IDHoiVien)
)

alter table DOI add
	constraint FK_DOI_CLB foreign key(IDCLB)
		references CLB(IDCLB)

alter table HOIVIEN add
	constraint FK_HOIVIEN_DOI foreign key(IDCLB,IDDoi)
		references DOI(IDCLB,IDDoi)
alter table HOIVIEN add
	constraint FK_HOIVIEN_CLB foreign key(IDCLB)
		references CLB(IDCLB)
alter table HOIVIEN 
	drop constraint FK_HOIVIEN_CLB
alter table HOIVIEN add
	constraint FK_HOIVIEN_HOIVIEN foreign key(IDCLB,IDBanCungTapLuyen)
		references HOIVIEN(IDCLB,IDHoiVien)

insert into CLB (IDCLB, TenCLB, DiaChi)
values
	('C01', N'Câu lạc bộ Phan Đình Phùng', 'P1, Q5, Hồ Chí Minh'),
	('C02', N'Câu lạc bộ Võ Thị Sáu', 'P3, Q1, Hồ Chí Minh')
insert into DOI (IDCLB,IDDoi, TenDoi,IDDoiTruong)
values
	('C01','D01',N'Đội 1','H01'),
	('C01','D02',N'Đội 2','H02'),
	('C02','D01',N'Đội 1','H01')

alter table HOIVIEN
	alter column IDBanCungTapLuyen char(10)
insert into HOIVIEN (IDCLB,IDHoiVien,HoTen,NgaySinh,IDDoi,IDBanCungTapLuyen)
values
	('C01','H01',N'Tiến','1984/07/15','D01', NULL),
	('C01','H02',N'Tùng','1983/09/26', 'D02',NULL),
	('C01','H03',N'Bình','1984/10/18','D01',NULL),
	('C01','H04',N'Đông','1987/12/09','D02',NULL),
	('C02','H01',N'Nam','1988/05/03','D01',NULL),
	('C02','H02',N'Á','1986/06/05','D01',NULL)

update HOIVIEN
set IDBanCungTapLuyen = 'H03' where IDCLB = 'C01' and IDHoiVien = 'H01'
update HOIVIEN
set IDBanCungTapLuyen = 'H04' where IDCLB = 'C01' and IDHoiVien = 'H02'
update HOIVIEN
set IDBanCungTapLuyen = 'H01' where IDCLB = 'C01' and IDHoiVien = 'H03'
update HOIVIEN
set IDBanCungTapLuyen = 'H02' where IDCLB = 'C01' and IDHoiVien = 'H04'
update HOIVIEN
set IDBanCungTapLuyen = 'H02' where IDCLB = 'C02' and IDHoiVien = 'H01'
update HOIVIEN
set IDBanCungTapLuyen = 'H01' where IDCLB = 'C02' and IDHoiVien = 'H02'