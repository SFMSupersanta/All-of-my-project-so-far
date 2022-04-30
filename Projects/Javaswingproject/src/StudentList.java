package src;
import java.util.ArrayList;
import src.Student;
public class StudentList extends ArrayList<Student>
{
    public StudentList()
    {
        super();
    }
    public Student search(String id)
    {
        for(int i = 0; i < this.size(); i++)
        {
            if(this.get(i).getCode().equals(id)) return this.get(i);
        }
        return null;
    }
    private boolean isDuplicate(String id)
    {
        return null != search(id);
    }
    public void addStudent()
    {
        Inputter input = new Inputter();
        String code;
        do
        {
            code = input.inputPatten("Type in a code (S000):", "[Ss][\\d]{3}");
            code = code.toUpperCase();
            if(isDuplicate(code)) System.out.println("Code already exist!");
        }while (isDuplicate(code));
        this.add(new Student(code, input.inputInt("Type mark (0-10): ", 0 , 10), input.inputNonBlankStr("Input a non blank name:")));
    }
    public void searchStudent()
    {
        if(this.isEmpty()) System.out.println("List is empty");
        else{
            Inputter input = new Inputter();
            String code = input.inputPatten("Input code to search(not blank)", "[Ss][\\d]{3}");
            code = code.toUpperCase();
            Student su = search(code);
            if (su == null) System.out.println("Student not exist");
            else System.out.println("Found " + su);
        }
    }
    public void updateStudent()
    {
        if(this.isEmpty()) System.out.println("List is empty");
        else
        {
            String code;
            Inputter input = new Inputter();
            Student bufStudent = null;
            do
            {
                code = input.inputPatten("Enter student's code", "[Ss][\\d]{3}");
                code = code.toUpperCase();
                bufStudent = search(code);
                if(bufStudent == null) System.out.println("Student does not exist");
            } while (bufStudent == null);
            bufStudent.setMark(input.inputInt(("old mark: " + bufStudent.getMark() + " new mark: "), 0, 10));
            bufStudent.setName(input.inputNonBlankStr("old name: " + bufStudent.getName() + " new name:"));
            System.out.println("Student " + bufStudent.getCode() + " has been updated");
        }
    }
    public void deleteStudent()
    {
        if(this.isEmpty()) System.out.println("List is empty");
        else 
        {
            String code;
            Inputter input = new Inputter();
            Student bufStudent = null;
            do
            {
                code = input.inputPatten("Enter student's code", "[Ss][\\d]{3}");
                code = code.toUpperCase();
                bufStudent = search(code);
                if(bufStudent == null) System.out.println("Student does not exist");
            } while (bufStudent == null);
            this.remove(bufStudent);
            System.out.println("Student " + bufStudent.getCode() + " has been deleted");
        }
    }
    public void printAll()
    {
        if(this.isEmpty()) System.out.println("List is empty");
        else 
        {
            for(Student bufStudent : this)
            {
                System.out.println(bufStudent);
            }
        }
        System.out.println("Total: " + this.size() +  " student(s)");
    }
}