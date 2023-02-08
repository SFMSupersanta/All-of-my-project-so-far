namespace FirstDotConsole;

internal class Class1
{
    private int a;

    public int A
    {
        get => a;
        set => a = value;
    }

    public string B
    {
        get => b;
        set => b = value ?? throw new ArgumentNullException(nameof(value));
    }

    private string b;

    public Class1(int a, string b)
    {
        this.a = a;
        this.b = b;
    }

    public override string ToString( )
    {
        return $"{nameof(a)}: {a}, {nameof(b)}: {b}";
    }
}