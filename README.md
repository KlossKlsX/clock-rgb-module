# PCB-RP2040-RGB-Clock-Y13
## Arduino - Zestaw RP2040-Zero + zegar i sterownik LED RGB
## Główne cechy
* Głowny chip to dwurdzeniowy **RP2040** produkowany przez Raspberry Pi
* Zgodność programistyczna ze środowiskiem Arduino
* Zgodność programistyczna i hardwarowa z płytką "RP2040-Zero"
* Wyymiary płytki: 69 mm x 38 mm
* 2 dedykowane wyjścia do modułów LED RBG
* Wbudowany enkoder inkrementalny z przyciskiem i filtrami RC
* Wbudowany dokładny (±3.5ppm) zegar czasu rzeczywistego DS3231 (zegar 12/24 godzinny + kalendarz)
* Bateria guzikowa 1220 podtrzymująca działanie zegara podczas braku zasilania
* Dedykowany port zasilania 5V z bezpiecznikiem 500mA i diodą zabezpieczającą  

## Opis

Moduł jest programistycznie i hardwarowo zgodny z płytką "RP2040-Zero".

Opis tej płytki znajduje się pod adresem:

[https://www.waveshare.com/wiki/RP2040-Zero](https://www.waveshare.com/wiki/RP2040-Zero)

## Foldery:

[PCB-RP2040-RGB-Clock-Y13 - PCB i schemat](Hardware)

[Szkice dla Arduino](Arduino%20examples)


## Instalacja

W celu uruchominia modułu wymagane jest zainstalowanie następujących elementów:

Dodatek do Ardunio do obsługu RP2040

[Raspberry Pi Pico Arduino core](https://github.com/earlephilhower/arduino-pico/)

Dodatkowe bilbioteki do Arduino instalowane z "Library manager" w Arduino wraz z zależnościami:

[Adafruit NeoMatrix](https://github.com/adafruit/Adafruit_NeoMatrix)

[rp2040-encoder-library](https://github.com/gbr1/rp2040-encoder-library)

[DS3231](https://github.com/NorthernWidget/DS3231)


W celu kompilacji i wgrania programu z Arduino należy wybrać płytkę **"Waveshare RP2040 Zero"**.

Do wgrania możyy być wymaganyy restart (reset) płytki z wciśniętyym przyciskiem Boot.
