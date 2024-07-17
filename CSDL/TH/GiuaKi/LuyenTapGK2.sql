create database CLB
go
use CLB
create table clb (
	IDCLB char(10) not null,
	TenCLB nvarchar(50),
	DiaChi nvarchar(50)
	primary key(IDCLB)
)
create table DOI(
	IDCLB char(10) not null,
	IDDoi char(10) not null,
	TenDoi nvarchar(30),
	IDDoiTruong char(10),
	primary key(IDCLB,IDDoi)
)
create table HOIVIEN(
	IDCLB char(10) not null,
	IDHoiVien char(10) not null,
	HoTen nvarchar(30),
	NgaySinh Date,
	IDDoi char(10),
	IDBanCungTapLuyen char(10)
	primary key(IDCLB,IDHoiVien)
)
alter table DOI add
	constraint FK_DOI_CLB foreign key (IDCLB)
		references clb(IDCLB)
alter table DOI add
	constraint FK_DOI_HOIVIEN foreign key(IDCLB,IDDoiTruong)
		references HOIVIEN(IDCLB,IDHoiVien)
alter table HOIVIEN add
	constraint FK_HOIVIEN_DOI foreign key(IDCLB,IDDoi)
		references DOI(IDCLB,IDDoi)
alter table HOIVIEN add
	constraint FK_HOIVIEN_HOIVIEN foreign key(IDCLB,IDBanCungTapLuyen)
		references HOIVIEN(IDCLB,IDHoiVien)

insert into clb(IDCLB,TenCLB,DiaChi)
values
	('C01',N'Câu lạc bộ Phan Đình Phùng',N'P1,Q5,Hồ Chí Minh'),
	('C02',N'Câu lạc bộ Võ Thị Sáu',N'P3,Q1,Hồ Chí Minh')
insert into DOI(IDCLB,IDDoi,TenDoi,IDDoiTruong)
values
	('C01','D01',N'Đội 1',NULL),
	('C01','D02',N'Đội 2',NULL),
	('C02','D01',N'Đội 1',NULL)
insert into HOIVIEN(IDCLB,IDHoiVien,HoTen,NgaySinh,IDDoi,IDBanCungTapLuyen)
values
	('C01','H01',N'Tiến','07/15/1984','D01',NULL),
	('C01','H02',N'Hùng','09/26/1983','D02',NULL),
	('C01','H03',N'Bình','10/18/1984 ','D01',NULL),
	('C01','H04',N'Đông','12/09/1987','D02',NULL),
	('C02','H01',N'Nam','05/03/1988 ','D01',NULL),
	('C02','H02',N'Á','06/05/1986','D01',NULL)

update DOI set IDDoiTruong = 'H01' where IDCLB = 'C01' and IDDoi = 'D01'
update DOI set IDDoiTruong = 'H02' where IDCLB = 'C01' and IDDoi = 'D02'
update DOI set IDDoiTruong = 'H01' where IDCLB = 'C02' and IDDoi = 'D01'

update HOIVIEN set IDBanCungTapLuyen = 'H03' where IDCLB = 'C01' and IDHoiVien ='H01'
update HOIVIEN set IDBanCungTapLuyen = 'H04' where IDCLB = 'C01' and IDHoiVien ='H02'
update HOIVIEN set IDBanCungTapLuyen = 'H01' where IDCLB = 'C01' and IDHoiVien ='H03'
update HOIVIEN set IDBanCungTapLuyen = 'H02' where IDCLB = 'C01' and IDHoiVien ='H04'
update HOIVIEN set IDBanCungTapLuyen = 'H02' where IDCLB = 'C02' and IDHoiVien ='H01'
update HOIVIEN set IDBanCungTapLuyen = 'H01' where IDCLB = 'C02' and IDHoiVien ='H02'

select DOI.IDCLB, doi.TenDoi
from DOI join HOIVIEN hv on DOI.IDCLB = hv.IDCLB and DOI.IDDoi = hv.IDDoi
where YEAR(hv.NgaySinh) >= 1988