#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
struct player
{
   string name;
   int price;
   int speed;
   int finishing; //ghodrat tamam konandegi
   int defence; //defa
   int ID;
};
struct team{
   player players[50];
   string name;
   int money;
   int ID;
   int wins;
   int loses;
   int mosavi;
};
bool search_player(team y[] ,player x){
   int search = x.ID;
   for (int i = 0; !y[i].name.empty(); i++)
   {
      for (int j = 0;!y[i].players[j].name.empty(); j++)
      {
         if (x.ID == y[i].players[j].ID)
         {
            return false;
         } 
      } 
   }
   return true;
}
bool search_aplayer_ateam(team x , player y){
   for (int i = 0; !x.players[i].name.empty() ; i++)
   {
      if (y.ID == x.players[i].ID)
      {
         return false;
      }
      
   }
   return true;
}
int count_teams(team x[]){
   int num = 0;
   for(int i = 0 ; !x[i].name.empty() ; i++){
      num ++;
   }
   return num;
}
bool compareTeams(const team &team1, const team &team2) {
    if (team1.wins == team2.wins) {
      return team1.loses < team2.loses;
    }
    return team1.wins > team2.wins;
}
int main(){
   player p[100];
   team t[100];
   string in;
   int num_player=0;
   int num_team=0;
   bool mewo = true;
   while(mewo)
   {
      cin>>in;
      if (in == "end")
      {
         return 0;
      }
      
      if (in == "new")
      {
         cin >> in;
         if (in == "player")
         {
            cin >> p[num_player].name;
            cin >> p[num_player].price;
            cin >> p[num_player].speed;
            cin >> p[num_player].finishing;
            cin >> p[num_player].defence;
            p[num_player].ID = num_player+1;
            num_player++;
         }
         if (in == "team")
         {
            cin >> t[num_team].name;
            cin >> t[num_team].money;
            t[num_team].ID = num_team+1;
            t[num_team].wins = 0;
            t[num_team].loses = 0;
            t[num_team].mosavi = 0;
            num_team++;
         }  
      }
      if (in == "buy")
      {
         int id_player;
         int id_team;
         cin >> id_player;
         cin >> id_team;
         if (!p[id_player-1].name.empty() && !t[id_team-1].name.empty()&& t[id_team-1].money>=p[id_player-1].price&& search_player(t,p[id_player-1]))
         {
            t[id_team-1].money = t[id_team-1].money - p[id_player].price;
            for (int i = 0;i<50 ; i++)
            {
               if (!t[id_team-1].players[i].name.empty())
               {
                  continue;
               }
               else
               {
                  t[id_team-1].players[i] = p[id_player-1];
                  break;
               }
               
            }
            cout << "player added to the team succesfully" << endl;
            
         }
         else if (p[id_player-1].name.empty())
         {
            cout << "player with the id " << id_player << " doesnt exist" << endl;
         }
         else if (t[id_team-1].name.empty())
         {
            cout << "team with the id " << id_team << " doesnt exist" << endl;
         }
         else if (t[id_team-1].money<p[id_player-1].price)
         {
            cout << "the team cant afford to buy this player" << endl;
         }
         else if (!search_player(t,p[id_player-1]))
         {
            cout << "player already has a team" << endl;
         }
      }
      if (in == "sell")
      {
         int id_player;
         int id_team;
         cin >> id_player;
         cin >> id_team;
         if (!t[id_team-1].name.empty()&&!search_aplayer_ateam(t[id_team-1],p[id_player-1]))
         {
            for (int i = 0; i < 50; i++)
            {
               if (t[id_team-1].players[i].ID == id_player)
               {
                  for (int j = i;j<50; j++)
                  {
                     t[id_team-1].players[j] = t[id_team-1].players[j+1];
                     
                  }  
                  break;
               }
               
            }
            cout << "player sold succesfully" << endl;
         }
         else if (t[id_team-1].name.empty())
         {
            cout << "team doesnt exist" << endl;
         }
         else if (search_aplayer_ateam(t[id_team-1],p[id_player-1]))
         {
            cout << "team doest have this player" << endl;
         }
      }
      if (in == "match")
      {
         int id_team1;
         int id_team2;
         cin >> id_team1;
         cin >> id_team2;
         if (t[id_team1-1].name.empty() || t[id_team2-1].name.empty())
         {
            cout << "team doesnt exist" << endl;
         }
         else if (t[id_team1-1].players[10].name.empty() || t[id_team2-1].players[10].name.empty())
         {
            cout << "the game can not be held due to loss of the players" << endl;
         }
         else
         {
            int power_1 = 0;
            int power_2 = 0;
            for (int i = 0; i < 11; i++)
            {
               power_1 += t[id_team1-1].players[i].finishing +t[id_team1-1].players[i].speed;
            }
            for (int i = 0; i < 11; i++)
            {
               power_2 += t[id_team2-1].players[i].speed + t[id_team2-1].players[i].defence;
            }
            if (power_1 > power_2)
            {
               t[id_team1-1].wins++;
               t[id_team2-1].loses--;
               t[id_team1-1].money += 1000;
            }
            if (power_1 < power_2)
            {
               t[id_team2-1].wins++;
               t[id_team1-1].loses--;
               t[id_team2-1].money += 1000;
            }
            if (power_1 == power_2)
            {
               t[id_team1-1].mosavi++;
               t[id_team2-1].mosavi--;
            }
         }
      }
      if (in == "show")
      {
         cin >> in;
         if (in == "players")
         {
            for (int i = 0; !p[i].name.empty() ; i++)
            {
               cout << p[i].ID << " : " << p[i].name << endl;
            }
            
         }
         else if (in == "teams")
         {
            for (int i = 0; !t[i].name.empty()  ; i++)
            {
               cout << t[i].ID << " : " << t[i].name << endl;
            }
            
         }
         else if (in == "player")
         {
            int id;
            cin >> id;
            if (p[id-1].name.empty())
            {
               cout << "player doesnt exist" << endl;
            }
            else
            {
               cout << "player : " << p[id-1].name << endl;
               cout << "price : " << p[id-1].price << endl;
               cout << "state :" << endl;
               cout << "speed : " << p[id-1].speed << endl;
               cout << "finishing : " << p[id-1].finishing << endl;
               cout << "defence : " << p[id-1].defence << endl; 
            }
            
            
         }
         else if (in == "team")
         {
            int id;
            cin >> id;
            if (t[id-1].name.empty())
            {
               cout << "team doesnt exist" << endl;
            }
            else
            {
               cout << "team : " << t[id-1].name << endl;
               cout << "money : " << t[id-1].money << endl;
               cout << "players : ";
               for (int i = 0; !t[id-1].players[i].name.empty(); i++)
               {
                  cout << t[id-1].players[i].ID << " ";
               }
               cout << endl;
               cout << "state :" << endl;
               cout << "win : " << t[id-1].wins << endl;
               cout << "draw : " << t[id-1].mosavi << endl;
               cout << "loose : " << t[id-1].loses << endl;
            }
            
         }
      }
      if (in == "rank")
      {
         int size = count_teams(t);
         sort(t, t + size, compareTeams);
         for (int i = 0; !t[i].name.empty(); i++)
         {
            cout << i+1 << ". " << t[i].name <<endl;
         }
         
      }
      
   } 
   return 0;
}