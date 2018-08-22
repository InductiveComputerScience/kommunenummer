import static java.lang.Math.*;

public class kommunenummer{
static public class Success{
	public boolean success;
	public char [] feilmelding;
}
	public static StringReference createStringReference(char [] string){
		StringReference stringReference;

		stringReference = new StringReference();
		stringReference.string = string;
		return stringReference;
	}

	public static boolean [] lagGyldigReversTabell(double [] nummerliste){
		double i;
		double maxnummer;
		boolean [] inverse;

		maxnummer = 0d;
		for(i = 0d; i < nummerliste.length; i = i + 1d){
			maxnummer = max(maxnummer, nummerliste[(int)(i)]);
		}

		inverse = new boolean [(int)(maxnummer + 1d)];

		for(i = 0d; i < maxnummer; i = i + 1d){
			inverse[(int)(i)] = false;
		}

		for(i = 0d; i < nummerliste.length; i = i + 1d){
			inverse[(int)(nummerliste[(int)(i)])] = true;
		}

		return inverse;
	}

	public static char [] hentKommunenavnFraNummer(char [] kommunenummer, Success success){
		char [] kommunenavn;
		StringReference [] kommunenavnListe;
		double nr;
		StringToDecimalResult stringToDecimalResult;

		kommunenavn = new char [0];

		if(erGyldigKommunenummer(kommunenummer)){
			kommunenavnListe = hentKommunenavn();
			stringToDecimalResult = stringToDecimalForBase(kommunenummer, 10d);
			if(stringToDecimalResult.success){
				nr = stringToDecimalResult.result;
				kommunenavn = kommunenavnListe[(int)(nr)].string;
				success.success = true;
			}else{
				success.feilmelding = "Kommunenummer var ikke et gyldig tall.".toCharArray();
				success.success = false;
			}
		}else{
			success.success = false;
			success.feilmelding = "Kommunenummer er ikke gyldig.".toCharArray();
		}

		return kommunenavn;
	}

	public static boolean erGyldigKommunenummer(char [] kommunenummer){
		boolean gyldig;
		double nr;
		boolean [] gyldigKommunetabell;

		if(kommunenummer.length == 4d){
			nr = stringToDecimalForBase(kommunenummer, 10d).result;
			if(nr >= 101d && nr <= 2030d && erHelttall(nr)){
				gyldigKommunetabell = hentGyldigKommunetabell();
				gyldig = gyldigKommunetabell[(int)(nr)];
			}else{
				gyldig = false;
			}
		}else{
			gyldig = false;
		}

		return gyldig;
	}

	public static boolean erHelttall(double nr){

		return (nr%1d) == 0d;
	}

	public static boolean [] hentGyldigKommunetabell(){
		double [] nummerliste;

		nummerliste = hentGyldigeKommunenummer();
		return lagGyldigReversTabell(nummerliste);
	}

