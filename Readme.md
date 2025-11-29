# Was?
Dies ist der Quellcode für einen einfachen Pixelflut-Klienten, geschrieben in Python. Ein Pixelflut-Client verbindet sich mit einem Pixelflut-Server und sendet Pixel-Befehle, um ein Bild auf dem Server zu zeichnen.

Wir nutzen diese Implementiertung für einen Einführungs-Workshop in Python.

Der Server ist z.B. unter https://github.com/timvisee/pixelpwnr-server erhältlich. Vor der Nutzung ist für die Teilnehmer eine "server_ip.txt"-Datei mit der IP-Adresse des Servers im selben Verzeichnis wie dieser Code zu erstellen.

# Fahrplan (Beispiel)
...jede Runde hängt von den Teilnehmern ab, hier ist ein grobes Beispiel für die Reihenfolge der Themen (können z.B. im Live-Coding vorgestellt werden, was Teilnehmern beim Abschreiben hilft):
1. Wir beginnen mit deiner Auflösung ungefähr gleich dem Seitenverhältnis des Servers (z.B. 16x9)
2. Kurze Erklärung der Python Syntax - Teilnehmer sollen den Code erstmalig ausführen
3. Erklärung der Bedeutung der Parameter, Einführung was sind "Named Parameters" (dann x/y/r/g/b benennen)
4. Spielt mal mit den Farben rum - merkt ihr was? Andere malen drüber.
5. Fummelt mal an x/y rum - merkt ihr was? Flächengröße. Python zählt von 0-8 bei 9 Pixen.
6. Mehr Zeichnen: Zeile duplizieren. Teilnehmer fragen, was passiert wenn man zwei Zeilen mit verschiednen Farben aber gleichen Koordinaten zeichnet.
7. Themenwechsel: Mathe! Beginnen wir mit Variablen. Ersetzt mal einen Farbwert / Koordinate durch eine und z.B. schiebt eure Pixel umher.
8. Macht mal Mathe - also wieder holt die Variablen-Zuweisung und packt Mathematik rein (nur +/-/* nutzen, geteilt führt zu Fließkommazahlen)
9. Was macht der Rechner? `print()` einführen. Teilnehmer sollen mal 2 Zeilen ausgeben und merken, dass das unübersichtlich wird → als ersten Parameter einen String einsetzen.
10. Schleifen einführen mit x-Koordinate.
11. Rechner zu schnell? `time.sleep()` einführen mit Hinwei, wie Kommazahlen in Python funktionieren (`.` vs `,`).
12. Das erste Mal die Auflösung erhöhen (x4, also z.B. 64x36) damit die Teilnehmer mehr Platz zum Zeichnen haben.
13. Wie wäre es mal eine Fläche zu zeichnen? Teinehmer sollen auf `for` in `for` kommen.
14. Wie wäre nur unter bestimmten Bedingungen zu zeichnen? `if` einführen. Gutes Beispiel wäre z.B. nur Pixel mit Farbwert `>=0` und `<256` (geht auch per `range()`) zu zeichnen, wenn man eine Variable für die Farbe nutzt.
15. `get_color()` einführen, um den aktuellen Farbwert eines Pixels auszulesen - wie wäre eine Kombination mit `if`?
16. Nun ein Spiel: Fang-den-Pixel. Am Ende gibts einen Score pro Farbe... Wer derweil mehr über Python-Themen wissen will, kann sich gerne melden - z.B. `random`, `break`/`continue`
17. Tipp: `while` nutzen um den Code dauerhaft laufen zu lassen - z.B. für mehr Punkte - mit Ctrl+C beenden.
