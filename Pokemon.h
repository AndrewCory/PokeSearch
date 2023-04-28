#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Pokemon {
private:
    int hp;
    int pokedexNum;
    string name;
    string type1;
    string type2;
    int att;
    int def;
    int spcAtt;
    int spcDef;
    int speed;

    int searchedVal;

    int total = hp + att + def + spcAtt + spcDef + speed;
public:
    void updateSearchedVal(string type)
    {
        if (type == "health")
            searchedVal = hp;
        if (type == "pokedexNum")
            searchedVal = pokedexNum;
        if (type == "attack")
            searchedVal = att;
        if (type == "defense")
            searchedVal = def;
        if (type == "specialAttack")
            searchedVal = spcAtt;
        if (type == "specialDefense")
            searchedVal = spcDef;
        if (type == "speed")
            searchedVal = speed;
    }

    int getSearchedValue()
    {
        return searchedVal;
    }

    int getPokedexNum() {
        return pokedexNum;
    }

    int getAtt() {
        return att;
    }

    int getDef() {
        return def;
    }

    int getSpcAtt() {
        return spcAtt;
    }

    int getSpcDef() {
        return spcDef;
    }

    int getSpeed() {
        return speed;
    }

    int getHealth() {
        return hp;
    }

    int getTotal() {
        return total;
    }

    string getName() {
        return name;
    }

    string getType1() {
        return type1;
    }

    string getType2() {
        return type2;
    }

    void setPokedexNum(int in) {
        pokedexNum = in;
        
    }

    void setAtt(int in) {
        att = in;
    }

    void setDef(int in) {
        def = in;
    }

    void setSpcAtt(int in) {
        spcAtt = in;
    }

    void setSpcDef(int in) {
        spcDef = in;
    }

    void setSpeed(int in) {
        speed = in;
    }

    void setHealth(int in) {
        hp = in;
    }

    void setTotal(int in) {
        total = in;
    }

    void setName(string in) {
        name = in;
    }

    void setType1(string in) {
        type1 = in;
    }

    void setType2(string in) {
        type2 = in;
    }
};