	public static StringReference [] hentKommunenavn(){
		StringReference [] kommunenavn;

		kommunenavn = new StringReference [2100];

		kommunenavn[101] = createStringReference("Halden".toCharArray());
		kommunenavn[104] = createStringReference("Moss".toCharArray());
		kommunenavn[105] = createStringReference("Sarpsborg".toCharArray());
		kommunenavn[106] = createStringReference("Fredrikstad".toCharArray());
		kommunenavn[111] = createStringReference("Hvaler".toCharArray());
		kommunenavn[118] = createStringReference("Aremark".toCharArray());
		kommunenavn[119] = createStringReference("Marker".toCharArray());
		kommunenavn[121] = createStringReference("R\u00f8mskog".toCharArray());
		kommunenavn[122] = createStringReference("Tr\u00f8gstad".toCharArray());
		kommunenavn[123] = createStringReference("Spydeberg".toCharArray());
		kommunenavn[124] = createStringReference("Askim".toCharArray());
		kommunenavn[125] = createStringReference("Eidsberg".toCharArray());
		kommunenavn[127] = createStringReference("Skiptvet".toCharArray());
		kommunenavn[128] = createStringReference("Rakkestad".toCharArray());
		kommunenavn[135] = createStringReference("R\u00e5de".toCharArray());
		kommunenavn[136] = createStringReference("Rygge".toCharArray());
		kommunenavn[137] = createStringReference("V\u00e5ler".toCharArray());
		kommunenavn[138] = createStringReference("Hob\u00f8l".toCharArray());
		kommunenavn[211] = createStringReference("Vestby".toCharArray());
		kommunenavn[213] = createStringReference("Ski".toCharArray());
		kommunenavn[214] = createStringReference("\u00c5s".toCharArray());
		kommunenavn[215] = createStringReference("Frogn".toCharArray());
		kommunenavn[216] = createStringReference("Nesodden".toCharArray());
		kommunenavn[217] = createStringReference("Oppeg\u00e5rd".toCharArray());
		kommunenavn[219] = createStringReference("B\u00e6rum".toCharArray());
		kommunenavn[220] = createStringReference("Asker".toCharArray());
		kommunenavn[221] = createStringReference("Aurskog-H\u00f8land".toCharArray());
		kommunenavn[226] = createStringReference("S\u00f8rum".toCharArray());
		kommunenavn[227] = createStringReference("Fet".toCharArray());
		kommunenavn[228] = createStringReference("R\u00e6lingen".toCharArray());
		kommunenavn[229] = createStringReference("Enebakk".toCharArray());
		kommunenavn[230] = createStringReference("L\u00f8renskog".toCharArray());
		kommunenavn[231] = createStringReference("Skedsmo".toCharArray());
		kommunenavn[233] = createStringReference("Nittedal".toCharArray());
		kommunenavn[234] = createStringReference("Gjerdrum".toCharArray());
		kommunenavn[235] = createStringReference("Ullensaker".toCharArray());
		kommunenavn[236] = createStringReference("Nes".toCharArray());
		kommunenavn[237] = createStringReference("Eidsvoll".toCharArray());
		kommunenavn[238] = createStringReference("Nannestad".toCharArray());
		kommunenavn[239] = createStringReference("Hurdal".toCharArray());
		kommunenavn[301] = createStringReference("Oslo".toCharArray());
		kommunenavn[402] = createStringReference("Kongsvinger".toCharArray());
		kommunenavn[403] = createStringReference("Hamar".toCharArray());
		kommunenavn[412] = createStringReference("Ringsaker".toCharArray());
		kommunenavn[415] = createStringReference("L\u00f8ten".toCharArray());
		kommunenavn[417] = createStringReference("Stange".toCharArray());
		kommunenavn[418] = createStringReference("Nord-Odal".toCharArray());
		kommunenavn[419] = createStringReference("S\u00f8r-Odal".toCharArray());
		kommunenavn[420] = createStringReference("Eidskog".toCharArray());
		kommunenavn[423] = createStringReference("Grue".toCharArray());
		kommunenavn[425] = createStringReference("\u00c5snes".toCharArray());
		kommunenavn[426] = createStringReference("V\u00e5ler".toCharArray());
		kommunenavn[427] = createStringReference("Elverum".toCharArray());
		kommunenavn[428] = createStringReference("Trysil".toCharArray());
		kommunenavn[429] = createStringReference("\u00c5mot".toCharArray());
		kommunenavn[430] = createStringReference("Stor-Elvdal".toCharArray());
		kommunenavn[432] = createStringReference("Rendalen".toCharArray());
		kommunenavn[434] = createStringReference("Engerdal".toCharArray());
		kommunenavn[436] = createStringReference("Tolga".toCharArray());
		kommunenavn[437] = createStringReference("Tynset".toCharArray());
		kommunenavn[438] = createStringReference("Alvdal".toCharArray());
		kommunenavn[439] = createStringReference("Folldal".toCharArray());
		kommunenavn[441] = createStringReference("Os".toCharArray());
		kommunenavn[501] = createStringReference("Lillehammer".toCharArray());
		kommunenavn[502] = createStringReference("Gj\u00f8vik".toCharArray());
		kommunenavn[511] = createStringReference("Dovre".toCharArray());
		kommunenavn[512] = createStringReference("Lesja".toCharArray());
		kommunenavn[513] = createStringReference("Skj\u00e5k".toCharArray());
		kommunenavn[514] = createStringReference("Lom".toCharArray());
		kommunenavn[515] = createStringReference("V\u00e5g\u00e5".toCharArray());
		kommunenavn[516] = createStringReference("Nord-Fron".toCharArray());
		kommunenavn[517] = createStringReference("Sel".toCharArray());
		kommunenavn[519] = createStringReference("S\u00f8r-Fron".toCharArray());
		kommunenavn[520] = createStringReference("Ringebu".toCharArray());
		kommunenavn[521] = createStringReference("\u00d8yer".toCharArray());
		kommunenavn[522] = createStringReference("Gausdal".toCharArray());
		kommunenavn[528] = createStringReference("\u00d8stre Toten".toCharArray());
		kommunenavn[529] = createStringReference("Vestre Toten".toCharArray());
		kommunenavn[532] = createStringReference("Jevnaker".toCharArray());
		kommunenavn[533] = createStringReference("Lunner".toCharArray());
		kommunenavn[534] = createStringReference("Gran".toCharArray());
		kommunenavn[536] = createStringReference("S\u00f8ndre Land".toCharArray());
		kommunenavn[538] = createStringReference("Nordre Land".toCharArray());
		kommunenavn[540] = createStringReference("S\u00f8r-Aurdal".toCharArray());
		kommunenavn[541] = createStringReference("Etnedal".toCharArray());
		kommunenavn[542] = createStringReference("Nord-Aurdal".toCharArray());
		kommunenavn[543] = createStringReference("Vestre Slidre".toCharArray());
		kommunenavn[544] = createStringReference("\u00d8ystre Slidre".toCharArray());
		kommunenavn[545] = createStringReference("Vang".toCharArray());
		kommunenavn[602] = createStringReference("Drammen".toCharArray());
		kommunenavn[604] = createStringReference("Kongsberg".toCharArray());
		kommunenavn[605] = createStringReference("Ringerike".toCharArray());
		kommunenavn[612] = createStringReference("Hole".toCharArray());
		kommunenavn[615] = createStringReference("Fl\u00e5".toCharArray());
		kommunenavn[616] = createStringReference("Nes".toCharArray());
		kommunenavn[617] = createStringReference("Gol".toCharArray());
		kommunenavn[618] = createStringReference("Hemsedal".toCharArray());
		kommunenavn[619] = createStringReference("\u00c5l".toCharArray());
		kommunenavn[620] = createStringReference("Hol".toCharArray());
		kommunenavn[621] = createStringReference("Sigdal".toCharArray());
		kommunenavn[622] = createStringReference("Kr\u00f8dsherad".toCharArray());
		kommunenavn[623] = createStringReference("Modum".toCharArray());
		kommunenavn[624] = createStringReference("\u00d8vre Eiker".toCharArray());
		kommunenavn[625] = createStringReference("Nedre Eiker".toCharArray());
		kommunenavn[626] = createStringReference("Lier".toCharArray());
		kommunenavn[627] = createStringReference("R\u00f8yken".toCharArray());
		kommunenavn[628] = createStringReference("Hurum".toCharArray());
		kommunenavn[631] = createStringReference("Flesberg".toCharArray());
		kommunenavn[632] = createStringReference("Rollag".toCharArray());
		kommunenavn[633] = createStringReference("Nore og Uvdal".toCharArray());
		kommunenavn[701] = createStringReference("Horten".toCharArray());
		kommunenavn[702] = createStringReference("Holmestrand".toCharArray());
		kommunenavn[704] = createStringReference("T\u00f8nsberg".toCharArray());
		kommunenavn[709] = createStringReference("Larvik".toCharArray());
		kommunenavn[710] = createStringReference("Sandefjord".toCharArray());
		kommunenavn[711] = createStringReference("Svelvik".toCharArray());
		kommunenavn[713] = createStringReference("Sande".toCharArray());
		kommunenavn[714] = createStringReference("Hof".toCharArray());
		kommunenavn[716] = createStringReference("Re".toCharArray());
		kommunenavn[722] = createStringReference("N\u00f8tter\u00f8y".toCharArray());
		kommunenavn[723] = createStringReference("Tj\u00f8me".toCharArray());
		kommunenavn[728] = createStringReference("Lardal".toCharArray());
		kommunenavn[805] = createStringReference("Porsgrunn".toCharArray());
		kommunenavn[806] = createStringReference("Skien".toCharArray());
		kommunenavn[807] = createStringReference("Notodden".toCharArray());
		kommunenavn[811] = createStringReference("Siljan".toCharArray());
		kommunenavn[814] = createStringReference("Bamble".toCharArray());
		kommunenavn[815] = createStringReference("Krager\u00f8".toCharArray());
		kommunenavn[817] = createStringReference("Drangedal".toCharArray());
		kommunenavn[819] = createStringReference("Nome".toCharArray());
		kommunenavn[821] = createStringReference("B\u00f8".toCharArray());
		kommunenavn[822] = createStringReference("Sauherad".toCharArray());
		kommunenavn[826] = createStringReference("Tinn".toCharArray());
		kommunenavn[827] = createStringReference("Hjartdal".toCharArray());
		kommunenavn[828] = createStringReference("Seljord".toCharArray());
		kommunenavn[829] = createStringReference("Kviteseid".toCharArray());
		kommunenavn[830] = createStringReference("Nissedal".toCharArray());
		kommunenavn[831] = createStringReference("Fyresdal".toCharArray());
		kommunenavn[833] = createStringReference("Tokke".toCharArray());
		kommunenavn[834] = createStringReference("Vinje".toCharArray());
		kommunenavn[901] = createStringReference("Ris\u00f8r".toCharArray());
		kommunenavn[904] = createStringReference("Grimstad".toCharArray());
		kommunenavn[906] = createStringReference("Arendal".toCharArray());
		kommunenavn[911] = createStringReference("Gjerstad".toCharArray());
		kommunenavn[912] = createStringReference("Veg\u00e5rshei".toCharArray());
		kommunenavn[914] = createStringReference("Tvedestrand".toCharArray());
		kommunenavn[919] = createStringReference("Froland".toCharArray());
		kommunenavn[926] = createStringReference("Lillesand".toCharArray());
		kommunenavn[928] = createStringReference("Birkenes".toCharArray());
		kommunenavn[929] = createStringReference("\u00c5mli".toCharArray());
		kommunenavn[935] = createStringReference("Iveland".toCharArray());
		kommunenavn[937] = createStringReference("Evje og Hornnes".toCharArray());
		kommunenavn[938] = createStringReference("Bygland".toCharArray());
		kommunenavn[940] = createStringReference("Valle".toCharArray());
		kommunenavn[941] = createStringReference("Bykle".toCharArray());
		kommunenavn[1001] = createStringReference("Kristiansand".toCharArray());
		kommunenavn[1002] = createStringReference("Mandal".toCharArray());
		kommunenavn[1003] = createStringReference("Farsund".toCharArray());
		kommunenavn[1004] = createStringReference("Flekkefjord".toCharArray());
		kommunenavn[1014] = createStringReference("Vennesla".toCharArray());
		kommunenavn[1017] = createStringReference("Songdalen".toCharArray());
		kommunenavn[1018] = createStringReference("S\u00f8gne".toCharArray());
		kommunenavn[1021] = createStringReference("Marnardal".toCharArray());
		kommunenavn[1026] = createStringReference("\u00c5seral".toCharArray());
		kommunenavn[1027] = createStringReference("Audnedal".toCharArray());
		kommunenavn[1029] = createStringReference("Lindesnes".toCharArray());
		kommunenavn[1032] = createStringReference("Lyngdal".toCharArray());
		kommunenavn[1034] = createStringReference("H\u00e6gebostad".toCharArray());
		kommunenavn[1037] = createStringReference("Kvinesdal".toCharArray());
		kommunenavn[1046] = createStringReference("Sirdal".toCharArray());
		kommunenavn[1101] = createStringReference("Eigersund".toCharArray());
		kommunenavn[1102] = createStringReference("Sandnes".toCharArray());
		kommunenavn[1103] = createStringReference("Stavanger".toCharArray());
		kommunenavn[1106] = createStringReference("Haugesund".toCharArray());
		kommunenavn[1111] = createStringReference("Sokndal".toCharArray());
		kommunenavn[1112] = createStringReference("Lund".toCharArray());
		kommunenavn[1114] = createStringReference("Bjerkreim".toCharArray());
		kommunenavn[1119] = createStringReference("H\u00e5".toCharArray());
		kommunenavn[1120] = createStringReference("Klepp".toCharArray());
		kommunenavn[1121] = createStringReference("Time".toCharArray());
		kommunenavn[1122] = createStringReference("Gjesdal".toCharArray());
		kommunenavn[1124] = createStringReference("Sola".toCharArray());
		kommunenavn[1127] = createStringReference("Randaberg".toCharArray());
		kommunenavn[1129] = createStringReference("Forsand".toCharArray());
		kommunenavn[1130] = createStringReference("Strand".toCharArray());
		kommunenavn[1133] = createStringReference("Hjelmeland".toCharArray());
		kommunenavn[1134] = createStringReference("Suldal".toCharArray());
		kommunenavn[1135] = createStringReference("Sauda".toCharArray());
		kommunenavn[1141] = createStringReference("Finn\u00f8y".toCharArray());
		kommunenavn[1142] = createStringReference("Rennes\u00f8y".toCharArray());
		kommunenavn[1144] = createStringReference("Kvits\u00f8y".toCharArray());
		kommunenavn[1145] = createStringReference("Bokn".toCharArray());
		kommunenavn[1146] = createStringReference("Tysv\u00e6r".toCharArray());
		kommunenavn[1149] = createStringReference("Karm\u00f8y".toCharArray());
		kommunenavn[1151] = createStringReference("Utsira".toCharArray());
		kommunenavn[1160] = createStringReference("Vindafjord".toCharArray());
		kommunenavn[1201] = createStringReference("Bergen".toCharArray());
		kommunenavn[1211] = createStringReference("Etne".toCharArray());
		kommunenavn[1216] = createStringReference("Sveio".toCharArray());
		kommunenavn[1219] = createStringReference("B\u00f8mlo".toCharArray());
		kommunenavn[1221] = createStringReference("Stord".toCharArray());
		kommunenavn[1222] = createStringReference("Fitjar".toCharArray());
		kommunenavn[1223] = createStringReference("Tysnes".toCharArray());
		kommunenavn[1224] = createStringReference("Kvinnherad".toCharArray());
		kommunenavn[1227] = createStringReference("Jondal".toCharArray());
		kommunenavn[1228] = createStringReference("Odda".toCharArray());
		kommunenavn[1231] = createStringReference("Ullensvang".toCharArray());
		kommunenavn[1232] = createStringReference("Eidfjord".toCharArray());
		kommunenavn[1233] = createStringReference("Ulvik".toCharArray());
		kommunenavn[1234] = createStringReference("Granvin".toCharArray());
		kommunenavn[1235] = createStringReference("Voss".toCharArray());
		kommunenavn[1238] = createStringReference("Kvam".toCharArray());
		kommunenavn[1241] = createStringReference("Fusa".toCharArray());
		kommunenavn[1242] = createStringReference("Samnanger".toCharArray());
		kommunenavn[1243] = createStringReference("Os".toCharArray());
		kommunenavn[1244] = createStringReference("Austevoll".toCharArray());
		kommunenavn[1245] = createStringReference("Sund".toCharArray());
		kommunenavn[1246] = createStringReference("Fjell".toCharArray());
		kommunenavn[1247] = createStringReference("Ask\u00f8y".toCharArray());
		kommunenavn[1251] = createStringReference("Vaksdal".toCharArray());
		kommunenavn[1252] = createStringReference("Modalen".toCharArray());
		kommunenavn[1253] = createStringReference("Oster\u00f8y".toCharArray());
		kommunenavn[1256] = createStringReference("Meland".toCharArray());
		kommunenavn[1259] = createStringReference("\u00d8ygarden".toCharArray());
		kommunenavn[1260] = createStringReference("Rad\u00f8y".toCharArray());
		kommunenavn[1263] = createStringReference("Lind\u00e5s".toCharArray());
		kommunenavn[1264] = createStringReference("Austrheim".toCharArray());
		kommunenavn[1265] = createStringReference("Fedje".toCharArray());
		kommunenavn[1266] = createStringReference("Masfjorden".toCharArray());
		kommunenavn[1401] = createStringReference("Flora".toCharArray());
		kommunenavn[1411] = createStringReference("Gulen".toCharArray());
		kommunenavn[1412] = createStringReference("Solund".toCharArray());
		kommunenavn[1413] = createStringReference("Hyllestad".toCharArray());
		kommunenavn[1416] = createStringReference("H\u00f8yanger".toCharArray());
		kommunenavn[1417] = createStringReference("Vik".toCharArray());
		kommunenavn[1418] = createStringReference("Balestrand".toCharArray());
		kommunenavn[1419] = createStringReference("Leikanger".toCharArray());
		kommunenavn[1420] = createStringReference("Sogndal".toCharArray());
		kommunenavn[1421] = createStringReference("Aurland".toCharArray());
		kommunenavn[1422] = createStringReference("L\u00e6rdal".toCharArray());
		kommunenavn[1424] = createStringReference("\u00c5rdal".toCharArray());
		kommunenavn[1426] = createStringReference("Luster".toCharArray());
		kommunenavn[1428] = createStringReference("Askvoll".toCharArray());
		kommunenavn[1429] = createStringReference("Fjaler".toCharArray());
		kommunenavn[1430] = createStringReference("Gaular".toCharArray());
		kommunenavn[1431] = createStringReference("J\u00f8lster".toCharArray());
		kommunenavn[1432] = createStringReference("F\u00f8rde".toCharArray());
		kommunenavn[1433] = createStringReference("Naustdal".toCharArray());
		kommunenavn[1438] = createStringReference("Bremanger".toCharArray());
		kommunenavn[1439] = createStringReference("V\u00e5gs\u00f8y".toCharArray());
		kommunenavn[1441] = createStringReference("Selje".toCharArray());
		kommunenavn[1443] = createStringReference("Eid".toCharArray());
		kommunenavn[1444] = createStringReference("Hornindal".toCharArray());
		kommunenavn[1445] = createStringReference("Gloppen".toCharArray());
		kommunenavn[1449] = createStringReference("Stryn".toCharArray());
		kommunenavn[1502] = createStringReference("Molde".toCharArray());
		kommunenavn[1504] = createStringReference("\u00c5lesund".toCharArray());
		kommunenavn[1505] = createStringReference("Kristiansund".toCharArray());
		kommunenavn[1511] = createStringReference("Vanylven".toCharArray());
		kommunenavn[1514] = createStringReference("Sande".toCharArray());
		kommunenavn[1515] = createStringReference("Her\u00f8y".toCharArray());
		kommunenavn[1516] = createStringReference("Ulstein".toCharArray());
		kommunenavn[1517] = createStringReference("Hareid".toCharArray());
		kommunenavn[1519] = createStringReference("Volda".toCharArray());
		kommunenavn[1520] = createStringReference("\u00d8rsta".toCharArray());
		kommunenavn[1523] = createStringReference("\u00d8rskog".toCharArray());
		kommunenavn[1524] = createStringReference("Norddal".toCharArray());
		kommunenavn[1525] = createStringReference("Stranda".toCharArray());
		kommunenavn[1526] = createStringReference("Stordal".toCharArray());
		kommunenavn[1528] = createStringReference("Sykkylven".toCharArray());
		kommunenavn[1529] = createStringReference("Skodje".toCharArray());
		kommunenavn[1531] = createStringReference("Sula".toCharArray());
		kommunenavn[1532] = createStringReference("Giske".toCharArray());
		kommunenavn[1534] = createStringReference("Haram".toCharArray());
		kommunenavn[1535] = createStringReference("Vestnes".toCharArray());
		kommunenavn[1539] = createStringReference("Rauma".toCharArray());
		kommunenavn[1543] = createStringReference("Nesset".toCharArray());
		kommunenavn[1545] = createStringReference("Midsund".toCharArray());
		kommunenavn[1546] = createStringReference("Sand\u00f8y".toCharArray());
		kommunenavn[1547] = createStringReference("Aukra".toCharArray());
		kommunenavn[1548] = createStringReference("Fr\u00e6na".toCharArray());
		kommunenavn[1551] = createStringReference("Eide".toCharArray());
		kommunenavn[1554] = createStringReference("Aver\u00f8y".toCharArray());
		kommunenavn[1557] = createStringReference("Gjemnes".toCharArray());
		kommunenavn[1560] = createStringReference("Tingvoll".toCharArray());
		kommunenavn[1563] = createStringReference("Sunndal".toCharArray());
		kommunenavn[1566] = createStringReference("Surnadal".toCharArray());
		kommunenavn[1567] = createStringReference("Rindal".toCharArray());
		kommunenavn[1571] = createStringReference("Halsa".toCharArray());
		kommunenavn[1573] = createStringReference("Sm\u00f8la".toCharArray());
		kommunenavn[1576] = createStringReference("Aure".toCharArray());
		kommunenavn[1601] = createStringReference("Trondheim".toCharArray());
		kommunenavn[1612] = createStringReference("Hemne".toCharArray());
		kommunenavn[1613] = createStringReference("Snillfjord".toCharArray());
		kommunenavn[1617] = createStringReference("Hitra".toCharArray());
		kommunenavn[1620] = createStringReference("Fr\u00f8ya".toCharArray());
		kommunenavn[1621] = createStringReference("\u00d8rland".toCharArray());
		kommunenavn[1622] = createStringReference("Agdenes".toCharArray());
		kommunenavn[1624] = createStringReference("Rissa".toCharArray());
		kommunenavn[1627] = createStringReference("Bjugn".toCharArray());
		kommunenavn[1630] = createStringReference("\u00c5fjord".toCharArray());
		kommunenavn[1632] = createStringReference("Roan".toCharArray());
		kommunenavn[1633] = createStringReference("Osen".toCharArray());
		kommunenavn[1634] = createStringReference("Oppdal".toCharArray());
		kommunenavn[1635] = createStringReference("Rennebu".toCharArray());
		kommunenavn[1636] = createStringReference("Meldal".toCharArray());
		kommunenavn[1638] = createStringReference("Orkdal".toCharArray());
		kommunenavn[1640] = createStringReference("R\u00f8ros".toCharArray());
		kommunenavn[1644] = createStringReference("Holt\u00e5len".toCharArray());
		kommunenavn[1648] = createStringReference("Midtre Gauldal".toCharArray());
		kommunenavn[1653] = createStringReference("Melhus".toCharArray());
		kommunenavn[1657] = createStringReference("Skaun".toCharArray());
		kommunenavn[1662] = createStringReference("Kl\u00e6bu".toCharArray());
		kommunenavn[1663] = createStringReference("Malvik".toCharArray());
		kommunenavn[1664] = createStringReference("Selbu".toCharArray());
		kommunenavn[1665] = createStringReference("Tydal".toCharArray());
		kommunenavn[1702] = createStringReference("Steinkjer".toCharArray());
		kommunenavn[1703] = createStringReference("Namsos".toCharArray());
		kommunenavn[1711] = createStringReference("Mer\u00e5ker".toCharArray());
		kommunenavn[1714] = createStringReference("Stj\u00f8rdal".toCharArray());
		kommunenavn[1717] = createStringReference("Frosta".toCharArray());
		kommunenavn[1718] = createStringReference("Leksvik".toCharArray());
		kommunenavn[1719] = createStringReference("Levanger".toCharArray());
		kommunenavn[1721] = createStringReference("Verdal".toCharArray());
		kommunenavn[1724] = createStringReference("Verran".toCharArray());
		kommunenavn[1725] = createStringReference("Namdalseid".toCharArray());
		kommunenavn[1736] = createStringReference("Sn\u00e5ase \u2013 Sn\u00e5sa".toCharArray());
		kommunenavn[1738] = createStringReference("Lierne".toCharArray());
		kommunenavn[1739] = createStringReference("Raarvihke \u2013 R\u00f8yrvik".toCharArray());
		kommunenavn[1740] = createStringReference("Namsskogan".toCharArray());
		kommunenavn[1742] = createStringReference("Grong".toCharArray());
		kommunenavn[1743] = createStringReference("H\u00f8ylandet".toCharArray());
		kommunenavn[1744] = createStringReference("Overhalla".toCharArray());
		kommunenavn[1748] = createStringReference("Fosnes".toCharArray());
		kommunenavn[1749] = createStringReference("Flatanger".toCharArray());
		kommunenavn[1750] = createStringReference("Vikna".toCharArray());
		kommunenavn[1751] = createStringReference("N\u00e6r\u00f8y".toCharArray());
		kommunenavn[1755] = createStringReference("Leka".toCharArray());
		kommunenavn[1756] = createStringReference("Inder\u00f8y".toCharArray());
		kommunenavn[1804] = createStringReference("Bod\u00f8".toCharArray());
		kommunenavn[1805] = createStringReference("Narvik".toCharArray());
		kommunenavn[1811] = createStringReference("Bindal".toCharArray());
		kommunenavn[1812] = createStringReference("S\u00f8mna".toCharArray());
		kommunenavn[1813] = createStringReference("Br\u00f8nn\u00f8y".toCharArray());
		kommunenavn[1815] = createStringReference("Vega".toCharArray());
		kommunenavn[1816] = createStringReference("Vevelstad".toCharArray());
		kommunenavn[1818] = createStringReference("Her\u00f8y".toCharArray());
		kommunenavn[1820] = createStringReference("Alstahaug".toCharArray());
		kommunenavn[1822] = createStringReference("Leirfjord".toCharArray());
		kommunenavn[1824] = createStringReference("Vefsn".toCharArray());
		kommunenavn[1825] = createStringReference("Grane".toCharArray());
		kommunenavn[1826] = createStringReference("Hattfjelldal".toCharArray());
		kommunenavn[1827] = createStringReference("D\u00f8nna".toCharArray());
		kommunenavn[1828] = createStringReference("Nesna".toCharArray());
		kommunenavn[1832] = createStringReference("Hemnes".toCharArray());
		kommunenavn[1833] = createStringReference("Rana".toCharArray());
		kommunenavn[1834] = createStringReference("Lur\u00f8y".toCharArray());
		kommunenavn[1835] = createStringReference("Tr\u00e6na".toCharArray());
		kommunenavn[1836] = createStringReference("R\u00f8d\u00f8y".toCharArray());
		kommunenavn[1837] = createStringReference("Mel\u00f8y".toCharArray());
		kommunenavn[1838] = createStringReference("Gildesk\u00e5l".toCharArray());
		kommunenavn[1839] = createStringReference("Beiarn".toCharArray());
		kommunenavn[1840] = createStringReference("Saltdal".toCharArray());
		kommunenavn[1841] = createStringReference("Fauske \u2013 Fuossko".toCharArray());
		kommunenavn[1845] = createStringReference("S\u00f8rfold".toCharArray());
		kommunenavn[1848] = createStringReference("Steigen".toCharArray());
		kommunenavn[1849] = createStringReference("Hamar\u00f8y \u2013 H\u00e1bmer".toCharArray());
		kommunenavn[1850] = createStringReference("Divtasvuodna \u2013 Tysfjord".toCharArray());
		kommunenavn[1851] = createStringReference("L\u00f8dingen".toCharArray());
		kommunenavn[1852] = createStringReference("Tjeldsund".toCharArray());
		kommunenavn[1853] = createStringReference("Evenes".toCharArray());
		kommunenavn[1854] = createStringReference("Ballangen".toCharArray());
		kommunenavn[1856] = createStringReference("R\u00f8st".toCharArray());
		kommunenavn[1857] = createStringReference("V\u00e6r\u00f8y".toCharArray());
		kommunenavn[1859] = createStringReference("Flakstad".toCharArray());
		kommunenavn[1860] = createStringReference("Vestv\u00e5g\u00f8y".toCharArray());
		kommunenavn[1865] = createStringReference("V\u00e5gan".toCharArray());
		kommunenavn[1866] = createStringReference("Hadsel".toCharArray());
		kommunenavn[1867] = createStringReference("B\u00f8".toCharArray());
		kommunenavn[1868] = createStringReference("\u00d8ksnes".toCharArray());
		kommunenavn[1870] = createStringReference("Sortland \u2013 Suort\u00e1".toCharArray());
		kommunenavn[1871] = createStringReference("And\u00f8y".toCharArray());
		kommunenavn[1874] = createStringReference("Moskenes".toCharArray());
		kommunenavn[1903] = createStringReference("Harstad \u2013 H\u00e1rstt\u00e1k".toCharArray());
		kommunenavn[1902] = createStringReference("Troms\u00f8".toCharArray());
		kommunenavn[1911] = createStringReference("Kv\u00e6fjord".toCharArray());
		kommunenavn[1913] = createStringReference("Sk\u00e5nland".toCharArray());
		kommunenavn[1917] = createStringReference("Ibestad".toCharArray());
		kommunenavn[1919] = createStringReference("Gratangen".toCharArray());
		kommunenavn[1920] = createStringReference("Loab\u00e1k \u2013 Lavangen".toCharArray());
		kommunenavn[1922] = createStringReference("Bardu".toCharArray());
		kommunenavn[1923] = createStringReference("Salangen".toCharArray());
		kommunenavn[1924] = createStringReference("M\u00e5lselv".toCharArray());
		kommunenavn[1925] = createStringReference("S\u00f8rreisa".toCharArray());
		kommunenavn[1926] = createStringReference("Dyr\u00f8y".toCharArray());
		kommunenavn[1927] = createStringReference("Tran\u00f8y".toCharArray());
		kommunenavn[1928] = createStringReference("Torsken".toCharArray());
		kommunenavn[1929] = createStringReference("Berg".toCharArray());
		kommunenavn[1931] = createStringReference("Lenvik".toCharArray());
		kommunenavn[1933] = createStringReference("Balsfjord".toCharArray());
		kommunenavn[1936] = createStringReference("Karls\u00f8y".toCharArray());
		kommunenavn[1938] = createStringReference("Lyngen".toCharArray());
		kommunenavn[1939] = createStringReference("Storfjord \u2013 Omasvuotna \u2013 Omasvuono".toCharArray());
		kommunenavn[1940] = createStringReference("G\u00e1ivuotna \u2013 K\u00e5fjord \u2013 Kaivuono".toCharArray());
		kommunenavn[1941] = createStringReference("Skjerv\u00f8y".toCharArray());
		kommunenavn[1942] = createStringReference("Nordreisa".toCharArray());
		kommunenavn[1943] = createStringReference("Kv\u00e6nangen".toCharArray());
		kommunenavn[2002] = createStringReference("Vard\u00f8".toCharArray());
		kommunenavn[2003] = createStringReference("Vads\u00f8".toCharArray());
		kommunenavn[2004] = createStringReference("Hammerfest".toCharArray());
		kommunenavn[2011] = createStringReference("Guovdageaidnu \u2013 Kautokeino".toCharArray());
		kommunenavn[2012] = createStringReference("Alta".toCharArray());
		kommunenavn[2014] = createStringReference("Loppa".toCharArray());
		kommunenavn[2015] = createStringReference("Hasvik".toCharArray());
		kommunenavn[2017] = createStringReference("Kvalsund".toCharArray());
		kommunenavn[2018] = createStringReference("M\u00e5s\u00f8y".toCharArray());
		kommunenavn[2019] = createStringReference("Nordkapp".toCharArray());
		kommunenavn[2020] = createStringReference("Porsanger \u2013 Pors\u00e1\u014bgu \u2013 Porsanki".toCharArray());
		kommunenavn[2021] = createStringReference("K\u00e1r\u00e1\u0161johka \u2013 Karasjok".toCharArray());
		kommunenavn[2022] = createStringReference("Lebesby".toCharArray());
		kommunenavn[2023] = createStringReference("Gamvik".toCharArray());
		kommunenavn[2024] = createStringReference("Berlev\u00e5g".toCharArray());
		kommunenavn[2025] = createStringReference("Deatnu \u2013 Tana".toCharArray());
		kommunenavn[2027] = createStringReference("Unj\u00e1rga \u2013 Nesseby".toCharArray());
		kommunenavn[2028] = createStringReference("B\u00e5tsfjord".toCharArray());
		kommunenavn[2030] = createStringReference("S\u00f8r-Varanger".toCharArray());

		return kommunenavn;
	}

