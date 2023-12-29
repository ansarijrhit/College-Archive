package tests.IanTests;

public class SingletonPublic {
    private String string;

    private SingletonPublic() {
        this.string = "hello";
    }

    public SingletonPublic getSingleton() {
        return new SingletonPublic();
    }
}
