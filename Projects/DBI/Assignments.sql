create table Students(StudentID int identity(1,1) NOT NULL, Name nvarchar(15) NOT NULL, Address nvarchar(50) NOT NULL, Gender char(1) NOT NULL constraint PK_Student primary key (StudentID))

create table Teacher(TeacherID int identity(1,1) NOT NULL, Name nvarchar(15) NOT NULL, Address nvarchar(50) NOT NULL, Gender char(1) NOT NULL constraint PK_Teacher primary key (TeacherID))

create table Class(ClassID int identity(1,1) NOT NULL, Year int NOT NULL, Semester char(10) NOT NULL, NoCredits int NOT NULL, CourseID char(6) NOT NULL, GroupID char(6) NOT NULL, TeacherID int NOT NULL constraint PK_Class primary key (ClassID), constraint FK_Class_Teacher foreign key (TeacherID) references Teacher(TeacherID))

create table Attend(StudentID int identity(1,1) NOT NULL, ClassID int NOT NULL, Slot int NOT NULL, Date date NOT NULL, Attend bit NOT NULL constraint PK_Attend primary key (Slot, Date), constraint FK_Attend_Class foreign key (ClassID) references Class(ClassID), constraint FK_Attend_student foreign key (StudentID) references Students(StudentID))