#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

#define toVector(s) (new vector<char> ((s), (s) + strlen(s)))

struct Success;

struct StringToDecimalResult;

struct BooleanReference;

struct DoubleReference;

struct StringReference;

struct DecimalListRef;

struct StringListRef;

struct Success{
  bool success;
  vector<char> *feilmelding;
};

struct StringToDecimalResult{
  double result;
  vector<char> *feilmelding;
  bool success;
};

struct BooleanReference{
  bool booleanValue;
};

struct DoubleReference{
  double doubleValue;
};

struct StringReference{
  vector<char> *string;
};

struct DecimalListRef{
  vector<double> *list;
};

struct StringListRef{
  vector<StringReference*> *list;
};

StringReference *createStringReference(vector<char> *string);

vector<bool> *lagGyldigReversTabell(vector<double> *nummerliste);

vector<char> *hentKommunenavnFraNummer(vector<char> *kommunenummer, Success *success);
bool erGyldigKommunenummer(vector<char> *kommunenummer);
bool erHelttall(double nr);
vector<bool> *hentGyldigKommunetabell();
vector<StringReference*> *hentKommunenavn();
vector<double> *hentGyldigeKommunenummer();

double test1();

double test();

vector<char> *decimalToString(double decimal);
vector<char> *numberToString(double decimal, double base);
double getDigits(double base);
double getDigitPosition(double decimal, double base);
char getSingleDigitFromNumber(double c, double base);
vector<char> *getNumberTable();

StringToDecimalResult *stringToDecimal(vector<char> *string);
StringToDecimalResult *stringToDecimalForBase(vector<char> *string, double base);
double getDecimalFromSingleDecimalDigit(char c, double base);
bool isNumber(char c, double base);

void assertFalse(bool b, DoubleReference *failures);
void assertTrue(bool b, DoubleReference *failures);
void assertEquals(double a, double b, DoubleReference *failures);
void assertStringEquals(vector<char> *a, vector<char> *b, DoubleReference *failures);

vector<double> *stringToNumberArray(vector<char> *string);
vector<char> *numberArrayToString(vector<double> *array);
bool stringsEqual(vector<char> *data1, vector<char> *data2);
bool numberArraysEqual(vector<double> *data1, vector<double> *data2);

vector<char> *substring(vector<char> *string, double from, double to);
vector<char> *appendString(vector<char> *string, vector<char> *s);
vector<char> *appendCharacter(vector<char> *string, char c);
vector<StringReference*> *split(vector<char> *toSplit, char splitBy);


vector<double> *addDecimal(vector<double> *list, double a);
void addDecimalRef(DecimalListRef *list, double i);
vector<double> *removeDecimal(vector<double> *list, double n);
double getDecimalRef(DecimalListRef *list, double i);
void removeDecimalRef(DecimalListRef *list, double i);

vector<StringReference*> *addString(vector<StringReference*> *list, StringReference *a);
void addStringRef(StringListRef *list, StringReference *i);
vector<StringReference*> *removeString(vector<StringReference*> *list, double n);
StringReference *getStringRef(StringListRef *list, double i);
void removeStringRef(StringListRef *list, double i);