	public static double [] hentGyldigeKommunenummer(){
		double [] gyldigeKommunenummer;

		gyldigeKommunenummer = new double [(int)(425d + 1d)];

		gyldigeKommunenummer[0] = 101d;
		gyldigeKommunenummer[1] = 104d;
		gyldigeKommunenummer[2] = 105d;
		gyldigeKommunenummer[3] = 106d;
		gyldigeKommunenummer[4] = 111d;
		gyldigeKommunenummer[5] = 118d;
		gyldigeKommunenummer[6] = 119d;
		gyldigeKommunenummer[7] = 121d;
		gyldigeKommunenummer[8] = 122d;
		gyldigeKommunenummer[9] = 123d;
		gyldigeKommunenummer[10] = 124d;
		gyldigeKommunenummer[11] = 125d;
		gyldigeKommunenummer[12] = 127d;
		gyldigeKommunenummer[13] = 128d;
		gyldigeKommunenummer[14] = 135d;
		gyldigeKommunenummer[15] = 136d;
		gyldigeKommunenummer[16] = 137d;
		gyldigeKommunenummer[17] = 138d;
		gyldigeKommunenummer[18] = 211d;
		gyldigeKommunenummer[19] = 213d;
		gyldigeKommunenummer[20] = 214d;
		gyldigeKommunenummer[21] = 215d;
		gyldigeKommunenummer[22] = 216d;
		gyldigeKommunenummer[23] = 217d;
		gyldigeKommunenummer[24] = 219d;
		gyldigeKommunenummer[25] = 220d;
		gyldigeKommunenummer[26] = 221d;
		gyldigeKommunenummer[27] = 226d;
		gyldigeKommunenummer[28] = 227d;
		gyldigeKommunenummer[29] = 228d;
		gyldigeKommunenummer[30] = 229d;
		gyldigeKommunenummer[31] = 230d;
		gyldigeKommunenummer[32] = 231d;
		gyldigeKommunenummer[33] = 233d;
		gyldigeKommunenummer[34] = 234d;
		gyldigeKommunenummer[35] = 235d;
		gyldigeKommunenummer[36] = 236d;
		gyldigeKommunenummer[37] = 237d;
		gyldigeKommunenummer[38] = 238d;
		gyldigeKommunenummer[39] = 239d;
		gyldigeKommunenummer[40] = 301d;
		gyldigeKommunenummer[41] = 402d;
		gyldigeKommunenummer[42] = 403d;
		gyldigeKommunenummer[43] = 412d;
		gyldigeKommunenummer[44] = 415d;
		gyldigeKommunenummer[45] = 417d;
		gyldigeKommunenummer[46] = 418d;
		gyldigeKommunenummer[47] = 419d;
		gyldigeKommunenummer[48] = 420d;
		gyldigeKommunenummer[49] = 423d;
		gyldigeKommunenummer[50] = 425d;
		gyldigeKommunenummer[51] = 426d;
		gyldigeKommunenummer[52] = 427d;
		gyldigeKommunenummer[53] = 428d;
		gyldigeKommunenummer[54] = 429d;
		gyldigeKommunenummer[55] = 430d;
		gyldigeKommunenummer[56] = 432d;
		gyldigeKommunenummer[57] = 434d;
		gyldigeKommunenummer[58] = 436d;
		gyldigeKommunenummer[59] = 437d;
		gyldigeKommunenummer[60] = 438d;
		gyldigeKommunenummer[61] = 439d;
		gyldigeKommunenummer[62] = 441d;
		gyldigeKommunenummer[63] = 501d;
		gyldigeKommunenummer[64] = 502d;
		gyldigeKommunenummer[65] = 511d;
		gyldigeKommunenummer[66] = 512d;
		gyldigeKommunenummer[67] = 513d;
		gyldigeKommunenummer[68] = 514d;
		gyldigeKommunenummer[69] = 515d;
		gyldigeKommunenummer[70] = 516d;
		gyldigeKommunenummer[71] = 517d;
		gyldigeKommunenummer[72] = 519d;
		gyldigeKommunenummer[73] = 520d;
		gyldigeKommunenummer[74] = 521d;
		gyldigeKommunenummer[75] = 522d;
		gyldigeKommunenummer[76] = 528d;
		gyldigeKommunenummer[77] = 529d;
		gyldigeKommunenummer[78] = 532d;
		gyldigeKommunenummer[79] = 533d;
		gyldigeKommunenummer[80] = 534d;
		gyldigeKommunenummer[81] = 536d;
		gyldigeKommunenummer[82] = 538d;
		gyldigeKommunenummer[83] = 540d;
		gyldigeKommunenummer[84] = 541d;
		gyldigeKommunenummer[85] = 542d;
		gyldigeKommunenummer[86] = 543d;
		gyldigeKommunenummer[87] = 544d;
		gyldigeKommunenummer[88] = 545d;
		gyldigeKommunenummer[89] = 602d;
		gyldigeKommunenummer[90] = 604d;
		gyldigeKommunenummer[91] = 605d;
		gyldigeKommunenummer[92] = 612d;
		gyldigeKommunenummer[93] = 615d;
		gyldigeKommunenummer[94] = 616d;
		gyldigeKommunenummer[95] = 617d;
		gyldigeKommunenummer[96] = 618d;
		gyldigeKommunenummer[97] = 619d;
		gyldigeKommunenummer[98] = 620d;
		gyldigeKommunenummer[99] = 621d;
		gyldigeKommunenummer[100] = 622d;
		gyldigeKommunenummer[101] = 623d;
		gyldigeKommunenummer[102] = 624d;
		gyldigeKommunenummer[103] = 625d;
		gyldigeKommunenummer[104] = 626d;
		gyldigeKommunenummer[105] = 627d;
		gyldigeKommunenummer[106] = 628d;
		gyldigeKommunenummer[107] = 631d;
		gyldigeKommunenummer[108] = 632d;
		gyldigeKommunenummer[109] = 633d;
		gyldigeKommunenummer[110] = 701d;
		gyldigeKommunenummer[111] = 702d;
		gyldigeKommunenummer[112] = 704d;
		gyldigeKommunenummer[113] = 709d;
		gyldigeKommunenummer[114] = 710d;
		gyldigeKommunenummer[115] = 711d;
		gyldigeKommunenummer[116] = 713d;
		gyldigeKommunenummer[117] = 714d;
		gyldigeKommunenummer[118] = 716d;
		gyldigeKommunenummer[119] = 722d;
		gyldigeKommunenummer[120] = 723d;
		gyldigeKommunenummer[121] = 728d;
		gyldigeKommunenummer[122] = 805d;
		gyldigeKommunenummer[123] = 806d;
		gyldigeKommunenummer[124] = 807d;
		gyldigeKommunenummer[125] = 811d;
		gyldigeKommunenummer[126] = 814d;
		gyldigeKommunenummer[127] = 815d;
		gyldigeKommunenummer[128] = 817d;
		gyldigeKommunenummer[129] = 819d;
		gyldigeKommunenummer[130] = 821d;
		gyldigeKommunenummer[131] = 822d;
		gyldigeKommunenummer[132] = 826d;
		gyldigeKommunenummer[133] = 827d;
		gyldigeKommunenummer[134] = 828d;
		gyldigeKommunenummer[135] = 829d;
		gyldigeKommunenummer[136] = 830d;
		gyldigeKommunenummer[137] = 831d;
		gyldigeKommunenummer[138] = 833d;
		gyldigeKommunenummer[139] = 834d;
		gyldigeKommunenummer[140] = 901d;
		gyldigeKommunenummer[141] = 904d;
		gyldigeKommunenummer[142] = 906d;
		gyldigeKommunenummer[143] = 911d;
		gyldigeKommunenummer[144] = 912d;
		gyldigeKommunenummer[145] = 914d;
		gyldigeKommunenummer[146] = 919d;
		gyldigeKommunenummer[147] = 926d;
		gyldigeKommunenummer[148] = 928d;
		gyldigeKommunenummer[149] = 929d;
		gyldigeKommunenummer[150] = 935d;
		gyldigeKommunenummer[151] = 937d;
		gyldigeKommunenummer[152] = 938d;
		gyldigeKommunenummer[153] = 940d;
		gyldigeKommunenummer[154] = 941d;
		gyldigeKommunenummer[155] = 1001d;
		gyldigeKommunenummer[156] = 1002d;
		gyldigeKommunenummer[157] = 1003d;
		gyldigeKommunenummer[158] = 1004d;
		gyldigeKommunenummer[159] = 1014d;
		gyldigeKommunenummer[160] = 1017d;
		gyldigeKommunenummer[161] = 1018d;
		gyldigeKommunenummer[162] = 1021d;
		gyldigeKommunenummer[163] = 1026d;
		gyldigeKommunenummer[164] = 1027d;
		gyldigeKommunenummer[165] = 1029d;
		gyldigeKommunenummer[166] = 1032d;
		gyldigeKommunenummer[167] = 1034d;
		gyldigeKommunenummer[168] = 1037d;
		gyldigeKommunenummer[169] = 1046d;
		gyldigeKommunenummer[170] = 1101d;
		gyldigeKommunenummer[171] = 1102d;
		gyldigeKommunenummer[172] = 1103d;
		gyldigeKommunenummer[173] = 1106d;
		gyldigeKommunenummer[174] = 1111d;
		gyldigeKommunenummer[175] = 1112d;
		gyldigeKommunenummer[176] = 1114d;
		gyldigeKommunenummer[177] = 1119d;
		gyldigeKommunenummer[178] = 1120d;
		gyldigeKommunenummer[179] = 1121d;
		gyldigeKommunenummer[180] = 1122d;
		gyldigeKommunenummer[181] = 1124d;
		gyldigeKommunenummer[182] = 1127d;
		gyldigeKommunenummer[183] = 1129d;
		gyldigeKommunenummer[184] = 1130d;
		gyldigeKommunenummer[185] = 1133d;
		gyldigeKommunenummer[186] = 1134d;
		gyldigeKommunenummer[187] = 1135d;
		gyldigeKommunenummer[188] = 1141d;
		gyldigeKommunenummer[189] = 1142d;
		gyldigeKommunenummer[190] = 1144d;
		gyldigeKommunenummer[191] = 1145d;
		gyldigeKommunenummer[192] = 1146d;
		gyldigeKommunenummer[193] = 1149d;
		gyldigeKommunenummer[194] = 1151d;
		gyldigeKommunenummer[195] = 1160d;
		gyldigeKommunenummer[196] = 1201d;
		gyldigeKommunenummer[197] = 1211d;
		gyldigeKommunenummer[198] = 1216d;
		gyldigeKommunenummer[199] = 1219d;
		gyldigeKommunenummer[200] = 1221d;
		gyldigeKommunenummer[201] = 1222d;
		gyldigeKommunenummer[202] = 1223d;
		gyldigeKommunenummer[203] = 1224d;
		gyldigeKommunenummer[204] = 1227d;
		gyldigeKommunenummer[205] = 1228d;
		gyldigeKommunenummer[206] = 1231d;
		gyldigeKommunenummer[207] = 1232d;
		gyldigeKommunenummer[208] = 1233d;
		gyldigeKommunenummer[209] = 1234d;
		gyldigeKommunenummer[210] = 1235d;
		gyldigeKommunenummer[211] = 1238d;
		gyldigeKommunenummer[212] = 1241d;
		gyldigeKommunenummer[213] = 1242d;
		gyldigeKommunenummer[214] = 1243d;
		gyldigeKommunenummer[215] = 1244d;
		gyldigeKommunenummer[216] = 1245d;
		gyldigeKommunenummer[217] = 1246d;
		gyldigeKommunenummer[218] = 1247d;
		gyldigeKommunenummer[219] = 1251d;
		gyldigeKommunenummer[220] = 1252d;
		gyldigeKommunenummer[221] = 1253d;
		gyldigeKommunenummer[222] = 1256d;
		gyldigeKommunenummer[223] = 1259d;
		gyldigeKommunenummer[224] = 1260d;
		gyldigeKommunenummer[225] = 1263d;
		gyldigeKommunenummer[226] = 1264d;
		gyldigeKommunenummer[227] = 1265d;
		gyldigeKommunenummer[228] = 1266d;
		gyldigeKommunenummer[229] = 1401d;
		gyldigeKommunenummer[230] = 1411d;
		gyldigeKommunenummer[231] = 1412d;
		gyldigeKommunenummer[232] = 1413d;
		gyldigeKommunenummer[233] = 1416d;
		gyldigeKommunenummer[234] = 1417d;
		gyldigeKommunenummer[235] = 1418d;
		gyldigeKommunenummer[236] = 1419d;
		gyldigeKommunenummer[237] = 1420d;
		gyldigeKommunenummer[238] = 1421d;
		gyldigeKommunenummer[239] = 1422d;
		gyldigeKommunenummer[240] = 1424d;
		gyldigeKommunenummer[241] = 1426d;
		gyldigeKommunenummer[242] = 1428d;
		gyldigeKommunenummer[243] = 1429d;
		gyldigeKommunenummer[244] = 1430d;
		gyldigeKommunenummer[245] = 1431d;
		gyldigeKommunenummer[246] = 1432d;
		gyldigeKommunenummer[247] = 1433d;
		gyldigeKommunenummer[248] = 1438d;
		gyldigeKommunenummer[249] = 1439d;
		gyldigeKommunenummer[250] = 1441d;
		gyldigeKommunenummer[251] = 1443d;
		gyldigeKommunenummer[252] = 1444d;
		gyldigeKommunenummer[253] = 1445d;
		gyldigeKommunenummer[254] = 1449d;
		gyldigeKommunenummer[255] = 1502d;
		gyldigeKommunenummer[256] = 1504d;
		gyldigeKommunenummer[257] = 1505d;
		gyldigeKommunenummer[258] = 1511d;
		gyldigeKommunenummer[259] = 1514d;
		gyldigeKommunenummer[260] = 1515d;
		gyldigeKommunenummer[261] = 1516d;
		gyldigeKommunenummer[262] = 1517d;
		gyldigeKommunenummer[263] = 1519d;
		gyldigeKommunenummer[264] = 1520d;
		gyldigeKommunenummer[265] = 1523d;
		gyldigeKommunenummer[266] = 1524d;
		gyldigeKommunenummer[267] = 1525d;
		gyldigeKommunenummer[268] = 1526d;
		gyldigeKommunenummer[269] = 1528d;
		gyldigeKommunenummer[270] = 1529d;
		gyldigeKommunenummer[271] = 1531d;
		gyldigeKommunenummer[272] = 1532d;
		gyldigeKommunenummer[273] = 1534d;
		gyldigeKommunenummer[274] = 1535d;
		gyldigeKommunenummer[275] = 1539d;
		gyldigeKommunenummer[276] = 1543d;
		gyldigeKommunenummer[277] = 1545d;
		gyldigeKommunenummer[278] = 1546d;
		gyldigeKommunenummer[279] = 1547d;
		gyldigeKommunenummer[280] = 1548d;
		gyldigeKommunenummer[281] = 1551d;
		gyldigeKommunenummer[282] = 1554d;
		gyldigeKommunenummer[283] = 1557d;
		gyldigeKommunenummer[284] = 1560d;
		gyldigeKommunenummer[285] = 1563d;
		gyldigeKommunenummer[286] = 1566d;
		gyldigeKommunenummer[287] = 1567d;
		gyldigeKommunenummer[288] = 1571d;
		gyldigeKommunenummer[289] = 1573d;
		gyldigeKommunenummer[290] = 1576d;
		gyldigeKommunenummer[291] = 1601d;
		gyldigeKommunenummer[292] = 1612d;
		gyldigeKommunenummer[293] = 1613d;
		gyldigeKommunenummer[294] = 1617d;
		gyldigeKommunenummer[295] = 1620d;
		gyldigeKommunenummer[296] = 1621d;
		gyldigeKommunenummer[297] = 1622d;
		gyldigeKommunenummer[298] = 1624d;
		gyldigeKommunenummer[299] = 1627d;
		gyldigeKommunenummer[300] = 1630d;
		gyldigeKommunenummer[301] = 1632d;
		gyldigeKommunenummer[302] = 1633d;
		gyldigeKommunenummer[303] = 1634d;
		gyldigeKommunenummer[304] = 1635d;
		gyldigeKommunenummer[305] = 1636d;
		gyldigeKommunenummer[306] = 1638d;
		gyldigeKommunenummer[307] = 1640d;
		gyldigeKommunenummer[308] = 1644d;
		gyldigeKommunenummer[309] = 1648d;
		gyldigeKommunenummer[310] = 1653d;
		gyldigeKommunenummer[311] = 1657d;
		gyldigeKommunenummer[312] = 1662d;
		gyldigeKommunenummer[313] = 1663d;
		gyldigeKommunenummer[314] = 1664d;
		gyldigeKommunenummer[315] = 1665d;
		gyldigeKommunenummer[316] = 1702d;
		gyldigeKommunenummer[317] = 1703d;
		gyldigeKommunenummer[318] = 1711d;
		gyldigeKommunenummer[319] = 1714d;
		gyldigeKommunenummer[320] = 1717d;
		gyldigeKommunenummer[321] = 1718d;
		gyldigeKommunenummer[322] = 1719d;
		gyldigeKommunenummer[323] = 1721d;
		gyldigeKommunenummer[324] = 1724d;
		gyldigeKommunenummer[325] = 1725d;
		gyldigeKommunenummer[326] = 1736d;
		gyldigeKommunenummer[327] = 1738d;
		gyldigeKommunenummer[328] = 1739d;
		gyldigeKommunenummer[329] = 1740d;
		gyldigeKommunenummer[330] = 1742d;
		gyldigeKommunenummer[331] = 1743d;
		gyldigeKommunenummer[332] = 1744d;
		gyldigeKommunenummer[333] = 1748d;
		gyldigeKommunenummer[334] = 1749d;
		gyldigeKommunenummer[335] = 1750d;
		gyldigeKommunenummer[336] = 1751d;
		gyldigeKommunenummer[337] = 1755d;
		gyldigeKommunenummer[338] = 1756d;
		gyldigeKommunenummer[339] = 1804d;
		gyldigeKommunenummer[340] = 1805d;
		gyldigeKommunenummer[341] = 1811d;
		gyldigeKommunenummer[342] = 1812d;
		gyldigeKommunenummer[343] = 1813d;
		gyldigeKommunenummer[344] = 1815d;
		gyldigeKommunenummer[345] = 1816d;
		gyldigeKommunenummer[346] = 1818d;
		gyldigeKommunenummer[347] = 1820d;
		gyldigeKommunenummer[348] = 1822d;
		gyldigeKommunenummer[349] = 1824d;
		gyldigeKommunenummer[350] = 1825d;
		gyldigeKommunenummer[351] = 1826d;
		gyldigeKommunenummer[352] = 1827d;
		gyldigeKommunenummer[353] = 1828d;
		gyldigeKommunenummer[354] = 1832d;
		gyldigeKommunenummer[355] = 1833d;
		gyldigeKommunenummer[356] = 1834d;
		gyldigeKommunenummer[357] = 1835d;
		gyldigeKommunenummer[358] = 1836d;
		gyldigeKommunenummer[359] = 1837d;
		gyldigeKommunenummer[360] = 1838d;
		gyldigeKommunenummer[361] = 1839d;
		gyldigeKommunenummer[362] = 1840d;
		gyldigeKommunenummer[363] = 1841d;
		gyldigeKommunenummer[364] = 1845d;
		gyldigeKommunenummer[365] = 1848d;
		gyldigeKommunenummer[366] = 1849d;
		gyldigeKommunenummer[367] = 1850d;
		gyldigeKommunenummer[368] = 1851d;
		gyldigeKommunenummer[369] = 1852d;
		gyldigeKommunenummer[370] = 1853d;
		gyldigeKommunenummer[371] = 1854d;
		gyldigeKommunenummer[372] = 1856d;
		gyldigeKommunenummer[373] = 1857d;
		gyldigeKommunenummer[374] = 1859d;
		gyldigeKommunenummer[375] = 1860d;
		gyldigeKommunenummer[376] = 1865d;
		gyldigeKommunenummer[377] = 1866d;
		gyldigeKommunenummer[378] = 1867d;
		gyldigeKommunenummer[379] = 1868d;
		gyldigeKommunenummer[380] = 1870d;
		gyldigeKommunenummer[381] = 1871d;
		gyldigeKommunenummer[382] = 1874d;
		gyldigeKommunenummer[383] = 1903d;
		gyldigeKommunenummer[384] = 1902d;
		gyldigeKommunenummer[385] = 1911d;
		gyldigeKommunenummer[386] = 1913d;
		gyldigeKommunenummer[387] = 1917d;
		gyldigeKommunenummer[388] = 1919d;
		gyldigeKommunenummer[389] = 1920d;
		gyldigeKommunenummer[390] = 1922d;
		gyldigeKommunenummer[391] = 1923d;
		gyldigeKommunenummer[392] = 1924d;
		gyldigeKommunenummer[393] = 1925d;
		gyldigeKommunenummer[394] = 1926d;
		gyldigeKommunenummer[395] = 1927d;
		gyldigeKommunenummer[396] = 1928d;
		gyldigeKommunenummer[397] = 1929d;
		gyldigeKommunenummer[398] = 1931d;
		gyldigeKommunenummer[399] = 1933d;
		gyldigeKommunenummer[400] = 1936d;
		gyldigeKommunenummer[401] = 1938d;
		gyldigeKommunenummer[402] = 1939d;
		gyldigeKommunenummer[403] = 1940d;
		gyldigeKommunenummer[404] = 1941d;
		gyldigeKommunenummer[405] = 1942d;
		gyldigeKommunenummer[406] = 1943d;
		gyldigeKommunenummer[407] = 2002d;
		gyldigeKommunenummer[408] = 2003d;
		gyldigeKommunenummer[409] = 2004d;
		gyldigeKommunenummer[410] = 2011d;
		gyldigeKommunenummer[411] = 2012d;
		gyldigeKommunenummer[412] = 2014d;
		gyldigeKommunenummer[413] = 2015d;
		gyldigeKommunenummer[414] = 2017d;
		gyldigeKommunenummer[415] = 2018d;
		gyldigeKommunenummer[416] = 2019d;
		gyldigeKommunenummer[417] = 2020d;
		gyldigeKommunenummer[418] = 2021d;
		gyldigeKommunenummer[419] = 2022d;
		gyldigeKommunenummer[420] = 2023d;
		gyldigeKommunenummer[421] = 2024d;
		gyldigeKommunenummer[422] = 2025d;
		gyldigeKommunenummer[423] = 2027d;
		gyldigeKommunenummer[424] = 2028d;
		gyldigeKommunenummer[425] = 2030d;

		return gyldigeKommunenummer;
	}

