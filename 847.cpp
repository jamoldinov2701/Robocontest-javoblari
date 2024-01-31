#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
vector<string>answers;
char a[15][15];
int whites_attacking[15][15];
int blacks_attacking[15][15];
int Nx[10] = {1,1,2,2,-2,-2,-1,-1};
int Ny[10] = {2,-2,1,-1,1,-1,-2,2};
int Kx[10] = {1,1,1,-1,-1,-1,0,0};
int Ky[10] = {-1,0,1,1,0,-1,1,-1};

int attacked_cells;
int black_king_X, white_king_X;
int black_king_Y, white_king_Y;
bool have_answer = false,black_have_postion = false;

void run_black_king_everywhere(int x , int y);
void run_black_rook_everywhere(int x , int y);
void run_black_bipshop_everywhere(int x , int y);
void run_black_knight_everywhere(int x , int y);

string make_asnwer(int x , int y , int move_x , int move_y)
{
    string answer = "";

    answer = answer + char('A' + y - 1);
    answer = answer + char('0' + 8-x+1);
    answer += " ";

    answer = answer + char('A' + move_y-1);
    answer = answer + char('0' + 8 - move_x + 1);
    return answer;
}
bool in_board(int x, int y)
{
    return 1<=x and x<=8 and 1<=y and y<=8;
}
bool can_move(int x, int y)
{
    if(in_board(x,y)) return a[y] == '.';
    else return false;
}
bool is_az(char c)
{
    return 'a' <= c and c <= 'z' and c!='.';
}

bool can_move_black(int x, int y)
{
    if(in_board(x,y)) return 'A' <= a[x][y] and a[x][y] <= 'Z';
    else return false;
}


void assign_whites_attacked(int x , int y , int move_x , int move_y)
{
    int next_x = x + move_x;
    int next_y = y + move_y;

    whites_attacking[next_x][next_y] ++;
    if(can_move(next_x , next_y))
    {
        assign_whites_attacked(next_x , next_y , move_x , move_y);
    }
}
void assign_blacks_attacked(int x , int y , int move_x , int move_y)
{
    int next_x = x + move_x;
    int next_y = y + move_y;

    blacks_attacking[next_x][next_y] ++;
    if(can_move(next_x , next_y))
    {
        assign_blacks_attacked(next_x , next_y , move_x , move_y);
    }
}
///Bipshop
void assign_white_bipshop(int x, int y)
{
    assign_whites_attacked(x,y,-1,-1);
    assign_whites_attacked(x,y,-1,1);
    assign_whites_attacked(x,y,1,1);
    assign_whites_attacked(x,y,1,-1);
}
void assign_black_bipshop(int x, int y)
{
    assign_blacks_attacked(x,y,-1,-1);
    assign_blacks_attacked(x,y,-1,1);
    assign_blacks_attacked(x,y,1,1);
    assign_blacks_attacked(x,y,1,-1);
}


///Rook
void assign_white_rook(int x, int y)
{
    assign_whites_attacked(x,y,-1,0);
    assign_whites_attacked(x,y,1,0);
    assign_whites_attacked(x,y,0,1);
    assign_whites_attacked(x,y,0,-1);
}
void assign_black_rook(int x, int y)
{
    assign_blacks_attacked(x,y,-1,0);
    assign_blacks_attacked(x,y,1,0);
    assign_blacks_attacked(x,y,0,1);
    assign_blacks_attacked(x,y,0,-1);
}

///Knight
void assign_white_knight(int x, int y)
{
    for(int i=0; i<8; i++)
    {
        int xx = x + Nx[i];
        int yy = y + Ny[i];
        if(in_board(xx,yy))
            whites_attacking[xx][yy] ++;
    }
}
void assign_black_knight(int x, int y)
{
    for(int i=0; i<8; i++)
    {
        int xx = x + Nx[i];
        int yy = y + Ny[i];
        if(in_board(xx,yy))
            blacks_attacking[xx][yy] ++;
    }
}

///King
void assign_white_king(int x , int y)
{
    for(int i=0; i<8; i++)
    {
        int xx = x + Kx[i];
        int yy = y + Ky[i];
        if(in_board(xx,yy))
            whites_attacking[xx][yy] ++;
    }
}
void assign_black_king(int x , int y)
{
    for(int i=0; i<8; i++)
    {
        int xx = x + Kx[i];
        int yy = y + Ky[i];
        if(in_board(xx,yy))
            blacks_attacking[xx][yy] ++;
    }
}

