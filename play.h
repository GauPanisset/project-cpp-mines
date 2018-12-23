#ifndef DEF_PARTIE
#define DEF_PARTIE

#include <string>

class Play
{

	private:
	int boxes;
	std::string mod;

	public:
	Play(int game_boxes, std::string game_mod);
	//void drawCard(); Tire une carte
	//void replaceACard(); Replacer une carte dans la bonne case
	//void run();  Lance la partie
	int whichBox(); //Renvoie dans quelle case jouer

};


#endif