	public static double test1(){
		DoubleReference doubleReference;
		Success success;
		char [] kommuenavn;

		doubleReference = new DoubleReference();
		doubleReference.doubleValue = 0d;

		success = new Success();
		kommuenavn = hentKommunenavnFraNummer("1640".toCharArray(), success);
		assertStringEquals(kommuenavn, "R\u00f8ros".toCharArray(), doubleReference);
		assertTrue(success.success, doubleReference);

		return doubleReference.doubleValue;
	}

	public static double test(){
		double failures;

		failures = 0d;

		failures = failures + test1();

		return failures;
	}

static public class StringToDecimalResult{
	public double result;
	public char [] feilmelding;
	public boolean success;
}
	public static char [] decimalToString(double decimal){

		return numberToString(decimal, 10d);
	}

	public static char [] numberToString(double decimal, double base){
		char [] string;
		double digits;
		double digitPosition;
		boolean hasPrintedPoint;
		double i, d;

		string = new char [0];

		digits = getDigits(base);

		/* Find digitPosition:*/
		digitPosition = getDigitPosition(decimal, base);

		decimal = (double)round(decimal*pow(base, -digitPosition  + digits - 1d));

		hasPrintedPoint = false;

		/* Print leading zeros.*/
		if(digitPosition < 0d){
			string = appendCharacter(string, '0');
			string = appendCharacter(string, '.');
			hasPrintedPoint = true;
			for(i = 0d; i < -digitPosition  - 1d; i = i + 1d){
				string = appendCharacter(string, '0');
			}
		}

		/* Print number.*/
		for(i = 0d; i < digits; i = i + 1d){
			d = floor(decimal/pow(base, digits - i - 1d));
			if(!hasPrintedPoint && digitPosition - i + 1d == 0d){
				if(decimal != 0d){
					string = appendCharacter(string, '.');
				}
				hasPrintedPoint = true;
			}
			if(decimal == 0d && hasPrintedPoint){
			}else{
				string = appendCharacter(string, getSingleDigitFromNumber(d, base));
			}
			decimal = decimal - d*pow(base, digits - i - 1d);
		}

		/* Print trailing zeros.*/
		for(i = 0d; i < digitPosition - digits + 1d; i = i + 1d){
			string = appendCharacter(string, '0');
		}

		/* Done*/
		return string;
	}

