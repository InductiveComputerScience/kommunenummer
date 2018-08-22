<?php
function createStringReference(&$string){
  $stringReference = new stdClass();
  $stringReference->string = $string;
  return $stringReference;
}
function &lagGyldigReversTabell(&$nummerliste){
  $maxnummer = 0.0;
  for($i = 0.0; $i < count($nummerliste); $i = $i + 1.0){
    $maxnummer = max($maxnummer, $nummerliste[$i]);
  }

  $inverse = array_fill(0, $maxnummer + 1.0, 0);

  for($i = 0.0; $i < $maxnummer; $i = $i + 1.0){
    $inverse[$i] = false;
  }

  for($i = 0.0; $i < count($nummerliste); $i = $i + 1.0){
    $inverse[$nummerliste[$i]] = true;
  }

  return $inverse;
}
function &hentKommunenavnFraNummer(&$kommunenummer, $success){
  $kommunenavn = array_fill(0, 0.0, 0);

  if(erGyldigKommunenummer($kommunenummer)){
    $kommunenavnListe = hentKommunenavn();
    $stringToDecimalResult = stringToDecimalForBase($kommunenummer, 10.0);
    if($stringToDecimalResult->success){
      $nr = $stringToDecimalResult->result;
      $kommunenavn = $kommunenavnListe[$nr]->string;
      $success->success = true;
    }else{
      $success->feilmelding = str_split("Kommunenummer var ikke et gyldig tall.");
      $success->success = false;
    }
  }else{
    $success->success = false;
    $success->feilmelding = str_split("Kommunenummer er ikke gyldig.");
  }

  return $kommunenavn;
}
function erGyldigKommunenummer(&$kommunenummer){
  if(count($kommunenummer) == 4.0){
    $nr = stringToDecimalForBase($kommunenummer, 10.0)->result;
    if($nr >= 101.0 && $nr <= 2030.0 && erHelttall($nr)){
      $gyldigKommunetabell = hentGyldigKommunetabell();
      $gyldig = $gyldigKommunetabell[$nr];
    }else{
      $gyldig = false;
    }
  }else{
    $gyldig = false;
  }

  return $gyldig;
}
function erHelttall($nr){
  return ($nr%1.0) == 0.0;
}
function &hentGyldigKommunetabell(){
  $nummerliste = hentGyldigeKommunenummer();
  return lagGyldigReversTabell($nummerliste);
}
function &hentKommunenavn(){
  $kommunenavn = array_fill(0, 2100.0, 0);

  $kommunenavn[101.0] = createStringReference(str_split("Halden"));
  $kommunenavn[104.0] = createStringReference(str_split("Moss"));
  $kommunenavn[105.0] = createStringReference(str_split("Sarpsborg"));
  $kommunenavn[106.0] = createStringReference(str_split("Fredrikstad"));
  $kommunenavn[111.0] = createStringReference(str_split("Hvaler"));
  $kommunenavn[118.0] = createStringReference(str_split("Aremark"));
  $kommunenavn[119.0] = createStringReference(str_split("Marker"));
  $kommunenavn[121.0] = createStringReference(str_split("R\u00f8mskog"));
  $kommunenavn[122.0] = createStringReference(str_split("Tr\u00f8gstad"));
  $kommunenavn[123.0] = createStringReference(str_split("Spydeberg"));
  $kommunenavn[124.0] = createStringReference(str_split("Askim"));
  $kommunenavn[125.0] = createStringReference(str_split("Eidsberg"));
  $kommunenavn[127.0] = createStringReference(str_split("Skiptvet"));
  $kommunenavn[128.0] = createStringReference(str_split("Rakkestad"));
  $kommunenavn[135.0] = createStringReference(str_split("R\u00e5de"));
  $kommunenavn[136.0] = createStringReference(str_split("Rygge"));
  $kommunenavn[137.0] = createStringReference(str_split("V\u00e5ler"));
  $kommunenavn[138.0] = createStringReference(str_split("Hob\u00f8l"));
  $kommunenavn[211.0] = createStringReference(str_split("Vestby"));
  $kommunenavn[213.0] = createStringReference(str_split("Ski"));
  $kommunenavn[214.0] = createStringReference(str_split("\u00c5s"));
  $kommunenavn[215.0] = createStringReference(str_split("Frogn"));
  $kommunenavn[216.0] = createStringReference(str_split("Nesodden"));
  $kommunenavn[217.0] = createStringReference(str_split("Oppeg\u00e5rd"));
  $kommunenavn[219.0] = createStringReference(str_split("B\u00e6rum"));
  $kommunenavn[220.0] = createStringReference(str_split("Asker"));
  $kommunenavn[221.0] = createStringReference(str_split("Aurskog-H\u00f8land"));
  $kommunenavn[226.0] = createStringReference(str_split("S\u00f8rum"));
  $kommunenavn[227.0] = createStringReference(str_split("Fet"));
  $kommunenavn[228.0] = createStringReference(str_split("R\u00e6lingen"));
  $kommunenavn[229.0] = createStringReference(str_split("Enebakk"));
  $kommunenavn[230.0] = createStringReference(str_split("L\u00f8renskog"));
  $kommunenavn[231.0] = createStringReference(str_split("Skedsmo"));
  $kommunenavn[233.0] = createStringReference(str_split("Nittedal"));
  $kommunenavn[234.0] = createStringReference(str_split("Gjerdrum"));
  $kommunenavn[235.0] = createStringReference(str_split("Ullensaker"));
  $kommunenavn[236.0] = createStringReference(str_split("Nes"));
  $kommunenavn[237.0] = createStringReference(str_split("Eidsvoll"));
  $kommunenavn[238.0] = createStringReference(str_split("Nannestad"));
  $kommunenavn[239.0] = createStringReference(str_split("Hurdal"));
  $kommunenavn[301.0] = createStringReference(str_split("Oslo"));
  $kommunenavn[402.0] = createStringReference(str_split("Kongsvinger"));
  $kommunenavn[403.0] = createStringReference(str_split("Hamar"));
  $kommunenavn[412.0] = createStringReference(str_split("Ringsaker"));
  $kommunenavn[415.0] = createStringReference(str_split("L\u00f8ten"));
  $kommunenavn[417.0] = createStringReference(str_split("Stange"));
  $kommunenavn[418.0] = createStringReference(str_split("Nord-Odal"));
  $kommunenavn[419.0] = createStringReference(str_split("S\u00f8r-Odal"));
  $kommunenavn[420.0] = createStringReference(str_split("Eidskog"));
  $kommunenavn[423.0] = createStringReference(str_split("Grue"));
  $kommunenavn[425.0] = createStringReference(str_split("\u00c5snes"));
  $kommunenavn[426.0] = createStringReference(str_split("V\u00e5ler"));
  $kommunenavn[427.0] = createStringReference(str_split("Elverum"));
  $kommunenavn[428.0] = createStringReference(str_split("Trysil"));
  $kommunenavn[429.0] = createStringReference(str_split("\u00c5mot"));
  $kommunenavn[430.0] = createStringReference(str_split("Stor-Elvdal"));
  $kommunenavn[432.0] = createStringReference(str_split("Rendalen"));
  $kommunenavn[434.0] = createStringReference(str_split("Engerdal"));
  $kommunenavn[436.0] = createStringReference(str_split("Tolga"));
  $kommunenavn[437.0] = createStringReference(str_split("Tynset"));
  $kommunenavn[438.0] = createStringReference(str_split("Alvdal"));
  $kommunenavn[439.0] = createStringReference(str_split("Folldal"));
  $kommunenavn[441.0] = createStringReference(str_split("Os"));
  $kommunenavn[501.0] = createStringReference(str_split("Lillehammer"));
  $kommunenavn[502.0] = createStringReference(str_split("Gj\u00f8vik"));
  $kommunenavn[511.0] = createStringReference(str_split("Dovre"));
  $kommunenavn[512.0] = createStringReference(str_split("Lesja"));
  $kommunenavn[513.0] = createStringReference(str_split("Skj\u00e5k"));
  $kommunenavn[514.0] = createStringReference(str_split("Lom"));
  $kommunenavn[515.0] = createStringReference(str_split("V\u00e5g\u00e5"));
  $kommunenavn[516.0] = createStringReference(str_split("Nord-Fron"));
  $kommunenavn[517.0] = createStringReference(str_split("Sel"));
  $kommunenavn[519.0] = createStringReference(str_split("S\u00f8r-Fron"));
  $kommunenavn[520.0] = createStringReference(str_split("Ringebu"));
  $kommunenavn[521.0] = createStringReference(str_split("\u00d8yer"));
  $kommunenavn[522.0] = createStringReference(str_split("Gausdal"));
  $kommunenavn[528.0] = createStringReference(str_split("\u00d8stre Toten"));
  $kommunenavn[529.0] = createStringReference(str_split("Vestre Toten"));
  $kommunenavn[532.0] = createStringReference(str_split("Jevnaker"));
  $kommunenavn[533.0] = createStringReference(str_split("Lunner"));
  $kommunenavn[534.0] = createStringReference(str_split("Gran"));
  $kommunenavn[536.0] = createStringReference(str_split("S\u00f8ndre Land"));
  $kommunenavn[538.0] = createStringReference(str_split("Nordre Land"));
  $kommunenavn[540.0] = createStringReference(str_split("S\u00f8r-Aurdal"));
  $kommunenavn[541.0] = createStringReference(str_split("Etnedal"));
  $kommunenavn[542.0] = createStringReference(str_split("Nord-Aurdal"));
  $kommunenavn[543.0] = createStringReference(str_split("Vestre Slidre"));
  $kommunenavn[544.0] = createStringReference(str_split("\u00d8ystre Slidre"));
  $kommunenavn[545.0] = createStringReference(str_split("Vang"));
  $kommunenavn[602.0] = createStringReference(str_split("Drammen"));
  $kommunenavn[604.0] = createStringReference(str_split("Kongsberg"));
  $kommunenavn[605.0] = createStringReference(str_split("Ringerike"));
  $kommunenavn[612.0] = createStringReference(str_split("Hole"));
  $kommunenavn[615.0] = createStringReference(str_split("Fl\u00e5"));
  $kommunenavn[616.0] = createStringReference(str_split("Nes"));
  $kommunenavn[617.0] = createStringReference(str_split("Gol"));
  $kommunenavn[618.0] = createStringReference(str_split("Hemsedal"));
  $kommunenavn[619.0] = createStringReference(str_split("\u00c5l"));
  $kommunenavn[620.0] = createStringReference(str_split("Hol"));
  $kommunenavn[621.0] = createStringReference(str_split("Sigdal"));
  $kommunenavn[622.0] = createStringReference(str_split("Kr\u00f8dsherad"));
  $kommunenavn[623.0] = createStringReference(str_split("Modum"));
  $kommunenavn[624.0] = createStringReference(str_split("\u00d8vre Eiker"));
  $kommunenavn[625.0] = createStringReference(str_split("Nedre Eiker"));
  $kommunenavn[626.0] = createStringReference(str_split("Lier"));
  $kommunenavn[627.0] = createStringReference(str_split("R\u00f8yken"));
  $kommunenavn[628.0] = createStringReference(str_split("Hurum"));
  $kommunenavn[631.0] = createStringReference(str_split("Flesberg"));
  $kommunenavn[632.0] = createStringReference(str_split("Rollag"));
  $kommunenavn[633.0] = createStringReference(str_split("Nore og Uvdal"));
  $kommunenavn[701.0] = createStringReference(str_split("Horten"));
  $kommunenavn[702.0] = createStringReference(str_split("Holmestrand"));
  $kommunenavn[704.0] = createStringReference(str_split("T\u00f8nsberg"));
  $kommunenavn[709.0] = createStringReference(str_split("Larvik"));
  $kommunenavn[710.0] = createStringReference(str_split("Sandefjord"));
  $kommunenavn[711.0] = createStringReference(str_split("Svelvik"));
  $kommunenavn[713.0] = createStringReference(str_split("Sande"));
  $kommunenavn[714.0] = createStringReference(str_split("Hof"));
  $kommunenavn[716.0] = createStringReference(str_split("Re"));
  $kommunenavn[722.0] = createStringReference(str_split("N\u00f8tter\u00f8y"));
  $kommunenavn[723.0] = createStringReference(str_split("Tj\u00f8me"));
  $kommunenavn[728.0] = createStringReference(str_split("Lardal"));
  $kommunenavn[805.0] = createStringReference(str_split("Porsgrunn"));
  $kommunenavn[806.0] = createStringReference(str_split("Skien"));
  $kommunenavn[807.0] = createStringReference(str_split("Notodden"));
  $kommunenavn[811.0] = createStringReference(str_split("Siljan"));
  $kommunenavn[814.0] = createStringReference(str_split("Bamble"));
  $kommunenavn[815.0] = createStringReference(str_split("Krager\u00f8"));
  $kommunenavn[817.0] = createStringReference(str_split("Drangedal"));
  $kommunenavn[819.0] = createStringReference(str_split("Nome"));
  $kommunenavn[821.0] = createStringReference(str_split("B\u00f8"));
  $kommunenavn[822.0] = createStringReference(str_split("Sauherad"));
  $kommunenavn[826.0] = createStringReference(str_split("Tinn"));
  $kommunenavn[827.0] = createStringReference(str_split("Hjartdal"));
  $kommunenavn[828.0] = createStringReference(str_split("Seljord"));
  $kommunenavn[829.0] = createStringReference(str_split("Kviteseid"));
  $kommunenavn[830.0] = createStringReference(str_split("Nissedal"));
  $kommunenavn[831.0] = createStringReference(str_split("Fyresdal"));
  $kommunenavn[833.0] = createStringReference(str_split("Tokke"));
  $kommunenavn[834.0] = createStringReference(str_split("Vinje"));
  $kommunenavn[901.0] = createStringReference(str_split("Ris\u00f8r"));
  $kommunenavn[904.0] = createStringReference(str_split("Grimstad"));
  $kommunenavn[906.0] = createStringReference(str_split("Arendal"));
  $kommunenavn[911.0] = createStringReference(str_split("Gjerstad"));
  $kommunenavn[912.0] = createStringReference(str_split("Veg\u00e5rshei"));
  $kommunenavn[914.0] = createStringReference(str_split("Tvedestrand"));
  $kommunenavn[919.0] = createStringReference(str_split("Froland"));
  $kommunenavn[926.0] = createStringReference(str_split("Lillesand"));
  $kommunenavn[928.0] = createStringReference(str_split("Birkenes"));
  $kommunenavn[929.0] = createStringReference(str_split("\u00c5mli"));
  $kommunenavn[935.0] = createStringReference(str_split("Iveland"));
  $kommunenavn[937.0] = createStringReference(str_split("Evje og Hornnes"));
  $kommunenavn[938.0] = createStringReference(str_split("Bygland"));
  $kommunenavn[940.0] = createStringReference(str_split("Valle"));
  $kommunenavn[941.0] = createStringReference(str_split("Bykle"));
  $kommunenavn[1001.0] = createStringReference(str_split("Kristiansand"));
  $kommunenavn[1002.0] = createStringReference(str_split("Mandal"));
  $kommunenavn[1003.0] = createStringReference(str_split("Farsund"));
  $kommunenavn[1004.0] = createStringReference(str_split("Flekkefjord"));
  $kommunenavn[1014.0] = createStringReference(str_split("Vennesla"));
  $kommunenavn[1017.0] = createStringReference(str_split("Songdalen"));
  $kommunenavn[1018.0] = createStringReference(str_split("S\u00f8gne"));
  $kommunenavn[1021.0] = createStringReference(str_split("Marnardal"));
  $kommunenavn[1026.0] = createStringReference(str_split("\u00c5seral"));
  $kommunenavn[1027.0] = createStringReference(str_split("Audnedal"));
  $kommunenavn[1029.0] = createStringReference(str_split("Lindesnes"));
  $kommunenavn[1032.0] = createStringReference(str_split("Lyngdal"));
  $kommunenavn[1034.0] = createStringReference(str_split("H\u00e6gebostad"));
  $kommunenavn[1037.0] = createStringReference(str_split("Kvinesdal"));
  $kommunenavn[1046.0] = createStringReference(str_split("Sirdal"));
  $kommunenavn[1101.0] = createStringReference(str_split("Eigersund"));
  $kommunenavn[1102.0] = createStringReference(str_split("Sandnes"));
  $kommunenavn[1103.0] = createStringReference(str_split("Stavanger"));
  $kommunenavn[1106.0] = createStringReference(str_split("Haugesund"));
  $kommunenavn[1111.0] = createStringReference(str_split("Sokndal"));
  $kommunenavn[1112.0] = createStringReference(str_split("Lund"));
  $kommunenavn[1114.0] = createStringReference(str_split("Bjerkreim"));
  $kommunenavn[1119.0] = createStringReference(str_split("H\u00e5"));
  $kommunenavn[1120.0] = createStringReference(str_split("Klepp"));
  $kommunenavn[1121.0] = createStringReference(str_split("Time"));
  $kommunenavn[1122.0] = createStringReference(str_split("Gjesdal"));
  $kommunenavn[1124.0] = createStringReference(str_split("Sola"));
  $kommunenavn[1127.0] = createStringReference(str_split("Randaberg"));
  $kommunenavn[1129.0] = createStringReference(str_split("Forsand"));
  $kommunenavn[1130.0] = createStringReference(str_split("Strand"));
  $kommunenavn[1133.0] = createStringReference(str_split("Hjelmeland"));
  $kommunenavn[1134.0] = createStringReference(str_split("Suldal"));
  $kommunenavn[1135.0] = createStringReference(str_split("Sauda"));
  $kommunenavn[1141.0] = createStringReference(str_split("Finn\u00f8y"));
  $kommunenavn[1142.0] = createStringReference(str_split("Rennes\u00f8y"));
  $kommunenavn[1144.0] = createStringReference(str_split("Kvits\u00f8y"));
  $kommunenavn[1145.0] = createStringReference(str_split("Bokn"));
  $kommunenavn[1146.0] = createStringReference(str_split("Tysv\u00e6r"));
  $kommunenavn[1149.0] = createStringReference(str_split("Karm\u00f8y"));
  $kommunenavn[1151.0] = createStringReference(str_split("Utsira"));
  $kommunenavn[1160.0] = createStringReference(str_split("Vindafjord"));
  $kommunenavn[1201.0] = createStringReference(str_split("Bergen"));
  $kommunenavn[1211.0] = createStringReference(str_split("Etne"));
  $kommunenavn[1216.0] = createStringReference(str_split("Sveio"));
  $kommunenavn[1219.0] = createStringReference(str_split("B\u00f8mlo"));
  $kommunenavn[1221.0] = createStringReference(str_split("Stord"));
  $kommunenavn[1222.0] = createStringReference(str_split("Fitjar"));
  $kommunenavn[1223.0] = createStringReference(str_split("Tysnes"));
  $kommunenavn[1224.0] = createStringReference(str_split("Kvinnherad"));
  $kommunenavn[1227.0] = createStringReference(str_split("Jondal"));
  $kommunenavn[1228.0] = createStringReference(str_split("Odda"));
  $kommunenavn[1231.0] = createStringReference(str_split("Ullensvang"));
  $kommunenavn[1232.0] = createStringReference(str_split("Eidfjord"));
  $kommunenavn[1233.0] = createStringReference(str_split("Ulvik"));
  $kommunenavn[1234.0] = createStringReference(str_split("Granvin"));
  $kommunenavn[1235.0] = createStringReference(str_split("Voss"));
  $kommunenavn[1238.0] = createStringReference(str_split("Kvam"));
  $kommunenavn[1241.0] = createStringReference(str_split("Fusa"));
  $kommunenavn[1242.0] = createStringReference(str_split("Samnanger"));
  $kommunenavn[1243.0] = createStringReference(str_split("Os"));
  $kommunenavn[1244.0] = createStringReference(str_split("Austevoll"));
  $kommunenavn[1245.0] = createStringReference(str_split("Sund"));
  $kommunenavn[1246.0] = createStringReference(str_split("Fjell"));
  $kommunenavn[1247.0] = createStringReference(str_split("Ask\u00f8y"));
  $kommunenavn[1251.0] = createStringReference(str_split("Vaksdal"));
  $kommunenavn[1252.0] = createStringReference(str_split("Modalen"));
  $kommunenavn[1253.0] = createStringReference(str_split("Oster\u00f8y"));
  $kommunenavn[1256.0] = createStringReference(str_split("Meland"));
  $kommunenavn[1259.0] = createStringReference(str_split("\u00d8ygarden"));
  $kommunenavn[1260.0] = createStringReference(str_split("Rad\u00f8y"));
  $kommunenavn[1263.0] = createStringReference(str_split("Lind\u00e5s"));
  $kommunenavn[1264.0] = createStringReference(str_split("Austrheim"));
  $kommunenavn[1265.0] = createStringReference(str_split("Fedje"));
  $kommunenavn[1266.0] = createStringReference(str_split("Masfjorden"));
  $kommunenavn[1401.0] = createStringReference(str_split("Flora"));
  $kommunenavn[1411.0] = createStringReference(str_split("Gulen"));
  $kommunenavn[1412.0] = createStringReference(str_split("Solund"));
  $kommunenavn[1413.0] = createStringReference(str_split("Hyllestad"));
  $kommunenavn[1416.0] = createStringReference(str_split("H\u00f8yanger"));
  $kommunenavn[1417.0] = createStringReference(str_split("Vik"));
  $kommunenavn[1418.0] = createStringReference(str_split("Balestrand"));
  $kommunenavn[1419.0] = createStringReference(str_split("Leikanger"));
  $kommunenavn[1420.0] = createStringReference(str_split("Sogndal"));
  $kommunenavn[1421.0] = createStringReference(str_split("Aurland"));
  $kommunenavn[1422.0] = createStringReference(str_split("L\u00e6rdal"));
  $kommunenavn[1424.0] = createStringReference(str_split("\u00c5rdal"));
  $kommunenavn[1426.0] = createStringReference(str_split("Luster"));
  $kommunenavn[1428.0] = createStringReference(str_split("Askvoll"));
  $kommunenavn[1429.0] = createStringReference(str_split("Fjaler"));
  $kommunenavn[1430.0] = createStringReference(str_split("Gaular"));
  $kommunenavn[1431.0] = createStringReference(str_split("J\u00f8lster"));
  $kommunenavn[1432.0] = createStringReference(str_split("F\u00f8rde"));
  $kommunenavn[1433.0] = createStringReference(str_split("Naustdal"));
  $kommunenavn[1438.0] = createStringReference(str_split("Bremanger"));
  $kommunenavn[1439.0] = createStringReference(str_split("V\u00e5gs\u00f8y"));
  $kommunenavn[1441.0] = createStringReference(str_split("Selje"));
  $kommunenavn[1443.0] = createStringReference(str_split("Eid"));
  $kommunenavn[1444.0] = createStringReference(str_split("Hornindal"));
  $kommunenavn[1445.0] = createStringReference(str_split("Gloppen"));
  $kommunenavn[1449.0] = createStringReference(str_split("Stryn"));
  $kommunenavn[1502.0] = createStringReference(str_split("Molde"));
  $kommunenavn[1504.0] = createStringReference(str_split("\u00c5lesund"));
  $kommunenavn[1505.0] = createStringReference(str_split("Kristiansund"));
  $kommunenavn[1511.0] = createStringReference(str_split("Vanylven"));
  $kommunenavn[1514.0] = createStringReference(str_split("Sande"));
  $kommunenavn[1515.0] = createStringReference(str_split("Her\u00f8y"));
  $kommunenavn[1516.0] = createStringReference(str_split("Ulstein"));
  $kommunenavn[1517.0] = createStringReference(str_split("Hareid"));
  $kommunenavn[1519.0] = createStringReference(str_split("Volda"));
  $kommunenavn[1520.0] = createStringReference(str_split("\u00d8rsta"));
  $kommunenavn[1523.0] = createStringReference(str_split("\u00d8rskog"));
  $kommunenavn[1524.0] = createStringReference(str_split("Norddal"));
  $kommunenavn[1525.0] = createStringReference(str_split("Stranda"));
  $kommunenavn[1526.0] = createStringReference(str_split("Stordal"));
  $kommunenavn[1528.0] = createStringReference(str_split("Sykkylven"));
  $kommunenavn[1529.0] = createStringReference(str_split("Skodje"));
  $kommunenavn[1531.0] = createStringReference(str_split("Sula"));
  $kommunenavn[1532.0] = createStringReference(str_split("Giske"));
  $kommunenavn[1534.0] = createStringReference(str_split("Haram"));
  $kommunenavn[1535.0] = createStringReference(str_split("Vestnes"));
  $kommunenavn[1539.0] = createStringReference(str_split("Rauma"));
  $kommunenavn[1543.0] = createStringReference(str_split("Nesset"));
  $kommunenavn[1545.0] = createStringReference(str_split("Midsund"));
  $kommunenavn[1546.0] = createStringReference(str_split("Sand\u00f8y"));
  $kommunenavn[1547.0] = createStringReference(str_split("Aukra"));
  $kommunenavn[1548.0] = createStringReference(str_split("Fr\u00e6na"));
  $kommunenavn[1551.0] = createStringReference(str_split("Eide"));
  $kommunenavn[1554.0] = createStringReference(str_split("Aver\u00f8y"));
  $kommunenavn[1557.0] = createStringReference(str_split("Gjemnes"));
  $kommunenavn[1560.0] = createStringReference(str_split("Tingvoll"));
  $kommunenavn[1563.0] = createStringReference(str_split("Sunndal"));
  $kommunenavn[1566.0] = createStringReference(str_split("Surnadal"));
  $kommunenavn[1567.0] = createStringReference(str_split("Rindal"));
  $kommunenavn[1571.0] = createStringReference(str_split("Halsa"));
  $kommunenavn[1573.0] = createStringReference(str_split("Sm\u00f8la"));
  $kommunenavn[1576.0] = createStringReference(str_split("Aure"));
  $kommunenavn[1601.0] = createStringReference(str_split("Trondheim"));
  $kommunenavn[1612.0] = createStringReference(str_split("Hemne"));
  $kommunenavn[1613.0] = createStringReference(str_split("Snillfjord"));
  $kommunenavn[1617.0] = createStringReference(str_split("Hitra"));
  $kommunenavn[1620.0] = createStringReference(str_split("Fr\u00f8ya"));
  $kommunenavn[1621.0] = createStringReference(str_split("\u00d8rland"));
  $kommunenavn[1622.0] = createStringReference(str_split("Agdenes"));
  $kommunenavn[1624.0] = createStringReference(str_split("Rissa"));
  $kommunenavn[1627.0] = createStringReference(str_split("Bjugn"));
  $kommunenavn[1630.0] = createStringReference(str_split("\u00c5fjord"));
  $kommunenavn[1632.0] = createStringReference(str_split("Roan"));
  $kommunenavn[1633.0] = createStringReference(str_split("Osen"));
  $kommunenavn[1634.0] = createStringReference(str_split("Oppdal"));
  $kommunenavn[1635.0] = createStringReference(str_split("Rennebu"));
  $kommunenavn[1636.0] = createStringReference(str_split("Meldal"));
  $kommunenavn[1638.0] = createStringReference(str_split("Orkdal"));
  $kommunenavn[1640.0] = createStringReference(str_split("R\u00f8ros"));
  $kommunenavn[1644.0] = createStringReference(str_split("Holt\u00e5len"));
  $kommunenavn[1648.0] = createStringReference(str_split("Midtre Gauldal"));
  $kommunenavn[1653.0] = createStringReference(str_split("Melhus"));
  $kommunenavn[1657.0] = createStringReference(str_split("Skaun"));
  $kommunenavn[1662.0] = createStringReference(str_split("Kl\u00e6bu"));
  $kommunenavn[1663.0] = createStringReference(str_split("Malvik"));
  $kommunenavn[1664.0] = createStringReference(str_split("Selbu"));
  $kommunenavn[1665.0] = createStringReference(str_split("Tydal"));
  $kommunenavn[1702.0] = createStringReference(str_split("Steinkjer"));
  $kommunenavn[1703.0] = createStringReference(str_split("Namsos"));
  $kommunenavn[1711.0] = createStringReference(str_split("Mer\u00e5ker"));
  $kommunenavn[1714.0] = createStringReference(str_split("Stj\u00f8rdal"));
  $kommunenavn[1717.0] = createStringReference(str_split("Frosta"));
  $kommunenavn[1718.0] = createStringReference(str_split("Leksvik"));
  $kommunenavn[1719.0] = createStringReference(str_split("Levanger"));
  $kommunenavn[1721.0] = createStringReference(str_split("Verdal"));
  $kommunenavn[1724.0] = createStringReference(str_split("Verran"));
  $kommunenavn[1725.0] = createStringReference(str_split("Namdalseid"));
  $kommunenavn[1736.0] = createStringReference(str_split("Sn\u00e5ase \u2013 Sn\u00e5sa"));
  $kommunenavn[1738.0] = createStringReference(str_split("Lierne"));
  $kommunenavn[1739.0] = createStringReference(str_split("Raarvihke \u2013 R\u00f8yrvik"));
  $kommunenavn[1740.0] = createStringReference(str_split("Namsskogan"));
  $kommunenavn[1742.0] = createStringReference(str_split("Grong"));
  $kommunenavn[1743.0] = createStringReference(str_split("H\u00f8ylandet"));
  $kommunenavn[1744.0] = createStringReference(str_split("Overhalla"));
  $kommunenavn[1748.0] = createStringReference(str_split("Fosnes"));
  $kommunenavn[1749.0] = createStringReference(str_split("Flatanger"));
  $kommunenavn[1750.0] = createStringReference(str_split("Vikna"));
  $kommunenavn[1751.0] = createStringReference(str_split("N\u00e6r\u00f8y"));
  $kommunenavn[1755.0] = createStringReference(str_split("Leka"));
  $kommunenavn[1756.0] = createStringReference(str_split("Inder\u00f8y"));
  $kommunenavn[1804.0] = createStringReference(str_split("Bod\u00f8"));
  $kommunenavn[1805.0] = createStringReference(str_split("Narvik"));
  $kommunenavn[1811.0] = createStringReference(str_split("Bindal"));
  $kommunenavn[1812.0] = createStringReference(str_split("S\u00f8mna"));
  $kommunenavn[1813.0] = createStringReference(str_split("Br\u00f8nn\u00f8y"));
  $kommunenavn[1815.0] = createStringReference(str_split("Vega"));
  $kommunenavn[1816.0] = createStringReference(str_split("Vevelstad"));
  $kommunenavn[1818.0] = createStringReference(str_split("Her\u00f8y"));
  $kommunenavn[1820.0] = createStringReference(str_split("Alstahaug"));
  $kommunenavn[1822.0] = createStringReference(str_split("Leirfjord"));
  $kommunenavn[1824.0] = createStringReference(str_split("Vefsn"));
  $kommunenavn[1825.0] = createStringReference(str_split("Grane"));
  $kommunenavn[1826.0] = createStringReference(str_split("Hattfjelldal"));
  $kommunenavn[1827.0] = createStringReference(str_split("D\u00f8nna"));
  $kommunenavn[1828.0] = createStringReference(str_split("Nesna"));
  $kommunenavn[1832.0] = createStringReference(str_split("Hemnes"));
  $kommunenavn[1833.0] = createStringReference(str_split("Rana"));
  $kommunenavn[1834.0] = createStringReference(str_split("Lur\u00f8y"));
  $kommunenavn[1835.0] = createStringReference(str_split("Tr\u00e6na"));
  $kommunenavn[1836.0] = createStringReference(str_split("R\u00f8d\u00f8y"));
  $kommunenavn[1837.0] = createStringReference(str_split("Mel\u00f8y"));
  $kommunenavn[1838.0] = createStringReference(str_split("Gildesk\u00e5l"));
  $kommunenavn[1839.0] = createStringReference(str_split("Beiarn"));
  $kommunenavn[1840.0] = createStringReference(str_split("Saltdal"));
  $kommunenavn[1841.0] = createStringReference(str_split("Fauske \u2013 Fuossko"));
  $kommunenavn[1845.0] = createStringReference(str_split("S\u00f8rfold"));
  $kommunenavn[1848.0] = createStringReference(str_split("Steigen"));
  $kommunenavn[1849.0] = createStringReference(str_split("Hamar\u00f8y \u2013 H\u00e1bmer"));
  $kommunenavn[1850.0] = createStringReference(str_split("Divtasvuodna \u2013 Tysfjord"));
  $kommunenavn[1851.0] = createStringReference(str_split("L\u00f8dingen"));
  $kommunenavn[1852.0] = createStringReference(str_split("Tjeldsund"));
  $kommunenavn[1853.0] = createStringReference(str_split("Evenes"));
  $kommunenavn[1854.0] = createStringReference(str_split("Ballangen"));
  $kommunenavn[1856.0] = createStringReference(str_split("R\u00f8st"));
  $kommunenavn[1857.0] = createStringReference(str_split("V\u00e6r\u00f8y"));
  $kommunenavn[1859.0] = createStringReference(str_split("Flakstad"));
  $kommunenavn[1860.0] = createStringReference(str_split("Vestv\u00e5g\u00f8y"));
  $kommunenavn[1865.0] = createStringReference(str_split("V\u00e5gan"));
  $kommunenavn[1866.0] = createStringReference(str_split("Hadsel"));
  $kommunenavn[1867.0] = createStringReference(str_split("B\u00f8"));
  $kommunenavn[1868.0] = createStringReference(str_split("\u00d8ksnes"));
  $kommunenavn[1870.0] = createStringReference(str_split("Sortland \u2013 Suort\u00e1"));
  $kommunenavn[1871.0] = createStringReference(str_split("And\u00f8y"));
  $kommunenavn[1874.0] = createStringReference(str_split("Moskenes"));
  $kommunenavn[1903.0] = createStringReference(str_split("Harstad \u2013 H\u00e1rstt\u00e1k"));
  $kommunenavn[1902.0] = createStringReference(str_split("Troms\u00f8"));
  $kommunenavn[1911.0] = createStringReference(str_split("Kv\u00e6fjord"));
  $kommunenavn[1913.0] = createStringReference(str_split("Sk\u00e5nland"));
  $kommunenavn[1917.0] = createStringReference(str_split("Ibestad"));
  $kommunenavn[1919.0] = createStringReference(str_split("Gratangen"));
  $kommunenavn[1920.0] = createStringReference(str_split("Loab\u00e1k \u2013 Lavangen"));
  $kommunenavn[1922.0] = createStringReference(str_split("Bardu"));
  $kommunenavn[1923.0] = createStringReference(str_split("Salangen"));
  $kommunenavn[1924.0] = createStringReference(str_split("M\u00e5lselv"));
  $kommunenavn[1925.0] = createStringReference(str_split("S\u00f8rreisa"));
  $kommunenavn[1926.0] = createStringReference(str_split("Dyr\u00f8y"));
  $kommunenavn[1927.0] = createStringReference(str_split("Tran\u00f8y"));
  $kommunenavn[1928.0] = createStringReference(str_split("Torsken"));
  $kommunenavn[1929.0] = createStringReference(str_split("Berg"));
  $kommunenavn[1931.0] = createStringReference(str_split("Lenvik"));
  $kommunenavn[1933.0] = createStringReference(str_split("Balsfjord"));
  $kommunenavn[1936.0] = createStringReference(str_split("Karls\u00f8y"));
  $kommunenavn[1938.0] = createStringReference(str_split("Lyngen"));
  $kommunenavn[1939.0] = createStringReference(str_split("Storfjord \u2013 Omasvuotna \u2013 Omasvuono"));
  $kommunenavn[1940.0] = createStringReference(str_split("G\u00e1ivuotna \u2013 K\u00e5fjord \u2013 Kaivuono"));
  $kommunenavn[1941.0] = createStringReference(str_split("Skjerv\u00f8y"));
  $kommunenavn[1942.0] = createStringReference(str_split("Nordreisa"));
  $kommunenavn[1943.0] = createStringReference(str_split("Kv\u00e6nangen"));
  $kommunenavn[2002.0] = createStringReference(str_split("Vard\u00f8"));
  $kommunenavn[2003.0] = createStringReference(str_split("Vads\u00f8"));
  $kommunenavn[2004.0] = createStringReference(str_split("Hammerfest"));
  $kommunenavn[2011.0] = createStringReference(str_split("Guovdageaidnu \u2013 Kautokeino"));
  $kommunenavn[2012.0] = createStringReference(str_split("Alta"));
  $kommunenavn[2014.0] = createStringReference(str_split("Loppa"));
  $kommunenavn[2015.0] = createStringReference(str_split("Hasvik"));
  $kommunenavn[2017.0] = createStringReference(str_split("Kvalsund"));
  $kommunenavn[2018.0] = createStringReference(str_split("M\u00e5s\u00f8y"));
  $kommunenavn[2019.0] = createStringReference(str_split("Nordkapp"));
  $kommunenavn[2020.0] = createStringReference(str_split("Porsanger \u2013 Pors\u00e1\u014bgu \u2013 Porsanki"));
  $kommunenavn[2021.0] = createStringReference(str_split("K\u00e1r\u00e1\u0161johka \u2013 Karasjok"));
  $kommunenavn[2022.0] = createStringReference(str_split("Lebesby"));
  $kommunenavn[2023.0] = createStringReference(str_split("Gamvik"));
  $kommunenavn[2024.0] = createStringReference(str_split("Berlev\u00e5g"));
  $kommunenavn[2025.0] = createStringReference(str_split("Deatnu \u2013 Tana"));
  $kommunenavn[2027.0] = createStringReference(str_split("Unj\u00e1rga \u2013 Nesseby"));
  $kommunenavn[2028.0] = createStringReference(str_split("B\u00e5tsfjord"));
  $kommunenavn[2030.0] = createStringReference(str_split("S\u00f8r-Varanger"));

  return $kommunenavn;
}
function &hentGyldigeKommunenummer(){
  $gyldigeKommunenummer = array_fill(0, 425.0 + 1.0, 0);

  $gyldigeKommunenummer[0.0] = 101.0;
  $gyldigeKommunenummer[1.0] = 104.0;
  $gyldigeKommunenummer[2.0] = 105.0;
  $gyldigeKommunenummer[3.0] = 106.0;
  $gyldigeKommunenummer[4.0] = 111.0;
  $gyldigeKommunenummer[5.0] = 118.0;
  $gyldigeKommunenummer[6.0] = 119.0;
  $gyldigeKommunenummer[7.0] = 121.0;
  $gyldigeKommunenummer[8.0] = 122.0;
  $gyldigeKommunenummer[9.0] = 123.0;
  $gyldigeKommunenummer[10.0] = 124.0;
  $gyldigeKommunenummer[11.0] = 125.0;
  $gyldigeKommunenummer[12.0] = 127.0;
  $gyldigeKommunenummer[13.0] = 128.0;
  $gyldigeKommunenummer[14.0] = 135.0;
  $gyldigeKommunenummer[15.0] = 136.0;
  $gyldigeKommunenummer[16.0] = 137.0;
  $gyldigeKommunenummer[17.0] = 138.0;
  $gyldigeKommunenummer[18.0] = 211.0;
  $gyldigeKommunenummer[19.0] = 213.0;
  $gyldigeKommunenummer[20.0] = 214.0;
  $gyldigeKommunenummer[21.0] = 215.0;
  $gyldigeKommunenummer[22.0] = 216.0;
  $gyldigeKommunenummer[23.0] = 217.0;
  $gyldigeKommunenummer[24.0] = 219.0;
  $gyldigeKommunenummer[25.0] = 220.0;
  $gyldigeKommunenummer[26.0] = 221.0;
  $gyldigeKommunenummer[27.0] = 226.0;
  $gyldigeKommunenummer[28.0] = 227.0;
  $gyldigeKommunenummer[29.0] = 228.0;
  $gyldigeKommunenummer[30.0] = 229.0;
  $gyldigeKommunenummer[31.0] = 230.0;
  $gyldigeKommunenummer[32.0] = 231.0;
  $gyldigeKommunenummer[33.0] = 233.0;
  $gyldigeKommunenummer[34.0] = 234.0;
  $gyldigeKommunenummer[35.0] = 235.0;
  $gyldigeKommunenummer[36.0] = 236.0;
  $gyldigeKommunenummer[37.0] = 237.0;
  $gyldigeKommunenummer[38.0] = 238.0;
  $gyldigeKommunenummer[39.0] = 239.0;
  $gyldigeKommunenummer[40.0] = 301.0;
  $gyldigeKommunenummer[41.0] = 402.0;
  $gyldigeKommunenummer[42.0] = 403.0;
  $gyldigeKommunenummer[43.0] = 412.0;
  $gyldigeKommunenummer[44.0] = 415.0;
  $gyldigeKommunenummer[45.0] = 417.0;
  $gyldigeKommunenummer[46.0] = 418.0;
  $gyldigeKommunenummer[47.0] = 419.0;
  $gyldigeKommunenummer[48.0] = 420.0;
  $gyldigeKommunenummer[49.0] = 423.0;
  $gyldigeKommunenummer[50.0] = 425.0;
  $gyldigeKommunenummer[51.0] = 426.0;
  $gyldigeKommunenummer[52.0] = 427.0;
  $gyldigeKommunenummer[53.0] = 428.0;
  $gyldigeKommunenummer[54.0] = 429.0;
  $gyldigeKommunenummer[55.0] = 430.0;
  $gyldigeKommunenummer[56.0] = 432.0;
  $gyldigeKommunenummer[57.0] = 434.0;
  $gyldigeKommunenummer[58.0] = 436.0;
  $gyldigeKommunenummer[59.0] = 437.0;
  $gyldigeKommunenummer[60.0] = 438.0;
  $gyldigeKommunenummer[61.0] = 439.0;
  $gyldigeKommunenummer[62.0] = 441.0;
  $gyldigeKommunenummer[63.0] = 501.0;
  $gyldigeKommunenummer[64.0] = 502.0;
  $gyldigeKommunenummer[65.0] = 511.0;
  $gyldigeKommunenummer[66.0] = 512.0;
  $gyldigeKommunenummer[67.0] = 513.0;
  $gyldigeKommunenummer[68.0] = 514.0;
  $gyldigeKommunenummer[69.0] = 515.0;
  $gyldigeKommunenummer[70.0] = 516.0;
  $gyldigeKommunenummer[71.0] = 517.0;
  $gyldigeKommunenummer[72.0] = 519.0;
  $gyldigeKommunenummer[73.0] = 520.0;
  $gyldigeKommunenummer[74.0] = 521.0;
  $gyldigeKommunenummer[75.0] = 522.0;
  $gyldigeKommunenummer[76.0] = 528.0;
  $gyldigeKommunenummer[77.0] = 529.0;
  $gyldigeKommunenummer[78.0] = 532.0;
  $gyldigeKommunenummer[79.0] = 533.0;
  $gyldigeKommunenummer[80.0] = 534.0;
  $gyldigeKommunenummer[81.0] = 536.0;
  $gyldigeKommunenummer[82.0] = 538.0;
  $gyldigeKommunenummer[83.0] = 540.0;
  $gyldigeKommunenummer[84.0] = 541.0;
  $gyldigeKommunenummer[85.0] = 542.0;
  $gyldigeKommunenummer[86.0] = 543.0;
  $gyldigeKommunenummer[87.0] = 544.0;
  $gyldigeKommunenummer[88.0] = 545.0;
  $gyldigeKommunenummer[89.0] = 602.0;
  $gyldigeKommunenummer[90.0] = 604.0;
  $gyldigeKommunenummer[91.0] = 605.0;
  $gyldigeKommunenummer[92.0] = 612.0;
  $gyldigeKommunenummer[93.0] = 615.0;
  $gyldigeKommunenummer[94.0] = 616.0;
  $gyldigeKommunenummer[95.0] = 617.0;
  $gyldigeKommunenummer[96.0] = 618.0;
  $gyldigeKommunenummer[97.0] = 619.0;
  $gyldigeKommunenummer[98.0] = 620.0;
  $gyldigeKommunenummer[99.0] = 621.0;
  $gyldigeKommunenummer[100.0] = 622.0;
  $gyldigeKommunenummer[101.0] = 623.0;
  $gyldigeKommunenummer[102.0] = 624.0;
  $gyldigeKommunenummer[103.0] = 625.0;
  $gyldigeKommunenummer[104.0] = 626.0;
  $gyldigeKommunenummer[105.0] = 627.0;
  $gyldigeKommunenummer[106.0] = 628.0;
  $gyldigeKommunenummer[107.0] = 631.0;
  $gyldigeKommunenummer[108.0] = 632.0;
  $gyldigeKommunenummer[109.0] = 633.0;
  $gyldigeKommunenummer[110.0] = 701.0;
  $gyldigeKommunenummer[111.0] = 702.0;
  $gyldigeKommunenummer[112.0] = 704.0;
  $gyldigeKommunenummer[113.0] = 709.0;
  $gyldigeKommunenummer[114.0] = 710.0;
  $gyldigeKommunenummer[115.0] = 711.0;
  $gyldigeKommunenummer[116.0] = 713.0;
  $gyldigeKommunenummer[117.0] = 714.0;
  $gyldigeKommunenummer[118.0] = 716.0;
  $gyldigeKommunenummer[119.0] = 722.0;
  $gyldigeKommunenummer[120.0] = 723.0;
  $gyldigeKommunenummer[121.0] = 728.0;
  $gyldigeKommunenummer[122.0] = 805.0;
  $gyldigeKommunenummer[123.0] = 806.0;
  $gyldigeKommunenummer[124.0] = 807.0;
  $gyldigeKommunenummer[125.0] = 811.0;
  $gyldigeKommunenummer[126.0] = 814.0;
  $gyldigeKommunenummer[127.0] = 815.0;
  $gyldigeKommunenummer[128.0] = 817.0;
  $gyldigeKommunenummer[129.0] = 819.0;
  $gyldigeKommunenummer[130.0] = 821.0;
  $gyldigeKommunenummer[131.0] = 822.0;
  $gyldigeKommunenummer[132.0] = 826.0;
  $gyldigeKommunenummer[133.0] = 827.0;
  $gyldigeKommunenummer[134.0] = 828.0;
  $gyldigeKommunenummer[135.0] = 829.0;
  $gyldigeKommunenummer[136.0] = 830.0;
  $gyldigeKommunenummer[137.0] = 831.0;
  $gyldigeKommunenummer[138.0] = 833.0;
  $gyldigeKommunenummer[139.0] = 834.0;
  $gyldigeKommunenummer[140.0] = 901.0;
  $gyldigeKommunenummer[141.0] = 904.0;
  $gyldigeKommunenummer[142.0] = 906.0;
  $gyldigeKommunenummer[143.0] = 911.0;
  $gyldigeKommunenummer[144.0] = 912.0;
  $gyldigeKommunenummer[145.0] = 914.0;
  $gyldigeKommunenummer[146.0] = 919.0;
  $gyldigeKommunenummer[147.0] = 926.0;
  $gyldigeKommunenummer[148.0] = 928.0;
  $gyldigeKommunenummer[149.0] = 929.0;
  $gyldigeKommunenummer[150.0] = 935.0;
  $gyldigeKommunenummer[151.0] = 937.0;
  $gyldigeKommunenummer[152.0] = 938.0;
  $gyldigeKommunenummer[153.0] = 940.0;
  $gyldigeKommunenummer[154.0] = 941.0;
  $gyldigeKommunenummer[155.0] = 1001.0;
  $gyldigeKommunenummer[156.0] = 1002.0;
  $gyldigeKommunenummer[157.0] = 1003.0;
  $gyldigeKommunenummer[158.0] = 1004.0;
  $gyldigeKommunenummer[159.0] = 1014.0;
  $gyldigeKommunenummer[160.0] = 1017.0;
  $gyldigeKommunenummer[161.0] = 1018.0;
  $gyldigeKommunenummer[162.0] = 1021.0;
  $gyldigeKommunenummer[163.0] = 1026.0;
  $gyldigeKommunenummer[164.0] = 1027.0;
  $gyldigeKommunenummer[165.0] = 1029.0;
  $gyldigeKommunenummer[166.0] = 1032.0;
  $gyldigeKommunenummer[167.0] = 1034.0;
  $gyldigeKommunenummer[168.0] = 1037.0;
  $gyldigeKommunenummer[169.0] = 1046.0;
  $gyldigeKommunenummer[170.0] = 1101.0;
  $gyldigeKommunenummer[171.0] = 1102.0;
  $gyldigeKommunenummer[172.0] = 1103.0;
  $gyldigeKommunenummer[173.0] = 1106.0;
  $gyldigeKommunenummer[174.0] = 1111.0;
  $gyldigeKommunenummer[175.0] = 1112.0;
  $gyldigeKommunenummer[176.0] = 1114.0;
  $gyldigeKommunenummer[177.0] = 1119.0;
  $gyldigeKommunenummer[178.0] = 1120.0;
  $gyldigeKommunenummer[179.0] = 1121.0;
  $gyldigeKommunenummer[180.0] = 1122.0;
  $gyldigeKommunenummer[181.0] = 1124.0;
  $gyldigeKommunenummer[182.0] = 1127.0;
  $gyldigeKommunenummer[183.0] = 1129.0;
  $gyldigeKommunenummer[184.0] = 1130.0;
  $gyldigeKommunenummer[185.0] = 1133.0;
  $gyldigeKommunenummer[186.0] = 1134.0;
  $gyldigeKommunenummer[187.0] = 1135.0;
  $gyldigeKommunenummer[188.0] = 1141.0;
  $gyldigeKommunenummer[189.0] = 1142.0;
  $gyldigeKommunenummer[190.0] = 1144.0;
  $gyldigeKommunenummer[191.0] = 1145.0;
  $gyldigeKommunenummer[192.0] = 1146.0;
  $gyldigeKommunenummer[193.0] = 1149.0;
  $gyldigeKommunenummer[194.0] = 1151.0;
  $gyldigeKommunenummer[195.0] = 1160.0;
  $gyldigeKommunenummer[196.0] = 1201.0;
  $gyldigeKommunenummer[197.0] = 1211.0;
  $gyldigeKommunenummer[198.0] = 1216.0;
  $gyldigeKommunenummer[199.0] = 1219.0;
  $gyldigeKommunenummer[200.0] = 1221.0;
  $gyldigeKommunenummer[201.0] = 1222.0;
  $gyldigeKommunenummer[202.0] = 1223.0;
  $gyldigeKommunenummer[203.0] = 1224.0;
  $gyldigeKommunenummer[204.0] = 1227.0;
  $gyldigeKommunenummer[205.0] = 1228.0;
  $gyldigeKommunenummer[206.0] = 1231.0;
  $gyldigeKommunenummer[207.0] = 1232.0;
  $gyldigeKommunenummer[208.0] = 1233.0;
  $gyldigeKommunenummer[209.0] = 1234.0;
  $gyldigeKommunenummer[210.0] = 1235.0;
  $gyldigeKommunenummer[211.0] = 1238.0;
  $gyldigeKommunenummer[212.0] = 1241.0;
  $gyldigeKommunenummer[213.0] = 1242.0;
  $gyldigeKommunenummer[214.0] = 1243.0;
  $gyldigeKommunenummer[215.0] = 1244.0;
  $gyldigeKommunenummer[216.0] = 1245.0;
  $gyldigeKommunenummer[217.0] = 1246.0;
  $gyldigeKommunenummer[218.0] = 1247.0;
  $gyldigeKommunenummer[219.0] = 1251.0;
  $gyldigeKommunenummer[220.0] = 1252.0;
  $gyldigeKommunenummer[221.0] = 1253.0;
  $gyldigeKommunenummer[222.0] = 1256.0;
  $gyldigeKommunenummer[223.0] = 1259.0;
  $gyldigeKommunenummer[224.0] = 1260.0;
  $gyldigeKommunenummer[225.0] = 1263.0;
  $gyldigeKommunenummer[226.0] = 1264.0;
  $gyldigeKommunenummer[227.0] = 1265.0;
  $gyldigeKommunenummer[228.0] = 1266.0;
  $gyldigeKommunenummer[229.0] = 1401.0;
  $gyldigeKommunenummer[230.0] = 1411.0;
  $gyldigeKommunenummer[231.0] = 1412.0;
  $gyldigeKommunenummer[232.0] = 1413.0;
  $gyldigeKommunenummer[233.0] = 1416.0;
  $gyldigeKommunenummer[234.0] = 1417.0;
  $gyldigeKommunenummer[235.0] = 1418.0;
  $gyldigeKommunenummer[236.0] = 1419.0;
  $gyldigeKommunenummer[237.0] = 1420.0;
  $gyldigeKommunenummer[238.0] = 1421.0;
  $gyldigeKommunenummer[239.0] = 1422.0;
  $gyldigeKommunenummer[240.0] = 1424.0;
  $gyldigeKommunenummer[241.0] = 1426.0;
  $gyldigeKommunenummer[242.0] = 1428.0;
  $gyldigeKommunenummer[243.0] = 1429.0;
  $gyldigeKommunenummer[244.0] = 1430.0;
  $gyldigeKommunenummer[245.0] = 1431.0;
  $gyldigeKommunenummer[246.0] = 1432.0;
  $gyldigeKommunenummer[247.0] = 1433.0;
  $gyldigeKommunenummer[248.0] = 1438.0;
  $gyldigeKommunenummer[249.0] = 1439.0;
  $gyldigeKommunenummer[250.0] = 1441.0;
  $gyldigeKommunenummer[251.0] = 1443.0;
  $gyldigeKommunenummer[252.0] = 1444.0;
  $gyldigeKommunenummer[253.0] = 1445.0;
  $gyldigeKommunenummer[254.0] = 1449.0;
  $gyldigeKommunenummer[255.0] = 1502.0;
  $gyldigeKommunenummer[256.0] = 1504.0;
  $gyldigeKommunenummer[257.0] = 1505.0;
  $gyldigeKommunenummer[258.0] = 1511.0;
  $gyldigeKommunenummer[259.0] = 1514.0;
  $gyldigeKommunenummer[260.0] = 1515.0;
  $gyldigeKommunenummer[261.0] = 1516.0;
  $gyldigeKommunenummer[262.0] = 1517.0;
  $gyldigeKommunenummer[263.0] = 1519.0;
  $gyldigeKommunenummer[264.0] = 1520.0;
  $gyldigeKommunenummer[265.0] = 1523.0;
  $gyldigeKommunenummer[266.0] = 1524.0;
  $gyldigeKommunenummer[267.0] = 1525.0;
  $gyldigeKommunenummer[268.0] = 1526.0;
  $gyldigeKommunenummer[269.0] = 1528.0;
  $gyldigeKommunenummer[270.0] = 1529.0;
  $gyldigeKommunenummer[271.0] = 1531.0;
  $gyldigeKommunenummer[272.0] = 1532.0;
  $gyldigeKommunenummer[273.0] = 1534.0;
  $gyldigeKommunenummer[274.0] = 1535.0;
  $gyldigeKommunenummer[275.0] = 1539.0;
  $gyldigeKommunenummer[276.0] = 1543.0;
  $gyldigeKommunenummer[277.0] = 1545.0;
  $gyldigeKommunenummer[278.0] = 1546.0;
  $gyldigeKommunenummer[279.0] = 1547.0;
  $gyldigeKommunenummer[280.0] = 1548.0;
  $gyldigeKommunenummer[281.0] = 1551.0;
  $gyldigeKommunenummer[282.0] = 1554.0;
  $gyldigeKommunenummer[283.0] = 1557.0;
  $gyldigeKommunenummer[284.0] = 1560.0;
  $gyldigeKommunenummer[285.0] = 1563.0;
  $gyldigeKommunenummer[286.0] = 1566.0;
  $gyldigeKommunenummer[287.0] = 1567.0;
  $gyldigeKommunenummer[288.0] = 1571.0;
  $gyldigeKommunenummer[289.0] = 1573.0;
  $gyldigeKommunenummer[290.0] = 1576.0;
  $gyldigeKommunenummer[291.0] = 1601.0;
  $gyldigeKommunenummer[292.0] = 1612.0;
  $gyldigeKommunenummer[293.0] = 1613.0;
  $gyldigeKommunenummer[294.0] = 1617.0;
  $gyldigeKommunenummer[295.0] = 1620.0;
  $gyldigeKommunenummer[296.0] = 1621.0;
  $gyldigeKommunenummer[297.0] = 1622.0;
  $gyldigeKommunenummer[298.0] = 1624.0;
  $gyldigeKommunenummer[299.0] = 1627.0;
  $gyldigeKommunenummer[300.0] = 1630.0;
  $gyldigeKommunenummer[301.0] = 1632.0;
  $gyldigeKommunenummer[302.0] = 1633.0;
  $gyldigeKommunenummer[303.0] = 1634.0;
  $gyldigeKommunenummer[304.0] = 1635.0;
  $gyldigeKommunenummer[305.0] = 1636.0;
  $gyldigeKommunenummer[306.0] = 1638.0;
  $gyldigeKommunenummer[307.0] = 1640.0;
  $gyldigeKommunenummer[308.0] = 1644.0;
  $gyldigeKommunenummer[309.0] = 1648.0;
  $gyldigeKommunenummer[310.0] = 1653.0;
  $gyldigeKommunenummer[311.0] = 1657.0;
  $gyldigeKommunenummer[312.0] = 1662.0;
  $gyldigeKommunenummer[313.0] = 1663.0;
  $gyldigeKommunenummer[314.0] = 1664.0;
  $gyldigeKommunenummer[315.0] = 1665.0;
  $gyldigeKommunenummer[316.0] = 1702.0;
  $gyldigeKommunenummer[317.0] = 1703.0;
  $gyldigeKommunenummer[318.0] = 1711.0;
  $gyldigeKommunenummer[319.0] = 1714.0;
  $gyldigeKommunenummer[320.0] = 1717.0;
  $gyldigeKommunenummer[321.0] = 1718.0;
  $gyldigeKommunenummer[322.0] = 1719.0;
  $gyldigeKommunenummer[323.0] = 1721.0;
  $gyldigeKommunenummer[324.0] = 1724.0;
  $gyldigeKommunenummer[325.0] = 1725.0;
  $gyldigeKommunenummer[326.0] = 1736.0;
  $gyldigeKommunenummer[327.0] = 1738.0;
  $gyldigeKommunenummer[328.0] = 1739.0;
  $gyldigeKommunenummer[329.0] = 1740.0;
  $gyldigeKommunenummer[330.0] = 1742.0;
  $gyldigeKommunenummer[331.0] = 1743.0;
  $gyldigeKommunenummer[332.0] = 1744.0;
  $gyldigeKommunenummer[333.0] = 1748.0;
  $gyldigeKommunenummer[334.0] = 1749.0;
  $gyldigeKommunenummer[335.0] = 1750.0;
  $gyldigeKommunenummer[336.0] = 1751.0;
  $gyldigeKommunenummer[337.0] = 1755.0;
  $gyldigeKommunenummer[338.0] = 1756.0;
  $gyldigeKommunenummer[339.0] = 1804.0;
  $gyldigeKommunenummer[340.0] = 1805.0;
  $gyldigeKommunenummer[341.0] = 1811.0;
  $gyldigeKommunenummer[342.0] = 1812.0;
  $gyldigeKommunenummer[343.0] = 1813.0;
  $gyldigeKommunenummer[344.0] = 1815.0;
  $gyldigeKommunenummer[345.0] = 1816.0;
  $gyldigeKommunenummer[346.0] = 1818.0;
  $gyldigeKommunenummer[347.0] = 1820.0;
  $gyldigeKommunenummer[348.0] = 1822.0;
  $gyldigeKommunenummer[349.0] = 1824.0;
  $gyldigeKommunenummer[350.0] = 1825.0;
  $gyldigeKommunenummer[351.0] = 1826.0;
  $gyldigeKommunenummer[352.0] = 1827.0;
  $gyldigeKommunenummer[353.0] = 1828.0;
  $gyldigeKommunenummer[354.0] = 1832.0;
  $gyldigeKommunenummer[355.0] = 1833.0;
  $gyldigeKommunenummer[356.0] = 1834.0;
  $gyldigeKommunenummer[357.0] = 1835.0;
  $gyldigeKommunenummer[358.0] = 1836.0;
  $gyldigeKommunenummer[359.0] = 1837.0;
  $gyldigeKommunenummer[360.0] = 1838.0;
  $gyldigeKommunenummer[361.0] = 1839.0;
  $gyldigeKommunenummer[362.0] = 1840.0;
  $gyldigeKommunenummer[363.0] = 1841.0;
  $gyldigeKommunenummer[364.0] = 1845.0;
  $gyldigeKommunenummer[365.0] = 1848.0;
  $gyldigeKommunenummer[366.0] = 1849.0;
  $gyldigeKommunenummer[367.0] = 1850.0;
  $gyldigeKommunenummer[368.0] = 1851.0;
  $gyldigeKommunenummer[369.0] = 1852.0;
  $gyldigeKommunenummer[370.0] = 1853.0;
  $gyldigeKommunenummer[371.0] = 1854.0;
  $gyldigeKommunenummer[372.0] = 1856.0;
  $gyldigeKommunenummer[373.0] = 1857.0;
  $gyldigeKommunenummer[374.0] = 1859.0;
  $gyldigeKommunenummer[375.0] = 1860.0;
  $gyldigeKommunenummer[376.0] = 1865.0;
  $gyldigeKommunenummer[377.0] = 1866.0;
  $gyldigeKommunenummer[378.0] = 1867.0;
  $gyldigeKommunenummer[379.0] = 1868.0;
  $gyldigeKommunenummer[380.0] = 1870.0;
  $gyldigeKommunenummer[381.0] = 1871.0;
  $gyldigeKommunenummer[382.0] = 1874.0;
  $gyldigeKommunenummer[383.0] = 1903.0;
  $gyldigeKommunenummer[384.0] = 1902.0;
  $gyldigeKommunenummer[385.0] = 1911.0;
  $gyldigeKommunenummer[386.0] = 1913.0;
  $gyldigeKommunenummer[387.0] = 1917.0;
  $gyldigeKommunenummer[388.0] = 1919.0;
  $gyldigeKommunenummer[389.0] = 1920.0;
  $gyldigeKommunenummer[390.0] = 1922.0;
  $gyldigeKommunenummer[391.0] = 1923.0;
  $gyldigeKommunenummer[392.0] = 1924.0;
  $gyldigeKommunenummer[393.0] = 1925.0;
  $gyldigeKommunenummer[394.0] = 1926.0;
  $gyldigeKommunenummer[395.0] = 1927.0;
  $gyldigeKommunenummer[396.0] = 1928.0;
  $gyldigeKommunenummer[397.0] = 1929.0;
  $gyldigeKommunenummer[398.0] = 1931.0;
  $gyldigeKommunenummer[399.0] = 1933.0;
  $gyldigeKommunenummer[400.0] = 1936.0;
  $gyldigeKommunenummer[401.0] = 1938.0;
  $gyldigeKommunenummer[402.0] = 1939.0;
  $gyldigeKommunenummer[403.0] = 1940.0;
  $gyldigeKommunenummer[404.0] = 1941.0;
  $gyldigeKommunenummer[405.0] = 1942.0;
  $gyldigeKommunenummer[406.0] = 1943.0;
  $gyldigeKommunenummer[407.0] = 2002.0;
  $gyldigeKommunenummer[408.0] = 2003.0;
  $gyldigeKommunenummer[409.0] = 2004.0;
  $gyldigeKommunenummer[410.0] = 2011.0;
  $gyldigeKommunenummer[411.0] = 2012.0;
  $gyldigeKommunenummer[412.0] = 2014.0;
  $gyldigeKommunenummer[413.0] = 2015.0;
  $gyldigeKommunenummer[414.0] = 2017.0;
  $gyldigeKommunenummer[415.0] = 2018.0;
  $gyldigeKommunenummer[416.0] = 2019.0;
  $gyldigeKommunenummer[417.0] = 2020.0;
  $gyldigeKommunenummer[418.0] = 2021.0;
  $gyldigeKommunenummer[419.0] = 2022.0;
  $gyldigeKommunenummer[420.0] = 2023.0;
  $gyldigeKommunenummer[421.0] = 2024.0;
  $gyldigeKommunenummer[422.0] = 2025.0;
  $gyldigeKommunenummer[423.0] = 2027.0;
  $gyldigeKommunenummer[424.0] = 2028.0;
  $gyldigeKommunenummer[425.0] = 2030.0;

  return $gyldigeKommunenummer;
}
function test1(){
  $doubleReference = new stdClass();
  $doubleReference->doubleValue = 0.0;

  $success = new stdClass();
  $kommuenavn = hentKommunenavnFraNummer(str_split("1640"), $success);
  assertStringEquals($kommuenavn, str_split("R\u00f8ros"), $doubleReference);
  assertTrue($success->success, $doubleReference);

  return $doubleReference->doubleValue;
}
function test(){
  $failures = 0.0;

  $failures = $failures + test1();

  return $failures;
}
function &decimalToString($decimal){
  return numberToString($decimal, 10.0);
}
function &numberToString($decimal, $base){
  $string = array_fill(0, 0.0, 0);

  $digits = getDigits($base);

  /* Find digitPosition: */
  $digitPosition = getDigitPosition($decimal, $base);

  $decimal = round($decimal*pow($base, -$digitPosition + $digits - 1.0));

  $hasPrintedPoint = false;

  /* Print leading zeros. */
  if($digitPosition < 0.0){
    $string = appendCharacter($string, "0");
    $string = appendCharacter($string, ".");
    $hasPrintedPoint = true;
    for($i = 0.0; $i < -$digitPosition - 1.0; $i = $i + 1.0){
      $string = appendCharacter($string, "0");
    }
  }

  /* Print number. */
  for($i = 0.0; $i < $digits; $i = $i + 1.0){
    $d = floor($decimal/pow($base, $digits - $i - 1.0));
    if( !$hasPrintedPoint  && $digitPosition - $i + 1.0 == 0.0){
      if($decimal != 0.0){
        $string = appendCharacter($string, ".");
      }
      $hasPrintedPoint = true;
    }
    if($decimal == 0.0 && $hasPrintedPoint){
    }else{
      $string = appendCharacter($string, getSingleDigitFromNumber($d, $base));
    }
    $decimal = $decimal - $d*pow($base, $digits - $i - 1.0);
  }

  /* Print trailing zeros. */
  for($i = 0.0; $i < $digitPosition - $digits + 1.0; $i = $i + 1.0){
    $string = appendCharacter($string, "0");
  }

  /* Done */
  return $string;
}
function getDigits($base){
  $t = pow(10.0, 15.0);
  return floor(log10($t)/log10($base));
}
function getDigitPosition($decimal, $base){
  $power = ceil(log10($decimal)/log10($base));

  $t = $decimal*pow($base, -$power);
  if($t < $base && $t >= 1.0){
  }else if($t >= $base){
    $power = $power + 1.0;
  }else if($t < 1.0){
    $power = $power - 1.0;
  }


  return $power;
}
function getSingleDigitFromNumber($c, $base){
  $numberTable = getNumberTable();

  if($c > $base - 1.0){
    $retc = "?";
  }else{
    $retc = $numberTable[$c];
  }

  return $retc;
}
function &getNumberTable(){
  $numberTable = array_fill(0, 16.0, 0);
  $numberTable[0.0] = "0";
  $numberTable[1.0] = "1";
  $numberTable[2.0] = "2";
  $numberTable[3.0] = "3";
  $numberTable[4.0] = "4";
  $numberTable[5.0] = "5";
  $numberTable[6.0] = "6";
  $numberTable[7.0] = "7";
  $numberTable[8.0] = "8";
  $numberTable[9.0] = "9";
  $numberTable[10.0] = "A";
  $numberTable[11.0] = "B";
  $numberTable[12.0] = "C";
  $numberTable[13.0] = "D";
  $numberTable[14.0] = "E";
  $numberTable[15.0] = "F";
  return $numberTable;
}
function stringToDecimal(&$string){
  return stringToDecimalForBase($string, 10.0);
}
function stringToDecimalForBase(&$string, $base){
  $stringToDecimalResult = new stdClass();
  $stringToDecimalResult->success = true;
  $i = 0.0;
  $isPositive = true;
  $beforeDecimalPoint = 0.0;
  $afterDecimalPoint = 0.0;
  $n = 0.0;
  $validCharacters = 0.0;

  if($base >= 2.0 && $base <= 16.0){
    for($j = 0.0; $j < count($string); $j = $j + 1.0){
      $c = $string[$j];
      if(isNumber($c, $base) || $c == "." || $c == "-"){
        $validCharacters = $validCharacters + 1.0;
      }
    }
    if($validCharacters == count($string)){
      if(count($string) > 0.0){
        $c = $string[$i];
        if($c == "-"){
          $isPositive = false;
          $i = $i + 1.0;
        }
        if($i < count($string)){
          $c = $string[$i];
          if(isNumber($c, $base)){
            for(; isNumber($c, $base) && ($i < count($string)); ){
              $beforeDecimalPoint = $beforeDecimalPoint + 1.0;
              $i = $i + 1.0;
              if($i < count($string)){
                $c = $string[$i];
              }
            }
            if($i < count($string)){
              $c = $string[$i];
              if($c == "."){
                $i = $i + 1.0;
                if($i < count($string)){
                  $c = $string[$i];
                  for(; isNumber($c, $base) && ($i < count($string)); ){
                    $afterDecimalPoint = $afterDecimalPoint + 1.0;
                    $i = $i + 1.0;
                    if($i < count($string)){
                      $c = $string[$i];
                    }
                  }
                }else{
                  $stringToDecimalResult->success = false;
                  $stringToDecimalResult->feilmelding = str_split("Number must have digits after the decimal point.");
                }
              }
            }
          }else{
            $stringToDecimalResult->success = false;
            $stringToDecimalResult->feilmelding = str_split("Number must start with digits (for negative numbers, after the optional negative sign).");
          }
        }
        if($stringToDecimalResult->success != false){
          $i = 0.0;
          if( !$isPositive ){
            $i = 1.0;
          }
          for($j = 0.0; $j < $beforeDecimalPoint; $j = $j + 1.0){
            $c = $string[$i];
            $i = $i + 1.0;
            $d = getDecimalFromSingleDecimalDigit($c, $base);
            $n = $n + $d*pow($base, $beforeDecimalPoint - $j - 1.0);
          }
          if($afterDecimalPoint > 0.0){
            $i = $i + 1.0;
            for($j = 0.0; $j < $afterDecimalPoint; $j = $j + 1.0){
              $c = $string[$i];
              $i = $i + 1.0;
              $d = getDecimalFromSingleDecimalDigit($c, $base);
              $n = $n + $d*pow($base, 0.0 - $j - 1.0);
            }
          }
          if( !$isPositive ){
            $n = -$n;
          }
          $stringToDecimalResult->result = $n;
          $stringToDecimalResult->success = true;
        }
      }else{
        $stringToDecimalResult->success = false;
        $stringToDecimalResult->feilmelding = str_split("String has no content.");
      }
    }else{
      $stringToDecimalResult->success = false;
      $stringToDecimalResult->feilmelding = str_split("String contains invalid character.");
    }
  }else{
    $stringToDecimalResult->success = false;
    $stringToDecimalResult->feilmelding = str_split("Base must be from 2 to 16.");
  }

  return $stringToDecimalResult;
}
function getDecimalFromSingleDecimalDigit($c, $base){
  $numberTable = getNumberTable();
  $position = 0.0;

  for($i = 0.0; $i < $base; $i = $i + 1.0){
    if($numberTable[$i] == $c){
      $position = $i;
    }
  }

  return $position;
}
function isNumber($c, $base){
  $numberTable = getNumberTable();
  $found = false;

  for($i = 0.0; $i < $base; $i = $i + 1.0){
    if($numberTable[$i] == $c){
      $found = true;
    }
  }

  return $found;
}
function assertFalse($b, $failures){
  if($b){
    $failures->doubleValue = $failures->doubleValue + 1.0;
  }
}
function assertTrue($b, $failures){
  if( !$b ){
    $failures->doubleValue = $failures->doubleValue + 1.0;
  }
}
function assertEquals($a, $b, $failures){
  if($a != $b){
    $failures->doubleValue = $failures->doubleValue + 1.0;
  }
}
function assertStringEquals(&$a, &$b, $failures){
  if( !stringsEqual($a, $b) ){
    $failures->doubleValue = $failures->doubleValue + 1.0;
  }
}
function &stringToNumberArray(&$string){
  $array = array_fill(0, count($string), 0);

  for($i = 0.0; $i < count($string); $i = $i + 1.0){
    $array[$i] = ord($string[$i]);
  }
  return $array;
}
function &numberArrayToString(&$array){
  $string = array_fill(0, count($array), 0);

  for($i = 0.0; $i < count($array); $i = $i + 1.0){
    $string[$i] = chr($array[$i]);
  }
  return $string;
}
function stringsEqual(&$data1, &$data2){
  $equal = false;
  if(count($data1) == count($data2)){
    $nrEqual = 0.0;
    for($i = 0.0; $i < count($data1); $i = $i + 1.0){
      if($data1[$i] == $data2[$i]){
        $nrEqual = $nrEqual + 1.0;
      }
    }
    if($nrEqual == count($data1)){
      $equal = true;
    }
  }else{
    $equal = false;
  }

  return $equal;
}
function numberArraysEqual(&$data1, &$data2){
  $equal = false;
  if(count($data1) == count($data2)){
    $nrEqual = 0.0;
    for($i = 0.0; $i < count($data1); $i = $i + 1.0){
      if($data1[$i] == $data2[$i]){
        $nrEqual = $nrEqual + 1.0;
      }
    }
    if($nrEqual == count($data1)){
      $equal = true;
    }
  }else{
    $equal = false;
  }

  return $equal;
}
function &substring(&$string, $from, $to){
  $n = array_fill(0, $to - $from, 0);

  for($i = $from; $i < $to; $i = $i + 1.0){
    $n[$i - $from] = $string[$i];
  }

  return $n;
}
function &appendString(&$string, &$s){
  $newString = array_fill(0, count($string) + count($s), 0);

  for($i = 0.0; $i < count($string); $i = $i + 1.0){
    $newString[$i] = $string[$i];
  }

  for($i = 0.0; $i < count($s); $i = $i + 1.0){
    $newString[count($string) + $i] = $s[$i];
  }

  unset($string);

  return $newString;
}
function &appendCharacter(&$string, $c){
  $newString = array_fill(0, count($string) + 1.0, 0);

  for($i = 0.0; $i < count($string); $i = $i + 1.0){
    $newString[$i] = $string[$i];
  }

  $newString[count($string)] = $c;

  unset($string);

  return $newString;
}
function &split(&$toSplit, $splitBy){
  $splitt = array_fill(0, 0.0, 0);

  $next = array_fill(0, 0.0, 0);
  for($i = 0.0; $i < count($toSplit); $i = $i + 1.0){
    $c = $toSplit[$i];
    if($c == $splitBy){
      $n = new stdClass();
      $n->string = $next;
      $splitt = addString($splitt, $n);
      $next = array_fill(0, 0.0, 0);
    }else{
      $next = appendCharacter($next, $c);
    }
  }

  if(count($next) > 0.0){
    $n = new stdClass();
    $n->string = $next;
    $splitt = addString($splitt, $n);
  }

  return $splitt;
}
function &addDecimal(&$list, $a){
  $newlist = array_fill(0, count($list) + 1.0, 0);
  for($i = 0.0; $i < count($list); $i = $i + 1.0){
    $newlist[$i] = $list[$i];
  }
  $newlist[count($list)] = $a;
		
  unset($list);
		
  return $newlist;
}
function addDecimalRef($list, $i){
  $list->list = addDecimal($list->list, $i);
}
function &removeDecimal(&$list, $n){
  $newlist = array_fill(0, count($list) - 1.0, 0);

  for($i = 0.0; $i < count($list); $i = $i + 1.0){
    if($i < $n){
      $newlist[$i] = $list[$i];
    }
    if($i > $n){
      $newlist[$i - 1.0] = $list[$i];
    }
  }
		
  unset($list);
		
  return $newlist;
}
function getDecimalRef($list, $i){
  return $list->list[$i];
}
function removeDecimalRef($list, $i){
  $list->list = removeDecimal($list->list, $i);
}
function &addString(&$list, $a){
  $newlist = array_fill(0, count($list) + 1.0, 0);

  for($i = 0.0; $i < count($list); $i = $i + 1.0){
    $newlist[$i] = $list[$i];
  }
  $newlist[count($list)] = $a;
		
  unset($list);
		
  return $newlist;
}
function addStringRef($list, $i){
  $list->list = addString($list->list, $i);
}
function &removeString(&$list, $n){
  $newlist = array_fill(0, count($list) - 1.0, 0);

  for($i = 0.0; $i < count($list); $i = $i + 1.0){
    if($i < $n){
      $newlist[$i] = $list[$i];
    }
    if($i > $n){
      $newlist[$i - 1.0] = $list[$i];
    }
  }
		
  unset($list);
		
  return $newlist;
}
function getStringRef($list, $i){
  return $list->list[$i];
}
function removeStringRef($list, $i){
  $list->list = removeString($list->list, $i);
}


echo test();