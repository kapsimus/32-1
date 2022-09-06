#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>
#include "nlohmann/json.hpp"
#include "Film.h"

void createRecord(Film& newFilm, nlohmann::json& record) {
    record["name"] = newFilm.getName();
    record["studio"] = newFilm.getStudio();
    record["date"] = newFilm.getDate();
    int count = newFilm.getScenaristsCount();
    if (count == 1) {
        record["script"] = newFilm.getScenarist();
    } else if (count > 1) {
        record["script"] = newFilm.getScenaristList();
    }
    count = newFilm.getDirectorsCount();
    if (count == 1) {
        record["director"] = newFilm.getDirector();
    } else if (count > 1) {
        record["director"] = newFilm.getDirectorsList();
    }
    count = newFilm.getProducersCount();
    if (count == 1) {
        record["producer"] = newFilm.getProducer();
    } else if (count > 1) {
        record["producer"] = newFilm.getProducersList();
    }
    std::vector<std::pair<std::string, std::string>> actors;
    newFilm.getActors(actors);
    record["actors"] = actors;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    nlohmann::json record;
    std::ofstream file("film_base.json");

    Film newFilm("Тот самый Мюнхгаузен", "Мосфильм", 1980);
    newFilm.setScenarist("Григорий Горин");
    newFilm.setDirector("Марк Захаров");
    newFilm.setProducer("Центральное телевидение СССР");
    newFilm.setActor("барон Карл Фридрих Иероним фон Мюнхгаузен", "Олег Янковский");
    newFilm.setActor("Марта, возлюбленная барона", "Елена Коренева");
    newFilm.setActor("баронесса Якобина фон Мюнхгаузен", "Инна Чурикова");
    newFilm.setActor("Генрих Рамкопф, любовник баронессы", "Александр Абдулов");
    newFilm.setActor("Феофил фон Мюнхгаузен, сын барона", "Леонид Ярмольник");
    newFilm.setActor("Томас, слуга барона", "Юрий Катин-Ярцев");

    createRecord(newFilm, record);
    std::cout << record;
    file << record;
    return 0;
}
