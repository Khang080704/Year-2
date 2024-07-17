select distinct qg.TenQG
from [TINH _THANH] tt, QUOC_GIA qg
where qg.DienTich > 330000 or (tt.MaTinhThanh = qg.ThuDo and tt.DanSo > 10000000)

--Cau 2