///Pawn
void assign_white_pawn(int x , int y)
{
    if(in_board(x-1,y+1)) whites_attacking[x-1][y+1] ++;
    if(in_board(x-1,y-1)) whites_attacking[x-1][y-1] ++;
}
void assign_black_pawn(int x , int y)
{
    if(in_board(x+1,y+1)) blacks_attacking[x+1][y+1] ++;
    if(in_board(x+1,y-1)) blacks_attacking[x+1][y-1] ++;
}
///*--------------------------------------------------------------------------------------


void assign_whites_everywhere()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            whites_attacking[i][j] = 0;


    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {
            if(a[i][j] == 'N')
            {
                assign_white_knight(i,j);
            }
            if(a[i][j] == 'B' or a[i][j] == 'Q')
            {
                assign_white_bipshop(i,j);
            }
            if(a[i][j] == 'R' or a[i][j] == 'Q')
            {
                assign_white_rook(i,j);
            }
            if(a[i][j] == 'P')
            {
                assign_white_pawn(i,j);
            }
            if(a[i][j] == 'K')
            {
                assign_white_king(i,j);
                /*Shox yonina borib bilami*/

            }
        }
    }

}

void assign_black_everywhere()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            blacks_attacking[i][j] = 0;

    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {
            if(a[i][j] == 'n')
            {
                assign_black_knight(i,j);
            }
            if(a[i][j] == 'b' or a[i][j] == 'q')
            {
                assign_black_bipshop(i,j);
            }
            if(a[i][j] == 'r' or a[i][j] == 'q')
            {
                assign_black_rook(i,j);
            }
            if(a[i][j] == 'p')
            {
                assign_black_pawn(i,j);
            }
            if(a[i][j] == 'k')
            {
                assign_black_king(i,j);
            }
        }
    }
}

void is_lose()
{
    black_have_postion = false;
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {
            if(a[i][j] == 'n')
            {
                run_black_knight_everywhere(i,j);
            }
            if(a[i][j]=='b' or a[i][j] == 'q')
            {
                run_black_bipshop_everywhere(i,j);
            }
            if(a[i][j]=='r' or a[i][j] == 'q')
            {
                run_black_rook_everywhere(i,j);
            }
            if(a[i][j] == 'k')
            {
                run_black_king_everywhere(i,j);
            }
        }
    }
    if(black_have_postion == false) have_answer = true;


}

void run_white(int x , int y , int xx , int yy)
{
//    cout<<x<< " "<<y<< " to "<<xx<< " "<<yy<<endl;
    swap(a[x][y] , a[xx][yy]);
    assign_black_everywhere();
    if(blacks_attacking[white_king_X][white_king_Y] == 0)
    {
        assign_whites_everywhere();
        if(whites_attacking[black_king_X][black_king_Y])
        {
//            cout<<" is_lose";
            is_lose();
            if(have_answer)
            {
                answers.push_back(make_asnwer(x,y,xx,yy));
                have_answer = false;
            }
        }
    }

    swap(a[x][y] , a[xx][yy]);
}
void run_white_and_catch(int x , int y , int xx , int yy)
{
    if(a[xx][yy] == 'k') return;
    char old = a[xx][yy];

    a[xx][yy] = a[x][y];
    a[x][y] = '.';

    assign_black_everywhere();
    if(blacks_attacking[white_king_X][white_king_Y] == 0)
    {
        assign_whites_everywhere();

        if(whites_attacking[black_king_X][black_king_Y])
        {
//            cout<<" is_lose";
            is_lose();
            if(have_answer)
            {
                answers.push_back(make_asnwer(x,y,xx,yy));
                have_answer = false;
            }
        }
    }

    a[x][y] = a[xx][yy];
    a[xx][yy] = old;
}


int run_black(int x , int y , int xx , int yy)
{
    swap(a[x][y] , a[xx][yy]);
    assign_whites_everywhere();

    swap(a[x][y] , a[xx][yy]);
//    cout<<x<<" "<<y<<" "<<xx<<" "<<yy<<" "<<whites_attacking[black_king_X][black_king_Y]<<endl;
    if(whites_attacking[black_king_X][black_king_Y] >= 1) return 1;
    else return -10000;
}
int run_black_and_catch(int x , int y , int xx , int yy)
{
    if(a[xx][yy] == 'K') return 1;
    char old = a[xx][yy];

    a[xx][yy] = a[x][y];
    a[x][y] = '.';
    assign_whites_everywhere();

    a[x][y] = a[xx][yy];
    a[xx][yy] = old;

    if(whites_attacking[black_king_X][black_king_Y] >= 1) return 1;
    else return -10000;
}

void white_smart_mover(int x, int y, int xx, int yy)
{
    if(can_move(xx,yy))
    {
        run_white(x,y,xx,yy);
    }
    else if(in_board(xx,yy) and is_az(a[xx][yy]))
    {
        run_white_and_catch(x,y,xx,yy);
    }
}

