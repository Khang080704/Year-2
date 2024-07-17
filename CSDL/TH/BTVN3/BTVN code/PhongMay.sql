create database QLNhanVien 
go
use QLNhanVien;
go
create table PhongMay(
		MaPhong		char(10) primary Key,
		TenPhong	nvarchar(50),
		MayChu		char(10),
		MaNVQL		char(10)
)
go
create table MayTinh(
	MaMT	char(10),
	MaPM	char(10),
	TenMT	nvarchar(50),
	TinhTrang	bit,
	MayGateWay char(10),
	primary key(MaMT, MaPM)
)

create table NhanVien(
	MaNV	char(10) primary key,
	TenNV	nvarchar(50),
	MaNVQL	char(10),
	Phai	char(3) check(Phai in('Nam','Nu')),
)
go
alter table MayTinh
	alter column MaPM char(10) not null;
	
alter table PhongMay add
	constraint FK_PhongMay_MayTinh foreign key (MaPhong,MayChu)
		REFERENCES MayTinh(MaMT,MaPM)
alter table PhongMay add
	constraint FK_PhongMay_NhanVien foreign key (MaNVQL)
		REFERENCES NhanVien(MaNV)
alter table NhanVien add
	constraint FK_NhanVien_NhanVien foreign key(MaNVQL)
		References NhanVien(MaNV)
alter table MayTinh add
	constraint FK_MayTinh_PhongMay foreign key (MaPM)
		references PhongMay(MaPhong)
alter table MayTinh add
	constraint FK_MayTinh_MayTinh foreign key (MaPM, MayGateWay)
		references MayTinh(MaMT,MaPM)
insert into NhanVien (MaNV, TenNV, MaNVQL, Phai)
values
	('A1', 'Nguyễn Văn A', NULL, 'Nam'),
	('A2', 'Nguyễn Văn B', NULL, 'Nam'),
	('B1', 'Nguyễn Thị C', NULL, 'Nu')
update NhanVien set MaNVQL = 'A2' where MaNV = 'A1'
update NhanVien set	MaNVQL = 'B1' where MaNV = 'A2'
update NhanVien set	MaNVQL = 'A1' where MaNV = 'B1'
update NhanVien set TenNV = N'Nguyễn Văn A' where TenNV = 'Nguyễn Văn A'
update NhanVien set TenNV = N'Nguyễn Văn B' where TenNV = 'Nguyễn Văn B'
update NhanVien set TenNV = N'Nguyễn Thị C' where TenNV = 'Nguyễn Thị C'

alter table PhongMay
	drop constraint FK_PhongMay_MayTinh;
alter table PhongMay add
	constraint FK_PhongMay_MayTinh foreign key (MaPhong,MayChu)
		REFERENCES MayTinh(MaPM,MaMT)
alter table MayTinh
	drop constraint FK_MayTinh_MayTinh

