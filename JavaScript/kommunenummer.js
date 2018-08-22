function createStringReference(string){
  var stringReference;
  stringReference = {};
  stringReference.string = string;
  return stringReference;
}
function lagGyldigReversTabell(nummerliste){
  var i;
  var maxnummer;
  var inverse;
  maxnummer = 0;
  for(i = 0; i < nummerliste.length; i = i + 1){
    maxnummer = Math.max(maxnummer, nummerliste[i]);
  }

  inverse = [];
  inverse.length = maxnummer + 1;

  for(i = 0; i < maxnummer; i = i + 1){
    inverse[i] = false;
  }

  for(i = 0; i < nummerliste.length; i = i + 1){
    inverse[nummerliste[i]] = true;
  }

  return inverse;
}
function hentKommunenavnFraNummer(kommunenummer, success){
  var kommunenavn;
  var kommunenavnListe;
  var nr;
  var stringToDecimalResult;
  kommunenavn = [];
  kommunenavn.length = 0;

  if(erGyldigKommunenummer(kommunenummer)){
    kommunenavnListe = hentKommunenavn();
    stringToDecimalResult = stringToDecimalForBase(kommunenummer, 10);
    if(stringToDecimalResult.success){
      nr = stringToDecimalResult.result;
      kommunenavn = kommunenavnListe[nr].string;
      success.success = true;
    }else{
      success.feilmelding = "Kommunenummer var ikke et gyldig tall.";
      success.success = false;
    }
  }else{
    success.success = false;
    success.feilmelding = "Kommunenummer er ikke gyldig.";
  }

  return kommunenavn;
}
function erGyldigKommunenummer(kommunenummer){
  var gyldig;
  var nr;
  var gyldigKommunetabell;
  if(kommunenummer.length == 4){
    nr = stringToDecimalForBase(kommunenummer, 10).result;
    if(nr >= 101 && nr <= 2030 && erHelttall(nr)){
      gyldigKommunetabell = hentGyldigKommunetabell();
      gyldig = gyldigKommunetabell[nr];
    }else{
      gyldig = false;
    }
  }else{
    gyldig = false;
  }

  return gyldig;
}
function erHelttall(nr){
  return (nr%1) == 0;
}
function hentGyldigKommunetabell(){
  var nummerliste;
  nummerliste = hentGyldigeKommunenummer();
  return lagGyldigReversTabell(nummerliste);
}
function hentKommunenavn(){
  var kommunenavn;
  kommunenavn = [];
  kommunenavn.length = 2100;

  kommunenavn[101] = createStringReference("Halden");
  kommunenavn[104] = createStringReference("Moss");
  kommunenavn[105] = createStringReference("Sarpsborg");
  kommunenavn[106] = createStringReference("Fredrikstad");
  kommunenavn[111] = createStringReference("Hvaler");
  kommunenavn[118] = createStringReference("Aremark");
  kommunenavn[119] = createStringReference("Marker");
  kommunenavn[121] = createStringReference("R\u00f8mskog");
  kommunenavn[122] = createStringReference("Tr\u00f8gstad");
  kommunenavn[123] = createStringReference("Spydeberg");
  kommunenavn[124] = createStringReference("Askim");
  kommunenavn[125] = createStringReference("Eidsberg");
  kommunenavn[127] = createStringReference("Skiptvet");
  kommunenavn[128] = createStringReference("Rakkestad");
  kommunenavn[135] = createStringReference("R\u00e5de");
  kommunenavn[136] = createStringReference("Rygge");
  kommunenavn[137] = createStringReference("V\u00e5ler");
  kommunenavn[138] = createStringReference("Hob\u00f8l");
  kommunenavn[211] = createStringReference("Vestby");
  kommunenavn[213] = createStringReference("Ski");
  kommunenavn[214] = createStringReference("\u00c5s");
  kommunenavn[215] = createStringReference("Frogn");
  kommunenavn[216] = createStringReference("Nesodden");
  kommunenavn[217] = createStringReference("Oppeg\u00e5rd");
  kommunenavn[219] = createStringReference("B\u00e6rum");
  kommunenavn[220] = createStringReference("Asker");
  kommunenavn[221] = createStringReference("Aurskog-H\u00f8land");
  kommunenavn[226] = createStringReference("S\u00f8rum");
  kommunenavn[227] = createStringReference("Fet");
  kommunenavn[228] = createStringReference("R\u00e6lingen");
  kommunenavn[229] = createStringReference("Enebakk");
  kommunenavn[230] = createStringReference("L\u00f8renskog");
  kommunenavn[231] = createStringReference("Skedsmo");
  kommunenavn[233] = createStringReference("Nittedal");
  kommunenavn[234] = createStringReference("Gjerdrum");
  kommunenavn[235] = createStringReference("Ullensaker");
  kommunenavn[236] = createStringReference("Nes");
  kommunenavn[237] = createStringReference("Eidsvoll");
  kommunenavn[238] = createStringReference("Nannestad");
  kommunenavn[239] = createStringReference("Hurdal");
  kommunenavn[301] = createStringReference("Oslo");
  kommunenavn[402] = createStringReference("Kongsvinger");
  kommunenavn[403] = createStringReference("Hamar");
  kommunenavn[412] = createStringReference("Ringsaker");
  kommunenavn[415] = createStringReference("L\u00f8ten");
  kommunenavn[417] = createStringReference("Stange");
  kommunenavn[418] = createStringReference("Nord-Odal");
  kommunenavn[419] = createStringReference("S\u00f8r-Odal");
  kommunenavn[420] = createStringReference("Eidskog");
  kommunenavn[423] = createStringReference("Grue");
  kommunenavn[425] = createStringReference("\u00c5snes");
  kommunenavn[426] = createStringReference("V\u00e5ler");
  kommunenavn[427] = createStringReference("Elverum");
  kommunenavn[428] = createStringReference("Trysil");
  kommunenavn[429] = createStringReference("\u00c5mot");
  kommunenavn[430] = createStringReference("Stor-Elvdal");
  kommunenavn[432] = createStringReference("Rendalen");
  kommunenavn[434] = createStringReference("Engerdal");
  kommunenavn[436] = createStringReference("Tolga");
  kommunenavn[437] = createStringReference("Tynset");
  kommunenavn[438] = createStringReference("Alvdal");
  kommunenavn[439] = createStringReference("Folldal");
  kommunenavn[441] = createStringReference("Os");
  kommunenavn[501] = createStringReference("Lillehammer");
  kommunenavn[502] = createStringReference("Gj\u00f8vik");
  kommunenavn[511] = createStringReference("Dovre");
  kommunenavn[512] = createStringReference("Lesja");
  kommunenavn[513] = createStringReference("Skj\u00e5k");
  kommunenavn[514] = createStringReference("Lom");
  kommunenavn[515] = createStringReference("V\u00e5g\u00e5");
  kommunenavn[516] = createStringReference("Nord-Fron");
  kommunenavn[517] = createStringReference("Sel");
  kommunenavn[519] = createStringReference("S\u00f8r-Fron");
  kommunenavn[520] = createStringReference("Ringebu");
  kommunenavn[521] = createStringReference("\u00d8yer");
  kommunenavn[522] = createStringReference("Gausdal");
  kommunenavn[528] = createStringReference("\u00d8stre Toten");
  kommunenavn[529] = createStringReference("Vestre Toten");
  kommunenavn[532] = createStringReference("Jevnaker");
  kommunenavn[533] = createStringReference("Lunner");
  kommunenavn[534] = createStringReference("Gran");
  kommunenavn[536] = createStringReference("S\u00f8ndre Land");
  kommunenavn[538] = createStringReference("Nordre Land");
  kommunenavn[540] = createStringReference("S\u00f8r-Aurdal");
  kommunenavn[541] = createStringReference("Etnedal");
  kommunenavn[542] = createStringReference("Nord-Aurdal");
  kommunenavn[543] = createStringReference("Vestre Slidre");
  kommunenavn[544] = createStringReference("\u00d8ystre Slidre");
  kommunenavn[545] = createStringReference("Vang");
  kommunenavn[602] = createStringReference("Drammen");
  kommunenavn[604] = createStringReference("Kongsberg");
  kommunenavn[605] = createStringReference("Ringerike");
  kommunenavn[612] = createStringReference("Hole");
  kommunenavn[615] = createStringReference("Fl\u00e5");
  kommunenavn[616] = createStringReference("Nes");
  kommunenavn[617] = createStringReference("Gol");
  kommunenavn[618] = createStringReference("Hemsedal");
  kommunenavn[619] = createStringReference("\u00c5l");
  kommunenavn[620] = createStringReference("Hol");
  kommunenavn[621] = createStringReference("Sigdal");
  kommunenavn[622] = createStringReference("Kr\u00f8dsherad");
  kommunenavn[623] = createStringReference("Modum");
  kommunenavn[624] = createStringReference("\u00d8vre Eiker");
  kommunenavn[625] = createStringReference("Nedre Eiker");
  kommunenavn[626] = createStringReference("Lier");
  kommunenavn[627] = createStringReference("R\u00f8yken");
  kommunenavn[628] = createStringReference("Hurum");
  kommunenavn[631] = createStringReference("Flesberg");
  kommunenavn[632] = createStringReference("Rollag");
  kommunenavn[633] = createStringReference("Nore og Uvdal");
  kommunenavn[701] = createStringReference("Horten");
  kommunenavn[702] = createStringReference("Holmestrand");
  kommunenavn[704] = createStringReference("T\u00f8nsberg");
  kommunenavn[709] = createStringReference("Larvik");
  kommunenavn[710] = createStringReference("Sandefjord");
  kommunenavn[711] = createStringReference("Svelvik");
  kommunenavn[713] = createStringReference("Sande");
  kommunenavn[714] = createStringReference("Hof");
  kommunenavn[716] = createStringReference("Re");
  kommunenavn[722] = createStringReference("N\u00f8tter\u00f8y");
  kommunenavn[723] = createStringReference("Tj\u00f8me");
  kommunenavn[728] = createStringReference("Lardal");
  kommunenavn[805] = createStringReference("Porsgrunn");
  kommunenavn[806] = createStringReference("Skien");
  kommunenavn[807] = createStringReference("Notodden");
  kommunenavn[811] = createStringReference("Siljan");
  kommunenavn[814] = createStringReference("Bamble");
  kommunenavn[815] = createStringReference("Krager\u00f8");
  kommunenavn[817] = createStringReference("Drangedal");
  kommunenavn[819] = createStringReference("Nome");
  kommunenavn[821] = createStringReference("B\u00f8");
  kommunenavn[822] = createStringReference("Sauherad");
  kommunenavn[826] = createStringReference("Tinn");
  kommunenavn[827] = createStringReference("Hjartdal");
  kommunenavn[828] = createStringReference("Seljord");
  kommunenavn[829] = createStringReference("Kviteseid");
  kommunenavn[830] = createStringReference("Nissedal");
  kommunenavn[831] = createStringReference("Fyresdal");
  kommunenavn[833] = createStringReference("Tokke");
  kommunenavn[834] = createStringReference("Vinje");
  kommunenavn[901] = createStringReference("Ris\u00f8r");
  kommunenavn[904] = createStringReference("Grimstad");
  kommunenavn[906] = createStringReference("Arendal");
  kommunenavn[911] = createStringReference("Gjerstad");
  kommunenavn[912] = createStringReference("Veg\u00e5rshei");
  kommunenavn[914] = createStringReference("Tvedestrand");
  kommunenavn[919] = createStringReference("Froland");
  kommunenavn[926] = createStringReference("Lillesand");
  kommunenavn[928] = createStringReference("Birkenes");
  kommunenavn[929] = createStringReference("\u00c5mli");
  kommunenavn[935] = createStringReference("Iveland");
  kommunenavn[937] = createStringReference("Evje og Hornnes");
  kommunenavn[938] = createStringReference("Bygland");
  kommunenavn[940] = createStringReference("Valle");
  kommunenavn[941] = createStringReference("Bykle");
  kommunenavn[1001] = createStringReference("Kristiansand");
  kommunenavn[1002] = createStringReference("Mandal");
  kommunenavn[1003] = createStringReference("Farsund");
  kommunenavn[1004] = createStringReference("Flekkefjord");
  kommunenavn[1014] = createStringReference("Vennesla");
  kommunenavn[1017] = createStringReference("Songdalen");
  kommunenavn[1018] = createStringReference("S\u00f8gne");
  kommunenavn[1021] = createStringReference("Marnardal");
  kommunenavn[1026] = createStringReference("\u00c5seral");
  kommunenavn[1027] = createStringReference("Audnedal");
  kommunenavn[1029] = createStringReference("Lindesnes");
  kommunenavn[1032] = createStringReference("Lyngdal");
  kommunenavn[1034] = createStringReference("H\u00e6gebostad");
  kommunenavn[1037] = createStringReference("Kvinesdal");
  kommunenavn[1046] = createStringReference("Sirdal");
  kommunenavn[1101] = createStringReference("Eigersund");
  kommunenavn[1102] = createStringReference("Sandnes");
  kommunenavn[1103] = createStringReference("Stavanger");
  kommunenavn[1106] = createStringReference("Haugesund");
  kommunenavn[1111] = createStringReference("Sokndal");
  kommunenavn[1112] = createStringReference("Lund");
  kommunenavn[1114] = createStringReference("Bjerkreim");
  kommunenavn[1119] = createStringReference("H\u00e5");
  kommunenavn[1120] = createStringReference("Klepp");
  kommunenavn[1121] = createStringReference("Time");
  kommunenavn[1122] = createStringReference("Gjesdal");
  kommunenavn[1124] = createStringReference("Sola");
  kommunenavn[1127] = createStringReference("Randaberg");
  kommunenavn[1129] = createStringReference("Forsand");
  kommunenavn[1130] = createStringReference("Strand");
  kommunenavn[1133] = createStringReference("Hjelmeland");
  kommunenavn[1134] = createStringReference("Suldal");
  kommunenavn[1135] = createStringReference("Sauda");
  kommunenavn[1141] = createStringReference("Finn\u00f8y");
  kommunenavn[1142] = createStringReference("Rennes\u00f8y");
  kommunenavn[1144] = createStringReference("Kvits\u00f8y");
  kommunenavn[1145] = createStringReference("Bokn");
  kommunenavn[1146] = createStringReference("Tysv\u00e6r");
  kommunenavn[1149] = createStringReference("Karm\u00f8y");
  kommunenavn[1151] = createStringReference("Utsira");
  kommunenavn[1160] = createStringReference("Vindafjord");
  kommunenavn[1201] = createStringReference("Bergen");
  kommunenavn[1211] = createStringReference("Etne");
  kommunenavn[1216] = createStringReference("Sveio");
  kommunenavn[1219] = createStringReference("B\u00f8mlo");
  kommunenavn[1221] = createStringReference("Stord");
  kommunenavn[1222] = createStringReference("Fitjar");
  kommunenavn[1223] = createStringReference("Tysnes");
  kommunenavn[1224] = createStringReference("Kvinnherad");
  kommunenavn[1227] = createStringReference("Jondal");
  kommunenavn[1228] = createStringReference("Odda");
  kommunenavn[1231] = createStringReference("Ullensvang");
  kommunenavn[1232] = createStringReference("Eidfjord");
  kommunenavn[1233] = createStringReference("Ulvik");
  kommunenavn[1234] = createStringReference("Granvin");
  kommunenavn[1235] = createStringReference("Voss");
  kommunenavn[1238] = createStringReference("Kvam");
  kommunenavn[1241] = createStringReference("Fusa");
  kommunenavn[1242] = createStringReference("Samnanger");
  kommunenavn[1243] = createStringReference("Os");
  kommunenavn[1244] = createStringReference("Austevoll");
  kommunenavn[1245] = createStringReference("Sund");
  kommunenavn[1246] = createStringReference("Fjell");
  kommunenavn[1247] = createStringReference("Ask\u00f8y");
  kommunenavn[1251] = createStringReference("Vaksdal");
  kommunenavn[1252] = createStringReference("Modalen");
  kommunenavn[1253] = createStringReference("Oster\u00f8y");
  kommunenavn[1256] = createStringReference("Meland");
  kommunenavn[1259] = createStringReference("\u00d8ygarden");
  kommunenavn[1260] = createStringReference("Rad\u00f8y");
  kommunenavn[1263] = createStringReference("Lind\u00e5s");
  kommunenavn[1264] = createStringReference("Austrheim");
  kommunenavn[1265] = createStringReference("Fedje");
  kommunenavn[1266] = createStringReference("Masfjorden");
  kommunenavn[1401] = createStringReference("Flora");
  kommunenavn[1411] = createStringReference("Gulen");
  kommunenavn[1412] = createStringReference("Solund");
  kommunenavn[1413] = createStringReference("Hyllestad");
  kommunenavn[1416] = createStringReference("H\u00f8yanger");
  kommunenavn[1417] = createStringReference("Vik");
  kommunenavn[1418] = createStringReference("Balestrand");
  kommunenavn[1419] = createStringReference("Leikanger");
  kommunenavn[1420] = createStringReference("Sogndal");
  kommunenavn[1421] = createStringReference("Aurland");
  kommunenavn[1422] = createStringReference("L\u00e6rdal");
  kommunenavn[1424] = createStringReference("\u00c5rdal");
  kommunenavn[1426] = createStringReference("Luster");
  kommunenavn[1428] = createStringReference("Askvoll");
  kommunenavn[1429] = createStringReference("Fjaler");
  kommunenavn[1430] = createStringReference("Gaular");
  kommunenavn[1431] = createStringReference("J\u00f8lster");
  kommunenavn[1432] = createStringReference("F\u00f8rde");
  kommunenavn[1433] = createStringReference("Naustdal");
  kommunenavn[1438] = createStringReference("Bremanger");
  kommunenavn[1439] = createStringReference("V\u00e5gs\u00f8y");
  kommunenavn[1441] = createStringReference("Selje");
  kommunenavn[1443] = createStringReference("Eid");
  kommunenavn[1444] = createStringReference("Hornindal");
  kommunenavn[1445] = createStringReference("Gloppen");
  kommunenavn[1449] = createStringReference("Stryn");
  kommunenavn[1502] = createStringReference("Molde");
  kommunenavn[1504] = createStringReference("\u00c5lesund");
  kommunenavn[1505] = createStringReference("Kristiansund");
  kommunenavn[1511] = createStringReference("Vanylven");
  kommunenavn[1514] = createStringReference("Sande");
  kommunenavn[1515] = createStringReference("Her\u00f8y");
  kommunenavn[1516] = createStringReference("Ulstein");
  kommunenavn[1517] = createStringReference("Hareid");
  kommunenavn[1519] = createStringReference("Volda");
  kommunenavn[1520] = createStringReference("\u00d8rsta");
  kommunenavn[1523] = createStringReference("\u00d8rskog");
  kommunenavn[1524] = createStringReference("Norddal");
  kommunenavn[1525] = createStringReference("Stranda");
  kommunenavn[1526] = createStringReference("Stordal");
  kommunenavn[1528] = createStringReference("Sykkylven");
  kommunenavn[1529] = createStringReference("Skodje");
  kommunenavn[1531] = createStringReference("Sula");
  kommunenavn[1532] = createStringReference("Giske");
  kommunenavn[1534] = createStringReference("Haram");
  kommunenavn[1535] = createStringReference("Vestnes");
  kommunenavn[1539] = createStringReference("Rauma");
  kommunenavn[1543] = createStringReference("Nesset");
  kommunenavn[1545] = createStringReference("Midsund");
  kommunenavn[1546] = createStringReference("Sand\u00f8y");
  kommunenavn[1547] = createStringReference("Aukra");
  kommunenavn[1548] = createStringReference("Fr\u00e6na");
  kommunenavn[1551] = createStringReference("Eide");
  kommunenavn[1554] = createStringReference("Aver\u00f8y");
  kommunenavn[1557] = createStringReference("Gjemnes");
  kommunenavn[1560] = createStringReference("Tingvoll");
  kommunenavn[1563] = createStringReference("Sunndal");
  kommunenavn[1566] = createStringReference("Surnadal");
  kommunenavn[1567] = createStringReference("Rindal");
  kommunenavn[1571] = createStringReference("Halsa");
  kommunenavn[1573] = createStringReference("Sm\u00f8la");
  kommunenavn[1576] = createStringReference("Aure");
  kommunenavn[1601] = createStringReference("Trondheim");
  kommunenavn[1612] = createStringReference("Hemne");
  kommunenavn[1613] = createStringReference("Snillfjord");
  kommunenavn[1617] = createStringReference("Hitra");
  kommunenavn[1620] = createStringReference("Fr\u00f8ya");
  kommunenavn[1621] = createStringReference("\u00d8rland");
  kommunenavn[1622] = createStringReference("Agdenes");
  kommunenavn[1624] = createStringReference("Rissa");
  kommunenavn[1627] = createStringReference("Bjugn");
  kommunenavn[1630] = createStringReference("\u00c5fjord");
  kommunenavn[1632] = createStringReference("Roan");
  kommunenavn[1633] = createStringReference("Osen");
  kommunenavn[1634] = createStringReference("Oppdal");
  kommunenavn[1635] = createStringReference("Rennebu");
  kommunenavn[1636] = createStringReference("Meldal");
  kommunenavn[1638] = createStringReference("Orkdal");
  kommunenavn[1640] = createStringReference("R\u00f8ros");
  kommunenavn[1644] = createStringReference("Holt\u00e5len");
  kommunenavn[1648] = createStringReference("Midtre Gauldal");
  kommunenavn[1653] = createStringReference("Melhus");
  kommunenavn[1657] = createStringReference("Skaun");
  kommunenavn[1662] = createStringReference("Kl\u00e6bu");
  kommunenavn[1663] = createStringReference("Malvik");
  kommunenavn[1664] = createStringReference("Selbu");
  kommunenavn[1665] = createStringReference("Tydal");
  kommunenavn[1702] = createStringReference("Steinkjer");
  kommunenavn[1703] = createStringReference("Namsos");
  kommunenavn[1711] = createStringReference("Mer\u00e5ker");
  kommunenavn[1714] = createStringReference("Stj\u00f8rdal");
  kommunenavn[1717] = createStringReference("Frosta");
  kommunenavn[1718] = createStringReference("Leksvik");
  kommunenavn[1719] = createStringReference("Levanger");
  kommunenavn[1721] = createStringReference("Verdal");
  kommunenavn[1724] = createStringReference("Verran");
  kommunenavn[1725] = createStringReference("Namdalseid");
  kommunenavn[1736] = createStringReference("Sn\u00e5ase \u2013 Sn\u00e5sa");
  kommunenavn[1738] = createStringReference("Lierne");
  kommunenavn[1739] = createStringReference("Raarvihke \u2013 R\u00f8yrvik");
  kommunenavn[1740] = createStringReference("Namsskogan");
  kommunenavn[1742] = createStringReference("Grong");
  kommunenavn[1743] = createStringReference("H\u00f8ylandet");
  kommunenavn[1744] = createStringReference("Overhalla");
  kommunenavn[1748] = createStringReference("Fosnes");
  kommunenavn[1749] = createStringReference("Flatanger");
  kommunenavn[1750] = createStringReference("Vikna");
  kommunenavn[1751] = createStringReference("N\u00e6r\u00f8y");
  kommunenavn[1755] = createStringReference("Leka");
  kommunenavn[1756] = createStringReference("Inder\u00f8y");
  kommunenavn[1804] = createStringReference("Bod\u00f8");
  kommunenavn[1805] = createStringReference("Narvik");
  kommunenavn[1811] = createStringReference("Bindal");
  kommunenavn[1812] = createStringReference("S\u00f8mna");
  kommunenavn[1813] = createStringReference("Br\u00f8nn\u00f8y");
  kommunenavn[1815] = createStringReference("Vega");
  kommunenavn[1816] = createStringReference("Vevelstad");
  kommunenavn[1818] = createStringReference("Her\u00f8y");
  kommunenavn[1820] = createStringReference("Alstahaug");
  kommunenavn[1822] = createStringReference("Leirfjord");
  kommunenavn[1824] = createStringReference("Vefsn");
  kommunenavn[1825] = createStringReference("Grane");
  kommunenavn[1826] = createStringReference("Hattfjelldal");
  kommunenavn[1827] = createStringReference("D\u00f8nna");
  kommunenavn[1828] = createStringReference("Nesna");
  kommunenavn[1832] = createStringReference("Hemnes");
  kommunenavn[1833] = createStringReference("Rana");
  kommunenavn[1834] = createStringReference("Lur\u00f8y");
  kommunenavn[1835] = createStringReference("Tr\u00e6na");
  kommunenavn[1836] = createStringReference("R\u00f8d\u00f8y");
  kommunenavn[1837] = createStringReference("Mel\u00f8y");
  kommunenavn[1838] = createStringReference("Gildesk\u00e5l");
  kommunenavn[1839] = createStringReference("Beiarn");
  kommunenavn[1840] = createStringReference("Saltdal");
  kommunenavn[1841] = createStringReference("Fauske \u2013 Fuossko");
  kommunenavn[1845] = createStringReference("S\u00f8rfold");
  kommunenavn[1848] = createStringReference("Steigen");
  kommunenavn[1849] = createStringReference("Hamar\u00f8y \u2013 H\u00e1bmer");
  kommunenavn[1850] = createStringReference("Divtasvuodna \u2013 Tysfjord");
  kommunenavn[1851] = createStringReference("L\u00f8dingen");
  kommunenavn[1852] = createStringReference("Tjeldsund");
  kommunenavn[1853] = createStringReference("Evenes");
  kommunenavn[1854] = createStringReference("Ballangen");
  kommunenavn[1856] = createStringReference("R\u00f8st");
  kommunenavn[1857] = createStringReference("V\u00e6r\u00f8y");
  kommunenavn[1859] = createStringReference("Flakstad");
  kommunenavn[1860] = createStringReference("Vestv\u00e5g\u00f8y");
  kommunenavn[1865] = createStringReference("V\u00e5gan");
  kommunenavn[1866] = createStringReference("Hadsel");
  kommunenavn[1867] = createStringReference("B\u00f8");
  kommunenavn[1868] = createStringReference("\u00d8ksnes");
  kommunenavn[1870] = createStringReference("Sortland \u2013 Suort\u00e1");
  kommunenavn[1871] = createStringReference("And\u00f8y");
  kommunenavn[1874] = createStringReference("Moskenes");
  kommunenavn[1903] = createStringReference("Harstad \u2013 H\u00e1rstt\u00e1k");
  kommunenavn[1902] = createStringReference("Troms\u00f8");
  kommunenavn[1911] = createStringReference("Kv\u00e6fjord");
  kommunenavn[1913] = createStringReference("Sk\u00e5nland");
  kommunenavn[1917] = createStringReference("Ibestad");
  kommunenavn[1919] = createStringReference("Gratangen");
  kommunenavn[1920] = createStringReference("Loab\u00e1k \u2013 Lavangen");
  kommunenavn[1922] = createStringReference("Bardu");
  kommunenavn[1923] = createStringReference("Salangen");
  kommunenavn[1924] = createStringReference("M\u00e5lselv");
  kommunenavn[1925] = createStringReference("S\u00f8rreisa");
  kommunenavn[1926] = createStringReference("Dyr\u00f8y");
  kommunenavn[1927] = createStringReference("Tran\u00f8y");
  kommunenavn[1928] = createStringReference("Torsken");
  kommunenavn[1929] = createStringReference("Berg");
  kommunenavn[1931] = createStringReference("Lenvik");
  kommunenavn[1933] = createStringReference("Balsfjord");
  kommunenavn[1936] = createStringReference("Karls\u00f8y");
  kommunenavn[1938] = createStringReference("Lyngen");
  kommunenavn[1939] = createStringReference("Storfjord \u2013 Omasvuotna \u2013 Omasvuono");
  kommunenavn[1940] = createStringReference("G\u00e1ivuotna \u2013 K\u00e5fjord \u2013 Kaivuono");
  kommunenavn[1941] = createStringReference("Skjerv\u00f8y");
  kommunenavn[1942] = createStringReference("Nordreisa");
  kommunenavn[1943] = createStringReference("Kv\u00e6nangen");
  kommunenavn[2002] = createStringReference("Vard\u00f8");
  kommunenavn[2003] = createStringReference("Vads\u00f8");
  kommunenavn[2004] = createStringReference("Hammerfest");
  kommunenavn[2011] = createStringReference("Guovdageaidnu \u2013 Kautokeino");
  kommunenavn[2012] = createStringReference("Alta");
  kommunenavn[2014] = createStringReference("Loppa");
  kommunenavn[2015] = createStringReference("Hasvik");
  kommunenavn[2017] = createStringReference("Kvalsund");
  kommunenavn[2018] = createStringReference("M\u00e5s\u00f8y");
  kommunenavn[2019] = createStringReference("Nordkapp");
  kommunenavn[2020] = createStringReference("Porsanger \u2013 Pors\u00e1\u014bgu \u2013 Porsanki");
  kommunenavn[2021] = createStringReference("K\u00e1r\u00e1\u0161johka \u2013 Karasjok");
  kommunenavn[2022] = createStringReference("Lebesby");
  kommunenavn[2023] = createStringReference("Gamvik");
  kommunenavn[2024] = createStringReference("Berlev\u00e5g");
  kommunenavn[2025] = createStringReference("Deatnu \u2013 Tana");
  kommunenavn[2027] = createStringReference("Unj\u00e1rga \u2013 Nesseby");
  kommunenavn[2028] = createStringReference("B\u00e5tsfjord");
  kommunenavn[2030] = createStringReference("S\u00f8r-Varanger");

  return kommunenavn;
}
function hentGyldigeKommunenummer(){
  var gyldigeKommunenummer;
  gyldigeKommunenummer = [];
  gyldigeKommunenummer.length = 425 + 1;

  gyldigeKommunenummer[0] = 101;
  gyldigeKommunenummer[1] = 104;
  gyldigeKommunenummer[2] = 105;
  gyldigeKommunenummer[3] = 106;
  gyldigeKommunenummer[4] = 111;
  gyldigeKommunenummer[5] = 118;
  gyldigeKommunenummer[6] = 119;
  gyldigeKommunenummer[7] = 121;
  gyldigeKommunenummer[8] = 122;
  gyldigeKommunenummer[9] = 123;
  gyldigeKommunenummer[10] = 124;
  gyldigeKommunenummer[11] = 125;
  gyldigeKommunenummer[12] = 127;
  gyldigeKommunenummer[13] = 128;
  gyldigeKommunenummer[14] = 135;
  gyldigeKommunenummer[15] = 136;
  gyldigeKommunenummer[16] = 137;
  gyldigeKommunenummer[17] = 138;
  gyldigeKommunenummer[18] = 211;
  gyldigeKommunenummer[19] = 213;
  gyldigeKommunenummer[20] = 214;
  gyldigeKommunenummer[21] = 215;
  gyldigeKommunenummer[22] = 216;
  gyldigeKommunenummer[23] = 217;
  gyldigeKommunenummer[24] = 219;
  gyldigeKommunenummer[25] = 220;
  gyldigeKommunenummer[26] = 221;
  gyldigeKommunenummer[27] = 226;
  gyldigeKommunenummer[28] = 227;
  gyldigeKommunenummer[29] = 228;
  gyldigeKommunenummer[30] = 229;
  gyldigeKommunenummer[31] = 230;
  gyldigeKommunenummer[32] = 231;
  gyldigeKommunenummer[33] = 233;
  gyldigeKommunenummer[34] = 234;
  gyldigeKommunenummer[35] = 235;
  gyldigeKommunenummer[36] = 236;
  gyldigeKommunenummer[37] = 237;
  gyldigeKommunenummer[38] = 238;
  gyldigeKommunenummer[39] = 239;
  gyldigeKommunenummer[40] = 301;
  gyldigeKommunenummer[41] = 402;
  gyldigeKommunenummer[42] = 403;
  gyldigeKommunenummer[43] = 412;
  gyldigeKommunenummer[44] = 415;
  gyldigeKommunenummer[45] = 417;
  gyldigeKommunenummer[46] = 418;
  gyldigeKommunenummer[47] = 419;
  gyldigeKommunenummer[48] = 420;
  gyldigeKommunenummer[49] = 423;
  gyldigeKommunenummer[50] = 425;
  gyldigeKommunenummer[51] = 426;
  gyldigeKommunenummer[52] = 427;
  gyldigeKommunenummer[53] = 428;
  gyldigeKommunenummer[54] = 429;
  gyldigeKommunenummer[55] = 430;
  gyldigeKommunenummer[56] = 432;
  gyldigeKommunenummer[57] = 434;
  gyldigeKommunenummer[58] = 436;
  gyldigeKommunenummer[59] = 437;
  gyldigeKommunenummer[60] = 438;
  gyldigeKommunenummer[61] = 439;
  gyldigeKommunenummer[62] = 441;
  gyldigeKommunenummer[63] = 501;
  gyldigeKommunenummer[64] = 502;
  gyldigeKommunenummer[65] = 511;
  gyldigeKommunenummer[66] = 512;
  gyldigeKommunenummer[67] = 513;
  gyldigeKommunenummer[68] = 514;
  gyldigeKommunenummer[69] = 515;
  gyldigeKommunenummer[70] = 516;
  gyldigeKommunenummer[71] = 517;
  gyldigeKommunenummer[72] = 519;
  gyldigeKommunenummer[73] = 520;
  gyldigeKommunenummer[74] = 521;
  gyldigeKommunenummer[75] = 522;
  gyldigeKommunenummer[76] = 528;
  gyldigeKommunenummer[77] = 529;
  gyldigeKommunenummer[78] = 532;
  gyldigeKommunenummer[79] = 533;
  gyldigeKommunenummer[80] = 534;
  gyldigeKommunenummer[81] = 536;
  gyldigeKommunenummer[82] = 538;
  gyldigeKommunenummer[83] = 540;
  gyldigeKommunenummer[84] = 541;
  gyldigeKommunenummer[85] = 542;
  gyldigeKommunenummer[86] = 543;
  gyldigeKommunenummer[87] = 544;
  gyldigeKommunenummer[88] = 545;
  gyldigeKommunenummer[89] = 602;
  gyldigeKommunenummer[90] = 604;
  gyldigeKommunenummer[91] = 605;
  gyldigeKommunenummer[92] = 612;
  gyldigeKommunenummer[93] = 615;
  gyldigeKommunenummer[94] = 616;
  gyldigeKommunenummer[95] = 617;
  gyldigeKommunenummer[96] = 618;
  gyldigeKommunenummer[97] = 619;
  gyldigeKommunenummer[98] = 620;
  gyldigeKommunenummer[99] = 621;
  gyldigeKommunenummer[100] = 622;
  gyldigeKommunenummer[101] = 623;
  gyldigeKommunenummer[102] = 624;
  gyldigeKommunenummer[103] = 625;
  gyldigeKommunenummer[104] = 626;
  gyldigeKommunenummer[105] = 627;
  gyldigeKommunenummer[106] = 628;
  gyldigeKommunenummer[107] = 631;
  gyldigeKommunenummer[108] = 632;
  gyldigeKommunenummer[109] = 633;
  gyldigeKommunenummer[110] = 701;
  gyldigeKommunenummer[111] = 702;
  gyldigeKommunenummer[112] = 704;
  gyldigeKommunenummer[113] = 709;
  gyldigeKommunenummer[114] = 710;
  gyldigeKommunenummer[115] = 711;
  gyldigeKommunenummer[116] = 713;
  gyldigeKommunenummer[117] = 714;
  gyldigeKommunenummer[118] = 716;
  gyldigeKommunenummer[119] = 722;
  gyldigeKommunenummer[120] = 723;
  gyldigeKommunenummer[121] = 728;
  gyldigeKommunenummer[122] = 805;
  gyldigeKommunenummer[123] = 806;
  gyldigeKommunenummer[124] = 807;
  gyldigeKommunenummer[125] = 811;
  gyldigeKommunenummer[126] = 814;
  gyldigeKommunenummer[127] = 815;
  gyldigeKommunenummer[128] = 817;
  gyldigeKommunenummer[129] = 819;
  gyldigeKommunenummer[130] = 821;
  gyldigeKommunenummer[131] = 822;
  gyldigeKommunenummer[132] = 826;
  gyldigeKommunenummer[133] = 827;
  gyldigeKommunenummer[134] = 828;
  gyldigeKommunenummer[135] = 829;
  gyldigeKommunenummer[136] = 830;
  gyldigeKommunenummer[137] = 831;
  gyldigeKommunenummer[138] = 833;
  gyldigeKommunenummer[139] = 834;
  gyldigeKommunenummer[140] = 901;
  gyldigeKommunenummer[141] = 904;
  gyldigeKommunenummer[142] = 906;
  gyldigeKommunenummer[143] = 911;
  gyldigeKommunenummer[144] = 912;
  gyldigeKommunenummer[145] = 914;
  gyldigeKommunenummer[146] = 919;
  gyldigeKommunenummer[147] = 926;
  gyldigeKommunenummer[148] = 928;
  gyldigeKommunenummer[149] = 929;
  gyldigeKommunenummer[150] = 935;
  gyldigeKommunenummer[151] = 937;
  gyldigeKommunenummer[152] = 938;
  gyldigeKommunenummer[153] = 940;
  gyldigeKommunenummer[154] = 941;
  gyldigeKommunenummer[155] = 1001;
  gyldigeKommunenummer[156] = 1002;
  gyldigeKommunenummer[157] = 1003;
  gyldigeKommunenummer[158] = 1004;
  gyldigeKommunenummer[159] = 1014;
  gyldigeKommunenummer[160] = 1017;
  gyldigeKommunenummer[161] = 1018;
  gyldigeKommunenummer[162] = 1021;
  gyldigeKommunenummer[163] = 1026;
  gyldigeKommunenummer[164] = 1027;
  gyldigeKommunenummer[165] = 1029;
  gyldigeKommunenummer[166] = 1032;
  gyldigeKommunenummer[167] = 1034;
  gyldigeKommunenummer[168] = 1037;
  gyldigeKommunenummer[169] = 1046;
  gyldigeKommunenummer[170] = 1101;
  gyldigeKommunenummer[171] = 1102;
  gyldigeKommunenummer[172] = 1103;
  gyldigeKommunenummer[173] = 1106;
  gyldigeKommunenummer[174] = 1111;
  gyldigeKommunenummer[175] = 1112;
  gyldigeKommunenummer[176] = 1114;
  gyldigeKommunenummer[177] = 1119;
  gyldigeKommunenummer[178] = 1120;
  gyldigeKommunenummer[179] = 1121;
  gyldigeKommunenummer[180] = 1122;
  gyldigeKommunenummer[181] = 1124;
  gyldigeKommunenummer[182] = 1127;
  gyldigeKommunenummer[183] = 1129;
  gyldigeKommunenummer[184] = 1130;
  gyldigeKommunenummer[185] = 1133;
  gyldigeKommunenummer[186] = 1134;
  gyldigeKommunenummer[187] = 1135;
  gyldigeKommunenummer[188] = 1141;
  gyldigeKommunenummer[189] = 1142;
  gyldigeKommunenummer[190] = 1144;
  gyldigeKommunenummer[191] = 1145;
  gyldigeKommunenummer[192] = 1146;
  gyldigeKommunenummer[193] = 1149;
  gyldigeKommunenummer[194] = 1151;
  gyldigeKommunenummer[195] = 1160;
  gyldigeKommunenummer[196] = 1201;
  gyldigeKommunenummer[197] = 1211;
  gyldigeKommunenummer[198] = 1216;
  gyldigeKommunenummer[199] = 1219;
  gyldigeKommunenummer[200] = 1221;
  gyldigeKommunenummer[201] = 1222;
  gyldigeKommunenummer[202] = 1223;
  gyldigeKommunenummer[203] = 1224;
  gyldigeKommunenummer[204] = 1227;
  gyldigeKommunenummer[205] = 1228;
  gyldigeKommunenummer[206] = 1231;
  gyldigeKommunenummer[207] = 1232;
  gyldigeKommunenummer[208] = 1233;
  gyldigeKommunenummer[209] = 1234;
  gyldigeKommunenummer[210] = 1235;
  gyldigeKommunenummer[211] = 1238;
  gyldigeKommunenummer[212] = 1241;
  gyldigeKommunenummer[213] = 1242;
  gyldigeKommunenummer[214] = 1243;
  gyldigeKommunenummer[215] = 1244;
  gyldigeKommunenummer[216] = 1245;
  gyldigeKommunenummer[217] = 1246;
  gyldigeKommunenummer[218] = 1247;
  gyldigeKommunenummer[219] = 1251;
  gyldigeKommunenummer[220] = 1252;
  gyldigeKommunenummer[221] = 1253;
  gyldigeKommunenummer[222] = 1256;
  gyldigeKommunenummer[223] = 1259;
  gyldigeKommunenummer[224] = 1260;
  gyldigeKommunenummer[225] = 1263;
  gyldigeKommunenummer[226] = 1264;
  gyldigeKommunenummer[227] = 1265;
  gyldigeKommunenummer[228] = 1266;
  gyldigeKommunenummer[229] = 1401;
  gyldigeKommunenummer[230] = 1411;
  gyldigeKommunenummer[231] = 1412;
  gyldigeKommunenummer[232] = 1413;
  gyldigeKommunenummer[233] = 1416;
  gyldigeKommunenummer[234] = 1417;
  gyldigeKommunenummer[235] = 1418;
  gyldigeKommunenummer[236] = 1419;
  gyldigeKommunenummer[237] = 1420;
  gyldigeKommunenummer[238] = 1421;
  gyldigeKommunenummer[239] = 1422;
  gyldigeKommunenummer[240] = 1424;
  gyldigeKommunenummer[241] = 1426;
  gyldigeKommunenummer[242] = 1428;
  gyldigeKommunenummer[243] = 1429;
  gyldigeKommunenummer[244] = 1430;
  gyldigeKommunenummer[245] = 1431;
  gyldigeKommunenummer[246] = 1432;
  gyldigeKommunenummer[247] = 1433;
  gyldigeKommunenummer[248] = 1438;
  gyldigeKommunenummer[249] = 1439;
  gyldigeKommunenummer[250] = 1441;
  gyldigeKommunenummer[251] = 1443;
  gyldigeKommunenummer[252] = 1444;
  gyldigeKommunenummer[253] = 1445;
  gyldigeKommunenummer[254] = 1449;
  gyldigeKommunenummer[255] = 1502;
  gyldigeKommunenummer[256] = 1504;
  gyldigeKommunenummer[257] = 1505;
  gyldigeKommunenummer[258] = 1511;
  gyldigeKommunenummer[259] = 1514;
  gyldigeKommunenummer[260] = 1515;
  gyldigeKommunenummer[261] = 1516;
  gyldigeKommunenummer[262] = 1517;
  gyldigeKommunenummer[263] = 1519;
  gyldigeKommunenummer[264] = 1520;
  gyldigeKommunenummer[265] = 1523;
  gyldigeKommunenummer[266] = 1524;
  gyldigeKommunenummer[267] = 1525;
  gyldigeKommunenummer[268] = 1526;
  gyldigeKommunenummer[269] = 1528;
  gyldigeKommunenummer[270] = 1529;
  gyldigeKommunenummer[271] = 1531;
  gyldigeKommunenummer[272] = 1532;
  gyldigeKommunenummer[273] = 1534;
  gyldigeKommunenummer[274] = 1535;
  gyldigeKommunenummer[275] = 1539;
  gyldigeKommunenummer[276] = 1543;
  gyldigeKommunenummer[277] = 1545;
  gyldigeKommunenummer[278] = 1546;
  gyldigeKommunenummer[279] = 1547;
  gyldigeKommunenummer[280] = 1548;
  gyldigeKommunenummer[281] = 1551;
  gyldigeKommunenummer[282] = 1554;
  gyldigeKommunenummer[283] = 1557;
  gyldigeKommunenummer[284] = 1560;
  gyldigeKommunenummer[285] = 1563;
  gyldigeKommunenummer[286] = 1566;
  gyldigeKommunenummer[287] = 1567;
  gyldigeKommunenummer[288] = 1571;
  gyldigeKommunenummer[289] = 1573;
  gyldigeKommunenummer[290] = 1576;
  gyldigeKommunenummer[291] = 1601;
  gyldigeKommunenummer[292] = 1612;
  gyldigeKommunenummer[293] = 1613;
  gyldigeKommunenummer[294] = 1617;
  gyldigeKommunenummer[295] = 1620;
  gyldigeKommunenummer[296] = 1621;
  gyldigeKommunenummer[297] = 1622;
  gyldigeKommunenummer[298] = 1624;
  gyldigeKommunenummer[299] = 1627;
  gyldigeKommunenummer[300] = 1630;
  gyldigeKommunenummer[301] = 1632;
  gyldigeKommunenummer[302] = 1633;
  gyldigeKommunenummer[303] = 1634;
  gyldigeKommunenummer[304] = 1635;
  gyldigeKommunenummer[305] = 1636;
  gyldigeKommunenummer[306] = 1638;
  gyldigeKommunenummer[307] = 1640;
  gyldigeKommunenummer[308] = 1644;
  gyldigeKommunenummer[309] = 1648;
  gyldigeKommunenummer[310] = 1653;
  gyldigeKommunenummer[311] = 1657;
  gyldigeKommunenummer[312] = 1662;
  gyldigeKommunenummer[313] = 1663;
  gyldigeKommunenummer[314] = 1664;
  gyldigeKommunenummer[315] = 1665;
  gyldigeKommunenummer[316] = 1702;
  gyldigeKommunenummer[317] = 1703;
  gyldigeKommunenummer[318] = 1711;
  gyldigeKommunenummer[319] = 1714;
  gyldigeKommunenummer[320] = 1717;
  gyldigeKommunenummer[321] = 1718;
  gyldigeKommunenummer[322] = 1719;
  gyldigeKommunenummer[323] = 1721;
  gyldigeKommunenummer[324] = 1724;
  gyldigeKommunenummer[325] = 1725;
  gyldigeKommunenummer[326] = 1736;
  gyldigeKommunenummer[327] = 1738;
  gyldigeKommunenummer[328] = 1739;
  gyldigeKommunenummer[329] = 1740;
  gyldigeKommunenummer[330] = 1742;
  gyldigeKommunenummer[331] = 1743;
  gyldigeKommunenummer[332] = 1744;
  gyldigeKommunenummer[333] = 1748;
  gyldigeKommunenummer[334] = 1749;
  gyldigeKommunenummer[335] = 1750;
  gyldigeKommunenummer[336] = 1751;
  gyldigeKommunenummer[337] = 1755;
  gyldigeKommunenummer[338] = 1756;
  gyldigeKommunenummer[339] = 1804;
  gyldigeKommunenummer[340] = 1805;
  gyldigeKommunenummer[341] = 1811;
  gyldigeKommunenummer[342] = 1812;
  gyldigeKommunenummer[343] = 1813;
  gyldigeKommunenummer[344] = 1815;
  gyldigeKommunenummer[345] = 1816;
  gyldigeKommunenummer[346] = 1818;
  gyldigeKommunenummer[347] = 1820;
  gyldigeKommunenummer[348] = 1822;
  gyldigeKommunenummer[349] = 1824;
  gyldigeKommunenummer[350] = 1825;
  gyldigeKommunenummer[351] = 1826;
  gyldigeKommunenummer[352] = 1827;
  gyldigeKommunenummer[353] = 1828;
  gyldigeKommunenummer[354] = 1832;
  gyldigeKommunenummer[355] = 1833;
  gyldigeKommunenummer[356] = 1834;
  gyldigeKommunenummer[357] = 1835;
  gyldigeKommunenummer[358] = 1836;
  gyldigeKommunenummer[359] = 1837;
  gyldigeKommunenummer[360] = 1838;
  gyldigeKommunenummer[361] = 1839;
  gyldigeKommunenummer[362] = 1840;
  gyldigeKommunenummer[363] = 1841;
  gyldigeKommunenummer[364] = 1845;
  gyldigeKommunenummer[365] = 1848;
  gyldigeKommunenummer[366] = 1849;
  gyldigeKommunenummer[367] = 1850;
  gyldigeKommunenummer[368] = 1851;
  gyldigeKommunenummer[369] = 1852;
  gyldigeKommunenummer[370] = 1853;
  gyldigeKommunenummer[371] = 1854;
  gyldigeKommunenummer[372] = 1856;
  gyldigeKommunenummer[373] = 1857;
  gyldigeKommunenummer[374] = 1859;
  gyldigeKommunenummer[375] = 1860;
  gyldigeKommunenummer[376] = 1865;
  gyldigeKommunenummer[377] = 1866;
  gyldigeKommunenummer[378] = 1867;
  gyldigeKommunenummer[379] = 1868;
  gyldigeKommunenummer[380] = 1870;
  gyldigeKommunenummer[381] = 1871;
  gyldigeKommunenummer[382] = 1874;
  gyldigeKommunenummer[383] = 1903;
  gyldigeKommunenummer[384] = 1902;
  gyldigeKommunenummer[385] = 1911;
  gyldigeKommunenummer[386] = 1913;
  gyldigeKommunenummer[387] = 1917;
  gyldigeKommunenummer[388] = 1919;
  gyldigeKommunenummer[389] = 1920;
  gyldigeKommunenummer[390] = 1922;
  gyldigeKommunenummer[391] = 1923;
  gyldigeKommunenummer[392] = 1924;
  gyldigeKommunenummer[393] = 1925;
  gyldigeKommunenummer[394] = 1926;
  gyldigeKommunenummer[395] = 1927;
  gyldigeKommunenummer[396] = 1928;
  gyldigeKommunenummer[397] = 1929;
  gyldigeKommunenummer[398] = 1931;
  gyldigeKommunenummer[399] = 1933;
  gyldigeKommunenummer[400] = 1936;
  gyldigeKommunenummer[401] = 1938;
  gyldigeKommunenummer[402] = 1939;
  gyldigeKommunenummer[403] = 1940;
  gyldigeKommunenummer[404] = 1941;
  gyldigeKommunenummer[405] = 1942;
  gyldigeKommunenummer[406] = 1943;
  gyldigeKommunenummer[407] = 2002;
  gyldigeKommunenummer[408] = 2003;
  gyldigeKommunenummer[409] = 2004;
  gyldigeKommunenummer[410] = 2011;
  gyldigeKommunenummer[411] = 2012;
  gyldigeKommunenummer[412] = 2014;
  gyldigeKommunenummer[413] = 2015;
  gyldigeKommunenummer[414] = 2017;
  gyldigeKommunenummer[415] = 2018;
  gyldigeKommunenummer[416] = 2019;
  gyldigeKommunenummer[417] = 2020;
  gyldigeKommunenummer[418] = 2021;
  gyldigeKommunenummer[419] = 2022;
  gyldigeKommunenummer[420] = 2023;
  gyldigeKommunenummer[421] = 2024;
  gyldigeKommunenummer[422] = 2025;
  gyldigeKommunenummer[423] = 2027;
  gyldigeKommunenummer[424] = 2028;
  gyldigeKommunenummer[425] = 2030;

  return gyldigeKommunenummer;
}
function test1(){
  var doubleReference;
  var success;
  var kommuenavn;
  doubleReference = {};
  doubleReference.doubleValue = 0;

  success = {};
  kommuenavn = hentKommunenavnFraNummer("1640", success);
  assertStringEquals(kommuenavn, "R\u00f8ros", doubleReference);
  assertTrue(success.success, doubleReference);

  return doubleReference.doubleValue;
}
function test(){
  var failures;
  failures = 0;

  failures = failures + test1();

  return failures;
}
function decimalToString(decimal){
  return numberToString(decimal, 10);
}
function numberToString(decimal, base){
  var string;
  var digits;
  var digitPosition;
  var hasPrintedPoint;
  var i, d;
  string = [];
  string.length = 0;

  digits = getDigits(base);

  /* Find digitPosition: */
  digitPosition = getDigitPosition(decimal, base);

  decimal = Math.round(decimal*Math.pow(base,  -digitPosition  + digits - 1));

  hasPrintedPoint = false;

  /* Print leading zeros. */
  if(digitPosition < 0){
    string = appendCharacter(string, '0');
    string = appendCharacter(string, '.');
    hasPrintedPoint = true;
    for(i = 0; i <  -digitPosition  - 1; i = i + 1){
      string = appendCharacter(string, '0');
    }
  }

  /* Print number. */
  for(i = 0; i < digits; i = i + 1){
    d = Math.floor(decimal/Math.pow(base, digits - i - 1));
    if( !hasPrintedPoint  && digitPosition - i + 1 == 0){
      if(decimal != 0){
        string = appendCharacter(string, '.');
      }
      hasPrintedPoint = true;
    }
    if(decimal == 0 && hasPrintedPoint){
    }else{
      string = appendCharacter(string, getSingleDigitFromNumber(d, base));
    }
    decimal = decimal - d*Math.pow(base, digits - i - 1);
  }

  /* Print trailing zeros. */
  for(i = 0; i < digitPosition - digits + 1; i = i + 1){
    string = appendCharacter(string, '0');
  }

  /* Done */
  return string;
}
function getDigits(base){
  var t;
  t = Math.pow(10, 15);
  return Math.floor(Math.log10(t)/Math.log10(base));
}
function getDigitPosition(decimal, base){
  var power;
  var t;
  power = Math.ceil(Math.log10(decimal)/Math.log10(base));

  t = decimal*Math.pow(base,  -power );
  if(t < base && t >= 1){
  }else if(t >= base){
    power = power + 1;
  }else if(t < 1){
    power = power - 1;
  }


  return power;
}
function getSingleDigitFromNumber(c, base){
  var numberTable;
  var retc;
  numberTable = getNumberTable();

  if(c > base - 1){
    retc = '?';
  }else{
    retc = numberTable[c];
  }

  return retc;
}
function getNumberTable(){
  var numberTable;
  numberTable = [];
  numberTable.length = 16;
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
function stringToDecimal(string){
  return stringToDecimalForBase(string, 10);
}
function stringToDecimalForBase(string, base){
  var stringToDecimalResult;
  var c;
  var i, j;
  var isPositive;
  var beforeDecimalPoint;
  var afterDecimalPoint;
  var n;
  var validCharacters;
  var d;
  stringToDecimalResult = {};
  stringToDecimalResult.success = true;
  i = 0;
  isPositive = true;
  beforeDecimalPoint = 0;
  afterDecimalPoint = 0;
  n = 0;
  validCharacters = 0;

  if(base >= 2 && base <= 16){
    for(j = 0; j < string.length; j = j + 1){
      c = string[j];
      if(isNumber(c, base) || c == '.' || c == '-'){
        validCharacters = validCharacters + 1;
      }
    }
    if(validCharacters == string.length){
      if(string.length > 0){
        c = string[i];
        if(c == '-'){
          isPositive = false;
          i = i + 1;
        }
        if(i < string.length){
          c = string[i];
          if(isNumber(c, base)){
            for(; isNumber(c, base) && (i < string.length); ){
              beforeDecimalPoint = beforeDecimalPoint + 1;
              i = i + 1;
              if(i < string.length){
                c = string[i];
              }
            }
            if(i < string.length){
              c = string[i];
              if(c == '.'){
                i = i + 1;
                if(i < string.length){
                  c = string[i];
                  for(; isNumber(c, base) && (i < string.length); ){
                    afterDecimalPoint = afterDecimalPoint + 1;
                    i = i + 1;
                    if(i < string.length){
                      c = string[i];
                    }
                  }
                }else{
                  stringToDecimalResult.success = false;
                  stringToDecimalResult.feilmelding = "Number must have digits after the decimal point.";
                }
              }
            }
          }else{
            stringToDecimalResult.success = false;
            stringToDecimalResult.feilmelding = "Number must start with digits (for negative numbers, after the optional negative sign).";
          }
        }
        if(stringToDecimalResult.success != false){
          i = 0;
          if( !isPositive ){
            i = 1;
          }
          for(j = 0; j < beforeDecimalPoint; j = j + 1){
            c = string[i];
            i = i + 1;
            d = getDecimalFromSingleDecimalDigit(c, base);
            n = n + d*Math.pow(base, beforeDecimalPoint - j - 1);
          }
          if(afterDecimalPoint > 0){
            i = i + 1;
            for(j = 0; j < afterDecimalPoint; j = j + 1){
              c = string[i];
              i = i + 1;
              d = getDecimalFromSingleDecimalDigit(c, base);
              n = n + d*Math.pow(base, 0 - j - 1);
            }
          }
          if( !isPositive ){
            n =  -n ;
          }
          stringToDecimalResult.result = n;
          stringToDecimalResult.success = true;
        }
      }else{
        stringToDecimalResult.success = false;
        stringToDecimalResult.feilmelding = "String has no content.";
      }
    }else{
      stringToDecimalResult.success = false;
      stringToDecimalResult.feilmelding = "String contains invalid character.";
    }
  }else{
    stringToDecimalResult.success = false;
    stringToDecimalResult.feilmelding = "Base must be from 2 to 16.";
  }

  return stringToDecimalResult;
}
function getDecimalFromSingleDecimalDigit(c, base){
  var numberTable;
  var i;
  var position;
  numberTable = getNumberTable();
  position = 0;

  for(i = 0; i < base; i = i + 1){
    if(numberTable[i] == c){
      position = i;
    }
  }

  return position;
}
function isNumber(c, base){
  var numberTable;
  var i;
  var found;
  numberTable = getNumberTable();
  found = false;

  for(i = 0; i < base; i = i + 1){
    if(numberTable[i] == c){
      found = true;
    }
  }

  return found;
}
function assertFalse(b, failures){
  if(b){
    failures.doubleValue = failures.doubleValue + 1;
  }
}
function assertTrue(b, failures){
  if( !b ){
    failures.doubleValue = failures.doubleValue + 1;
  }
}
function assertEquals(a, b, failures){
  if(a != b){
    failures.doubleValue = failures.doubleValue + 1;
  }
}
function assertStringEquals(a, b, failures){
  if( !stringsEqual(a, b) ){
    failures.doubleValue = failures.doubleValue + 1;
  }
}
function stringToNumberArray(string){
  var i;
  var array;
  array = [];
  array.length = string.length;

  for(i = 0; i < string.length; i = i + 1){
    array[i] = string[i].codePointAt(0);
  }
  return array;
}
function numberArrayToString(array){
  var i;
  var string;
  string = [];
  string.length = array.length;

  for(i = 0; i < array.length; i = i + 1){
    string[i] = String.fromCharCode(array[i]);
  }
  return string;
}
function stringsEqual(data1, data2){
  var equal;
  var nrEqual, i;
  equal = false;
  if(data1.length == data2.length){
    nrEqual = 0;
    for(i = 0; i < data1.length; i = i + 1){
      if(data1[i] == data2[i]){
        nrEqual = nrEqual + 1;
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
function numberArraysEqual(data1, data2){
  var equal;
  var nrEqual, i;
  equal = false;
  if(data1.length == data2.length){
    nrEqual = 0;
    for(i = 0; i < data1.length; i = i + 1){
      if(data1[i] == data2[i]){
        nrEqual = nrEqual + 1;
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
function substring(string, from, to){
  var n;
  var i;
  n = [];
  n.length = to - from;

  for(i = from; i < to; i = i + 1){
    n[i - from] = string[i];
  }

  return n;
}
function appendString(string, s){
  var newString;
  var i;
  newString = [];
  newString.length = string.length + s.length;

  for(i = 0; i < string.length; i = i + 1){
    newString[i] = string[i];
  }

  for(i = 0; i < s.length; i = i + 1){
    newString[string.length + i] = s[i];
  }

  delete(string);

  return newString;
}
function appendCharacter(string, c){
  var newString;
  var i;
  newString = [];
  newString.length = string.length + 1;

  for(i = 0; i < string.length; i = i + 1){
    newString[i] = string[i];
  }

  newString[string.length] = c;

  delete(string);

  return newString;
}
function split(toSplit, splitBy){
  var splitt;
  var next;
  var i;
  var c;
  var n;
  splitt = [];
  splitt.length = 0;

  next = [];
  next.length = 0;
  for(i = 0; i < toSplit.length; i = i + 1){
    c = toSplit[i];
    if(c == splitBy){
      n = {};
      n.string = next;
      splitt = addString(splitt, n);
      next = [];
      next.length = 0;
    }else{
      next = appendCharacter(next, c);
    }
  }

  if(next.length > 0){
    n = {};
    n.string = next;
    splitt = addString(splitt, n);
  }

  return splitt;
}
function addDecimal(list, a){
  var newlist;
  var i;
  newlist = [];
  newlist.length = list.length + 1;
  for(i = 0; i < list.length; i = i + 1){
    newlist[i] = list[i];
  }
  newlist[list.length] = a;
		
  delete(list);
		
  return newlist;
}
function addDecimalRef(list, i){
  list.list = addDecimal(list.list, i);
}
function removeDecimal(list, n){
  var newlist;
  var i;
  newlist = [];
  newlist.length = list.length - 1;

  for(i = 0; i < list.length; i = i + 1){
    if(i < n){
      newlist[i] = list[i];
    }
    if(i > n){
      newlist[i - 1] = list[i];
    }
  }
		
  delete(list);
		
  return newlist;
}
function getDecimalRef(list, i){
  return list.list[i];
}
function removeDecimalRef(list, i){
  list.list = removeDecimal(list.list, i);
}
function addString(list, a){
  var newlist;
  var i;
  newlist = [];
  newlist.length = list.length + 1;

  for(i = 0; i < list.length; i = i + 1){
    newlist[i] = list[i];
  }
  newlist[list.length] = a;
		
  delete(list);
		
  return newlist;
}
function addStringRef(list, i){
  list.list = addString(list.list, i);
}
function removeString(list, n){
  var newlist;
  var i;
  newlist = [];
  newlist.length = list.length - 1;

  for(i = 0; i < list.length; i = i + 1){
    if(i < n){
      newlist[i] = list[i];
    }
    if(i > n){
      newlist[i - 1] = list[i];
    }
  }
		
  delete(list);
		
  return newlist;
}
function getStringRef(list, i){
  return list.list[i];
}
function removeStringRef(list, i){
  list.list = removeString(list.list, i);
}


console.log(test());