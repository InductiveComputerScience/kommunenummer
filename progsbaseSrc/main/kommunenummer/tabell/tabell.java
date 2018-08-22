package kommunenummer.tabell;

import static java.lang.Math.*;

public class tabell {
    public static boolean [] lagGyldigReversTabell(double [] nummerliste){
        double i;
        double maxnummer;
        boolean inverse[];

        maxnummer = 0d;
        for(i = 0d; i < nummerliste.length; i = i + 1d){
            maxnummer = max(maxnummer, nummerliste[(int)i]);
        }

        inverse = new boolean [(int)(maxnummer + 1d)];

        for(i = 0d; i < maxnummer; i = i + 1d){
            inverse[(int)i] = false;
        }

        for(i = 0d; i < nummerliste.length; i = i + 1d){
            inverse[(int)nummerliste[(int)i]] = true;
        }

        return inverse;
    }
}
