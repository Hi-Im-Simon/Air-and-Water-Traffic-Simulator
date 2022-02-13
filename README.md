# DOKUMENTACJA TECHNICZNA PROJEKTU

# Symulacja ruchu powietrznego i wodnego

## Przedmiot: PROGRAMOWANIE OBIEKTOWE

- Zakres projektu
- Diagram klas
- Wymagania systemowe

    - Wymagania funkcjonalne
    - Wymagania pozafunkcjonalne

- Realizacja projektu
- Kryteria akceptacyjne

## 1. Zakres projektu

- System wykorzystywany będzie do przeprowadzania symulacji oraz przewidywania
    ruchu lotniczego oraz wodnego.
- Granicą używalności systemu będą wszelkiego rodzaju wydarzenia losowe, które nie
    są możliwe do przewidzenia w symulacji. Nie będzie on posiadał granic w postaci
    wymagań systemowych, ponieważ będzie on bardzo lekko i wydajny, przez co nie
    powinien mieć problemów nawet z bardzo dużą bazą maszyn, czy miejsc
    transportowych.
- Targetem systemu jest ogólnie pojęty przemysł transportowy oraz jego pasjonaci.
- Potrzeba utworzenia systemu wynika z zapotrzebowania rynkowego na dobrze
    działający oraz przyjazny dla użytkownika system, który będzie posiadał podobne
    możliwości.


## 2. Diagram klas

![image](https://user-images.githubusercontent.com/75808585/153770451-e1e9ed63-86bf-41f6-a2f7-c8eca3cdb5c0.png)


## 3. Wymagania systemowe

### 3.1 Wymagania funkcjonalne

- możliwość dodawania i usuwania linii lotniczych oraz połączeń morskich
- baza lotów oraz rejsów
- monitorowanie zachowań portów lotniczych i wodnych
- monitorowanie stanów samolotów oraz statków w czasie rzeczywistym podczas ich podróży
- podgląd aktualnego czasu symulacji
- rozdzielenie interfejsu użytkownika od procesu odpowiedzialnego za przetwarzanie informacji oraz wykonywanie obliczeń osiągnięte dzięki wielowątkowości

### 3.2 Wymagania pozafunkcjonalne

- oprawa graficzna
- efekty dźwiękowe
- modyfikowanie parametrów samolotów i statków
- modyfikowanie parametrów lotnisk i portów


## 4. Realizacja projektu

Praca podzielona zostanie na części (m. in. user-side, server-side) i rozdzielona pomiędzy uczestników grupy.

Etapami tworzenia projektu będą:
- stworzenie klas wykorzystywanych w dalszej części projektu
- połączenie klas i stworzenie z nich podstawowego systemu
- dodawanie kolejnych funkcjonalności wraz z postępem pracy i zaobserwowanym potencjałem projektu
- stworzenie interfejsu graficznego oraz przyjaźniejszego interfejsu dla użytkownika

Program napisany będzie w językach programowania C/C++ przy wykorzystaniu odpowiednich bibliotek.
Bibliotekami oraz plikami nagłówkowymi wykorzystywanymi w projekcie będą między innymi:

- mingw thread - aby program mógł jednocześnie pobierać dane od użytkownika oraz wykonywać obliczenia w tle
- math - ułatwienie wykonywania obliczeń
- inne, np. iostream, string, vector, map

Program wykonany będzie w całości w języku angielskim w celu zmaksymalizowania potencjalnego targetu.


## 5. Kryteria akceptacyjne

Sprawdzenie podstawowych funkcjonalności:
* Poprzez wykonanie poleceń wprowadzania nowych informacji do bazy danych:

    * addairport - dodawanie nowego lotniska do bazy danychwraz z położeniem (koordynaty x oraz y) na symulowanej mapie
    * addplane - dodawanie nowego samolotu do bazy danychwraz z jego trasą (składającą się z istniejących wcześniej lotnisk) lub samolotu stacjonarnego (z trasą przechodzącą przez ilość lotnisk równą 0 lub 1)
    * addharbor oraz addship - według wcześniejszego schematu dla przystani wodnych oraz statków
 
* Poprzez wykonanie poleceń wypisywania informacji z bazy danych:
    * airports - wypisanie dostępnych lotnisk, ich położeniaoraz stopnia zapełnienia
    * planes - wypisanie istniejących samolotów, ich aktualnegostanu, trasy, długości trasy oraz przebytego dystansu
    * harbors oraz ships - według wcześniejszego schematudla przystani wodnych oraz statków
* Poprzez wykonanie poleceń usuwania informacji z bazy danych:
    * remplane - usunięcie samolotu z bazy oraz zwolnieniezajmowanego przez niego miejsca na jego aktualnym lotnisku (komenda powinna być wykorzystywana głównie w celu usunięcia samolotów stacjonarnych lub tych, które zakończyły już swój lot)
    * remship - według wcześniejszego schematu dla statków
