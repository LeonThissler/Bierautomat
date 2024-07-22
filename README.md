# Bierautomat
Dieses Projekt behandelt ein Bierautomaten, welcher mit einer Siemens KTP600 HMI, einer Siemens LOGO!
und einem Arduino Mega 2560 gesteuert wird (Projekt in bearbeitung)
***********************************************************************************************************
Aufgabe:
per HMI Panel, sollen als Benutzer mit Service Berechtigung: 
-die Biersorten für insgesamt 6 Fächer eingestellt werden,
-die gesamte Betriebszeit der Anlage ausgelesen werden(mit reset),
-die Preise eingestellt werden,
-ein Testfach angefordert werden ohne Geld einzuwerfen,
-die Gesamteinnahmen ausgelesen werden(mit reset),
-eine Benutzerverwaltung stattfinden,
-Anlagenübersicht mit "groben" Schaltplan gelesen werden.

als Benutzer ohne Service Berechtigung:
-Bier auswahl treffen,
-Geld einwerfen um an Bier zu kommen(ohne Wechselgeld).
************************************************************************************************************
Ablauf:
HMI kommuniziert mit S7-1215C DC/DC/RLY über Profinet ->
von Service Benutzer wird per HMI ein Geldwert eines Faches in einem Datenbaustein der SPS eingestellt ->
Normaler Benutzer wählt Fach aus welches in der SPS einen Wert hat ->
Normaler Benutzer wirft Münze ein und ein Münzzähler erfasst diese->
Je nach Münze setzt sendet der Münzzähler impulse an den Arduino und dieser schaltet je nach Münze ein Relais welches einen Eingang in der LOGO! setzt->
je nach Eingang zählt die SPS nun hoch bis der voreingestellte Fachwert mit dem eingeworfenen Münzgeld übereinstimmt ->
wenn der Wert gleich ist, wird je nach ausgewählten Fach nun dieses Betätigt(Motor des Faches wird angesteuert)->
Bier wird ausgegeben und Münzwert wird zurück gesetzt und Gesamteinnahmen werden um eingeworfenen Betrag erhöht.
**************************************************************************************************************
Jeder Benutzer der eine Anmeldung hat besitzt ein Konto auf welches Geld draufgebucht werden kann von einer anderen Person mit Admin account 
Jeder Benutzer hat eine fest zugewiesene Nummer mit welcher das Konto aufgerufen wird zudem kann das Geld was durch den Münzzähler eingezahlt wurd und auf dem Automaten gespeichert ist , per Taste auf der HMI auf das Konto der jewiligen Anmeldung gebucht werden -> so umgeht man die Geldrückgabe



