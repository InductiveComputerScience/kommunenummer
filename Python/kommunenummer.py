from math import *
class Success:
  success = None
  feilmelding = None

def createStringReference(string):
  stringReference = StringReference()
  stringReference.string = string
  return stringReference

def lagGyldigReversTabell(nummerliste):
  maxnummer = 0.0
  i = 0.0
  while i < len(nummerliste):
    maxnummer = max(maxnummer,nummerliste[int(i)])
    i = i + 1.0
  

  inverse =  [None]*int(maxnummer + 1.0)

  i = 0.0
  while i < maxnummer:
    inverse[int(i)] = False
    i = i + 1.0
  

  i = 0.0
  while i < len(nummerliste):
    inverse[int(nummerliste[int(i)])] = True
    i = i + 1.0
  

  return inverse

def hentKommunenavnFraNummer(kommunenummer, success):
  kommunenavn =  [None]*int(0.0)

  if erGyldigKommunenummer(kommunenummer):
    kommunenavnListe = hentKommunenavn()
    stringToDecimalResult = stringToDecimalForBase(kommunenummer, 10.0)
    if stringToDecimalResult.success:
      nr = stringToDecimalResult.result
      kommunenavn = kommunenavnListe[int(nr)].string
      success.success = True
    else:
      success.feilmelding = "Kommunenummer var ikke et gyldig tall."
      success.success = False
  else:
    success.success = False
    success.feilmelding = "Kommunenummer er ikke gyldig."

  return kommunenavn

def erGyldigKommunenummer(kommunenummer):
  if len(kommunenummer) == 4.0:
    nr = stringToDecimalForBase(kommunenummer, 10.0).result
    if nr >= 101.0 and nr <= 2030.0 and erHelttall(nr):
      gyldigKommunetabell = hentGyldigKommunetabell()
      gyldig = gyldigKommunetabell[int(nr)]
    else:
      gyldig = False
  else:
    gyldig = False

  return gyldig

def erHelttall(nr):
  return (nr % 1.0) == 0.0

def hentGyldigKommunetabell():
  nummerliste = hentGyldigeKommunenummer()
  return lagGyldigReversTabell(nummerliste)

