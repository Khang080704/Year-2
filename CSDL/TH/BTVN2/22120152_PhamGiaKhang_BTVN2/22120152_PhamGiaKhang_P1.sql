create database QUAN_LI_KHOA_HOC
use QUAN_LI_KHOA_HOC
create table BaiBao(
	IDBaiBao char(10) not null,
	TenBaiBao nvarchar(50),
	IDTruong char(10) not null,
	IDPhanBien char(10)
	primary key (IDBaiBao,IDTruong)
)
create table NhaKhoaHoc(
	IDNhaKhoaHoc char(10) not null,
	IDTruong char(10) not null,
	HoTen nvarchar(50),
	NgaySinh Datetime,
	primary key (IDNhaKhoaHoc,IDTruong)
)
create table ThamGia(
	IDBaiBao char(10) not null,
	IDNhaKhoaHoc char(10) not null,
	IDTruong char(10) not null,
	ThanhTich nvarchar(50),
	primary key(IDBaiBao,IDNhaKhoaHoc,IDTruong)
)

alter table ThamGia add
	constraint FK_ThamGia_BaiBao foreign key (IDBaiBao,IDTruong)
		references BaiBao(IDBaiBao,IDTruong)

alter table ThamGia add
	constraint FK_ThamGia_NhaKhoaHoc foreign key(IDNhaKhoaHoc,IDTruong)
		references NhaKhoaHoc(IDNhaKhoaHoc,IDTruong)

alter table BaiBao add
	constraint FK_BaiBao_NhaKhoaHoc foreign key(IDPhanBien,IDTruong)
		references NhaKhoaHoc(IDNhaKhoaHoc,IDTruong)

insert into NhaKhoaHoc (IDNhaKhoaHoc,IDTruong,HoTen,NgaySinh)
values
	('N2','TN',N'Nguyễn',07/15/1984),
	('N2','BK',N'Tín',09/26/1983),
	('N1','BK',N'Hà',10/18/1984),
	('N1','TN',N'Hữu',12/09/1984),
	('N3','BK',N'Nhân',12/101/1982)

alter table NhaKhoaHoc
	alter column NgaySinh Date;

update NhaKhoaHoc set NgaySinh = '07-15-1984' where HoTen =N'Nguyễn'
update NhaKhoaHoc set NgaySinh = '09-26-1983' where HoTen =N'Tín'
update NhaKhoaHoc set NgaySinh = '10-18-1984' where HoTen =N'Hà'
update NhaKhoaHoc set NgaySinh = '12-09-1984' where HoTen =N'Hữu'
update NhaKhoaHoc set NgaySinh = '12-01-1982' where HoTen =N'Nhân'

insert into BaiBao (IDBaiBao,IDTruong,TenBaiBao,IDPhanBien)
values
	('B1','TN',N'Phát Triển TPTM','N2'),
	('B1','BK',N'Nghiên cứu BI','N2'),
	('B2','BK',N'Xử lí ngôn ngữ','N2')
insert into ThamGia (IDBaiBao,IDTruong,IDNhaKhoaHoc,ThanhTich)
values
	('B1', 'TN','N1',N'Giỏi'),
	('B1', 'BK','N1',N'Xuất sắc'),
	('B1', 'BK','N3',N'Khá'),
	('B2', 'BK','N1',N'Trung Bình'),
	('B2', 'BK','N3',N'Khá')
use QUAN_LI_KHOA_HOC

---a. Cho biet danh sach cac bai bao (IDTruong, TenBaiBao) co nha khoa hoc sinh nam 1984 tham gia
select distinct bb.IDTruong,bb.TenBaiBao
from ThamGia tg join BaiBao bb on tg.IDBaiBao=bb.IDBaiBao and tg.IDTruong=bb.IDTruong
                join NhaKhoaHoc nkh on tg.IDNhaKhoaHoc=nkh.IDNhaKhoaHoc and tg.IDTruong=nkh.IDTruong
where year(nkh.NgaySinh)=1984

select bb.IDBaiBao, bb.IDTruong, nkh.NgaySinh
from BaiBao bb, NhaKhoaHoc nkh
where YEAR(nkh.NgaySinh) = 1984
order by nkh.NgaySinh 


select distinct nkh.IDTruong, nkh.HoTen 
FROM BaiBao BB
JOIN THAMGIA TG ON BB.IDBaiBao = TG.IDBaiBao 
JOIN NhaKhoaHoc NKH ON TG.IDNhaKhoaHoc = NKH.IDNhaKhoaHoc
JOIN NhaKhoaHoc PhanBien ON BB.IDPhanBien = PhanBien.IDNhaKhoaHoc
WHERE YEAR(NKH.NgaySinh) = YEAR(PhanBien.NgaySinh)

---b. Cho biet danh sach cac nha khoa hoc(IDTruong,HoTen) tham gia bai bao duoc phan bien boi nha khoa hoc cung tuoi
select distinct nkh.IDTruong,nkh.HoTen
from ThamGia tg join BaiBao bb on tg.IDBaiBao=bb.IDBaiBao and tg.IDTruong=bb.IDTruong
                join NhaKhoaHoc nkh on tg.IDNhaKhoaHoc=nkh.IDNhaKhoaHoc and tg.IDTruong=nkh.IDTruong

union
select distinct nkh.IDTruong,nkh.HoTen
from BaiBao bb join NhaKhoaHoc nkh on bb.IDTruong=nkh.IDTruong and bb.IDPhanBien=nkh.IDNhaKhoaHoc
where year(nkh
