//
// Created by Sudeep Narala on 10/24/18.
//

#ifndef LAB5_SONG_H
#define LAB5_SONG_H
#include <string>

using namespace std;

class Song {
    private:
        string title;
        string artist;
        int size;

    public:
        Song();
        Song(string title, string artist, int size);

        string getTitle() const
        {
            return title;
        };
        string getArtist() const
        {
            return artist;
        };
        int getSize() const
        {
            return size;
        };
        void setTitle(string t)
        {
            title = t;
        };
        void setArtist(string a)
        {
            artist = a;
        };
        void setSize(int s)
        {
            size = s;
        };

        bool operator > (Song const &rhs);
        bool operator < (Song const &rhs);
        bool operator == (Song const &rhs);


};


#endif //LAB5_SONG_H
