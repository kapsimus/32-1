#include <map>
#include <utility>
#include <vector>
#include <string>
#include "Film.h"

Film::Film() {
    name = "empty";
    studio = "empty";
    date = 0;
}

Film::Film(const std::string _name, const std::string _studio, const int _date) :
    name(_name), studio(_studio), date(_date) {}

void Film::setName(const std::string &_name) {
    name = _name;
}

void Film::setDate(const int _date) {
    date = _date;
}

void Film::setActor(const std::string &_pers, const std::string &_name) {
    cast.insert(std::pair<std::string, std::string>(_pers, _name));

}

void Film::setDirector(const std::string &_director) {
    director.push_back(_director);
}

void Film::setDirector(const std::vector<std::string> &_director) {
    director = _director;
}

void Film::setProducer(const std::string &_producer) {
    producer.push_back(_producer);
}

void Film::setProducer(const std::vector<std::string> &_producer) {
    producer = _producer;
}

void Film::setScenarist(const std::string &_scenarist) {
    script.push_back(_scenarist);
}

void Film::setScenarist(const std::vector<std::string> &_scenarist) {
    script = _scenarist;
}

void Film::setStudio(const std::string &_studio) {
    studio = _studio;
}

std::string Film::getName() {
    return name;
}

std::string Film::getActor(int number) {
    if (cast.size() >= number) {
        int counter = 0;
        for (std::map<std::string, std::string>::iterator it = cast.begin(); it != cast.end(); it++) {
            if (counter == number) {
                return it->second;
            }
            counter++;
        }
    } else {
        return "empty";
    }
}

void Film::getActor(std::string &_pers, std::string &_name, int number) {
    if (!cast.empty() && cast.size() >= number) {
        int counter = 0;
        for (std::map<std::string, std::string>::iterator it = cast.begin(); it != cast.end(); it++) {
            if (counter == number) {
                _pers = it->second;
                _name = it->first;
                break;
            }
            counter++;
        }
    } else {
        _pers = "empty";
        _name = "empty";
    }
}

void Film::getActors(std::vector<std::pair<std::string, std::string>>& actors) {
    if (!cast.empty()) {
        int counter = 0;
        for (std::map<std::string, std::string>::iterator it = cast.begin(); it != cast.end(); it++) {
            actors.push_back(std::pair<std::string, std::string>(it->first, it->second));
        }
    }
}

std::string Film::getPersonage(int number) {
    if (cast.size() >= number) {
        int counter = 0;
        for (std::map<std::string, std::string>::iterator it = cast.begin(); it != cast.end(); it++) {
            if (counter == number) {
                return it->first;
            }
            counter++;
        }
    } else {
        return "empty";
    }
}

int Film::getActorsCount() {
    if (!cast.empty()) {
        return cast.size();
    } else {
        return 0;
    }
}

int Film::getDate() {
    return date;
}

std::string Film::getDirector() {
    if (!director.empty()) {
        return director[0];
    }
}

std::string Film::getDirector(int number) {
    if (!director.empty() && number < director.size()) {
        return director[number];
    }
}

int Film::getDirectorsCount() {
    if (!director.empty()) {
        return director.size();
    }
}

std::string Film::getProducer() {
    if (!producer.empty()) {
        return producer[0];
    }
}

std::string Film::getProducer(int number) {
    if (!producer.empty() && number < producer.size()) {
        return producer[number];
    }
}

std::vector<std::string> &Film::getProducersList() {
    if (!producer.empty()) {
        return producer;
    }
}

int Film::getProducersCount() {
    if (!producer.empty()) {
        return producer.size();
    }
}

std::vector<std::string> &Film::getDirectorsList() {
    if (!director.empty()) {
        return director;
    }
}

std::string Film::getScenarist() {
    if (!script.empty()) {
        return script[0];
    }
}

std::string Film::getScenarist(int number) {
    if (!script.empty() && number < script.size()) {
        return script[number];
    }
}

std::vector<std::string> &Film::getScenaristList() {
    if (!script.empty()) {
        return script;
    }
}

int Film::getScenaristsCount() {
    if (!script.empty()) {
        return script.size();
    }
}

std::string Film::getStudio() {
    return studio;
}