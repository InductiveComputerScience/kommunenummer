package kommunenummer.StringReferenceUtil;

import references.references.StringReference;

public class StringReferenceUtil {
    public static StringReference createStringReference(char [] string){
        StringReference stringReference;
        stringReference = new StringReference();
        stringReference.string = string;
        return stringReference;
    }
}
