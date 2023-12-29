package tests.IanTests;

public class IanTests {
    StrategyPattern pat1; // Strategy Pattern implemented

    private IanTests() { // is not publicly constructable
        pat1 = new StrategyPatternTest(); // should ring as dependency injection
    }

    public IanTests doThis() { //publicly constructable
        return new IanTests();
    }
}
