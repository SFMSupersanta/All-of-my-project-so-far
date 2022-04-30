package src;
public class Student {
    private String code;
    private int mark;
    private String name;
    public Student(String code, int mark, String name) {
        this.code = code;
        this.mark = mark;
        this.name = name;
    }
    public Student(){}
    public String getCode(){return code;}
    public void setCode(String code){this.code = code;}
    public int getMark(){return mark;}
    public void setMark(int mark){this.mark = mark;}
    public String getName(){return name;}
    public void setName(String name){this.name = name;}
    public String toString()
    {
        return "code: " + code + " " + "mark:" + mark + " " + "name: " + name; 
    }
}