def hentKommunenavn():
  kommunenavn =  [None]*int(2100.0)

  kommunenavn[int(101.0)] = createStringReference("Halden")
  kommunenavn[int(104.0)] = createStringReference("Moss")
  kommunenavn[int(105.0)] = createStringReference("Sarpsborg")
  kommunenavn[int(106.0)] = createStringReference("Fredrikstad")
  kommunenavn[int(111.0)] = createStringReference("Hvaler")
  kommunenavn[int(118.0)] = createStringReference("Aremark")
  kommunenavn[int(119.0)] = createStringReference("Marker")
  kommunenavn[int(121.0)] = createStringReference("R\u00f8mskog")
  kommunenavn[int(122.0)] = createStringReference("Tr\u00f8gstad")
  kommunenavn[int(123.0)] = createStringReference("Spydeberg")
  kommunenavn[int(124.0)] = createStringReference("Askim")
  kommunenavn[int(125.0)] = createStringReference("Eidsberg")
  kommunenavn[int(127.0)] = createStringReference("Skiptvet")
  kommunenavn[int(128.0)] = createStringReference("Rakkestad")
  kommunenavn[int(135.0)] = createStringReference("R\u00e5de")
  kommunenavn[int(136.0)] = createStringReference("Rygge")
  kommunenavn[int(137.0)] = createStringReference("V\u00e5ler")
  kommunenavn[int(138.0)] = createStringReference("Hob\u00f8l")
  kommunenavn[int(211.0)] = createStringReference("Vestby")
  kommunenavn[int(213.0)] = createStringReference("Ski")
  kommunenavn[int(214.0)] = createStringReference("\u00c5s")
  kommunenavn[int(215.0)] = createStringReference("Frogn")
  kommunenavn[int(216.0)] = createStringReference("Nesodden")
  kommunenavn[int(217.0)] = createStringReference("Oppeg\u00e5rd")
  kommunenavn[int(219.0)] = createStringReference("B\u00e6rum")
  kommunenavn[int(220.0)] = createStringReference("Asker")
  kommunenavn[int(221.0)] = createStringReference("Aurskog-H\u00f8land")
  kommunenavn[int(226.0)] = createStringReference("S\u00f8rum")
  kommunenavn[int(227.0)] = createStringReference("Fet")
  kommunenavn[int(228.0)] = createStringReference("R\u00e6lingen")
  kommunenavn[int(229.0)] = createStringReference("Enebakk")
  kommunenavn[int(230.0)] = createStringReference("L\u00f8renskog")
  kommunenavn[int(231.0)] = createStringReference("Skedsmo")
  kommunenavn[int(233.0)] = createStringReference("Nittedal")
  kommunenavn[int(234.0)] = createStringReference("Gjerdrum")
  kommunenavn[int(235.0)] = createStringReference("Ullensaker")
  kommunenavn[int(236.0)] = createStringReference("Nes")
  kommunenavn[int(237.0)] = createStringReference("Eidsvoll")
  kommunenavn[int(238.0)] = createStringReference("Nannestad")
  kommunenavn[int(239.0)] = createStringReference("Hurdal")
  kommunenavn[int(301.0)] = createStringReference("Oslo")
  kommunenavn[int(402.0)] = createStringReference("Kongsvinger")
  kommunenavn[int(403.0)] = createStringReference("Hamar")
  kommunenavn[int(412.0)] = createStringReference("Ringsaker")
  kommunenavn[int(415.0)] = createStringReference("L\u00f8ten")
  kommunenavn[int(417.0)] = createStringReference("Stange")
  kommunenavn[int(418.0)] = createStringReference("Nord-Odal")
  kommunenavn[int(419.0)] = createStringReference("S\u00f8r-Odal")
  kommunenavn[int(420.0)] = createStringReference("Eidskog")
  kommunenavn[int(423.0)] = createStringReference("Grue")
  kommunenavn[int(425.0)] = createStringReference("\u00c5snes")
  kommunenavn[int(426.0)] = createStringReference("V\u00e5ler")
  kommunenavn[int(427.0)] = createStringReference("Elverum")
  kommunenavn[int(428.0)] = createStringReference("Trysil")
  kommunenavn[int(429.0)] = createStringReference("\u00c5mot")
  kommunenavn[int(430.0)] = createStringReference("Stor-Elvdal")
  kommunenavn[int(432.0)] = createStringReference("Rendalen")
  kommunenavn[int(434.0)] = createStringReference("Engerdal")
  kommunenavn[int(436.0)] = createStringReference("Tolga")
  kommunenavn[int(437.0)] = createStringReference("Tynset")
  kommunenavn[int(438.0)] = createStringReference("Alvdal")
  kommunenavn[int(439.0)] = createStringReference("Folldal")
  kommunenavn[int(441.0)] = createStringReference("Os")
  kommunenavn[int(501.0)] = createStringReference("Lillehammer")
  kommunenavn[int(502.0)] = createStringReference("Gj\u00f8vik")
  kommunenavn[int(511.0)] = createStringReference("Dovre")
  kommunenavn[int(512.0)] = createStringReference("Lesja")
  kommunenavn[int(513.0)] = createStringReference("Skj\u00e5k")
  kommunenavn[int(514.0)] = createStringReference("Lom")
  kommunenavn[int(515.0)] = createStringReference("V\u00e5g\u00e5")
  kommunenavn[int(516.0)] = createStringReference("Nord-Fron")
  kommunenavn[int(517.0)] = createStringReference("Sel")
  kommunenavn[int(519.0)] = createStringReference("S\u00f8r-Fron")
  kommunenavn[int(520.0)] = createStringReference("Ringebu")
  kommunenavn[int(521.0)] = createStringReference("\u00d8yer")
  kommunenavn[int(522.0)] = createStringReference("Gausdal")
  kommunenavn[int(528.0)] = createStringReference("\u00d8stre Toten")
  kommunenavn[int(529.0)] = createStringReference("Vestre Toten")
  kommunenavn[int(532.0)] = createStringReference("Jevnaker")
  kommunenavn[int(533.0)] = createStringReference("Lunner")
  kommunenavn[int(534.0)] = createStringReference("Gran")
  kommunenavn[int(536.0)] = createStringReference("S\u00f8ndre Land")
  kommunenavn[int(538.0)] = createStringReference("Nordre Land")
  kommunenavn[int(540.0)] = createStringReference("S\u00f8r-Aurdal")
  kommunenavn[int(541.0)] = createStringReference("Etnedal")
  kommunenavn[int(542.0)] = createStringReference("Nord-Aurdal")
  kommunenavn[int(543.0)] = createStringReference("Vestre Slidre")
  kommunenavn[int(544.0)] = createStringReference("\u00d8ystre Slidre")
  kommunenavn[int(545.0)] = createStringReference("Vang")
  kommunenavn[int(602.0)] = createStringReference("Drammen")
  kommunenavn[int(604.0)] = createStringReference("Kongsberg")
  kommunenavn[int(605.0)] = createStringReference("Ringerike")
  kommunenavn[int(612.0)] = createStringReference("Hole")
  kommunenavn[int(615.0)] = createStringReference("Fl\u00e5")
  kommunenavn[int(616.0)] = createStringReference("Nes")
  kommunenavn[int(617.0)] = createStringReference("Gol")
  kommunenavn[int(618.0)] = createStringReference("Hemsedal")
  kommunenavn[int(619.0)] = createStringReference("\u00c5l")
  kommunenavn[int(620.0)] = createStringReference("Hol")
  kommunenavn[int(621.0)] = createStringReference("Sigdal")
  kommunenavn[int(622.0)] = createStringReference("Kr\u00f8dsherad")
  kommunenavn[int(623.0)] = createStringReference("Modum")
  kommunenavn[int(624.0)] = createStringReference("\u00d8vre Eiker")
  kommunenavn[int(625.0)] = createStringReference("Nedre Eiker")
  kommunenavn[int(626.0)] = createStringReference("Lier")
  kommunenavn[int(627.0)] = createStringReference("R\u00f8yken")
  kommunenavn[int(628.0)] = createStringReference("Hurum")
  kommunenavn[int(631.0)] = createStringReference("Flesberg")
  kommunenavn[int(632.0)] = createStringReference("Rollag")
  kommunenavn[int(633.0)] = createStringReference("Nore og Uvdal")
  kommunenavn[int(701.0)] = createStringReference("Horten")
  kommunenavn[int(702.0)] = createStringReference("Holmestrand")
  kommunenavn[int(704.0)] = createStringReference("T\u00f8nsberg")
  kommunenavn[int(709.0)] = createStringReference("Larvik")
  kommunenavn[int(710.0)] = createStringReference("Sandefjord")
  kommunenavn[int(711.0)] = createStringReference("Svelvik")
  kommunenavn[int(713.0)] = createStringReference("Sande")
  kommunenavn[int(714.0)] = createStringReference("Hof")
  kommunenavn[int(716.0)] = createStringReference("Re")
  kommunenavn[int(722.0)] = createStringReference("N\u00f8tter\u00f8y")
  kommunenavn[int(723.0)] = createStringReference("Tj\u00f8me")
  kommunenavn[int(728.0)] = createStringReference("Lardal")
  kommunenavn[int(805.0)] = createStringReference("Porsgrunn")
  kommunenavn[int(806.0)] = createStringReference("Skien")
  kommunenavn[int(807.0)] = createStringReference("Notodden")
  kommunenavn[int(811.0)] = createStringReference("Siljan")
  kommunenavn[int(814.0)] = createStringReference("Bamble")
  kommunenavn[int(815.0)] = createStringReference("Krager\u00f8")
  kommunenavn[int(817.0)] = createStringReference("Drangedal")
  kommunenavn[int(819.0)] = createStringReference("Nome")
  kommunenavn[int(821.0)] = createStringReference("B\u00f8")
  kommunenavn[int(822.0)] = createStringReference("Sauherad")
  kommunenavn[int(826.0)] = createStringReference("Tinn")
  kommunenavn[int(827.0)] = createStringReference("Hjartdal")
  kommunenavn[int(828.0)] = createStringReference("Seljord")
  kommunenavn[int(829.0)] = createStringReference("Kviteseid")
  kommunenavn[int(830.0)] = createStringReference("Nissedal")
  kommunenavn[int(831.0)] = createStringReference("Fyresdal")
  kommunenavn[int(833.0)] = createStringReference("Tokke")
  kommunenavn[int(834.0)] = createStringReference("Vinje")
  kommunenavn[int(901.0)] = createStringReference("Ris\u00f8r")
  kommunenavn[int(904.0)] = createStringReference("Grimstad")
  kommunenavn[int(906.0)] = createStringReference("Arendal")
  kommunenavn[int(911.0)] = createStringReference("Gjerstad")
  kommunenavn[int(912.0)] = createStringReference("Veg\u00e5rshei")
  kommunenavn[int(914.0)] = createStringReference("Tvedestrand")
  kommunenavn[int(919.0)] = createStringReference("Froland")
  kommunenavn[int(926.0)] = createStringReference("Lillesand")
  kommunenavn[int(928.0)] = createStringReference("Birkenes")
  kommunenavn[int(929.0)] = createStringReference("\u00c5mli")
  kommunenavn[int(935.0)] = createStringReference("Iveland")
  kommunenavn[int(937.0)] = createStringReference("Evje og Hornnes")
  kommunenavn[int(938.0)] = createStringReference("Bygland")
  kommunenavn[int(940.0)] = createStringReference("Valle")
  kommunenavn[int(941.0)] = createStringReference("Bykle")
  kommunenavn[int(1001.0)] = createStringReference("Kristiansand")
  kommunenavn[int(1002.0)] = createStringReference("Mandal")
  kommunenavn[int(1003.0)] = createStringReference("Farsund")
  kommunenavn[int(1004.0)] = createStringReference("Flekkefjord")
  kommunenavn[int(1014.0)] = createStringReference("Vennesla")
  kommunenavn[int(1017.0)] = createStringReference("Songdalen")
  kommunenavn[int(1018.0)] = createStringReference("S\u00f8gne")
  kommunenavn[int(1021.0)] = createStringReference("Marnardal")
  kommunenavn[int(1026.0)] = createStringReference("\u00c5seral")
  kommunenavn[int(1027.0)] = createStringReference("Audnedal")
  kommunenavn[int(1029.0)] = createStringReference("Lindesnes")
  kommunenavn[int(1032.0)] = createStringReference("Lyngdal")
  kommunenavn[int(1034.0)] = createStringReference("H\u00e6gebostad")
  kommunenavn[int(1037.0)] = createStringReference("Kvinesdal")
  kommunenavn[int(1046.0)] = createStringReference("Sirdal")
  kommunenavn[int(1101.0)] = createStringReference("Eigersund")
  kommunenavn[int(1102.0)] = createStringReference("Sandnes")
  kommunenavn[int(1103.0)] = createStringReference("Stavanger")
  kommunenavn[int(1106.0)] = createStringReference("Haugesund")
  kommunenavn[int(1111.0)] = createStringReference("Sokndal")
  kommunenavn[int(1112.0)] = createStringReference("Lund")
  kommunenavn[int(1114.0)] = createStringReference("Bjerkreim")
  kommunenavn[int(1119.0)] = createStringReference("H\u00e5")
  kommunenavn[int(1120.0)] = createStringReference("Klepp")
  kommunenavn[int(1121.0)] = createStringReference("Time")
  kommunenavn[int(1122.0)] = createStringReference("Gjesdal")
  kommunenavn[int(1124.0)] = createStringReference("Sola")
  kommunenavn[int(1127.0)] = createStringReference("Randaberg")
  kommunenavn[int(1129.0)] = createStringReference("Forsand")
  kommunenavn[int(1130.0)] = createStringReference("Strand")
  kommunenavn[int(1133.0)] = createStringReference("Hjelmeland")
  kommunenavn[int(1134.0)] = createStringReference("Suldal")
  kommunenavn[int(1135.0)] = createStringReference("Sauda")
  kommunenavn[int(1141.0)] = createStringReference("Finn\u00f8y")
  kommunenavn[int(1142.0)] = createStringReference("Rennes\u00f8y")
  kommunenavn[int(1144.0)] = createStringReference("Kvits\u00f8y")
  kommunenavn[int(1145.0)] = createStringReference("Bokn")
  kommunenavn[int(1146.0)] = createStringReference("Tysv\u00e6r")
  kommunenavn[int(1149.0)] = createStringReference("Karm\u00f8y")
  kommunenavn[int(1151.0)] = createStringReference("Utsira")
  kommunenavn[int(1160.0)] = createStringReference("Vindafjord")
  kommunenavn[int(1201.0)] = createStringReference("Bergen")
  kommunenavn[int(1211.0)] = createStringReference("Etne")
  kommunenavn[int(1216.0)] = createStringReference("Sveio")
  kommunenavn[int(1219.0)] = createStringReference("B\u00f8mlo")
  kommunenavn[int(1221.0)] = createStringReference("Stord")
  kommunenavn[int(1222.0)] = createStringReference("Fitjar")
  kommunenavn[int(1223.0)] = createStringReference("Tysnes")
  kommunenavn[int(1224.0)] = createStringReference("Kvinnherad")
  kommunenavn[int(1227.0)] = createStringReference("Jondal")
  kommunenavn[int(1228.0)] = createStringReference("Odda")
  kommunenavn[int(1231.0)] = createStringReference("Ullensvang")
  kommunenavn[int(1232.0)] = createStringReference("Eidfjord")
  kommunenavn[int(1233.0)] = createStringReference("Ulvik")
  kommunenavn[int(1234.0)] = createStringReference("Granvin")
  kommunenavn[int(1235.0)] = createStringReference("Voss")
  kommunenavn[int(1238.0)] = createStringReference("Kvam")
  kommunenavn[int(1241.0)] = createStringReference("Fusa")
  kommunenavn[int(1242.0)] = createStringReference("Samnanger")
  kommunenavn[int(1243.0)] = createStringReference("Os")
  kommunenavn[int(1244.0)] = createStringReference("Austevoll")
  kommunenavn[int(1245.0)] = createStringReference("Sund")
  kommunenavn[int(1246.0)] = createStringReference("Fjell")
  kommunenavn[int(1247.0)] = createStringReference("Ask\u00f8y")
  kommunenavn[int(1251.0)] = createStringReference("Vaksdal")
  kommunenavn[int(1252.0)] = createStringReference("Modalen")
  kommunenavn[int(1253.0)] = createStringReference("Oster\u00f8y")
  kommunenavn[int(1256.0)] = createStringReference("Meland")
  kommunenavn[int(1259.0)] = createStringReference("\u00d8ygarden")
  kommunenavn[int(1260.0)] = createStringReference("Rad\u00f8y")
  kommunenavn[int(1263.0)] = createStringReference("Lind\u00e5s")
  kommunenavn[int(1264.0)] = createStringReference("Austrheim")
  kommunenavn[int(1265.0)] = createStringReference("Fedje")
  kommunenavn[int(1266.0)] = createStringReference("Masfjorden")
  kommunenavn[int(1401.0)] = createStringReference("Flora")
  kommunenavn[int(1411.0)] = createStringReference("Gulen")
  kommunenavn[int(1412.0)] = createStringReference("Solund")
  kommunenavn[int(1413.0)] = createStringReference("Hyllestad")
  kommunenavn[int(1416.0)] = createStringReference("H\u00f8yanger")
  kommunenavn[int(1417.0)] = createStringReference("Vik")
  kommunenavn[int(1418.0)] = createStringReference("Balestrand")
  kommunenavn[int(1419.0)] = createStringReference("Leikanger")
  kommunenavn[int(1420.0)] = createStringReference("Sogndal")
  kommunenavn[int(1421.0)] = createStringReference("Aurland")
  kommunenavn[int(1422.0)] = createStringReference("L\u00e6rdal")
  kommunenavn[int(1424.0)] = createStringReference("\u00c5rdal")
  kommunenavn[int(1426.0)] = createStringReference("Luster")
  kommunenavn[int(1428.0)] = createStringReference("Askvoll")
  kommunenavn[int(1429.0)] = createStringReference("Fjaler")
  kommunenavn[int(1430.0)] = createStringReference("Gaular")
  kommunenavn[int(1431.0)] = createStringReference("J\u00f8lster")
  kommunenavn[int(1432.0)] = createStringReference("F\u00f8rde")
  kommunenavn[int(1433.0)] = createStringReference("Naustdal")
  kommunenavn[int(1438.0)] = createStringReference("Bremanger")
  kommunenavn[int(1439.0)] = createStringReference("V\u00e5gs\u00f8y")
  kommunenavn[int(1441.0)] = createStringReference("Selje")
  kommunenavn[int(1443.0)] = createStringReference("Eid")
  kommunenavn[int(1444.0)] = createStringReference("Hornindal")
  kommunenavn[int(1445.0)] = createStringReference("Gloppen")
  kommunenavn[int(1449.0)] = createStringReference("Stryn")
  kommunenavn[int(1502.0)] = createStringReference("Molde")
  kommunenavn[int(1504.0)] = createStringReference("\u00c5lesund")
  kommunenavn[int(1505.0)] = createStringReference("Kristiansund")
  kommunenavn[int(1511.0)] = createStringReference("Vanylven")
  kommunenavn[int(1514.0)] = createStringReference("Sande")
  kommunenavn[int(1515.0)] = createStringReference("Her\u00f8y")
  kommunenavn[int(1516.0)] = createStringReference("Ulstein")
  kommunenavn[int(1517.0)] = createStringReference("Hareid")
  kommunenavn[int(1519.0)] = createStringReference("Volda")
  kommunenavn[int(1520.0)] = createStringReference("\u00d8rsta")
  kommunenavn[int(1523.0)] = createStringReference("\u00d8rskog")
  kommunenavn[int(1524.0)] = createStringReference("Norddal")
  kommunenavn[int(1525.0)] = createStringReference("Stranda")
  kommunenavn[int(1526.0)] = createStringReference("Stordal")
  kommunenavn[int(1528.0)] = createStringReference("Sykkylven")
  kommunenavn[int(1529.0)] = createStringReference("Skodje")
  kommunenavn[int(1531.0)] = createStringReference("Sula")
  kommunenavn[int(1532.0)] = createStringReference("Giske")
  kommunenavn[int(1534.0)] = createStringReference("Haram")
  kommunenavn[int(1535.0)] = createStringReference("Vestnes")
  kommunenavn[int(1539.0)] = createStringReference("Rauma")
  kommunenavn[int(1543.0)] = createStringReference("Nesset")
  kommunenavn[int(1545.0)] = createStringReference("Midsund")
  kommunenavn[int(1546.0)] = createStringReference("Sand\u00f8y")
  kommunenavn[int(1547.0)] = createStringReference("Aukra")
  kommunenavn[int(1548.0)] = createStringReference("Fr\u00e6na")
  kommunenavn[int(1551.0)] = createStringReference("Eide")
  kommunenavn[int(1554.0)] = createStringReference("Aver\u00f8y")
  kommunenavn[int(1557.0)] = createStringReference("Gjemnes")
  kommunenavn[int(1560.0)] = createStringReference("Tingvoll")
  kommunenavn[int(1563.0)] = createStringReference("Sunndal")
  kommunenavn[int(1566.0)] = createStringReference("Surnadal")
  kommunenavn[int(1567.0)] = createStringReference("Rindal")
  kommunenavn[int(1571.0)] = createStringReference("Halsa")
  kommunenavn[int(1573.0)] = createStringReference("Sm\u00f8la")
  kommunenavn[int(1576.0)] = createStringReference("Aure")
  kommunenavn[int(1601.0)] = createStringReference("Trondheim")
  kommunenavn[int(1612.0)] = createStringReference("Hemne")
  kommunenavn[int(1613.0)] = createStringReference("Snillfjord")
  kommunenavn[int(1617.0)] = createStringReference("Hitra")
  kommunenavn[int(1620.0)] = createStringReference("Fr\u00f8ya")
  kommunenavn[int(1621.0)] = createStringReference("\u00d8rland")
  kommunenavn[int(1622.0)] = createStringReference("Agdenes")
  kommunenavn[int(1624.0)] = createStringReference("Rissa")
  kommunenavn[int(1627.0)] = createStringReference("Bjugn")
  kommunenavn[int(1630.0)] = createStringReference("\u00c5fjord")
  kommunenavn[int(1632.0)] = createStringReference("Roan")
  kommunenavn[int(1633.0)] = createStringReference("Osen")
  kommunenavn[int(1634.0)] = createStringReference("Oppdal")
  kommunenavn[int(1635.0)] = createStringReference("Rennebu")
  kommunenavn[int(1636.0)] = createStringReference("Meldal")
  kommunenavn[int(1638.0)] = createStringReference("Orkdal")
  kommunenavn[int(1640.0)] = createStringReference("R\u00f8ros")
  kommunenavn[int(1644.0)] = createStringReference("Holt\u00e5len")
  kommunenavn[int(1648.0)] = createStringReference("Midtre Gauldal")
  kommunenavn[int(1653.0)] = createStringReference("Melhus")
  kommunenavn[int(1657.0)] = createStringReference("Skaun")
  kommunenavn[int(1662.0)] = createStringReference("Kl\u00e6bu")
  kommunenavn[int(1663.0)] = createStringReference("Malvik")
  kommunenavn[int(1664.0)] = createStringReference("Selbu")
  kommunenavn[int(1665.0)] = createStringReference("Tydal")
  kommunenavn[int(1702.0)] = createStringReference("Steinkjer")
  kommunenavn[int(1703.0)] = createStringReference("Namsos")
  kommunenavn[int(1711.0)] = createStringReference("Mer\u00e5ker")
  kommunenavn[int(1714.0)] = createStringReference("Stj\u00f8rdal")
  kommunenavn[int(1717.0)] = createStringReference("Frosta")
  kommunenavn[int(1718.0)] = createStringReference("Leksvik")
  kommunenavn[int(1719.0)] = createStringReference("Levanger")
  kommunenavn[int(1721.0)] = createStringReference("Verdal")
  kommunenavn[int(1724.0)] = createStringReference("Verran")
  kommunenavn[int(1725.0)] = createStringReference("Namdalseid")
  kommunenavn[int(1736.0)] = createStringReference("Sn\u00e5ase \u2013 Sn\u00e5sa")
  kommunenavn[int(1738.0)] = createStringReference("Lierne")
  kommunenavn[int(1739.0)] = createStringReference("Raarvihke \u2013 R\u00f8yrvik")
  kommunenavn[int(1740.0)] = createStringReference("Namsskogan")
  kommunenavn[int(1742.0)] = createStringReference("Grong")
  kommunenavn[int(1743.0)] = createStringReference("H\u00f8ylandet")
  kommunenavn[int(1744.0)] = createStringReference("Overhalla")
  kommunenavn[int(1748.0)] = createStringReference("Fosnes")
  kommunenavn[int(1749.0)] = createStringReference("Flatanger")
  kommunenavn[int(1750.0)] = createStringReference("Vikna")
  kommunenavn[int(1751.0)] = createStringReference("N\u00e6r\u00f8y")
  kommunenavn[int(1755.0)] = createStringReference("Leka")
  kommunenavn[int(1756.0)] = createStringReference("Inder\u00f8y")
  kommunenavn[int(1804.0)] = createStringReference("Bod\u00f8")
  kommunenavn[int(1805.0)] = createStringReference("Narvik")
  kommunenavn[int(1811.0)] = createStringReference("Bindal")
  kommunenavn[int(1812.0)] = createStringReference("S\u00f8mna")
  kommunenavn[int(1813.0)] = createStringReference("Br\u00f8nn\u00f8y")
  kommunenavn[int(1815.0)] = createStringReference("Vega")
  kommunenavn[int(1816.0)] = createStringReference("Vevelstad")
  kommunenavn[int(1818.0)] = createStringReference("Her\u00f8y")
  kommunenavn[int(1820.0)] = createStringReference("Alstahaug")
  kommunenavn[int(1822.0)] = createStringReference("Leirfjord")
  kommunenavn[int(1824.0)] = createStringReference("Vefsn")
  kommunenavn[int(1825.0)] = createStringReference("Grane")
  kommunenavn[int(1826.0)] = createStringReference("Hattfjelldal")
  kommunenavn[int(1827.0)] = createStringReference("D\u00f8nna")
  kommunenavn[int(1828.0)] = createStringReference("Nesna")
  kommunenavn[int(1832.0)] = createStringReference("Hemnes")
  kommunenavn[int(1833.0)] = createStringReference("Rana")
  kommunenavn[int(1834.0)] = createStringReference("Lur\u00f8y")
  kommunenavn[int(1835.0)] = createStringReference("Tr\u00e6na")
  kommunenavn[int(1836.0)] = createStringReference("R\u00f8d\u00f8y")
  kommunenavn[int(1837.0)] = createStringReference("Mel\u00f8y")
  kommunenavn[int(1838.0)] = createStringReference("Gildesk\u00e5l")
  kommunenavn[int(1839.0)] = createStringReference("Beiarn")
  kommunenavn[int(1840.0)] = createStringReference("Saltdal")
  kommunenavn[int(1841.0)] = createStringReference("Fauske \u2013 Fuossko")
  kommunenavn[int(1845.0)] = createStringReference("S\u00f8rfold")
  kommunenavn[int(1848.0)] = createStringReference("Steigen")
  kommunenavn[int(1849.0)] = createStringReference("Hamar\u00f8y \u2013 H\u00e1bmer")
  kommunenavn[int(1850.0)] = createStringReference("Divtasvuodna \u2013 Tysfjord")
  kommunenavn[int(1851.0)] = createStringReference("L\u00f8dingen")
  kommunenavn[int(1852.0)] = createStringReference("Tjeldsund")
  kommunenavn[int(1853.0)] = createStringReference("Evenes")
  kommunenavn[int(1854.0)] = createStringReference("Ballangen")
  kommunenavn[int(1856.0)] = createStringReference("R\u00f8st")
  kommunenavn[int(1857.0)] = createStringReference("V\u00e6r\u00f8y")
  kommunenavn[int(1859.0)] = createStringReference("Flakstad")
  kommunenavn[int(1860.0)] = createStringReference("Vestv\u00e5g\u00f8y")
  kommunenavn[int(1865.0)] = createStringReference("V\u00e5gan")
  kommunenavn[int(1866.0)] = createStringReference("Hadsel")
  kommunenavn[int(1867.0)] = createStringReference("B\u00f8")
  kommunenavn[int(1868.0)] = createStringReference("\u00d8ksnes")
  kommunenavn[int(1870.0)] = createStringReference("Sortland \u2013 Suort\u00e1")
  kommunenavn[int(1871.0)] = createStringReference("And\u00f8y")
  kommunenavn[int(1874.0)] = createStringReference("Moskenes")
  kommunenavn[int(1903.0)] = createStringReference("Harstad \u2013 H\u00e1rstt\u00e1k")
  kommunenavn[int(1902.0)] = createStringReference("Troms\u00f8")
  kommunenavn[int(1911.0)] = createStringReference("Kv\u00e6fjord")
  kommunenavn[int(1913.0)] = createStringReference("Sk\u00e5nland")
  kommunenavn[int(1917.0)] = createStringReference("Ibestad")
  kommunenavn[int(1919.0)] = createStringReference("Gratangen")
  kommunenavn[int(1920.0)] = createStringReference("Loab\u00e1k \u2013 Lavangen")
  kommunenavn[int(1922.0)] = createStringReference("Bardu")
  kommunenavn[int(1923.0)] = createStringReference("Salangen")
  kommunenavn[int(1924.0)] = createStringReference("M\u00e5lselv")
  kommunenavn[int(1925.0)] = createStringReference("S\u00f8rreisa")
  kommunenavn[int(1926.0)] = createStringReference("Dyr\u00f8y")
  kommunenavn[int(1927.0)] = createStringReference("Tran\u00f8y")
  kommunenavn[int(1928.0)] = createStringReference("Torsken")
  kommunenavn[int(1929.0)] = createStringReference("Berg")
  kommunenavn[int(1931.0)] = createStringReference("Lenvik")
  kommunenavn[int(1933.0)] = createStringReference("Balsfjord")
  kommunenavn[int(1936.0)] = createStringReference("Karls\u00f8y")
  kommunenavn[int(1938.0)] = createStringReference("Lyngen")
  kommunenavn[int(1939.0)] = createStringReference("Storfjord \u2013 Omasvuotna \u2013 Omasvuono")
  kommunenavn[int(1940.0)] = createStringReference("G\u00e1ivuotna \u2013 K\u00e5fjord \u2013 Kaivuono")
  kommunenavn[int(1941.0)] = createStringReference("Skjerv\u00f8y")
  kommunenavn[int(1942.0)] = createStringReference("Nordreisa")
  kommunenavn[int(1943.0)] = createStringReference("Kv\u00e6nangen")
  kommunenavn[int(2002.0)] = createStringReference("Vard\u00f8")
  kommunenavn[int(2003.0)] = createStringReference("Vads\u00f8")
  kommunenavn[int(2004.0)] = createStringReference("Hammerfest")
  kommunenavn[int(2011.0)] = createStringReference("Guovdageaidnu \u2013 Kautokeino")
  kommunenavn[int(2012.0)] = createStringReference("Alta")
  kommunenavn[int(2014.0)] = createStringReference("Loppa")
  kommunenavn[int(2015.0)] = createStringReference("Hasvik")
  kommunenavn[int(2017.0)] = createStringReference("Kvalsund")
  kommunenavn[int(2018.0)] = createStringReference("M\u00e5s\u00f8y")
  kommunenavn[int(2019.0)] = createStringReference("Nordkapp")
  kommunenavn[int(2020.0)] = createStringReference("Porsanger \u2013 Pors\u00e1\u014bgu \u2013 Porsanki")
  kommunenavn[int(2021.0)] = createStringReference("K\u00e1r\u00e1\u0161johka \u2013 Karasjok")
  kommunenavn[int(2022.0)] = createStringReference("Lebesby")
  kommunenavn[int(2023.0)] = createStringReference("Gamvik")
  kommunenavn[int(2024.0)] = createStringReference("Berlev\u00e5g")
  kommunenavn[int(2025.0)] = createStringReference("Deatnu \u2013 Tana")
  kommunenavn[int(2027.0)] = createStringReference("Unj\u00e1rga \u2013 Nesseby")
  kommunenavn[int(2028.0)] = createStringReference("B\u00e5tsfjord")
  kommunenavn[int(2030.0)] = createStringReference("S\u00f8r-Varanger")

  return kommunenavn

