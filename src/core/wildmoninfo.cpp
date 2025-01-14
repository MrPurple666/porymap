#include "wildmoninfo.h"
#include "montabwidget.h"



WildMonInfo getDefaultMonInfo(EncounterField field) {
    WildMonInfo newInfo;
    newInfo.active = true;
    newInfo.encounterRate = 0;

    int size = field.encounterRates.size();
    while (size--)
        newInfo.wildPokemon.append(WildPokemon());

    return newInfo;
}

void combineEncounters(WildMonInfo &to, WildMonInfo from) {
    to.encounterRate = from.encounterRate;

    if (to.wildPokemon.size() == from.wildPokemon.size()) {
        to.wildPokemon = from.wildPokemon;
    }
    else if (to.wildPokemon.size() > from.wildPokemon.size()) {
        to.wildPokemon = from.wildPokemon + to.wildPokemon.mid(from.wildPokemon.size());
    }
    else {
        to.wildPokemon = from.wildPokemon.mid(0, to.wildPokemon.size());
    }
}
