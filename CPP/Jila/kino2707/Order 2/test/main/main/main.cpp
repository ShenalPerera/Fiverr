#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>


#include "main.hpp"
#include "Monster.hpp"
#include "Location.hpp"
#include "Dragon.hpp"

using namespace std;

int main() {
    Monster monsters_map[20];
    Item items_map[20];
    srand(time(nullptr));
    displayRules("game_rules.txt");


    // Create the player
    string player_name;
    cout << "\nEnter your name : ";
    cin >> player_name;
    system("clear");
    createPlayer(player_name);


    Player player = createPlayer(player_name);
    vector<Location>  map = createMap();
    assignMonstersAndItems(map, monsters_map, items_map);

    char user_choice;

    do {
        system("clear");
        Location* location = current_location(map);
        if (location->getHasMonster()) {
            cout << "Caution! There is a monster" << endl;
            monsters_map[location->getIndex()].getDetails();
        }
        player.displayAttributes();

        cout << "S - Move\nA - Attack\nF - Flee\nX - Examine\nM - Map\nT - Take\nD - Drop\nP - Potion\nQ - Quit\n";
        cin >> user_choice;

        switch (user_choice) {
        case 'S':
            move(map, player);
            break;
        case 'M':
            show_map(map);
            break;
        case 'F':
            flee(map, monsters_map, player);
            break;
        case 'A':
            attack(map, monsters_map, player);
            break;
        case 'X':
            examine(map, player, items_map);
            break;
        case 'T':
            handle_inventory(map, 'T', player, items_map);
            break;
        case 'D':
            handle_inventory(map, 'D', player, items_map);
            break;
        case 'Q':
            player.displayAttributes();
            break;
        case 'P':
            drink_potion(player);
            break;
        default:
            displayRules("game_rules.txt");
            break;
        }
    } while (user_choice != 'Q' && !game_status(map, player));

    player.displayAttributes();

    return EXIT_SUCCESS;
}



void  displayRules(string filename) {
    ifstream fin(filename);
    if (fin.fail()) {
        cerr << "Error when loading files!" << endl;
        exit(1);
    }

    string line;
    while (!fin.eof()) {
        getline(fin, line);
        cout << line << endl;
    }
    fin.close();

}

void setDamage(Player& player) {
    int damage = player.getAttack() / 3;
    for (int i = 0; i < player.getInventory().size(); ++i) {
        if (player.getInventory().at(i).getItemType() == weapon) {
            damage = damage + 2;
        }
    }
    player.setDamage(damage);

}

Player createPlayer(string name) {
    Player player;
    player.setName(name);


    player.setHealth(((rand() % 9) + 4) + 12);
    player.setAttack((player.getHealth() / 6));
    player.setDefence(player.getAttack() / 2);

    player.setLuck(((rand() % 5) + 2) + 6);

    // create a map, sword, lantern, and  provisions
    Location dummy;
    Item map("Map", item, -1, true, "Can see the map of the Treasure Caverns of Doom", dummy);
    Item sword("Sword", weapon, -1, true, "adds +2 damage to user’s current damage", dummy);
    Item provisions("Provisions", item, ((rand() % 3) + 2), true, "Each provision restores 5-10 health", dummy);
    Item lantern("Lantern", item, 150, true, "Lights way losing 2-5 points with each move or search action", dummy);

    player.addItem(map);
    player.addItem(sword);
    player.addItem(lantern);
    player.addItem(provisions);

    setDamage(player);

    return player;

}

void setDestinations(int location1, int location2, int location3, Location& current, vector<Location>& map) {
    current.addDestinations(map.at(location1));
    current.addDestinations(map.at(location2));
    current.addDestinations(map.at(location3));
}

