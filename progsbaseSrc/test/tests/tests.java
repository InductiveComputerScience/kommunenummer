package tests;

import static kommunenummertest.kommunenummertest.test1;

public class tests {
    public static double test(){
        double failures;
        failures = 0d;

        failures = failures + test1();

        return failures;
    }
}
