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
int main(){
   player p[100];
   team t[100];
   string in;
   int num_player=0;
   int num_team=0;
   while(1)
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
         if (!t[id_team-1].name.empty()&&search_aplayer_ateam(t[id_team-1],p[id_player-1]))
         {
            
         }
         

      }
      
      
      

   } 
   

   return 0;
}