def hentGyldigeKommunenummer():
  gyldigeKommunenummer =  [None]*int(425.0 + 1.0)

  gyldigeKommunenummer[int(0.0)] = 101.0
  gyldigeKommunenummer[int(1.0)] = 104.0
  gyldigeKommunenummer[int(2.0)] = 105.0
  gyldigeKommunenummer[int(3.0)] = 106.0
  gyldigeKommunenummer[int(4.0)] = 111.0
  gyldigeKommunenummer[int(5.0)] = 118.0
  gyldigeKommunenummer[int(6.0)] = 119.0
  gyldigeKommunenummer[int(7.0)] = 121.0
  gyldigeKommunenummer[int(8.0)] = 122.0
  gyldigeKommunenummer[int(9.0)] = 123.0
  gyldigeKommunenummer[int(10.0)] = 124.0
  gyldigeKommunenummer[int(11.0)] = 125.0
  gyldigeKommunenummer[int(12.0)] = 127.0
  gyldigeKommunenummer[int(13.0)] = 128.0
  gyldigeKommunenummer[int(14.0)] = 135.0
  gyldigeKommunenummer[int(15.0)] = 136.0
  gyldigeKommunenummer[int(16.0)] = 137.0
  gyldigeKommunenummer[int(17.0)] = 138.0
  gyldigeKommunenummer[int(18.0)] = 211.0
  gyldigeKommunenummer[int(19.0)] = 213.0
  gyldigeKommunenummer[int(20.0)] = 214.0
  gyldigeKommunenummer[int(21.0)] = 215.0
  gyldigeKommunenummer[int(22.0)] = 216.0
  gyldigeKommunenummer[int(23.0)] = 217.0
  gyldigeKommunenummer[int(24.0)] = 219.0
  gyldigeKommunenummer[int(25.0)] = 220.0
  gyldigeKommunenummer[int(26.0)] = 221.0
  gyldigeKommunenummer[int(27.0)] = 226.0
  gyldigeKommunenummer[int(28.0)] = 227.0
  gyldigeKommunenummer[int(29.0)] = 228.0
  gyldigeKommunenummer[int(30.0)] = 229.0
  gyldigeKommunenummer[int(31.0)] = 230.0
  gyldigeKommunenummer[int(32.0)] = 231.0
  gyldigeKommunenummer[int(33.0)] = 233.0
  gyldigeKommunenummer[int(34.0)] = 234.0
  gyldigeKommunenummer[int(35.0)] = 235.0
  gyldigeKommunenummer[int(36.0)] = 236.0
  gyldigeKommunenummer[int(37.0)] = 237.0
  gyldigeKommunenummer[int(38.0)] = 238.0
  gyldigeKommunenummer[int(39.0)] = 239.0
  gyldigeKommunenummer[int(40.0)] = 301.0
  gyldigeKommunenummer[int(41.0)] = 402.0
  gyldigeKommunenummer[int(42.0)] = 403.0
  gyldigeKommunenummer[int(43.0)] = 412.0
  gyldigeKommunenummer[int(44.0)] = 415.0
  gyldigeKommunenummer[int(45.0)] = 417.0
  gyldigeKommunenummer[int(46.0)] = 418.0
  gyldigeKommunenummer[int(47.0)] = 419.0
  gyldigeKommunenummer[int(48.0)] = 420.0
  gyldigeKommunenummer[int(49.0)] = 423.0
  gyldigeKommunenummer[int(50.0)] = 425.0
  gyldigeKommunenummer[int(51.0)] = 426.0
  gyldigeKommunenummer[int(52.0)] = 427.0
  gyldigeKommunenummer[int(53.0)] = 428.0
  gyldigeKommunenummer[int(54.0)] = 429.0
  gyldigeKommunenummer[int(55.0)] = 430.0
  gyldigeKommunenummer[int(56.0)] = 432.0
  gyldigeKommunenummer[int(57.0)] = 434.0
  gyldigeKommunenummer[int(58.0)] = 436.0
  gyldigeKommunenummer[int(59.0)] = 437.0
  gyldigeKommunenummer[int(60.0)] = 438.0
  gyldigeKommunenummer[int(61.0)] = 439.0
  gyldigeKommunenummer[int(62.0)] = 441.0
  gyldigeKommunenummer[int(63.0)] = 501.0
  gyldigeKommunenummer[int(64.0)] = 502.0
  gyldigeKommunenummer[int(65.0)] = 511.0
  gyldigeKommunenummer[int(66.0)] = 512.0
  gyldigeKommunenummer[int(67.0)] = 513.0
  gyldigeKommunenummer[int(68.0)] = 514.0
  gyldigeKommunenummer[int(69.0)] = 515.0
  gyldigeKommunenummer[int(70.0)] = 516.0
  gyldigeKommunenummer[int(71.0)] = 517.0
  gyldigeKommunenummer[int(72.0)] = 519.0
  gyldigeKommunenummer[int(73.0)] = 520.0
  gyldigeKommunenummer[int(74.0)] = 521.0
  gyldigeKommunenummer[int(75.0)] = 522.0
  gyldigeKommunenummer[int(76.0)] = 528.0
  gyldigeKommunenummer[int(77.0)] = 529.0
  gyldigeKommunenummer[int(78.0)] = 532.0
  gyldigeKommunenummer[int(79.0)] = 533.0
  gyldigeKommunenummer[int(80.0)] = 534.0
  gyldigeKommunenummer[int(81.0)] = 536.0
  gyldigeKommunenummer[int(82.0)] = 538.0
  gyldigeKommunenummer[int(83.0)] = 540.0
  gyldigeKommunenummer[int(84.0)] = 541.0
  gyldigeKommunenummer[int(85.0)] = 542.0
  gyldigeKommunenummer[int(86.0)] = 543.0
  gyldigeKommunenummer[int(87.0)] = 544.0
  gyldigeKommunenummer[int(88.0)] = 545.0
  gyldigeKommunenummer[int(89.0)] = 602.0
  gyldigeKommunenummer[int(90.0)] = 604.0
  gyldigeKommunenummer[int(91.0)] = 605.0
  gyldigeKommunenummer[int(92.0)] = 612.0
  gyldigeKommunenummer[int(93.0)] = 615.0
  gyldigeKommunenummer[int(94.0)] = 616.0
  gyldigeKommunenummer[int(95.0)] = 617.0
  gyldigeKommunenummer[int(96.0)] = 618.0
  gyldigeKommunenummer[int(97.0)] = 619.0
  gyldigeKommunenummer[int(98.0)] = 620.0
  gyldigeKommunenummer[int(99.0)] = 621.0
  gyldigeKommunenummer[int(100.0)] = 622.0
  gyldigeKommunenummer[int(101.0)] = 623.0
  gyldigeKommunenummer[int(102.0)] = 624.0
  gyldigeKommunenummer[int(103.0)] = 625.0
  gyldigeKommunenummer[int(104.0)] = 626.0
  gyldigeKommunenummer[int(105.0)] = 627.0
  gyldigeKommunenummer[int(106.0)] = 628.0
  gyldigeKommunenummer[int(107.0)] = 631.0
  gyldigeKommunenummer[int(108.0)] = 632.0
  gyldigeKommunenummer[int(109.0)] = 633.0
  gyldigeKommunenummer[int(110.0)] = 701.0
  gyldigeKommunenummer[int(111.0)] = 702.0
  gyldigeKommunenummer[int(112.0)] = 704.0
  gyldigeKommunenummer[int(113.0)] = 709.0
  gyldigeKommunenummer[int(114.0)] = 710.0
  gyldigeKommunenummer[int(115.0)] = 711.0
  gyldigeKommunenummer[int(116.0)] = 713.0
  gyldigeKommunenummer[int(117.0)] = 714.0
  gyldigeKommunenummer[int(118.0)] = 716.0
  gyldigeKommunenummer[int(119.0)] = 722.0
  gyldigeKommunenummer[int(120.0)] = 723.0
  gyldigeKommunenummer[int(121.0)] = 728.0
  gyldigeKommunenummer[int(122.0)] = 805.0
  gyldigeKommunenummer[int(123.0)] = 806.0
  gyldigeKommunenummer[int(124.0)] = 807.0
  gyldigeKommunenummer[int(125.0)] = 811.0
  gyldigeKommunenummer[int(126.0)] = 814.0
  gyldigeKommunenummer[int(127.0)] = 815.0
  gyldigeKommunenummer[int(128.0)] = 817.0
  gyldigeKommunenummer[int(129.0)] = 819.0
  gyldigeKommunenummer[int(130.0)] = 821.0
  gyldigeKommunenummer[int(131.0)] = 822.0
  gyldigeKommunenummer[int(132.0)] = 826.0
  gyldigeKommunenummer[int(133.0)] = 827.0
  gyldigeKommunenummer[int(134.0)] = 828.0
  gyldigeKommunenummer[int(135.0)] = 829.0
  gyldigeKommunenummer[int(136.0)] = 830.0
  gyldigeKommunenummer[int(137.0)] = 831.0
  gyldigeKommunenummer[int(138.0)] = 833.0
  gyldigeKommunenummer[int(139.0)] = 834.0
  gyldigeKommunenummer[int(140.0)] = 901.0
  gyldigeKommunenummer[int(141.0)] = 904.0
  gyldigeKommunenummer[int(142.0)] = 906.0
  gyldigeKommunenummer[int(143.0)] = 911.0
  gyldigeKommunenummer[int(144.0)] = 912.0
  gyldigeKommunenummer[int(145.0)] = 914.0
  gyldigeKommunenummer[int(146.0)] = 919.0
  gyldigeKommunenummer[int(147.0)] = 926.0
  gyldigeKommunenummer[int(148.0)] = 928.0
  gyldigeKommunenummer[int(149.0)] = 929.0
  gyldigeKommunenummer[int(150.0)] = 935.0
  gyldigeKommunenummer[int(151.0)] = 937.0
  gyldigeKommunenummer[int(152.0)] = 938.0
  gyldigeKommunenummer[int(153.0)] = 940.0
  gyldigeKommunenummer[int(154.0)] = 941.0
  gyldigeKommunenummer[int(155.0)] = 1001.0
  gyldigeKommunenummer[int(156.0)] = 1002.0
  gyldigeKommunenummer[int(157.0)] = 1003.0
  gyldigeKommunenummer[int(158.0)] = 1004.0
  gyldigeKommunenummer[int(159.0)] = 1014.0
  gyldigeKommunenummer[int(160.0)] = 1017.0
  gyldigeKommunenummer[int(161.0)] = 1018.0
  gyldigeKommunenummer[int(162.0)] = 1021.0
  gyldigeKommunenummer[int(163.0)] = 1026.0
  gyldigeKommunenummer[int(164.0)] = 1027.0
  gyldigeKommunenummer[int(165.0)] = 1029.0
  gyldigeKommunenummer[int(166.0)] = 1032.0
  gyldigeKommunenummer[int(167.0)] = 1034.0
  gyldigeKommunenummer[int(168.0)] = 1037.0
  gyldigeKommunenummer[int(169.0)] = 1046.0
  gyldigeKommunenummer[int(170.0)] = 1101.0
  gyldigeKommunenummer[int(171.0)] = 1102.0
  gyldigeKommunenummer[int(172.0)] = 1103.0
  gyldigeKommunenummer[int(173.0)] = 1106.0
  gyldigeKommunenummer[int(174.0)] = 1111.0
  gyldigeKommunenummer[int(175.0)] = 1112.0
  gyldigeKommunenummer[int(176.0)] = 1114.0
  gyldigeKommunenummer[int(177.0)] = 1119.0
  gyldigeKommunenummer[int(178.0)] = 1120.0
  gyldigeKommunenummer[int(179.0)] = 1121.0
  gyldigeKommunenummer[int(180.0)] = 1122.0
  gyldigeKommunenummer[int(181.0)] = 1124.0
  gyldigeKommunenummer[int(182.0)] = 1127.0
  gyldigeKommunenummer[int(183.0)] = 1129.0
  gyldigeKommunenummer[int(184.0)] = 1130.0
  gyldigeKommunenummer[int(185.0)] = 1133.0
  gyldigeKommunenummer[int(186.0)] = 1134.0
  gyldigeKommunenummer[int(187.0)] = 1135.0
  gyldigeKommunenummer[int(188.0)] = 1141.0
  gyldigeKommunenummer[int(189.0)] = 1142.0
  gyldigeKommunenummer[int(190.0)] = 1144.0
  gyldigeKommunenummer[int(191.0)] = 1145.0
  gyldigeKommunenummer[int(192.0)] = 1146.0
  gyldigeKommunenummer[int(193.0)] = 1149.0
  gyldigeKommunenummer[int(194.0)] = 1151.0
  gyldigeKommunenummer[int(195.0)] = 1160.0
  gyldigeKommunenummer[int(196.0)] = 1201.0
  gyldigeKommunenummer[int(197.0)] = 1211.0
  gyldigeKommunenummer[int(198.0)] = 1216.0
  gyldigeKommunenummer[int(199.0)] = 1219.0
  gyldigeKommunenummer[int(200.0)] = 1221.0
  gyldigeKommunenummer[int(201.0)] = 1222.0
  gyldigeKommunenummer[int(202.0)] = 1223.0
  gyldigeKommunenummer[int(203.0)] = 1224.0
  gyldigeKommunenummer[int(204.0)] = 1227.0
  gyldigeKommunenummer[int(205.0)] = 1228.0
  gyldigeKommunenummer[int(206.0)] = 1231.0
  gyldigeKommunenummer[int(207.0)] = 1232.0
  gyldigeKommunenummer[int(208.0)] = 1233.0
  gyldigeKommunenummer[int(209.0)] = 1234.0
  gyldigeKommunenummer[int(210.0)] = 1235.0
  gyldigeKommunenummer[int(211.0)] = 1238.0
  gyldigeKommunenummer[int(212.0)] = 1241.0
  gyldigeKommunenummer[int(213.0)] = 1242.0
  gyldigeKommunenummer[int(214.0)] = 1243.0
  gyldigeKommunenummer[int(215.0)] = 1244.0
  gyldigeKommunenummer[int(216.0)] = 1245.0
  gyldigeKommunenummer[int(217.0)] = 1246.0
  gyldigeKommunenummer[int(218.0)] = 1247.0
  gyldigeKommunenummer[int(219.0)] = 1251.0
  gyldigeKommunenummer[int(220.0)] = 1252.0
  gyldigeKommunenummer[int(221.0)] = 1253.0
  gyldigeKommunenummer[int(222.0)] = 1256.0
  gyldigeKommunenummer[int(223.0)] = 1259.0
  gyldigeKommunenummer[int(224.0)] = 1260.0
  gyldigeKommunenummer[int(225.0)] = 1263.0
  gyldigeKommunenummer[int(226.0)] = 1264.0
  gyldigeKommunenummer[int(227.0)] = 1265.0
  gyldigeKommunenummer[int(228.0)] = 1266.0
  gyldigeKommunenummer[int(229.0)] = 1401.0
  gyldigeKommunenummer[int(230.0)] = 1411.0
  gyldigeKommunenummer[int(231.0)] = 1412.0
  gyldigeKommunenummer[int(232.0)] = 1413.0
  gyldigeKommunenummer[int(233.0)] = 1416.0
  gyldigeKommunenummer[int(234.0)] = 1417.0
  gyldigeKommunenummer[int(235.0)] = 1418.0
  gyldigeKommunenummer[int(236.0)] = 1419.0
  gyldigeKommunenummer[int(237.0)] = 1420.0
  gyldigeKommunenummer[int(238.0)] = 1421.0
  gyldigeKommunenummer[int(239.0)] = 1422.0
  gyldigeKommunenummer[int(240.0)] = 1424.0
  gyldigeKommunenummer[int(241.0)] = 1426.0
  gyldigeKommunenummer[int(242.0)] = 1428.0
  gyldigeKommunenummer[int(243.0)] = 1429.0
  gyldigeKommunenummer[int(244.0)] = 1430.0
  gyldigeKommunenummer[int(245.0)] = 1431.0
  gyldigeKommunenummer[int(246.0)] = 1432.0
  gyldigeKommunenummer[int(247.0)] = 1433.0
  gyldigeKommunenummer[int(248.0)] = 1438.0
  gyldigeKommunenummer[int(249.0)] = 1439.0
  gyldigeKommunenummer[int(250.0)] = 1441.0
  gyldigeKommunenummer[int(251.0)] = 1443.0
  gyldigeKommunenummer[int(252.0)] = 1444.0
  gyldigeKommunenummer[int(253.0)] = 1445.0
  gyldigeKommunenummer[int(254.0)] = 1449.0
  gyldigeKommunenummer[int(255.0)] = 1502.0
  gyldigeKommunenummer[int(256.0)] = 1504.0
  gyldigeKommunenummer[int(257.0)] = 1505.0
  gyldigeKommunenummer[int(258.0)] = 1511.0
  gyldigeKommunenummer[int(259.0)] = 1514.0
  gyldigeKommunenummer[int(260.0)] = 1515.0
  gyldigeKommunenummer[int(261.0)] = 1516.0
  gyldigeKommunenummer[int(262.0)] = 1517.0
  gyldigeKommunenummer[int(263.0)] = 1519.0
  gyldigeKommunenummer[int(264.0)] = 1520.0
  gyldigeKommunenummer[int(265.0)] = 1523.0
  gyldigeKommunenummer[int(266.0)] = 1524.0
  gyldigeKommunenummer[int(267.0)] = 1525.0
  gyldigeKommunenummer[int(268.0)] = 1526.0
  gyldigeKommunenummer[int(269.0)] = 1528.0
  gyldigeKommunenummer[int(270.0)] = 1529.0
  gyldigeKommunenummer[int(271.0)] = 1531.0
  gyldigeKommunenummer[int(272.0)] = 1532.0
  gyldigeKommunenummer[int(273.0)] = 1534.0
  gyldigeKommunenummer[int(274.0)] = 1535.0
  gyldigeKommunenummer[int(275.0)] = 1539.0
  gyldigeKommunenummer[int(276.0)] = 1543.0
  gyldigeKommunenummer[int(277.0)] = 1545.0
  gyldigeKommunenummer[int(278.0)] = 1546.0
  gyldigeKommunenummer[int(279.0)] = 1547.0
  gyldigeKommunenummer[int(280.0)] = 1548.0
  gyldigeKommunenummer[int(281.0)] = 1551.0
  gyldigeKommunenummer[int(282.0)] = 1554.0
  gyldigeKommunenummer[int(283.0)] = 1557.0
  gyldigeKommunenummer[int(284.0)] = 1560.0
  gyldigeKommunenummer[int(285.0)] = 1563.0
  gyldigeKommunenummer[int(286.0)] = 1566.0
  gyldigeKommunenummer[int(287.0)] = 1567.0
  gyldigeKommunenummer[int(288.0)] = 1571.0
  gyldigeKommunenummer[int(289.0)] = 1573.0
  gyldigeKommunenummer[int(290.0)] = 1576.0
  gyldigeKommunenummer[int(291.0)] = 1601.0
  gyldigeKommunenummer[int(292.0)] = 1612.0
  gyldigeKommunenummer[int(293.0)] = 1613.0
  gyldigeKommunenummer[int(294.0)] = 1617.0
  gyldigeKommunenummer[int(295.0)] = 1620.0
  gyldigeKommunenummer[int(296.0)] = 1621.0
  gyldigeKommunenummer[int(297.0)] = 1622.0
  gyldigeKommunenummer[int(298.0)] = 1624.0
  gyldigeKommunenummer[int(299.0)] = 1627.0
  gyldigeKommunenummer[int(300.0)] = 1630.0
  gyldigeKommunenummer[int(301.0)] = 1632.0
  gyldigeKommunenummer[int(302.0)] = 1633.0
  gyldigeKommunenummer[int(303.0)] = 1634.0
  gyldigeKommunenummer[int(304.0)] = 1635.0
  gyldigeKommunenummer[int(305.0)] = 1636.0
  gyldigeKommunenummer[int(306.0)] = 1638.0
  gyldigeKommunenummer[int(307.0)] = 1640.0
  gyldigeKommunenummer[int(308.0)] = 1644.0
  gyldigeKommunenummer[int(309.0)] = 1648.0
  gyldigeKommunenummer[int(310.0)] = 1653.0
  gyldigeKommunenummer[int(311.0)] = 1657.0
  gyldigeKommunenummer[int(312.0)] = 1662.0
  gyldigeKommunenummer[int(313.0)] = 1663.0
  gyldigeKommunenummer[int(314.0)] = 1664.0
  gyldigeKommunenummer[int(315.0)] = 1665.0
  gyldigeKommunenummer[int(316.0)] = 1702.0
  gyldigeKommunenummer[int(317.0)] = 1703.0
  gyldigeKommunenummer[int(318.0)] = 1711.0
  gyldigeKommunenummer[int(319.0)] = 1714.0
  gyldigeKommunenummer[int(320.0)] = 1717.0
  gyldigeKommunenummer[int(321.0)] = 1718.0
  gyldigeKommunenummer[int(322.0)] = 1719.0
  gyldigeKommunenummer[int(323.0)] = 1721.0
  gyldigeKommunenummer[int(324.0)] = 1724.0
  gyldigeKommunenummer[int(325.0)] = 1725.0
  gyldigeKommunenummer[int(326.0)] = 1736.0
  gyldigeKommunenummer[int(327.0)] = 1738.0
  gyldigeKommunenummer[int(328.0)] = 1739.0
  gyldigeKommunenummer[int(329.0)] = 1740.0
  gyldigeKommunenummer[int(330.0)] = 1742.0
  gyldigeKommunenummer[int(331.0)] = 1743.0
  gyldigeKommunenummer[int(332.0)] = 1744.0
  gyldigeKommunenummer[int(333.0)] = 1748.0
  gyldigeKommunenummer[int(334.0)] = 1749.0
  gyldigeKommunenummer[int(335.0)] = 1750.0
  gyldigeKommunenummer[int(336.0)] = 1751.0
  gyldigeKommunenummer[int(337.0)] = 1755.0
  gyldigeKommunenummer[int(338.0)] = 1756.0
  gyldigeKommunenummer[int(339.0)] = 1804.0
  gyldigeKommunenummer[int(340.0)] = 1805.0
  gyldigeKommunenummer[int(341.0)] = 1811.0
  gyldigeKommunenummer[int(342.0)] = 1812.0
  gyldigeKommunenummer[int(343.0)] = 1813.0
  gyldigeKommunenummer[int(344.0)] = 1815.0
  gyldigeKommunenummer[int(345.0)] = 1816.0
  gyldigeKommunenummer[int(346.0)] = 1818.0
  gyldigeKommunenummer[int(347.0)] = 1820.0
  gyldigeKommunenummer[int(348.0)] = 1822.0
  gyldigeKommunenummer[int(349.0)] = 1824.0
  gyldigeKommunenummer[int(350.0)] = 1825.0
  gyldigeKommunenummer[int(351.0)] = 1826.0
  gyldigeKommunenummer[int(352.0)] = 1827.0
  gyldigeKommunenummer[int(353.0)] = 1828.0
  gyldigeKommunenummer[int(354.0)] = 1832.0
  gyldigeKommunenummer[int(355.0)] = 1833.0
  gyldigeKommunenummer[int(356.0)] = 1834.0
  gyldigeKommunenummer[int(357.0)] = 1835.0
  gyldigeKommunenummer[int(358.0)] = 1836.0
  gyldigeKommunenummer[int(359.0)] = 1837.0
  gyldigeKommunenummer[int(360.0)] = 1838.0
  gyldigeKommunenummer[int(361.0)] = 1839.0
  gyldigeKommunenummer[int(362.0)] = 1840.0
  gyldigeKommunenummer[int(363.0)] = 1841.0
  gyldigeKommunenummer[int(364.0)] = 1845.0
  gyldigeKommunenummer[int(365.0)] = 1848.0
  gyldigeKommunenummer[int(366.0)] = 1849.0
  gyldigeKommunenummer[int(367.0)] = 1850.0
  gyldigeKommunenummer[int(368.0)] = 1851.0
  gyldigeKommunenummer[int(369.0)] = 1852.0
  gyldigeKommunenummer[int(370.0)] = 1853.0
  gyldigeKommunenummer[int(371.0)] = 1854.0
  gyldigeKommunenummer[int(372.0)] = 1856.0
  gyldigeKommunenummer[int(373.0)] = 1857.0
  gyldigeKommunenummer[int(374.0)] = 1859.0
  gyldigeKommunenummer[int(375.0)] = 1860.0
  gyldigeKommunenummer[int(376.0)] = 1865.0
  gyldigeKommunenummer[int(377.0)] = 1866.0
  gyldigeKommunenummer[int(378.0)] = 1867.0
  gyldigeKommunenummer[int(379.0)] = 1868.0
  gyldigeKommunenummer[int(380.0)] = 1870.0
  gyldigeKommunenummer[int(381.0)] = 1871.0
  gyldigeKommunenummer[int(382.0)] = 1874.0
  gyldigeKommunenummer[int(383.0)] = 1903.0
  gyldigeKommunenummer[int(384.0)] = 1902.0
  gyldigeKommunenummer[int(385.0)] = 1911.0
  gyldigeKommunenummer[int(386.0)] = 1913.0
  gyldigeKommunenummer[int(387.0)] = 1917.0
  gyldigeKommunenummer[int(388.0)] = 1919.0
  gyldigeKommunenummer[int(389.0)] = 1920.0
  gyldigeKommunenummer[int(390.0)] = 1922.0
  gyldigeKommunenummer[int(391.0)] = 1923.0
  gyldigeKommunenummer[int(392.0)] = 1924.0
  gyldigeKommunenummer[int(393.0)] = 1925.0
  gyldigeKommunenummer[int(394.0)] = 1926.0
  gyldigeKommunenummer[int(395.0)] = 1927.0
  gyldigeKommunenummer[int(396.0)] = 1928.0
  gyldigeKommunenummer[int(397.0)] = 1929.0
  gyldigeKommunenummer[int(398.0)] = 1931.0
  gyldigeKommunenummer[int(399.0)] = 1933.0
  gyldigeKommunenummer[int(400.0)] = 1936.0
  gyldigeKommunenummer[int(401.0)] = 1938.0
  gyldigeKommunenummer[int(402.0)] = 1939.0
  gyldigeKommunenummer[int(403.0)] = 1940.0
  gyldigeKommunenummer[int(404.0)] = 1941.0
  gyldigeKommunenummer[int(405.0)] = 1942.0
  gyldigeKommunenummer[int(406.0)] = 1943.0
  gyldigeKommunenummer[int(407.0)] = 2002.0
  gyldigeKommunenummer[int(408.0)] = 2003.0
  gyldigeKommunenummer[int(409.0)] = 2004.0
  gyldigeKommunenummer[int(410.0)] = 2011.0
  gyldigeKommunenummer[int(411.0)] = 2012.0
  gyldigeKommunenummer[int(412.0)] = 2014.0
  gyldigeKommunenummer[int(413.0)] = 2015.0
  gyldigeKommunenummer[int(414.0)] = 2017.0
  gyldigeKommunenummer[int(415.0)] = 2018.0
  gyldigeKommunenummer[int(416.0)] = 2019.0
  gyldigeKommunenummer[int(417.0)] = 2020.0
  gyldigeKommunenummer[int(418.0)] = 2021.0
  gyldigeKommunenummer[int(419.0)] = 2022.0
  gyldigeKommunenummer[int(420.0)] = 2023.0
  gyldigeKommunenummer[int(421.0)] = 2024.0
  gyldigeKommunenummer[int(422.0)] = 2025.0
  gyldigeKommunenummer[int(423.0)] = 2027.0
  gyldigeKommunenummer[int(424.0)] = 2028.0
  gyldigeKommunenummer[int(425.0)] = 2030.0

  return gyldigeKommunenummer

