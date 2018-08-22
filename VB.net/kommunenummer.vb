Imports System
Imports System.Math

Public Structure Success
	Public success As Boolean
	Public feilmelding As Char ()
End Structure

Public Structure StringToDecimalResult
	Public result As Double
	Public feilmelding As Char ()
	Public success As Boolean
End Structure

Public Structure BooleanReference
	Public booleanValue As Boolean
End Structure

Public Structure DoubleReference
	Public doubleValue As Double
End Structure

Public Structure StringReference
	Public stringxx As Char ()
End Structure

Public Structure DecimalListRef
	Public list As Double ()
End Structure

Public Structure StringListRef
	Public list As StringReference ()
End Structure

Module kommunenummer
	Public Function createStringReference(ByRef stringxx As Char ()) As StringReference
		Dim stringReference As StringReference

		stringReference = New StringReference()
		stringReference.stringxx = stringxx
		Return stringReference
	End Function


	Public Function lagGyldigReversTabell(ByRef nummerliste As Double ()) As Boolean ()
		Dim i As Double
		Dim maxnummer As Double
		Dim inverse As Boolean ()

		maxnummer = 0
		i = 0
		While i < nummerliste.Length
			maxnummer = Max(maxnummer, nummerliste(i))
			i = i + 1
		End While

		inverse = New Boolean (maxnummer + 1 - 1){}

		i = 0
		While i < maxnummer
			inverse(i) = false
			i = i + 1
		End While

		i = 0
		While i < nummerliste.Length
			inverse(nummerliste(i)) = true
			i = i + 1
		End While

		Return inverse
	End Function


	Public Function hentKommunenavnFraNummer(ByRef kommunenummer As Char (), ByRef success As Success) As Char ()
		Dim kommunenavn As Char ()
		Dim kommunenavnListe As StringReference ()
		Dim nr As Double
		Dim stringToDecimalResult As StringToDecimalResult

		kommunenavn = New Char (0 - 1){}

		If erGyldigKommunenummer(kommunenummer)
			kommunenavnListe = hentKommunenavn()
			stringToDecimalResult = stringToDecimalForBase(kommunenummer, 10)
			If stringToDecimalResult.success
				nr = stringToDecimalResult.result
				kommunenavn = kommunenavnListe(nr).stringxx
				success.success = true
			Else
				success.feilmelding = "Kommunenummer var ikke et gyldig tall.".ToCharArray()
				success.success = false
			End If
		Else
			success.success = false
			success.feilmelding = "Kommunenummer er ikke gyldig.".ToCharArray()
		End If

		Return kommunenavn
	End Function


	Public Function erGyldigKommunenummer(ByRef kommunenummer As Char ()) As Boolean
		Dim gyldig As Boolean
		Dim nr As Double
		Dim gyldigKommunetabell As Boolean ()

		If kommunenummer.Length = 4
			nr = stringToDecimalForBase(kommunenummer, 10).result
			If nr >= 101 And nr <= 2030 And erHelttall(nr)
				gyldigKommunetabell = hentGyldigKommunetabell()
				gyldig = gyldigKommunetabell(nr)
			Else
				gyldig = false
			End If
		Else
			gyldig = false
		End If

		Return gyldig
	End Function


	Public Function erHelttall(nr As Double) As Boolean

		Return (nr Mod 1) = 0
	End Function


	Public Function hentGyldigKommunetabell() As Boolean ()
		Dim nummerliste As Double ()

		nummerliste = hentGyldigeKommunenummer()
		Return lagGyldigReversTabell(nummerliste)
	End Function


	Public Function hentKommunenavn() As StringReference ()
		Dim kommunenavn As StringReference ()

		kommunenavn = New StringReference (2100 - 1){}

		kommunenavn(101) = createStringReference("Halden".ToCharArray())
		kommunenavn(104) = createStringReference("Moss".ToCharArray())
		kommunenavn(105) = createStringReference("Sarpsborg".ToCharArray())
		kommunenavn(106) = createStringReference("Fredrikstad".ToCharArray())
		kommunenavn(111) = createStringReference("Hvaler".ToCharArray())
		kommunenavn(118) = createStringReference("Aremark".ToCharArray())
		kommunenavn(119) = createStringReference("Marker".ToCharArray())
		kommunenavn(121) = createStringReference("R\u00f8mskog".ToCharArray())
		kommunenavn(122) = createStringReference("Tr\u00f8gstad".ToCharArray())
		kommunenavn(123) = createStringReference("Spydeberg".ToCharArray())
		kommunenavn(124) = createStringReference("Askim".ToCharArray())
		kommunenavn(125) = createStringReference("Eidsberg".ToCharArray())
		kommunenavn(127) = createStringReference("Skiptvet".ToCharArray())
		kommunenavn(128) = createStringReference("Rakkestad".ToCharArray())
		kommunenavn(135) = createStringReference("R\u00e5de".ToCharArray())
		kommunenavn(136) = createStringReference("Rygge".ToCharArray())
		kommunenavn(137) = createStringReference("V\u00e5ler".ToCharArray())
		kommunenavn(138) = createStringReference("Hob\u00f8l".ToCharArray())
		kommunenavn(211) = createStringReference("Vestby".ToCharArray())
		kommunenavn(213) = createStringReference("Ski".ToCharArray())
		kommunenavn(214) = createStringReference("\u00c5s".ToCharArray())
		kommunenavn(215) = createStringReference("Frogn".ToCharArray())
		kommunenavn(216) = createStringReference("Nesodden".ToCharArray())
		kommunenavn(217) = createStringReference("Oppeg\u00e5rd".ToCharArray())
		kommunenavn(219) = createStringReference("B\u00e6rum".ToCharArray())
		kommunenavn(220) = createStringReference("Asker".ToCharArray())
		kommunenavn(221) = createStringReference("Aurskog-H\u00f8land".ToCharArray())
		kommunenavn(226) = createStringReference("S\u00f8rum".ToCharArray())
		kommunenavn(227) = createStringReference("Fet".ToCharArray())
		kommunenavn(228) = createStringReference("R\u00e6lingen".ToCharArray())
		kommunenavn(229) = createStringReference("Enebakk".ToCharArray())
		kommunenavn(230) = createStringReference("L\u00f8renskog".ToCharArray())
		kommunenavn(231) = createStringReference("Skedsmo".ToCharArray())
		kommunenavn(233) = createStringReference("Nittedal".ToCharArray())
		kommunenavn(234) = createStringReference("Gjerdrum".ToCharArray())
		kommunenavn(235) = createStringReference("Ullensaker".ToCharArray())
		kommunenavn(236) = createStringReference("Nes".ToCharArray())
		kommunenavn(237) = createStringReference("Eidsvoll".ToCharArray())
		kommunenavn(238) = createStringReference("Nannestad".ToCharArray())
		kommunenavn(239) = createStringReference("Hurdal".ToCharArray())
		kommunenavn(301) = createStringReference("Oslo".ToCharArray())
		kommunenavn(402) = createStringReference("Kongsvinger".ToCharArray())
		kommunenavn(403) = createStringReference("Hamar".ToCharArray())
		kommunenavn(412) = createStringReference("Ringsaker".ToCharArray())
		kommunenavn(415) = createStringReference("L\u00f8ten".ToCharArray())
		kommunenavn(417) = createStringReference("Stange".ToCharArray())
		kommunenavn(418) = createStringReference("Nord-Odal".ToCharArray())
		kommunenavn(419) = createStringReference("S\u00f8r-Odal".ToCharArray())
		kommunenavn(420) = createStringReference("Eidskog".ToCharArray())
		kommunenavn(423) = createStringReference("Grue".ToCharArray())
		kommunenavn(425) = createStringReference("\u00c5snes".ToCharArray())
		kommunenavn(426) = createStringReference("V\u00e5ler".ToCharArray())
		kommunenavn(427) = createStringReference("Elverum".ToCharArray())
		kommunenavn(428) = createStringReference("Trysil".ToCharArray())
		kommunenavn(429) = createStringReference("\u00c5mot".ToCharArray())
		kommunenavn(430) = createStringReference("Stor-Elvdal".ToCharArray())
		kommunenavn(432) = createStringReference("Rendalen".ToCharArray())
		kommunenavn(434) = createStringReference("Engerdal".ToCharArray())
		kommunenavn(436) = createStringReference("Tolga".ToCharArray())
		kommunenavn(437) = createStringReference("Tynset".ToCharArray())
		kommunenavn(438) = createStringReference("Alvdal".ToCharArray())
		kommunenavn(439) = createStringReference("Folldal".ToCharArray())
		kommunenavn(441) = createStringReference("Os".ToCharArray())
		kommunenavn(501) = createStringReference("Lillehammer".ToCharArray())
		kommunenavn(502) = createStringReference("Gj\u00f8vik".ToCharArray())
		kommunenavn(511) = createStringReference("Dovre".ToCharArray())
		kommunenavn(512) = createStringReference("Lesja".ToCharArray())
		kommunenavn(513) = createStringReference("Skj\u00e5k".ToCharArray())
		kommunenavn(514) = createStringReference("Lom".ToCharArray())
		kommunenavn(515) = createStringReference("V\u00e5g\u00e5".ToCharArray())
		kommunenavn(516) = createStringReference("Nord-Fron".ToCharArray())
		kommunenavn(517) = createStringReference("Sel".ToCharArray())
		kommunenavn(519) = createStringReference("S\u00f8r-Fron".ToCharArray())
		kommunenavn(520) = createStringReference("Ringebu".ToCharArray())
		kommunenavn(521) = createStringReference("\u00d8yer".ToCharArray())
		kommunenavn(522) = createStringReference("Gausdal".ToCharArray())
		kommunenavn(528) = createStringReference("\u00d8stre Toten".ToCharArray())
		kommunenavn(529) = createStringReference("Vestre Toten".ToCharArray())
		kommunenavn(532) = createStringReference("Jevnaker".ToCharArray())
		kommunenavn(533) = createStringReference("Lunner".ToCharArray())
		kommunenavn(534) = createStringReference("Gran".ToCharArray())
		kommunenavn(536) = createStringReference("S\u00f8ndre Land".ToCharArray())
		kommunenavn(538) = createStringReference("Nordre Land".ToCharArray())
		kommunenavn(540) = createStringReference("S\u00f8r-Aurdal".ToCharArray())
		kommunenavn(541) = createStringReference("Etnedal".ToCharArray())
		kommunenavn(542) = createStringReference("Nord-Aurdal".ToCharArray())
		kommunenavn(543) = createStringReference("Vestre Slidre".ToCharArray())
		kommunenavn(544) = createStringReference("\u00d8ystre Slidre".ToCharArray())
		kommunenavn(545) = createStringReference("Vang".ToCharArray())
		kommunenavn(602) = createStringReference("Drammen".ToCharArray())
		kommunenavn(604) = createStringReference("Kongsberg".ToCharArray())
		kommunenavn(605) = createStringReference("Ringerike".ToCharArray())
		kommunenavn(612) = createStringReference("Hole".ToCharArray())
		kommunenavn(615) = createStringReference("Fl\u00e5".ToCharArray())
		kommunenavn(616) = createStringReference("Nes".ToCharArray())
		kommunenavn(617) = createStringReference("Gol".ToCharArray())
		kommunenavn(618) = createStringReference("Hemsedal".ToCharArray())
		kommunenavn(619) = createStringReference("\u00c5l".ToCharArray())
		kommunenavn(620) = createStringReference("Hol".ToCharArray())
		kommunenavn(621) = createStringReference("Sigdal".ToCharArray())
		kommunenavn(622) = createStringReference("Kr\u00f8dsherad".ToCharArray())
		kommunenavn(623) = createStringReference("Modum".ToCharArray())
		kommunenavn(624) = createStringReference("\u00d8vre Eiker".ToCharArray())
		kommunenavn(625) = createStringReference("Nedre Eiker".ToCharArray())
		kommunenavn(626) = createStringReference("Lier".ToCharArray())
		kommunenavn(627) = createStringReference("R\u00f8yken".ToCharArray())
		kommunenavn(628) = createStringReference("Hurum".ToCharArray())
		kommunenavn(631) = createStringReference("Flesberg".ToCharArray())
		kommunenavn(632) = createStringReference("Rollag".ToCharArray())
		kommunenavn(633) = createStringReference("Nore og Uvdal".ToCharArray())
		kommunenavn(701) = createStringReference("Horten".ToCharArray())
		kommunenavn(702) = createStringReference("Holmestrand".ToCharArray())
		kommunenavn(704) = createStringReference("T\u00f8nsberg".ToCharArray())
		kommunenavn(709) = createStringReference("Larvik".ToCharArray())
		kommunenavn(710) = createStringReference("Sandefjord".ToCharArray())
		kommunenavn(711) = createStringReference("Svelvik".ToCharArray())
		kommunenavn(713) = createStringReference("Sande".ToCharArray())
		kommunenavn(714) = createStringReference("Hof".ToCharArray())
		kommunenavn(716) = createStringReference("Re".ToCharArray())
		kommunenavn(722) = createStringReference("N\u00f8tter\u00f8y".ToCharArray())
		kommunenavn(723) = createStringReference("Tj\u00f8me".ToCharArray())
		kommunenavn(728) = createStringReference("Lardal".ToCharArray())
		kommunenavn(805) = createStringReference("Porsgrunn".ToCharArray())
		kommunenavn(806) = createStringReference("Skien".ToCharArray())
		kommunenavn(807) = createStringReference("Notodden".ToCharArray())
		kommunenavn(811) = createStringReference("Siljan".ToCharArray())
		kommunenavn(814) = createStringReference("Bamble".ToCharArray())
		kommunenavn(815) = createStringReference("Krager\u00f8".ToCharArray())
		kommunenavn(817) = createStringReference("Drangedal".ToCharArray())
		kommunenavn(819) = createStringReference("Nome".ToCharArray())
		kommunenavn(821) = createStringReference("B\u00f8".ToCharArray())
		kommunenavn(822) = createStringReference("Sauherad".ToCharArray())
		kommunenavn(826) = createStringReference("Tinn".ToCharArray())
		kommunenavn(827) = createStringReference("Hjartdal".ToCharArray())
		kommunenavn(828) = createStringReference("Seljord".ToCharArray())
		kommunenavn(829) = createStringReference("Kviteseid".ToCharArray())
		kommunenavn(830) = createStringReference("Nissedal".ToCharArray())
		kommunenavn(831) = createStringReference("Fyresdal".ToCharArray())
		kommunenavn(833) = createStringReference("Tokke".ToCharArray())
		kommunenavn(834) = createStringReference("Vinje".ToCharArray())
		kommunenavn(901) = createStringReference("Ris\u00f8r".ToCharArray())
		kommunenavn(904) = createStringReference("Grimstad".ToCharArray())
		kommunenavn(906) = createStringReference("Arendal".ToCharArray())
		kommunenavn(911) = createStringReference("Gjerstad".ToCharArray())
		kommunenavn(912) = createStringReference("Veg\u00e5rshei".ToCharArray())
		kommunenavn(914) = createStringReference("Tvedestrand".ToCharArray())
		kommunenavn(919) = createStringReference("Froland".ToCharArray())
		kommunenavn(926) = createStringReference("Lillesand".ToCharArray())
		kommunenavn(928) = createStringReference("Birkenes".ToCharArray())
		kommunenavn(929) = createStringReference("\u00c5mli".ToCharArray())
		kommunenavn(935) = createStringReference("Iveland".ToCharArray())
		kommunenavn(937) = createStringReference("Evje og Hornnes".ToCharArray())
		kommunenavn(938) = createStringReference("Bygland".ToCharArray())
		kommunenavn(940) = createStringReference("Valle".ToCharArray())
		kommunenavn(941) = createStringReference("Bykle".ToCharArray())
		kommunenavn(1001) = createStringReference("Kristiansand".ToCharArray())
		kommunenavn(1002) = createStringReference("Mandal".ToCharArray())
		kommunenavn(1003) = createStringReference("Farsund".ToCharArray())
		kommunenavn(1004) = createStringReference("Flekkefjord".ToCharArray())
		kommunenavn(1014) = createStringReference("Vennesla".ToCharArray())
		kommunenavn(1017) = createStringReference("Songdalen".ToCharArray())
		kommunenavn(1018) = createStringReference("S\u00f8gne".ToCharArray())
		kommunenavn(1021) = createStringReference("Marnardal".ToCharArray())
		kommunenavn(1026) = createStringReference("\u00c5seral".ToCharArray())
		kommunenavn(1027) = createStringReference("Audnedal".ToCharArray())
		kommunenavn(1029) = createStringReference("Lindesnes".ToCharArray())
		kommunenavn(1032) = createStringReference("Lyngdal".ToCharArray())
		kommunenavn(1034) = createStringReference("H\u00e6gebostad".ToCharArray())
		kommunenavn(1037) = createStringReference("Kvinesdal".ToCharArray())
		kommunenavn(1046) = createStringReference("Sirdal".ToCharArray())
		kommunenavn(1101) = createStringReference("Eigersund".ToCharArray())
		kommunenavn(1102) = createStringReference("Sandnes".ToCharArray())
		kommunenavn(1103) = createStringReference("Stavanger".ToCharArray())
		kommunenavn(1106) = createStringReference("Haugesund".ToCharArray())
		kommunenavn(1111) = createStringReference("Sokndal".ToCharArray())
		kommunenavn(1112) = createStringReference("Lund".ToCharArray())
		kommunenavn(1114) = createStringReference("Bjerkreim".ToCharArray())
		kommunenavn(1119) = createStringReference("H\u00e5".ToCharArray())
		kommunenavn(1120) = createStringReference("Klepp".ToCharArray())
		kommunenavn(1121) = createStringReference("Time".ToCharArray())
		kommunenavn(1122) = createStringReference("Gjesdal".ToCharArray())
		kommunenavn(1124) = createStringReference("Sola".ToCharArray())
		kommunenavn(1127) = createStringReference("Randaberg".ToCharArray())
		kommunenavn(1129) = createStringReference("Forsand".ToCharArray())
		kommunenavn(1130) = createStringReference("Strand".ToCharArray())
		kommunenavn(1133) = createStringReference("Hjelmeland".ToCharArray())
		kommunenavn(1134) = createStringReference("Suldal".ToCharArray())
		kommunenavn(1135) = createStringReference("Sauda".ToCharArray())
		kommunenavn(1141) = createStringReference("Finn\u00f8y".ToCharArray())
		kommunenavn(1142) = createStringReference("Rennes\u00f8y".ToCharArray())
		kommunenavn(1144) = createStringReference("Kvits\u00f8y".ToCharArray())
		kommunenavn(1145) = createStringReference("Bokn".ToCharArray())
		kommunenavn(1146) = createStringReference("Tysv\u00e6r".ToCharArray())
		kommunenavn(1149) = createStringReference("Karm\u00f8y".ToCharArray())
		kommunenavn(1151) = createStringReference("Utsira".ToCharArray())
		kommunenavn(1160) = createStringReference("Vindafjord".ToCharArray())
		kommunenavn(1201) = createStringReference("Bergen".ToCharArray())
		kommunenavn(1211) = createStringReference("Etne".ToCharArray())
		kommunenavn(1216) = createStringReference("Sveio".ToCharArray())
		kommunenavn(1219) = createStringReference("B\u00f8mlo".ToCharArray())
		kommunenavn(1221) = createStringReference("Stord".ToCharArray())
		kommunenavn(1222) = createStringReference("Fitjar".ToCharArray())
		kommunenavn(1223) = createStringReference("Tysnes".ToCharArray())
		kommunenavn(1224) = createStringReference("Kvinnherad".ToCharArray())
		kommunenavn(1227) = createStringReference("Jondal".ToCharArray())
		kommunenavn(1228) = createStringReference("Odda".ToCharArray())
		kommunenavn(1231) = createStringReference("Ullensvang".ToCharArray())
		kommunenavn(1232) = createStringReference("Eidfjord".ToCharArray())
		kommunenavn(1233) = createStringReference("Ulvik".ToCharArray())
		kommunenavn(1234) = createStringReference("Granvin".ToCharArray())
		kommunenavn(1235) = createStringReference("Voss".ToCharArray())
		kommunenavn(1238) = createStringReference("Kvam".ToCharArray())
		kommunenavn(1241) = createStringReference("Fusa".ToCharArray())
		kommunenavn(1242) = createStringReference("Samnanger".ToCharArray())
		kommunenavn(1243) = createStringReference("Os".ToCharArray())
		kommunenavn(1244) = createStringReference("Austevoll".ToCharArray())
		kommunenavn(1245) = createStringReference("Sund".ToCharArray())
		kommunenavn(1246) = createStringReference("Fjell".ToCharArray())
		kommunenavn(1247) = createStringReference("Ask\u00f8y".ToCharArray())
		kommunenavn(1251) = createStringReference("Vaksdal".ToCharArray())
		kommunenavn(1252) = createStringReference("Modalen".ToCharArray())
		kommunenavn(1253) = createStringReference("Oster\u00f8y".ToCharArray())
		kommunenavn(1256) = createStringReference("Meland".ToCharArray())
		kommunenavn(1259) = createStringReference("\u00d8ygarden".ToCharArray())
		kommunenavn(1260) = createStringReference("Rad\u00f8y".ToCharArray())
		kommunenavn(1263) = createStringReference("Lind\u00e5s".ToCharArray())
		kommunenavn(1264) = createStringReference("Austrheim".ToCharArray())
		kommunenavn(1265) = createStringReference("Fedje".ToCharArray())
		kommunenavn(1266) = createStringReference("Masfjorden".ToCharArray())
		kommunenavn(1401) = createStringReference("Flora".ToCharArray())
		kommunenavn(1411) = createStringReference("Gulen".ToCharArray())
		kommunenavn(1412) = createStringReference("Solund".ToCharArray())
		kommunenavn(1413) = createStringReference("Hyllestad".ToCharArray())
		kommunenavn(1416) = createStringReference("H\u00f8yanger".ToCharArray())
		kommunenavn(1417) = createStringReference("Vik".ToCharArray())
		kommunenavn(1418) = createStringReference("Balestrand".ToCharArray())
		kommunenavn(1419) = createStringReference("Leikanger".ToCharArray())
		kommunenavn(1420) = createStringReference("Sogndal".ToCharArray())
		kommunenavn(1421) = createStringReference("Aurland".ToCharArray())
		kommunenavn(1422) = createStringReference("L\u00e6rdal".ToCharArray())
		kommunenavn(1424) = createStringReference("\u00c5rdal".ToCharArray())
		kommunenavn(1426) = createStringReference("Luster".ToCharArray())
		kommunenavn(1428) = createStringReference("Askvoll".ToCharArray())
		kommunenavn(1429) = createStringReference("Fjaler".ToCharArray())
		kommunenavn(1430) = createStringReference("Gaular".ToCharArray())
		kommunenavn(1431) = createStringReference("J\u00f8lster".ToCharArray())
		kommunenavn(1432) = createStringReference("F\u00f8rde".ToCharArray())
		kommunenavn(1433) = createStringReference("Naustdal".ToCharArray())
		kommunenavn(1438) = createStringReference("Bremanger".ToCharArray())
		kommunenavn(1439) = createStringReference("V\u00e5gs\u00f8y".ToCharArray())
		kommunenavn(1441) = createStringReference("Selje".ToCharArray())
		kommunenavn(1443) = createStringReference("Eid".ToCharArray())
		kommunenavn(1444) = createStringReference("Hornindal".ToCharArray())
		kommunenavn(1445) = createStringReference("Gloppen".ToCharArray())
		kommunenavn(1449) = createStringReference("Stryn".ToCharArray())
		kommunenavn(1502) = createStringReference("Molde".ToCharArray())
		kommunenavn(1504) = createStringReference("\u00c5lesund".ToCharArray())
		kommunenavn(1505) = createStringReference("Kristiansund".ToCharArray())
		kommunenavn(1511) = createStringReference("Vanylven".ToCharArray())
		kommunenavn(1514) = createStringReference("Sande".ToCharArray())
		kommunenavn(1515) = createStringReference("Her\u00f8y".ToCharArray())
		kommunenavn(1516) = createStringReference("Ulstein".ToCharArray())
		kommunenavn(1517) = createStringReference("Hareid".ToCharArray())
		kommunenavn(1519) = createStringReference("Volda".ToCharArray())
		kommunenavn(1520) = createStringReference("\u00d8rsta".ToCharArray())
		kommunenavn(1523) = createStringReference("\u00d8rskog".ToCharArray())
		kommunenavn(1524) = createStringReference("Norddal".ToCharArray())
		kommunenavn(1525) = createStringReference("Stranda".ToCharArray())
		kommunenavn(1526) = createStringReference("Stordal".ToCharArray())
		kommunenavn(1528) = createStringReference("Sykkylven".ToCharArray())
		kommunenavn(1529) = createStringReference("Skodje".ToCharArray())
		kommunenavn(1531) = createStringReference("Sula".ToCharArray())
		kommunenavn(1532) = createStringReference("Giske".ToCharArray())
		kommunenavn(1534) = createStringReference("Haram".ToCharArray())
		kommunenavn(1535) = createStringReference("Vestnes".ToCharArray())
		kommunenavn(1539) = createStringReference("Rauma".ToCharArray())
		kommunenavn(1543) = createStringReference("Nesset".ToCharArray())
		kommunenavn(1545) = createStringReference("Midsund".ToCharArray())
		kommunenavn(1546) = createStringReference("Sand\u00f8y".ToCharArray())
		kommunenavn(1547) = createStringReference("Aukra".ToCharArray())
		kommunenavn(1548) = createStringReference("Fr\u00e6na".ToCharArray())
		kommunenavn(1551) = createStringReference("Eide".ToCharArray())
		kommunenavn(1554) = createStringReference("Aver\u00f8y".ToCharArray())
		kommunenavn(1557) = createStringReference("Gjemnes".ToCharArray())
		kommunenavn(1560) = createStringReference("Tingvoll".ToCharArray())
		kommunenavn(1563) = createStringReference("Sunndal".ToCharArray())
		kommunenavn(1566) = createStringReference("Surnadal".ToCharArray())
		kommunenavn(1567) = createStringReference("Rindal".ToCharArray())
		kommunenavn(1571) = createStringReference("Halsa".ToCharArray())
		kommunenavn(1573) = createStringReference("Sm\u00f8la".ToCharArray())
		kommunenavn(1576) = createStringReference("Aure".ToCharArray())
		kommunenavn(1601) = createStringReference("Trondheim".ToCharArray())
		kommunenavn(1612) = createStringReference("Hemne".ToCharArray())
		kommunenavn(1613) = createStringReference("Snillfjord".ToCharArray())
		kommunenavn(1617) = createStringReference("Hitra".ToCharArray())
		kommunenavn(1620) = createStringReference("Fr\u00f8ya".ToCharArray())
		kommunenavn(1621) = createStringReference("\u00d8rland".ToCharArray())
		kommunenavn(1622) = createStringReference("Agdenes".ToCharArray())
		kommunenavn(1624) = createStringReference("Rissa".ToCharArray())
		kommunenavn(1627) = createStringReference("Bjugn".ToCharArray())
		kommunenavn(1630) = createStringReference("\u00c5fjord".ToCharArray())
		kommunenavn(1632) = createStringReference("Roan".ToCharArray())
		kommunenavn(1633) = createStringReference("Osen".ToCharArray())
		kommunenavn(1634) = createStringReference("Oppdal".ToCharArray())
		kommunenavn(1635) = createStringReference("Rennebu".ToCharArray())
		kommunenavn(1636) = createStringReference("Meldal".ToCharArray())
		kommunenavn(1638) = createStringReference("Orkdal".ToCharArray())
		kommunenavn(1640) = createStringReference("R\u00f8ros".ToCharArray())
		kommunenavn(1644) = createStringReference("Holt\u00e5len".ToCharArray())
		kommunenavn(1648) = createStringReference("Midtre Gauldal".ToCharArray())
		kommunenavn(1653) = createStringReference("Melhus".ToCharArray())
		kommunenavn(1657) = createStringReference("Skaun".ToCharArray())
		kommunenavn(1662) = createStringReference("Kl\u00e6bu".ToCharArray())
		kommunenavn(1663) = createStringReference("Malvik".ToCharArray())
		kommunenavn(1664) = createStringReference("Selbu".ToCharArray())
		kommunenavn(1665) = createStringReference("Tydal".ToCharArray())
		kommunenavn(1702) = createStringReference("Steinkjer".ToCharArray())
		kommunenavn(1703) = createStringReference("Namsos".ToCharArray())
		kommunenavn(1711) = createStringReference("Mer\u00e5ker".ToCharArray())
		kommunenavn(1714) = createStringReference("Stj\u00f8rdal".ToCharArray())
		kommunenavn(1717) = createStringReference("Frosta".ToCharArray())
		kommunenavn(1718) = createStringReference("Leksvik".ToCharArray())
		kommunenavn(1719) = createStringReference("Levanger".ToCharArray())
		kommunenavn(1721) = createStringReference("Verdal".ToCharArray())
		kommunenavn(1724) = createStringReference("Verran".ToCharArray())
		kommunenavn(1725) = createStringReference("Namdalseid".ToCharArray())
		kommunenavn(1736) = createStringReference("Sn\u00e5ase \u2013 Sn\u00e5sa".ToCharArray())
		kommunenavn(1738) = createStringReference("Lierne".ToCharArray())
		kommunenavn(1739) = createStringReference("Raarvihke \u2013 R\u00f8yrvik".ToCharArray())
		kommunenavn(1740) = createStringReference("Namsskogan".ToCharArray())
		kommunenavn(1742) = createStringReference("Grong".ToCharArray())
		kommunenavn(1743) = createStringReference("H\u00f8ylandet".ToCharArray())
		kommunenavn(1744) = createStringReference("Overhalla".ToCharArray())
		kommunenavn(1748) = createStringReference("Fosnes".ToCharArray())
		kommunenavn(1749) = createStringReference("Flatanger".ToCharArray())
		kommunenavn(1750) = createStringReference("Vikna".ToCharArray())
		kommunenavn(1751) = createStringReference("N\u00e6r\u00f8y".ToCharArray())
		kommunenavn(1755) = createStringReference("Leka".ToCharArray())
		kommunenavn(1756) = createStringReference("Inder\u00f8y".ToCharArray())
		kommunenavn(1804) = createStringReference("Bod\u00f8".ToCharArray())
		kommunenavn(1805) = createStringReference("Narvik".ToCharArray())
		kommunenavn(1811) = createStringReference("Bindal".ToCharArray())
		kommunenavn(1812) = createStringReference("S\u00f8mna".ToCharArray())
		kommunenavn(1813) = createStringReference("Br\u00f8nn\u00f8y".ToCharArray())
		kommunenavn(1815) = createStringReference("Vega".ToCharArray())
		kommunenavn(1816) = createStringReference("Vevelstad".ToCharArray())
		kommunenavn(1818) = createStringReference("Her\u00f8y".ToCharArray())
		kommunenavn(1820) = createStringReference("Alstahaug".ToCharArray())
		kommunenavn(1822) = createStringReference("Leirfjord".ToCharArray())
		kommunenavn(1824) = createStringReference("Vefsn".ToCharArray())
		kommunenavn(1825) = createStringReference("Grane".ToCharArray())
		kommunenavn(1826) = createStringReference("Hattfjelldal".ToCharArray())
		kommunenavn(1827) = createStringReference("D\u00f8nna".ToCharArray())
		kommunenavn(1828) = createStringReference("Nesna".ToCharArray())
		kommunenavn(1832) = createStringReference("Hemnes".ToCharArray())
		kommunenavn(1833) = createStringReference("Rana".ToCharArray())
		kommunenavn(1834) = createStringReference("Lur\u00f8y".ToCharArray())
		kommunenavn(1835) = createStringReference("Tr\u00e6na".ToCharArray())
		kommunenavn(1836) = createStringReference("R\u00f8d\u00f8y".ToCharArray())
		kommunenavn(1837) = createStringReference("Mel\u00f8y".ToCharArray())
		kommunenavn(1838) = createStringReference("Gildesk\u00e5l".ToCharArray())
		kommunenavn(1839) = createStringReference("Beiarn".ToCharArray())
		kommunenavn(1840) = createStringReference("Saltdal".ToCharArray())
		kommunenavn(1841) = createStringReference("Fauske \u2013 Fuossko".ToCharArray())
		kommunenavn(1845) = createStringReference("S\u00f8rfold".ToCharArray())
		kommunenavn(1848) = createStringReference("Steigen".ToCharArray())
		kommunenavn(1849) = createStringReference("Hamar\u00f8y \u2013 H\u00e1bmer".ToCharArray())
		kommunenavn(1850) = createStringReference("Divtasvuodna \u2013 Tysfjord".ToCharArray())
		kommunenavn(1851) = createStringReference("L\u00f8dingen".ToCharArray())
		kommunenavn(1852) = createStringReference("Tjeldsund".ToCharArray())
		kommunenavn(1853) = createStringReference("Evenes".ToCharArray())
		kommunenavn(1854) = createStringReference("Ballangen".ToCharArray())
		kommunenavn(1856) = createStringReference("R\u00f8st".ToCharArray())
		kommunenavn(1857) = createStringReference("V\u00e6r\u00f8y".ToCharArray())
		kommunenavn(1859) = createStringReference("Flakstad".ToCharArray())
		kommunenavn(1860) = createStringReference("Vestv\u00e5g\u00f8y".ToCharArray())
		kommunenavn(1865) = createStringReference("V\u00e5gan".ToCharArray())
		kommunenavn(1866) = createStringReference("Hadsel".ToCharArray())
		kommunenavn(1867) = createStringReference("B\u00f8".ToCharArray())
		kommunenavn(1868) = createStringReference("\u00d8ksnes".ToCharArray())
		kommunenavn(1870) = createStringReference("Sortland \u2013 Suort\u00e1".ToCharArray())
		kommunenavn(1871) = createStringReference("And\u00f8y".ToCharArray())
		kommunenavn(1874) = createStringReference("Moskenes".ToCharArray())
		kommunenavn(1903) = createStringReference("Harstad \u2013 H\u00e1rstt\u00e1k".ToCharArray())
		kommunenavn(1902) = createStringReference("Troms\u00f8".ToCharArray())
		kommunenavn(1911) = createStringReference("Kv\u00e6fjord".ToCharArray())
		kommunenavn(1913) = createStringReference("Sk\u00e5nland".ToCharArray())
		kommunenavn(1917) = createStringReference("Ibestad".ToCharArray())
		kommunenavn(1919) = createStringReference("Gratangen".ToCharArray())
		kommunenavn(1920) = createStringReference("Loab\u00e1k \u2013 Lavangen".ToCharArray())
		kommunenavn(1922) = createStringReference("Bardu".ToCharArray())
		kommunenavn(1923) = createStringReference("Salangen".ToCharArray())
		kommunenavn(1924) = createStringReference("M\u00e5lselv".ToCharArray())
		kommunenavn(1925) = createStringReference("S\u00f8rreisa".ToCharArray())
		kommunenavn(1926) = createStringReference("Dyr\u00f8y".ToCharArray())
		kommunenavn(1927) = createStringReference("Tran\u00f8y".ToCharArray())
		kommunenavn(1928) = createStringReference("Torsken".ToCharArray())
		kommunenavn(1929) = createStringReference("Berg".ToCharArray())
		kommunenavn(1931) = createStringReference("Lenvik".ToCharArray())
		kommunenavn(1933) = createStringReference("Balsfjord".ToCharArray())
		kommunenavn(1936) = createStringReference("Karls\u00f8y".ToCharArray())
		kommunenavn(1938) = createStringReference("Lyngen".ToCharArray())
		kommunenavn(1939) = createStringReference("Storfjord \u2013 Omasvuotna \u2013 Omasvuono".ToCharArray())
		kommunenavn(1940) = createStringReference("G\u00e1ivuotna \u2013 K\u00e5fjord \u2013 Kaivuono".ToCharArray())
		kommunenavn(1941) = createStringReference("Skjerv\u00f8y".ToCharArray())
		kommunenavn(1942) = createStringReference("Nordreisa".ToCharArray())
		kommunenavn(1943) = createStringReference("Kv\u00e6nangen".ToCharArray())
		kommunenavn(2002) = createStringReference("Vard\u00f8".ToCharArray())
		kommunenavn(2003) = createStringReference("Vads\u00f8".ToCharArray())
		kommunenavn(2004) = createStringReference("Hammerfest".ToCharArray())
		kommunenavn(2011) = createStringReference("Guovdageaidnu \u2013 Kautokeino".ToCharArray())
		kommunenavn(2012) = createStringReference("Alta".ToCharArray())
		kommunenavn(2014) = createStringReference("Loppa".ToCharArray())
		kommunenavn(2015) = createStringReference("Hasvik".ToCharArray())
		kommunenavn(2017) = createStringReference("Kvalsund".ToCharArray())
		kommunenavn(2018) = createStringReference("M\u00e5s\u00f8y".ToCharArray())
		kommunenavn(2019) = createStringReference("Nordkapp".ToCharArray())
		kommunenavn(2020) = createStringReference("Porsanger \u2013 Pors\u00e1\u014bgu \u2013 Porsanki".ToCharArray())
		kommunenavn(2021) = createStringReference("K\u00e1r\u00e1\u0161johka \u2013 Karasjok".ToCharArray())
		kommunenavn(2022) = createStringReference("Lebesby".ToCharArray())
		kommunenavn(2023) = createStringReference("Gamvik".ToCharArray())
		kommunenavn(2024) = createStringReference("Berlev\u00e5g".ToCharArray())
		kommunenavn(2025) = createStringReference("Deatnu \u2013 Tana".ToCharArray())
		kommunenavn(2027) = createStringReference("Unj\u00e1rga \u2013 Nesseby".ToCharArray())
		kommunenavn(2028) = createStringReference("B\u00e5tsfjord".ToCharArray())
		kommunenavn(2030) = createStringReference("S\u00f8r-Varanger".ToCharArray())

		Return kommunenavn
	End Function


	Public Function hentGyldigeKommunenummer() As Double ()
		Dim gyldigeKommunenummer As Double ()

		gyldigeKommunenummer = New Double (425 + 1 - 1){}

		gyldigeKommunenummer(0) = 101
		gyldigeKommunenummer(1) = 104
		gyldigeKommunenummer(2) = 105
		gyldigeKommunenummer(3) = 106
		gyldigeKommunenummer(4) = 111
		gyldigeKommunenummer(5) = 118
		gyldigeKommunenummer(6) = 119
		gyldigeKommunenummer(7) = 121
		gyldigeKommunenummer(8) = 122
		gyldigeKommunenummer(9) = 123
		gyldigeKommunenummer(10) = 124
		gyldigeKommunenummer(11) = 125
		gyldigeKommunenummer(12) = 127
		gyldigeKommunenummer(13) = 128
		gyldigeKommunenummer(14) = 135
		gyldigeKommunenummer(15) = 136
		gyldigeKommunenummer(16) = 137
		gyldigeKommunenummer(17) = 138
		gyldigeKommunenummer(18) = 211
		gyldigeKommunenummer(19) = 213
		gyldigeKommunenummer(20) = 214
		gyldigeKommunenummer(21) = 215
		gyldigeKommunenummer(22) = 216
		gyldigeKommunenummer(23) = 217
		gyldigeKommunenummer(24) = 219
		gyldigeKommunenummer(25) = 220
		gyldigeKommunenummer(26) = 221
		gyldigeKommunenummer(27) = 226
		gyldigeKommunenummer(28) = 227
		gyldigeKommunenummer(29) = 228
		gyldigeKommunenummer(30) = 229
		gyldigeKommunenummer(31) = 230
		gyldigeKommunenummer(32) = 231
		gyldigeKommunenummer(33) = 233
		gyldigeKommunenummer(34) = 234
		gyldigeKommunenummer(35) = 235
		gyldigeKommunenummer(36) = 236
		gyldigeKommunenummer(37) = 237
		gyldigeKommunenummer(38) = 238
		gyldigeKommunenummer(39) = 239
		gyldigeKommunenummer(40) = 301
		gyldigeKommunenummer(41) = 402
		gyldigeKommunenummer(42) = 403
		gyldigeKommunenummer(43) = 412
		gyldigeKommunenummer(44) = 415
		gyldigeKommunenummer(45) = 417
		gyldigeKommunenummer(46) = 418
		gyldigeKommunenummer(47) = 419
		gyldigeKommunenummer(48) = 420
		gyldigeKommunenummer(49) = 423
		gyldigeKommunenummer(50) = 425
		gyldigeKommunenummer(51) = 426
		gyldigeKommunenummer(52) = 427
		gyldigeKommunenummer(53) = 428
		gyldigeKommunenummer(54) = 429
		gyldigeKommunenummer(55) = 430
		gyldigeKommunenummer(56) = 432
		gyldigeKommunenummer(57) = 434
		gyldigeKommunenummer(58) = 436
		gyldigeKommunenummer(59) = 437
		gyldigeKommunenummer(60) = 438
		gyldigeKommunenummer(61) = 439
		gyldigeKommunenummer(62) = 441
		gyldigeKommunenummer(63) = 501
		gyldigeKommunenummer(64) = 502
		gyldigeKommunenummer(65) = 511
		gyldigeKommunenummer(66) = 512
		gyldigeKommunenummer(67) = 513
		gyldigeKommunenummer(68) = 514
		gyldigeKommunenummer(69) = 515
		gyldigeKommunenummer(70) = 516
		gyldigeKommunenummer(71) = 517
		gyldigeKommunenummer(72) = 519
		gyldigeKommunenummer(73) = 520
		gyldigeKommunenummer(74) = 521
		gyldigeKommunenummer(75) = 522
		gyldigeKommunenummer(76) = 528
		gyldigeKommunenummer(77) = 529
		gyldigeKommunenummer(78) = 532
		gyldigeKommunenummer(79) = 533
		gyldigeKommunenummer(80) = 534
		gyldigeKommunenummer(81) = 536
		gyldigeKommunenummer(82) = 538
		gyldigeKommunenummer(83) = 540
		gyldigeKommunenummer(84) = 541
		gyldigeKommunenummer(85) = 542
		gyldigeKommunenummer(86) = 543
		gyldigeKommunenummer(87) = 544
		gyldigeKommunenummer(88) = 545
		gyldigeKommunenummer(89) = 602
		gyldigeKommunenummer(90) = 604
		gyldigeKommunenummer(91) = 605
		gyldigeKommunenummer(92) = 612
		gyldigeKommunenummer(93) = 615
		gyldigeKommunenummer(94) = 616
		gyldigeKommunenummer(95) = 617
		gyldigeKommunenummer(96) = 618
		gyldigeKommunenummer(97) = 619
		gyldigeKommunenummer(98) = 620
		gyldigeKommunenummer(99) = 621
		gyldigeKommunenummer(100) = 622
		gyldigeKommunenummer(101) = 623
		gyldigeKommunenummer(102) = 624
		gyldigeKommunenummer(103) = 625
		gyldigeKommunenummer(104) = 626
		gyldigeKommunenummer(105) = 627
		gyldigeKommunenummer(106) = 628
		gyldigeKommunenummer(107) = 631
		gyldigeKommunenummer(108) = 632
		gyldigeKommunenummer(109) = 633
		gyldigeKommunenummer(110) = 701
		gyldigeKommunenummer(111) = 702
		gyldigeKommunenummer(112) = 704
		gyldigeKommunenummer(113) = 709
		gyldigeKommunenummer(114) = 710
		gyldigeKommunenummer(115) = 711
		gyldigeKommunenummer(116) = 713
		gyldigeKommunenummer(117) = 714
		gyldigeKommunenummer(118) = 716
		gyldigeKommunenummer(119) = 722
		gyldigeKommunenummer(120) = 723
		gyldigeKommunenummer(121) = 728
		gyldigeKommunenummer(122) = 805
		gyldigeKommunenummer(123) = 806
		gyldigeKommunenummer(124) = 807
		gyldigeKommunenummer(125) = 811
		gyldigeKommunenummer(126) = 814
		gyldigeKommunenummer(127) = 815
		gyldigeKommunenummer(128) = 817
		gyldigeKommunenummer(129) = 819
		gyldigeKommunenummer(130) = 821
		gyldigeKommunenummer(131) = 822
		gyldigeKommunenummer(132) = 826
		gyldigeKommunenummer(133) = 827
		gyldigeKommunenummer(134) = 828
		gyldigeKommunenummer(135) = 829
		gyldigeKommunenummer(136) = 830
		gyldigeKommunenummer(137) = 831
		gyldigeKommunenummer(138) = 833
		gyldigeKommunenummer(139) = 834
		gyldigeKommunenummer(140) = 901
		gyldigeKommunenummer(141) = 904
		gyldigeKommunenummer(142) = 906
		gyldigeKommunenummer(143) = 911
		gyldigeKommunenummer(144) = 912
		gyldigeKommunenummer(145) = 914
		gyldigeKommunenummer(146) = 919
		gyldigeKommunenummer(147) = 926
		gyldigeKommunenummer(148) = 928
		gyldigeKommunenummer(149) = 929
		gyldigeKommunenummer(150) = 935
		gyldigeKommunenummer(151) = 937
		gyldigeKommunenummer(152) = 938
		gyldigeKommunenummer(153) = 940
		gyldigeKommunenummer(154) = 941
		gyldigeKommunenummer(155) = 1001
		gyldigeKommunenummer(156) = 1002
		gyldigeKommunenummer(157) = 1003
		gyldigeKommunenummer(158) = 1004
		gyldigeKommunenummer(159) = 1014
		gyldigeKommunenummer(160) = 1017
		gyldigeKommunenummer(161) = 1018
		gyldigeKommunenummer(162) = 1021
		gyldigeKommunenummer(163) = 1026
		gyldigeKommunenummer(164) = 1027
		gyldigeKommunenummer(165) = 1029
		gyldigeKommunenummer(166) = 1032
		gyldigeKommunenummer(167) = 1034
		gyldigeKommunenummer(168) = 1037
		gyldigeKommunenummer(169) = 1046
		gyldigeKommunenummer(170) = 1101
		gyldigeKommunenummer(171) = 1102
		gyldigeKommunenummer(172) = 1103
		gyldigeKommunenummer(173) = 1106
		gyldigeKommunenummer(174) = 1111
		gyldigeKommunenummer(175) = 1112
		gyldigeKommunenummer(176) = 1114
		gyldigeKommunenummer(177) = 1119
		gyldigeKommunenummer(178) = 1120
		gyldigeKommunenummer(179) = 1121
		gyldigeKommunenummer(180) = 1122
		gyldigeKommunenummer(181) = 1124
		gyldigeKommunenummer(182) = 1127
		gyldigeKommunenummer(183) = 1129
		gyldigeKommunenummer(184) = 1130
		gyldigeKommunenummer(185) = 1133
		gyldigeKommunenummer(186) = 1134
		gyldigeKommunenummer(187) = 1135
		gyldigeKommunenummer(188) = 1141
		gyldigeKommunenummer(189) = 1142
		gyldigeKommunenummer(190) = 1144
		gyldigeKommunenummer(191) = 1145
		gyldigeKommunenummer(192) = 1146
		gyldigeKommunenummer(193) = 1149
		gyldigeKommunenummer(194) = 1151
		gyldigeKommunenummer(195) = 1160
		gyldigeKommunenummer(196) = 1201
		gyldigeKommunenummer(197) = 1211
		gyldigeKommunenummer(198) = 1216
		gyldigeKommunenummer(199) = 1219
		gyldigeKommunenummer(200) = 1221
		gyldigeKommunenummer(201) = 1222
		gyldigeKommunenummer(202) = 1223
		gyldigeKommunenummer(203) = 1224
		gyldigeKommunenummer(204) = 1227
		gyldigeKommunenummer(205) = 1228
		gyldigeKommunenummer(206) = 1231
		gyldigeKommunenummer(207) = 1232
		gyldigeKommunenummer(208) = 1233
		gyldigeKommunenummer(209) = 1234
		gyldigeKommunenummer(210) = 1235
		gyldigeKommunenummer(211) = 1238
		gyldigeKommunenummer(212) = 1241
		gyldigeKommunenummer(213) = 1242
		gyldigeKommunenummer(214) = 1243
		gyldigeKommunenummer(215) = 1244
		gyldigeKommunenummer(216) = 1245
		gyldigeKommunenummer(217) = 1246
		gyldigeKommunenummer(218) = 1247
		gyldigeKommunenummer(219) = 1251
		gyldigeKommunenummer(220) = 1252
		gyldigeKommunenummer(221) = 1253
		gyldigeKommunenummer(222) = 1256
		gyldigeKommunenummer(223) = 1259
		gyldigeKommunenummer(224) = 1260
		gyldigeKommunenummer(225) = 1263
		gyldigeKommunenummer(226) = 1264
		gyldigeKommunenummer(227) = 1265
		gyldigeKommunenummer(228) = 1266
		gyldigeKommunenummer(229) = 1401
		gyldigeKommunenummer(230) = 1411
		gyldigeKommunenummer(231) = 1412
		gyldigeKommunenummer(232) = 1413
		gyldigeKommunenummer(233) = 1416
		gyldigeKommunenummer(234) = 1417
		gyldigeKommunenummer(235) = 1418
		gyldigeKommunenummer(236) = 1419
		gyldigeKommunenummer(237) = 1420
		gyldigeKommunenummer(238) = 1421
		gyldigeKommunenummer(239) = 1422
		gyldigeKommunenummer(240) = 1424
		gyldigeKommunenummer(241) = 1426
		gyldigeKommunenummer(242) = 1428
		gyldigeKommunenummer(243) = 1429
		gyldigeKommunenummer(244) = 1430
		gyldigeKommunenummer(245) = 1431
		gyldigeKommunenummer(246) = 1432
		gyldigeKommunenummer(247) = 1433
		gyldigeKommunenummer(248) = 1438
		gyldigeKommunenummer(249) = 1439
		gyldigeKommunenummer(250) = 1441
		gyldigeKommunenummer(251) = 1443
		gyldigeKommunenummer(252) = 1444
		gyldigeKommunenummer(253) = 1445
		gyldigeKommunenummer(254) = 1449
		gyldigeKommunenummer(255) = 1502
		gyldigeKommunenummer(256) = 1504
		gyldigeKommunenummer(257) = 1505
		gyldigeKommunenummer(258) = 1511
		gyldigeKommunenummer(259) = 1514
		gyldigeKommunenummer(260) = 1515
		gyldigeKommunenummer(261) = 1516
		gyldigeKommunenummer(262) = 1517
		gyldigeKommunenummer(263) = 1519
		gyldigeKommunenummer(264) = 1520
		gyldigeKommunenummer(265) = 1523
		gyldigeKommunenummer(266) = 1524
		gyldigeKommunenummer(267) = 1525
		gyldigeKommunenummer(268) = 1526
		gyldigeKommunenummer(269) = 1528
		gyldigeKommunenummer(270) = 1529
		gyldigeKommunenummer(271) = 1531
		gyldigeKommunenummer(272) = 1532
		gyldigeKommunenummer(273) = 1534
		gyldigeKommunenummer(274) = 1535
		gyldigeKommunenummer(275) = 1539
		gyldigeKommunenummer(276) = 1543
		gyldigeKommunenummer(277) = 1545
		gyldigeKommunenummer(278) = 1546
		gyldigeKommunenummer(279) = 1547
		gyldigeKommunenummer(280) = 1548
		gyldigeKommunenummer(281) = 1551
		gyldigeKommunenummer(282) = 1554
		gyldigeKommunenummer(283) = 1557
		gyldigeKommunenummer(284) = 1560
		gyldigeKommunenummer(285) = 1563
		gyldigeKommunenummer(286) = 1566
		gyldigeKommunenummer(287) = 1567
		gyldigeKommunenummer(288) = 1571
		gyldigeKommunenummer(289) = 1573
		gyldigeKommunenummer(290) = 1576
		gyldigeKommunenummer(291) = 1601
		gyldigeKommunenummer(292) = 1612
		gyldigeKommunenummer(293) = 1613
		gyldigeKommunenummer(294) = 1617
		gyldigeKommunenummer(295) = 1620
		gyldigeKommunenummer(296) = 1621
		gyldigeKommunenummer(297) = 1622
		gyldigeKommunenummer(298) = 1624
		gyldigeKommunenummer(299) = 1627
		gyldigeKommunenummer(300) = 1630
		gyldigeKommunenummer(301) = 1632
		gyldigeKommunenummer(302) = 1633
		gyldigeKommunenummer(303) = 1634
		gyldigeKommunenummer(304) = 1635
		gyldigeKommunenummer(305) = 1636
		gyldigeKommunenummer(306) = 1638
		gyldigeKommunenummer(307) = 1640
		gyldigeKommunenummer(308) = 1644
		gyldigeKommunenummer(309) = 1648
		gyldigeKommunenummer(310) = 1653
		gyldigeKommunenummer(311) = 1657
		gyldigeKommunenummer(312) = 1662
		gyldigeKommunenummer(313) = 1663
		gyldigeKommunenummer(314) = 1664
		gyldigeKommunenummer(315) = 1665
		gyldigeKommunenummer(316) = 1702
		gyldigeKommunenummer(317) = 1703
		gyldigeKommunenummer(318) = 1711
		gyldigeKommunenummer(319) = 1714
		gyldigeKommunenummer(320) = 1717
		gyldigeKommunenummer(321) = 1718
		gyldigeKommunenummer(322) = 1719
		gyldigeKommunenummer(323) = 1721
		gyldigeKommunenummer(324) = 1724
		gyldigeKommunenummer(325) = 1725
		gyldigeKommunenummer(326) = 1736
		gyldigeKommunenummer(327) = 1738
		gyldigeKommunenummer(328) = 1739
		gyldigeKommunenummer(329) = 1740
		gyldigeKommunenummer(330) = 1742
		gyldigeKommunenummer(331) = 1743
		gyldigeKommunenummer(332) = 1744
		gyldigeKommunenummer(333) = 1748
		gyldigeKommunenummer(334) = 1749
		gyldigeKommunenummer(335) = 1750
		gyldigeKommunenummer(336) = 1751
		gyldigeKommunenummer(337) = 1755
		gyldigeKommunenummer(338) = 1756
		gyldigeKommunenummer(339) = 1804
		gyldigeKommunenummer(340) = 1805
		gyldigeKommunenummer(341) = 1811
		gyldigeKommunenummer(342) = 1812
		gyldigeKommunenummer(343) = 1813
		gyldigeKommunenummer(344) = 1815
		gyldigeKommunenummer(345) = 1816
		gyldigeKommunenummer(346) = 1818
		gyldigeKommunenummer(347) = 1820
		gyldigeKommunenummer(348) = 1822
		gyldigeKommunenummer(349) = 1824
		gyldigeKommunenummer(350) = 1825
		gyldigeKommunenummer(351) = 1826
		gyldigeKommunenummer(352) = 1827
		gyldigeKommunenummer(353) = 1828
		gyldigeKommunenummer(354) = 1832
		gyldigeKommunenummer(355) = 1833
		gyldigeKommunenummer(356) = 1834
		gyldigeKommunenummer(357) = 1835
		gyldigeKommunenummer(358) = 1836
		gyldigeKommunenummer(359) = 1837
		gyldigeKommunenummer(360) = 1838
		gyldigeKommunenummer(361) = 1839
		gyldigeKommunenummer(362) = 1840
		gyldigeKommunenummer(363) = 1841
		gyldigeKommunenummer(364) = 1845
		gyldigeKommunenummer(365) = 1848
		gyldigeKommunenummer(366) = 1849
		gyldigeKommunenummer(367) = 1850
		gyldigeKommunenummer(368) = 1851
		gyldigeKommunenummer(369) = 1852
		gyldigeKommunenummer(370) = 1853
		gyldigeKommunenummer(371) = 1854
		gyldigeKommunenummer(372) = 1856
		gyldigeKommunenummer(373) = 1857
		gyldigeKommunenummer(374) = 1859
		gyldigeKommunenummer(375) = 1860
		gyldigeKommunenummer(376) = 1865
		gyldigeKommunenummer(377) = 1866
		gyldigeKommunenummer(378) = 1867
		gyldigeKommunenummer(379) = 1868
		gyldigeKommunenummer(380) = 1870
		gyldigeKommunenummer(381) = 1871
		gyldigeKommunenummer(382) = 1874
		gyldigeKommunenummer(383) = 1903
		gyldigeKommunenummer(384) = 1902
		gyldigeKommunenummer(385) = 1911
		gyldigeKommunenummer(386) = 1913
		gyldigeKommunenummer(387) = 1917
		gyldigeKommunenummer(388) = 1919
		gyldigeKommunenummer(389) = 1920
		gyldigeKommunenummer(390) = 1922
		gyldigeKommunenummer(391) = 1923
		gyldigeKommunenummer(392) = 1924
		gyldigeKommunenummer(393) = 1925
		gyldigeKommunenummer(394) = 1926
		gyldigeKommunenummer(395) = 1927
		gyldigeKommunenummer(396) = 1928
		gyldigeKommunenummer(397) = 1929
		gyldigeKommunenummer(398) = 1931
		gyldigeKommunenummer(399) = 1933
		gyldigeKommunenummer(400) = 1936
		gyldigeKommunenummer(401) = 1938
		gyldigeKommunenummer(402) = 1939
		gyldigeKommunenummer(403) = 1940
		gyldigeKommunenummer(404) = 1941
		gyldigeKommunenummer(405) = 1942
		gyldigeKommunenummer(406) = 1943
		gyldigeKommunenummer(407) = 2002
		gyldigeKommunenummer(408) = 2003
		gyldigeKommunenummer(409) = 2004
		gyldigeKommunenummer(410) = 2011
		gyldigeKommunenummer(411) = 2012
		gyldigeKommunenummer(412) = 2014
		gyldigeKommunenummer(413) = 2015
		gyldigeKommunenummer(414) = 2017
		gyldigeKommunenummer(415) = 2018
		gyldigeKommunenummer(416) = 2019
		gyldigeKommunenummer(417) = 2020
		gyldigeKommunenummer(418) = 2021
		gyldigeKommunenummer(419) = 2022
		gyldigeKommunenummer(420) = 2023
		gyldigeKommunenummer(421) = 2024
		gyldigeKommunenummer(422) = 2025
		gyldigeKommunenummer(423) = 2027
		gyldigeKommunenummer(424) = 2028
		gyldigeKommunenummer(425) = 2030

		Return gyldigeKommunenummer
	End Function


	Public Function test1() As Double
		Dim doubleReference As DoubleReference
		Dim success As Success
		Dim kommuenavn As Char ()

		doubleReference = New DoubleReference()
		doubleReference.doubleValue = 0

		success = New Success()
		kommuenavn = hentKommunenavnFraNummer("1640".ToCharArray(), success)
		Call assertStringEquals(kommuenavn, "R\u00f8ros".ToCharArray(), doubleReference)
		Call assertTrue(success.success, doubleReference)

		Return doubleReference.doubleValue
	End Function


	Public Function test() As Double
		Dim failures As Double

		failures = 0

		failures = failures + test1()

		Return failures
	End Function


	Public Function decimalToString(decimalx As Double) As Char ()

		Return numberToString(decimalx, 10)
	End Function


	Public Function numberToString(decimalx As Double, base As Double) As Char ()
		Dim stringxx As Char ()
		Dim digits As Double
		Dim digitPosition As Double
		Dim hasPrintedPoint As Boolean
		Dim i, d As Double

		stringxx = New Char (0 - 1){}

		digits = getDigits(base)

		' Find digitPosition:
		digitPosition = getDigitPosition(decimalx, base)

		decimalx = Round(decimalx*base ^ (-digitPosition  + digits - 1))

		hasPrintedPoint = false

		' Print leading zeros.
		If digitPosition < 0
			stringxx = appendCharacter(stringxx, "0"C)
			stringxx = appendCharacter(stringxx, "."C)
			hasPrintedPoint = true
			i = 0
			While i < -digitPosition  - 1
				stringxx = appendCharacter(stringxx, "0"C)
				i = i + 1
			End While
		End If

		' Print number.
		i = 0
		While i < digits
			d = Floor(decimalx/base ^ (digits - i - 1))
			If Not hasPrintedPoint And digitPosition - i + 1 = 0
				If decimalx <> 0
					stringxx = appendCharacter(stringxx, "."C)
				End If
				hasPrintedPoint = true
			End If
			If decimalx = 0 And hasPrintedPoint
			Else
				stringxx = appendCharacter(stringxx, getSingleDigitFromNumber(d, base))
			End If
			decimalx = decimalx - d*base ^ (digits - i - 1)
			i = i + 1
		End While

		' Print trailing zeros.
		i = 0
		While i < digitPosition - digits + 1
			stringxx = appendCharacter(stringxx, "0"C)
			i = i + 1
		End While

		' Done
		Return stringxx
	End Function


	Public Function getDigits(base As Double) As Double
		Dim t As Double

		t = 10 ^ 15
		Return Floor(Log10(t)/Log10(base))
	End Function


	Public Function getDigitPosition(decimalx As Double, base As Double) As Double
		Dim power As Double
		Dim t As Double

		power = Ceiling(Log10(decimalx)/Log10(base))

		t = decimalx*base ^ (-power )
		If t < base And t >= 1
		ElseIf t >= base
			power = power + 1
		ElseIf t < 1
			power = power - 1
		End If


		Return power
	End Function


	Public Function getSingleDigitFromNumber(c As Double, base As Double) As Char
		Dim numberTable As Char ()
		Dim retc As Char

		numberTable = getNumberTable()

		If c > base - 1
			retc = "?"C
		Else
			retc = numberTable(c)
		End If

		Return retc
	End Function


	Public Function getNumberTable() As Char ()
		Dim numberTable As Char ()

		numberTable = New Char (16 - 1){}
		numberTable(0) = "0"C
		numberTable(1) = "1"C
		numberTable(2) = "2"C
		numberTable(3) = "3"C
		numberTable(4) = "4"C
		numberTable(5) = "5"C
		numberTable(6) = "6"C
		numberTable(7) = "7"C
		numberTable(8) = "8"C
		numberTable(9) = "9"C
		numberTable(10) = "A"C
		numberTable(11) = "B"C
		numberTable(12) = "C"C
		numberTable(13) = "D"C
		numberTable(14) = "E"C
		numberTable(15) = "F"C
		Return numberTable
	End Function


	Public Function stringToDecimal(ByRef stringxx As Char ()) As StringToDecimalResult

		Return stringToDecimalForBase(stringxx, 10)
	End Function


	Public Function stringToDecimalForBase(ByRef stringxx As Char (), base As Double) As StringToDecimalResult
		Dim stringToDecimalResult As StringToDecimalResult
		Dim c As Char
		Dim i, j As Double
		Dim isPositive As Boolean
		Dim beforeDecimalPoint As Double
		Dim afterDecimalPoint As Double
		Dim n As Double
		Dim validCharacters As Double
		Dim d As Double

		stringToDecimalResult = New StringToDecimalResult()
		stringToDecimalResult.success = true
		i = 0
		isPositive = true
		beforeDecimalPoint = 0
		afterDecimalPoint = 0
		n = 0
		validCharacters = 0

		If base >= 2 And base <= 16
			j = 0
			While j < stringxx.Length
				c = stringxx(j)
				If isNumber(c, base) Or c = "."C Or c = "-"C
					validCharacters = validCharacters + 1
				End If
				j = j + 1
			End While
			If validCharacters = stringxx.Length
				If stringxx.Length > 0
					c = stringxx(i)
					If c = "-"C
						isPositive = false
						i = i + 1
					End If
					If i < stringxx.Length
						c = stringxx(i)
						If isNumber(c, base)
							
							While isNumber(c, base) And (i < stringxx.Length)
								beforeDecimalPoint = beforeDecimalPoint + 1
								i = i + 1
								If i < stringxx.Length
									c = stringxx(i)
								End If
							End While
							If i < stringxx.Length
								c = stringxx(i)
								If c = "."C
									i = i + 1
									If i < stringxx.Length
										c = stringxx(i)
										
										While isNumber(c, base) And (i < stringxx.Length)
											afterDecimalPoint = afterDecimalPoint + 1
											i = i + 1
											If i < stringxx.Length
												c = stringxx(i)
											End If
										End While
									Else
										stringToDecimalResult.success = false
										stringToDecimalResult.feilmelding = "Number must have digits after the decimal point.".ToCharArray()
									End If
								End If
							End If
						Else
							stringToDecimalResult.success = false
							stringToDecimalResult.feilmelding = "Number must start with digits (for negative numbers, after the optional negative sign).".ToCharArray()
						End If
					End If
					If stringToDecimalResult.success <> false
						i = 0
						If Not isPositive
							i = 1
						End If
						j = 0
						While j < beforeDecimalPoint
							c = stringxx(i)
							i = i + 1
							d = getDecimalFromSingleDecimalDigit(c, base)
							n = n + d*base ^ (beforeDecimalPoint - j - 1)
							j = j + 1
						End While
						If afterDecimalPoint > 0
							i = i + 1
							j = 0
							While j < afterDecimalPoint
								c = stringxx(i)
								i = i + 1
								d = getDecimalFromSingleDecimalDigit(c, base)
								n = n + d*base ^ (0 - j - 1)
								j = j + 1
							End While
						End If
						If Not isPositive
							n = -n 
						End If
						stringToDecimalResult.result = n
						stringToDecimalResult.success = true
					End If
				Else
					stringToDecimalResult.success = false
					stringToDecimalResult.feilmelding = "String has no content.".ToCharArray()
				End If
			Else
				stringToDecimalResult.success = false
				stringToDecimalResult.feilmelding = "String contains invalid character.".ToCharArray()
			End If
		Else
			stringToDecimalResult.success = false
			stringToDecimalResult.feilmelding = "Base must be from 2 to 16.".ToCharArray()
		End If

		Return stringToDecimalResult
	End Function


	Public Function getDecimalFromSingleDecimalDigit(c As Char, base As Double) As Double
		Dim numberTable As Char ()
		Dim i As Double
		Dim position As Double

		numberTable = getNumberTable()
		position = 0

		i = 0
		While i < base
			If numberTable(i) = c
				position = i
			End If
			i = i + 1
		End While

		Return position
	End Function


	Public Function isNumber(c As Char, base As Double) As Boolean
		Dim numberTable As Char ()
		Dim i As Double
		Dim found As Boolean

		numberTable = getNumberTable()
		found = false

		i = 0
		While i < base
			If numberTable(i) = c
				found = true
			End If
			i = i + 1
		End While

		Return found
	End Function


	Public Sub assertFalse(b As Boolean, ByRef failures As DoubleReference)

		If b
			failures.doubleValue = failures.doubleValue + 1
		End If
	End Sub


	Public Sub assertTrue(b As Boolean, ByRef failures As DoubleReference)

		If Not b
			failures.doubleValue = failures.doubleValue + 1
		End If
	End Sub


	Public Sub assertEquals(a As Double, b As Double, ByRef failures As DoubleReference)

		If a <> b
			failures.doubleValue = failures.doubleValue + 1
		End If
	End Sub


	Public Sub assertStringEquals(ByRef a As Char (), ByRef b As Char (), ByRef failures As DoubleReference)

		If Not stringsEqual(a, b)
			failures.doubleValue = failures.doubleValue + 1
		End If
	End Sub


	Public Function stringToNumberArray(ByRef stringxx As Char ()) As Double ()
		Dim i As Double
		Dim arrayx As Double ()

		arrayx = New Double (stringxx.Length - 1){}

		i = 0
		While i < stringxx.Length
			arrayx(i) = Convert.ToByte(stringxx(i))
			i = i + 1
		End While
		Return arrayx
	End Function


	Public Function numberArrayToString(ByRef arrayx As Double ()) As Char ()
		Dim i As Double
		Dim stringxx As Char ()

		stringxx = New Char (arrayx.Length - 1){}

		i = 0
		While i < arrayx.Length
			stringxx(i) = Convert.ToChar(Convert.ToInt64(arrayx(i)))
			i = i + 1
		End While
		Return stringxx
	End Function


	Public Function stringsEqual(ByRef data1 As Char (), ByRef data2 As Char ()) As Boolean
		Dim equal As Boolean
		Dim nrEqual, i As Double

		equal = false
		If data1.Length = data2.Length
			nrEqual = 0
			i = 0
			While i < data1.Length
				If data1(i) = data2(i)
					nrEqual = nrEqual + 1
				End If
				i = i + 1
			End While
			If nrEqual = data1.Length
				equal = true
			End If
		Else
			equal = false
		End If

		Return equal
	End Function


	Public Function numberArraysEqual(ByRef data1 As Double (), ByRef data2 As Double ()) As Boolean
		Dim equal As Boolean
		Dim nrEqual, i As Double

		equal = false
		If data1.Length = data2.Length
			nrEqual = 0
			i = 0
			While i < data1.Length
				If data1(i) = data2(i)
					nrEqual = nrEqual + 1
				End If
				i = i + 1
			End While
			If nrEqual = data1.Length
				equal = true
			End If
		Else
			equal = false
		End If

		Return equal
	End Function


	Public Function substring(ByRef stringxx As Char (), from As Double, tox As Double) As Char ()
		Dim n As Char ()
		Dim i As Double

		n = New Char (tox - from - 1){}

		i = from
		While i < tox
			n(i - from) = stringxx(i)
			i = i + 1
		End While

		Return n
	End Function


	Public Function appendString(ByRef stringxx As Char (), ByRef s As Char ()) As Char ()
		Dim newString As Char ()
		Dim i As Double

		newString = New Char (stringxx.Length + s.Length - 1){}

		i = 0
		While i < stringxx.Length
			newString(i) = stringxx(i)
			i = i + 1
		End While

		i = 0
		While i < s.Length
			newString(stringxx.Length + i) = s(i)
			i = i + 1
		End While

		Erase stringxx 

		Return newString
	End Function


	Public Function appendCharacter(ByRef stringxx As Char (), c As Char) As Char ()
		Dim newString As Char ()
		Dim i As Double

		newString = New Char (stringxx.Length + 1 - 1){}

		i = 0
		While i < stringxx.Length
			newString(i) = stringxx(i)
			i = i + 1
		End While

		newString(stringxx.Length) = c

		Erase stringxx 

		Return newString
	End Function


	Public Function split(ByRef toSplit As Char (), splitBy As Char) As StringReference ()
		Dim splitt As StringReference ()
		Dim nextxx As Char ()
		Dim i As Double
		Dim c As Char
		Dim n As StringReference

		splitt = New StringReference (0 - 1){}

		nextxx = New Char (0 - 1){}
		i = 0
		While i < toSplit.Length
			c = toSplit(i)
			If c = splitBy
				n = New StringReference()
				n.stringxx = nextxx
				splitt = addString(splitt, n)
				nextxx = New Char (0 - 1){}
			Else
				nextxx = appendCharacter(nextxx, c)
			End If
			i = i + 1
		End While

		If nextxx.Length > 0
			n = New StringReference()
			n.stringxx = nextxx
			splitt = addString(splitt, n)
		End If

		Return splitt
	End Function


	Public Function addDecimal(ByRef list As Double (), a As Double) As Double ()
		Dim newlist As Double ()
		Dim i As Double

		newlist = New Double (list.Length + 1 - 1){}
		i = 0
		While i < list.Length
			newlist(i) = list(i)
			i = i + 1
		End While
		newlist(list.Length) = a
		
		Erase list 
		
		Return newlist
	End Function


	Public Sub addDecimalRef(ByRef list As DecimalListRef, i As Double)

		list.list = addDecimal(list.list, i)
	End Sub


	Public Function removeDecimal(ByRef list As Double (), n As Double) As Double ()
		Dim newlist As Double ()
		Dim i As Double

		newlist = New Double (list.Length - 1 - 1){}

		i = 0
		While i < list.Length
			If i < n
				newlist(i) = list(i)
			End If
			If i > n
				newlist(i - 1) = list(i)
			End If
			i = i + 1
		End While
		
		Erase list 
		
		Return newlist
	End Function


	Public Function getDecimalRef(ByRef list As DecimalListRef, i As Double) As Double

		Return list.list(i)
	End Function


	Public Sub removeDecimalRef(ByRef list As DecimalListRef, i As Double)

		list.list = removeDecimal(list.list, i)
	End Sub


	Public Function addString(ByRef list As StringReference (), ByRef a As StringReference) As StringReference ()
		Dim newlist As StringReference ()
		Dim i As Double

		newlist = New StringReference (list.Length + 1 - 1){}

		i = 0
		While i < list.Length
			newlist(i) = list(i)
			i = i + 1
		End While
		newlist(list.Length) = a
		
		Erase list 
		
		Return newlist
	End Function


	Public Sub addStringRef(ByRef list As StringListRef, ByRef i As StringReference)

		list.list = addString(list.list, i)
	End Sub


	Public Function removeString(ByRef list As StringReference (), n As Double) As StringReference ()
		Dim newlist As StringReference ()
		Dim i As Double

		newlist = New StringReference (list.Length - 1 - 1){}

		i = 0
		While i < list.Length
			If i < n
				newlist(i) = list(i)
			End If
			If i > n
				newlist(i - 1) = list(i)
			End If
			i = i + 1
		End While
		
		Erase list 
		
		Return newlist
	End Function


	Public Function getStringRef(ByRef list As StringListRef, i As Double) As StringReference

		Return list.list(i)
	End Function


	Public Sub removeStringRef(ByRef list As StringListRef, i As Double)

		list.list = removeString(list.list, i)
	End Sub


End Module


Module kommunenummerTestBundle
	Sub Main(args As String())
		Console.WriteLine(test())
	End Sub
End Module