	public static double getDigits(double base){
		double t;

		t = pow(10d, 15d);
		return floor(log10(t)/log10(base));
	}

	public static double getDigitPosition(double decimal, double base){
		double power;
		double t;

		power = ceil(log10(decimal)/log10(base));

		t = decimal*pow(base, -power );
		if(t < base && t >= 1d){
		}else if(t >= base){
			power = power + 1d;
		}else if(t < 1d){
			power = power - 1d;
		}


		return power;
	}

	public static char getSingleDigitFromNumber(double c, double base){
		char [] numberTable;
		char retc;

		numberTable = getNumberTable();

		if(c > base - 1d){
			retc = '?';
		}else{
			retc = numberTable[(int)(c)];
		}

		return retc;
	}

	public static char [] getNumberTable(){
		char [] numberTable;

		numberTable = new char [16];
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
		return numberTable;
	}

	public static StringToDecimalResult stringToDecimal(char [] string){

		return stringToDecimalForBase(string, 10d);
	}

	public static StringToDecimalResult stringToDecimalForBase(char [] string, double base){
		StringToDecimalResult stringToDecimalResult;
		char c;
		double i, j;
		boolean isPositive;
		double beforeDecimalPoint;
		double afterDecimalPoint;
		double n;
		double validCharacters;
		double d;

		stringToDecimalResult = new StringToDecimalResult();
		stringToDecimalResult.success = true;
		i = 0d;
		isPositive = true;
		beforeDecimalPoint = 0d;
		afterDecimalPoint = 0d;
		n = 0d;
		validCharacters = 0d;

		if(base >= 2d && base <= 16d){
			for(j = 0d; j < string.length; j = j + 1d){
				c = string[(int)(j)];
				if(isNumber(c, base) || c == '.' || c == '-'){
					validCharacters = validCharacters + 1d;
				}
			}
			if(validCharacters == string.length){
				if(string.length > 0d){
					c = string[(int)(i)];
					if(c == '-'){
						isPositive = false;
						i = i + 1d;
					}
					if(i < string.length){
						c = string[(int)(i)];
						if(isNumber(c, base)){
							for(; isNumber(c, base) && (i < string.length); ){
								beforeDecimalPoint = beforeDecimalPoint + 1d;
								i = i + 1d;
								if(i < string.length){
									c = string[(int)(i)];
								}
							}
							if(i < string.length){
								c = string[(int)(i)];
								if(c == '.'){
									i = i + 1d;
									if(i < string.length){
										c = string[(int)(i)];
										for(; isNumber(c, base) && (i < string.length); ){
											afterDecimalPoint = afterDecimalPoint + 1d;
											i = i + 1d;
											if(i < string.length){
												c = string[(int)(i)];
											}
										}
									}else{
										stringToDecimalResult.success = false;
										stringToDecimalResult.feilmelding = "Number must have digits after the decimal point.".toCharArray();
									}
								}
							}
						}else{
							stringToDecimalResult.success = false;
							stringToDecimalResult.feilmelding = "Number must start with digits (for negative numbers, after the optional negative sign).".toCharArray();
						}
					}
					if(stringToDecimalResult.success != false){
						i = 0d;
						if(!isPositive){
							i = 1d;
						}
						for(j = 0d; j < beforeDecimalPoint; j = j + 1d){
							c = string[(int)(i)];
							i = i + 1d;
							d = getDecimalFromSingleDecimalDigit(c, base);
							n = n + d*pow(base, beforeDecimalPoint - j - 1d);
						}
						if(afterDecimalPoint > 0d){
							i = i + 1d;
							for(j = 0d; j < afterDecimalPoint; j = j + 1d){
								c = string[(int)(i)];
								i = i + 1d;
								d = getDecimalFromSingleDecimalDigit(c, base);
								n = n + d*pow(base, 0d - j - 1d);
							}
						}
						if(!isPositive){
							n = -n ;
						}
						stringToDecimalResult.result = n;
						stringToDecimalResult.success = true;
					}
				}else{
					stringToDecimalResult.success = false;
					stringToDecimalResult.feilmelding = "String has no content.".toCharArray();
				}
			}else{
				stringToDecimalResult.success = false;
				stringToDecimalResult.feilmelding = "String contains invalid character.".toCharArray();
			}
		}else{
			stringToDecimalResult.success = false;
			stringToDecimalResult.feilmelding = "Base must be from 2 to 16.".toCharArray();
		}

		return stringToDecimalResult;
	}