StringReference *createStringReference(vector<char> *string){
  StringReference *stringReference;

  stringReference = new StringReference();
  stringReference->string = string;
  return stringReference;
}
vector<bool> *lagGyldigReversTabell(vector<double> *nummerliste){
  double i;
  double maxnummer;
  vector<bool> *inverse;

  maxnummer = 0.0;
  for(i = 0.0; i < nummerliste->size(); i = i + 1.0){
    maxnummer = fmax(maxnummer, (*nummerliste)[(int)(i)]);
  }

  inverse = new vector<bool> (maxnummer + 1.0);

  for(i = 0.0; i < maxnummer; i = i + 1.0){
    (*inverse)[(int)(i)] = false;
  }

  for(i = 0.0; i < nummerliste->size(); i = i + 1.0){
    (*inverse)[(int)((*nummerliste)[(int)(i)])] = true;
  }

  return inverse;
}
vector<char> *hentKommunenavnFraNummer(vector<char> *kommunenummer, Success *success){
  vector<char> *kommunenavn;
  vector<StringReference*> *kommunenavnListe;
  double nr;
  StringToDecimalResult *stringToDecimalResult;

  kommunenavn = new vector<char> (0.0);

  if(erGyldigKommunenummer(kommunenummer)){
    kommunenavnListe = hentKommunenavn();
    stringToDecimalResult = stringToDecimalForBase(kommunenummer, 10.0);
    if(stringToDecimalResult->success){
      nr = stringToDecimalResult->result;
      kommunenavn = (*kommunenavnListe)[(int)(nr)]->string;
      success->success = true;
    }else{
      success->feilmelding = toVector("Kommunenummer var ikke et gyldig tall.");
      success->success = false;
    }
  }else{
    success->success = false;
    success->feilmelding = toVector("Kommunenummer er ikke gyldig.");
  }

  return kommunenavn;
}
bool erGyldigKommunenummer(vector<char> *kommunenummer){
  bool gyldig;
  double nr;
  vector<bool> *gyldigKommunetabell;

  if(kommunenummer->size() == 4.0){
    nr = stringToDecimalForBase(kommunenummer, 10.0)->result;
    if(nr >= 101.0 && nr <= 2030.0 && erHelttall(nr)){
      gyldigKommunetabell = hentGyldigKommunetabell();
      gyldig = (*gyldigKommunetabell)[(int)(nr)];
    }else{
      gyldig = false;
    }
  }else{
    gyldig = false;
  }

  return gyldig;
}
bool erHelttall(double nr){

  return (fmod(nr, 1.0)) == 0.0;
}
vector<bool> *hentGyldigKommunetabell(){
  vector<double> *nummerliste;

  nummerliste = hentGyldigeKommunenummer();
  return lagGyldigReversTabell(nummerliste);
}
vector<StringReference*> *hentKommunenavn(){
  vector<StringReference*> *kommunenavn;

  kommunenavn = new vector<StringReference*> (2100.0);

  (*kommunenavn)[101] = createStringReference(toVector("Halden"));
  (*kommunenavn)[104] = createStringReference(toVector("Moss"));
  (*kommunenavn)[105] = createStringReference(toVector("Sarpsborg"));
  (*kommunenavn)[106] = createStringReference(toVector("Fredrikstad"));
  (*kommunenavn)[111] = createStringReference(toVector("Hvaler"));
  (*kommunenavn)[118] = createStringReference(toVector("Aremark"));
  (*kommunenavn)[119] = createStringReference(toVector("Marker"));
  (*kommunenavn)[121] = createStringReference(toVector("R\u00f8mskog"));
  (*kommunenavn)[122] = createStringReference(toVector("Tr\u00f8gstad"));
  (*kommunenavn)[123] = createStringReference(toVector("Spydeberg"));
  (*kommunenavn)[124] = createStringReference(toVector("Askim"));
  (*kommunenavn)[125] = createStringReference(toVector("Eidsberg"));
  (*kommunenavn)[127] = createStringReference(toVector("Skiptvet"));
  (*kommunenavn)[128] = createStringReference(toVector("Rakkestad"));
  (*kommunenavn)[135] = createStringReference(toVector("R\u00e5de"));
  (*kommunenavn)[136] = createStringReference(toVector("Rygge"));
  (*kommunenavn)[137] = createStringReference(toVector("V\u00e5ler"));
  (*kommunenavn)[138] = createStringReference(toVector("Hob\u00f8l"));
  (*kommunenavn)[211] = createStringReference(toVector("Vestby"));
  (*kommunenavn)[213] = createStringReference(toVector("Ski"));
  (*kommunenavn)[214] = createStringReference(toVector("\u00c5s"));
  (*kommunenavn)[215] = createStringReference(toVector("Frogn"));
  (*kommunenavn)[216] = createStringReference(toVector("Nesodden"));
  (*kommunenavn)[217] = createStringReference(toVector("Oppeg\u00e5rd"));
  (*kommunenavn)[219] = createStringReference(toVector("B\u00e6rum"));
  (*kommunenavn)[220] = createStringReference(toVector("Asker"));
  (*kommunenavn)[221] = createStringReference(toVector("Aurskog-H\u00f8land"));
  (*kommunenavn)[226] = createStringReference(toVector("S\u00f8rum"));
  (*kommunenavn)[227] = createStringReference(toVector("Fet"));
  (*kommunenavn)[228] = createStringReference(toVector("R\u00e6lingen"));
  (*kommunenavn)[229] = createStringReference(toVector("Enebakk"));
  (*kommunenavn)[230] = createStringReference(toVector("L\u00f8renskog"));
  (*kommunenavn)[231] = createStringReference(toVector("Skedsmo"));
  (*kommunenavn)[233] = createStringReference(toVector("Nittedal"));
  (*kommunenavn)[234] = createStringReference(toVector("Gjerdrum"));
  (*kommunenavn)[235] = createStringReference(toVector("Ullensaker"));
  (*kommunenavn)[236] = createStringReference(toVector("Nes"));
  (*kommunenavn)[237] = createStringReference(toVector("Eidsvoll"));
  (*kommunenavn)[238] = createStringReference(toVector("Nannestad"));
  (*kommunenavn)[239] = createStringReference(toVector("Hurdal"));
  (*kommunenavn)[301] = createStringReference(toVector("Oslo"));
  (*kommunenavn)[402] = createStringReference(toVector("Kongsvinger"));
  (*kommunenavn)[403] = createStringReference(toVector("Hamar"));
  (*kommunenavn)[412] = createStringReference(toVector("Ringsaker"));
  (*kommunenavn)[415] = createStringReference(toVector("L\u00f8ten"));
  (*kommunenavn)[417] = createStringReference(toVector("Stange"));
  (*kommunenavn)[418] = createStringReference(toVector("Nord-Odal"));
  (*kommunenavn)[419] = createStringReference(toVector("S\u00f8r-Odal"));
  (*kommunenavn)[420] = createStringReference(toVector("Eidskog"));
  (*kommunenavn)[423] = createStringReference(toVector("Grue"));
  (*kommunenavn)[425] = createStringReference(toVector("\u00c5snes"));
  (*kommunenavn)[426] = createStringReference(toVector("V\u00e5ler"));
  (*kommunenavn)[427] = createStringReference(toVector("Elverum"));
  (*kommunenavn)[428] = createStringReference(toVector("Trysil"));
  (*kommunenavn)[429] = createStringReference(toVector("\u00c5mot"));
  (*kommunenavn)[430] = createStringReference(toVector("Stor-Elvdal"));
  (*kommunenavn)[432] = createStringReference(toVector("Rendalen"));
  (*kommunenavn)[434] = createStringReference(toVector("Engerdal"));
  (*kommunenavn)[436] = createStringReference(toVector("Tolga"));
  (*kommunenavn)[437] = createStringReference(toVector("Tynset"));
  (*kommunenavn)[438] = createStringReference(toVector("Alvdal"));
  (*kommunenavn)[439] = createStringReference(toVector("Folldal"));
  (*kommunenavn)[441] = createStringReference(toVector("Os"));
  (*kommunenavn)[501] = createStringReference(toVector("Lillehammer"));
  (*kommunenavn)[502] = createStringReference(toVector("Gj\u00f8vik"));
  (*kommunenavn)[511] = createStringReference(toVector("Dovre"));
  (*kommunenavn)[512] = createStringReference(toVector("Lesja"));
  (*kommunenavn)[513] = createStringReference(toVector("Skj\u00e5k"));
  (*kommunenavn)[514] = createStringReference(toVector("Lom"));
  (*kommunenavn)[515] = createStringReference(toVector("V\u00e5g\u00e5"));
  (*kommunenavn)[516] = createStringReference(toVector("Nord-Fron"));
  (*kommunenavn)[517] = createStringReference(toVector("Sel"));
  (*kommunenavn)[519] = createStringReference(toVector("S\u00f8r-Fron"));
  (*kommunenavn)[520] = createStringReference(toVector("Ringebu"));
  (*kommunenavn)[521] = createStringReference(toVector("\u00d8yer"));
  (*kommunenavn)[522] = createStringReference(toVector("Gausdal"));
  (*kommunenavn)[528] = createStringReference(toVector("\u00d8stre Toten"));
  (*kommunenavn)[529] = createStringReference(toVector("Vestre Toten"));
  (*kommunenavn)[532] = createStringReference(toVector("Jevnaker"));
  (*kommunenavn)[533] = createStringReference(toVector("Lunner"));
  (*kommunenavn)[534] = createStringReference(toVector("Gran"));
  (*kommunenavn)[536] = createStringReference(toVector("S\u00f8ndre Land"));
  (*kommunenavn)[538] = createStringReference(toVector("Nordre Land"));
  (*kommunenavn)[540] = createStringReference(toVector("S\u00f8r-Aurdal"));
  (*kommunenavn)[541] = createStringReference(toVector("Etnedal"));
  (*kommunenavn)[542] = createStringReference(toVector("Nord-Aurdal"));
  (*kommunenavn)[543] = createStringReference(toVector("Vestre Slidre"));
  (*kommunenavn)[544] = createStringReference(toVector("\u00d8ystre Slidre"));
  (*kommunenavn)[545] = createStringReference(toVector("Vang"));
  (*kommunenavn)[602] = createStringReference(toVector("Drammen"));
  (*kommunenavn)[604] = createStringReference(toVector("Kongsberg"));
  (*kommunenavn)[605] = createStringReference(toVector("Ringerike"));
  (*kommunenavn)[612] = createStringReference(toVector("Hole"));
  (*kommunenavn)[615] = createStringReference(toVector("Fl\u00e5"));
  (*kommunenavn)[616] = createStringReference(toVector("Nes"));
  (*kommunenavn)[617] = createStringReference(toVector("Gol"));
  (*kommunenavn)[618] = createStringReference(toVector("Hemsedal"));
  (*kommunenavn)[619] = createStringReference(toVector("\u00c5l"));
  (*kommunenavn)[620] = createStringReference(toVector("Hol"));
  (*kommunenavn)[621] = createStringReference(toVector("Sigdal"));
  (*kommunenavn)[622] = createStringReference(toVector("Kr\u00f8dsherad"));
  (*kommunenavn)[623] = createStringReference(toVector("Modum"));
  (*kommunenavn)[624] = createStringReference(toVector("\u00d8vre Eiker"));
  (*kommunenavn)[625] = createStringReference(toVector("Nedre Eiker"));
  (*kommunenavn)[626] = createStringReference(toVector("Lier"));
  (*kommunenavn)[627] = createStringReference(toVector("R\u00f8yken"));
  (*kommunenavn)[628] = createStringReference(toVector("Hurum"));
  (*kommunenavn)[631] = createStringReference(toVector("Flesberg"));
  (*kommunenavn)[632] = createStringReference(toVector("Rollag"));
  (*kommunenavn)[633] = createStringReference(toVector("Nore og Uvdal"));
  (*kommunenavn)[701] = createStringReference(toVector("Horten"));
  (*kommunenavn)[702] = createStringReference(toVector("Holmestrand"));
  (*kommunenavn)[704] = createStringReference(toVector("T\u00f8nsberg"));
  (*kommunenavn)[709] = createStringReference(toVector("Larvik"));
  (*kommunenavn)[710] = createStringReference(toVector("Sandefjord"));
  (*kommunenavn)[711] = createStringReference(toVector("Svelvik"));
  (*kommunenavn)[713] = createStringReference(toVector("Sande"));
  (*kommunenavn)[714] = createStringReference(toVector("Hof"));
  (*kommunenavn)[716] = createStringReference(toVector("Re"));
  (*kommunenavn)[722] = createStringReference(toVector("N\u00f8tter\u00f8y"));
  (*kommunenavn)[723] = createStringReference(toVector("Tj\u00f8me"));
  (*kommunenavn)[728] = createStringReference(toVector("Lardal"));
  (*kommunenavn)[805] = createStringReference(toVector("Porsgrunn"));
  (*kommunenavn)[806] = createStringReference(toVector("Skien"));
  (*kommunenavn)[807] = createStringReference(toVector("Notodden"));
  (*kommunenavn)[811] = createStringReference(toVector("Siljan"));
  (*kommunenavn)[814] = createStringReference(toVector("Bamble"));
  (*kommunenavn)[815] = createStringReference(toVector("Krager\u00f8"));
  (*kommunenavn)[817] = createStringReference(toVector("Drangedal"));
  (*kommunenavn)[819] = createStringReference(toVector("Nome"));
  (*kommunenavn)[821] = createStringReference(toVector("B\u00f8"));
  (*kommunenavn)[822] = createStringReference(toVector("Sauherad"));
  (*kommunenavn)[826] = createStringReference(toVector("Tinn"));
  (*kommunenavn)[827] = createStringReference(toVector("Hjartdal"));
  (*kommunenavn)[828] = createStringReference(toVector("Seljord"));
  (*kommunenavn)[829] = createStringReference(toVector("Kviteseid"));
  (*kommunenavn)[830] = createStringReference(toVector("Nissedal"));
  (*kommunenavn)[831] = createStringReference(toVector("Fyresdal"));
  (*kommunenavn)[833] = createStringReference(toVector("Tokke"));
  (*kommunenavn)[834] = createStringReference(toVector("Vinje"));
  (*kommunenavn)[901] = createStringReference(toVector("Ris\u00f8r"));
  (*kommunenavn)[904] = createStringReference(toVector("Grimstad"));
  (*kommunenavn)[906] = createStringReference(toVector("Arendal"));
  (*kommunenavn)[911] = createStringReference(toVector("Gjerstad"));
  (*kommunenavn)[912] = createStringReference(toVector("Veg\u00e5rshei"));
  (*kommunenavn)[914] = createStringReference(toVector("Tvedestrand"));
  (*kommunenavn)[919] = createStringReference(toVector("Froland"));
  (*kommunenavn)[926] = createStringReference(toVector("Lillesand"));
  (*kommunenavn)[928] = createStringReference(toVector("Birkenes"));
  (*kommunenavn)[929] = createStringReference(toVector("\u00c5mli"));
  (*kommunenavn)[935] = createStringReference(toVector("Iveland"));
  (*kommunenavn)[937] = createStringReference(toVector("Evje og Hornnes"));
  (*kommunenavn)[938] = createStringReference(toVector("Bygland"));
  (*kommunenavn)[940] = createStringReference(toVector("Valle"));
  (*kommunenavn)[941] = createStringReference(toVector("Bykle"));
  (*kommunenavn)[1001] = createStringReference(toVector("Kristiansand"));
  (*kommunenavn)[1002] = createStringReference(toVector("Mandal"));
  (*kommunenavn)[1003] = createStringReference(toVector("Farsund"));
  (*kommunenavn)[1004] = createStringReference(toVector("Flekkefjord"));
  (*kommunenavn)[1014] = createStringReference(toVector("Vennesla"));
  (*kommunenavn)[1017] = createStringReference(toVector("Songdalen"));
  (*kommunenavn)[1018] = createStringReference(toVector("S\u00f8gne"));
  (*kommunenavn)[1021] = createStringReference(toVector("Marnardal"));
  (*kommunenavn)[1026] = createStringReference(toVector("\u00c5seral"));
  (*kommunenavn)[1027] = createStringReference(toVector("Audnedal"));
  (*kommunenavn)[1029] = createStringReference(toVector("Lindesnes"));
  (*kommunenavn)[1032] = createStringReference(toVector("Lyngdal"));
  (*kommunenavn)[1034] = createStringReference(toVector("H\u00e6gebostad"));
  (*kommunenavn)[1037] = createStringReference(toVector("Kvinesdal"));
  (*kommunenavn)[1046] = createStringReference(toVector("Sirdal"));
  (*kommunenavn)[1101] = createStringReference(toVector("Eigersund"));
  (*kommunenavn)[1102] = createStringReference(toVector("Sandnes"));
  (*kommunenavn)[1103] = createStringReference(toVector("Stavanger"));
  (*kommunenavn)[1106] = createStringReference(toVector("Haugesund"));
  (*kommunenavn)[1111] = createStringReference(toVector("Sokndal"));
  (*kommunenavn)[1112] = createStringReference(toVector("Lund"));
  (*kommunenavn)[1114] = createStringReference(toVector("Bjerkreim"));
  (*kommunenavn)[1119] = createStringReference(toVector("H\u00e5"));
  (*kommunenavn)[1120] = createStringReference(toVector("Klepp"));
  (*kommunenavn)[1121] = createStringReference(toVector("Time"));
  (*kommunenavn)[1122] = createStringReference(toVector("Gjesdal"));
  (*kommunenavn)[1124] = createStringReference(toVector("Sola"));
  (*kommunenavn)[1127] = createStringReference(toVector("Randaberg"));
  (*kommunenavn)[1129] = createStringReference(toVector("Forsand"));
  (*kommunenavn)[1130] = createStringReference(toVector("Strand"));
  (*kommunenavn)[1133] = createStringReference(toVector("Hjelmeland"));
  (*kommunenavn)[1134] = createStringReference(toVector("Suldal"));
  (*kommunenavn)[1135] = createStringReference(toVector("Sauda"));
  (*kommunenavn)[1141] = createStringReference(toVector("Finn\u00f8y"));
  (*kommunenavn)[1142] = createStringReference(toVector("Rennes\u00f8y"));
  (*kommunenavn)[1144] = createStringReference(toVector("Kvits\u00f8y"));
  (*kommunenavn)[1145] = createStringReference(toVector("Bokn"));
  (*kommunenavn)[1146] = createStringReference(toVector("Tysv\u00e6r"));
  (*kommunenavn)[1149] = createStringReference(toVector("Karm\u00f8y"));
  (*kommunenavn)[1151] = createStringReference(toVector("Utsira"));
  (*kommunenavn)[1160] = createStringReference(toVector("Vindafjord"));
  (*kommunenavn)[1201] = createStringReference(toVector("Bergen"));
  (*kommunenavn)[1211] = createStringReference(toVector("Etne"));
  (*kommunenavn)[1216] = createStringReference(toVector("Sveio"));
  (*kommunenavn)[1219] = createStringReference(toVector("B\u00f8mlo"));
  (*kommunenavn)[1221] = createStringReference(toVector("Stord"));
  (*kommunenavn)[1222] = createStringReference(toVector("Fitjar"));
  (*kommunenavn)[1223] = createStringReference(toVector("Tysnes"));
  (*kommunenavn)[1224] = createStringReference(toVector("Kvinnherad"));
  (*kommunenavn)[1227] = createStringReference(toVector("Jondal"));
  (*kommunenavn)[1228] = createStringReference(toVector("Odda"));
  (*kommunenavn)[1231] = createStringReference(toVector("Ullensvang"));
  (*kommunenavn)[1232] = createStringReference(toVector("Eidfjord"));
  (*kommunenavn)[1233] = createStringReference(toVector("Ulvik"));
  (*kommunenavn)[1234] = createStringReference(toVector("Granvin"));
  (*kommunenavn)[1235] = createStringReference(toVector("Voss"));
  (*kommunenavn)[1238] = createStringReference(toVector("Kvam"));
  (*kommunenavn)[1241] = createStringReference(toVector("Fusa"));
  (*kommunenavn)[1242] = createStringReference(toVector("Samnanger"));
  (*kommunenavn)[1243] = createStringReference(toVector("Os"));
  (*kommunenavn)[1244] = createStringReference(toVector("Austevoll"));
  (*kommunenavn)[1245] = createStringReference(toVector("Sund"));
  (*kommunenavn)[1246] = createStringReference(toVector("Fjell"));
  (*kommunenavn)[1247] = createStringReference(toVector("Ask\u00f8y"));
  (*kommunenavn)[1251] = createStringReference(toVector("Vaksdal"));
  (*kommunenavn)[1252] = createStringReference(toVector("Modalen"));
  (*kommunenavn)[1253] = createStringReference(toVector("Oster\u00f8y"));
  (*kommunenavn)[1256] = createStringReference(toVector("Meland"));
  (*kommunenavn)[1259] = createStringReference(toVector("\u00d8ygarden"));
  (*kommunenavn)[1260] = createStringReference(toVector("Rad\u00f8y"));
  (*kommunenavn)[1263] = createStringReference(toVector("Lind\u00e5s"));
  (*kommunenavn)[1264] = createStringReference(toVector("Austrheim"));
  (*kommunenavn)[1265] = createStringReference(toVector("Fedje"));
  (*kommunenavn)[1266] = createStringReference(toVector("Masfjorden"));
  (*kommunenavn)[1401] = createStringReference(toVector("Flora"));
  (*kommunenavn)[1411] = createStringReference(toVector("Gulen"));
  (*kommunenavn)[1412] = createStringReference(toVector("Solund"));
  (*kommunenavn)[1413] = createStringReference(toVector("Hyllestad"));
  (*kommunenavn)[1416] = createStringReference(toVector("H\u00f8yanger"));
  (*kommunenavn)[1417] = createStringReference(toVector("Vik"));
  (*kommunenavn)[1418] = createStringReference(toVector("Balestrand"));
  (*kommunenavn)[1419] = createStringReference(toVector("Leikanger"));
  (*kommunenavn)[1420] = createStringReference(toVector("Sogndal"));
  (*kommunenavn)[1421] = createStringReference(toVector("Aurland"));
  (*kommunenavn)[1422] = createStringReference(toVector("L\u00e6rdal"));
  (*kommunenavn)[1424] = createStringReference(toVector("\u00c5rdal"));
  (*kommunenavn)[1426] = createStringReference(toVector("Luster"));
  (*kommunenavn)[1428] = createStringReference(toVector("Askvoll"));
  (*kommunenavn)[1429] = createStringReference(toVector("Fjaler"));
  (*kommunenavn)[1430] = createStringReference(toVector("Gaular"));
  (*kommunenavn)[1431] = createStringReference(toVector("J\u00f8lster"));
  (*kommunenavn)[1432] = createStringReference(toVector("F\u00f8rde"));
  (*kommunenavn)[1433] = createStringReference(toVector("Naustdal"));
  (*kommunenavn)[1438] = createStringReference(toVector("Bremanger"));
  (*kommunenavn)[1439] = createStringReference(toVector("V\u00e5gs\u00f8y"));
  (*kommunenavn)[1441] = createStringReference(toVector("Selje"));
  (*kommunenavn)[1443] = createStringReference(toVector("Eid"));
  (*kommunenavn)[1444] = createStringReference(toVector("Hornindal"));
  (*kommunenavn)[1445] = createStringReference(toVector("Gloppen"));
  (*kommunenavn)[1449] = createStringReference(toVector("Stryn"));
  (*kommunenavn)[1502] = createStringReference(toVector("Molde"));
  (*kommunenavn)[1504] = createStringReference(toVector("\u00c5lesund"));
  (*kommunenavn)[1505] = createStringReference(toVector("Kristiansund"));
  (*kommunenavn)[1511] = createStringReference(toVector("Vanylven"));
  (*kommunenavn)[1514] = createStringReference(toVector("Sande"));
  (*kommunenavn)[1515] = createStringReference(toVector("Her\u00f8y"));
  (*kommunenavn)[1516] = createStringReference(toVector("Ulstein"));
  (*kommunenavn)[1517] = createStringReference(toVector("Hareid"));
  (*kommunenavn)[1519] = createStringReference(toVector("Volda"));
  (*kommunenavn)[1520] = createStringReference(toVector("\u00d8rsta"));
  (*kommunenavn)[1523] = createStringReference(toVector("\u00d8rskog"));
  (*kommunenavn)[1524] = createStringReference(toVector("Norddal"));
  (*kommunenavn)[1525] = createStringReference(toVector("Stranda"));
  (*kommunenavn)[1526] = createStringReference(toVector("Stordal"));
  (*kommunenavn)[1528] = createStringReference(toVector("Sykkylven"));
  (*kommunenavn)[1529] = createStringReference(toVector("Skodje"));
  (*kommunenavn)[1531] = createStringReference(toVector("Sula"));
  (*kommunenavn)[1532] = createStringReference(toVector("Giske"));
  (*kommunenavn)[1534] = createStringReference(toVector("Haram"));
  (*kommunenavn)[1535] = createStringReference(toVector("Vestnes"));
  (*kommunenavn)[1539] = createStringReference(toVector("Rauma"));
  (*kommunenavn)[1543] = createStringReference(toVector("Nesset"));
  (*kommunenavn)[1545] = createStringReference(toVector("Midsund"));
  (*kommunenavn)[1546] = createStringReference(toVector("Sand\u00f8y"));
  (*kommunenavn)[1547] = createStringReference(toVector("Aukra"));
  (*kommunenavn)[1548] = createStringReference(toVector("Fr\u00e6na"));
  (*kommunenavn)[1551] = createStringReference(toVector("Eide"));
  (*kommunenavn)[1554] = createStringReference(toVector("Aver\u00f8y"));
  (*kommunenavn)[1557] = createStringReference(toVector("Gjemnes"));
  (*kommunenavn)[1560] = createStringReference(toVector("Tingvoll"));
  (*kommunenavn)[1563] = createStringReference(toVector("Sunndal"));
  (*kommunenavn)[1566] = createStringReference(toVector("Surnadal"));
  (*kommunenavn)[1567] = createStringReference(toVector("Rindal"));
  (*kommunenavn)[1571] = createStringReference(toVector("Halsa"));
  (*kommunenavn)[1573] = createStringReference(toVector("Sm\u00f8la"));
  (*kommunenavn)[1576] = createStringReference(toVector("Aure"));
  (*kommunenavn)[1601] = createStringReference(toVector("Trondheim"));
  (*kommunenavn)[1612] = createStringReference(toVector("Hemne"));
  (*kommunenavn)[1613] = createStringReference(toVector("Snillfjord"));
  (*kommunenavn)[1617] = createStringReference(toVector("Hitra"));
  (*kommunenavn)[1620] = createStringReference(toVector("Fr\u00f8ya"));
  (*kommunenavn)[1621] = createStringReference(toVector("\u00d8rland"));
  (*kommunenavn)[1622] = createStringReference(toVector("Agdenes"));
  (*kommunenavn)[1624] = createStringReference(toVector("Rissa"));
  (*kommunenavn)[1627] = createStringReference(toVector("Bjugn"));
  (*kommunenavn)[1630] = createStringReference(toVector("\u00c5fjord"));
  (*kommunenavn)[1632] = createStringReference(toVector("Roan"));
  (*kommunenavn)[1633] = createStringReference(toVector("Osen"));
  (*kommunenavn)[1634] = createStringReference(toVector("Oppdal"));
  (*kommunenavn)[1635] = createStringReference(toVector("Rennebu"));
  (*kommunenavn)[1636] = createStringReference(toVector("Meldal"));
  (*kommunenavn)[1638] = createStringReference(toVector("Orkdal"));
  (*kommunenavn)[1640] = createStringReference(toVector("R\u00f8ros"));
  (*kommunenavn)[1644] = createStringReference(toVector("Holt\u00e5len"));
  (*kommunenavn)[1648] = createStringReference(toVector("Midtre Gauldal"));
  (*kommunenavn)[1653] = createStringReference(toVector("Melhus"));
  (*kommunenavn)[1657] = createStringReference(toVector("Skaun"));
  (*kommunenavn)[1662] = createStringReference(toVector("Kl\u00e6bu"));
  (*kommunenavn)[1663] = createStringReference(toVector("Malvik"));
  (*kommunenavn)[1664] = createStringReference(toVector("Selbu"));
  (*kommunenavn)[1665] = createStringReference(toVector("Tydal"));
  (*kommunenavn)[1702] = createStringReference(toVector("Steinkjer"));
  (*kommunenavn)[1703] = createStringReference(toVector("Namsos"));
  (*kommunenavn)[1711] = createStringReference(toVector("Mer\u00e5ker"));
  (*kommunenavn)[1714] = createStringReference(toVector("Stj\u00f8rdal"));
  (*kommunenavn)[1717] = createStringReference(toVector("Frosta"));
  (*kommunenavn)[1718] = createStringReference(toVector("Leksvik"));
  (*kommunenavn)[1719] = createStringReference(toVector("Levanger"));
  (*kommunenavn)[1721] = createStringReference(toVector("Verdal"));
  (*kommunenavn)[1724] = createStringReference(toVector("Verran"));
  (*kommunenavn)[1725] = createStringReference(toVector("Namdalseid"));
  (*kommunenavn)[1736] = createStringReference(toVector("Sn\u00e5ase \u2013 Sn\u00e5sa"));
  (*kommunenavn)[1738] = createStringReference(toVector("Lierne"));
  (*kommunenavn)[1739] = createStringReference(toVector("Raarvihke \u2013 R\u00f8yrvik"));
  (*kommunenavn)[1740] = createStringReference(toVector("Namsskogan"));
  (*kommunenavn)[1742] = createStringReference(toVector("Grong"));
  (*kommunenavn)[1743] = createStringReference(toVector("H\u00f8ylandet"));
  (*kommunenavn)[1744] = createStringReference(toVector("Overhalla"));
  (*kommunenavn)[1748] = createStringReference(toVector("Fosnes"));
  (*kommunenavn)[1749] = createStringReference(toVector("Flatanger"));
  (*kommunenavn)[1750] = createStringReference(toVector("Vikna"));
  (*kommunenavn)[1751] = createStringReference(toVector("N\u00e6r\u00f8y"));
  (*kommunenavn)[1755] = createStringReference(toVector("Leka"));
  (*kommunenavn)[1756] = createStringReference(toVector("Inder\u00f8y"));
  (*kommunenavn)[1804] = createStringReference(toVector("Bod\u00f8"));
  (*kommunenavn)[1805] = createStringReference(toVector("Narvik"));
  (*kommunenavn)[1811] = createStringReference(toVector("Bindal"));
  (*kommunenavn)[1812] = createStringReference(toVector("S\u00f8mna"));
  (*kommunenavn)[1813] = createStringReference(toVector("Br\u00f8nn\u00f8y"));
  (*kommunenavn)[1815] = createStringReference(toVector("Vega"));
  (*kommunenavn)[1816] = createStringReference(toVector("Vevelstad"));
  (*kommunenavn)[1818] = createStringReference(toVector("Her\u00f8y"));
  (*kommunenavn)[1820] = createStringReference(toVector("Alstahaug"));
  (*kommunenavn)[1822] = createStringReference(toVector("Leirfjord"));
  (*kommunenavn)[1824] = createStringReference(toVector("Vefsn"));
  (*kommunenavn)[1825] = createStringReference(toVector("Grane"));
  (*kommunenavn)[1826] = createStringReference(toVector("Hattfjelldal"));
  (*kommunenavn)[1827] = createStringReference(toVector("D\u00f8nna"));
  (*kommunenavn)[1828] = createStringReference(toVector("Nesna"));
  (*kommunenavn)[1832] = createStringReference(toVector("Hemnes"));
  (*kommunenavn)[1833] = createStringReference(toVector("Rana"));
  (*kommunenavn)[1834] = createStringReference(toVector("Lur\u00f8y"));
  (*kommunenavn)[1835] = createStringReference(toVector("Tr\u00e6na"));
  (*kommunenavn)[1836] = createStringReference(toVector("R\u00f8d\u00f8y"));
  (*kommunenavn)[1837] = createStringReference(toVector("Mel\u00f8y"));
  (*kommunenavn)[1838] = createStringReference(toVector("Gildesk\u00e5l"));
  (*kommunenavn)[1839] = createStringReference(toVector("Beiarn"));
  (*kommunenavn)[1840] = createStringReference(toVector("Saltdal"));
  (*kommunenavn)[1841] = createStringReference(toVector("Fauske \u2013 Fuossko"));
  (*kommunenavn)[1845] = createStringReference(toVector("S\u00f8rfold"));
  (*kommunenavn)[1848] = createStringReference(toVector("Steigen"));
  (*kommunenavn)[1849] = createStringReference(toVector("Hamar\u00f8y \u2013 H\u00e1bmer"));
  (*kommunenavn)[1850] = createStringReference(toVector("Divtasvuodna \u2013 Tysfjord"));
  (*kommunenavn)[1851] = createStringReference(toVector("L\u00f8dingen"));
  (*kommunenavn)[1852] = createStringReference(toVector("Tjeldsund"));
  (*kommunenavn)[1853] = createStringReference(toVector("Evenes"));
  (*kommunenavn)[1854] = createStringReference(toVector("Ballangen"));
  (*kommunenavn)[1856] = createStringReference(toVector("R\u00f8st"));
  (*kommunenavn)[1857] = createStringReference(toVector("V\u00e6r\u00f8y"));
  (*kommunenavn)[1859] = createStringReference(toVector("Flakstad"));
  (*kommunenavn)[1860] = createStringReference(toVector("Vestv\u00e5g\u00f8y"));
  (*kommunenavn)[1865] = createStringReference(toVector("V\u00e5gan"));
  (*kommunenavn)[1866] = createStringReference(toVector("Hadsel"));
  (*kommunenavn)[1867] = createStringReference(toVector("B\u00f8"));
  (*kommunenavn)[1868] = createStringReference(toVector("\u00d8ksnes"));
  (*kommunenavn)[1870] = createStringReference(toVector("Sortland \u2013 Suort\u00e1"));
  (*kommunenavn)[1871] = createStringReference(toVector("And\u00f8y"));
  (*kommunenavn)[1874] = createStringReference(toVector("Moskenes"));
  (*kommunenavn)[1903] = createStringReference(toVector("Harstad \u2013 H\u00e1rstt\u00e1k"));
  (*kommunenavn)[1902] = createStringReference(toVector("Troms\u00f8"));
  (*kommunenavn)[1911] = createStringReference(toVector("Kv\u00e6fjord"));
  (*kommunenavn)[1913] = createStringReference(toVector("Sk\u00e5nland"));
  (*kommunenavn)[1917] = createStringReference(toVector("Ibestad"));
  (*kommunenavn)[1919] = createStringReference(toVector("Gratangen"));
  (*kommunenavn)[1920] = createStringReference(toVector("Loab\u00e1k \u2013 Lavangen"));
  (*kommunenavn)[1922] = createStringReference(toVector("Bardu"));
  (*kommunenavn)[1923] = createStringReference(toVector("Salangen"));
  (*kommunenavn)[1924] = createStringReference(toVector("M\u00e5lselv"));
  (*kommunenavn)[1925] = createStringReference(toVector("S\u00f8rreisa"));
  (*kommunenavn)[1926] = createStringReference(toVector("Dyr\u00f8y"));
  (*kommunenavn)[1927] = createStringReference(toVector("Tran\u00f8y"));
  (*kommunenavn)[1928] = createStringReference(toVector("Torsken"));
  (*kommunenavn)[1929] = createStringReference(toVector("Berg"));
  (*kommunenavn)[1931] = createStringReference(toVector("Lenvik"));
  (*kommunenavn)[1933] = createStringReference(toVector("Balsfjord"));
  (*kommunenavn)[1936] = createStringReference(toVector("Karls\u00f8y"));
  (*kommunenavn)[1938] = createStringReference(toVector("Lyngen"));
  (*kommunenavn)[1939] = createStringReference(toVector("Storfjord \u2013 Omasvuotna \u2013 Omasvuono"));
  (*kommunenavn)[1940] = createStringReference(toVector("G\u00e1ivuotna \u2013 K\u00e5fjord \u2013 Kaivuono"));
  (*kommunenavn)[1941] = createStringReference(toVector("Skjerv\u00f8y"));
  (*kommunenavn)[1942] = createStringReference(toVector("Nordreisa"));
  (*kommunenavn)[1943] = createStringReference(toVector("Kv\u00e6nangen"));
  (*kommunenavn)[2002] = createStringReference(toVector("Vard\u00f8"));
  (*kommunenavn)[2003] = createStringReference(toVector("Vads\u00f8"));
  (*kommunenavn)[2004] = createStringReference(toVector("Hammerfest"));
  (*kommunenavn)[2011] = createStringReference(toVector("Guovdageaidnu \u2013 Kautokeino"));
  (*kommunenavn)[2012] = createStringReference(toVector("Alta"));
  (*kommunenavn)[2014] = createStringReference(toVector("Loppa"));
  (*kommunenavn)[2015] = createStringReference(toVector("Hasvik"));
  (*kommunenavn)[2017] = createStringReference(toVector("Kvalsund"));
  (*kommunenavn)[2018] = createStringReference(toVector("M\u00e5s\u00f8y"));
  (*kommunenavn)[2019] = createStringReference(toVector("Nordkapp"));
  (*kommunenavn)[2020] = createStringReference(toVector("Porsanger \u2013 Pors\u00e1\u014bgu \u2013 Porsanki"));
  (*kommunenavn)[2021] = createStringReference(toVector("K\u00e1r\u00e1\u0161johka \u2013 Karasjok"));
  (*kommunenavn)[2022] = createStringReference(toVector("Lebesby"));
  (*kommunenavn)[2023] = createStringReference(toVector("Gamvik"));
  (*kommunenavn)[2024] = createStringReference(toVector("Berlev\u00e5g"));
  (*kommunenavn)[2025] = createStringReference(toVector("Deatnu \u2013 Tana"));
  (*kommunenavn)[2027] = createStringReference(toVector("Unj\u00e1rga \u2013 Nesseby"));
  (*kommunenavn)[2028] = createStringReference(toVector("B\u00e5tsfjord"));
  (*kommunenavn)[2030] = createStringReference(toVector("S\u00f8r-Varanger"));

  return kommunenavn;
}
vector<double> *hentGyldigeKommunenummer(){
  vector<double> *gyldigeKommunenummer;

  gyldigeKommunenummer = new vector<double> (425.0 + 1.0);

  (*gyldigeKommunenummer)[0] = 101.0;
  (*gyldigeKommunenummer)[1] = 104.0;
  (*gyldigeKommunenummer)[2] = 105.0;
  (*gyldigeKommunenummer)[3] = 106.0;
  (*gyldigeKommunenummer)[4] = 111.0;
  (*gyldigeKommunenummer)[5] = 118.0;
  (*gyldigeKommunenummer)[6] = 119.0;
  (*gyldigeKommunenummer)[7] = 121.0;
  (*gyldigeKommunenummer)[8] = 122.0;
  (*gyldigeKommunenummer)[9] = 123.0;
  (*gyldigeKommunenummer)[10] = 124.0;
  (*gyldigeKommunenummer)[11] = 125.0;
  (*gyldigeKommunenummer)[12] = 127.0;
  (*gyldigeKommunenummer)[13] = 128.0;
  (*gyldigeKommunenummer)[14] = 135.0;
  (*gyldigeKommunenummer)[15] = 136.0;
  (*gyldigeKommunenummer)[16] = 137.0;
  (*gyldigeKommunenummer)[17] = 138.0;
  (*gyldigeKommunenummer)[18] = 211.0;
  (*gyldigeKommunenummer)[19] = 213.0;
  (*gyldigeKommunenummer)[20] = 214.0;
  (*gyldigeKommunenummer)[21] = 215.0;
  (*gyldigeKommunenummer)[22] = 216.0;
  (*gyldigeKommunenummer)[23] = 217.0;
  (*gyldigeKommunenummer)[24] = 219.0;
  (*gyldigeKommunenummer)[25] = 220.0;
  (*gyldigeKommunenummer)[26] = 221.0;
  (*gyldigeKommunenummer)[27] = 226.0;
  (*gyldigeKommunenummer)[28] = 227.0;
  (*gyldigeKommunenummer)[29] = 228.0;
  (*gyldigeKommunenummer)[30] = 229.0;
  (*gyldigeKommunenummer)[31] = 230.0;
  (*gyldigeKommunenummer)[32] = 231.0;
  (*gyldigeKommunenummer)[33] = 233.0;
  (*gyldigeKommunenummer)[34] = 234.0;
  (*gyldigeKommunenummer)[35] = 235.0;
  (*gyldigeKommunenummer)[36] = 236.0;
  (*gyldigeKommunenummer)[37] = 237.0;
  (*gyldigeKommunenummer)[38] = 238.0;
  (*gyldigeKommunenummer)[39] = 239.0;
  (*gyldigeKommunenummer)[40] = 301.0;
  (*gyldigeKommunenummer)[41] = 402.0;
  (*gyldigeKommunenummer)[42] = 403.0;
  (*gyldigeKommunenummer)[43] = 412.0;
  (*gyldigeKommunenummer)[44] = 415.0;
  (*gyldigeKommunenummer)[45] = 417.0;
  (*gyldigeKommunenummer)[46] = 418.0;
  (*gyldigeKommunenummer)[47] = 419.0;
  (*gyldigeKommunenummer)[48] = 420.0;
  (*gyldigeKommunenummer)[49] = 423.0;
  (*gyldigeKommunenummer)[50] = 425.0;
  (*gyldigeKommunenummer)[51] = 426.0;
  (*gyldigeKommunenummer)[52] = 427.0;
  (*gyldigeKommunenummer)[53] = 428.0;
  (*gyldigeKommunenummer)[54] = 429.0;
  (*gyldigeKommunenummer)[55] = 430.0;
  (*gyldigeKommunenummer)[56] = 432.0;
  (*gyldigeKommunenummer)[57] = 434.0;
  (*gyldigeKommunenummer)[58] = 436.0;
  (*gyldigeKommunenummer)[59] = 437.0;
  (*gyldigeKommunenummer)[60] = 438.0;
  (*gyldigeKommunenummer)[61] = 439.0;
  (*gyldigeKommunenummer)[62] = 441.0;
  (*gyldigeKommunenummer)[63] = 501.0;
  (*gyldigeKommunenummer)[64] = 502.0;
  (*gyldigeKommunenummer)[65] = 511.0;
  (*gyldigeKommunenummer)[66] = 512.0;
  (*gyldigeKommunenummer)[67] = 513.0;
  (*gyldigeKommunenummer)[68] = 514.0;
  (*gyldigeKommunenummer)[69] = 515.0;
  (*gyldigeKommunenummer)[70] = 516.0;
  (*gyldigeKommunenummer)[71] = 517.0;
  (*gyldigeKommunenummer)[72] = 519.0;
  (*gyldigeKommunenummer)[73] = 520.0;
  (*gyldigeKommunenummer)[74] = 521.0;
  (*gyldigeKommunenummer)[75] = 522.0;
  (*gyldigeKommunenummer)[76] = 528.0;
  (*gyldigeKommunenummer)[77] = 529.0;
  (*gyldigeKommunenummer)[78] = 532.0;
  (*gyldigeKommunenummer)[79] = 533.0;
  (*gyldigeKommunenummer)[80] = 534.0;
  (*gyldigeKommunenummer)[81] = 536.0;
  (*gyldigeKommunenummer)[82] = 538.0;
  (*gyldigeKommunenummer)[83] = 540.0;
  (*gyldigeKommunenummer)[84] = 541.0;
  (*gyldigeKommunenummer)[85] = 542.0;
  (*gyldigeKommunenummer)[86] = 543.0;
  (*gyldigeKommunenummer)[87] = 544.0;
  (*gyldigeKommunenummer)[88] = 545.0;
  (*gyldigeKommunenummer)[89] = 602.0;
  (*gyldigeKommunenummer)[90] = 604.0;
  (*gyldigeKommunenummer)[91] = 605.0;
  (*gyldigeKommunenummer)[92] = 612.0;
  (*gyldigeKommunenummer)[93] = 615.0;
  (*gyldigeKommunenummer)[94] = 616.0;
  (*gyldigeKommunenummer)[95] = 617.0;
  (*gyldigeKommunenummer)[96] = 618.0;
  (*gyldigeKommunenummer)[97] = 619.0;
  (*gyldigeKommunenummer)[98] = 620.0;
  (*gyldigeKommunenummer)[99] = 621.0;
  (*gyldigeKommunenummer)[100] = 622.0;
  (*gyldigeKommunenummer)[101] = 623.0;
  (*gyldigeKommunenummer)[102] = 624.0;
  (*gyldigeKommunenummer)[103] = 625.0;
  (*gyldigeKommunenummer)[104] = 626.0;
  (*gyldigeKommunenummer)[105] = 627.0;
  (*gyldigeKommunenummer)[106] = 628.0;
  (*gyldigeKommunenummer)[107] = 631.0;
  (*gyldigeKommunenummer)[108] = 632.0;
  (*gyldigeKommunenummer)[109] = 633.0;
  (*gyldigeKommunenummer)[110] = 701.0;
  (*gyldigeKommunenummer)[111] = 702.0;
  (*gyldigeKommunenummer)[112] = 704.0;
  (*gyldigeKommunenummer)[113] = 709.0;
  (*gyldigeKommunenummer)[114] = 710.0;
  (*gyldigeKommunenummer)[115] = 711.0;
  (*gyldigeKommunenummer)[116] = 713.0;
  (*gyldigeKommunenummer)[117] = 714.0;
  (*gyldigeKommunenummer)[118] = 716.0;
  (*gyldigeKommunenummer)[119] = 722.0;
  (*gyldigeKommunenummer)[120] = 723.0;
  (*gyldigeKommunenummer)[121] = 728.0;
  (*gyldigeKommunenummer)[122] = 805.0;
  (*gyldigeKommunenummer)[123] = 806.0;
  (*gyldigeKommunenummer)[124] = 807.0;
  (*gyldigeKommunenummer)[125] = 811.0;
  (*gyldigeKommunenummer)[126] = 814.0;
  (*gyldigeKommunenummer)[127] = 815.0;
  (*gyldigeKommunenummer)[128] = 817.0;
  (*gyldigeKommunenummer)[129] = 819.0;
  (*gyldigeKommunenummer)[130] = 821.0;
  (*gyldigeKommunenummer)[131] = 822.0;
  (*gyldigeKommunenummer)[132] = 826.0;
  (*gyldigeKommunenummer)[133] = 827.0;
  (*gyldigeKommunenummer)[134] = 828.0;
  (*gyldigeKommunenummer)[135] = 829.0;
  (*gyldigeKommunenummer)[136] = 830.0;
  (*gyldigeKommunenummer)[137] = 831.0;
  (*gyldigeKommunenummer)[138] = 833.0;
  (*gyldigeKommunenummer)[139] = 834.0;
  (*gyldigeKommunenummer)[140] = 901.0;
  (*gyldigeKommunenummer)[141] = 904.0;
  (*gyldigeKommunenummer)[142] = 906.0;
  (*gyldigeKommunenummer)[143] = 911.0;
  (*gyldigeKommunenummer)[144] = 912.0;
  (*gyldigeKommunenummer)[145] = 914.0;
  (*gyldigeKommunenummer)[146] = 919.0;
  (*gyldigeKommunenummer)[147] = 926.0;
  (*gyldigeKommunenummer)[148] = 928.0;
  (*gyldigeKommunenummer)[149] = 929.0;
  (*gyldigeKommunenummer)[150] = 935.0;
  (*gyldigeKommunenummer)[151] = 937.0;
  (*gyldigeKommunenummer)[152] = 938.0;
  (*gyldigeKommunenummer)[153] = 940.0;
  (*gyldigeKommunenummer)[154] = 941.0;
  (*gyldigeKommunenummer)[155] = 1001.0;
  (*gyldigeKommunenummer)[156] = 1002.0;
  (*gyldigeKommunenummer)[157] = 1003.0;
  (*gyldigeKommunenummer)[158] = 1004.0;
  (*gyldigeKommunenummer)[159] = 1014.0;
  (*gyldigeKommunenummer)[160] = 1017.0;
  (*gyldigeKommunenummer)[161] = 1018.0;
  (*gyldigeKommunenummer)[162] = 1021.0;
  (*gyldigeKommunenummer)[163] = 1026.0;
  (*gyldigeKommunenummer)[164] = 1027.0;
  (*gyldigeKommunenummer)[165] = 1029.0;
  (*gyldigeKommunenummer)[166] = 1032.0;
  (*gyldigeKommunenummer)[167] = 1034.0;
  (*gyldigeKommunenummer)[168] = 1037.0;
  (*gyldigeKommunenummer)[169] = 1046.0;
  (*gyldigeKommunenummer)[170] = 1101.0;
  (*gyldigeKommunenummer)[171] = 1102.0;
  (*gyldigeKommunenummer)[172] = 1103.0;
  (*gyldigeKommunenummer)[173] = 1106.0;
  (*gyldigeKommunenummer)[174] = 1111.0;
  (*gyldigeKommunenummer)[175] = 1112.0;
  (*gyldigeKommunenummer)[176] = 1114.0;
  (*gyldigeKommunenummer)[177] = 1119.0;
  (*gyldigeKommunenummer)[178] = 1120.0;
  (*gyldigeKommunenummer)[179] = 1121.0;
  (*gyldigeKommunenummer)[180] = 1122.0;
  (*gyldigeKommunenummer)[181] = 1124.0;
  (*gyldigeKommunenummer)[182] = 1127.0;
  (*gyldigeKommunenummer)[183] = 1129.0;
  (*gyldigeKommunenummer)[184] = 1130.0;
  (*gyldigeKommunenummer)[185] = 1133.0;
  (*gyldigeKommunenummer)[186] = 1134.0;
  (*gyldigeKommunenummer)[187] = 1135.0;
  (*gyldigeKommunenummer)[188] = 1141.0;
  (*gyldigeKommunenummer)[189] = 1142.0;
  (*gyldigeKommunenummer)[190] = 1144.0;
  (*gyldigeKommunenummer)[191] = 1145.0;
  (*gyldigeKommunenummer)[192] = 1146.0;
  (*gyldigeKommunenummer)[193] = 1149.0;
  (*gyldigeKommunenummer)[194] = 1151.0;
  (*gyldigeKommunenummer)[195] = 1160.0;
  (*gyldigeKommunenummer)[196] = 1201.0;
  (*gyldigeKommunenummer)[197] = 1211.0;
  (*gyldigeKommunenummer)[198] = 1216.0;
  (*gyldigeKommunenummer)[199] = 1219.0;
  (*gyldigeKommunenummer)[200] = 1221.0;
  (*gyldigeKommunenummer)[201] = 1222.0;
  (*gyldigeKommunenummer)[202] = 1223.0;
  (*gyldigeKommunenummer)[203] = 1224.0;
  (*gyldigeKommunenummer)[204] = 1227.0;
  (*gyldigeKommunenummer)[205] = 1228.0;
  (*gyldigeKommunenummer)[206] = 1231.0;
  (*gyldigeKommunenummer)[207] = 1232.0;
  (*gyldigeKommunenummer)[208] = 1233.0;
  (*gyldigeKommunenummer)[209] = 1234.0;
  (*gyldigeKommunenummer)[210] = 1235.0;
  (*gyldigeKommunenummer)[211] = 1238.0;
  (*gyldigeKommunenummer)[212] = 1241.0;
  (*gyldigeKommunenummer)[213] = 1242.0;
  (*gyldigeKommunenummer)[214] = 1243.0;
  (*gyldigeKommunenummer)[215] = 1244.0;
  (*gyldigeKommunenummer)[216] = 1245.0;
  (*gyldigeKommunenummer)[217] = 1246.0;
  (*gyldigeKommunenummer)[218] = 1247.0;
  (*gyldigeKommunenummer)[219] = 1251.0;
  (*gyldigeKommunenummer)[220] = 1252.0;
  (*gyldigeKommunenummer)[221] = 1253.0;
  (*gyldigeKommunenummer)[222] = 1256.0;
  (*gyldigeKommunenummer)[223] = 1259.0;
  (*gyldigeKommunenummer)[224] = 1260.0;
  (*gyldigeKommunenummer)[225] = 1263.0;
  (*gyldigeKommunenummer)[226] = 1264.0;
  (*gyldigeKommunenummer)[227] = 1265.0;
  (*gyldigeKommunenummer)[228] = 1266.0;
  (*gyldigeKommunenummer)[229] = 1401.0;
  (*gyldigeKommunenummer)[230] = 1411.0;
  (*gyldigeKommunenummer)[231] = 1412.0;
  (*gyldigeKommunenummer)[232] = 1413.0;
  (*gyldigeKommunenummer)[233] = 1416.0;
  (*gyldigeKommunenummer)[234] = 1417.0;
  (*gyldigeKommunenummer)[235] = 1418.0;
  (*gyldigeKommunenummer)[236] = 1419.0;
  (*gyldigeKommunenummer)[237] = 1420.0;
  (*gyldigeKommunenummer)[238] = 1421.0;
  (*gyldigeKommunenummer)[239] = 1422.0;
  (*gyldigeKommunenummer)[240] = 1424.0;
  (*gyldigeKommunenummer)[241] = 1426.0;
  (*gyldigeKommunenummer)[242] = 1428.0;
  (*gyldigeKommunenummer)[243] = 1429.0;
  (*gyldigeKommunenummer)[244] = 1430.0;
  (*gyldigeKommunenummer)[245] = 1431.0;
  (*gyldigeKommunenummer)[246] = 1432.0;
  (*gyldigeKommunenummer)[247] = 1433.0;
  (*gyldigeKommunenummer)[248] = 1438.0;
  (*gyldigeKommunenummer)[249] = 1439.0;
  (*gyldigeKommunenummer)[250] = 1441.0;
  (*gyldigeKommunenummer)[251] = 1443.0;
  (*gyldigeKommunenummer)[252] = 1444.0;
  (*gyldigeKommunenummer)[253] = 1445.0;
  (*gyldigeKommunenummer)[254] = 1449.0;
  (*gyldigeKommunenummer)[255] = 1502.0;
  (*gyldigeKommunenummer)[256] = 1504.0;
  (*gyldigeKommunenummer)[257] = 1505.0;
  (*gyldigeKommunenummer)[258] = 1511.0;
  (*gyldigeKommunenummer)[259] = 1514.0;
  (*gyldigeKommunenummer)[260] = 1515.0;
  (*gyldigeKommunenummer)[261] = 1516.0;
  (*gyldigeKommunenummer)[262] = 1517.0;
  (*gyldigeKommunenummer)[263] = 1519.0;
  (*gyldigeKommunenummer)[264] = 1520.0;
  (*gyldigeKommunenummer)[265] = 1523.0;
  (*gyldigeKommunenummer)[266] = 1524.0;
  (*gyldigeKommunenummer)[267] = 1525.0;
  (*gyldigeKommunenummer)[268] = 1526.0;
  (*gyldigeKommunenummer)[269] = 1528.0;
  (*gyldigeKommunenummer)[270] = 1529.0;
  (*gyldigeKommunenummer)[271] = 1531.0;
  (*gyldigeKommunenummer)[272] = 1532.0;
  (*gyldigeKommunenummer)[273] = 1534.0;
  (*gyldigeKommunenummer)[274] = 1535.0;
  (*gyldigeKommunenummer)[275] = 1539.0;
  (*gyldigeKommunenummer)[276] = 1543.0;
  (*gyldigeKommunenummer)[277] = 1545.0;
  (*gyldigeKommunenummer)[278] = 1546.0;
  (*gyldigeKommunenummer)[279] = 1547.0;
  (*gyldigeKommunenummer)[280] = 1548.0;
  (*gyldigeKommunenummer)[281] = 1551.0;
  (*gyldigeKommunenummer)[282] = 1554.0;
  (*gyldigeKommunenummer)[283] = 1557.0;
  (*gyldigeKommunenummer)[284] = 1560.0;
  (*gyldigeKommunenummer)[285] = 1563.0;
  (*gyldigeKommunenummer)[286] = 1566.0;
  (*gyldigeKommunenummer)[287] = 1567.0;
  (*gyldigeKommunenummer)[288] = 1571.0;
  (*gyldigeKommunenummer)[289] = 1573.0;
  (*gyldigeKommunenummer)[290] = 1576.0;
  (*gyldigeKommunenummer)[291] = 1601.0;
  (*gyldigeKommunenummer)[292] = 1612.0;
  (*gyldigeKommunenummer)[293] = 1613.0;
  (*gyldigeKommunenummer)[294] = 1617.0;
  (*gyldigeKommunenummer)[295] = 1620.0;
  (*gyldigeKommunenummer)[296] = 1621.0;
  (*gyldigeKommunenummer)[297] = 1622.0;
  (*gyldigeKommunenummer)[298] = 1624.0;
  (*gyldigeKommunenummer)[299] = 1627.0;
  (*gyldigeKommunenummer)[300] = 1630.0;
  (*gyldigeKommunenummer)[301] = 1632.0;
  (*gyldigeKommunenummer)[302] = 1633.0;
  (*gyldigeKommunenummer)[303] = 1634.0;
  (*gyldigeKommunenummer)[304] = 1635.0;
  (*gyldigeKommunenummer)[305] = 1636.0;
  (*gyldigeKommunenummer)[306] = 1638.0;
  (*gyldigeKommunenummer)[307] = 1640.0;
  (*gyldigeKommunenummer)[308] = 1644.0;
  (*gyldigeKommunenummer)[309] = 1648.0;
  (*gyldigeKommunenummer)[310] = 1653.0;
  (*gyldigeKommunenummer)[311] = 1657.0;
  (*gyldigeKommunenummer)[312] = 1662.0;
  (*gyldigeKommunenummer)[313] = 1663.0;
  (*gyldigeKommunenummer)[314] = 1664.0;
  (*gyldigeKommunenummer)[315] = 1665.0;
  (*gyldigeKommunenummer)[316] = 1702.0;
  (*gyldigeKommunenummer)[317] = 1703.0;
  (*gyldigeKommunenummer)[318] = 1711.0;
  (*gyldigeKommunenummer)[319] = 1714.0;
  (*gyldigeKommunenummer)[320] = 1717.0;
  (*gyldigeKommunenummer)[321] = 1718.0;
  (*gyldigeKommunenummer)[322] = 1719.0;
  (*gyldigeKommunenummer)[323] = 1721.0;
  (*gyldigeKommunenummer)[324] = 1724.0;
  (*gyldigeKommunenummer)[325] = 1725.0;
  (*gyldigeKommunenummer)[326] = 1736.0;
  (*gyldigeKommunenummer)[327] = 1738.0;
  (*gyldigeKommunenummer)[328] = 1739.0;
  (*gyldigeKommunenummer)[329] = 1740.0;
  (*gyldigeKommunenummer)[330] = 1742.0;
  (*gyldigeKommunenummer)[331] = 1743.0;
  (*gyldigeKommunenummer)[332] = 1744.0;
  (*gyldigeKommunenummer)[333] = 1748.0;
  (*gyldigeKommunenummer)[334] = 1749.0;
  (*gyldigeKommunenummer)[335] = 1750.0;
  (*gyldigeKommunenummer)[336] = 1751.0;
  (*gyldigeKommunenummer)[337] = 1755.0;
  (*gyldigeKommunenummer)[338] = 1756.0;
  (*gyldigeKommunenummer)[339] = 1804.0;
  (*gyldigeKommunenummer)[340] = 1805.0;
  (*gyldigeKommunenummer)[341] = 1811.0;
  (*gyldigeKommunenummer)[342] = 1812.0;
  (*gyldigeKommunenummer)[343] = 1813.0;
  (*gyldigeKommunenummer)[344] = 1815.0;
  (*gyldigeKommunenummer)[345] = 1816.0;
  (*gyldigeKommunenummer)[346] = 1818.0;
  (*gyldigeKommunenummer)[347] = 1820.0;
  (*gyldigeKommunenummer)[348] = 1822.0;
  (*gyldigeKommunenummer)[349] = 1824.0;
  (*gyldigeKommunenummer)[350] = 1825.0;
  (*gyldigeKommunenummer)[351] = 1826.0;
  (*gyldigeKommunenummer)[352] = 1827.0;
  (*gyldigeKommunenummer)[353] = 1828.0;
  (*gyldigeKommunenummer)[354] = 1832.0;
  (*gyldigeKommunenummer)[355] = 1833.0;
  (*gyldigeKommunenummer)[356] = 1834.0;
  (*gyldigeKommunenummer)[357] = 1835.0;
  (*gyldigeKommunenummer)[358] = 1836.0;
  (*gyldigeKommunenummer)[359] = 1837.0;
  (*gyldigeKommunenummer)[360] = 1838.0;
  (*gyldigeKommunenummer)[361] = 1839.0;
  (*gyldigeKommunenummer)[362] = 1840.0;
  (*gyldigeKommunenummer)[363] = 1841.0;
  (*gyldigeKommunenummer)[364] = 1845.0;
  (*gyldigeKommunenummer)[365] = 1848.0;
  (*gyldigeKommunenummer)[366] = 1849.0;
  (*gyldigeKommunenummer)[367] = 1850.0;
  (*gyldigeKommunenummer)[368] = 1851.0;
  (*gyldigeKommunenummer)[369] = 1852.0;
  (*gyldigeKommunenummer)[370] = 1853.0;
  (*gyldigeKommunenummer)[371] = 1854.0;
  (*gyldigeKommunenummer)[372] = 1856.0;
  (*gyldigeKommunenummer)[373] = 1857.0;
  (*gyldigeKommunenummer)[374] = 1859.0;
  (*gyldigeKommunenummer)[375] = 1860.0;
  (*gyldigeKommunenummer)[376] = 1865.0;
  (*gyldigeKommunenummer)[377] = 1866.0;
  (*gyldigeKommunenummer)[378] = 1867.0;
  (*gyldigeKommunenummer)[379] = 1868.0;
  (*gyldigeKommunenummer)[380] = 1870.0;
  (*gyldigeKommunenummer)[381] = 1871.0;
  (*gyldigeKommunenummer)[382] = 1874.0;
  (*gyldigeKommunenummer)[383] = 1903.0;
  (*gyldigeKommunenummer)[384] = 1902.0;
  (*gyldigeKommunenummer)[385] = 1911.0;
  (*gyldigeKommunenummer)[386] = 1913.0;
  (*gyldigeKommunenummer)[387] = 1917.0;
  (*gyldigeKommunenummer)[388] = 1919.0;
  (*gyldigeKommunenummer)[389] = 1920.0;
  (*gyldigeKommunenummer)[390] = 1922.0;
  (*gyldigeKommunenummer)[391] = 1923.0;
  (*gyldigeKommunenummer)[392] = 1924.0;
  (*gyldigeKommunenummer)[393] = 1925.0;
  (*gyldigeKommunenummer)[394] = 1926.0;
  (*gyldigeKommunenummer)[395] = 1927.0;
  (*gyldigeKommunenummer)[396] = 1928.0;
  (*gyldigeKommunenummer)[397] = 1929.0;
  (*gyldigeKommunenummer)[398] = 1931.0;
  (*gyldigeKommunenummer)[399] = 1933.0;
  (*gyldigeKommunenummer)[400] = 1936.0;
  (*gyldigeKommunenummer)[401] = 1938.0;
  (*gyldigeKommunenummer)[402] = 1939.0;
  (*gyldigeKommunenummer)[403] = 1940.0;
  (*gyldigeKommunenummer)[404] = 1941.0;
  (*gyldigeKommunenummer)[405] = 1942.0;
  (*gyldigeKommunenummer)[406] = 1943.0;
  (*gyldigeKommunenummer)[407] = 2002.0;
  (*gyldigeKommunenummer)[408] = 2003.0;
  (*gyldigeKommunenummer)[409] = 2004.0;
  (*gyldigeKommunenummer)[410] = 2011.0;
  (*gyldigeKommunenummer)[411] = 2012.0;
  (*gyldigeKommunenummer)[412] = 2014.0;
  (*gyldigeKommunenummer)[413] = 2015.0;
  (*gyldigeKommunenummer)[414] = 2017.0;
  (*gyldigeKommunenummer)[415] = 2018.0;
  (*gyldigeKommunenummer)[416] = 2019.0;
  (*gyldigeKommunenummer)[417] = 2020.0;
  (*gyldigeKommunenummer)[418] = 2021.0;
  (*gyldigeKommunenummer)[419] = 2022.0;
  (*gyldigeKommunenummer)[420] = 2023.0;
  (*gyldigeKommunenummer)[421] = 2024.0;
  (*gyldigeKommunenummer)[422] = 2025.0;
  (*gyldigeKommunenummer)[423] = 2027.0;
  (*gyldigeKommunenummer)[424] = 2028.0;
  (*gyldigeKommunenummer)[425] = 2030.0;

  return gyldigeKommunenummer;
}
double test1(){
  DoubleReference *doubleReference;
  Success *success;
  vector<char> *kommuenavn;

  doubleReference = new DoubleReference();
  doubleReference->doubleValue = 0.0;

  success = new Success();
  kommuenavn = hentKommunenavnFraNummer(toVector("1640"), success);
  assertStringEquals(kommuenavn, toVector("R\u00f8ros"), doubleReference);
  assertTrue(success->success, doubleReference);

  return doubleReference->doubleValue;
}
double test(){
  double failures;

  failures = 0.0;

  failures = failures + test1();

  return failures;
}
vector<char> *decimalToString(double decimal){

  return numberToString(decimal, 10.0);
}
vector<char> *numberToString(double decimal, double base){
  vector<char> *string;
  double digits;
  double digitPosition;
  bool hasPrintedPoint;
  double i, d;

  string = new vector<char> (0.0);

  digits = getDigits(base);

  /* Find digitPosition: */
  digitPosition = getDigitPosition(decimal, base);

  decimal = round(decimal*pow(base,  -digitPosition  + digits - 1.0));

  hasPrintedPoint = false;

  /* Print leading zeros. */
  if(digitPosition < 0.0){
    string = appendCharacter(string, '0');
    string = appendCharacter(string, '.');
    hasPrintedPoint = true;
    for(i = 0.0; i <  -digitPosition  - 1.0; i = i + 1.0){
      string = appendCharacter(string, '0');
    }
  }

  /* Print number. */
  for(i = 0.0; i < digits; i = i + 1.0){
    d = floor(decimal/pow(base, digits - i - 1.0));
    if( !hasPrintedPoint  && digitPosition - i + 1.0 == 0.0){
      if(decimal != 0.0){
        string = appendCharacter(string, '.');
      }
      hasPrintedPoint = true;
    }
    if(decimal == 0.0 && hasPrintedPoint){
    }else{
      string = appendCharacter(string, getSingleDigitFromNumber(d, base));
    }
    decimal = decimal - d*pow(base, digits - i - 1.0);
  }

  /* Print trailing zeros. */
  for(i = 0.0; i < digitPosition - digits + 1.0; i = i + 1.0){
    string = appendCharacter(string, '0');
  }

  /* Done */
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
  vector<char> *numberTable;
  char retc;

  numberTable = getNumberTable();

  if(c > base - 1.0){
    retc = '?';
  }else{
    retc = (*numberTable)[(int)(c)];
  }

  return retc;
}
vector<char> *getNumberTable(){
  vector<char> *numberTable;

  numberTable = new vector<char> (16.0);
  (*numberTable)[0] = '0';
  (*numberTable)[1] = '1';
  (*numberTable)[2] = '2';
  (*numberTable)[3] = '3';
  (*numberTable)[4] = '4';
  (*numberTable)[5] = '5';
  (*numberTable)[6] = '6';
  (*numberTable)[7] = '7';
  (*numberTable)[8] = '8';
  (*numberTable)[9] = '9';
  (*numberTable)[10] = 'A';
  (*numberTable)[11] = 'B';
  (*numberTable)[12] = 'C';
  (*numberTable)[13] = 'D';
  (*numberTable)[14] = 'E';
  (*numberTable)[15] = 'F';
  return numberTable;
}
StringToDecimalResult *stringToDecimal(vector<char> *string){

  return stringToDecimalForBase(string, 10.0);
}
StringToDecimalResult *stringToDecimalForBase(vector<char> *string, double base){
  StringToDecimalResult *stringToDecimalResult;
  char c;
  double i, j;
  bool isPositive;
  double beforeDecimalPoint;
  double afterDecimalPoint;
  double n;
  double validCharacters;
  double d;

  stringToDecimalResult = new StringToDecimalResult();
  stringToDecimalResult->success = true;
  i = 0.0;
  isPositive = true;
  beforeDecimalPoint = 0.0;
  afterDecimalPoint = 0.0;
  n = 0.0;
  validCharacters = 0.0;

  if(base >= 2.0 && base <= 16.0){
    for(j = 0.0; j < string->size(); j = j + 1.0){
      c = (*string)[(int)(j)];
      if(isNumber(c, base) || c == '.' || c == '-'){
        validCharacters = validCharacters + 1.0;
      }
    }
    if(validCharacters == string->size()){
      if(string->size() > 0.0){
        c = (*string)[(int)(i)];
        if(c == '-'){
          isPositive = false;
          i = i + 1.0;
        }
        if(i < string->size()){
          c = (*string)[(int)(i)];
          if(isNumber(c, base)){
            for(; isNumber(c, base) && (i < string->size()); ){
              beforeDecimalPoint = beforeDecimalPoint + 1.0;
              i = i + 1.0;
              if(i < string->size()){
                c = (*string)[(int)(i)];
              }
            }
            if(i < string->size()){
              c = (*string)[(int)(i)];
              if(c == '.'){
                i = i + 1.0;
                if(i < string->size()){
                  c = (*string)[(int)(i)];
                  for(; isNumber(c, base) && (i < string->size()); ){
                    afterDecimalPoint = afterDecimalPoint + 1.0;
                    i = i + 1.0;
                    if(i < string->size()){
                      c = (*string)[(int)(i)];
                    }
                  }
                }else{
                  stringToDecimalResult->success = false;
                  stringToDecimalResult->feilmelding = toVector("Number must have digits after the decimal point.");
                }
              }
            }
          }else{
            stringToDecimalResult->success = false;
            stringToDecimalResult->feilmelding = toVector("Number must start with digits (for negative numbers, after the optional negative sign).");
          }
        }
        if(stringToDecimalResult->success != false){
          i = 0.0;
          if( !isPositive ){
            i = 1.0;
          }
          for(j = 0.0; j < beforeDecimalPoint; j = j + 1.0){
            c = (*string)[(int)(i)];
            i = i + 1.0;
            d = getDecimalFromSingleDecimalDigit(c, base);
            n = n + d*pow(base, beforeDecimalPoint - j - 1.0);
          }
          if(afterDecimalPoint > 0.0){
            i = i + 1.0;
            for(j = 0.0; j < afterDecimalPoint; j = j + 1.0){
              c = (*string)[(int)(i)];
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
        stringToDecimalResult->feilmelding = toVector("String has no content.");
      }
    }else{
      stringToDecimalResult->success = false;
      stringToDecimalResult->feilmelding = toVector("String contains invalid character.");
    }
  }else{
    stringToDecimalResult->success = false;
    stringToDecimalResult->feilmelding = toVector("Base must be from 2 to 16.");
  }

  return stringToDecimalResult;
}
double getDecimalFromSingleDecimalDigit(char c, double base){
  vector<char> *numberTable;
  double i;
  double position;

  numberTable = getNumberTable();
  position = 0.0;

  for(i = 0.0; i < base; i = i + 1.0){
    if((*numberTable)[(int)(i)] == c){
      position = i;
    }
  }

  return position;
}
bool isNumber(char c, double base){
  vector<char> *numberTable;
  double i;
  bool found;

  numberTable = getNumberTable();
  found = false;

  for(i = 0.0; i < base; i = i + 1.0){
    if((*numberTable)[(int)(i)] == c){
      found = true;
    }
  }

  return found;
}
void assertFalse(bool b, DoubleReference *failures){

  if(b){
    failures->doubleValue = failures->doubleValue + 1.0;
  }
}
void assertTrue(bool b, DoubleReference *failures){

  if( !b ){
    failures->doubleValue = failures->doubleValue + 1.0;
  }
}
void assertEquals(double a, double b, DoubleReference *failures){

  if(a != b){
    failures->doubleValue = failures->doubleValue + 1.0;
  }
}
void assertStringEquals(vector<char> *a, vector<char> *b, DoubleReference *failures){

  if( !stringsEqual(a, b) ){
    failures->doubleValue = failures->doubleValue + 1.0;
  }
}
vector<double> *stringToNumberArray(vector<char> *string){
  double i;
  vector<double> *array;

  array = new vector<double> (string->size());

  for(i = 0.0; i < string->size(); i = i + 1.0){
    (*array)[(int)(i)] = (*string)[(int)(i)];
  }
  return array;
}
vector<char> *numberArrayToString(vector<double> *array){
  double i;
  vector<char> *string;

  string = new vector<char> (array->size());

  for(i = 0.0; i < array->size(); i = i + 1.0){
    (*string)[(int)(i)] = (*array)[(int)(i)];
  }
  return string;
}
bool stringsEqual(vector<char> *data1, vector<char> *data2){
  bool equal;
  double nrEqual, i;

  equal = false;
  if(data1->size() == data2->size()){
    nrEqual = 0.0;
    for(i = 0.0; i < data1->size(); i = i + 1.0){
      if((*data1)[(int)(i)] == (*data2)[(int)(i)]){
        nrEqual = nrEqual + 1.0;
      }
    }
    if(nrEqual == data1->size()){
      equal = true;
    }
  }else{
    equal = false;
  }

  return equal;
}
bool numberArraysEqual(vector<double> *data1, vector<double> *data2){
  bool equal;
  double nrEqual, i;

  equal = false;
  if(data1->size() == data2->size()){
    nrEqual = 0.0;
    for(i = 0.0; i < data1->size(); i = i + 1.0){
      if((*data1)[(int)(i)] == (*data2)[(int)(i)]){
        nrEqual = nrEqual + 1.0;
      }
    }
    if(nrEqual == data1->size()){
      equal = true;
    }
  }else{
    equal = false;
  }

  return equal;
}
vector<char> *substring(vector<char> *string, double from, double to){
  vector<char> *n;
  double i;

  n = new vector<char> (to - from);

  for(i = from; i < to; i = i + 1.0){
    (*n)[(int)(i - from)] = (*string)[(int)(i)];
  }

  return n;
}
vector<char> *appendString(vector<char> *string, vector<char> *s){
  vector<char> *newString;
  double i;

  newString = new vector<char> (string->size() + s->size());

  for(i = 0.0; i < string->size(); i = i + 1.0){
    (*newString)[(int)(i)] = (*string)[(int)(i)];
  }

  for(i = 0.0; i < s->size(); i = i + 1.0){
    (*newString)[(int)(string->size() + i)] = (*s)[(int)(i)];
  }

  delete string;

  return newString;
}
vector<char> *appendCharacter(vector<char> *string, char c){
  vector<char> *newString;
  double i;

  newString = new vector<char> (string->size() + 1.0);

  for(i = 0.0; i < string->size(); i = i + 1.0){
    (*newString)[(int)(i)] = (*string)[(int)(i)];
  }

  (*newString)[(int)(string->size())] = c;

  delete string;

  return newString;
}
vector<StringReference*> *split(vector<char> *toSplit, char splitBy){
  vector<StringReference*> *splitt;
  vector<char> *next;
  double i;
  char c;
  StringReference *n;

  splitt = new vector<StringReference*> (0.0);

  next = new vector<char> (0.0);
  for(i = 0.0; i < toSplit->size(); i = i + 1.0){
    c = (*toSplit)[(int)(i)];
    if(c == splitBy){
      n = new StringReference();
      n->string = next;
      splitt = addString(splitt, n);
      next = new vector<char> (0.0);
    }else{
      next = appendCharacter(next, c);
    }
  }

  if(next->size() > 0.0){
    n = new StringReference();
    n->string = next;
    splitt = addString(splitt, n);
  }

  return splitt;
}
vector<double> *addDecimal(vector<double> *list, double a){
  vector<double> *newlist;
  double i;

  newlist = new vector<double> (list->size() + 1.0);
  for(i = 0.0; i < list->size(); i = i + 1.0){
    (*newlist)[(int)(i)] = (*list)[(int)(i)];
  }
  (*newlist)[(int)(list->size())] = a;
		
  delete list;
		
  return newlist;
}
void addDecimalRef(DecimalListRef *list, double i){

  list->list = addDecimal(list->list, i);
}
vector<double> *removeDecimal(vector<double> *list, double n){
  vector<double> *newlist;
  double i;

  newlist = new vector<double> (list->size() - 1.0);

  for(i = 0.0; i < list->size(); i = i + 1.0){
    if(i < n){
      (*newlist)[(int)(i)] = (*list)[(int)(i)];
    }
    if(i > n){
      (*newlist)[(int)(i - 1.0)] = (*list)[(int)(i)];
    }
  }
		
  delete list;
		
  return newlist;
}
double getDecimalRef(DecimalListRef *list, double i){

  return (*list->list)[(int)(i)];
}
void removeDecimalRef(DecimalListRef *list, double i){

  list->list = removeDecimal(list->list, i);
}
vector<StringReference*> *addString(vector<StringReference*> *list, StringReference *a){
  vector<StringReference*> *newlist;
  double i;

  newlist = new vector<StringReference*> (list->size() + 1.0);

  for(i = 0.0; i < list->size(); i = i + 1.0){
    (*newlist)[(int)(i)] = (*list)[(int)(i)];
  }
  (*newlist)[(int)(list->size())] = a;
		
  delete list;
		
  return newlist;
}
void addStringRef(StringListRef *list, StringReference *i){

  list->list = addString(list->list, i);
}
vector<StringReference*> *removeString(vector<StringReference*> *list, double n){
  vector<StringReference*> *newlist;
  double i;

  newlist = new vector<StringReference*> (list->size() - 1.0);

  for(i = 0.0; i < list->size(); i = i + 1.0){
    if(i < n){
      (*newlist)[(int)(i)] = (*list)[(int)(i)];
    }
    if(i > n){
      (*newlist)[(int)(i - 1.0)] = (*list)[(int)(i)];
    }
  }
		
  delete list;
		
  return newlist;
}
StringReference *getStringRef(StringListRef *list, double i){

  return (*list->list)[(int)(i)];
}
void removeStringRef(StringListRef *list, double i){

  list->list = removeString(list->list, i);
}


#include <iostream>

using namespace std;

int main(){
	cout << test();
	return 0;
}