vector<Location> createMap() {

    // store the names and descriptions
    string name_desc[20][2] = { {"small cave","This is the entry point the caverns"}
                            ,{"mushroom mecca","cavern with large number of mushroom."},
                             {"Blog of Eternal stench","Stinking cave in the game"},
                             {"creepy cells","Cavern wall cells move motility"},
                             {"guard room","Cavern has gates to guard the inside"},
                             {"large dank cave","Caverns is unpleasantly cold"},
                             {"small smelly cave","cavern full with smelly smoke"},
                             {"large cavern","largest cavern in the world"},
                             {"vaulted chamber","chamber with high security"},
                             {"torture chamber","dead bodies everywhere in this cavern"},
                             {"winding tunnel","a winding cavern"},
                             {"winding tunnel 2","another tunnel"},
                             {"narrow passage","only fit two persons"},
                             {"daffy tunnel","abounding in drafts of air"},
                             {"empty tunnel","One big and empty cavern"},
                             {"draft cave","Cavern abounding in drafts of air"},
                             {"ovoid chamber","Shaped ovoid cave"},
                             {"low cave","has lowest upper head"},
                             {"small cave 2","small cave"},
                             {"slimmy cave","a slim cave"}
    };

    int destinations[20][3] = {
                            {1,2,16},
                            {0,4,7},
                            {0,3,3},
                            {2,4,1},
                            {1,3,13},
                            {5,5,9},
                            {6,6,10},
                            {1,8,12},
                            {7,13,11},
                            {5,15,19},
                            {6,12,16},
                            {8,14,17},
                            {7,17,10},
                            {8,4,18},
                            {11,18,15},
                            {9,19,14},
                            {10,0,17},
                            {11,12,16},
                            {13,19,14},
                            {9,15,18}

    };
    // Create the 20 caverns and add them into a vector
    vector<Location> map;

    int index_val = 0;
    for (auto& i : name_desc) {
        Location location;
        location.setName(i[0]);
        location.setDescription(i[1]);
        location.setIndex(index_val);
        map.push_back(location);
        index_val++;
    }

    for (int i = 0; i < 20; ++i) {
        setDestinations(destinations[i][0], destinations[i][1], destinations[i][2], map.at(i), map);
    }





    map.at(0).setHasPlayer(true);
    return map;
}

bool generateProb(int value_out_hundred) {

    int random_number = (rand() % 101);

    return random_number <= value_out_hundred;
}

//create random integer from in to out
int randInt(int in, int out) {

    return (rand() % (out - in + 1)) + in;
}

void assignMonstersAndItems(vector<Location>& map, Monster monsters_map[], Item items_map[]) {
    Monster monsters[5];

    ifstream fin("monsters.txt");
    if (fin.fail()) {
        cerr << "Error monsters.txt file is missing" << endl;
        exit(1);
    }

    string name;
    int level;
    int carr_item_percent;
    char item_type;
    int in;
    int out;
    int i = 0;

    while (!fin.eof()) {
        fin >> name;
        fin >> level;
        fin >> carr_item_percent;
        fin >> item_type;
        fin >> in;
        fin >> out;

        Item dummy;
        Location location;

        int health = level * randInt(in, out);
        fin >> in;
        fin >> out;
        int attack = level + randInt(in, out);
        fin >> in;
        fin >> out;
        int defence = level + randInt(in, out);
        fin >> in;
        fin >> out;
        int damage = level + randInt(in, out);


        Monster monster(name, level, health, attack, defence, damage, location, dummy);
        monsters[i] = monster;
        i++;
    }
    fin.close();


    // Add dragon
    int health = 5 * randInt(6, 8);
    int attack = 5 + randInt(6, 10);
    int defence = 5 + randInt(6, 12);
    int damage = 2 * randInt(4, 6) + 3 * randInt(2, 3);
    Location dummy_location;
    Item dummy_item;





    ifstream fin2("items.txt");
    if (fin2.fail()) {
        cerr << "items.txt file is missing" << endl;
        exit(1);
    }


    string item_name;
    string description;

    Item items[11];

    int item_index = 0;
    while (!fin2.eof()) {
        fin2 >> item_name;
        fin2 >> item_type;
        getline(fin2, description);
        ItemType type;
        switch (item_type) {
        case 'i':
            type = item;
            break;
        case 'a':
            type = armour;
            break;
        case 'p':
            type = potion;
            break;
        case 'f':
            type = artefact;
            break;
        }
        Location dummy;

        Item item(item_name, type, -1, true, description, dummy);
        if (type == potion) {
            item.setNumOfUses(randInt(2, 4));
        }
        items[item_index++] = item;


    }






    // Update the maps with monsters
    for (int j = 0; j < 14; ++j) {

        int index = randInt(-1, 19);


        if (index == -1 || index == 0 || map.at(index).getHasMonster()) {
            continue;
        }

        Monster monster = monsters[randInt(0, 3)];
        map.at(index).setHasMonster(true);
        map.at(index).setIndex(index);
        monsters_map[index] = monster;

        bool hasItem = false;
        ItemType itemType;
        if (monster.getName() == "Goblin") {
            itemType = item;
            hasItem = generateProb(40);
        }
        else if (monster.getName() == "Hobgoblin") {
            itemType = item;
            hasItem = generateProb(50);
        }

        if (hasItem) {
            int item_val;

            item_val = randInt(0, 5);
            Item item1 = items[item_val];
            map.at(index).setHasItem(true);
            map.at(index).setIndex(index);
            items_map[index] = item1;
            items_map[index].setUsable(true);
        }

    }

    int count = 4;
    for (int j = 1; j < 20; ++j) {
        if (monsters_map[j].getName() == "Ogre" && !map.at(j).getHasItem() && count > 0) {
            if (generateProb(60)) {
                Item item1 = items[10 - count];
                map.at(j).setHasItem(true);
                map.at(j).setIndex(j);
                items_map[j] = item1;
                items_map[j].setUsable(true);
                count--;
            }
        }

        if (monsters_map[j].getName() == "Troll" && !map.at(j).getHasItem() && count > 0) {
            if (generateProb(70)) {
                Item item1 = items[10 - count];
                map.at(j).setHasItem(true);
                map.at(j).setIndex(j);
                items_map[j] = item1;
                items_map[j].setUsable(true);
                count--;
            }
        }

        if (!map.at(j).getHasItem()) {
            int temp_index = randInt(-5, 5);
            if (temp_index < 0) continue;
            Item item1 = items[temp_index];
            map.at(j).setHasItem(true);
            map.at(j).setIndex(j);
            items_map[j] = item1;
            items_map[j].setUsable(true);

        }
    }

    while (count > 0) {
        int art_index = randInt(0, 19);
        if (map.at(art_index).getHasItem()) continue;
        Item item1 = items[9 - count];
        map.at(art_index).setHasItem(true);
        map.at(art_index).setIndex(art_index);
        items_map[art_index] = item1;
        items_map[art_index].setUsable(true);
        count--;
    }

    for (int j = 1; j < 20; ++j) {
        if (!(map.at(j).getHasMonster() || map.at(j).getHasMonster())) {
            Dragon dragon("dragon", 5, health, attack, defence, damage, dummy_location, dummy_item);
            monsters_map[j] = dragon;
            items_map[j] = items[10];
            map.at(j).setHasMonster(true);
            map.at(j).setHasItem(true);
            break;
        }
    }

}

