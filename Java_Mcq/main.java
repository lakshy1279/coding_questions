// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
abstract class Hackerearth
{
    int k = 1;
    public Hackerearth()
    {
        show();
        k = 3;
    }
    abstract void myMethod();

    void  show()
    {
        System.out.println(k);
    }
}
interface Hacker
{
    abstract void myMethod();
}
class Hackster extends Hackerearth implements Hacker
{
    public Hackster()
    {
        super();
        k = 2;
    }
    public void myMethod()
    {
        new Hackster();
    }
}
class Hack extends Hackster
{
    public Hack()
    {
        k = -1;
        myMethod();
    }
}
public class Main {
    public static class printHello {

        public static void print()
        {
            System.out.println("Hello");
        }
    }
    // The static keyword in this context means that the nested class is not associated with any instance of the outer class. This allows it to be accessed independently, without the need to create an instance of the outer class.
    public static void main(String[] args) {
        Hack obj = new Hack();
    }
}