def test1():
  doubleReference = DoubleReference()
  doubleReference.doubleValue = 0.0

  success = Success()
  kommuenavn = hentKommunenavnFraNummer("1640", success)
  assertStringEquals(kommuenavn, "R\u00f8ros", doubleReference)
  assertTrue(success.success, doubleReference)

  return doubleReference.doubleValue

def test():
  failures = 0.0

  failures = failures + test1()

  return failures

class StringToDecimalResult:
  result = None
  feilmelding = None
  success = None

def decimalToString(decimal):
  return numberToString(decimal, 10.0)

def numberToString(decimal, base):
  string =  [None]*int(0.0)

  digits = getDigits(base)

  # Find digitPosition:
  digitPosition = getDigitPosition(decimal, base)

  decimal = round(decimal*base**( -digitPosition  + digits - 1.0))

  hasPrintedPoint = False

  # Print leading zeros.
  if digitPosition < 0.0:
    string = appendCharacter(string, '0')
    string = appendCharacter(string, '.')
    hasPrintedPoint = True
    i = 0.0
    while i <  -digitPosition  - 1.0:
      string = appendCharacter(string, '0')
      i = i + 1.0
    

  # Print number.
  i = 0.0
  while i < digits:
    d = floor(decimal/base**(digits - i - 1.0))
    if  not hasPrintedPoint  and digitPosition - i + 1.0 == 0.0:
      if decimal != 0.0:
        string = appendCharacter(string, '.')
      hasPrintedPoint = True
    if decimal == 0.0 and hasPrintedPoint:
      pass
    else:
      string = appendCharacter(string, getSingleDigitFromNumber(d, base))
    decimal = decimal - d*base**(digits - i - 1.0)
    i = i + 1.0
  

  # Print trailing zeros.
  i = 0.0
  while i < digitPosition - digits + 1.0:
    string = appendCharacter(string, '0')
    i = i + 1.0
  

  # Done
  return string