void move(vector<Location>& map, Player& player) {
    cout << "Your current Location : \n";
    consumeOil(player);
    if (current_location(map)->getHasMonster()) {
        cout << "Cannot move! use flee command" << endl;
        return;
    }

    for (int i = 0; i < 20; ++i) {
        if (map.at(i).getHasPlayer()) {
            map.at(i).displayData();
            cout << "Choose your path ==> \n";
            int paths[3];
            for (int j = 0; j < 3; ++j) {
                cout << j + 1 << " - " << map.at(i).getDestinations().at(j).getName() << endl;
                paths[j] = map.at(i).getDestinations().at(j).getIndex();
            }
            int path;
            cin >> path;
            map.at(i).setHasPlayer(false);
            map.at(paths[path - 1]).setHasPlayer(true);

            break;
        }
    }
}

void show_map(vector<Location>& map) {
    for (auto& i : map) {
        if (i.getHasPlayer()) cout << "==>";
        i.displayData();
    }
    cout << "Pres any key : ";
    string l;
    cin >> l;
}

Location* current_location(vector<Location>& map) {
    for (auto& i : map) {
        if (i.getHasPlayer()) { return &i; }
    }
}

void attack(vector<Location>& map, Monster monsters[], Player& player) {
    Location* location = current_location(map);
    if (!location->getHasMonster()) {
        cout << "Cannot attack without a monster" << endl;
        return;
    }

    Monster* monster = &monsters[location->getIndex()];
    monster->getDetails();

    bool sword = false, armour = false, axe = false, chain = false, boots = false;
    for (int i = 0; i < player.getInventory().size(); ++i) {
        string item_name = player.getInventory().at(i).getName();
        if (item_name == "Sword") {
            sword = true;
        }
        if (item_name == "Armour") {
            armour = true;
        }
        if (item_name == "Krang’s_Battle_Axe*") {
            axe = true;
        }
        if (item_name == "Krang’s_Chainmail*") {
            chain = true;
        }
        if (item_name == "Boots_of_Speed*") {
            boots = true;
        }
    }

    int round = 1;
    while (true) {

        cout << "Round " << round << endl;
        monster->getDetails();
        player.displayAttributes();

        int player_attack = player.getAttack() + randInt(2, 10);
        int monster_attack = monster->getAttack() + randInt(2, 10);

        int damage_inflicted;
        if (player_attack > monster_attack) {
            cout << "Attack" << endl;
            damage_inflicted = player.getDamage() + (sword ? 2 : 0) + (axe ? 8 : 0) - monster->getDefence();
            cout << damage_inflicted << endl;
            if (damage_inflicted <= 0) {
                damage_inflicted = player.getDamage() + (sword ? 2 : 0) + (axe ? 8 : 0);
            }

            monster->setHealth(monster->getHealth() - damage_inflicted);

        }
        else {
            cout << "Taking damage" << endl;
            damage_inflicted = monster->getDamage() - player.getDefence() - (armour ? 4 : 0) - (chain ? 12 : 0) - (boots ? 6 : 0);
            cout << damage_inflicted << endl;
            if (damage_inflicted <= 0) {
                damage_inflicted = 1;
            }
            player.setHealth(player.getHealth() - damage_inflicted);
        }



        if (player.getHealth() <= 0) {
            cout << "You lost!" << endl;
            exit(0);
        }
        if (monster->getHealth() <= 0) {
            cout << "You won the battle" << endl;
            location->setHasMonster(false);
            break;
        }
        round++;

    }
}

