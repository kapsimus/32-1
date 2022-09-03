#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"
#include "Film.h"

void addPair(std::string& buffer, std::string key, std::string value) {
    buffer += "\"" + key + "\": \"" + value + "\"";
}

void addPair(std::string& buffer, std::string key, int value) {
    buffer += "\"" + key + "\": " + std::to_string(value) ;
}

void addOne(std::string& buffer, std::string value) {
    buffer += "\"" + value + "\"";
}


int main() {
    setlocale(LC_ALL, "Russian");
    std::ofstream file("film_base.json");

    Film newFilm("Тот самый Мюнхгаузен", "Мосфильм", 1980);
    newFilm.setScenarist("Григорий Горин");
    newFilm.setDirector("Марк Захаров");
    newFilm.setProducer(" Центральное телевидение СССР");
    newFilm.setActor("барон Карл Фридрих Иероним фон Мюнхгаузен", "Олег Янковский");
    newFilm.setActor("Марта, возлюбленная барона", "Елена Коренева");
    newFilm.setActor("баронесса Якобина фон Мюнхгаузен", "Инна Чурикова");
    newFilm.setActor("Генрих Рамкопф, любовник баронессы", "Александр Абдулов");
    newFilm.setActor("Феофил фон Мюнхгаузен, сын барона", "Леонид Ярмольник");
    newFilm.setActor("Томас, слуга барона", "Юрий Катин-Ярцев");

    std::string text;
    text += "{\n";
    addPair(text, "name", newFilm.getName());
    text += ", ";
    addPair(text, "studio", newFilm.getStudio());
    text += ", ";
    addPair(text, "date", newFilm.getDate());
    text += ", ";
    int count = newFilm.getScenaristsCount();
    if (count == 1) {
        addPair(text, "script", newFilm.getScenarist());
    } else if (count > 1) {
        text += " \"scenarists\": {\n";
        for (int i = 0; i < count; i++) {
            if (i > 0 && i < count - 1) {
                text += ", ";
            }
            addOne(text, newFilm.getScenarist(i));
        }
        text += "\n}\n";
    }
    count = newFilm.getDirectorsCount();
    if (count == 1) {
        addPair(text, "director", newFilm.getDirector());
    } else if (count > 1) {
        text += " \"directors\": {\n";
        for (int i = 0; i < count; i++) {
            if (i > 0 && i < count - 1) {
                text += ", ";
            }
            addOne(text, newFilm.getDirector(i));
        }
        text += "\n}\n";
    }
    count = newFilm.getProducersCount();
    if (count == 1) {
        addPair(text, "producer", newFilm.getDirector());
    } else if (count > 1) {
        text += " \"producers\": {\n";
        for (int i = 0; i < count; i++) {
            if (i > 0 && i < count - 1) {
                text += ", ";
            }
            addOne(text, newFilm.getProducer(i));
        }
        text += "\n}\n";
    }
    count = newFilm.getActorsCount();
    text += " \"actors\": {\n";
    for (int i = 0; i < count; i++) {
        if (i > 0 && i < count - 1) {
            text += ", ";
        }
        addPair(text, newFilm.getPersonage(i), newFilm.getActor(i));
    text += "\n}\n";
    }
    text += "}";

    nlohmann::json record = text;
    std::cout << record;
    file << record;
    return 0;
}