void black_smart_mover(int x, int y, int xx, int yy)
{
    if(can_move(xx,yy))
    {
        attacked_cells += run_black(x,y,xx,yy);
    }
    else if(!is_az(a[xx][yy]))
    {
        attacked_cells += run_black_and_catch(x,y,xx,yy);
    }
}

///Run whites
void run_white_bipshop_everywhere(int x , int y)
{
    int xx = x,yy = y;
    while(--xx>=1 and --yy>=1)
    {
        white_smart_mover(x,y,xx,yy);
        if(a[xx][yy] != '.') break;
    }
    xx = x,yy = y;
    while(++xx<=8 and --yy>=1)
    {
        white_smart_mover(x,y,xx,yy);
        if(a[xx][yy] != '.') break;
    }
    xx = x,yy = y;
    while(++xx<=8 and ++yy<=8)
    {
        white_smart_mover(x,y,xx,yy);
        if(a[xx][yy] != '.') break;
    }
    xx = x,yy = y;
    while(--xx>=1 and ++yy<=8)
    {
        white_smart_mover(x,y,xx,yy);
        if(a[xx][yy] != '.') break;
    }
}

void run_white_rook_everywhere(int x , int y)
{
    int xx = x,yy = y;
    while(--xx>=1)
    {
        white_smart_mover(x,y,xx,yy);
        if(a[xx][yy] != '.') break;
    }
    xx = x,yy = y;
    while(++xx<=8)
    {
        white_smart_mover(x,y,xx,yy);
        if(a[xx][yy] != '.') break;
    }
    xx = x,yy = y;
    while(++yy<=8)
    {
        white_smart_mover(x,y,xx,yy);
        if(a[xx][yy] != '.') break;
    }
    xx = x,yy = y;
    while(--yy>=1)
    {
        white_smart_mover(x,y,xx,yy);
        if(a[xx][yy] != '.') break;
    }
}

void run_white_knight_everywhere(int x , int y)
{
    for(int i=0; i<8; i++)
    {
        int xx = x + Nx[i];
        int yy = y + Ny[i];
        white_smart_mover(x,y,xx,yy);
    }
}
void run_white_king_everywhere(int x , int y)
{
    int old_white_king_X = white_king_X;
    int old_white_king_Y = white_king_Y;
    for(int i=0; i<8; i++)
    {
        int xx = x + Kx[i];
        int yy = y + Ky[i];
        white_king_X = xx;
        white_king_Y = yy;
        white_smart_mover(x,y,xx,yy);
    }
    white_king_X = old_white_king_X;
    white_king_Y = old_white_king_Y;
}
void run_white_pawn_everywhere(int x , int y)
{
    if(x==2)
    {
//        cout<<" TO Queen \n";
        a[x][y] = 'Q';
        if(can_move(x-1,y))
        {
            run_white(x,y,x-1,y);
        }
        a[x][y] = 'P';


//        cout<<" TO Kinght \n";
        a[x][y] = 'N';
        if(can_move(x-1,y))
        {
            run_white(x,y,x-1,y);
        }
        a[x][y] = 'P';


//        cout<<"Catch and TO Queen \n";
        if(is_az(a[x-1][y-1]))
        {
            a[x][y] = 'Q';
            if(can_move(x-1,y-1))
            {
                run_white_and_catch(x,y,x-1,y-1);
            }
            a[x][y] = 'P';

//        cout<<"Catch and TO Kinght \n";
            a[x][y] = 'N';
            if(can_move(x-1,y-1))
            {
                run_white_and_catch(x,y,x-1,y-1);
            }
            a[x][y] = 'P';
        }

        if(is_az(a[x-1][y+1]))
        {
            a[x][y] = 'Q';
            if(can_move(x-1,y+1))
            {
                run_white_and_catch(x,y,x-1,y+1);
            }
            a[x][y] = 'P';

//        cout<<"Catch and TO Kinght \n";
            a[x][y] = 'N';
            if(can_move(x-1,y+1))
            {
                run_white_and_catch(x,y,x-1,y+1);
            }
            a[x][y] = 'P';
        }

    }
    else
    {
        if(can_move(x-1,y))
        {
            run_white(x,y,x-1,y);
        }
        if(is_az(a[x-1][y-1]) and in_board(x-1,y-1))
        {
            run_white_and_catch(x,y,x-1,y-1);
        }
        if(is_az(a[x-1][y+1]) and in_board(x-1,y+1))
        {
            run_white_and_catch(x,y,x-1,y+1);
        }
    }

    ///First move
    if(x==7)
    {
        if(can_move(x-2,y))
        {
            run_white(x,y,x-2,y);
        }
        if(is_az(a[x-1][y-1]) and can_move(x-2,y-1))
        {
            run_white(x,y,x-2,y-1);
        }
        if(is_az(a[x-1][y+1]) and can_move(x-2,y+1))
        {
            run_white(x,y,x-2,y+1);
        }
    }
}

