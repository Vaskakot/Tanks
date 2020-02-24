#include <iostream>
#include <ctime>

using namespace std;
int Min(int x, int y)
{
    if(x<y)return x;
    else return y;
}
class Tank
{
private:
    int damage, health, x, y, direction;
    float armorclass;
public:
    Tank(int sx, int sy, int sd)
    {
        damage = 40;
        health = 400;
        armorclass = 0.10;
        x = sx;
        y = sy;
        direction = sd;
    }
    void GetInfo()
    {
        cout<<"Your current health - "<<health<<endl;
        cout<<"Your average damage - "<<damage<<endl;
        cout<<"Your armor class(deflect possibility) - "<<armorclass<<endl;
    }
    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    }
    int GetD()
    {
        return direction;
    }
    void Move()
    {
        if(direction % 4==0)y++;
        else if(direction%4==1)x++;
        else if(direction%4==2)y--;
        else x--;
    }
    void TurnRight()
    {
        direction++;
    }
    ~Tank()
    {
    }
};
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
        srand(time(0));
        char Values[] = {'|', '_', 'H', '_', '_'};
        int token;
        for(int i=0; i<width;i++)
            for(int j=0; j<length; j++)
            {
                token = rand() % 5;
                F[i][j] = Values[token];
            }
        F[x][y] = 'P';
        F[a][b] = 'E';
    }
    void Printer(int x, int y, int range)
    {
        for(int i=y-Min(range, y); i<y+Min(range, width-y); i++)
        {
            if(i>=0&&i<=width)
                for(int j=x-Min(range, x); j<x+Min(range, length - x); j++)
                {
                    if (j>=0&&j<=length)cout<<F[i][j];
                }
                cout<<endl;
        }
    }
    char Look(Tank T)
    {
        if(T.GetD()%4 == 0)return F[T.GetY()+1][T.GetX()];
        if(T.GetD()%4 == 1)return F[T.GetY()][T.GetX()+1];
        if(T.GetD()%4 == 2)return F[T.GetY()-1][T.GetX()];
        if(T.GetD()%4 == 3)return F[T.GetY()][T.GetX()-1];
    }

    void Movement(Tank T)
    {
        if(Look(T)!='H')
        {
        char token = F[T.GetY()][T.GetX()];
        F[T.GetY()][T.GetX()] = '_';
        T.Move();
        F[T.GetY()][T.GetX()] = token;
        }
    }
};
int main()
{
    Tank Player(1, 1, 1);
    Tank Enemy(4, 4, 3);
    Field F(5, 5);
    F.Create(Player.GetX(), Player.GetY(), Enemy.GetX(), Enemy.GetY());
    F.Printer(2, 2, 3);
    F.Movement(Player);
    cout<<endl;
    F.Printer(2,2, 3);
    F.Movement(Enemy);
    cout<<endl;
    F.Printer(2, 2, 3);
    return 0;
}