	public static double getDecimalFromSingleDecimalDigit(char c, double base){
		char [] numberTable;
		double i;
		double position;

		numberTable = getNumberTable();
		position = 0d;

		for(i = 0d; i < base; i = i + 1d){
			if(numberTable[(int)(i)] == c){
				position = i;
			}
		}

		return position;
	}

	public static boolean isNumber(char c, double base){
		char [] numberTable;
		double i;
		boolean found;

		numberTable = getNumberTable();
		found = false;

		for(i = 0d; i < base; i = i + 1d){
			if(numberTable[(int)(i)] == c){
				found = true;
			}
		}

		return found;
	}

	public static void assertFalse(boolean b, DoubleReference failures){

		if(b){
			failures.doubleValue = failures.doubleValue + 1d;
		}
	}

	public static void assertTrue(boolean b, DoubleReference failures){

		if(!b){
			failures.doubleValue = failures.doubleValue + 1d;
		}
	}

	public static void assertEquals(double a, double b, DoubleReference failures){

		if(a != b){
			failures.doubleValue = failures.doubleValue + 1d;
		}
	}

	public static void assertStringEquals(char [] a, char [] b, DoubleReference failures){

		if(!stringsEqual(a, b)){
			failures.doubleValue = failures.doubleValue + 1d;
		}
	}