def getDigits(base):
  t = 10.0**15.0
  return floor(log10(t)/log10(base))

def getDigitPosition(decimal, base):
  power = ceil(log10(decimal)/log10(base))

  t = decimal*base**( -power )
  if t < base and t >= 1.0:
    pass
  elif t >= base:
    power = power + 1.0
  elif t < 1.0:
    power = power - 1.0
  return power

def getSingleDigitFromNumber(c, base):
  numberTable = getNumberTable()

  if c > base - 1.0:
    retc = '?'
  else:
    retc = numberTable[int(c)]

  return retc

def getNumberTable():
  numberTable =  [None]*int(16.0)
  numberTable[int(0.0)] = '0'
  numberTable[int(1.0)] = '1'
  numberTable[int(2.0)] = '2'
  numberTable[int(3.0)] = '3'
  numberTable[int(4.0)] = '4'
  numberTable[int(5.0)] = '5'
  numberTable[int(6.0)] = '6'
  numberTable[int(7.0)] = '7'
  numberTable[int(8.0)] = '8'
  numberTable[int(9.0)] = '9'
  numberTable[int(10.0)] = 'A'
  numberTable[int(11.0)] = 'B'
  numberTable[int(12.0)] = 'C'
  numberTable[int(13.0)] = 'D'
  numberTable[int(14.0)] = 'E'
  numberTable[int(15.0)] = 'F'
  return numberTable

