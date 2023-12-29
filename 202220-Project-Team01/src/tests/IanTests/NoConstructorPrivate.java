package tests.IanTests;

// this class fails as the constructor is private, 
// and so is the singleton type return. so the class is not constructable

public class NoConstructorPrivate {
    private NoConstructorPrivate() {

    }
    private NoConstructorPrivate getNoConstructorPrivate() {
        return new NoConstructorPrivate();
    }
}
