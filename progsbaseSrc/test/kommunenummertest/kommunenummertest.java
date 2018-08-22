package kommunenummertest;

import kommunenummer.kommunenummer.Success;
import references.references.DoubleReference;

import static kommunenummer.kommunenummer.kommunenummer.hentKommunenavnFraNummer;
import static testing.testing.testing.assertStringEquals;
import static testing.testing.testing.assertTrue;

public class kommunenummertest {
    public static double test1(){
        DoubleReference doubleReference;
        Success success;
        char [] kommuenavn;

        doubleReference = new DoubleReference();
        doubleReference.doubleValue = 0d;

        success = new Success();
        kommuenavn = hentKommunenavnFraNummer("1640".toCharArray(), success);
        assertStringEquals(kommuenavn, "R\u00F8ros".toCharArray(), doubleReference);
        assertTrue(success.success, doubleReference);

        return doubleReference.doubleValue;
    }
}
