#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;


const ll N=1000;
char a[3][3]= {'.','.','.','.','.','.','.','.','.'};

void display()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<a[i][j];
        }

        cout<<"\n";
    }
}


bool valid(int x,int y,char val)
{
    cin>>x>>y;
    x--;
    y--;

    if(a[x][y]=='.')
    {
        a[x][y]=val;

        return 1;
    }

    return 0;
}


bool is_wins(int n)
{
    char val;
    char next_val;
    int f=1;
    //check columns
    for(int i=0; i<n; i++)
    {
        char val;
        f=1;
        for(int j=0; j<n-1; j++)
        {
            val=a[j][i] ;
            next_val=a[j+1][i];
            if(a[j][i]=='.')
            {
                f=0;
                break;
            }
            if(val!=next_val) f=0;
        }

        if(f)
        {
            cout<<"palyer  "<<val<<"  won!"<<"\n";
            return 1;
        }
    }
//check rows
    for(int i=0; i<n; i++)
    {
        f=1;
        for(int j=0; j<n-1; j++)
        {
            val=a[i][j];
            next_val=a[i][j+1];
            if(a[i][j]=='.')
            {
                f=0;
                break;
            }
            if(val!=next_val) f=0;
        }
        if(f)
        {
            cout<<"palyer "<<val<<" won!"<<"\n";
            return 1 ;
        }
    }

//primary diagonal
    for( int i=0; i<n-1; i++)
    {
        f=1;
        val=a[i][i];
        next_val=a[i+1][i+1];
        if(a[i][i]=='.')

        {
            f=0;
            break;
        }
        if(val!=next_val) f=0;
    }
    if(f)
    {
        {
            cout<<"palyer "<<val<<" won!"<<"\n";
            return 1 ;
        }
    }
    int i=0;
    int j=n-1;

    //secondary diagonal
    while(i<n-1 && j>0)
    {
        f=1;
        val=a[i][j];
        next_val=a[i+1][j-1];
        if(a[i++][j--]=='.')
        {
            f=0;
            break;
        }

        if(val!=next_val) f=0;
    }

    if(f)
    {
        {
            cout<<"palyer "<<val<<" won!"<<"\n";
            return 1 ;
        }
    }

    return 0;
}

bool which_player(int z,int x,int y)
{
    char val;

    if(z==1)
    {
        cout<<"\n\n";
        cout<<"player x turn , enter location(r,c): ";
        val='x';

        if((valid( x, y, val)))
        {
            display();
            //z^=1;
            if(is_wins(3)) return 1;
            which_player(0,x,y);

        }
        else
        {
            cout<<"\n\n";
            cout<<"not valid, ";
            which_player(1,x,y);
        }

    }


    else
    {
        cout<<"\n\n";
        cout<<"player o turn , enter location(r,c): ";
        val='o';
        if(valid( x, y, val))
        {
            display();
            //z^=1;
            if(is_wins(3))return 1 ;
            which_player(1,x,y);
        }
        else
        {
            cout<<"not valid,";
            which_player(0,x,y);
        }
    }



}




int main()
{
    int z=1;
    int n;
    cin>>n;
    int x,y;
    which_player(z,x,y);
    return 0;
}
