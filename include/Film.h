#pragma once
#include <iostream>
#include <vector>
#include <map>

class Film {
private:
    std::string name;
    std::string studio;
    int date;
    std::vector<std::string> script;
    std::vector<std::string> director;
    std::vector<std::string> producer;
    std::map<std::string, std::string> cast;
public:
    Film();
    Film(std::string  _name, const std::string _studio, const int _date);
    void setName(const std::string& _name);
    void setStudio(const std::string& _studio);
    void setDate(const int _date);
    void setScenarist(const std::string& _scenarist);
    void setScenarist(const std::vector<std::string>& _scenarist);
    void setDirector(const std::string& _director);
    void setDirector(const std::vector<std::string>& _director);
    void setProducer(const std::string& _producer);
    void setProducer(const std::vector<std::string>& _producer);
    void setActor(const std::string& _pers, const std::string& _name);

    std::string getName();
    std::string getStudio();
    int getDate();
    std::string getScenarist();
    std::string getScenarist(int number);
    std::vector<std::string>& getScenaristList();
    int getScenaristsCount();
    std::string getDirector();
    std::string getDirector(int number);
    std::vector<std::string>& getDirectorsList();
    int getDirectorsCount();
    std::string getProducer();
    std::string getProducer(int number);
    int getProducersCount();
    void getActor(std::string& _pers, std::string& _name, int number);
    std::string getPersonage(int number);
    std::string getActor(int number);
    int getActorsCount();

};