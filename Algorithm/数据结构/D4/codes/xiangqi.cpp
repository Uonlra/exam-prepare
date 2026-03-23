#include <bits/stdc++.h>
using namespace std;

// 棋盘：0-9行(0-4为红方), 0-8列
// 棋子: G(帅/将), R(车), H(马), C(炮), 空位用'.'表示
const int ROWS = 10, COLS = 9;

struct Piece {
    char type;  // 棋子类型
    int x, y;   // 位置
};

struct State {
    char board[ROWS][COLS];
    vector<Piece> redPieces;
    Piece blackKing;
};

bool isValid(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}

// 检查帅的位置是否有效（九宫格内）
bool inRedPalace(int x, int y) {
    return x >= 0 && x <= 2 && y >= 3 && y <= 5;
}

// 检查将的位置是否有效（九宫格内）
bool inBlackPalace(int x, int y) {
    return x >= 7 && x <= 9 && y >= 3 && y <= 5;
}

// 检查"蹩马腿" - 马在指定方向上的腿是否被挡住
bool isHorseLegBlocked(int fromX, int fromY, int toX, int toY, const State& state) {
    int dx = toX - fromX;
    int dy = toY - fromY;
    
    // 检查相邻的两个方向
    // 例如：(-2, -1) 需要检查 (-1, -1) 和 (-1, 0)
    if (abs(dx) == 2 && abs(dy) == 1) {
        int cx = fromX + dx / 2;
        int cy = fromY;
        if (state.board[cx][cy] != '.') return true;
    } else if (abs(dx) == 1 && abs(dy) == 2) {
        int cx = fromX;
        int cy = fromY + dy / 2;
        if (state.board[cx][cy] != '.') return true;
    }
    return false;
}

// 检查能否移动到目标位置（不检查是否将帅对面）
bool canMove(const Piece& piece, int toX, int toY, const State& state) {
    if (!isValid(toX, toY)) return false;
    
    char target = state.board[toX][toY];
    
    // 红方棋子不能吃红方棋子
    if (target != '.' && target >= 'A' && target <= 'Z') return false;
    
    int dx = toX - piece.x;
    int dy = toY - piece.y;
    
    if (piece.type == 'G') {  // 帅
        if (!inRedPalace(toX, toY)) return false;
        if (abs(dx) + abs(dy) != 1) return false;
        return true;
    } else if (piece.type == 'R') {  // 车
        if (dx != 0 && dy != 0) return false;
        // 检查路径是否通畅
        int stepX = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
        int stepY = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);
        int x = piece.x + stepX, y = piece.y + stepY;
        while (x != toX || y != toY) {
            if (state.board[x][y] != '.') return false;
            x += stepX;
            y += stepY;
        }
        return true;
    } else if (piece.type == 'H') {  // 马
        if (!(abs(dx) == 2 && abs(dy) == 1) && !(abs(dx) == 1 && abs(dy) == 2)) return false;
        return !isHorseLegBlocked(piece.x, piece.y, toX, toY, state);
    } else if (piece.type == 'C') {  // 炮
        if (dx != 0 && dy != 0) return false;
        int stepX = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
        int stepY = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);
        int pieceCount = 0;
        int x = piece.x + stepX, y = piece.y + stepY;
        while (isValid(x, y)) {
            if (x == toX && y == toY) {
                return pieceCount == (target != '.' ? 1 : 0);
            }
            if (state.board[x][y] != '.') pieceCount++;
            x += stepX;
            y += stepY;
        }
        return false;
    }
    return false;
}

// 检查红方是否能攻击到指定位置
bool canAttack(const State& state, int x, int y) {
    for (const auto& piece : state.redPieces) {
        if (piece.type == 'G') {
            if (abs(piece.x - x) + abs(piece.y - y) == 1 && inRedPalace(x, y)) {
                return true;
            }
        } else {
            // 创建临时状态来测试移动
            State temp = state;
            if (canMove(piece, x, y, temp)) {
                return true;
            }
        }
    }
    return false;
}

// 检查将帅是否对面
bool areFacingEachOther(const State& state) {
    // 检查是否在同一列
    for (auto& piece : state.redPieces) {
        if (piece.type == 'G') {
            if (piece.y == state.blackKing.y) {
                // 检查中间是否有棋子
                int minX = min(piece.x, state.blackKing.x);
                int maxX = max(piece.x, state.blackKing.x);
                bool blocked = false;
                for (int x = minX + 1; x < maxX; x++) {
                    if (state.board[x][piece.y] != '.') {
                        blocked = true;
                        break;
                    }
                }
                if (!blocked) return true;
            }
            break;
        }
    }
    return false;
}

// 检查黑方将是否处于被将军状态
bool isInCheck(const State& state) {
    // 检查是否被红方棋子攻击
    for (const auto& piece : state.redPieces) {
        if (piece.type == 'G') {
            if (abs(piece.x - state.blackKing.x) + abs(piece.y - state.blackKing.y) == 1) {
                return true;
            }
        } else {
            State temp = state;
            if (canMove(piece, state.blackKing.x, state.blackKing.y, temp)) {
                return true;
            }
        }
    }
    // 检查将帅对面
    return areFacingEachOther(state);
}

// 检查黑方将是否有合法移动
bool hasLegalMove(const State& state) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    for (int i = 0; i < 4; i++) {
        int newX = state.blackKing.x + dx[i];
        int newY = state.blackKing.y + dy[i];
        
        if (!inBlackPalace(newX, newY)) continue;
        if (state.board[newX][newY] != '.' && state.board[newX][newY] >= 'a') continue;  // 自己的棋子
        
        // 尝试这个移动
        State temp = state;
        temp.board[state.blackKing.x][state.blackKing.y] = '.';
        
        if (state.board[newX][newY] == '.') {
            temp.board[newX][newY] = 'k';
        } else {
            // 吃掉红方棋子
            for (int j = 0; j < temp.redPieces.size(); j++) {
                if (temp.redPieces[j].x == newX && temp.redPieces[j].y == newY) {
                    temp.redPieces.erase(temp.redPieces.begin() + j);
                    break;
                }
            }
            temp.board[newX][newY] = 'k';
        }
        temp.blackKing.x = newX;
        temp.blackKing.y = newY;
        
        // 检查新位置是否被攻击且不对面
        if (!isInCheck(temp)) {
            return true;
        }
    }
    return false;
}

// 判断是否将死
bool isCheckmate(const State& state) {
    return isInCheck(state) && !hasLegalMove(state);
}

void readBoard(State& state) {
    state.redPieces.clear();
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            state.board[i][j] = getchar();
            if (state.board[i][j] == '\n') {
                j--;
                continue;
            }
            if (state.board[i][j] != '.') {
                if (state.board[i][j] == 'k') {
                    state.blackKing = {state.board[i][j], i, j};
                } else if (state.board[i][j] >= 'A' && state.board[i][j] <= 'Z') {
                    state.redPieces.push_back({state.board[i][j], i, j});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    State state;
    while (true) {
        char c = getchar();
        if (c == EOF) break;
        
        ungetc(c, stdin);
        
        // 读取棋盘
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                char ch;
                cin >> ch;
                state.board[i][j] = ch;
                
                if (ch == 'k') {
                    state.blackKing = {ch, i, j};
                } else if (ch >= 'A' && ch <= 'Z') {
                    state.redPieces.push_back({ch, i, j});
                }
            }
        }
        
        if (state.board[0][0] == EOF) break;
        
        // 输出结果
        if (isCheckmate(state)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
