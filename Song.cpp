#include "song.hpp"

string Song::getNamesong() const{
    return nameSong;
}

string Song::getNameartist() const{
    return nameArtist;
}

string Song::getNameinterpreter() const{
    return nameInterpreter;
}

string Song::getDurationsong() const{
    return durationSong;
}

Date Song::getReleaseDate() const{
    return releaseDate;
}

int Song::getPositionranking() const{
    return positionRanking;
}

string Song::toString() const{
    string result;
    result = nameSong;
    result+="|";
    result+= nameArtist;
    result+="|";
    result+=nameInterpreter;
    result+="|";
    result+=durationSong;
    result+="|";
    result+=releaseDate.toString();
    result+="|";
    result+=to_string(positionRanking);
    return result;
}

void Song::setNamesong(const string& n){
    nameSong=n;
}

void Song::setNameartist(const string&n){
    nameArtist=n;
}

void Song::setNameinterpreter(const string&n){
    nameInterpreter=n;
}

void Song::setDurationsong(const string&n){
    durationSong=n;
}

void Song::setReleaseDate(const Date&r){
    releaseDate=r;
}

void Song::setPositionranking(const int&p){
    positionRanking=p;
}

//cancion
bool Song::operator ==(const Song& s) const{
    return nameSong == s.nameSong or nameArtist == s.nameArtist;
}

bool Song::operator!=(const Song& s) const{
    return nameSong != s.nameSong or nameArtist != s.nameArtist;
}

bool Song::operator<(const Song& s) const{
    return nameSong < s.nameSong or nameArtist < s.nameArtist;
}

bool Song::operator<=(const Song& s) const{
    return nameSong <= s.nameSong or nameArtist <= s.nameArtist;
}

bool Song::operator>(const Song& s) const{
    return nameSong > s.nameSong or nameArtist > s.nameArtist;
}

bool Song::operator>=(const Song& s) const{
    return nameSong >= s.nameSong or nameArtist >= s.nameArtist;
}

int Song::compareBySongName(const Song& a, const Song& b){
    return a.nameSong.compare(b.nameSong);
}

int Song::compareByInterpreter(const Song& a, const Song& b){
    return a.nameInterpreter.compare(b.nameInterpreter);
}
