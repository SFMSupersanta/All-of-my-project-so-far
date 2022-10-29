create database ASSIGNMENT ON PRIMARY (name = MyDatabase, filename = 'D:\Collage Excercise\Fall 2022\DBI101.ASSIGNMENTDATA.mdf', size = 10mb, maxsize = 20mb, filegrowth = 2mb)
log on (name = MyDatabaseLog, filename = 'D:\Collage Excercise\Fall 2022\DBI101.ASSIGNMENTDATALOG.ldf', size = 5mb, maxsize = 7mb, filegrowth = 1mb)

-- T?o table Studentsv? table Teachers tr??c khi t?o c?c table kh?c b?i 2 table n?y c? pk l? fk c?a c?c table kh?c
create table Students(
	StudentID int identity(1,1),
	Name nvarchar(30),
	Address nvarchar(50),
	Gender char(3)
	constraint PK_Students primary key (StudentID)
)

create table Teachers (
	TeacherID int identity(1,1),
	Name nvarchar(30),
	Address nvarchar(50),
	Gender char(3)
	constraint PK_Teachers primary key (TeacherID)
)

-- Class c? forein key l? TeacherID ??n t? Teachers v? m?i quan h? gi?a class v? Teacher l? nhi?u - m?t
create table Class (
	ClassID int identity(1,1),
	Year int,
	Semester char(10),
	NoCredits int,
	CourseID char(6),
	GroupID char(6),
	TeacherID int
	constraint PK_Class primary key (ClassID),
	constraint FK_Class_Teachers foreign key (TeacherID) references Teachers(TeacherID)
)

-- Table attend c? 2 forein key l? classID v? StudentID v? n? l? table trung gian gi?a Studentsv? class
-- V? Studentsv? class c? m?i quan h? nhi?u nhi?u
create table Attend (
	StudentID int identity(1,1),
	ClassID int,
	Slot int,
	Date date,
	Attend bit
	constraint PK_Attend primary key (Slot, Date),
	constraint FK_Attend_Class foreign key (ClassID) references Class(ClassID),
	constraint FK_Attend_Student foreign key (StudentID) references Students(StudentID)
)

