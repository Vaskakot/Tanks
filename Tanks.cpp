#include <iostream>
#include <ctime>

using namespace std;
class Field
{
private:
    int length, width;
    char **F;
public:
    Field(int l, int w)
    {
        F = new char*[w];
        for(int i = 0; i<w; i++)F[i] = new char[l];
        length = l;
        width = w;
    }
    void Create(int x, int y, int a, int b)
    {
        char Values[] = {'_', '|', 'H'};
        for(int i=0; i<width;i++)
            for(int j=0; j<length; j++)
            {
                srand(time(0));
                int token=rand()%3;
                F[i][j] = Values[token];
            }
        F[x][y] = 'P';
        F[a][b] = 'E';
    }
    void Printer(int x, int y, int range)
    {
        for(int i=y-range; i<y+range; i++)
        {
            for(int j=x-range; j<x+range; j++)cout<<F[i][j];
            cout<<endl;
        }
    }
};
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