	public static double [] stringToNumberArray(char [] string){
		double i;
		double [] array;

		array = new double [(int)(string.length)];

		for(i = 0d; i < string.length; i = i + 1d){
			array[(int)(i)] = string[(int)(i)];
		}
		return array;
	}

	public static char [] numberArrayToString(double [] array){
		double i;
		char [] string;

		string = new char [(int)(array.length)];

		for(i = 0d; i < array.length; i = i + 1d){
			string[(int)(i)] = (char)(array[(int)(i)]);
		}
		return string;
	}

	public static boolean stringsEqual(char [] data1, char [] data2){
		boolean equal;
		double nrEqual, i;

		equal = false;
		if(data1.length == data2.length){
			nrEqual = 0d;
			for(i = 0d; i < data1.length; i = i + 1d){
				if(data1[(int)(i)] == data2[(int)(i)]){
					nrEqual = nrEqual + 1d;
				}
			}
			if(nrEqual == data1.length){
				equal = true;
			}
		}else{
			equal = false;
		}

		return equal;
	}

	public static boolean numberArraysEqual(double [] data1, double [] data2){
		boolean equal;
		double nrEqual, i;

		equal = false;
		if(data1.length == data2.length){
			nrEqual = 0d;
			for(i = 0d; i < data1.length; i = i + 1d){
				if(data1[(int)(i)] == data2[(int)(i)]){
					nrEqual = nrEqual + 1d;
				}
			}
			if(nrEqual == data1.length){
				equal = true;
			}
		}else{
			equal = false;
		}

		return equal;
	}

