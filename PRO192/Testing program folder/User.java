
public class User {
    public String firstName;
    public String lastName;
    public String password;

    public String fullName() {
        return firstName + " " + lastName;
    }
}
