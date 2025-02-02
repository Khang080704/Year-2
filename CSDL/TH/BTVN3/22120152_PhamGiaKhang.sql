USE [QLGV]
GO
ALTER TABLE [dbo].[GiaoVien] DROP CONSTRAINT [FK_GiaoVien_bomon]
GO
ALTER TABLE [dbo].[bomon] DROP CONSTRAINT [FK_bomon_GiaoVien]
GO
/****** Object:  Table [dbo].[GiaoVien]    Script Date: 4/1/2024 14:46:47 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[GiaoVien]') AND type in (N'U'))
DROP TABLE [dbo].[GiaoVien]
GO
/****** Object:  Table [dbo].[bomon]    Script Date: 4/1/2024 14:46:47 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[bomon]') AND type in (N'U'))
DROP TABLE [dbo].[bomon]
GO
/****** Object:  Table [dbo].[bomon]    Script Date: 4/1/2024 14:46:47 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[bomon](
	[mabm] [char](10) NOT NULL,
	[tenbm] [nvarchar](50) NULL,
	[GVTrBM] [char](10) NULL,
 CONSTRAINT [PK_bomon] PRIMARY KEY CLUSTERED 
(
	[mabm] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[GiaoVien]    Script Date: 4/1/2024 14:46:48 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[GiaoVien](
	[magv] [char](10) NOT NULL,
	[tengv] [nvarchar](50) NOT NULL,
	[ngaysinh] [datetime] NOT NULL,
	[mabomon] [char](10) NULL,
 CONSTRAINT [PK_GiaoVien] PRIMARY KEY CLUSTERED 
(
	[magv] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[bomon] ([mabm], [tenbm], [GVTrBM]) VALUES (N'CNTT      ', N'Công nghệ thông tin', N'A1        ')
INSERT [dbo].[bomon] ([mabm], [tenbm], [GVTrBM]) VALUES (N'HTTT      ', N'Hệ thống thông tin', N'B2        ')
INSERT [dbo].[bomon] ([mabm], [tenbm], [GVTrBM]) VALUES (N'KHMT      ', N'Khoa học máy tính', N'B1        ')
INSERT [dbo].[bomon] ([mabm], [tenbm], [GVTrBM]) VALUES (N'KTPM      ', N'Kĩ thuật phần mềm', N'A2        ')
GO
INSERT [dbo].[GiaoVien] ([magv], [tengv], [ngaysinh], [mabomon]) VALUES (N'A1        ', N'Nguyễn Văn A', CAST(N'2004-07-08T00:00:00.000' AS DateTime), N'CNTT      ')
INSERT [dbo].[GiaoVien] ([magv], [tengv], [ngaysinh], [mabomon]) VALUES (N'A2        ', N'Nguyễn Văn B', CAST(N'1999-05-20T00:00:00.000' AS DateTime), N'KTPM      ')
INSERT [dbo].[GiaoVien] ([magv], [tengv], [ngaysinh], [mabomon]) VALUES (N'B1        ', N'Nguyễn Thị B', CAST(N'2000-06-06T00:00:00.000' AS DateTime), N'KHMT      ')
INSERT [dbo].[GiaoVien] ([magv], [tengv], [ngaysinh], [mabomon]) VALUES (N'B2        ', N'Nguyễn Thị D', CAST(N'1999-09-12T00:00:00.000' AS DateTime), N'HTTT      ')
GO
ALTER TABLE [dbo].[bomon]  WITH CHECK ADD  CONSTRAINT [FK_bomon_GiaoVien] FOREIGN KEY([GVTrBM])
REFERENCES [dbo].[GiaoVien] ([magv])
GO
ALTER TABLE [dbo].[bomon] CHECK CONSTRAINT [FK_bomon_GiaoVien]
GO
ALTER TABLE [dbo].[GiaoVien]  WITH CHECK ADD  CONSTRAINT [FK_GiaoVien_bomon] FOREIGN KEY([mabomon])
REFERENCES [dbo].[bomon] ([mabm])
GO
ALTER TABLE [dbo].[GiaoVien] CHECK CONSTRAINT [FK_GiaoVien_bomon]
GO