	public static char [] substring(char [] string, double from, double to){
		char [] n;
		double i;

		n = new char [(int)(to - from)];

		for(i = from; i < to; i = i + 1d){
			n[(int)(i - from)] = string[(int)(i)];
		}

		return n;
	}

	public static char [] appendString(char [] string, char [] s){
		char [] newString;
		double i;

		newString = new char [(int)(string.length + s.length)];

		for(i = 0d; i < string.length; i = i + 1d){
			newString[(int)(i)] = string[(int)(i)];
		}

		for(i = 0d; i < s.length; i = i + 1d){
			newString[(int)(string.length + i)] = s[(int)(i)];
		}

		delete(string);

		return newString;
	}

	public static char [] appendCharacter(char [] string, char c){
		char [] newString;
		double i;

		newString = new char [(int)(string.length + 1d)];

		for(i = 0d; i < string.length; i = i + 1d){
			newString[(int)(i)] = string[(int)(i)];
		}

		newString[(int)(string.length)] = c;

		delete(string);

		return newString;
	}

	public static StringReference [] split(char [] toSplit, char splitBy){
		StringReference [] splitt;
		char [] next;
		double i;
		char c;
		StringReference n;

		splitt = new StringReference [0];

		next = new char [0];
		for(i = 0d; i < toSplit.length; i = i + 1d){
			c = toSplit[(int)(i)];
			if(c == splitBy){
				n = new StringReference();
				n.string = next;
				splitt = addString(splitt, n);
				next = new char [0];
			}else{
				next = appendCharacter(next, c);
			}
		}

		if(next.length > 0d){
			n = new StringReference();
			n.string = next;
			splitt = addString(splitt, n);
		}

		return splitt;
	}

static public class BooleanReference{
	public boolean booleanValue;
}
static public class DoubleReference{
	public double doubleValue;
}
static public class StringReference{
	public char [] string;
}
static public class DecimalListRef{
	public double [] list;
}
static public class StringListRef{
	public StringReference [] list;
}
	public static double [] addDecimal(double [] list, double a){
		double [] newlist;
		double i;

		newlist = new double [(int)(list.length + 1d)];
		for(i = 0d; i < list.length; i = i + 1d){
			newlist[(int)(i)] = list[(int)(i)];
		}
		newlist[(int)(list.length)] = a;
		
		delete(list);
		
		return newlist;
	}

	public static void addDecimalRef(DecimalListRef list, double i){

		list.list = addDecimal(list.list, i);
	}

	public static double [] removeDecimal(double [] list, double n){
		double [] newlist;
		double i;

		newlist = new double [(int)(list.length - 1d)];

		for(i = 0d; i < list.length; i = i + 1d){
			if(i < n){
				newlist[(int)(i)] = list[(int)(i)];
			}
			if(i > n){
				newlist[(int)(i - 1d)] = list[(int)(i)];
			}
		}
		
		delete(list);
		
		return newlist;
	}

	public static double getDecimalRef(DecimalListRef list, double i){

		return list.list[(int)(i)];
	}

	public static void removeDecimalRef(DecimalListRef list, double i){

		list.list = removeDecimal(list.list, i);
	}

	public static StringReference [] addString(StringReference [] list, StringReference a){
		StringReference [] newlist;
		double i;

		newlist = new StringReference [(int)(list.length + 1d)];

		for(i = 0d; i < list.length; i = i + 1d){
			newlist[(int)(i)] = list[(int)(i)];
		}
		newlist[(int)(list.length)] = a;
		
		delete(list);
		
		return newlist;
	}

	public static void addStringRef(StringListRef list, StringReference i){

		list.list = addString(list.list, i);
	}

	public static StringReference [] removeString(StringReference [] list, double n){
		StringReference [] newlist;
		double i;

		newlist = new StringReference [(int)(list.length - 1d)];

		for(i = 0d; i < list.length; i = i + 1d){
			if(i < n){
				newlist[(int)(i)] = list[(int)(i)];
			}
			if(i > n){
				newlist[(int)(i - 1d)] = list[(int)(i)];
			}
		}
		
		delete(list);
		
		return newlist;
	}

	public static StringReference getStringRef(StringListRef list, double i){

		return list.list[(int)(i)];
	}

	public static void removeStringRef(StringListRef list, double i){

		list.list = removeString(list.list, i);
	}

  public static void delete(Object object){
    // Java has garbage collection.
  }


	public static void main(String [] args){
		System.out.println(test());
	}
}
