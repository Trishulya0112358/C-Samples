#include<bits/stdc++.h>
using namespace std;

class Player{
    int currPosition;
    string name;
    public:
        Player(int pos, string playerName)
        {
            currPosition = pos;
            name = playerName;
        }

        string getName()
        {
            return name;
        }

        void setCurrPos(int pos)
        {
            currPosition = pos;
        }

        int getCurrPos()
        {
            return currPosition;
        }
};

class Board{
    unordered_map<int, int> snakesAndLadders;
    unordered_map<string, int> playerNameMap;
    vector<Player*> players;
    pair<int, int> die;

    public:
        Board(vector<pair<int, int>> snakes, vector<pair<int, int>> ladders, vector<Player*> players, pair<int, int> die)
        {
            for(auto snake : snakes)
            {
                snakesAndLadders[snake.first] = snake.second;
            }

            for(auto ladder : ladders)
            {
                snakesAndLadders[ladder.first] = ladder.second;
            }

            for(auto player : players)
            {
                playerNameMap[player->getName()] = this->players.size();
                this->players.push_back(player);
            }

            this->die.first = die.first;
            this->die.second = die.second;
        }

        int dieRoll()
        {
            int range = die.second - die.first + 1;
            return (rand() % range) + die.first;
        }

        bool roll(string playerName)
        {
            Player* currentPlayer = players[playerNameMap[playerName]];

            int currPos = currentPlayer->getCurrPos();

            int dieRoll = this->dieRoll();
            int newPos = currPos + dieRoll;


            if(newPos > 100)
            {
                cout<<playerName<<" rolled a "<<dieRoll<<" and moved from "<<currPos<<" to "<<currPos<<endl;
                return false;
            }

            if(newPos == 100)
            {
                cout<<playerName<<" rolled a "<<dieRoll<<" and moved from "<<currPos<<" to "<<newPos<<endl;
                currentPlayer->setCurrPos(100);
                return true;
            }

            while(snakesAndLadders.find(newPos) != snakesAndLadders.end())
            {
                newPos = snakesAndLadders[newPos];
            }

            cout<<playerName<<" rolled a "<<dieRoll<<" and moved from "<<currPos<<" to "<<newPos<<endl;
            currentPlayer->setCurrPos(newPos);
            return false;
        }

        vector<Player*> getPlayers()
        {
            return players;
        }

        bool isGameOver()
        {
            for(auto player : players)
            {
                if(player->getCurrPos() == 100)
                {
                    return true;
                }
            }

            return false;
        }
};

void play(Board b)
{
    vector<Player*> players = b.getPlayers();

    for(auto player : players)
    {
        cout<<player->getName()<<endl;
    }

    while(!b.isGameOver())
    {
        for(auto player : players)
        {
            bool gameOver = b.roll(player->getName());
            if(gameOver)
            {
                cout<<player->getName()<<" wins the game"<<endl;
                break;
            }
        }
    }

}

int main(){
    int s, l, p;

    vector<Player*> players;
    vector<pair<int, int>> snakes;
    vector<pair<int, int>> ladders;

    cout<<"Enter no. of snakes"<<endl;
    cin>>s;
    for(int i=0;i<s;i++)
    {
        int head, tail;
        cout<<"Enter head and tail for snake "<<i+1<<": "<<endl;
        cin>>head>>tail;

        snakes.push_back(make_pair(head, tail));
    }

    cout<<"Enter no. of ladders"<<endl;
    cin>>l;
    for(int i=0;i<l;i++)
    {
        int bottom, top;
        cout<<"Enter bottom and top for ladder "<<i+1<<": "<<endl;
        cin>>bottom>>top;

        ladders.push_back(make_pair(bottom, top));
    }

    cout<<"Enter no. of players: "<<endl;
    cin>>p;

    for(int i=0;i<p;i++)
    {
        string name;
        cout<<"Enter name of player "<<i+1<<": "<<endl;
        cin>>name;

        Player* p0 = new Player(0, name);

        players.push_back(p0);
    }

    pair<int, int> die = make_pair(1, 6);

    Board b(snakes, ladders, players, die);

    cout<<"Made the Board"<<endl;

    play(b);
}
