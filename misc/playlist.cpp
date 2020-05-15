#include <stdexcept>
#include <iostream>
#include <map>

using namespace std;

class Song
{
public:
    Song(string name): name(name), nextSong(NULL) {}

    void next(Song* song)
    {
        this->nextSong = song;
    }

    bool isRepeatingPlaylist()
    {
        Song* curr = this;
        map<string, int> countMap;
        while (curr !=NULL){

			auto result = countMap.insert(pair<string, int>(curr->name,1));

			if (result.second == false)
			{
				return true;
			}

            curr = curr->nextSong;
		}

		return false;
    }

private:
    const string name;
    Song* nextSong;
};

#ifndef RunTests
int main()
{
    Song* first = new Song("Hello");
    Song* second = new Song("Eye of the tiger");

    first->next(second);
    second->next(first);

    cout << boolalpha << first->isRepeatingPlaylist() << "\n";
}
#endif
