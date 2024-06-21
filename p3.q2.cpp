#include <iostream>
#include <string>
#include <string.h>
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
void hazf(team x,int id) {
   int last=-1;
   for (int i = 0; i < 50; i++)
   {
      if (x.players[i].ID == id)
      {
         for (int j = i;j<50; j++)
         {
            x.players[j] = x.players[j+1];
            if (!x.players[j + 1].name.empty()) {
               last = j +1;
               
               }
            
         }  
         break;
      }
       
   }
   if (last != -1) {
        x.players[last] = {};
    }
}
void match(team x , team y){
   int power_x = 0;
   int power_y = 0;
   for (int i = 0; i < 11; i++)
   {
      power_x += x.players[i].finishing + x.players[i].speed;
   }
   for (int i = 0; i < 11; i++)
   {
      power_y += y.players[i].speed + y.players[i].defence;
   }
   if (power_x > power_y)
   {
      x.wins++;
      y.loses--;
      x.money += 1000;
   }
   if (power_x < power_y)
   {
      y.wins++;
      x.loses--;
      y.money += 1000;
   }
   if (power_x == power_y)
   {
      x.mosavi++;
      y.mosavi--;
   }
   
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
         if (!t[id_team-1].name.empty()&&!search_aplayer_ateam(t[id_team-1],p[id_player-1]))
         {
            hazf(t[id_team-1],id_player);
            cout << "player sold succesfully";
         }
         else if (t[id_team-1].name.empty())
         {
            cout << "team doesnt exist";
         }
         else if (search_aplayer_ateam(t[id_team-1],p[id_player-1]))
         {
            cout << "team doest have this player";
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
            cout << "team doesnt exist";
         }
         else if (t[id_team1-1].players[11].name.empty() || t[id_team2-1].players[11].name.empty())
         {
            cout << "the game can not be held due to loss of the players";
         }
         else
         {
            match(t[id_team1-1],t[id_team2-1]);
         }
      }
      
   } 
   return 0;
}