#include "../pub.h"

class Solution {
public:
    int findMinStep(string board, string hand) {
        if (board.size() == 0) return 0;
        int boardLen = static_cast<int>(board.size());
        int handLen = static_cast<int>(hand.size());
        int res = handLen + 1;
        for (int i = 0; i < boardLen; ) {
            int curSteps = 0, cnt = 0;
            char ball = board[i];
            while (i < boardLen && board[i] == ball) {
                i++;
                cnt++;
            }
            if (count(hand.begin(), hand.end(), ball) >= 3 - cnt) {
                curSteps += 3 - cnt; 
                string newHand = hand;
                string left = board.substr(0, i - cnt);
                string right = board.substr(i);
                string newBoard = connectStr(left, right);
                // remove used balls
                for (int k = 0; k < 3 - cnt; k++) {
                    newHand.erase(newHand.find(ball), 1);
                }
                int furtherSteps = findMinStep(newBoard, newHand);
                if (furtherSteps != -1) {
                    res = min (res, curSteps + furtherSteps);
                }
            }
        }

        return res == handLen + 1 ? -1 : res;
    }

    string connectStr(string left, string right) {
        int j = static_cast<int>(left.size() - 1);
        int k = 0, dup = 0;
        while (j >= 0 && left[j] == right.front()) {
            j--;
            dup++;
        }
        while (k < static_cast<int>(right.size()) && right[k] == left.back()) {
            k++;
            dup++;
        }
        if (dup >= 3)  
            return connectStr(left.substr(0, j + 1), right.substr(k));
        else 
            return left + right;
    }
};