void flee(vector<Location>& map, Monster monsters[], Player& player) {
    Location* location = current_location(map);
    if (!location->getHasMonster()) {
        cout << "Can not use flee when no monster alive" << endl;
        return;
    }



    else {
        Monster* monster = &monsters[location->getIndex()];
        int damage_inflict = monster->getDamage() - player.getDefence();
        if (damage_inflict <= 0) {
            damage_inflict = monster->getDamage();
        }

        player.setHealth(player.getHealth() - damage_inflict);
        if (player.getHealth() <= 0) {
            cout << "You died!" << endl;
            exit(0);
        }

        for (int i = 0; i < 20; ++i) {
            if (map.at(i).getHasPlayer()) {
                map.at(i).displayData();
                cout << "Choose your path ==> \n";
                int paths[3];
                for (int j = 0; j < 3; ++j) {
                    cout << j + 1 << " - " << map.at(i).getDestinations().at(j).getName() << endl;
                    paths[j] = map.at(i).getDestinations().at(j).getIndex();
                }
                int path;
                cin >> path;
                map.at(i).setHasPlayer(false);
                map.at(paths[path - 1]).setHasPlayer(true);
                break;
            }
        }
        player.displayAttributes();
    }
}

void examine(vector<Location>& map, Player& player, Item items[]) {
    Location* location = current_location(map);
    consumeOil(player);
    if (location->getHasMonster()) {
        cout << "Cannot examine the cave while monster is live" << endl;
        return;
    }

    if (!location->getHasItem()) {
        bool luck = generateProb(30);
        bool isGold = generateProb(50);

        if (!isGold) {
            luck = generateProb(20);
            if (luck) {
                Item item1("Gems", item, -1, true, "This is found Gem", *location);
                player.addItem(item1);
                cout << "Gems is found and collected" << endl;
                return;
            }
            else {
                cout << "Nothing found in the cavern" << endl;
                return;
            }
        }
        else {
            if (luck) {
                Item item1("Gold", item, -1, true, "This is found gold", *location);
                player.addItem(item1);
                cout << "Gold is found and collected" << endl;
                return;
            }
            else {
                cout << "Nothing found in the cavern" << endl;
                return;
            }
        }




    }

    else {
        cout << items[location->getIndex()].getName() << " found " << endl;
        return;
    }

}

void handle_inventory(vector<Location>& map, char take_drop, Player& player, Item items[]) {
    Location* location = current_location(map);

    if (location->getHasMonster()) {
        cout << "Cannot perform the action while monster is alive" << endl;
        return;
    }



    if (take_drop == 'T') {
        if (player.getInventory().size() < 12) {
            if (location->getHasItem()) {

                player.addItem(items[location->getIndex()]);
                location->setHasItem(false);
                if (items[location->getIndex()].getItemType() == artefact) {
                    player.setArtCount();
                }
            }
        }
    }

    if (take_drop == 'D') {
        player.removeItem();
    }

    update_inventory(player);
}

void consumeOil(Player& player) {
    Item temp = player.getInventory().at(2);

    if (temp.getNumOfUses() <= 0) {
        cout << "Oil is over !" << endl;
        exit(0);
    }
    player.consumeOil(randInt(2, 5));
}

void update_inventory(Player& player) {
    player.updateInventory();
}

bool game_status(vector<Location>& map, Player& player) {
    if (player.getHealth() <= 0 || player.getInventory().at(2).getNumOfUses() <= 0) {
        cout << "You loose" << endl;
    }
    if (player.getArtCount() == 5 && current_location(map)->getIndex() == 0) {
        cout << "You won" << endl;
    }
}

void drink_potion(Player& player) {

    for (int i = 0; i < player.getInventory().size(); ++i) {
        if (player.getInventory().at(i).getName() == "Potion" || player.getInventory().at(i).getName() == "Provisions") {

            if (player.getInventory().at(i).getNumOfUses() > 0) {
                cout << i + 1 << " " << player.getInventory().at(i).getName() << endl;
            }
            else return;
        }

    }
    int input;
    cin >> input;
    if (player.getInventory().at(input - 1).getName() == "Potion") {
        player.updateAttribute(input - 1, randInt(2, 4));
    }
    else {
        player.updateAttribute(input - 1, randInt(5, 10));
    }


}