def stringToDecimal(string):
  return stringToDecimalForBase(string, 10.0)

def stringToDecimalForBase(string, base):
  stringToDecimalResult = StringToDecimalResult()
  stringToDecimalResult.success = True
  i = 0.0
  isPositive = True
  beforeDecimalPoint = 0.0
  afterDecimalPoint = 0.0
  n = 0.0
  validCharacters = 0.0

  if base >= 2.0 and base <= 16.0:
    j = 0.0
    while j < len(string):
      c = string[int(j)]
      if isNumber(c, base) or c == '.' or c == '-':
        validCharacters = validCharacters + 1.0
      j = j + 1.0
    
    if validCharacters == len(string):
      if len(string) > 0.0:
        c = string[int(i)]
        if c == '-':
          isPositive = False
          i = i + 1.0
        if i < len(string):
          c = string[int(i)]
          if isNumber(c, base):
            while isNumber(c, base) and (i < len(string)):
              beforeDecimalPoint = beforeDecimalPoint + 1.0
              i = i + 1.0
              if i < len(string):
                c = string[int(i)]
            
            if i < len(string):
              c = string[int(i)]
              if c == '.':
                i = i + 1.0
                if i < len(string):
                  c = string[int(i)]
                  while isNumber(c, base) and (i < len(string)):
                    afterDecimalPoint = afterDecimalPoint + 1.0
                    i = i + 1.0
                    if i < len(string):
                      c = string[int(i)]
                  
                else:
                  stringToDecimalResult.success = False
                  stringToDecimalResult.feilmelding = "Number must have digits after the decimal point."
          else:
            stringToDecimalResult.success = False
            stringToDecimalResult.feilmelding = "Number must start with digits (for negative numbers, after the optional negative sign)."
        if stringToDecimalResult.success != False:
          i = 0.0
          if  not isPositive :
            i = 1.0
          j = 0.0
          while j < beforeDecimalPoint:
            c = string[int(i)]
            i = i + 1.0
            d = getDecimalFromSingleDecimalDigit(c, base)
            n = n + d*base**(beforeDecimalPoint - j - 1.0)
            j = j + 1.0
          
          if afterDecimalPoint > 0.0:
            i = i + 1.0
            j = 0.0
            while j < afterDecimalPoint:
              c = string[int(i)]
              i = i + 1.0
              d = getDecimalFromSingleDecimalDigit(c, base)
              n = n + d*base**(0.0 - j - 1.0)
              j = j + 1.0
            
          if  not isPositive :
            n =  -n 
          stringToDecimalResult.result = n
          stringToDecimalResult.success = True
      else:
        stringToDecimalResult.success = False
        stringToDecimalResult.feilmelding = "String has no content."
    else:
      stringToDecimalResult.success = False
      stringToDecimalResult.feilmelding = "String contains invalid character."
  else:
    stringToDecimalResult.success = False
    stringToDecimalResult.feilmelding = "Base must be from 2 to 16."

  return stringToDecimalResult

