#include <iostream>
#include <ctime>

using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char current_marker;
int current_player;

void drawBoard() //rysowanie planszy
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int slot) //umieszczenie pionka
{
    int row = slot / 3;
    int col;
    if (slot % 3 == 0)
    {
        row = row - 1;
        col = 2;
    }
    else col = (slot % 3) - 1;

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = current_marker;
        return true;
    }
    else return false;
}

int winner()
{
    for (int i = 0; i < 3; i++)
    {
        //rzedy
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;

        //columny
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;

    return 0;
}

void swap_player_and_marker()
{
    if (current_marker == 'X') current_marker = 'O';
    else current_marker = 'X';

    if (current_player == 1) current_player = 2;
    else current_player = 1;
}

void game()
{
    cout << "Gracz nr 1, wybierz czym zaczynasz : ";
    char marker_pl;
    cin >> marker_pl;

    current_player = 1;
    current_marker = marker_pl;

    drawBoard();

    int player_won;

    for (int i = 0; i < 9; i++)
    {
        cout << "Ruch gracza nr " << current_player << " . Wybierz pozycje : ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9)
        {
            cout << "Nie ma takiego miejsca! Wybierz inne!\n";
            i--;
            continue;
        };

        if (!placeMarker(slot))
        {
            cout << "To miejsce jest zajete! Wybierz inne!\n";
            i--;
            continue;
        };

        drawBoard();

        player_won = winner();

        if (player_won == 1) { cout << "Gracz 1 wygral!"; break; }
        if (player_won == 2) { cout << "Gracz 2 wygral!"; break; }

        swap_player_and_marker();
    }
    if (player_won == 0) cout << "Remis!";
}
int main()
{
    game();
}