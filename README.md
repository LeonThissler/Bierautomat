# Bierautomat
Dieses Projekt behandelt ein Bierautomaten, welcher mit einer Siemens KTP600 HMI, einer Siemens S7-1200
und einem Arduino Mega 2560 gesteuert wird (Projekt in bearbeitung)
***********************************************************************************************************
Aufgabe:
per HMI Panel, sollen als Benutzer mit Service Berechtigung: 
-die Biersorten für insgesamt 6 Fächer eingestellt werden,
-die Preise eingestellt werden,
-ein Testfach angefordert werden ohne Geld einzuwerfen,
-die Gesamteinnahmen ausgelesen werden(mit reset),
-eine Benutzerverwaltung stattfinden,
-Anlagenübersicht mit "groben" Schaltplan gelesen werden.
-Korrekturen an Benutzerkonten vorgenommen werden und Geld aufgebucht werden

als Benutzer ohne Service Berechtigung:
-Bier auswahl treffen,
-Geld einwerfen um an Bier zu kommen(ohne Wechselgeld).

als Benutzer ohne Service Berechtigung aber mit Konto:
Geld aufladen über Münzeinwurf welches für den Benutzer gespeichert wird
************************************************************************************************************
Ablauf:
HMI kommuniziert mit S7-1215C DC/DC/RLY über Profinet ->
von Service Benutzer wird per HMI ein Geldwert eines Faches in einem Datenbaustein der SPS eingestellt ->
Normaler Benutzer wählt Fach aus welches in der SPS einen Wert hat ->
Normaler Benutzer wirft Münze ein und ein Münzzähler erfasst diese->
Je nach Münze sendet der Münzzähler impulse an den Arduino und dieser schaltet je nach Münze relais in einer bestimmten anzahl welches auf den Eingang I0.0 und I0.1 abgefragt wird , damit überwacht werden kann ob ein puls verloren geht

**************************************************************************************************************

Jeder Benutzer hat eine fest zugewiesene Nummer mit welcher das Konto aufgerufen wird 



