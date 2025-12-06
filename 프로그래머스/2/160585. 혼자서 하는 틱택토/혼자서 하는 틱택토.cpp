#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> board) {
    int countO = 0, countX = 0;
    int winO = 0, winX = 0;
    vector<string> s = { "OXO","XOX","OXO" };
    if (s == board) return 1;
    

    // 돌 개수 세기
    for (string s : board) {
        for (char c : s) {
            if (c == 'O') countO++;
            else if (c == 'X') countX++;
        }
    }

    // 돌 개수 규칙
    if (!(countO == countX || countO == countX + 1)) return 0;

    // 가로 체크
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            char c = board[i][0];
            if (c == 'O') winO++;
            else if (c == 'X') winX++;
        }
    }

    // 세로 체크
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            char c = board[0][i];
            if (c == 'O') winO++;
            else if (c == 'X') winX++;
        }
    }

    // 대각선 체크
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        char c = board[0][0];
        if (c == 'O') winO++;
        else if (c == 'X') winX++;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        char c = board[0][2];
        if (c == 'O') winO++;
        else if (c == 'X') winX++;
    }

    // 동시에 승리 불가
    if (winO > 0 && winX > 0) return 0;

    // 한 명이 여러 줄 승리 불가

    // 승리자와 턴 수 일치 여부
    if (winO > 0 && countO != countX + 1) return 0;
    if (winX > 0 && countO != countX) return 0;

    return 1;
}