def getDecimalFromSingleDecimalDigit(c, base):
  numberTable = getNumberTable()
  position = 0.0

  i = 0.0
  while i < base:
    if numberTable[int(i)] == c:
      position = i
    i = i + 1.0
  

  return position

def isNumber(c, base):
  numberTable = getNumberTable()
  found = False

  i = 0.0
  while i < base:
    if numberTable[int(i)] == c:
      found = True
    i = i + 1.0
  

  return found

def assertFalse(b, failures):
  if b:
    failures.doubleValue = failures.doubleValue + 1.0

def assertTrue(b, failures):
  if  not b :
    failures.doubleValue = failures.doubleValue + 1.0

def assertEquals(a, b, failures):
  if a != b:
    failures.doubleValue = failures.doubleValue + 1.0

def assertStringEquals(a, b, failures):
  if  not stringsEqual(a, b) :
    failures.doubleValue = failures.doubleValue + 1.0

def stringToNumberArray(string):
  array =  [None]*int(len(string))

  i = 0.0
  while i < len(string):
    array[int(i)] = ord(string[int(i)])
    i = i + 1.0
  
  return array

def numberArrayToString(array):
  string =  [None]*int(len(array))

  i = 0.0
  while i < len(array):
    string[int(i)] = chr(int(array[int(i)]))
    i = i + 1.0
  
  return string

