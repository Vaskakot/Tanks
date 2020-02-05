#include <iostream>
#include <ctime>

using namespace std;
class Tank
{
private:
    int damage, health, x, y;
    float armorclass;
public:
    Tank()
    {
        damage = 40;
        health = 400;
        armorclass = 0.10;
    }
    void GetInfo()
    {
        cout<<"Your current health - "<<health<<endl;
        cout<<"Your average damage - "<<damage<<endl;
        cout<<"Your armor class(deflect possibility) - "<<armorclass<<endl;
    }

};
int main()
{
    Tank Player;
    Player.GetInfo();
    return 0;
}
