#ifndef SONG_HPP_INCLUDED
#define SONG_HPP_INCLUDED

#include <string>
#include <iostream>
#include "date.hpp"

using namespace std;

class Song{
private:
    string nameSong;
    string nameArtist;
    string nameInterpreter;
    string durationSong;
    Date releaseDate;
    int positionRanking;

public:
    
    string getNamesong()const;
    string getNameartist()const;
    string getNameinterpreter()const;
    string getDurationsong()const;
    Date getReleaseDate()const;
    int getPositionranking()const;
    string toString() const;
    void setNamesong(const string&);
    void setNameartist(const string&);
    void setNameinterpreter(const string&);
    void setDurationsong(const string&);
    void setReleaseDate(const Date&);
    void setPositionranking(const int&);

    bool operator == (const Song&) const;
    bool operator != (const Song&) const;
    bool operator < (const Song&) const;
    bool operator <= (const Song&) const;
    bool operator > (const Song&) const;
    bool operator >= (const Song&) const;
    
    static int compareBySongName(const Song&,const Song&);
    static int compareByInterpreter(const Song&,const Song&);
};
#endif // SONG_HPP_INCLUDED
