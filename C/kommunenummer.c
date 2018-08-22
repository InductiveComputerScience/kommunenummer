#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define strparam(str) (str), strlen(str)

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct Success;
typedef struct Success Success;

struct StringToDecimalResult;
typedef struct StringToDecimalResult StringToDecimalResult;

struct BooleanReference;
typedef struct BooleanReference BooleanReference;

struct DoubleReference;
typedef struct DoubleReference DoubleReference;

struct StringReference;
typedef struct StringReference StringReference;

struct DecimalListRef;
typedef struct DecimalListRef DecimalListRef;

struct StringListRef;
typedef struct StringListRef StringListRef;

struct Success{
  _Bool success;
  char *feilmelding;
  size_t feilmeldingLength;
};

struct StringToDecimalResult{
  double result;
  char *feilmelding;
  size_t feilmeldingLength;
  _Bool success;
};

struct BooleanReference{
  _Bool booleanValue;
};

struct DoubleReference{
  double doubleValue;
};

struct StringReference{
  char *string;
  size_t stringLength;
};

struct DecimalListRef{
  double *list;
  size_t listLength;
};

struct StringListRef{
  StringReference **list;
  size_t listLength;
};

StringReference *createStringReference(char *string, size_t stringLength);

_Bool *lagGyldigReversTabell(size_t *returnArrayLength, double *nummerliste, size_t nummerlisteLength);

char *hentKommunenavnFraNummer(size_t *returnArrayLength, char *kommunenummer, size_t kommunenummerLength, Success *success);
_Bool erGyldigKommunenummer(char *kommunenummer, size_t kommunenummerLength);
_Bool erHelttall(double nr);
_Bool *hentGyldigKommunetabell(size_t *returnArrayLength);
StringReference **hentKommunenavn(size_t *returnArrayLength);
double *hentGyldigeKommunenummer(size_t *returnArrayLength);

double test1();

double test();

char *decimalToString(size_t *returnArrayLength, double decimal);
char *numberToString(size_t *returnArrayLength, double decimal, double base);
double getDigits(double base);
double getDigitPosition(double decimal, double base);
char getSingleDigitFromNumber(double c, double base);
char *getNumberTable(size_t *returnArrayLength);

StringToDecimalResult *stringToDecimal(char *string, size_t stringLength);
StringToDecimalResult *stringToDecimalForBase(char *string, size_t stringLength, double base);
double getDecimalFromSingleDecimalDigit(char c, double base);
_Bool isNumber(char c, double base);

void assertFalse(_Bool b, DoubleReference *failures);
void assertTrue(_Bool b, DoubleReference *failures);
void assertEquals(double a, double b, DoubleReference *failures);
void assertStringEquals(char *a, size_t aLength, char *b, size_t bLength, DoubleReference *failures);

double *stringToNumberArray(size_t *returnArrayLength, char *string, size_t stringLength);
char *numberArrayToString(size_t *returnArrayLength, double *array, size_t arrayLength);
_Bool stringsEqual(char *data1, size_t data1Length, char *data2, size_t data2Length);
_Bool numberArraysEqual(double *data1, size_t data1Length, double *data2, size_t data2Length);

char *substring(size_t *returnArrayLength, char *string, size_t stringLength, double from, double to);
char *appendString(size_t *returnArrayLength, char *string, size_t stringLength, char *s, size_t sLength);
char *appendCharacter(size_t *returnArrayLength, char *string, size_t stringLength, char c);
StringReference **split(size_t *returnArrayLength, char *toSplit, size_t toSplitLength, char splitBy);


double *addDecimal(size_t *returnArrayLength, double *list, size_t listLength, double a);
void addDecimalRef(DecimalListRef *list, double i);
double *removeDecimal(size_t *returnArrayLength, double *list, size_t listLength, double n);
double getDecimalRef(DecimalListRef *list, double i);
void removeDecimalRef(DecimalListRef *list, double i);

StringReference **addString(size_t *returnArrayLength, StringReference **list, size_t listLength, StringReference *a);
void addStringRef(StringListRef *list, StringReference *i);
StringReference **removeString(size_t *returnArrayLength, StringReference **list, size_t listLength, double n);
StringReference *getStringRef(StringListRef *list, double i);
void removeStringRef(StringListRef *list, double i);