def stringsEqual(data1, data2):
  equal = False
  if len(data1) == len(data2):
    nrEqual = 0.0
    i = 0.0
    while i < len(data1):
      if data1[int(i)] == data2[int(i)]:
        nrEqual = nrEqual + 1.0
      i = i + 1.0
    
    if nrEqual == len(data1):
      equal = True
  else:
    equal = False

  return equal

def numberArraysEqual(data1, data2):
  equal = False
  if len(data1) == len(data2):
    nrEqual = 0.0
    i = 0.0
    while i < len(data1):
      if data1[int(i)] == data2[int(i)]:
        nrEqual = nrEqual + 1.0
      i = i + 1.0
    
    if nrEqual == len(data1):
      equal = True
  else:
    equal = False

  return equal

def substring(string, fromx, to):
  n =  [None]*int(to - fromx)

  i = fromx
  while i < to:
    n[int(i - fromx)] = string[int(i)]
    i = i + 1.0
  

  return n

def appendString(string, s):
  newString =  [None]*int(len(string) + len(s))

  i = 0.0
  while i < len(string):
    newString[int(i)] = string[int(i)]
    i = i + 1.0
  

  i = 0.0
  while i < len(s):
    newString[int(len(string) + i)] = s[int(i)]
    i = i + 1.0
  

  del(string)

  return newString

def appendCharacter(string, c):
  newString =  [None]*int(len(string) + 1.0)

  i = 0.0
  while i < len(string):
    newString[int(i)] = string[int(i)]
    i = i + 1.0
  

  newString[int(len(string))] = c

  del(string)

  return newString

def split(toSplit, splitBy):
  splitt =  [None]*int(0.0)

  next =  [None]*int(0.0)
  i = 0.0
  while i < len(toSplit):
    c = toSplit[int(i)]
    if c == splitBy:
      n = StringReference()
      n.string = next
      splitt = addString(splitt, n)
      next =  [None]*int(0.0)
    else:
      next = appendCharacter(next, c)
    i = i + 1.0
  

  if len(next) > 0.0:
    n = StringReference()
    n.string = next
    splitt = addString(splitt, n)

  return splitt

class BooleanReference:
  booleanValue = None

class DoubleReference:
  doubleValue = None

class StringReference:
  string = None

class DecimalListRef:
  list = None

class StringListRef:
  list = None

def addDecimal(list, a):
  newlist =  [None]*int(len(list) + 1.0)
  i = 0.0
  while i < len(list):
    newlist[int(i)] = list[int(i)]
    i = i + 1.0
  
  newlist[int(len(list))] = a
		
  del(list)
		
  return newlist

def addDecimalRef(list, i):
  list.list = addDecimal(list.list, i)

def removeDecimal(list, n):
  newlist =  [None]*int(len(list) - 1.0)

  i = 0.0
  while i < len(list):
    if i < n:
      newlist[int(i)] = list[int(i)]
    if i > n:
      newlist[int(i - 1.0)] = list[int(i)]
    i = i + 1.0
  
		
  del(list)
		
  return newlist

def getDecimalRef(list, i):
  return list.list[int(i)]

def removeDecimalRef(list, i):
  list.list = removeDecimal(list.list, i)

def addString(list, a):
  newlist =  [None]*int(len(list) + 1.0)

  i = 0.0
  while i < len(list):
    newlist[int(i)] = list[int(i)]
    i = i + 1.0
  
  newlist[int(len(list))] = a
		
  del(list)
		
  return newlist

def addStringRef(list, i):
  list.list = addString(list.list, i)

def removeString(list, n):
  newlist =  [None]*int(len(list) - 1.0)

  i = 0.0
  while i < len(list):
    if i < n:
      newlist[int(i)] = list[int(i)]
    if i > n:
      newlist[int(i - 1.0)] = list[int(i)]
    i = i + 1.0
  
		
  del(list)
		
  return newlist

def getStringRef(list, i):
  return list.list[int(i)]

def removeStringRef(list, i):
  list.list = removeString(list.list, i)



print(test())