create database QLPHUONG
go
use QLPHUONG
go
create table Phuong(
	IDPhuong char(4) not null,
	IDChuTich char(4),
	TenPhuong nvarchar(20),
	primary key (IDPhuong)
)
go
create table KhuPho(
	IDKhuPho int not null,
	IDTrKhuPho char(4),
	IDPhuong char(4) not null,
	primary key(IDKhuPho,IDPhuong)
)
go
create table Dan(
	IDDan char(4) not null,
	IDKhuPho int,
	Ten nvarchar(20),
	TinhTrang nvarchar(50) not null,
	IDPhuong char(4) not null,
	primary key(IDDan,IDPhuong)
)
go
create table TrucKhuPho(
	IDDan char(4) not null,
	IDKhuPho int not null,
	NghiPhep char(5),
	IDPhuong char(4) not null,
	primary key(IDDan,IDKhuPho,IDPhuong)
)
go
alter table Phuong add
	constraint FK_Phuong_Dan foreign key(IDChuTich,IDPhuong)
		references Dan(IDDan,IDPhuong)
go
alter table KhuPho add
	constraint FK_KhuPho_Phuong foreign key(IDPhuong)
		references Phuong(IDPhuong)
go
alter table KhuPho add
	constraint FK_KhuPho_Dan foreign key(IDTrKhuPho,IDPhuong)
		references Dan(IDDan,IDPhuong)
go
alter table Dan add
	constraint FK_Dan_KhuPho foreign key(IDKhuPho,IDPhuong)
		references KhuPho(IDKhuPho,IDPhuong)
go
alter table TrucKhuPho add
	constraint FK_TrucKhuPho_Dan foreign key(IDDan,IDPhuong)
		references Dan(IDDan,IDPhuong)
go
alter table TrucKhuPho add
	constraint FK_TrucKhuPho_KhuPho foreign key(IDKhuPho,IDPhuong)
		references KhuPho(IDKhuPho,IDPhuong)
go
insert into Phuong(IDPhuong,TenPhuong,IDChuTich)
values
	('PHA',N'Phường A',Null),
	('PHB',N'Phường B',Null),
	('PHC',N'Phường C',Null)
alter table Phuong drop column TenPhuong