StringReference *createStringReference(char *string, size_t stringLength){
  StringReference *stringReference;

  stringReference = (StringReference *)malloc(sizeof(StringReference));
  stringReference->string = string;
  stringReference->stringLength = stringLength;
  return stringReference;
}
_Bool *lagGyldigReversTabell(size_t *returnArrayLength, double *nummerliste, size_t nummerlisteLength){
  double i;
  double maxnummer;
  _Bool *inverse;
  size_t inverseLength;

  maxnummer = 0.0;
  for(i = 0.0; i < nummerlisteLength; i = i + 1.0){
    maxnummer = fmax(maxnummer, nummerliste[(int)(i)]);
  }

  inverse = (_Bool*)malloc(sizeof(_Bool) * (maxnummer + 1.0));
  inverseLength = maxnummer + 1.0;

  for(i = 0.0; i < maxnummer; i = i + 1.0){
    inverse[(int)(i)] = false;
  }

  for(i = 0.0; i < nummerlisteLength; i = i + 1.0){
    inverse[(int)(nummerliste[(int)(i)])] = true;
  }

  *returnArrayLength = inverseLength;
  return inverse;
}
char *hentKommunenavnFraNummer(size_t *returnArrayLength, char *kommunenummer, size_t kommunenummerLength, Success *success){
  char *kommunenavn;
  size_t kommunenavnLength;
  StringReference **kommunenavnListe;
  size_t kommunenavnListeLength;
  double nr;
  StringToDecimalResult *stringToDecimalResult;

  kommunenavn = (char*)malloc(sizeof(char) * (0.0));
  kommunenavnLength = 0.0;

  if(erGyldigKommunenummer(kommunenummer, kommunenummerLength)){
    kommunenavnListe = hentKommunenavn(&kommunenavnListeLength);
    stringToDecimalResult = stringToDecimalForBase(kommunenummer, kommunenummerLength, 10.0);
    if(stringToDecimalResult->success){
      nr = stringToDecimalResult->result;
      kommunenavn = kommunenavnListe[(int)(nr)]->string;
      kommunenavnLength = kommunenavnListe[(int)(nr)]->stringLength;
      success->success = true;
    }else{
      success->feilmelding = "Kommunenummer var ikke et gyldig tall.";
      success->feilmeldingLength = strlen(success->feilmelding);
      success->success = false;
    }
  }else{
    success->success = false;
    success->feilmelding = "Kommunenummer er ikke gyldig.";
    success->feilmeldingLength = strlen(success->feilmelding);
  }

  *returnArrayLength = kommunenavnLength;
  return kommunenavn;
}
_Bool erGyldigKommunenummer(char *kommunenummer, size_t kommunenummerLength){
  _Bool gyldig;
  double nr;
  _Bool *gyldigKommunetabell;
  size_t gyldigKommunetabellLength;

  if(kommunenummerLength == 4.0){
    nr = stringToDecimalForBase(kommunenummer, kommunenummerLength, 10.0)->result;
    if(nr >= 101.0 && nr <= 2030.0 && erHelttall(nr)){
      gyldigKommunetabell = hentGyldigKommunetabell(&gyldigKommunetabellLength);
      gyldig = gyldigKommunetabell[(int)(nr)];
    }else{
      gyldig = false;
    }
  }else{
    gyldig = false;
  }

  return gyldig;
}
_Bool erHelttall(double nr){

  return (fmod(nr, 1.0)) == 0.0;
}
_Bool *hentGyldigKommunetabell(size_t *returnArrayLength){
  double *nummerliste;
  size_t nummerlisteLength;

  nummerliste = hentGyldigeKommunenummer(&nummerlisteLength);
    return lagGyldigReversTabell(returnArrayLength, nummerliste, nummerlisteLength);
}
StringReference **hentKommunenavn(size_t *returnArrayLength){
  StringReference **kommunenavn;
  size_t kommunenavnLength;

  kommunenavn = (StringReference**)malloc(sizeof(StringReference) * 2100.0);
  kommunenavnLength = 2100.0;

  kommunenavn[101] = createStringReference(strparam("Halden"));
  kommunenavn[104] = createStringReference(strparam("Moss"));
  kommunenavn[105] = createStringReference(strparam("Sarpsborg"));
  kommunenavn[106] = createStringReference(strparam("Fredrikstad"));
  kommunenavn[111] = createStringReference(strparam("Hvaler"));
  kommunenavn[118] = createStringReference(strparam("Aremark"));
  kommunenavn[119] = createStringReference(strparam("Marker"));
  kommunenavn[121] = createStringReference(strparam("R\u00f8mskog"));
  kommunenavn[122] = createStringReference(strparam("Tr\u00f8gstad"));
  kommunenavn[123] = createStringReference(strparam("Spydeberg"));
  kommunenavn[124] = createStringReference(strparam("Askim"));
  kommunenavn[125] = createStringReference(strparam("Eidsberg"));
  kommunenavn[127] = createStringReference(strparam("Skiptvet"));
  kommunenavn[128] = createStringReference(strparam("Rakkestad"));
  kommunenavn[135] = createStringReference(strparam("R\u00e5de"));
  kommunenavn[136] = createStringReference(strparam("Rygge"));
  kommunenavn[137] = createStringReference(strparam("V\u00e5ler"));
  kommunenavn[138] = createStringReference(strparam("Hob\u00f8l"));
  kommunenavn[211] = createStringReference(strparam("Vestby"));
  kommunenavn[213] = createStringReference(strparam("Ski"));
  kommunenavn[214] = createStringReference(strparam("\u00c5s"));
  kommunenavn[215] = createStringReference(strparam("Frogn"));
  kommunenavn[216] = createStringReference(strparam("Nesodden"));
  kommunenavn[217] = createStringReference(strparam("Oppeg\u00e5rd"));
  kommunenavn[219] = createStringReference(strparam("B\u00e6rum"));
  kommunenavn[220] = createStringReference(strparam("Asker"));
  kommunenavn[221] = createStringReference(strparam("Aurskog-H\u00f8land"));
  kommunenavn[226] = createStringReference(strparam("S\u00f8rum"));
  kommunenavn[227] = createStringReference(strparam("Fet"));
  kommunenavn[228] = createStringReference(strparam("R\u00e6lingen"));
  kommunenavn[229] = createStringReference(strparam("Enebakk"));
  kommunenavn[230] = createStringReference(strparam("L\u00f8renskog"));
  kommunenavn[231] = createStringReference(strparam("Skedsmo"));
  kommunenavn[233] = createStringReference(strparam("Nittedal"));
  kommunenavn[234] = createStringReference(strparam("Gjerdrum"));
  kommunenavn[235] = createStringReference(strparam("Ullensaker"));
  kommunenavn[236] = createStringReference(strparam("Nes"));
  kommunenavn[237] = createStringReference(strparam("Eidsvoll"));
  kommunenavn[238] = createStringReference(strparam("Nannestad"));
  kommunenavn[239] = createStringReference(strparam("Hurdal"));
  kommunenavn[301] = createStringReference(strparam("Oslo"));
  kommunenavn[402] = createStringReference(strparam("Kongsvinger"));
  kommunenavn[403] = createStringReference(strparam("Hamar"));
  kommunenavn[412] = createStringReference(strparam("Ringsaker"));
  kommunenavn[415] = createStringReference(strparam("L\u00f8ten"));
  kommunenavn[417] = createStringReference(strparam("Stange"));
  kommunenavn[418] = createStringReference(strparam("Nord-Odal"));
  kommunenavn[419] = createStringReference(strparam("S\u00f8r-Odal"));
  kommunenavn[420] = createStringReference(strparam("Eidskog"));
  kommunenavn[423] = createStringReference(strparam("Grue"));
  kommunenavn[425] = createStringReference(strparam("\u00c5snes"));
  kommunenavn[426] = createStringReference(strparam("V\u00e5ler"));
  kommunenavn[427] = createStringReference(strparam("Elverum"));
  kommunenavn[428] = createStringReference(strparam("Trysil"));
  kommunenavn[429] = createStringReference(strparam("\u00c5mot"));
  kommunenavn[430] = createStringReference(strparam("Stor-Elvdal"));
  kommunenavn[432] = createStringReference(strparam("Rendalen"));
  kommunenavn[434] = createStringReference(strparam("Engerdal"));
  kommunenavn[436] = createStringReference(strparam("Tolga"));
  kommunenavn[437] = createStringReference(strparam("Tynset"));
  kommunenavn[438] = createStringReference(strparam("Alvdal"));
  kommunenavn[439] = createStringReference(strparam("Folldal"));
  kommunenavn[441] = createStringReference(strparam("Os"));
  kommunenavn[501] = createStringReference(strparam("Lillehammer"));
  kommunenavn[502] = createStringReference(strparam("Gj\u00f8vik"));
  kommunenavn[511] = createStringReference(strparam("Dovre"));
  kommunenavn[512] = createStringReference(strparam("Lesja"));
  kommunenavn[513] = createStringReference(strparam("Skj\u00e5k"));
  kommunenavn[514] = createStringReference(strparam("Lom"));
  kommunenavn[515] = createStringReference(strparam("V\u00e5g\u00e5"));
  kommunenavn[516] = createStringReference(strparam("Nord-Fron"));
  kommunenavn[517] = createStringReference(strparam("Sel"));
  kommunenavn[519] = createStringReference(strparam("S\u00f8r-Fron"));
  kommunenavn[520] = createStringReference(strparam("Ringebu"));
  kommunenavn[521] = createStringReference(strparam("\u00d8yer"));
  kommunenavn[522] = createStringReference(strparam("Gausdal"));
  kommunenavn[528] = createStringReference(strparam("\u00d8stre Toten"));
  kommunenavn[529] = createStringReference(strparam("Vestre Toten"));
  kommunenavn[532] = createStringReference(strparam("Jevnaker"));
  kommunenavn[533] = createStringReference(strparam("Lunner"));
  kommunenavn[534] = createStringReference(strparam("Gran"));
  kommunenavn[536] = createStringReference(strparam("S\u00f8ndre Land"));
  kommunenavn[538] = createStringReference(strparam("Nordre Land"));
  kommunenavn[540] = createStringReference(strparam("S\u00f8r-Aurdal"));
  kommunenavn[541] = createStringReference(strparam("Etnedal"));
  kommunenavn[542] = createStringReference(strparam("Nord-Aurdal"));
  kommunenavn[543] = createStringReference(strparam("Vestre Slidre"));
  kommunenavn[544] = createStringReference(strparam("\u00d8ystre Slidre"));
  kommunenavn[545] = createStringReference(strparam("Vang"));
  kommunenavn[602] = createStringReference(strparam("Drammen"));
  kommunenavn[604] = createStringReference(strparam("Kongsberg"));
  kommunenavn[605] = createStringReference(strparam("Ringerike"));
  kommunenavn[612] = createStringReference(strparam("Hole"));
  kommunenavn[615] = createStringReference(strparam("Fl\u00e5"));
  kommunenavn[616] = createStringReference(strparam("Nes"));
  kommunenavn[617] = createStringReference(strparam("Gol"));
  kommunenavn[618] = createStringReference(strparam("Hemsedal"));
  kommunenavn[619] = createStringReference(strparam("\u00c5l"));
  kommunenavn[620] = createStringReference(strparam("Hol"));
  kommunenavn[621] = createStringReference(strparam("Sigdal"));
  kommunenavn[622] = createStringReference(strparam("Kr\u00f8dsherad"));
  kommunenavn[623] = createStringReference(strparam("Modum"));
  kommunenavn[624] = createStringReference(strparam("\u00d8vre Eiker"));
  kommunenavn[625] = createStringReference(strparam("Nedre Eiker"));
  kommunenavn[626] = createStringReference(strparam("Lier"));
  kommunenavn[627] = createStringReference(strparam("R\u00f8yken"));
  kommunenavn[628] = createStringReference(strparam("Hurum"));
  kommunenavn[631] = createStringReference(strparam("Flesberg"));
  kommunenavn[632] = createStringReference(strparam("Rollag"));
  kommunenavn[633] = createStringReference(strparam("Nore og Uvdal"));
  kommunenavn[701] = createStringReference(strparam("Horten"));
  kommunenavn[702] = createStringReference(strparam("Holmestrand"));
  kommunenavn[704] = createStringReference(strparam("T\u00f8nsberg"));
  kommunenavn[709] = createStringReference(strparam("Larvik"));
  kommunenavn[710] = createStringReference(strparam("Sandefjord"));
  kommunenavn[711] = createStringReference(strparam("Svelvik"));
  kommunenavn[713] = createStringReference(strparam("Sande"));
  kommunenavn[714] = createStringReference(strparam("Hof"));
  kommunenavn[716] = createStringReference(strparam("Re"));
  kommunenavn[722] = createStringReference(strparam("N\u00f8tter\u00f8y"));
  kommunenavn[723] = createStringReference(strparam("Tj\u00f8me"));
  kommunenavn[728] = createStringReference(strparam("Lardal"));
  kommunenavn[805] = createStringReference(strparam("Porsgrunn"));
  kommunenavn[806] = createStringReference(strparam("Skien"));
  kommunenavn[807] = createStringReference(strparam("Notodden"));
  kommunenavn[811] = createStringReference(strparam("Siljan"));
  kommunenavn[814] = createStringReference(strparam("Bamble"));
  kommunenavn[815] = createStringReference(strparam("Krager\u00f8"));
  kommunenavn[817] = createStringReference(strparam("Drangedal"));
  kommunenavn[819] = createStringReference(strparam("Nome"));
  kommunenavn[821] = createStringReference(strparam("B\u00f8"));
  kommunenavn[822] = createStringReference(strparam("Sauherad"));
  kommunenavn[826] = createStringReference(strparam("Tinn"));
  kommunenavn[827] = createStringReference(strparam("Hjartdal"));
  kommunenavn[828] = createStringReference(strparam("Seljord"));
  kommunenavn[829] = createStringReference(strparam("Kviteseid"));
  kommunenavn[830] = createStringReference(strparam("Nissedal"));
  kommunenavn[831] = createStringReference(strparam("Fyresdal"));
  kommunenavn[833] = createStringReference(strparam("Tokke"));
  kommunenavn[834] = createStringReference(strparam("Vinje"));
  kommunenavn[901] = createStringReference(strparam("Ris\u00f8r"));
  kommunenavn[904] = createStringReference(strparam("Grimstad"));
  kommunenavn[906] = createStringReference(strparam("Arendal"));
  kommunenavn[911] = createStringReference(strparam("Gjerstad"));
  kommunenavn[912] = createStringReference(strparam("Veg\u00e5rshei"));
  kommunenavn[914] = createStringReference(strparam("Tvedestrand"));
  kommunenavn[919] = createStringReference(strparam("Froland"));
  kommunenavn[926] = createStringReference(strparam("Lillesand"));
  kommunenavn[928] = createStringReference(strparam("Birkenes"));
  kommunenavn[929] = createStringReference(strparam("\u00c5mli"));
  kommunenavn[935] = createStringReference(strparam("Iveland"));
  kommunenavn[937] = createStringReference(strparam("Evje og Hornnes"));
  kommunenavn[938] = createStringReference(strparam("Bygland"));
  kommunenavn[940] = createStringReference(strparam("Valle"));
  kommunenavn[941] = createStringReference(strparam("Bykle"));
  kommunenavn[1001] = createStringReference(strparam("Kristiansand"));
  kommunenavn[1002] = createStringReference(strparam("Mandal"));
  kommunenavn[1003] = createStringReference(strparam("Farsund"));
  kommunenavn[1004] = createStringReference(strparam("Flekkefjord"));
  kommunenavn[1014] = createStringReference(strparam("Vennesla"));
  kommunenavn[1017] = createStringReference(strparam("Songdalen"));
  kommunenavn[1018] = createStringReference(strparam("S\u00f8gne"));
  kommunenavn[1021] = createStringReference(strparam("Marnardal"));
  kommunenavn[1026] = createStringReference(strparam("\u00c5seral"));
  kommunenavn[1027] = createStringReference(strparam("Audnedal"));
  kommunenavn[1029] = createStringReference(strparam("Lindesnes"));
  kommunenavn[1032] = createStringReference(strparam("Lyngdal"));
  kommunenavn[1034] = createStringReference(strparam("H\u00e6gebostad"));
  kommunenavn[1037] = createStringReference(strparam("Kvinesdal"));
  kommunenavn[1046] = createStringReference(strparam("Sirdal"));
  kommunenavn[1101] = createStringReference(strparam("Eigersund"));
  kommunenavn[1102] = createStringReference(strparam("Sandnes"));
  kommunenavn[1103] = createStringReference(strparam("Stavanger"));
  kommunenavn[1106] = createStringReference(strparam("Haugesund"));
  kommunenavn[1111] = createStringReference(strparam("Sokndal"));
  kommunenavn[1112] = createStringReference(strparam("Lund"));
  kommunenavn[1114] = createStringReference(strparam("Bjerkreim"));
  kommunenavn[1119] = createStringReference(strparam("H\u00e5"));
  kommunenavn[1120] = createStringReference(strparam("Klepp"));
  kommunenavn[1121] = createStringReference(strparam("Time"));
  kommunenavn[1122] = createStringReference(strparam("Gjesdal"));
  kommunenavn[1124] = createStringReference(strparam("Sola"));
  kommunenavn[1127] = createStringReference(strparam("Randaberg"));
  kommunenavn[1129] = createStringReference(strparam("Forsand"));
  kommunenavn[1130] = createStringReference(strparam("Strand"));
  kommunenavn[1133] = createStringReference(strparam("Hjelmeland"));
  kommunenavn[1134] = createStringReference(strparam("Suldal"));
  kommunenavn[1135] = createStringReference(strparam("Sauda"));
  kommunenavn[1141] = createStringReference(strparam("Finn\u00f8y"));
  kommunenavn[1142] = createStringReference(strparam("Rennes\u00f8y"));
  kommunenavn[1144] = createStringReference(strparam("Kvits\u00f8y"));
  kommunenavn[1145] = createStringReference(strparam("Bokn"));
  kommunenavn[1146] = createStringReference(strparam("Tysv\u00e6r"));
  kommunenavn[1149] = createStringReference(strparam("Karm\u00f8y"));
  kommunenavn[1151] = createStringReference(strparam("Utsira"));
  kommunenavn[1160] = createStringReference(strparam("Vindafjord"));
  kommunenavn[1201] = createStringReference(strparam("Bergen"));
  kommunenavn[1211] = createStringReference(strparam("Etne"));
  kommunenavn[1216] = createStringReference(strparam("Sveio"));
  kommunenavn[1219] = createStringReference(strparam("B\u00f8mlo"));
  kommunenavn[1221] = createStringReference(strparam("Stord"));
  kommunenavn[1222] = createStringReference(strparam("Fitjar"));
  kommunenavn[1223] = createStringReference(strparam("Tysnes"));
  kommunenavn[1224] = createStringReference(strparam("Kvinnherad"));
  kommunenavn[1227] = createStringReference(strparam("Jondal"));
  kommunenavn[1228] = createStringReference(strparam("Odda"));
  kommunenavn[1231] = createStringReference(strparam("Ullensvang"));
  kommunenavn[1232] = createStringReference(strparam("Eidfjord"));
  kommunenavn[1233] = createStringReference(strparam("Ulvik"));
  kommunenavn[1234] = createStringReference(strparam("Granvin"));
  kommunenavn[1235] = createStringReference(strparam("Voss"));
  kommunenavn[1238] = createStringReference(strparam("Kvam"));
  kommunenavn[1241] = createStringReference(strparam("Fusa"));
  kommunenavn[1242] = createStringReference(strparam("Samnanger"));
  kommunenavn[1243] = createStringReference(strparam("Os"));
  kommunenavn[1244] = createStringReference(strparam("Austevoll"));
  kommunenavn[1245] = createStringReference(strparam("Sund"));
  kommunenavn[1246] = createStringReference(strparam("Fjell"));
  kommunenavn[1247] = createStringReference(strparam("Ask\u00f8y"));
  kommunenavn[1251] = createStringReference(strparam("Vaksdal"));
  kommunenavn[1252] = createStringReference(strparam("Modalen"));
  kommunenavn[1253] = createStringReference(strparam("Oster\u00f8y"));
  kommunenavn[1256] = createStringReference(strparam("Meland"));
  kommunenavn[1259] = createStringReference(strparam("\u00d8ygarden"));
  kommunenavn[1260] = createStringReference(strparam("Rad\u00f8y"));
  kommunenavn[1263] = createStringReference(strparam("Lind\u00e5s"));
  kommunenavn[1264] = createStringReference(strparam("Austrheim"));
  kommunenavn[1265] = createStringReference(strparam("Fedje"));
  kommunenavn[1266] = createStringReference(strparam("Masfjorden"));
  kommunenavn[1401] = createStringReference(strparam("Flora"));
  kommunenavn[1411] = createStringReference(strparam("Gulen"));
  kommunenavn[1412] = createStringReference(strparam("Solund"));
  kommunenavn[1413] = createStringReference(strparam("Hyllestad"));
  kommunenavn[1416] = createStringReference(strparam("H\u00f8yanger"));
  kommunenavn[1417] = createStringReference(strparam("Vik"));
  kommunenavn[1418] = createStringReference(strparam("Balestrand"));
  kommunenavn[1419] = createStringReference(strparam("Leikanger"));
  kommunenavn[1420] = createStringReference(strparam("Sogndal"));
  kommunenavn[1421] = createStringReference(strparam("Aurland"));
  kommunenavn[1422] = createStringReference(strparam("L\u00e6rdal"));
  kommunenavn[1424] = createStringReference(strparam("\u00c5rdal"));
  kommunenavn[1426] = createStringReference(strparam("Luster"));
  kommunenavn[1428] = createStringReference(strparam("Askvoll"));
  kommunenavn[1429] = createStringReference(strparam("Fjaler"));
  kommunenavn[1430] = createStringReference(strparam("Gaular"));
  kommunenavn[1431] = createStringReference(strparam("J\u00f8lster"));
  kommunenavn[1432] = createStringReference(strparam("F\u00f8rde"));
  kommunenavn[1433] = createStringReference(strparam("Naustdal"));
  kommunenavn[1438] = createStringReference(strparam("Bremanger"));
  kommunenavn[1439] = createStringReference(strparam("V\u00e5gs\u00f8y"));
  kommunenavn[1441] = createStringReference(strparam("Selje"));
  kommunenavn[1443] = createStringReference(strparam("Eid"));
  kommunenavn[1444] = createStringReference(strparam("Hornindal"));
  kommunenavn[1445] = createStringReference(strparam("Gloppen"));
  kommunenavn[1449] = createStringReference(strparam("Stryn"));
  kommunenavn[1502] = createStringReference(strparam("Molde"));
  kommunenavn[1504] = createStringReference(strparam("\u00c5lesund"));
  kommunenavn[1505] = createStringReference(strparam("Kristiansund"));
  kommunenavn[1511] = createStringReference(strparam("Vanylven"));
  kommunenavn[1514] = createStringReference(strparam("Sande"));
  kommunenavn[1515] = createStringReference(strparam("Her\u00f8y"));
  kommunenavn[1516] = createStringReference(strparam("Ulstein"));
  kommunenavn[1517] = createStringReference(strparam("Hareid"));
  kommunenavn[1519] = createStringReference(strparam("Volda"));
  kommunenavn[1520] = createStringReference(strparam("\u00d8rsta"));
  kommunenavn[1523] = createStringReference(strparam("\u00d8rskog"));
  kommunenavn[1524] = createStringReference(strparam("Norddal"));
  kommunenavn[1525] = createStringReference(strparam("Stranda"));
  kommunenavn[1526] = createStringReference(strparam("Stordal"));
  kommunenavn[1528] = createStringReference(strparam("Sykkylven"));
  kommunenavn[1529] = createStringReference(strparam("Skodje"));
  kommunenavn[1531] = createStringReference(strparam("Sula"));
  kommunenavn[1532] = createStringReference(strparam("Giske"));
  kommunenavn[1534] = createStringReference(strparam("Haram"));
  kommunenavn[1535] = createStringReference(strparam("Vestnes"));
  kommunenavn[1539] = createStringReference(strparam("Rauma"));
  kommunenavn[1543] = createStringReference(strparam("Nesset"));
  kommunenavn[1545] = createStringReference(strparam("Midsund"));
  kommunenavn[1546] = createStringReference(strparam("Sand\u00f8y"));
  kommunenavn[1547] = createStringReference(strparam("Aukra"));
  kommunenavn[1548] = createStringReference(strparam("Fr\u00e6na"));
  kommunenavn[1551] = createStringReference(strparam("Eide"));
  kommunenavn[1554] = createStringReference(strparam("Aver\u00f8y"));
  kommunenavn[1557] = createStringReference(strparam("Gjemnes"));
  kommunenavn[1560] = createStringReference(strparam("Tingvoll"));
  kommunenavn[1563] = createStringReference(strparam("Sunndal"));
  kommunenavn[1566] = createStringReference(strparam("Surnadal"));
  kommunenavn[1567] = createStringReference(strparam("Rindal"));
  kommunenavn[1571] = createStringReference(strparam("Halsa"));
  kommunenavn[1573] = createStringReference(strparam("Sm\u00f8la"));
  kommunenavn[1576] = createStringReference(strparam("Aure"));
  kommunenavn[1601] = createStringReference(strparam("Trondheim"));
  kommunenavn[1612] = createStringReference(strparam("Hemne"));
  kommunenavn[1613] = createStringReference(strparam("Snillfjord"));
  kommunenavn[1617] = createStringReference(strparam("Hitra"));
  kommunenavn[1620] = createStringReference(strparam("Fr\u00f8ya"));
  kommunenavn[1621] = createStringReference(strparam("\u00d8rland"));
  kommunenavn[1622] = createStringReference(strparam("Agdenes"));
  kommunenavn[1624] = createStringReference(strparam("Rissa"));
  kommunenavn[1627] = createStringReference(strparam("Bjugn"));
  kommunenavn[1630] = createStringReference(strparam("\u00c5fjord"));
  kommunenavn[1632] = createStringReference(strparam("Roan"));
  kommunenavn[1633] = createStringReference(strparam("Osen"));
  kommunenavn[1634] = createStringReference(strparam("Oppdal"));
  kommunenavn[1635] = createStringReference(strparam("Rennebu"));
  kommunenavn[1636] = createStringReference(strparam("Meldal"));
  kommunenavn[1638] = createStringReference(strparam("Orkdal"));
  kommunenavn[1640] = createStringReference(strparam("R\u00f8ros"));
  kommunenavn[1644] = createStringReference(strparam("Holt\u00e5len"));
  kommunenavn[1648] = createStringReference(strparam("Midtre Gauldal"));
  kommunenavn[1653] = createStringReference(strparam("Melhus"));
  kommunenavn[1657] = createStringReference(strparam("Skaun"));
  kommunenavn[1662] = createStringReference(strparam("Kl\u00e6bu"));
  kommunenavn[1663] = createStringReference(strparam("Malvik"));
  kommunenavn[1664] = createStringReference(strparam("Selbu"));
  kommunenavn[1665] = createStringReference(strparam("Tydal"));
  kommunenavn[1702] = createStringReference(strparam("Steinkjer"));
  kommunenavn[1703] = createStringReference(strparam("Namsos"));
  kommunenavn[1711] = createStringReference(strparam("Mer\u00e5ker"));
  kommunenavn[1714] = createStringReference(strparam("Stj\u00f8rdal"));
  kommunenavn[1717] = createStringReference(strparam("Frosta"));
  kommunenavn[1718] = createStringReference(strparam("Leksvik"));
  kommunenavn[1719] = createStringReference(strparam("Levanger"));
  kommunenavn[1721] = createStringReference(strparam("Verdal"));
  kommunenavn[1724] = createStringReference(strparam("Verran"));
  kommunenavn[1725] = createStringReference(strparam("Namdalseid"));
  kommunenavn[1736] = createStringReference(strparam("Sn\u00e5ase \u2013 Sn\u00e5sa"));
  kommunenavn[1738] = createStringReference(strparam("Lierne"));
  kommunenavn[1739] = createStringReference(strparam("Raarvihke \u2013 R\u00f8yrvik"));
  kommunenavn[1740] = createStringReference(strparam("Namsskogan"));
  kommunenavn[1742] = createStringReference(strparam("Grong"));
  kommunenavn[1743] = createStringReference(strparam("H\u00f8ylandet"));
  kommunenavn[1744] = createStringReference(strparam("Overhalla"));
  kommunenavn[1748] = createStringReference(strparam("Fosnes"));
  kommunenavn[1749] = createStringReference(strparam("Flatanger"));
  kommunenavn[1750] = createStringReference(strparam("Vikna"));
  kommunenavn[1751] = createStringReference(strparam("N\u00e6r\u00f8y"));
  kommunenavn[1755] = createStringReference(strparam("Leka"));
  kommunenavn[1756] = createStringReference(strparam("Inder\u00f8y"));
  kommunenavn[1804] = createStringReference(strparam("Bod\u00f8"));
  kommunenavn[1805] = createStringReference(strparam("Narvik"));
  kommunenavn[1811] = createStringReference(strparam("Bindal"));
  kommunenavn[1812] = createStringReference(strparam("S\u00f8mna"));
  kommunenavn[1813] = createStringReference(strparam("Br\u00f8nn\u00f8y"));
  kommunenavn[1815] = createStringReference(strparam("Vega"));
  kommunenavn[1816] = createStringReference(strparam("Vevelstad"));
  kommunenavn[1818] = createStringReference(strparam("Her\u00f8y"));
  kommunenavn[1820] = createStringReference(strparam("Alstahaug"));
  kommunenavn[1822] = createStringReference(strparam("Leirfjord"));
  kommunenavn[1824] = createStringReference(strparam("Vefsn"));
  kommunenavn[1825] = createStringReference(strparam("Grane"));
  kommunenavn[1826] = createStringReference(strparam("Hattfjelldal"));
  kommunenavn[1827] = createStringReference(strparam("D\u00f8nna"));
  kommunenavn[1828] = createStringReference(strparam("Nesna"));
  kommunenavn[1832] = createStringReference(strparam("Hemnes"));
  kommunenavn[1833] = createStringReference(strparam("Rana"));
  kommunenavn[1834] = createStringReference(strparam("Lur\u00f8y"));
  kommunenavn[1835] = createStringReference(strparam("Tr\u00e6na"));
  kommunenavn[1836] = createStringReference(strparam("R\u00f8d\u00f8y"));
  kommunenavn[1837] = createStringReference(strparam("Mel\u00f8y"));
  kommunenavn[1838] = createStringReference(strparam("Gildesk\u00e5l"));
  kommunenavn[1839] = createStringReference(strparam("Beiarn"));
  kommunenavn[1840] = createStringReference(strparam("Saltdal"));
  kommunenavn[1841] = createStringReference(strparam("Fauske \u2013 Fuossko"));
  kommunenavn[1845] = createStringReference(strparam("S\u00f8rfold"));
  kommunenavn[1848] = createStringReference(strparam("Steigen"));
  kommunenavn[1849] = createStringReference(strparam("Hamar\u00f8y \u2013 H\u00e1bmer"));
  kommunenavn[1850] = createStringReference(strparam("Divtasvuodna \u2013 Tysfjord"));
  kommunenavn[1851] = createStringReference(strparam("L\u00f8dingen"));
  kommunenavn[1852] = createStringReference(strparam("Tjeldsund"));
  kommunenavn[1853] = createStringReference(strparam("Evenes"));
  kommunenavn[1854] = createStringReference(strparam("Ballangen"));
  kommunenavn[1856] = createStringReference(strparam("R\u00f8st"));
  kommunenavn[1857] = createStringReference(strparam("V\u00e6r\u00f8y"));
  kommunenavn[1859] = createStringReference(strparam("Flakstad"));
  kommunenavn[1860] = createStringReference(strparam("Vestv\u00e5g\u00f8y"));
  kommunenavn[1865] = createStringReference(strparam("V\u00e5gan"));
  kommunenavn[1866] = createStringReference(strparam("Hadsel"));
  kommunenavn[1867] = createStringReference(strparam("B\u00f8"));
  kommunenavn[1868] = createStringReference(strparam("\u00d8ksnes"));
  kommunenavn[1870] = createStringReference(strparam("Sortland \u2013 Suort\u00e1"));
  kommunenavn[1871] = createStringReference(strparam("And\u00f8y"));
  kommunenavn[1874] = createStringReference(strparam("Moskenes"));
  kommunenavn[1903] = createStringReference(strparam("Harstad \u2013 H\u00e1rstt\u00e1k"));
  kommunenavn[1902] = createStringReference(strparam("Troms\u00f8"));
  kommunenavn[1911] = createStringReference(strparam("Kv\u00e6fjord"));
  kommunenavn[1913] = createStringReference(strparam("Sk\u00e5nland"));
  kommunenavn[1917] = createStringReference(strparam("Ibestad"));
  kommunenavn[1919] = createStringReference(strparam("Gratangen"));
  kommunenavn[1920] = createStringReference(strparam("Loab\u00e1k \u2013 Lavangen"));
  kommunenavn[1922] = createStringReference(strparam("Bardu"));
  kommunenavn[1923] = createStringReference(strparam("Salangen"));
  kommunenavn[1924] = createStringReference(strparam("M\u00e5lselv"));
  kommunenavn[1925] = createStringReference(strparam("S\u00f8rreisa"));
  kommunenavn[1926] = createStringReference(strparam("Dyr\u00f8y"));
  kommunenavn[1927] = createStringReference(strparam("Tran\u00f8y"));
  kommunenavn[1928] = createStringReference(strparam("Torsken"));
  kommunenavn[1929] = createStringReference(strparam("Berg"));
  kommunenavn[1931] = createStringReference(strparam("Lenvik"));
  kommunenavn[1933] = createStringReference(strparam("Balsfjord"));
  kommunenavn[1936] = createStringReference(strparam("Karls\u00f8y"));
  kommunenavn[1938] = createStringReference(strparam("Lyngen"));
  kommunenavn[1939] = createStringReference(strparam("Storfjord \u2013 Omasvuotna \u2013 Omasvuono"));
  kommunenavn[1940] = createStringReference(strparam("G\u00e1ivuotna \u2013 K\u00e5fjord \u2013 Kaivuono"));
  kommunenavn[1941] = createStringReference(strparam("Skjerv\u00f8y"));
  kommunenavn[1942] = createStringReference(strparam("Nordreisa"));
  kommunenavn[1943] = createStringReference(strparam("Kv\u00e6nangen"));
  kommunenavn[2002] = createStringReference(strparam("Vard\u00f8"));
  kommunenavn[2003] = createStringReference(strparam("Vads\u00f8"));
  kommunenavn[2004] = createStringReference(strparam("Hammerfest"));
  kommunenavn[2011] = createStringReference(strparam("Guovdageaidnu \u2013 Kautokeino"));
  kommunenavn[2012] = createStringReference(strparam("Alta"));
  kommunenavn[2014] = createStringReference(strparam("Loppa"));
  kommunenavn[2015] = createStringReference(strparam("Hasvik"));
  kommunenavn[2017] = createStringReference(strparam("Kvalsund"));
  kommunenavn[2018] = createStringReference(strparam("M\u00e5s\u00f8y"));
  kommunenavn[2019] = createStringReference(strparam("Nordkapp"));
  kommunenavn[2020] = createStringReference(strparam("Porsanger \u2013 Pors\u00e1\u014bgu \u2013 Porsanki"));
  kommunenavn[2021] = createStringReference(strparam("K\u00e1r\u00e1\u0161johka \u2013 Karasjok"));
  kommunenavn[2022] = createStringReference(strparam("Lebesby"));
  kommunenavn[2023] = createStringReference(strparam("Gamvik"));
  kommunenavn[2024] = createStringReference(strparam("Berlev\u00e5g"));
  kommunenavn[2025] = createStringReference(strparam("Deatnu \u2013 Tana"));
  kommunenavn[2027] = createStringReference(strparam("Unj\u00e1rga \u2013 Nesseby"));
  kommunenavn[2028] = createStringReference(strparam("B\u00e5tsfjord"));
  kommunenavn[2030] = createStringReference(strparam("S\u00f8r-Varanger"));

  *returnArrayLength = kommunenavnLength;
  return kommunenavn;
}
double *hentGyldigeKommunenummer(size_t *returnArrayLength){
  double *gyldigeKommunenummer;
  size_t gyldigeKommunenummerLength;

  gyldigeKommunenummer = (double*)malloc(sizeof(double) * (425.0 + 1.0));
  gyldigeKommunenummerLength = 425.0 + 1.0;

  gyldigeKommunenummer[0] = 101.0;
  gyldigeKommunenummer[1] = 104.0;
  gyldigeKommunenummer[2] = 105.0;
  gyldigeKommunenummer[3] = 106.0;
  gyldigeKommunenummer[4] = 111.0;
  gyldigeKommunenummer[5] = 118.0;
  gyldigeKommunenummer[6] = 119.0;
  gyldigeKommunenummer[7] = 121.0;
  gyldigeKommunenummer[8] = 122.0;
  gyldigeKommunenummer[9] = 123.0;
  gyldigeKommunenummer[10] = 124.0;
  gyldigeKommunenummer[11] = 125.0;
  gyldigeKommunenummer[12] = 127.0;
  gyldigeKommunenummer[13] = 128.0;
  gyldigeKommunenummer[14] = 135.0;
  gyldigeKommunenummer[15] = 136.0;
  gyldigeKommunenummer[16] = 137.0;
  gyldigeKommunenummer[17] = 138.0;
  gyldigeKommunenummer[18] = 211.0;
  gyldigeKommunenummer[19] = 213.0;
  gyldigeKommunenummer[20] = 214.0;
  gyldigeKommunenummer[21] = 215.0;
  gyldigeKommunenummer[22] = 216.0;
  gyldigeKommunenummer[23] = 217.0;
  gyldigeKommunenummer[24] = 219.0;
  gyldigeKommunenummer[25] = 220.0;
  gyldigeKommunenummer[26] = 221.0;
  gyldigeKommunenummer[27] = 226.0;
  gyldigeKommunenummer[28] = 227.0;
  gyldigeKommunenummer[29] = 228.0;
  gyldigeKommunenummer[30] = 229.0;
  gyldigeKommunenummer[31] = 230.0;
  gyldigeKommunenummer[32] = 231.0;
  gyldigeKommunenummer[33] = 233.0;
  gyldigeKommunenummer[34] = 234.0;
  gyldigeKommunenummer[35] = 235.0;
  gyldigeKommunenummer[36] = 236.0;
  gyldigeKommunenummer[37] = 237.0;
  gyldigeKommunenummer[38] = 238.0;
  gyldigeKommunenummer[39] = 239.0;
  gyldigeKommunenummer[40] = 301.0;
  gyldigeKommunenummer[41] = 402.0;
  gyldigeKommunenummer[42] = 403.0;
  gyldigeKommunenummer[43] = 412.0;
  gyldigeKommunenummer[44] = 415.0;
  gyldigeKommunenummer[45] = 417.0;
  gyldigeKommunenummer[46] = 418.0;
  gyldigeKommunenummer[47] = 419.0;
  gyldigeKommunenummer[48] = 420.0;
  gyldigeKommunenummer[49] = 423.0;
  gyldigeKommunenummer[50] = 425.0;
  gyldigeKommunenummer[51] = 426.0;
  gyldigeKommunenummer[52] = 427.0;
  gyldigeKommunenummer[53] = 428.0;
  gyldigeKommunenummer[54] = 429.0;
  gyldigeKommunenummer[55] = 430.0;
  gyldigeKommunenummer[56] = 432.0;
  gyldigeKommunenummer[57] = 434.0;
  gyldigeKommunenummer[58] = 436.0;
  gyldigeKommunenummer[59] = 437.0;
  gyldigeKommunenummer[60] = 438.0;
  gyldigeKommunenummer[61] = 439.0;
  gyldigeKommunenummer[62] = 441.0;
  gyldigeKommunenummer[63] = 501.0;
  gyldigeKommunenummer[64] = 502.0;
  gyldigeKommunenummer[65] = 511.0;
  gyldigeKommunenummer[66] = 512.0;
  gyldigeKommunenummer[67] = 513.0;
  gyldigeKommunenummer[68] = 514.0;
  gyldigeKommunenummer[69] = 515.0;
  gyldigeKommunenummer[70] = 516.0;
  gyldigeKommunenummer[71] = 517.0;
  gyldigeKommunenummer[72] = 519.0;
  gyldigeKommunenummer[73] = 520.0;
  gyldigeKommunenummer[74] = 521.0;
  gyldigeKommunenummer[75] = 522.0;
  gyldigeKommunenummer[76] = 528.0;
  gyldigeKommunenummer[77] = 529.0;
  gyldigeKommunenummer[78] = 532.0;
  gyldigeKommunenummer[79] = 533.0;
  gyldigeKommunenummer[80] = 534.0;
  gyldigeKommunenummer[81] = 536.0;
  gyldigeKommunenummer[82] = 538.0;
  gyldigeKommunenummer[83] = 540.0;
  gyldigeKommunenummer[84] = 541.0;
  gyldigeKommunenummer[85] = 542.0;
  gyldigeKommunenummer[86] = 543.0;
  gyldigeKommunenummer[87] = 544.0;
  gyldigeKommunenummer[88] = 545.0;
  gyldigeKommunenummer[89] = 602.0;
  gyldigeKommunenummer[90] = 604.0;
  gyldigeKommunenummer[91] = 605.0;
  gyldigeKommunenummer[92] = 612.0;
  gyldigeKommunenummer[93] = 615.0;
  gyldigeKommunenummer[94] = 616.0;
  gyldigeKommunenummer[95] = 617.0;
  gyldigeKommunenummer[96] = 618.0;
  gyldigeKommunenummer[97] = 619.0;
  gyldigeKommunenummer[98] = 620.0;
  gyldigeKommunenummer[99] = 621.0;
  gyldigeKommunenummer[100] = 622.0;
  gyldigeKommunenummer[101] = 623.0;
  gyldigeKommunenummer[102] = 624.0;
  gyldigeKommunenummer[103] = 625.0;
  gyldigeKommunenummer[104] = 626.0;
  gyldigeKommunenummer[105] = 627.0;
  gyldigeKommunenummer[106] = 628.0;
  gyldigeKommunenummer[107] = 631.0;
  gyldigeKommunenummer[108] = 632.0;
  gyldigeKommunenummer[109] = 633.0;
  gyldigeKommunenummer[110] = 701.0;
  gyldigeKommunenummer[111] = 702.0;
  gyldigeKommunenummer[112] = 704.0;
  gyldigeKommunenummer[113] = 709.0;
  gyldigeKommunenummer[114] = 710.0;
  gyldigeKommunenummer[115] = 711.0;
  gyldigeKommunenummer[116] = 713.0;
  gyldigeKommunenummer[117] = 714.0;
  gyldigeKommunenummer[118] = 716.0;
  gyldigeKommunenummer[119] = 722.0;
  gyldigeKommunenummer[120] = 723.0;
  gyldigeKommunenummer[121] = 728.0;
  gyldigeKommunenummer[122] = 805.0;
  gyldigeKommunenummer[123] = 806.0;
  gyldigeKommunenummer[124] = 807.0;
  gyldigeKommunenummer[125] = 811.0;
  gyldigeKommunenummer[126] = 814.0;
  gyldigeKommunenummer[127] = 815.0;
  gyldigeKommunenummer[128] = 817.0;
  gyldigeKommunenummer[129] = 819.0;
  gyldigeKommunenummer[130] = 821.0;
  gyldigeKommunenummer[131] = 822.0;
  gyldigeKommunenummer[132] = 826.0;
  gyldigeKommunenummer[133] = 827.0;
  gyldigeKommunenummer[134] = 828.0;
  gyldigeKommunenummer[135] = 829.0;
  gyldigeKommunenummer[136] = 830.0;
  gyldigeKommunenummer[137] = 831.0;
  gyldigeKommunenummer[138] = 833.0;
  gyldigeKommunenummer[139] = 834.0;
  gyldigeKommunenummer[140] = 901.0;
  gyldigeKommunenummer[141] = 904.0;
  gyldigeKommunenummer[142] = 906.0;
  gyldigeKommunenummer[143] = 911.0;
  gyldigeKommunenummer[144] = 912.0;
  gyldigeKommunenummer[145] = 914.0;
  gyldigeKommunenummer[146] = 919.0;
  gyldigeKommunenummer[147] = 926.0;
  gyldigeKommunenummer[148] = 928.0;
  gyldigeKommunenummer[149] = 929.0;
  gyldigeKommunenummer[150] = 935.0;
  gyldigeKommunenummer[151] = 937.0;
  gyldigeKommunenummer[152] = 938.0;
  gyldigeKommunenummer[153] = 940.0;
  gyldigeKommunenummer[154] = 941.0;
  gyldigeKommunenummer[155] = 1001.0;
  gyldigeKommunenummer[156] = 1002.0;
  gyldigeKommunenummer[157] = 1003.0;
  gyldigeKommunenummer[158] = 1004.0;
  gyldigeKommunenummer[159] = 1014.0;
  gyldigeKommunenummer[160] = 1017.0;
  gyldigeKommunenummer[161] = 1018.0;
  gyldigeKommunenummer[162] = 1021.0;
  gyldigeKommunenummer[163] = 1026.0;
  gyldigeKommunenummer[164] = 1027.0;
  gyldigeKommunenummer[165] = 1029.0;
  gyldigeKommunenummer[166] = 1032.0;
  gyldigeKommunenummer[167] = 1034.0;
  gyldigeKommunenummer[168] = 1037.0;
  gyldigeKommunenummer[169] = 1046.0;
  gyldigeKommunenummer[170] = 1101.0;
  gyldigeKommunenummer[171] = 1102.0;
  gyldigeKommunenummer[172] = 1103.0;
  gyldigeKommunenummer[173] = 1106.0;
  gyldigeKommunenummer[174] = 1111.0;
  gyldigeKommunenummer[175] = 1112.0;
  gyldigeKommunenummer[176] = 1114.0;
  gyldigeKommunenummer[177] = 1119.0;
  gyldigeKommunenummer[178] = 1120.0;
  gyldigeKommunenummer[179] = 1121.0;
  gyldigeKommunenummer[180] = 1122.0;
  gyldigeKommunenummer[181] = 1124.0;
  gyldigeKommunenummer[182] = 1127.0;
  gyldigeKommunenummer[183] = 1129.0;
  gyldigeKommunenummer[184] = 1130.0;
  gyldigeKommunenummer[185] = 1133.0;
  gyldigeKommunenummer[186] = 1134.0;
  gyldigeKommunenummer[187] = 1135.0;
  gyldigeKommunenummer[188] = 1141.0;
  gyldigeKommunenummer[189] = 1142.0;
  gyldigeKommunenummer[190] = 1144.0;
  gyldigeKommunenummer[191] = 1145.0;
  gyldigeKommunenummer[192] = 1146.0;
  gyldigeKommunenummer[193] = 1149.0;
  gyldigeKommunenummer[194] = 1151.0;
  gyldigeKommunenummer[195] = 1160.0;
  gyldigeKommunenummer[196] = 1201.0;
  gyldigeKommunenummer[197] = 1211.0;
  gyldigeKommunenummer[198] = 1216.0;
  gyldigeKommunenummer[199] = 1219.0;
  gyldigeKommunenummer[200] = 1221.0;
  gyldigeKommunenummer[201] = 1222.0;
  gyldigeKommunenummer[202] = 1223.0;
  gyldigeKommunenummer[203] = 1224.0;
  gyldigeKommunenummer[204] = 1227.0;
  gyldigeKommunenummer[205] = 1228.0;
  gyldigeKommunenummer[206] = 1231.0;
  gyldigeKommunenummer[207] = 1232.0;
  gyldigeKommunenummer[208] = 1233.0;
  gyldigeKommunenummer[209] = 1234.0;
  gyldigeKommunenummer[210] = 1235.0;
  gyldigeKommunenummer[211] = 1238.0;
  gyldigeKommunenummer[212] = 1241.0;
  gyldigeKommunenummer[213] = 1242.0;
  gyldigeKommunenummer[214] = 1243.0;
  gyldigeKommunenummer[215] = 1244.0;
  gyldigeKommunenummer[216] = 1245.0;
  gyldigeKommunenummer[217] = 1246.0;
  gyldigeKommunenummer[218] = 1247.0;
  gyldigeKommunenummer[219] = 1251.0;
  gyldigeKommunenummer[220] = 1252.0;
  gyldigeKommunenummer[221] = 1253.0;
  gyldigeKommunenummer[222] = 1256.0;
  gyldigeKommunenummer[223] = 1259.0;
  gyldigeKommunenummer[224] = 1260.0;
  gyldigeKommunenummer[225] = 1263.0;
  gyldigeKommunenummer[226] = 1264.0;
  gyldigeKommunenummer[227] = 1265.0;
  gyldigeKommunenummer[228] = 1266.0;
  gyldigeKommunenummer[229] = 1401.0;
  gyldigeKommunenummer[230] = 1411.0;
  gyldigeKommunenummer[231] = 1412.0;
  gyldigeKommunenummer[232] = 1413.0;
  gyldigeKommunenummer[233] = 1416.0;
  gyldigeKommunenummer[234] = 1417.0;
  gyldigeKommunenummer[235] = 1418.0;
  gyldigeKommunenummer[236] = 1419.0;
  gyldigeKommunenummer[237] = 1420.0;
  gyldigeKommunenummer[238] = 1421.0;
  gyldigeKommunenummer[239] = 1422.0;
  gyldigeKommunenummer[240] = 1424.0;
  gyldigeKommunenummer[241] = 1426.0;
  gyldigeKommunenummer[242] = 1428.0;
  gyldigeKommunenummer[243] = 1429.0;
  gyldigeKommunenummer[244] = 1430.0;
  gyldigeKommunenummer[245] = 1431.0;
  gyldigeKommunenummer[246] = 1432.0;
  gyldigeKommunenummer[247] = 1433.0;
  gyldigeKommunenummer[248] = 1438.0;
  gyldigeKommunenummer[249] = 1439.0;
  gyldigeKommunenummer[250] = 1441.0;
  gyldigeKommunenummer[251] = 1443.0;
  gyldigeKommunenummer[252] = 1444.0;
  gyldigeKommunenummer[253] = 1445.0;
  gyldigeKommunenummer[254] = 1449.0;
  gyldigeKommunenummer[255] = 1502.0;
  gyldigeKommunenummer[256] = 1504.0;
  gyldigeKommunenummer[257] = 1505.0;
  gyldigeKommunenummer[258] = 1511.0;
  gyldigeKommunenummer[259] = 1514.0;
  gyldigeKommunenummer[260] = 1515.0;
  gyldigeKommunenummer[261] = 1516.0;
  gyldigeKommunenummer[262] = 1517.0;
  gyldigeKommunenummer[263] = 1519.0;
  gyldigeKommunenummer[264] = 1520.0;
  gyldigeKommunenummer[265] = 1523.0;
  gyldigeKommunenummer[266] = 1524.0;
  gyldigeKommunenummer[267] = 1525.0;
  gyldigeKommunenummer[268] = 1526.0;
  gyldigeKommunenummer[269] = 1528.0;
  gyldigeKommunenummer[270] = 1529.0;
  gyldigeKommunenummer[271] = 1531.0;
  gyldigeKommunenummer[272] = 1532.0;
  gyldigeKommunenummer[273] = 1534.0;
  gyldigeKommunenummer[274] = 1535.0;
  gyldigeKommunenummer[275] = 1539.0;
  gyldigeKommunenummer[276] = 1543.0;
  gyldigeKommunenummer[277] = 1545.0;
  gyldigeKommunenummer[278] = 1546.0;
  gyldigeKommunenummer[279] = 1547.0;
  gyldigeKommunenummer[280] = 1548.0;
  gyldigeKommunenummer[281] = 1551.0;
  gyldigeKommunenummer[282] = 1554.0;
  gyldigeKommunenummer[283] = 1557.0;
  gyldigeKommunenummer[284] = 1560.0;
  gyldigeKommunenummer[285] = 1563.0;
  gyldigeKommunenummer[286] = 1566.0;
  gyldigeKommunenummer[287] = 1567.0;
  gyldigeKommunenummer[288] = 1571.0;
  gyldigeKommunenummer[289] = 1573.0;
  gyldigeKommunenummer[290] = 1576.0;
  gyldigeKommunenummer[291] = 1601.0;
  gyldigeKommunenummer[292] = 1612.0;
  gyldigeKommunenummer[293] = 1613.0;
  gyldigeKommunenummer[294] = 1617.0;
  gyldigeKommunenummer[295] = 1620.0;
  gyldigeKommunenummer[296] = 1621.0;
  gyldigeKommunenummer[297] = 1622.0;
  gyldigeKommunenummer[298] = 1624.0;
  gyldigeKommunenummer[299] = 1627.0;
  gyldigeKommunenummer[300] = 1630.0;
  gyldigeKommunenummer[301] = 1632.0;
  gyldigeKommunenummer[302] = 1633.0;
  gyldigeKommunenummer[303] = 1634.0;
  gyldigeKommunenummer[304] = 1635.0;
  gyldigeKommunenummer[305] = 1636.0;
  gyldigeKommunenummer[306] = 1638.0;
  gyldigeKommunenummer[307] = 1640.0;
  gyldigeKommunenummer[308] = 1644.0;
  gyldigeKommunenummer[309] = 1648.0;
  gyldigeKommunenummer[310] = 1653.0;
  gyldigeKommunenummer[311] = 1657.0;
  gyldigeKommunenummer[312] = 1662.0;
  gyldigeKommunenummer[313] = 1663.0;
  gyldigeKommunenummer[314] = 1664.0;
  gyldigeKommunenummer[315] = 1665.0;
  gyldigeKommunenummer[316] = 1702.0;
  gyldigeKommunenummer[317] = 1703.0;
  gyldigeKommunenummer[318] = 1711.0;
  gyldigeKommunenummer[319] = 1714.0;
  gyldigeKommunenummer[320] = 1717.0;
  gyldigeKommunenummer[321] = 1718.0;
  gyldigeKommunenummer[322] = 1719.0;
  gyldigeKommunenummer[323] = 1721.0;
  gyldigeKommunenummer[324] = 1724.0;
  gyldigeKommunenummer[325] = 1725.0;
  gyldigeKommunenummer[326] = 1736.0;
  gyldigeKommunenummer[327] = 1738.0;
  gyldigeKommunenummer[328] = 1739.0;
  gyldigeKommunenummer[329] = 1740.0;
  gyldigeKommunenummer[330] = 1742.0;
  gyldigeKommunenummer[331] = 1743.0;
  gyldigeKommunenummer[332] = 1744.0;
  gyldigeKommunenummer[333] = 1748.0;
  gyldigeKommunenummer[334] = 1749.0;
  gyldigeKommunenummer[335] = 1750.0;
  gyldigeKommunenummer[336] = 1751.0;
  gyldigeKommunenummer[337] = 1755.0;
  gyldigeKommunenummer[338] = 1756.0;
  gyldigeKommunenummer[339] = 1804.0;
  gyldigeKommunenummer[340] = 1805.0;
  gyldigeKommunenummer[341] = 1811.0;
  gyldigeKommunenummer[342] = 1812.0;
  gyldigeKommunenummer[343] = 1813.0;
  gyldigeKommunenummer[344] = 1815.0;
  gyldigeKommunenummer[345] = 1816.0;
  gyldigeKommunenummer[346] = 1818.0;
  gyldigeKommunenummer[347] = 1820.0;
  gyldigeKommunenummer[348] = 1822.0;
  gyldigeKommunenummer[349] = 1824.0;
  gyldigeKommunenummer[350] = 1825.0;
  gyldigeKommunenummer[351] = 1826.0;
  gyldigeKommunenummer[352] = 1827.0;
  gyldigeKommunenummer[353] = 1828.0;
  gyldigeKommunenummer[354] = 1832.0;
  gyldigeKommunenummer[355] = 1833.0;
  gyldigeKommunenummer[356] = 1834.0;
  gyldigeKommunenummer[357] = 1835.0;
  gyldigeKommunenummer[358] = 1836.0;
  gyldigeKommunenummer[359] = 1837.0;
  gyldigeKommunenummer[360] = 1838.0;
  gyldigeKommunenummer[361] = 1839.0;
  gyldigeKommunenummer[362] = 1840.0;
  gyldigeKommunenummer[363] = 1841.0;
  gyldigeKommunenummer[364] = 1845.0;
  gyldigeKommunenummer[365] = 1848.0;
  gyldigeKommunenummer[366] = 1849.0;
  gyldigeKommunenummer[367] = 1850.0;
  gyldigeKommunenummer[368] = 1851.0;
  gyldigeKommunenummer[369] = 1852.0;
  gyldigeKommunenummer[370] = 1853.0;
  gyldigeKommunenummer[371] = 1854.0;
  gyldigeKommunenummer[372] = 1856.0;
  gyldigeKommunenummer[373] = 1857.0;
  gyldigeKommunenummer[374] = 1859.0;
  gyldigeKommunenummer[375] = 1860.0;
  gyldigeKommunenummer[376] = 1865.0;
  gyldigeKommunenummer[377] = 1866.0;
  gyldigeKommunenummer[378] = 1867.0;
  gyldigeKommunenummer[379] = 1868.0;
  gyldigeKommunenummer[380] = 1870.0;
  gyldigeKommunenummer[381] = 1871.0;
  gyldigeKommunenummer[382] = 1874.0;
  gyldigeKommunenummer[383] = 1903.0;
  gyldigeKommunenummer[384] = 1902.0;
  gyldigeKommunenummer[385] = 1911.0;
  gyldigeKommunenummer[386] = 1913.0;
  gyldigeKommunenummer[387] = 1917.0;
  gyldigeKommunenummer[388] = 1919.0;
  gyldigeKommunenummer[389] = 1920.0;
  gyldigeKommunenummer[390] = 1922.0;
  gyldigeKommunenummer[391] = 1923.0;
  gyldigeKommunenummer[392] = 1924.0;
  gyldigeKommunenummer[393] = 1925.0;
  gyldigeKommunenummer[394] = 1926.0;
  gyldigeKommunenummer[395] = 1927.0;
  gyldigeKommunenummer[396] = 1928.0;
  gyldigeKommunenummer[397] = 1929.0;
  gyldigeKommunenummer[398] = 1931.0;
  gyldigeKommunenummer[399] = 1933.0;
  gyldigeKommunenummer[400] = 1936.0;
  gyldigeKommunenummer[401] = 1938.0;
  gyldigeKommunenummer[402] = 1939.0;
  gyldigeKommunenummer[403] = 1940.0;
  gyldigeKommunenummer[404] = 1941.0;
  gyldigeKommunenummer[405] = 1942.0;
  gyldigeKommunenummer[406] = 1943.0;
  gyldigeKommunenummer[407] = 2002.0;
  gyldigeKommunenummer[408] = 2003.0;
  gyldigeKommunenummer[409] = 2004.0;
  gyldigeKommunenummer[410] = 2011.0;
  gyldigeKommunenummer[411] = 2012.0;
  gyldigeKommunenummer[412] = 2014.0;
  gyldigeKommunenummer[413] = 2015.0;
  gyldigeKommunenummer[414] = 2017.0;
  gyldigeKommunenummer[415] = 2018.0;
  gyldigeKommunenummer[416] = 2019.0;
  gyldigeKommunenummer[417] = 2020.0;
  gyldigeKommunenummer[418] = 2021.0;
  gyldigeKommunenummer[419] = 2022.0;
  gyldigeKommunenummer[420] = 2023.0;
  gyldigeKommunenummer[421] = 2024.0;
  gyldigeKommunenummer[422] = 2025.0;
  gyldigeKommunenummer[423] = 2027.0;
  gyldigeKommunenummer[424] = 2028.0;
  gyldigeKommunenummer[425] = 2030.0;

  *returnArrayLength = gyldigeKommunenummerLength;
  return gyldigeKommunenummer;
}
double test1(){
  DoubleReference *doubleReference;
  Success *success;
  char *kommuenavn;
  size_t kommuenavnLength;

  doubleReference = (DoubleReference *)malloc(sizeof(DoubleReference));
  doubleReference->doubleValue = 0.0;

  success = (Success *)malloc(sizeof(Success));
  kommuenavn = hentKommunenavnFraNummer(&kommuenavnLength, strparam("1640"), success);
  assertStringEquals(kommuenavn, kommuenavnLength, strparam("R\u00f8ros"), doubleReference);
  assertTrue(success->success, doubleReference);

  return doubleReference->doubleValue;
}
double test(){
  double failures;

  failures = 0.0;

  failures = failures + test1();

  return failures;
}
char *decimalToString(size_t *returnArrayLength, double decimal){

    return numberToString(returnArrayLength, decimal, 10.0);
}
char *numberToString(size_t *returnArrayLength, double decimal, double base){
  char *string;
  size_t stringLength;
  double digits;
  double digitPosition;
  _Bool hasPrintedPoint;
  double i, d;

  string = (char*)malloc(sizeof(char) * (0.0));
  stringLength = 0.0;

  digits = getDigits(base);

  /* Find digitPosition: */
  digitPosition = getDigitPosition(decimal, base);

  decimal = round(decimal*pow(base,  -digitPosition  + digits - 1.0));

  hasPrintedPoint = false;

  /* Print leading zeros. */
  if(digitPosition < 0.0){
    string = appendCharacter(&stringLength, string, stringLength, '0');
    string = appendCharacter(&stringLength, string, stringLength, '.');
    hasPrintedPoint = true;
    for(i = 0.0; i <  -digitPosition  - 1.0; i = i + 1.0){
      string = appendCharacter(&stringLength, string, stringLength, '0');
    }
  }

  /* Print number. */
  for(i = 0.0; i < digits; i = i + 1.0){
    d = floor(decimal/pow(base, digits - i - 1.0));
    if( !hasPrintedPoint  && digitPosition - i + 1.0 == 0.0){
      if(decimal != 0.0){
        string = appendCharacter(&stringLength, string, stringLength, '.');
      }
      hasPrintedPoint = true;
    }
    if(decimal == 0.0 && hasPrintedPoint){
    }else{
      string = appendCharacter(&stringLength, string, stringLength, getSingleDigitFromNumber(d, base));
    }
    decimal = decimal - d*pow(base, digits - i - 1.0);
  }

  /* Print trailing zeros. */
  for(i = 0.0; i < digitPosition - digits + 1.0; i = i + 1.0){
    string = appendCharacter(&stringLength, string, stringLength, '0');
  }

  /* Done */
  *returnArrayLength = stringLength;
  return string;
}
double getDigits(double base){
  double t;

  t = pow(10.0, 15.0);
  return floor(log10(t)/log10(base));
}
double getDigitPosition(double decimal, double base){
  double power;
  double t;

  power = ceil(log10(decimal)/log10(base));

  t = decimal*pow(base,  -power );
  if(t < base && t >= 1.0){
  }else if(t >= base){
    power = power + 1.0;
  }else if(t < 1.0){
    power = power - 1.0;
  }


  return power;
}
char getSingleDigitFromNumber(double c, double base){
  char *numberTable;
  size_t numberTableLength;
  char retc;

  numberTable = getNumberTable(&numberTableLength);

  if(c > base - 1.0){
    retc = '?';
  }else{
    retc = numberTable[(int)(c)];
  }

  return retc;
}
char *getNumberTable(size_t *returnArrayLength){
  char *numberTable;
  size_t numberTableLength;

  numberTable = (char*)malloc(sizeof(char) * (16.0));
  numberTableLength = 16.0;
  numberTable[0] = '0';
  numberTable[1] = '1';
  numberTable[2] = '2';
  numberTable[3] = '3';
  numberTable[4] = '4';
  numberTable[5] = '5';
  numberTable[6] = '6';
  numberTable[7] = '7';
  numberTable[8] = '8';
  numberTable[9] = '9';
  numberTable[10] = 'A';
  numberTable[11] = 'B';
  numberTable[12] = 'C';
  numberTable[13] = 'D';
  numberTable[14] = 'E';
  numberTable[15] = 'F';
  *returnArrayLength = numberTableLength;
  return numberTable;
}
StringToDecimalResult *stringToDecimal(char *string, size_t stringLength){

  return stringToDecimalForBase(string, stringLength, 10.0);
}
StringToDecimalResult *stringToDecimalForBase(char *string, size_t stringLength, double base){
  StringToDecimalResult *stringToDecimalResult;
  char c;
  double i, j;
  _Bool isPositive;
  double beforeDecimalPoint;
  double afterDecimalPoint;
  double n;
  double validCharacters;
  double d;

  stringToDecimalResult = (StringToDecimalResult *)malloc(sizeof(StringToDecimalResult));
  stringToDecimalResult->success = true;
  i = 0.0;
  isPositive = true;
  beforeDecimalPoint = 0.0;
  afterDecimalPoint = 0.0;
  n = 0.0;
  validCharacters = 0.0;

  if(base >= 2.0 && base <= 16.0){
    for(j = 0.0; j < stringLength; j = j + 1.0){
      c = string[(int)(j)];
      if(isNumber(c, base) || c == '.' || c == '-'){
        validCharacters = validCharacters + 1.0;
      }
    }
    if(validCharacters == stringLength){
      if(stringLength > 0.0){
        c = string[(int)(i)];
        if(c == '-'){
          isPositive = false;
          i = i + 1.0;
        }
        if(i < stringLength){
          c = string[(int)(i)];
          if(isNumber(c, base)){
            for(; isNumber(c, base) && (i < stringLength); ){
              beforeDecimalPoint = beforeDecimalPoint + 1.0;
              i = i + 1.0;
              if(i < stringLength){
                c = string[(int)(i)];
              }
            }
            if(i < stringLength){
              c = string[(int)(i)];
              if(c == '.'){
                i = i + 1.0;
                if(i < stringLength){
                  c = string[(int)(i)];
                  for(; isNumber(c, base) && (i < stringLength); ){
                    afterDecimalPoint = afterDecimalPoint + 1.0;
                    i = i + 1.0;
                    if(i < stringLength){
                      c = string[(int)(i)];
                    }
                  }
                }else{
                  stringToDecimalResult->success = false;
                  stringToDecimalResult->feilmelding = "Number must have digits after the decimal point.";
                  stringToDecimalResult->feilmeldingLength = strlen(stringToDecimalResult->feilmelding);
                }
              }
            }
          }else{
            stringToDecimalResult->success = false;
            stringToDecimalResult->feilmelding = "Number must start with digits (for negative numbers, after the optional negative sign).";
            stringToDecimalResult->feilmeldingLength = strlen(stringToDecimalResult->feilmelding);
          }
        }
        if(stringToDecimalResult->success != false){
          i = 0.0;
          if( !isPositive ){
            i = 1.0;
          }
          for(j = 0.0; j < beforeDecimalPoint; j = j + 1.0){
            c = string[(int)(i)];
            i = i + 1.0;
            d = getDecimalFromSingleDecimalDigit(c, base);
            n = n + d*pow(base, beforeDecimalPoint - j - 1.0);
          }
          if(afterDecimalPoint > 0.0){
            i = i + 1.0;
            for(j = 0.0; j < afterDecimalPoint; j = j + 1.0){
              c = string[(int)(i)];
              i = i + 1.0;
              d = getDecimalFromSingleDecimalDigit(c, base);
              n = n + d*pow(base, 0.0 - j - 1.0);
            }
          }
          if( !isPositive ){
            n =  -n ;
          }
          stringToDecimalResult->result = n;
          stringToDecimalResult->success = true;
        }
      }else{
        stringToDecimalResult->success = false;
        stringToDecimalResult->feilmelding = "String has no content.";
        stringToDecimalResult->feilmeldingLength = strlen(stringToDecimalResult->feilmelding);
      }
    }else{
      stringToDecimalResult->success = false;
      stringToDecimalResult->feilmelding = "String contains invalid character.";
      stringToDecimalResult->feilmeldingLength = strlen(stringToDecimalResult->feilmelding);
    }
  }else{
    stringToDecimalResult->success = false;
    stringToDecimalResult->feilmelding = "Base must be from 2 to 16.";
    stringToDecimalResult->feilmeldingLength = strlen(stringToDecimalResult->feilmelding);
  }

  return stringToDecimalResult;
}
double getDecimalFromSingleDecimalDigit(char c, double base){
  char *numberTable;
  size_t numberTableLength;
  double i;
  double position;

  numberTable = getNumberTable(&numberTableLength);
  position = 0.0;

  for(i = 0.0; i < base; i = i + 1.0){
    if(numberTable[(int)(i)] == c){
      position = i;
    }
  }

  return position;
}
_Bool isNumber(char c, double base){
  char *numberTable;
  size_t numberTableLength;
  double i;
  _Bool found;

  numberTable = getNumberTable(&numberTableLength);
  found = false;

  for(i = 0.0; i < base; i = i + 1.0){
    if(numberTable[(int)(i)] == c){
      found = true;
    }
  }

  return found;
}
void assertFalse(_Bool b, DoubleReference *failures){

  if(b){
    failures->doubleValue = failures->doubleValue + 1.0;
  }
}
void assertTrue(_Bool b, DoubleReference *failures){

  if( !b ){
    failures->doubleValue = failures->doubleValue + 1.0;
  }
}
void assertEquals(double a, double b, DoubleReference *failures){

  if(a != b){
    failures->doubleValue = failures->doubleValue + 1.0;
  }
}
void assertStringEquals(char *a, size_t aLength, char *b, size_t bLength, DoubleReference *failures){

  if( !stringsEqual(a, aLength, b, bLength) ){
    failures->doubleValue = failures->doubleValue + 1.0;
  }
}
double *stringToNumberArray(size_t *returnArrayLength, char *string, size_t stringLength){
  double i;
  double *array;
  size_t arrayLength;

  array = (double*)malloc(sizeof(double) * (stringLength));
  arrayLength = stringLength;

  for(i = 0.0; i < stringLength; i = i + 1.0){
    array[(int)(i)] = string[(int)(i)];
  }
  *returnArrayLength = arrayLength;
  return array;
}
char *numberArrayToString(size_t *returnArrayLength, double *array, size_t arrayLength){
  double i;
  char *string;
  size_t stringLength;

  string = (char*)malloc(sizeof(char) * (arrayLength));
  stringLength = arrayLength;

  for(i = 0.0; i < arrayLength; i = i + 1.0){
    string[(int)(i)] = array[(int)(i)];
  }
  *returnArrayLength = stringLength;
  return string;
}
_Bool stringsEqual(char *data1, size_t data1Length, char *data2, size_t data2Length){
  _Bool equal;
  double nrEqual, i;

  equal = false;
  if(data1Length == data2Length){
    nrEqual = 0.0;
    for(i = 0.0; i < data1Length; i = i + 1.0){
      if(data1[(int)(i)] == data2[(int)(i)]){
        nrEqual = nrEqual + 1.0;
      }
    }
    if(nrEqual == data1Length){
      equal = true;
    }
  }else{
    equal = false;
  }

  return equal;
}
_Bool numberArraysEqual(double *data1, size_t data1Length, double *data2, size_t data2Length){
  _Bool equal;
  double nrEqual, i;

  equal = false;
  if(data1Length == data2Length){
    nrEqual = 0.0;
    for(i = 0.0; i < data1Length; i = i + 1.0){
      if(data1[(int)(i)] == data2[(int)(i)]){
        nrEqual = nrEqual + 1.0;
      }
    }
    if(nrEqual == data1Length){
      equal = true;
    }
  }else{
    equal = false;
  }

  return equal;
}
char *substring(size_t *returnArrayLength, char *string, size_t stringLength, double from, double to){
  char *n;
  size_t nLength;
  double i;

  n = (char*)malloc(sizeof(char) * (to - from));
  nLength = to - from;

  for(i = from; i < to; i = i + 1.0){
    n[(int)(i - from)] = string[(int)(i)];
  }

  *returnArrayLength = nLength;
  return n;
}
char *appendString(size_t *returnArrayLength, char *string, size_t stringLength, char *s, size_t sLength){
  char *newString;
  size_t newStringLength;
  double i;

  newString = (char*)malloc(sizeof(char) * (stringLength + sLength));
  newStringLength = stringLength + sLength;

  for(i = 0.0; i < stringLength; i = i + 1.0){
    newString[(int)(i)] = string[(int)(i)];
  }

  for(i = 0.0; i < sLength; i = i + 1.0){
    newString[(int)(stringLength + i)] = s[(int)(i)];
  }

  free(string);

  *returnArrayLength = newStringLength;
  return newString;
}
char *appendCharacter(size_t *returnArrayLength, char *string, size_t stringLength, char c){
  char *newString;
  size_t newStringLength;
  double i;

  newString = (char*)malloc(sizeof(char) * (stringLength + 1.0));
  newStringLength = stringLength + 1.0;

  for(i = 0.0; i < stringLength; i = i + 1.0){
    newString[(int)(i)] = string[(int)(i)];
  }

  newString[(int)(stringLength)] = c;

  free(string);

  *returnArrayLength = newStringLength;
  return newString;
}
StringReference **split(size_t *returnArrayLength, char *toSplit, size_t toSplitLength, char splitBy){
  StringReference **splitt;
  size_t splittLength;
  char *next;
  size_t nextLength;
  double i;
  char c;
  StringReference *n;

  splitt = (StringReference**)malloc(sizeof(StringReference) * 0.0);
  splittLength = 0.0;

  next = (char*)malloc(sizeof(char) * (0.0));
  nextLength = 0.0;
  for(i = 0.0; i < toSplitLength; i = i + 1.0){
    c = toSplit[(int)(i)];
    if(c == splitBy){
      n = (StringReference *)malloc(sizeof(StringReference));
      n->string = next;
      n->stringLength = nextLength;
      splitt = addString(&splittLength, splitt, splittLength, n);
      next = (char*)malloc(sizeof(char) * (0.0));
      nextLength = 0.0;
    }else{
      next = appendCharacter(&nextLength, next, nextLength, c);
    }
  }

  if(nextLength > 0.0){
    n = (StringReference *)malloc(sizeof(StringReference));
    n->string = next;
    n->stringLength = nextLength;
    splitt = addString(&splittLength, splitt, splittLength, n);
  }

  *returnArrayLength = splittLength;
  return splitt;
}
double *addDecimal(size_t *returnArrayLength, double *list, size_t listLength, double a){
  double *newlist;
  size_t newlistLength;
  double i;

  newlist = (double*)malloc(sizeof(double) * (listLength + 1.0));
  newlistLength = listLength + 1.0;
  for(i = 0.0; i < listLength; i = i + 1.0){
    newlist[(int)(i)] = list[(int)(i)];
  }
  newlist[(int)(listLength)] = a;
		
  free(list);
		
  *returnArrayLength = newlistLength;
  return newlist;
}
void addDecimalRef(DecimalListRef *list, double i){

  list->list = addDecimal(&list->listLength, list->list, list->listLength, i);
}
double *removeDecimal(size_t *returnArrayLength, double *list, size_t listLength, double n){
  double *newlist;
  size_t newlistLength;
  double i;

  newlist = (double*)malloc(sizeof(double) * (listLength - 1.0));
  newlistLength = listLength - 1.0;

  for(i = 0.0; i < listLength; i = i + 1.0){
    if(i < n){
      newlist[(int)(i)] = list[(int)(i)];
    }
    if(i > n){
      newlist[(int)(i - 1.0)] = list[(int)(i)];
    }
  }
		
  free(list);
		
  *returnArrayLength = newlistLength;
  return newlist;
}
double getDecimalRef(DecimalListRef *list, double i){

  return list->list[(int)(i)];
}
void removeDecimalRef(DecimalListRef *list, double i){

  list->list = removeDecimal(&list->listLength, list->list, list->listLength, i);
}
StringReference **addString(size_t *returnArrayLength, StringReference **list, size_t listLength, StringReference *a){
  StringReference **newlist;
  size_t newlistLength;
  double i;

  newlist = (StringReference**)malloc(sizeof(StringReference) * listLength + 1.0);
  newlistLength = listLength + 1.0;

  for(i = 0.0; i < listLength; i = i + 1.0){
    newlist[(int)(i)] = list[(int)(i)];
  }
  newlist[(int)(listLength)] = a;
		
  free(list);
		
  *returnArrayLength = newlistLength;
  return newlist;
}
void addStringRef(StringListRef *list, StringReference *i){

  list->list = addString(&list->listLength, list->list, list->listLength, i);
}
StringReference **removeString(size_t *returnArrayLength, StringReference **list, size_t listLength, double n){
  StringReference **newlist;
  size_t newlistLength;
  double i;

  newlist = (StringReference**)malloc(sizeof(StringReference) * listLength - 1.0);
  newlistLength = listLength - 1.0;

  for(i = 0.0; i < listLength; i = i + 1.0){
    if(i < n){
      newlist[(int)(i)] = list[(int)(i)];
    }
    if(i > n){
      newlist[(int)(i - 1.0)] = list[(int)(i)];
    }
  }
		
  free(list);
		
  *returnArrayLength = newlistLength;
  return newlist;
}
StringReference *getStringRef(StringListRef *list, double i){

  return list->list[(int)(i)];
}
void removeStringRef(StringListRef *list, double i){

  list->list = removeString(&list->listLength, list->list, list->listLength, i);
}


#include <stdio.h>

int main(){
	printf("%f\n", test());
	return 0;
}