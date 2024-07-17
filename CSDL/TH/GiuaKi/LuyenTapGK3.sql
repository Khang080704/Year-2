create database THAMQUAN
use THAMQUAN

create table TINH_THANH(
	QuocGia char(10) not null,
	MaTinhThanh char(10) not null,
	DanSo int,
	DienTich float,
	TenTT nvarchar(50),
	Stt int,
	primary key(QuocGia,MaTinhThanh)
)
create table DIEM_THAM_QUAN(
	QuocGia char(10) not null,
	TinhThanh char(10) not null,
	Stt int not null,
	TenDTQ nvarchar(50),
	DacDiem nvarchar(50),
	primary key(QuocGia,TinhThanh,Stt)
)
create table QUOC_GIA(
	MaQG char(10) not null,
	TenQG nvarchar(50),
	ThuDo char(10),
	DanSo int,
	DienTich float
	primary key(MaQG)
)

alter table TINH_THANH add
	constraint FK_TINHTHANH_QUOCGIA foreign key(QuocGia)
		references QUOC_GIA(MaQG)
alter table TINH_THANH add
	constraint FK_TINHTHANh_DIEMTQ foreign key(QuocGia,MaTinhThanh,Stt)
		references DIEM_THAM_QUAN(QuocGia,TinhThanh,Stt)
alter table DIEM_THAM_QUAN add
	constraint FK_DIEMTQ_TINHTHANH foreign key(QuocGia,TinhThanh)
		references TINH_THANH(QuocGia,MaTinhThanh)
alter table QUOC_GIA add
	constraint FK_QUOCGIA_TINHTHANH foreign key(MaQG,ThuDo)
		references TINH_THANH(QuocGia,MaTinhThanh)

insert into QUOC_GIA(MaQG,TenQG,ThuDo,DanSo,DienTich)
values
	('QG002',N'Nhật Bản',Null,129500000,337834.00),
	('QG003',N'Thái Lan',NULL,300500000,207834.00),
	('QG001',N'Việt Nam',NULL,115000000,331688.00)

insert into TINH_THANH(QuocGia,MaTinhThanh,TenTT,DanSo,DienTich,Stt)
values
	('QG001','TT001',N'Hà Nội',2500000,927.39,NULL),
	('QG001','TT002',N'Huế',5344000,5009.00,NULL),
	('QG002','TT003',N'Tokyo',12084000,2187.00,NULL)
insert into DIEM_THAM_QUAN(Stt,TenDTQ,TinhThanh,QuocGia,DacDiem)
values
	(1,N'Văn Miếu','TT001','QG001',N'Di Tích Cổ'),
	(2,N'Hoàng Lăng','TT002','QG001',N'Di Tích Cổ'),
	(3,N'Tháp Tokyo','TT003','QG002',N'Công trình hiện đại')
update TINH_THANH set Stt = 1 where QuocGia = 'QG001' and MaTinhThanh ='TT001'
update TINH_THANH set Stt = 2 where QuocGia = 'QG001' and MaTinhThanh ='TT002'
update TINH_THANH set Stt = 3 where QuocGia = 'QG002' and MaTinhThanh ='TT003'

update QUOC_GIA set ThuDo = 'TT003' where MaQG = 'QG002'
update QUOC_GIA set ThuDo = 'TT001' where MaQG = 'QG001'

select qg.TenQG
from QUOC_GIA qg join TINH_THANH tt on qg.MaQG = tt.QuocGia and qg.ThuDo = tt.MaTinhThanh
where qg.DienTich >= 335000000 or tt.DanSo > 10000000

select qg.TenQG, tt.TenTT as ThuDo--, count(dtq.Stt) as SoDiemTQ
from QUOC_GIA qg join TINH_THANH tt on qg.MaQG =tt.QuocGia and qg.ThuDo = tt.MaTinhThanh
				 join DIEM_THAM_QUAN dtq on tt.QuocGia = dtq.QuocGia
group by qg.TenQG, tt.TenTT