///Run blacks
void run_black_king_everywhere(int x , int y)
{
    int old_black_king_X = black_king_X;
    int old_black_king_Y = black_king_Y;
//    cout<<x<<" black king king king "<<x<<" "<<y<<endl;
    attacked_cells = 0;
    for(int i=0; i<8; i++)
    {
        int xx = x + Kx[i];
        int yy = y + Ky[i];
        black_king_X = xx;
        black_king_Y = yy;

        if(!in_board(xx,yy) or is_az(a[xx][yy]))
        {
            attacked_cells++;
            continue;
        }


        black_smart_mover(x,y,xx,yy);
    }
    black_king_X = old_black_king_X;
    black_king_Y = old_black_king_Y;

    if(attacked_cells < 0) black_have_postion = true;
}

void run_black_bipshop_everywhere(int x , int y)
{
    int xx = x,yy = y;
    attacked_cells = 0;
    while(--xx>=1 and --yy>=1)
    {
        black_smart_mover(x,y,xx,yy);
        if(a[xx][yy] != '.') break;
    }
    xx = x,yy = y;
    while(++xx<=8 and --yy>=1)
    {
        black_smart_mover(x,y,xx,yy);
        if(a[xx][yy] != '.') break;
    }
    xx = x,yy = y;
    while(++xx<=8 and ++yy<=8)
    {
        black_smart_mover(x,y,xx,yy);
        if(a[xx][yy] != '.') break;
    }
    xx = x,yy = y;
    while(--xx>=1 and ++yy<=8)
    {
        black_smart_mover(x,y,xx,yy);
        if(a[xx][yy] != '.') break;
    }
    if(attacked_cells < 0) black_have_postion = true;
}

void run_black_rook_everywhere(int x , int y)
{
    int xx = x,yy = y;
    int attacked_cells = 0;
    while(--xx>=1)
    {
        black_smart_mover(x,y,xx,yy);
        if(a[xx][yy] != '.') break;
    }
    xx = x,yy = y;
    while(++xx<=8)
    {
        black_smart_mover(x,y,xx,yy);
        if(a[xx][yy] != '.') break;
    }
    xx = x,yy = y;
    while(++yy<=8)
    {
        black_smart_mover(x,y,xx,yy);
        if(a[xx][yy] != '.') break;
    }
    xx = x,yy = y;
    while(--yy>=1)
    {
        black_smart_mover(x,y,xx,yy);
        if(a[xx][yy] != '.') break;
    }
    if(attacked_cells < 0) black_have_postion = true;;
}
void run_black_knight_everywhere(int x , int y)
{
    int attacked_cells = 0;
    for(int i=0; i<8; i++)
    {
        int xx = x + Nx[i];
        int yy = y + Ny[i];
        black_smart_mover(x,y,xx,yy);
    }
    if(attacked_cells < 0) black_have_postion = true;;
}


void solution()
{
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {
            if(a[i][j] == 'N')
            {
                run_white_knight_everywhere(i,j);
            }
            if(a[i][j] == 'B' or a[i][j] == 'Q')
            {
                run_white_bipshop_everywhere(i,j);
            }
            if(a[i][j] == 'R' or a[i][j] == 'Q')
            {
                run_white_rook_everywhere(i,j);
            }
            if(a[i][j] == 'P')
            {
                run_white_pawn_everywhere(i,j);
            }
            if(a[i][j] == 'K')
            {
                run_white_king_everywhere(i,j);
            }

        }
    }

}

main()
{
    int n;
    cin>>n;
    for(int i=1; i<=8; i++)
    {
        for(int j=1;j<=8;j++)
        {
            cin>>a[i][j];
        }
    }
    if(n == 0)
    {
        for(int i=1; i<=8; i++)
            for(int j=1; j<=8; j++)
                if(a[i][j]!='.')
                {
                    if(is_az(a[i][j])) a[i][j] = toupper(a[i][j]);
                    else a[i][j] = tolower(a[i][j]);
                }
    }
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(a[i][j] == 'k')
            {
                black_king_X = i;
                black_king_Y = j;
            }
            if(a[i][j] == 'K')
            {
                white_king_X = i;
                white_king_Y = j;
            }
        }
    }


    solution();
    cout<<answers[0];
}