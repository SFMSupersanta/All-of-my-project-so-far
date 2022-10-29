
--Drop all tables

drop table NHANVIEN
drop table DUAN
drop table PHONG

-- Table phong
create table PHONG(
    MAPHONG int identity(101,1),
    TENPHONG nvarchar(255)
    constraint PK_PHONG PRIMARY KEY (MAPHONG)
)
INSERT INTO PHONG VALUES
	(N'Phòng Hành chính'),
	(N'Phòng Kỹ thuật'),
	(N'Phòng Kỹ thuật Điện'),
	(N'Phòng Phòng Kế toán'),
	(N'Phòng Điều hành Kỹ thuật');
select * from PHONG

--Table DUAN
create table DUAN(
    MADA int identity(201,1),
    TENDA nvarchar(255),
    MAPHONG int
    constraint PK_DUAN PRIMARY KEY (MADA)
    constraint PK_DUAN_PHONG FOREIGN KEY (MAPHONG) REFERENCES PHONG(MAPHONG)
)
INSERT INTO DUAN VALUES
	(N'Dự án Xây dựng HTM cho khoa CNTT', 102),
	(N'Dự án Xây dựng Website bán hàng Hải Anh', 104),
	(N'Dự án Phần mềm quản lý Đào tạo HPC', 102),
	(N'Dự án Phần mềm quản lý Văn bản ESOFT', 101);
select * from DUAN

--Table NHANVIEN
create table NHANVIEN(
    MANV int identity(1011,1),
    HOTEN nvarchar(255),
    TUOI int,
    GIOITINH nchar(3),
    LUONG int,
    MAPHONG int
    constraint PK_NHANVIEN PRIMARY KEY (MANV)
    constraint PK_NHANVIEN_PHONG FOREIGN KEY (MAPHONG) REFERENCES PHONG(MAPHONG)
)
INSERT INTO NHANVIEN VALUES
	(N'Nguyễn Thành Long', 18, N'Nam', 5000000, 101),
	(N'Nguyễn Thị Nhàn', 27, N'Nữ', 5000000, 104),
	(N'Hoàng Anh Tú', 18, N'Nam', 5000000, 101),
	(N'Lê Đức Quang Huy', 36, N'Nam', 5000000, 104),
	(N'Lê Đức Thước Long', 45, N'Nam', 5000000, 102);
select * from NHANVIEN

-- Projects that 102 in charge of:
select MADA, TENDA from DUAN where (MAPHONG = 102);
-- Employess that room 102 in charge of:
select MANV, HOTEN, TUOI, GIOITINH, LUONG from NHANVIEN where (MAPHONG = 102);
-- Employess whose name is Nhàn:
select MANV, HOTEN, TUOI, GIOITINH, LUONG from NHANVIEN where (HOTEN) like N'%Nhàn';




